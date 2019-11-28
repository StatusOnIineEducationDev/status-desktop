#include "s_onlineclassroomWidget.h"


StudentOnlineClassroomWidget::StudentOnlineClassroomWidget(QWidget *parent) 
	: OnlineClassroomWidget(parent), m_function_button_widget(nullptr),
	m_in_speech_removeable_widget(nullptr), m_interaction_widget(nullptr) {
	
	this->init();

	this->loadEnterDialog();
	this->loadFunctionButtonWidget();
	this->loadFunctionPageWidget();
	this->loadInSpeechRemovableWidget();
}

StudentOnlineClassroomWidget::~StudentOnlineClassroomWidget() {

}

void StudentOnlineClassroomWidget::init() {
	this->m_ui.begin_lesson_btn->setDisabled(true);
	this->m_ui.begin_lesson_btn->setText("δ��ʼ");

	// �����źŰ�
	this->connect(&this->m_lesson_timer, &QTimer::timeout, 
		this, &StudentOnlineClassroomWidget::sendMineCameraFrame);
}

void StudentOnlineClassroomWidget::loadEnterDialog() {
	// �������ؽ���Ի���
	QMap<QString, QVariant> *course;
	QList<QMap<QString, QVariant>> course_list;
	QList<CourseBase> *course_base_list = User::G_COURSES_BASE_LIST;
	this->m_enter_dialog = new StudentEnterDialog(this);
	this->connect(this->m_enter_dialog, &StudentEnterDialog::joinInLesson,
		this, &StudentOnlineClassroomWidget::joinInLesson);
	// ������������
	for (int index = 0; index < course_base_list->count(); index++) {
		course = new QMap<QString, QVariant>;
		course->insert("course_id", course_base_list->at(index).courseId());
		course->insert("course_name", course_base_list->at(index).courseName());
		course_list.append(*course);
	}
	this->m_enter_dialog->loadData(course_list);
	this->m_enter_dialog->setModal(true);  // ģ̬��������ֱ����exec()������
	this->m_enter_dialog->show();

	return;
}

void StudentOnlineClassroomWidget::loadFunctionButtonWidget() {
	// �������ع�����
	this->m_function_button_widget = new StudentOnlineClassroomFunctionButtonWidget(this);
	this->m_ui.function_btn_widget_layout->
		addWidget(this->m_function_button_widget);

	// �����ź�����
	Ui::StudentOnlineClassroomFunctionButtonWidget btn_ui =
		this->m_function_button_widget->ui();
	this->connect(btn_ui.quit_lesson_btn, &QPushButton::clicked,
		this, &StudentOnlineClassroomWidget::quitLesson);
	this->connect(btn_ui.raise_hand_btn, &QPushButton::clicked,
		this, &StudentOnlineClassroomWidget::raiseHand);

	return;
}

void StudentOnlineClassroomWidget::loadFunctionPageWidget() {
	// �������ػ���ҳ
	this->loadInteractionPageWidget();

	return;
}

void StudentOnlineClassroomWidget::loadInteractionPageWidget() {
	// �������ػ���ҳ
	this->m_interaction_widget = new StudentInteractionWidget(this);
	this->m_ui.function_tabWidget->addTab(this->m_interaction_widget, "����");

	this->m_interaction_widget->whiteBoardWidget()->
		setInteractiveWhiteBoardDisabled(true);

	// �����źŰ�
	this->connect(this->m_interaction_widget->chatAndInSpeechWidget(),
		&ChatAndInSpeechWidget::lessonConnectionDataReady,
		this, &StudentOnlineClassroomWidget::lessonConnectionSend);

	return;
}

void StudentOnlineClassroomWidget::loadInSpeechRemovableWidget() {
	this->m_in_speech_removeable_widget = new StudentInSpeechRemovableWidget(this);
	
	// �����źŰ�
	Ui::StudentInSpeechRemovableWidget ui = 
		this->m_in_speech_removeable_widget->ui();
	this->connect(ui.end_btn, &QPushButton::clicked,
		this, &StudentOnlineClassroomWidget::endSpeech);

	return;
}

