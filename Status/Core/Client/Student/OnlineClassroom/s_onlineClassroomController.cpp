#include "s_onlineClassroomController.h"


SOnlineClassroomController::SOnlineClassroomController(User *user, QObject *parent)
	:QObject(parent), m_enter_controller(nullptr), m_white_board_controller(nullptr),
	m_chat_controller(nullptr), m_concentration_controller(nullptr), 
	m_online_classroom_widget(nullptr),m_in_speech_removeable_widget(nullptr), 
	m_user(user), m_camera(nullptr), m_lesson_connection(nullptr) {
	this->connect(&this->m_lesson_timer, &QTimer::timeout, this, &SOnlineClassroomController::updateLastTime);
	this->connect(&this->m_lesson_timer, &QTimer::timeout, this, &SOnlineClassroomController::sendMineCameraFrame);
}

SOnlineClassroomController::~SOnlineClassroomController() {
	delete this->m_online_classroom_widget;
}

void SOnlineClassroomController::showOnlineClassroomWidget(SMainWindow *parent) {
	QMap<QString, QVariant> *course;
	QList<QMap<QString, QVariant>> course_list;
	QList<CourseBase> *course_base_list = this->m_user->coursesBaseList();

	if (this->m_online_classroom_widget == nullptr) {
		this->initOnlineClassroomWidget(parent);
		this->initController();

		// ������������
		for (int index = 0; index < course_base_list->count(); index++) {
			course = new QMap<QString, QVariant>;
			course->insert("course_id", course_base_list->at(index).courseId());
			course->insert("course_name", course_base_list->at(index).courseName());
			course_list.append(*course);
		}
		// ������ʾ
		this->m_enter_controller->showEnterDialog(this->m_online_classroom_widget, course_list);
	}

	// ������ʾ
	parent->ui().widget_layout->addWidget(this->m_online_classroom_widget);
	this->m_online_classroom_widget->show();

	return;
}

void SOnlineClassroomController::hideOnlineClassroomWidget(SMainWindow *parent) {
	// ������ʾ
	parent->ui().widget_layout->removeWidget(this->m_online_classroom_widget);
	this->m_online_classroom_widget->hide();
	
	return;
}

void SOnlineClassroomController::lessonConnectionSend(QJsonObject &data) {
	// ������������
	data["account_type"] = AccountType::Student;
	data["course_id"] = this->m_room.courseId();
	data["lesson_id"] = this->m_room.lessonId();
	data["uid"] = this->m_user->uid();
	data["username"] = this->m_user->username();

	// �������ﲻ��send������ᱨ���̴߳���
	this->m_lesson_connection->realSend(data);
}

void SOnlineClassroomController::initOnlineClassroomWidget(SMainWindow *parent) {
	Ui::SOnlineClassroomWidget ui;

	// ��������online_classroom_widget
	this->m_online_classroom_widget = new SOnlineClassroomWidget(parent);
	this->initAffiliatedWidget();
	ui = this->m_online_classroom_widget->ui();

	// �����źŰ�
	this->connect(parent, &SMainWindow::windowResized, this->m_online_classroom_widget, &SOnlineClassroomWidget::handleWindowResized);
	this->connect(ui.raise_hand_btn, &QPushButton::clicked, this, &SOnlineClassroomController::raiseHand);

	// ������������
	ui.flexible_main_area->hide();  // flexible_main_areaĬ������

	return;
}

void SOnlineClassroomController::initAffiliatedWidget() {
	Ui::SInSpeechRemovableWidget in_speech_ui;

	// ����in_speech_removeable_widget
	this->m_in_speech_removeable_widget = new SInSpeechRemovableWidget(this->m_online_classroom_widget);
	in_speech_ui = this->m_in_speech_removeable_widget->ui();
	this->m_in_speech_removeable_widget->hide();
	this->connect(in_speech_ui.end_btn, &QPushButton::clicked, this, &SOnlineClassroomController::endSpeech);
	
	return;
}

void SOnlineClassroomController::initController() {
	this->m_enter_controller = new SEnterController(this);
	this->m_white_board_controller = new SWhiteBoardController(this->m_online_classroom_widget, this);
	this->m_chat_controller = new SChatController(this->m_online_classroom_widget, this);
	this->m_concentration_controller = new SConcentrationController(this->m_online_classroom_widget, this);

	this->connect(m_enter_controller, &SEnterController::joinInLesson, this, &SOnlineClassroomController::joinInLesson);
	this->connect(m_chat_controller, &SChatController::lessonConnectionDataReady, this, &SOnlineClassroomController::lessonConnectionSend);
	
	return;
}

