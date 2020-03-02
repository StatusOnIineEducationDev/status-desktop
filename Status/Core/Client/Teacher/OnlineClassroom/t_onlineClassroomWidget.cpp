#include "t_onlineClassroomWidget.h"


TeacherOnlineClassroomWidget::TeacherOnlineClassroomWidget(MainWindow *parent)
	: OnlineClassroomWidget(parent), m_function_button_widget(nullptr),
	m_interaction_widget(nullptr) {

	this->init();
	this->loadEnterDialog();
	this->loadFunctionButtonWidget();
	this->loadFunctionPageWidget();
	this->loadHandleRaiseHandWidget();
	this->loadWaitingMask();  // ���һ��Ҫ�������һ��load

	this->createLessonConnection();
}

TeacherOnlineClassroomWidget::~TeacherOnlineClassroomWidget() {
	this->distroyLessonConnection();
}

void TeacherOnlineClassroomWidget::init() {
	this->m_ui.begin_lesson_btn->setText("��ʼ�Ͽ�");

	// �����źŰ�
	this->connect(this->m_ui.begin_lesson_btn, &QPushButton::clicked,
		this, &TeacherOnlineClassroomWidget::beginLesson);
}

void TeacherOnlineClassroomWidget::loadEnterDialog() {
	// �������ؽ���Ի���
	QMap<QString, QVariant> *course;
	QList<QMap<QString, QVariant>> course_list;
	QList<CourseBasic> course_basic_list = user->getCourseList();
	this->m_enter_dialog = new TeacherEnterDialog(this);
	this->connect(this->m_enter_dialog, &TeacherEnterDialog::createLesson,
		this, &TeacherOnlineClassroomWidget::createLesson);
	this->connect(this->m_enter_dialog->ui().close_btn, &QPushButton::clicked,
		this, &TeacherOnlineClassroomWidget::emitSignalCloseEnterDialog);
	// ������������
	for (int index = 0; index < course_basic_list.count(); index++) {
		course = new QMap<QString, QVariant>;
		course->insert("course_id", course_basic_list.at(index).courseId());
		course->insert("course_name", course_basic_list.at(index).courseName());
		course_list.append(*course);
	}
	this->m_enter_dialog->loadData(course_list);
	this->m_enter_dialog->setModal(true);  // ģ̬��������ֱ����exec()������
	this->m_enter_dialog->show();

	return;
}

void TeacherOnlineClassroomWidget::loadFunctionButtonWidget() {
	// �������ع�����
	this->m_function_button_widget = new TeacherOnlineClassroomFunctionButtonWidget(this);
	this->m_ui.function_btn_widget_layout->
		addWidget(this->m_function_button_widget);

	// �����ź�����
	Ui::TeacherOnlineClassroomFunctionButtonWidget btn_ui =
		this->m_function_button_widget->ui();
	this->connect(btn_ui.raise_hand_btn, &QPushButton::clicked,
		this, &TeacherOnlineClassroomWidget::showHandleRaiseHandWidget);
	this->connect(btn_ui.quit_lesson_btn, &QPushButton::clicked,
		this, &TeacherOnlineClassroomWidget::endLessonInquire);

	return;
}

void TeacherOnlineClassroomWidget::loadFunctionPageWidget() {
	// �������ػ���ҳ
	this->loadInteractionPageWidget();
	// �������ؿ��÷���ҳ
	this->loadLessonAnalysisPageWidget();

	return;
}

void TeacherOnlineClassroomWidget::loadInteractionPageWidget() {
	// �������ػ���ҳ
	this->m_interaction_widget = new TeacherInteractionWidget(this);
	this->m_ui.function_tabWidget->addTab(this->m_interaction_widget, "����");

	// �����źŰ�
	this->connect(this->m_interaction_widget->chatAndInSpeechWidget(),
		&ChatAndInSpeechWidget::lessonConnectionDataReady,
		this, &TeacherOnlineClassroomWidget::lessonConnectionSend);

	return;
}

void TeacherOnlineClassroomWidget::loadLessonAnalysisPageWidget() {
	// �������ؿ��÷���ҳ
	this->m_lesson_analysis_widget = new TeacherLessonAnalysisWidget(this);
	this->m_ui.function_tabWidget->addTab(this->m_lesson_analysis_widget, "����");

	// �����źŰ�
	this->connect(this->m_lesson_analysis_widget, 
		&TeacherLessonAnalysisWidget::lessonConnectionDataReady,
		this, &TeacherOnlineClassroomWidget::lessonConnectionSend);

	return;
}