void StudentOnlineClassroomWidget::handleLessonConnectionRecv() {
	QJsonObject data = this->m_lesson_connection->recv();
	TransportCmd cmd = TransportCmd(data["command"].toInt());

	switch (cmd) {
	case TransportCmd::JoinInLesson: 
		this->handleCommandJoinInLesson(data); break;
	case TransportCmd::BeginLesson:
		this->handleCommandBeginLesson(data); break;
	case TransportCmd::EndLesson: 
		this->handleCommandEndLesson(data); break;
	case TransportCmd::QuitLesson:
		this->handleCommandQuitLesson(data); break;
	case TransportCmd::RaiseHand: 
		this->handleCommandRaiseHand(data); break;
	case TransportCmd::ResultOfRaiseHand: 
		this->handleCommandResultOfRaiseHand(data); break;
	case TransportCmd::RemoveMemberFromInSpeech: 
		this->handleCommandRemoveMemberFromInSpeech(data); 
		this->m_interaction_widget->chatAndInSpeechWidget()->
			handleCommandRemoveMemberFromInSpeech(data); break;
	case TransportCmd::ConcentrationFinalData:
		this->handleCommandConcentrationFinalData(data); break;

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

void StudentOnlineClassroomWidget::handleCommandJoinInLesson(QJsonObject &data) {
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
		this->updateLessonInfo(
			data["course_name"].toString(), 
			data["course_id"].toString(),
			data["lesson_id"].toString(), 
			data["teacher_name"].toString(),
			data["teacher_id"].toString(), 
			course_status, 
			(int)data["create_timestamp"].toDouble(),
			(int)data["begin_timestamp"].toDouble());

		User::G_USER_STATUS = UserStatus::InClass;

		this->m_ui.begin_lesson_btn->setText("�����Ͽ�");

		this->openCamera();
		//QtConcurrent::run(this, &StudentOnlineClassroomWidget::openCamera);
		this->m_enter_dialog->hide();
		this->m_enter_dialog->deleteLater();
		this->lessonBegin();
		break;
	case CourseStatus::CantJoinIn:
		text = "�ÿ��ò�������;����";
		this->distroyLessonConnection();
		break;
	case CourseStatus::Waiting:
		text = "����ɹ�";

		// ������ʼ�����䣨���ã�����
		this->updateLessonInfo(
			data["course_name"].toString(),
			data["course_id"].toString(),
			data["lesson_id"].toString(),
			data["teacher_name"].toString(),
			data["teacher_id"].toString(),
			course_status,
			data["create_timestamp"].toInt());

		User::G_USER_STATUS = UserStatus::InRoom;

		this->openCamera();
		//QtConcurrent::run(this, &StudentOnlineClassroomWidget::openCamera);
		this->m_enter_dialog->hide();
		this->m_enter_dialog->deleteLater();
		break;
	}
	toast->setInfoText(text);
	toast->show();
	this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);

	return;
}

void StudentOnlineClassroomWidget::handleCommandBeginLesson(QJsonObject &data) {
	// ���������ɹ�
	this->updateBeginTime((int)data["begin_timestamp"].toDouble());
	this->lessonBegin();

	return;
}

void StudentOnlineClassroomWidget::handleCommandConcentrationData(QJsonObject &data) {

}

void StudentOnlineClassroomWidget::handleCommandEndLesson(QJsonObject &data) {
	Toast *toast = new Toast;

	// ���������ɹ�
	this->m_lesson_timer.stop();

	this->m_ui.begin_lesson_btn->setText("�ѽ���");

	User::G_USER_STATUS = UserStatus::Free;

	toast->setInfoText(QString("�����ѽ���"));
	toast->show();
	this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);

	return;
}

void StudentOnlineClassroomWidget::handleCommandQuitLesson(QJsonObject &data) {
	User::G_USER_STATUS = UserStatus::Free;

	emit this->quitLessonSuccess();

	return;
}

