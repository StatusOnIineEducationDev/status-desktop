#include "tonlineclassroomcontroller.h"


TOnlineClassroomController::TOnlineClassroomController(User *user, QObject *parent)
	:QObject(parent), m_user(user), m_camera(nullptr), m_lesson_connection(nullptr) {
}

TOnlineClassroomController::~TOnlineClassroomController() {

}

void TOnlineClassroomController::showOnlineClassroomWidget(TMainWindow *parent) {
	QMap<QString, QVariant> *course;
	QList<QMap<QString, QVariant>> course_list;
	QList<CourseBase> *course_base_list = this->m_user->coursesBaseList();

	this->initOnlineClassroomWidget(parent);
	this->initController();

	// ——加载数据
	for (int index = 0; index < course_base_list->count(); index++) {
		course = new QMap<QString, QVariant>;
		course->insert("course_id", course_base_list->at(index).courseId());
		course->insert("course_name", course_base_list->at(index).courseName());
		course_list.append(*course);
	}
	// ——显示
	parent->ui().widget_layout->addWidget(this->m_online_classroom_widget);
	this->m_online_classroom_widget->show();
	this->m_online_classroom_enter_controller->showOnlineClassroomEnterDialog(this->m_online_classroom_widget, course_list);

	return;
}

void TOnlineClassroomController::lessonConnectionSend(QJsonObject &data) {
	// ——请求数据
	data["account_type"] = AccountType::Teacher;
	data["course_id"] = this->m_room.courseId();
	data["lesson_id"] = this->m_room.lessonId();
	data["uid"] = this->m_user->uid();
	data["username"] = this->m_user->username();

	// ——这里不用send，否则会报跨线程错误
	this->m_lesson_connection->realSend(data);
}

void TOnlineClassroomController::initOnlineClassroomWidget(TMainWindow *parent) {
	Ui::TOnlineClassroomWidget ui;

	// ——创建online_classroom_widget
	this->m_online_classroom_widget = new TOnlineClassroomWidget(parent);
	this->initAffiliatedWidget();
	ui = this->m_online_classroom_widget->ui();

	// ——信号绑定
	this->connect(parent, &TMainWindow::windowResized, this->m_online_classroom_widget, &TOnlineClassroomWidget::handleWindowResized);
	this->connect(ui.begin_lesson_btn, &QPushButton::clicked, this, &TOnlineClassroomController::beginLesson);
	this->connect(ui.raise_hand_btn, &QPushButton::clicked, this, &TOnlineClassroomController::showHandleRaiseHandWidget);
	this->connect(ui.remove_btn, &QPushButton::clicked, this, &TOnlineClassroomController::removeMemberFromInSpeech);

	// ——其他设置
	ui.flexible_main_area->hide();  // flexible_main_area默认隐藏

	return;
}

void TOnlineClassroomController::initAffiliatedWidget() {
	Ui::THandleRaiseHandWidget raise_hand_ui;

	// ——handle_raise_hand_widget
	this->m_handle_raise_hand_widget = new THandleRaiseHandWidget(this->m_online_classroom_widget);
	raise_hand_ui = this->m_handle_raise_hand_widget->ui();
	this->m_handle_raise_hand_widget->hide();
	this->connect(raise_hand_ui.accept_btn, &QPushButton::clicked, this, &TOnlineClassroomController::acceptRaiseHand);
	this->connect(raise_hand_ui.refuse_btn, &QPushButton::clicked, this, &TOnlineClassroomController::refuseRaiseHand);

	return;
}

void TOnlineClassroomController::initController() {
	this->m_online_classroom_enter_controller = new TOnlineClassroomEnterController(this);
	this->m_online_classroom_white_board_controller = new TOnlineClassroomWhiteBoardController(this->m_online_classroom_widget, this);
	this->m_online_classroom_chat_controller = new TOnlineClassroomChatController(this->m_online_classroom_widget, this);

	this->connect(m_online_classroom_enter_controller, &TOnlineClassroomEnterController::createLesson, this, &TOnlineClassroomController::createLesson);
	this->connect(m_online_classroom_chat_controller, &TOnlineClassroomChatController::lessonConnectionDataReady, this, &TOnlineClassroomController::lessonConnectionSend);

	return;
}

void TOnlineClassroomController::createLessonConnection() {
	this->m_lesson_connection = new Connection;
	QThread *connection_thread = new QThread(this->m_online_classroom_widget);
	this->m_lesson_connection->moveToThread(connection_thread);
	connection_thread->start();
	
	this->m_lesson_connection->connect(ReadConf::G_SOCKET_HOST, ReadConf::G_SOCKET_PORT);

	// ——信号绑定
	this->connect(this->m_lesson_connection, &Connection::bufferReadyRead, this, &TOnlineClassroomController::handleLessonConnectionRecv);

	return;
}