void SOnlineClassroomController::createLessonConnection() {
	this->m_lesson_connection = new Connection;
	QThread *connection_thread = new QThread(this->m_online_classroom_widget);
	this->m_lesson_connection->moveToThread(connection_thread);
	connection_thread->start();

	this->m_lesson_connection->connect(ReadConf::G_SOCKET_HOST, ReadConf::G_SOCKET_PORT);

	// �����źŰ�
	this->connect(this->m_lesson_connection, &Connection::bufferReadyRead, this, &SOnlineClassroomController::handleLessonConnectionRecv);

	return;
}

void SOnlineClassroomController::distroyLessonConnection() {
	QThread *thread;
	
	if (this->m_lesson_connection != nullptr) {
		thread = this->m_lesson_connection->thread();
		delete this->m_lesson_connection;
		this->m_lesson_connection = nullptr;
		thread->exit(0);
		this->connect(thread, &QThread::finished, thread, &QThread::deleteLater);
	}
	
	return;
}

void SOnlineClassroomController::handleLessonConnectionRecv() {
	QJsonObject data = this->m_lesson_connection->recv();
	TransportCmd cmd = TransportCmd(data["command"].toInt());

	switch (cmd) {
	case TransportCmd::JoinInLesson: handleCommandJoinInLesson(data); break;
	case TransportCmd::BeginLesson: handleCommandBeginLesson(data); break;
	case TransportCmd::EndLesson: handleCommandEndLesson(data); break;
	case TransportCmd::SendChatContent: this->m_chat_controller->handleCommandSendChatContent(data); break;
	case TransportCmd::RecvChatContent: this->m_chat_controller->handleCommandRecvChatContent(data); break;
	case TransportCmd::ChatBan: this->m_chat_controller->handleCommandChatBan(data); break;
	case TransportCmd::RaiseHand: handleCommandRaiseHand(data); break;
	case TransportCmd::ResultOfRaiseHand: handleCommandResultOfRaiseHand(data); break;
	case TransportCmd::RemoveMemberFromInSpeech: handleCommandRemoveMemberFromInSpeech(data); break;
	case TransportCmd::ConcentrationFinalData: this->m_concentration_controller->handleCommandConcentrationFinalData(data); break;
	case TransportCmd::ConcentrationRealTimeData: this->m_concentration_controller->handleCommandConcentrationRealTimeData(data); break;

	}

	return;
}

void SOnlineClassroomController::handleCommandJoinInLesson(QJsonObject &data) {
	Ui::SOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();
	CourseStatus course_status = CourseStatus(data["course_status"].toInt());
	Toast *toast = new Toast;
	const CourseBase *course;
	QString text;
	QThread *thread;

	switch (course_status) {
	case CourseStatus::OffLine:
		text = "�γ�δ��ʼ";
		this->distroyLessonConnection();
		break;
	case CourseStatus::OnLine:
		text = "����ɹ�";

		// ������ʼ�����䣨���ã�����
		this->m_room.setRoomName(data["course_name"].toString());
		this->m_room.setCourseId(data["course_id"].toString());
		this->m_room.setLessonId(data["lesson_id"].toString());
		this->m_room.setTeacherId(data["teacher_id"].toString());
		this->m_room.setTeacherName(data["teacher_name"].toString());
		this->m_room.setStatus(course_status);

		this->m_user->setUserStatus(UserStatus::InClass);

		ui.lesson_status_btn->setText("�����Ͽ�");

		this->openCamera();
		this->updateRoomInfo(data);
		this->m_enter_controller->hideEnterDialog();
		this->lessonBegin();
		break;
	case CourseStatus::CantJoinIn:
		text = "�ÿ��ò�������;����";
		this->distroyLessonConnection();
		break;
	case CourseStatus::Waiting:
		text = "����ɹ�";

		// ������ʼ�����䣨���ã�����
		this->m_room.setRoomName(data["course_name"].toString());
		this->m_room.setCourseId(data["course_id"].toString());
		this->m_room.setLessonId(data["lesson_id"].toString());
		this->m_room.setTeacherId(data["teacher_id"].toString());
		this->m_room.setTeacherName(data["teacher_name"].toString());
		this->m_room.setStatus(course_status);

		this->m_user->setUserStatus(UserStatus::InClass);

		this->openCamera();
		this->updateRoomInfo(data);
		this->m_enter_controller->hideEnterDialog();
		break;
	}
	toast->setInfoText(text);
	toast->show();
	this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);

	return;
}