void TeacherOnlineClassroomWidget::loadHandleRaiseHandWidget() {
	this->m_handle_raise_hand_widget = new TeacherHandleRaiseHandWidget(this);

	// �����źŰ�
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
	case TransportCmd::JoinInLesson:
		this->handleCommandJoinInLesson(data); break;
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

	case TransportCmd::RefreshOnlineList:
		this->handleCommandRefreshOnlineList(data);
		this->m_lesson_analysis_widget->handleCommandRefreshOnlineList(data); break;
	case TransportCmd::GetStudentConc:
		this->m_lesson_analysis_widget->handleCommandGetStudentConc(data); break;
	}

	return;
}

void TeacherOnlineClassroomWidget::handleCommandCreateLesson(QJsonObject &data) {
	CourseStatus course_status = CourseStatus::Waiting;
	Toast *toast = new Toast;
	TipsDialog *dialog = new TipsDialog;

	// �洢��������
	this->m_room["course_id"] = data["course_id"].toString();
	this->m_room["course_name"] = data["course_name"].toString();

	//user->setUserStatus(UserStatus::InClass);

	//this->openCamera();
	////QtConcurrent::run(this, &TOnlineClassroomController::openCamera);
	//this->m_enter_dialog->hide();
	//this->m_enter_dialog->deleteLater();

	if (data["is_succeed"].toBool()) {
		toast->setInfoText(QString("�����ɹ�"));
		toast->show();
		this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);
		this->joinInLesson();
	}
	else {
		toast->setInfoText(QString("���ô���ʧ�ܣ�������"));
		toast->show();
		this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);

		// ���½���
		dialog->setText(QString("����һ�����ڽ��еĿ��ã��Ƿ����½��룿"));
		dialog->setConfirmText(QString("���½���"));
		dialog->setCancelText(QString("ȡ��"));
		this->connect(dialog, &TipsDialog::confirm,
			this, &TeacherOnlineClassroomWidget::joinInLesson);

		dialog->setModal(true);  // ģ̬��������ֱ����exec()������
		dialog->show();
	}
	
	return;
}

void TeacherOnlineClassroomWidget::handleCommandJoinInLesson(QJsonObject &data) {
	CourseStatus course_status = CourseStatus(data["course_status"].toInt());
	Toast *toast = new Toast;
	const CourseBasic *course;
	QString text;
	QThread *thread;

	switch (course_status) {
	case CourseStatus::OffLine:
		text = "�γ�δ��ʼ";
		//this->distroyLessonConnection();
		this->m_enter_dialog->show();
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

		user->setUserStatus(UserStatus::InClass);

		this->m_ui.begin_lesson_btn->setText("�����Ͽ�");

		// ��ʼ��
		this->connect(&this->m_lesson_timer, &QTimer::timeout,
			this, &TeacherOnlineClassroomWidget::updateLastTime);
		// ��ʼˢ�������б�
		this->connect(&this->m_lesson_timer, &QTimer::timeout,
			this->m_lesson_analysis_widget, &TeacherLessonAnalysisWidget::refreshOnlineList);
		// ��ʼˢ��ѧ��רע����Ϣ
		this->connect(&this->m_lesson_timer, &QTimer::timeout,
			this->m_lesson_analysis_widget, &TeacherLessonAnalysisWidget::getStudentConc);

		this->openCamera();
		//QtConcurrent::run(this, &StudentOnlineClassroomWidget::openCamera);
		this->m_enter_dialog->hide();
		this->m_enter_dialog->deleteLater();

		this->m_loading_mask->deleteLater();
		
		// ����������������
		this->m_interaction_widget->whiteBoardWidget()->
			createPaintConnection(this->m_room["course_id"].toString(),
				this->m_room["lesson_id"].toString());

		this->m_lesson_timer.start(1000);  // ֻҪ������Ҿ�Ҫ������ʱ��

		break;
	case CourseStatus::CantJoinIn:
		text = "�ÿ��ò�������;����";
		//this->distroyLessonConnection();
		this->m_enter_dialog->show();
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

		user->setUserStatus(UserStatus::InRoom);

		// ��ʼˢ�������б�
		this->connect(&this->m_lesson_timer, &QTimer::timeout,
			this->m_lesson_analysis_widget, &TeacherLessonAnalysisWidget::refreshOnlineList);

		this->openCamera();
		//QtConcurrent::run(this, &StudentOnlineClassroomWidget::openCamera);
		this->m_enter_dialog->hide();
		this->m_enter_dialog->deleteLater();

		this->m_loading_mask->deleteLater();

		this->m_lesson_timer.start(1000);  // ֻҪ������Ҿ�Ҫ������ʱ��

		break;
	}
	toast->setInfoText(text);
	toast->show();
	this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);

	return;
}

