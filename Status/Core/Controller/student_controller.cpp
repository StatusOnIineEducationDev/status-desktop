#include <QUdpSocket>
#include "Core/Controller/student_controller.h"
#include "Core/Transport/http_request.h"
#include "Core/View/Component/component.h"
#include "Core/online_education.h"
#include "Core/Tools/base64.h"
#pragma execution_character_set("utf-8")

StudentInteractionWidgetController::StudentInteractionWidgetController(StudentMainWindow *win, User *user)
	: m_win(win), m_user(user), m_student_interaction_widget(nullptr), 
	m_student_interaction_enter_dialog(nullptr), m_camera(nullptr) {
	// ——二段初始化
	this->interactionWidgetInit();  // interaction_widget初始化
	this->enterDialogInit();  // enter_dialog初始化
}

StudentInteractionWidgetController::~StudentInteractionWidgetController() {
	if (this->m_student_interaction_widget != nullptr) {
		delete this->m_student_interaction_widget;
	}
}

void StudentInteractionWidgetController::enterDialogInit() {
	Ui::StudentInteractionEnterDialog ui;
	QTableWidgetItem *course_id_item_temp = nullptr,
		*course_name_item_temp = nullptr,
		*course_status_item_temp = nullptr;
	const QList<CourseBase> *list = this->m_user->coursesBaseList();
	const CourseBase *obj_temp = nullptr;

	// ——enter dialog初始化
	this->m_student_interaction_enter_dialog = new StudentInteractionEnterDialog(this->m_student_interaction_widget);
	this->m_student_interaction_enter_dialog->setModal(true);  // 模态（这里与直接用exec()有区别）
	this->m_student_interaction_enter_dialog->show();
	ui = this->m_student_interaction_enter_dialog->ui();

	// ——写入table
	ui.courses_table->setRowCount(list->count());
	for (int index = 0; index < list->count(); index++) {
		obj_temp = &list->at(index);
		course_id_item_temp = new QTableWidgetItem(obj_temp->courseId());
		course_id_item_temp->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

		course_name_item_temp = new QTableWidgetItem(obj_temp->courseName());
		course_name_item_temp->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

		course_status_item_temp = new QTableWidgetItem(QIcon((":/pic/Resources/material/pic/offline.png")), "未开始");
		course_status_item_temp->setForeground(QBrush(QColor(191, 191, 191)));
		course_status_item_temp->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

		ui.courses_table->setItem(index, 0, course_id_item_temp);
		ui.courses_table->setItem(index, 1, course_name_item_temp);
		ui.courses_table->setItem(index, 2, course_status_item_temp);
	}

	// ——绑定信号
	this->connect(ui.refresh_btn, &QPushButton::clicked, this, &StudentInteractionWidgetController::getCoursesListStatusRequest);
	this->connect(ui.confirm_btn, &QPushButton::clicked, this, &StudentInteractionWidgetController::joinInLesson);

	return;
}

void StudentInteractionWidgetController::interactionWidgetInit() {
	Ui::StudentInteractionWidget ui;
	this->m_student_interaction_widget = new StudentInteractionWidget(this->m_win);

	ui = this->m_student_interaction_widget->ui();
	this->m_win->ui().widget_layout->addWidget(this->m_student_interaction_widget);  // 加入至layout中
	this->m_student_interaction_widget->show();  // 显示

	
	// ——专注度面积图
	this->m_concentration_area_chart = new AreaChartDynamic(QColor(18, 150, 219), this->m_student_interaction_widget);
	ui.concentration_area_chart_widget->setChart(this->m_concentration_area_chart);
	ui.concentration_area_chart_widget->setRenderHint(QPainter::Antialiasing);
	// ——专注度(缩略)面积图
	this->m_concentration_area_chart_min = new AreaChartDynamicMin(QColor(18, 150, 219), this->m_student_interaction_widget);
	ui.concentration_area_chart_min_widget->setChart(this->m_concentration_area_chart_min);
	ui.concentration_area_chart_min_widget->setRenderHint(QPainter::Antialiasing);


	return;
}

void StudentInteractionWidgetController::openCamera() {
	this->m_camera = new Camera(this->m_student_interaction_widget);
	
	this->connect(this->m_camera, &Camera::readyRead, this, &StudentInteractionWidgetController::mineCameraDisplay);
	this->connect(this->m_camera, &Camera::hadOpened, this, &StudentInteractionWidgetController::startSendCameraFrame);
	
	this->m_camera->open();

	return;
}

