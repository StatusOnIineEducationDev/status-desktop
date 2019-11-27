#include "t_onlineClassroomWidget.h"


TeacherOnlineClassroomWidget::TeacherOnlineClassroomWidget(QWidget *parent)
	: OnlineClassroomWidget(parent), m_function_button_widget(nullptr),
	m_interaction_widget(nullptr) {

	this->init();

	this->loadEnterDialog();
	this->loadFunctionButtonWidget();
	this->loadFunctionPageWidget();
	this->loadHandleRaiseHandWidget();
}

TeacherOnlineClassroomWidget::~TeacherOnlineClassroomWidget() {

}

void TeacherOnlineClassroomWidget::init() {
	this->m_ui.begin_lesson_btn->setText("开始上课");

	// ——信号绑定
	this->connect(this->m_ui.begin_lesson_btn, &QPushButton::clicked,
		this, &TeacherOnlineClassroomWidget::beginLesson);
}

void TeacherOnlineClassroomWidget::loadEnterDialog() {
	// ——加载进入对话框
	QMap<QString, QVariant> *course;
	QList<QMap<QString, QVariant>> course_list;
	QList<CourseBase> *course_base_list = User::G_COURSES_BASE_LIST;
	this->m_enter_dialog = new TeacherEnterDialog(this);
	this->connect(this->m_enter_dialog, &TeacherEnterDialog::createLesson,
		this, &TeacherOnlineClassroomWidget::createLesson);
	// ——加载数据
	for (int index = 0; index < course_base_list->count(); index++) {
		course = new QMap<QString, QVariant>;
		course->insert("course_id", course_base_list->at(index).courseId());
		course->insert("course_name", course_base_list->at(index).courseName());
		course_list.append(*course);
	}
	this->m_enter_dialog->loadData(course_list);
	this->m_enter_dialog->setModal(true);  // 模态（这里与直接用exec()有区别）
	this->m_enter_dialog->show();

	return;
}

void TeacherOnlineClassroomWidget::loadFunctionButtonWidget() {
	// ——加载功能条
	this->m_function_button_widget = new TeacherOnlineClassroomFunctionButtonWidget(this);
	this->m_ui.online_classroom_function_btn_widget_layout->
		addWidget(this->m_function_button_widget);

	// ——信号连接
	Ui::TeacherOnlineClassroomFunctionButtonWidget btn_ui =
		this->m_function_button_widget->ui();
	this->connect(btn_ui.raise_hand_btn, &QPushButton::clicked,
		this, &TeacherOnlineClassroomWidget::showHandleRaiseHandWidget);

	return;
}

void TeacherOnlineClassroomWidget::loadFunctionPageWidget() {
	// ——加载互动页
	this->loadInteractionPageWidget();

	return;
}

void TeacherOnlineClassroomWidget::loadInteractionPageWidget() {
	// ——加载互动页
	this->m_interaction_widget = new TeacherInteractionWidget(this);
	this->m_ui.function_tabWidget->addTab(this->m_interaction_widget, "互动");

	// ——信号绑定
	this->connect(this->m_interaction_widget->chatAndInSpeechWidget(),
		&ChatAndInSpeechWidget::lessonConnectionDataReady,
		this, &TeacherOnlineClassroomWidget::lessonConnectionSend);

	return;
}

void TeacherOnlineClassroomWidget::loadHandleRaiseHandWidget() {
	this->m_handle_raise_hand_widget = new TeacherHandleRaiseHandWidget(this);

	// ——信号绑定
	this->connect(this->m_handle_raise_hand_widget,
		&TeacherHandleRaiseHandWidget::lessonConnectionDataReady,
		this, &TeacherOnlineClassroomWidget::lessonConnectionSend);

	this->connect(this->m_handle_raise_hand_widget, 
		&TeacherHandleRaiseHandWidget::rasieHandInfoListChange,
		this->m_function_button_widget, 
		&TeacherOnlineClassroomFunctionButtonWidget::updateRaiseHandButton);
	this->connect(this->m_handle_raise_hand_widget,
		&TeacherHandleRaiseHandWidget::raiseHandAccepted,
		this->m_interaction_widget->chatAndInSpeechWidget(),
		&ChatAndInSpeechWidget::addMemberToInSpeech);

	return;
}

void TeacherOnlineClassroomWidget::handleLessonConnectionRecv() {
	QJsonObject data = this->m_lesson_connection->recv();
	TransportCmd cmd = TransportCmd(data["command"].toInt());

	switch (cmd) {
	case TransportCmd::CreateLesson: 
		this->handleCommandCreateLesson(data); break;
	case TransportCmd::BeginLesson: 
		this->handleCommandBeginLesson(data); break;
	case TransportCmd::EndLesson: 
		this->handleCommandEndLesson(data); break;

	case TransportCmd::RaiseHand:
		this->m_handle_raise_hand_widget->handleCommandRaiseHand(data); break;
	case TransportCmd::ResultOfRaiseHand:
		this->m_handle_raise_hand_widget->handleCommandResultOfRaiseHand(data); break;

	case TransportCmd::RemoveMemberFromInSpeech:
		this->m_interaction_widget->chatAndInSpeechWidget()->
			handleCommandRemoveMemberFromInSpeech(data); break;
	case TransportCmd::SendChatContent: 
		this->m_interaction_widget->chatAndInSpeechWidget()->
			handleCommandSendChatContent(data); break;
	case TransportCmd::RecvChatContent: 
		this->m_interaction_widget->chatAndInSpeechWidget()->
			handleCommandRecvChatContent(data); break;
	case TransportCmd::ChatBan: 
		this->m_interaction_widget->chatAndInSpeechWidget()->
			handleCommandChatBan(data); break;
	}

	return;
}