void StudentOnlineClassroomWidget::handleCommandRaiseHand(QJsonObject &data) {
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

void StudentOnlineClassroomWidget::handleCommandResultOfRaiseHand(QJsonObject &data) {
	QMap<QString, QVariant> info;

	if (ApplicationStatus(data["application_status"].toInt()) == ApplicationStatus::Accepted) {
		info["student_id"] = data["student_id"].toString();
		info["username"] = data["username"].toString();

		this->m_interaction_widget->chatAndInSpeechWidget()->
			addMemberToInSpeech(info);

		// ���������Լ������󱻽���
		if (data["student_id"].toString() == User::G_UID) {
			this->showInSpeechRemovableWidget();
			this->m_interaction_widget->whiteBoardWidget()->
				setInteractiveWhiteBoardDisabled(false);  // �ͷŻ������
		}
	}

	return;
}

void StudentOnlineClassroomWidget::handleCommandRemoveMemberFromInSpeech(QJsonObject &data) {
	Toast *toast = new Toast;

	// ������������Լ�������
	if (data["student_id"].toString() == User::G_UID) {
		this->disconnect(&this->m_lesson_timer, &QTimer::timeout, 
			this->m_in_speech_removeable_widget, 
			&StudentInSpeechRemovableWidget::updateInSpeechLastTime);
		this->m_in_speech_removeable_widget->hide();
		this->m_in_speech_removeable_widget->ui().time_text->setText("00:00:00");

		toast->setInfoText("�����ѽ���");
		toast->show();
		this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);

		this->m_interaction_widget->whiteBoardWidget()->
			setInteractiveWhiteBoardDisabled(true);  // �װ岻����

	}

	return;
}

void StudentOnlineClassroomWidget::handleCommandConcentrationFinalData(QJsonObject &data) {
	QMap<QString, QVariant> info;

	info["concentration_value"] = data["concentration_value"].toInt();
	info["fatigue_value"] = data["fatigue_value"].toInt();
	info["toward_score"] = data["toward_score"].toInt();
	info["emotion_score"] = data["emotion_score"].toInt();
	info["concentration_timestamp"] = data["concentration_timestamp"].toInt();
	this->m_final_data_list.append(info);

	this->updateDynamicAreaChat(data["concentration_timestamp"].toInt(), 
		data["concentration_value"].toInt());

	return;
}

void StudentOnlineClassroomWidget::joinInLesson(QString &course_id, QString &course_name) {
	QJsonObject request_json_obj;

	this->createLessonConnection();

	request_json_obj["command"] = TransportCmd::JoinInLesson;
	request_json_obj["account_type"] = AccountType::Student;
	request_json_obj["course_id"] = course_id;
	request_json_obj["course_name"] = course_name;
	request_json_obj["uid"] = User::G_UID;
	request_json_obj["username"] = User::G_USERNAME;

	this->m_lesson_connection->realSend(request_json_obj);

	return;
}

void StudentOnlineClassroomWidget::lessonBegin() {
	QJsonObject paint_request_json_obj;
	Toast *toast = new Toast("��ʼ�Ͽ�");

	User::G_USER_STATUS = UserStatus::InClass;

	this->m_lesson_timer.start(1000);  // ������ʱ��

	// ����������������
	this->m_interaction_widget->whiteBoardWidget()->
		createPaintConnection(this->m_room["course_id"].toString(), 
			this->m_room["lesson_id"].toString());

	this->m_ui.begin_lesson_btn->setText("�����Ͽ�");
	toast->show();
	this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);

	return;
}

void StudentOnlineClassroomWidget::quitLesson() {
	QJsonObject request_json_obj;

	switch (User::G_USER_STATUS) {
	case UserStatus::InClass:
	case UserStatus::InRoom:
		request_json_obj["command"] = TransportCmd::QuitLesson;
		this->lessonConnectionSend(request_json_obj);
		break;
	case UserStatus::Free:
		emit this->quitLessonSuccess();
		break;
	}

	return;
}

void StudentOnlineClassroomWidget::raiseHand() {
	QJsonObject request_json_obj;

	// ������������
	request_json_obj["command"] = TransportCmd::RaiseHand;
	request_json_obj["raise_hande_timestamp"] = (int)QDateTime::currentDateTime().toTime_t();

	this->lessonConnectionSend(request_json_obj);

	return;
}

void StudentOnlineClassroomWidget::showInSpeechRemovableWidget() {
	this->connect(&this->m_lesson_timer, &QTimer::timeout, 
		this->m_in_speech_removeable_widget, 
		&StudentInSpeechRemovableWidget::updateInSpeechLastTime);

	m_in_speech_removeable_widget->show();

	return;
}

void StudentOnlineClassroomWidget::endSpeech() {
	QJsonObject request_json_obj;

	request_json_obj["command"] = TransportCmd::RemoveMemberFromInSpeech;
	request_json_obj["student_id"] = User::G_UID;
	this->lessonConnectionSend(request_json_obj);

	return;
}