void StudentInteractionWidgetController::mineCameraDisplay(QImage &frame) {
	Ui::StudentInteractionWidget ui = this->m_student_interaction_widget->ui();

	ui.mine_camera_label->setPixmap(QPixmap::fromImage(frame));

	return;
}

void StudentInteractionWidgetController::startSendCameraFrame() {
	QTimer *timer = new QTimer;
	this->connect(timer, &QTimer::timeout, this, &StudentInteractionWidgetController::sendMineCameraFrame);
	timer->start(1000);
}

void StudentInteractionWidgetController::sendMineCameraFrame() {
	Mat frame_mat = this->m_camera->getFrameMat();
	QJsonObject json_obj;

	// ——Mat 转 base64
	std::vector<unsigned char> mat_encode_vector;
	std::string mat_encode_str;
	const char *mat_encode_char;
	QString base64_str;

	cv::imencode(".jpg", frame_mat, mat_encode_vector);
	mat_encode_str.append(mat_encode_vector.begin(), mat_encode_vector.end());
	mat_encode_char = mat_encode_str.c_str();
	base64_str = QString::fromStdString(base64_encode(mat_encode_char, mat_encode_str.size()));

	// ——发送（这里不能直接通过Send发射信号触发，否则会出现跨线程错误）
	json_obj["command"] = TransportCmd::StudentCameraFrameData;
	json_obj["timestamp"] = int(QDateTime::currentDateTime().toTime_t());
	json_obj["frame_mat"] = base64_str;
	this->m_lesson_connection->realSend(json_obj);

	return;
}

void StudentInteractionWidgetController::handleLessonConnectionRecv() {
	QJsonObject data = this->m_lesson_connection->recv();
	TransportCmd cmd = TransportCmd(data["command"].toInt());

	switch (cmd) {
	case TransportCmd::JoinInLesson: handleCommandJoinInLesson(data); break;
	case TransportCmd::BeginLesson: handleCommandBeginLesson(data); break;
	case TransportCmd::ConcentrationData: handleCommandConcentrationData(data); break;
	case TransportCmd::PaintCommand: handleCommandPaintCommand(data); break;
	}

	return;
}

void StudentInteractionWidgetController::handlePaintConnectionRecv() {
	QJsonObject data = this->m_paint_connection->recv();
	TransportCmd cmd = TransportCmd(data["command"].toInt());

	switch (cmd) {
	case TransportCmd::PaintCommand: handleCommandPaintCommand(data); break;
	}

	return;
}

void StudentInteractionWidgetController::handleCommandJoinInLesson(QJsonObject &data) {
	Ui::StudentInteractionWidget ui = this->m_student_interaction_widget->ui();
	int status = data["status"].toInt();
	Toast *toast = new Toast;
	const CourseBase *course;
	QString text;

	// 0-未上课；1-正在上课；2-禁止中途加入；3-等待中
	switch (status) {
	case 0:
		text = "课程未开始";
		delete this->m_lesson_connection;
		break;
	case 1:
		text = "进入成功";

		// ——初始化房间（课堂）数据
		course = &this->m_user->coursesBaseList()->at(this->m_student_interaction_enter_dialog->ui().courses_table->selectedItems().first()->row());
		this->m_room.setRoomName(course->courseName());
		this->m_room.setCourseId(course->courseId());
		this->m_room.setLessonId(data["lesson_id"].toString());
		this->m_room.setTeacherId(data["teacher_id"].toString());
		this->m_room.setTeacherName(data["teacher_name"].toString());
		ui.lesson_status_btn->setText("正在上课");

		this->openCamera();
		this->updateRoomBaseInfo(data);
		this->m_student_interaction_enter_dialog->hide();
		break;
	case 2:
		text = "该课堂不允许中途加入";
		delete this->m_lesson_connection;
		break;
	case 3:
		text = "进入成功";

		// ——初始化房间（课堂）数据
		course = &this->m_user->coursesBaseList()->at(this->m_student_interaction_enter_dialog->ui().courses_table->selectedItems().first()->row());
		this->m_room.setRoomName(course->courseName());
		this->m_room.setCourseId(course->courseId());
		this->m_room.setLessonId(data["lesson_id"].toString());
		this->m_room.setTeacherId(data["teacher_id"].toString());
		this->m_room.setTeacherName(data["teacher_name"].toString());

		this->openCamera();
		this->updateRoomBaseInfo(data);
		this->m_student_interaction_enter_dialog->hide();
		break;
	}
	toast->setInfoText(text);
	toast->show();
	this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);

	return;
}