void TeacherOnlineClassroomWidget::handleCommandCreateLesson(QJsonObject &data) {
	CourseStatus course_status = CourseStatus::Waiting;
	Toast *toast = new Toast;

	// ——创建成功
	//     ——初始化房间（课堂）数据
	this->updateLessonInfo(
		data["course_name"].toString(), 
		data["course_id"].toString(),
		data["lesson_id"].toString(), 
		data["teacher_name"].toString(),
		data["teacher_id"].toString(), 
		course_status, 
		(int)data["create_timestamp"].toDouble());

	User::G_USER_STATUS = UserStatus::InClass;

	this->openCamera();
	//QtConcurrent::run(this, &TOnlineClassroomController::openCamera);
	this->m_enter_dialog->hide();
	this->m_enter_dialog->deleteLater();

	toast->setInfoText(QString("创建成功"));
	toast->show();
	this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);

	return;
}

void TeacherOnlineClassroomWidget::handleCommandBeginLesson(QJsonObject &data) {
	Toast *toast = new Toast("开始上课");

	// ——开启成功
	this->m_lesson_timer.start(1000);  // 开启定时器
	this->updateBeginTime((int)data["begin_timestamp"].toDouble());

	toast->show();
	this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);

	// ——更新按钮功能
	this->m_ui.begin_lesson_btn->setText("结束课堂");
	this->disconnect(this->m_ui.begin_lesson_btn, &QPushButton::clicked, 
		this, &TeacherOnlineClassroomWidget::beginLesson);
	this->connect(this->m_ui.begin_lesson_btn, &QPushButton::clicked, 
		this, &TeacherOnlineClassroomWidget::endLesson);

	return;
}

void TeacherOnlineClassroomWidget::handleCommandEndLesson(QJsonObject &data) {
	Toast *toast = new Toast;

	// ——结束成功
	this->m_lesson_timer.stop();

	toast->setInfoText(QString("课堂已结束"));
	toast->show();
	this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);

	this->m_ui.begin_lesson_btn->setText("开始上课");
	this->disconnect(this->m_ui.begin_lesson_btn, &QPushButton::clicked,
		this, &TeacherOnlineClassroomWidget::endLesson);
	this->connect(this->m_ui.begin_lesson_btn, &QPushButton::clicked,
		this, &TeacherOnlineClassroomWidget::beginLesson);

	return;
}

void TeacherOnlineClassroomWidget::createLesson(QString &course_id, QString &course_name) {
	QJsonObject request_json_obj;

	this->createLessonConnection();

	request_json_obj["command"] = TransportCmd::CreateLesson;
	request_json_obj["account_type"] = AccountType::Teacher;
	request_json_obj["course_id"] = course_id;
	request_json_obj["course_name"] = course_name;
	request_json_obj["uid"] = User::G_UID;
	request_json_obj["username"] = User::G_USERNAME;

	this->m_lesson_connection->realSend(request_json_obj);

	return;
}

void TeacherOnlineClassroomWidget::beginLesson() {
	QJsonObject request_json_obj;
	QMap<QString, QVariant> data;

	request_json_obj["command"] = TransportCmd::BeginLesson;
	this->lessonConnectionSend(request_json_obj);

	// ——建立画板连接
	this->m_interaction_widget->whiteBoardWidget()->
		createPaintConnection(this->m_room["course_id"].toString(),
			this->m_room["lesson_id"].toString());

	return;
}

void TeacherOnlineClassroomWidget::endLesson() {
	QJsonObject request_json_obj;

	request_json_obj["command"] = TransportCmd::EndLesson;
	this->lessonConnectionSend(request_json_obj);

	return;
}

void TeacherOnlineClassroomWidget::showHandleRaiseHandWidget() {
	Ui::TeacherOnlineClassroomFunctionButtonWidget btn_ui =
		this->m_function_button_widget->ui();
	/*
		初始化位置
	*/
	int btn_width = btn_ui.raise_hand_btn->width(),
		btn_height = btn_ui.raise_hand_btn->height(),
		btn_x = btn_ui.raise_hand_btn->x(),
		btn_y = btn_ui.raise_hand_btn->y(),

		widget_width = this->m_handle_raise_hand_widget->width(),
		widget_height = this->m_handle_raise_hand_widget->height(),
		widget_x = btn_x - widget_width + btn_width,
		widget_y = btn_y + btn_height;
	QPoint pos = this->mapToGlobal(QPoint(widget_x, widget_y));

	this->m_handle_raise_hand_widget->
		setGeometry(pos.x(), pos.y(), widget_width, widget_height);
	this->m_handle_raise_hand_widget->show();

	return;
}