void TOnlineClassroomController::handleLessonConnectionRecv() {
	QJsonObject data = this->m_lesson_connection->recv();
	TransportCmd cmd = TransportCmd(data["command"].toInt());

	switch (cmd) {
	case TransportCmd::CreateLesson: handleCommandCreateLesson(data); break;
	case TransportCmd::BeginLesson: handleCommandBeginLesson(data); break;
	case TransportCmd::EndLesson: handleCommandEndLesson(data); break;
	case TransportCmd::SendChatContent: this->m_online_classroom_chat_controller->handleCommandSendChatContent(data); break;
	case TransportCmd::RecvChatContent: this->m_online_classroom_chat_controller->handleCommandRecvChatContent(data); break;
	case TransportCmd::ChatBan: this->m_online_classroom_chat_controller->handleCommandChatBan(data); break;
	case TransportCmd::RaiseHand: handleCommandRaiseHand(data); break;
	case TransportCmd::ResultOfRaiseHand: handleCommandResultOfRaiseHand(data); break;
	case TransportCmd::RemoveMemberFromInSpeech: handleCommandRemoveMemberFromInSpeech(data); break;
	}

	return;
}

void TOnlineClassroomController::handleCommandCreateLesson(QJsonObject &data) {
	Ui::TOnlineClassroomWidget widget_ui = this->m_online_classroom_widget->ui();
	Toast *toast = new Toast;

	// ——创建成功
	//     ——初始化房间（课堂）数据
	this->m_room.setRoomName(data["course_name"].toString());
	this->m_room.setCourseId(data["course_id"].toString());
	this->m_room.setLessonId(data["lesson_id"].toString());
	this->m_room.setTeacherId(data["teacher_id"].toString());
	this->m_room.setTeacherName(data["teacher_name"].toString());
	this->m_room.setCreateTime(QDateTime::fromTime_t(data["create_timestamp"].toDouble()));
	this->m_room.setBeginTime(QDateTime::fromTime_t(data["begin_timestamp"].toDouble()));

	this->m_user->setUserStatus(UserStatus::InClass);

	this->openCamera();
	this->m_online_classroom_enter_controller->hideOnlineClassroomEnterDialog();

	//     ——刷新ui
	widget_ui.room_name_text->setText(this->m_room.roomName());
	widget_ui.lesson_id_text->setText(this->m_room.lessonId());
	widget_ui.teacher_name_text->setText(this->m_room.teacherName());
	widget_ui.create_time_text->setText(this->m_room.createTime().toString("hh:mm:ss"));

	toast->setInfoText(QString("创建成功"));
	toast->show();
	this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);

	return;
}

void TOnlineClassroomController::handleCommandBeginLesson(QJsonObject &data) {
	Ui::TOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();
	Toast *toast = new Toast("开始上课");

	// ——开启成功
	this->m_room.setBeginTime(QDateTime::fromTime_t(data["begin_timestamp"].toDouble()));

	toast->show();
	this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);

	// ——更新按钮功能
	ui.begin_lesson_btn->setText("结束课堂");
	this->disconnect(ui.begin_lesson_btn, &QPushButton::clicked, this, &TOnlineClassroomController::beginLesson);
	this->connect(ui.begin_lesson_btn, &QPushButton::clicked, this, &TOnlineClassroomController::endLesson);

	// ——刷新ui
	ui.begin_time_text->setText(this->m_room.beginTime().toString("hh:mm:ss"));

	return;
}

void TOnlineClassroomController::handleCommandEndLesson(QJsonObject &data) {
	Ui::TOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();
	Toast *toast = new Toast;
	QThread *thread;

	// ——结束成功
	this->m_camera->deleteLater();

	thread = this->m_lesson_connection->thread();
	delete this->m_lesson_connection;
	this->m_lesson_connection = nullptr;
	thread->exit(0);

	this->m_online_classroom_white_board_controller->distroyPaintConnection();

	this->m_user->setUserStatus(UserStatus::Free);

	toast->setInfoText(QString("课堂已结束"));
	toast->show();
	this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);

	ui.begin_lesson_btn->setText("开始上课");
	this->disconnect(ui.begin_lesson_btn, &QPushButton::clicked, this, &TOnlineClassroomController::endLesson);
	this->connect(ui.begin_lesson_btn, &QPushButton::clicked, this, &TOnlineClassroomController::beginLesson);

	return;
}