void StudentInteractionWidgetController::handleCommandBeginLesson(QJsonObject &data) {
	Ui::StudentInteractionWidget ui = this->m_student_interaction_widget->ui();
	Toast *toast = new Toast("开始上课");

	ui.lesson_status_btn->setText("正在上课");
	toast->show();

	return;
}

void StudentInteractionWidgetController::handleCommandConcentrationData(QJsonObject &data) {
	Ui::StudentInteractionWidget ui = this->m_student_interaction_widget->ui();
	Concentration concentration_obj;
	int value = data["value"].toInt();
	double timestamp = data["timestamp"].toDouble();

	concentration_obj.setValue(value);
	concentration_obj.setDateTime(QDateTime::fromTime_t(timestamp));
	this->m_concentration_list.append(concentration_obj);
	              
	// ——更新专注度图
	this->m_concentration_area_chart->append(timestamp, value);
	this->m_concentration_area_chart_min->append(timestamp, value);
	// ——更新label
	ui.concentration_text->setText(QString::number(value));

	return;
}

void StudentInteractionWidgetController::handleCommandPaintCommand(QJsonObject &data) {
	this->m_student_interaction_widget->board()->paintByPaintCommand(data);

	return;
}

void StudentInteractionWidgetController::updateRoomBaseInfo(const QJsonObject &data) {
	Ui::StudentInteractionWidget ui = this->m_student_interaction_widget->ui();
	double start_timestamp = data["start_timestamp"].toDouble();
	
	ui.room_name_text->setText(this->m_room.roomName());
	ui.lesson_id_text->setText(this->m_room.lessonId());

	return;
}

void StudentInteractionWidgetController::createLessonConnection() {
	this->m_lesson_connection = new Connection;
	QThread *request_thread = new QThread;
	this->m_lesson_connection->moveToThread(request_thread);
	request_thread->start();

	//this->m_lesson_connection->connect("49.235.16.174", 5002);
	this->m_lesson_connection->connect("127.0.0.1", 5002);

	// ——信号绑定
	this->connect(this->m_lesson_connection, &Connection::bufferReadyRead, this, &StudentInteractionWidgetController::handleLessonConnectionRecv);

	return;
}

void StudentInteractionWidgetController::createPaintConnection() {
	this->m_paint_connection = new Connection;
	QThread *request_thread = new QThread;
	this->m_paint_connection->moveToThread(request_thread);
	request_thread->start();

	//this->m_lesson_connection->connect("49.235.16.174", 5002);
	this->m_paint_connection->connect("127.0.0.1", 5002);

	// ——信号绑定
	this->connect(this->m_paint_connection, &Connection::bufferReadyRead, this, &StudentInteractionWidgetController::handlePaintConnectionRecv);

	return;
}

void StudentInteractionWidgetController::getCoursesListStatusRequest() {
	QJsonObject request_json_obj;
	QJsonArray courses_id_json_arr;
	HttpRequest *request_obj = new HttpRequest;
	QThread *request_thread = new QThread;
	request_obj->moveToThread(request_thread);
	const QList<CourseBase> *list = this->m_user->coursesBaseList();

	// ——请求数据
	for (int index = 0; index < list->count(); index++) {
		courses_id_json_arr.append(list->at(index).courseId());
	}
	request_json_obj["courses_id"] = courses_id_json_arr;

	request_obj->request(QUrl("http://127.0.0.1:5000/getCoursesListStatus"), request_json_obj);
	this->connect(request_obj, &HttpRequest::success, this, &StudentInteractionWidgetController::getCoursesListStatusSuccess);
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::quit);
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::deleteLater);
	this->connect(request_obj, &HttpRequest::complete, request_obj, &HttpRequest::deleteLater);
	request_thread->start();

	return;
}