void SOnlineClassroomController::handleCommandBeginLesson(QJsonObject &data) {
	// ���������ɹ�
	this->m_room.setBeginTime(QDateTime::fromTime_t(data["begin_timestamp"].toDouble()));
	this->lessonBegin();

	return;
}

void SOnlineClassroomController::handleCommandConcentrationData(QJsonObject &data) {

}

void SOnlineClassroomController::handleCommandEndLesson(QJsonObject &data) {
	Ui::SOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();
	Toast *toast = new Toast;
	QThread *thread;

	// ���������ɹ�
	this->m_camera->deleteLater();
	this->m_lesson_timer.stop();
	this->distroyLessonConnection();
	this->m_white_board_controller->distroyPaintConnection();

	this->m_user->setUserStatus(UserStatus::Free);

	toast->setInfoText(QString("�����ѽ���"));
	toast->show();
	this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);

	return;
}

void SOnlineClassroomController::handleCommandRaiseHand(QJsonObject &data) {
	Toast *toast = new Toast;

	switch (RaiseHandError(data["raise_hand_err"].toInt())) {
	case RaiseHandError::NoError:
		toast->setInfoText("�����ѷ���");
		toast->show();
		this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);
		break;
	case RaiseHandError::InSpeechError:
		toast->setInfoText("�����ڷ���״̬��");
		toast->show();
		this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);
		break;
	case RaiseHandError::ApplyingError:
		toast->setInfoText("���ѷ������룬�����ĵȺ��ʦ��Ӧ");
		toast->show();
		this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);
		break;
	}

	return;
}

void SOnlineClassroomController::handleCommandResultOfRaiseHand(QJsonObject &data) {
	QMap<QString, QVariant> info;

	if (ApplicationStatus(data["application_status"].toInt()) == ApplicationStatus::Accepted) {
		info["student_id"] = data["student_id"].toString();
		info["username"] = data["username"].toString();

		this->m_in_speech_list.append(info);
		this->updateInSpeechWidgetInfo();

		// ���������Լ������󱻽���
		if (data["student_id"].toString() == this->m_user->uid()) {
			this->showInSpeechRemovableWidget();
		}
	}

	return;
}

void SOnlineClassroomController::handleCommandRemoveMemberFromInSpeech(QJsonObject &data) {
	Toast *toast = new Toast;

	for (int index = 0; index < this->m_in_speech_list.count(); index++) {
		if (this->m_in_speech_list[index]["student_id"].toString() == data["student_id"].toString()) {
			this->m_in_speech_list.removeAt(index);
			break;
		}
	}
	this->updateInSpeechWidgetInfo();

	// ������������Լ�������
	if (data["student_id"].toString() == this->m_user->uid()) {
		this->disconnect(&this->m_lesson_timer, &QTimer::timeout, this, &SOnlineClassroomController::updateInSpeechLastTime);
		this->m_in_speech_removeable_widget->hide();
		this->m_in_speech_removeable_widget->ui().time_text->setText("00:00:00");

		toast->setInfoText("�����ѽ���");
		toast->show();
		this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);
	}
	
	return;
}

void SOnlineClassroomController::joinInLesson(QMap<QString, QVariant> &data) {
	/*
		|-data(QMap<QString, QVariant>)
			|-course_id(QString)
			|-course_name(QString)
	*/
	QJsonObject request_json_obj;

	this->createLessonConnection();

	request_json_obj["command"] = TransportCmd::JoinInLesson;
	request_json_obj["account_type"] = AccountType::Student;
	request_json_obj["course_id"] = data["course_id"].toString();
	request_json_obj["course_name"] = data["course_name"].toString();
	request_json_obj["uid"] = this->m_user->uid();
	request_json_obj["username"] = this->m_user->username();

	this->m_lesson_connection->realSend(request_json_obj);

	return;
}

void SOnlineClassroomController::lessonBegin() {
	Ui::SOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();
	QJsonObject paint_request_json_obj;
	Toast *toast = new Toast("��ʼ�Ͽ�");

	this->m_lesson_timer.start(1000);  // ������ʱ��

	// ����ˢ��ui
	ui.begin_time_text->setText(this->m_room.beginTime().toString("hh:mm:ss"));

	// ����������������
	this->m_white_board_controller->createPaintConnection(this->m_room.courseId(), 
		this->m_room.lessonId(), this->m_user->uid());

	ui.lesson_status_btn->setText("�����Ͽ�");
	toast->show();
	this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);

	return;
}

void SOnlineClassroomController::openCamera() {
	this->m_camera = new Camera(this->m_online_classroom_widget);

	this->connect(this->m_camera, &Camera::readyRead, this, &SOnlineClassroomController::mineCameraDisplay);

	this->m_camera->open();

	return;
}