void TOnlineClassroomController::handleCommandRaiseHand(QJsonObject &data) {
	QMap<QString, QVariant> info;

	info["student_id"] = data["uid"].toString();
	info["username"] = data["username"].toString();
	info["timestamp"] = data["timestamp"].toInt();

	this->m_rasie_hand_info_list.append(info);
	this->updateHandleRaiseHandWidgetInfo();

	return;
}

void TOnlineClassroomController::handleCommandResultOfRaiseHand(QJsonObject &data) {
	QMap<QString, QVariant> info;

	if (ApplicationStatus(data["application_status"].toInt()) == ApplicationStatus::Accepted) {
		info["student_id"] = data["student_id"].toString();
		info["username"] = data["username"].toString();

		this->m_in_speech_list.append(info);
		this->updateInSpeechWidgetInfo();
	}

	// ——处理handle_raise_hand_widget
	for (int index = 0; index < this->m_rasie_hand_info_list.count(); index++) {
		if (this->m_rasie_hand_info_list[index]["student_id"].toString() == data["student_id"].toString()) {
			this->m_rasie_hand_info_list.removeAt(index);
			this->updateHandleRaiseHandWidgetInfo(index);
			break;
		}
	}

	return;
}

void TOnlineClassroomController::handleCommandRemoveMemberFromInSpeech(QJsonObject &data) {
	for (int index = 0; index < this->m_in_speech_list.count(); index++) {
		if (this->m_in_speech_list[index]["student_id"].toString() == data["student_id"].toString()) {
			this->m_in_speech_list.removeAt(index);
			break;
		}
	}
	this->updateInSpeechWidgetInfo();

	return;
}

void TOnlineClassroomController::createLesson(QMap<QString, QVariant> &data) {
	/*
		|-data(QMap<QString, QVariant>)
			|-course_id(QString)
			|-course_name(QString)
	*/
	QJsonObject request_json_obj;

	this->createLessonConnection();

	request_json_obj["command"] = TransportCmd::CreateLesson;
	request_json_obj["account_type"] = AccountType::Teacher;
	request_json_obj["course_id"] = data["course_id"].toString();
	request_json_obj["course_name"] = data["course_name"].toString();
	request_json_obj["uid"] = this->m_user->uid();
	request_json_obj["username"] = this->m_user->username();

	this->m_lesson_connection->realSend(request_json_obj);

	return;
}

void TOnlineClassroomController::beginLesson() {
	QJsonObject request_json_obj;
	QMap<QString, QVariant> data;

	request_json_obj["command"] = TransportCmd::BeginLesson;
	this->lessonConnectionSend(request_json_obj);

	// ——建立画板连接
	data["course_id"] = this->m_room.courseId();
	data["lesson_id"] = this->m_room.lessonId();
	data["uid"] = this->m_user->uid();
	this->m_online_classroom_white_board_controller->createPaintConnection(data);

	return;
}

void TOnlineClassroomController::endLesson() {
	QJsonObject request_json_obj;

	request_json_obj["command"] = TransportCmd::EndLesson;
	this->lessonConnectionSend(request_json_obj);

	return;
}

void TOnlineClassroomController::openCamera() {
	this->m_camera = new Camera(this->m_online_classroom_widget);

	this->connect(this->m_camera, &Camera::readyRead, this, &TOnlineClassroomController::mineCameraDisplay);

	this->m_camera->open();

	return;
}

void TOnlineClassroomController::mineCameraDisplay(QImage &frame) {
	Ui::TOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();

	ui.mine_camera_label->setPixmap(QPixmap::fromImage(frame));

	return;
}

void TOnlineClassroomController::showHandleRaiseHandWidget() {
	Ui::TOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();
	/*
		初始化位置
	*/
	int btn_width = ui.raise_hand_btn->width(),
		btn_height = ui.raise_hand_btn->height(),
		btn_x = ui.raise_hand_btn->x(),
		btn_y = ui.raise_hand_btn->y(),

		widget_width = this->m_handle_raise_hand_widget->width(),
		widget_height = this->m_handle_raise_hand_widget->height(),
		widget_x = btn_x - widget_width + btn_width,
		widget_y = btn_y + btn_height;

	this->m_handle_raise_hand_widget->setGeometry(widget_x, widget_y, widget_width, widget_height);
	this->m_handle_raise_hand_widget->show();

	return;
}