void StudentInteractionWidgetController::getCoursesListStatusSuccess(const QJsonObject &data) {
	Ui::StudentInteractionEnterDialog ui = this->m_student_interaction_enter_dialog->ui();
	QJsonArray *courses_status_json_arr = &data["courses_status"].toArray();
	QTableWidgetItem *course_status_item_temp = nullptr;
	QIcon status_icon;
	QString status_text;

	// 0-未上课；1-正在上课；2-禁止中途加入；3-等待中
	for (int index = 0; index < courses_status_json_arr->count(); index++) {
		switch (courses_status_json_arr->at(index).toInt()) {
		case 0:
			status_icon.addFile(":/pic/Resources/material/pic/offline.png");
			status_text = "未上课";
			course_status_item_temp = new QTableWidgetItem(status_icon, status_text);
			course_status_item_temp->setForeground(QBrush(QColor(191, 191, 191)));
			break;
		case 1:
			status_icon.addFile(":/pic/Resources/material/pic/online.png");
			status_text = "已开始";
			course_status_item_temp = new QTableWidgetItem(status_icon, status_text);
			course_status_item_temp->setForeground(QBrush(QColor(33, 186, 119)));
			break;
		case 2:
			status_icon.addFile(":/pic/Resources/material/pic/cant_join_in.png");
			status_text = "不能中途加入";
			course_status_item_temp = new QTableWidgetItem(status_icon, status_text);
			course_status_item_temp->setForeground(QBrush(QColor(255, 0, 0)));
			break;
		case 3:
			status_icon.addFile(":/pic/Resources/material/pic/waiting.png");
			status_text = "等待中";
			course_status_item_temp = new QTableWidgetItem(status_icon, status_text);
			course_status_item_temp->setForeground(QBrush(QColor(255, 168, 66)));
			break;
		}
		course_status_item_temp->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

		ui.courses_table->setItem(index, 2, course_status_item_temp);
	}
	
	return;
}

void StudentInteractionWidgetController::joinInLesson() {
	Ui::StudentInteractionEnterDialog ui = this->m_student_interaction_enter_dialog->ui();
	int row = ui.courses_table->currentRow();
	if (row == -1) {
		Toast *toast = new Toast("请先选择一个课程");
		toast->show();
		this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);
	}
	else {
		QJsonObject request_json_obj;
		QJsonArray courses_id_json_arr;
		QString course_id, course_name;

		this->createLessonConnection();
		this->createPaintConnection();
		course_id = ui.courses_table->item(row, 0)->text();

		// ——请求数据
		request_json_obj["command"] = TransportCmd::JoinInLesson;
		request_json_obj["course_id"] = course_id;
		request_json_obj["uid"] = this->m_user->uid();

		request_json_obj["command"] = TransportCmd::JoinInLesson;
		this->m_lesson_connection->send(request_json_obj);
		request_json_obj["command"] = TransportCmd::CreatePaintConnection;
		this->m_paint_connection->send(request_json_obj);
	}

	return;
}


//**************************************************************************************************
//**************************************************************************************************


StudentController::StudentController(StudentMainWindow *win, User *user) 
	: m_win(win), m_user(user), m_student_interaction_widget_controller(nullptr){
	Ui::StudentMainWindow ui = this->m_win->ui();

	this->m_win->show();

	this->connect(ui.interaction_btn, &QPushButton::clicked, this, &StudentController::showStudentInteractionWidget);

	// ——默认首页

}

StudentController::~StudentController() {
	if (this->m_win != nullptr) {
		delete this->m_win;
	}
	if (this->m_user != nullptr) {
		delete this->m_user;
	}
	if (this->m_student_interaction_widget_controller != nullptr) {
		delete this->m_student_interaction_widget_controller;
	}
}

/*
	切换窗口时调用
	清除当前的子窗
*/
void StudentController::clearWidget() {
	// 实时互动
	if (this->m_student_interaction_widget_controller != nullptr) {
		delete this->m_student_interaction_widget_controller;
		this->m_student_interaction_widget_controller = nullptr;
	}

	return;
}

/*
	切换至“实时互动”子窗
*/
void StudentController::showStudentInteractionWidget() {
	this->clearWidget();  // 先清除主窗中当前显示的子窗
	if (this->m_student_interaction_widget_controller == nullptr) {
		this->m_student_interaction_widget_controller = new StudentInteractionWidgetController(this->m_win, this->m_user);  // 动态创建子窗
	}

	return;
}