void SOnlineClassroomController::mineCameraDisplay(QImage &frame) {
	Ui::SOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();

	ui.mine_camera_label->setPixmap(QPixmap::fromImage(frame));

	return;
}

void SOnlineClassroomController::sendMineCameraFrame() {
	cv::Mat frame_mat = this->m_camera->getFrameMat();
	QJsonObject json_obj;

	// ����cv::Mat ת base64
	std::vector<unsigned char> mat_encode_vector;
	std::string mat_encode_str;
	const char *mat_encode_char;
	QString base64_str;

	cv::imencode(".jpg", frame_mat, mat_encode_vector);
	mat_encode_str.append(mat_encode_vector.begin(), mat_encode_vector.end());
	mat_encode_char = mat_encode_str.c_str();
	base64_str = QString::fromStdString(base64_encode(mat_encode_char, mat_encode_str.size()));

	json_obj["command"] = TransportCmd::StudentCameraFrameData;
	json_obj["frame_mat"] = base64_str;
	json_obj["timestamp"] = int(QDateTime::currentDateTime().toTime_t());
	this->lessonConnectionSend(json_obj);

	return;
}

void SOnlineClassroomController::updateRoomInfo(const QJsonObject &data) {
	Ui::SOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();

	// ������ʼ�����䣨���ã�����
	this->m_room.setRoomName(data["course_name"].toString());
	this->m_room.setCourseId(data["course_id"].toString());
	this->m_room.setLessonId(data["lesson_id"].toString());
	this->m_room.setTeacherId(data["teacher_id"].toString());
	this->m_room.setTeacherName(data["teacher_name"].toString());
	this->m_room.setCreateTime(QDateTime::fromTime_t(data["create_timestamp"].toDouble()));
	this->m_room.setBeginTime(QDateTime::fromTime_t(data["begin_timestamp"].toDouble()));

	// ����ˢ��ui
	ui.room_name_text->setText(this->m_room.roomName());
	ui.lesson_id_text->setText(this->m_room.lessonId());
	ui.teacher_name_text->setText(this->m_room.teacherName());
	ui.create_time_text->setText(this->m_room.createTime().toString("hh:mm:ss"));

	return;
}

void SOnlineClassroomController::updateLastTime() {
	Ui::SOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();
	int now_timestamp = QDateTime::currentDateTime().toTime_t(),
		begin_timestamp = this->m_room.beginTime().toTime_t();

	/*
		������Ҫ׼ȷ��ʱ
		����ʱ����������ʱ��
	*/
	ui.last_time_text->setText(formatTime(now_timestamp - begin_timestamp));

	return;
}

void SOnlineClassroomController::raiseHand() {
	Ui::SOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();
	QJsonObject request_json_obj;
	Toast *toast;

	// ������������
	request_json_obj["command"] = TransportCmd::RaiseHand;
	request_json_obj["timestamp"] = (int)QDateTime::currentDateTime().toTime_t();

	this->lessonConnectionSend(request_json_obj);

	return;
}

void SOnlineClassroomController::updateInSpeechWidgetInfo() {
	Ui::SOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();
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

void SOnlineClassroomController::showInSpeechRemovableWidget() {
	Ui::SInSpeechRemovableWidget ui = m_in_speech_removeable_widget->ui();

	this->connect(&this->m_lesson_timer, &QTimer::timeout, this, &SOnlineClassroomController::updateInSpeechLastTime);

	m_in_speech_removeable_widget->show();

	return;
}

void SOnlineClassroomController::updateInSpeechLastTime() {
	Ui::SInSpeechRemovableWidget ui = m_in_speech_removeable_widget->ui();
	QString time_text = ui.time_text->text();
	static int count = 0;

	/*
		����ļ�ʱ��׼ȷ��ʱ����˲���¼ʱ��
		���ǲ��þ�̬�����Ļ�������Ҫ����
		��time_textΪ��0��������count
		�ڽ������Ժ󣬻Ὣtime_text����Ϊ��00:00:00��������һ������flag
	*/
	if (time_text == "00:00:00") {
		count = 0;
	}

	count++;
	ui.time_text->setText(formatTime(count));

	return;
}

void SOnlineClassroomController::endSpeech() {
	QJsonObject request_json_obj;

	request_json_obj["command"] = TransportCmd::RemoveMemberFromInSpeech;
	request_json_obj["student_id"] = this->m_user->uid();
	this->lessonConnectionSend(request_json_obj);

	return;
}