void TeacherOnlineClassroomWidget::handleCommandBeginLesson(QJsonObject &data) {
	Toast *toast = new Toast("��ʼ�Ͽ�");

	// ���������ɹ�
	this->m_lesson_timer.start(1000);  // ������ʱ��
	// ��ʼˢ��ѧ��רע����Ϣ
	this->connect(&this->m_lesson_timer, &QTimer::timeout,
		this->m_lesson_analysis_widget, &TeacherLessonAnalysisWidget::getStudentConc);

	this->updateBeginTime((int)data["begin_timestamp"].toDouble());

	toast->show();
	this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);

	this->connect(&this->m_lesson_timer, &QTimer::timeout,
		this, &TeacherOnlineClassroomWidget::updateLastTime);

	// �������°�ť����
	this->m_ui.begin_lesson_btn->setText("�����Ͽ�");
	//this->disconnect(this->m_ui.begin_lesson_btn, &QPushButton::clicked, 
	//	this, &TeacherOnlineClassroomWidget::beginLesson);
	//this->connect(this->m_ui.begin_lesson_btn, &QPushButton::clicked, 
	//	this, &TeacherOnlineClassroomWidget::endLesson);

	return;
}

void TeacherOnlineClassroomWidget::handleCommandEndLesson(QJsonObject &data) {
	Toast *toast = new Toast;

	// ���������ɹ�
	this->m_lesson_timer.stop();
	user->setUserStatus(UserStatus::Free);

	toast->setInfoText(QString("�����ѽ���"));
	toast->show();
	this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);

	this->m_ui.begin_lesson_btn->setText("��ʼ�Ͽ�");
	//this->disconnect(this->m_ui.begin_lesson_btn, &QPushButton::clicked,
	//	this, &TeacherOnlineClassroomWidget::endLesson);
	//this->connect(this->m_ui.begin_lesson_btn, &QPushButton::clicked,
	//	this, &TeacherOnlineClassroomWidget::beginLesson);
	emit this->quitLessonRequestSuccess();

	return;
}

void TeacherOnlineClassroomWidget::handleCommandRefreshOnlineList(QJsonObject &data) {
	if (data["has_username_json"].toBool()) {
		this->m_ui.total_text->setText(QString::number(data["username_json"].toObject().count()));
	}

	this->m_ui.participants_text->setText(QString::number(data["online_list"].toArray().count()));

	return;
}

void TeacherOnlineClassroomWidget::createLesson(QString &course_id, QString &course_name) {
	QJsonObject request_json_obj;

	// this->createLessonConnection();

	request_json_obj["command"] = TransportCmd::CreateLesson;
	request_json_obj["account_type"] = AccountType::Teacher;
	request_json_obj["course_id"] = course_id;
	request_json_obj["course_name"] = course_name;
	request_json_obj["uid"] = user->getUid();
	request_json_obj["username"] = user->getUsername();

	this->m_lesson_connection->realSend(request_json_obj);

	this->m_enter_dialog->hide();
	this->m_loading_mask->show();

	return;
}

void TeacherOnlineClassroomWidget::joinInLesson() {
	QJsonObject request_json_obj;

	request_json_obj["command"] = TransportCmd::JoinInLesson;
	request_json_obj["account_type"] = AccountType::Teacher;
	request_json_obj["course_id"] = this->m_room["course_id"].toString();
	request_json_obj["course_name"] = this->m_room["course_name"].toString();
	request_json_obj["uid"] = user->getUid();
	request_json_obj["username"] = user->getUsername();

	this->m_lesson_connection->realSend(request_json_obj);

	return;
}

void TeacherOnlineClassroomWidget::beginLesson() {
	QJsonObject request_json_obj;
	QMap<QString, QVariant> data;

	request_json_obj["command"] = TransportCmd::BeginLesson;
	this->lessonConnectionSend(request_json_obj);

	// ����������������
	this->m_interaction_widget->whiteBoardWidget()->
		createPaintConnection(this->m_room["course_id"].toString(),
			this->m_room["lesson_id"].toString());

	return;
}

void TeacherOnlineClassroomWidget::endLessonInquire() {
	TipsDialog *dialog = new TipsDialog;

	dialog->setText(QString("�Ƿ�������ã�"));
	dialog->setConfirmText(QString("ȷ��"));
	dialog->setCancelText(QString("ȡ��"));
	this->connect(dialog, &TipsDialog::confirm,
		this, &TeacherOnlineClassroomWidget::endLesson);

	dialog->setModal(true);  // ģ̬��������ֱ����exec()������
	dialog->show();

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
		��ʼ��λ��
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