void TOnlineClassroomController::updateHandleRaiseHandWidgetInfo(int row) {
	Ui::THandleRaiseHandWidget ui = this->m_handle_raise_hand_widget->ui();
	QPushButton *raise_hand_btn = this->m_online_classroom_widget->ui().raise_hand_btn;
	CRaiseHandItemWidget *item_widget;
	QListWidgetItem *item;
	QMap<QString, QVariant> *info;

	/*
		方法一：清空整个widget，重新加载
		这样的方式优点是写起来简单，但如果需要加载的item较多
		便会有卡顿
	*/
	/*ui.raise_hand_view->clear();
	for (int index = 0; index < this->m_rasie_hand_info_list.count(); index++) {
		item_widget = new CRaiseHandItemWidget(ui.raise_hand_view);
		item = new QListWidgetItem;
		info = &this->m_rasie_hand_info_list[index];

		item_widget->ui().username_text->setText(info->value("username").toString());
		item_widget->ui().time_text->setText(QDateTime::fromTime_t(info->value("timestamp").toInt()).toString("hh:mm:ss"));
		item->setSizeHint(QSize(item_widget->width(), item_widget->height()));
		ui.raise_hand_view->addItem(item);
		ui.raise_hand_view->setItemWidget(item, item_widget);
	}*/

	/*
		方法二：不清空widget
		通过row标记，删除指定行或者添加行
		row = -1的话，说明是添加，而非删除
	*/
	switch (row) {
	case -1:
		item_widget = new CRaiseHandItemWidget(ui.raise_hand_view);
		item = new QListWidgetItem;
		info = &this->m_rasie_hand_info_list.last();

		item_widget->ui().username_text->setText(info->value("username").toString());
		item_widget->ui().time_text->setText(QDateTime::fromTime_t(info->value("timestamp").toInt()).toString("hh:mm:ss"));
		item->setSizeHint(QSize(item_widget->width(), item_widget->height()));
		ui.raise_hand_view->addItem(item);
		ui.raise_hand_view->setItemWidget(item, item_widget);
		break;
	default:
		ui.raise_hand_view->takeItem(row);
	}

	// ——更新按钮信息
	if (m_rasie_hand_info_list.count() > 0) {
		raise_hand_btn->setIcon(QIcon(":/button/Resources/material/button/raise_hand_new.png"));
		raise_hand_btn->setText("举手(" + QString::number(m_rasie_hand_info_list.count()) + ")");
	}
	else {
		raise_hand_btn->setIcon(QIcon(":/button/Resources/material/button/raise_hand.png"));
		raise_hand_btn->setText("举手");
	}
	
	return;
}

void TOnlineClassroomController::updateInSpeechWidgetInfo() {
	Ui::TOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();
	CInSpeechMemberItemWidget *item_widget;
	QListWidgetItem *item;
	QMap<QString, QVariant> *info;

	ui.in_speech_member_view->clear();
	for (int index = 0; index < this->m_in_speech_list.count(); index++) {
		item_widget = new CInSpeechMemberItemWidget(ui.in_speech_member_view);
		item = new QListWidgetItem;
		info = &this->m_in_speech_list[index];

		item_widget->ui().username_text->setText(info->value("username").toString());
		item->setSizeHint(QSize(item_widget->width(), item_widget->height()));
		ui.in_speech_member_view->addItem(item);
		ui.in_speech_member_view->setItemWidget(item, item_widget);
	}

	return;
}

void TOnlineClassroomController::acceptRaiseHand() {
	Ui::THandleRaiseHandWidget ui = this->m_handle_raise_hand_widget->ui();
	QListWidgetItem *del_item;
	QJsonObject request_json_obj;
	int row = ui.raise_hand_view->currentRow();

	if (row != -1) {
		request_json_obj["command"] = TransportCmd::ResultOfRaiseHand;
		request_json_obj["application_status"] = ApplicationStatus::Accepted;
		request_json_obj["student_id"] = m_rasie_hand_info_list[row]["student_id"].toString();
		this->lessonConnectionSend(request_json_obj);
	}

	return;
}

void TOnlineClassroomController::refuseRaiseHand() {
	Ui::THandleRaiseHandWidget ui = this->m_handle_raise_hand_widget->ui();
	QJsonObject request_json_obj;
	int row = ui.raise_hand_view->currentRow();

	if (row != -1) {
		request_json_obj["command"] = TransportCmd::ResultOfRaiseHand;
		request_json_obj["application_status"] = ApplicationStatus::Refused;
		request_json_obj["student_id"] = m_rasie_hand_info_list[row]["student_id"].toString();
		this->lessonConnectionSend(request_json_obj);
	}

	return;
}

void TOnlineClassroomController::removeMemberFromInSpeech() {
	Ui::TOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();
	QJsonObject request_json_obj;
	int row = ui.in_speech_member_view->currentRow();

	if (row != -1) {
		request_json_obj["command"] = TransportCmd::RemoveMemberFromInSpeech;
		request_json_obj["student_id"] = m_in_speech_list[row]["student_id"].toString();
		this->lessonConnectionSend(request_json_obj);
	}

	return;
}