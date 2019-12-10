#include "courseOverviewWidget.h"


CourseOverviewWidget::CourseOverviewWidget(QWidget *parent)
	: QWidget(parent) {
	m_ui.setupUi(this);


	QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
	shadow_effect->setOffset(0, 0);
	shadow_effect->setColor(Qt::gray);
	shadow_effect->setBlurRadius(20);
	this->m_ui.scrollAreaWidgetContents->setGraphicsEffect(shadow_effect);

	qRegisterMetaType<QJsonObject>("QJsonObject&");  //ע��QJsonObject&����

	this->loadIntroductionCardWidget();
	this->loadNoticeCardWidget();
	this->m_ui.widget_layout->addStretch();  // ��ĩβ�Ӹ���ֱ����
}

CourseOverviewWidget::~CourseOverviewWidget() {

}

void CourseOverviewWidget::updateAllData(const QString &course_id) {
	this->getCourseIntroductionRequest(course_id);
	this->getCourseNoticeRequest(course_id);

	return;
}

void CourseOverviewWidget::loadIntroductionCardWidget() {
	this->m_introduction_card_widget = new TextInfoCardWidget(this);
	this->m_introduction_card_widget->setTitle("�γ̽���");

	this->m_ui.widget_layout->addWidget(this->m_introduction_card_widget);
}

void CourseOverviewWidget::loadNoticeCardWidget() {
	this->m_notice_card_widget = new TextInfoCardWidget(this);
	this->m_notice_card_widget->setTitle("�γ̹���");

	this->m_ui.widget_layout->addWidget(this->m_notice_card_widget);
}

void CourseOverviewWidget::getCourseIntroductionRequest(const QString &course_id) {
	// ��������
	QJsonObject request_json_obj;
	QString url = "http://" + ReadConf::G_HTTP_HOST + ":"
		+ QString::number(ReadConf::G_HTTP_PORT);
	HttpRequest *request_obj = new HttpRequest;
	QThread *request_thread = new QThread;
	request_obj->moveToThread(request_thread);

	// �����ɱ�
	//     �����̶�����
	request_json_obj["account_type"] = user->getAccountType();
	request_json_obj["uid"] = user->getUid();
	request_json_obj["username"] = user->getUsername();
	//     �����ɱ�����
	request_json_obj["course_id"] = course_id;
	request_obj->request(QUrl(url + "/getCourseIntroduction"), request_json_obj);
	this->connect(request_obj, &HttpRequest::success,
		this, &CourseOverviewWidget::getCourseIntroductionRequestSuccess);

	// ��������
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::quit);
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::deleteLater);
	this->connect(request_obj, &HttpRequest::complete, request_obj, &HttpRequest::deleteLater);
	request_thread->start();

	return;
}

void CourseOverviewWidget::getCourseIntroductionRequestSuccess(const QJsonObject &data) {
	this->m_introduction_card_widget->
		setContentText(data["introduction_text"].toString());

	return;
}

void CourseOverviewWidget::getCourseNoticeRequest(const QString &course_id) {
	// ��������
	QJsonObject request_json_obj;
	QString url = "http://" + ReadConf::G_HTTP_HOST + ":"
		+ QString::number(ReadConf::G_HTTP_PORT);
	HttpRequest *request_obj = new HttpRequest;
	QThread *request_thread = new QThread;
	request_obj->moveToThread(request_thread);

	// �����ɱ�
	//     �����̶�����
	request_json_obj["account_type"] = user->getAccountType();
	request_json_obj["uid"] = user->getUid();
	request_json_obj["username"] = user->getUsername();
	//     �����ɱ�����
	request_json_obj["course_id"] = course_id;
	request_obj->request(QUrl(url + "/getCourseNotice"), request_json_obj);
	this->connect(request_obj, &HttpRequest::success,
		this, &CourseOverviewWidget::getCourseNoticeRequestSuccess);

	// ��������
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::quit);
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::deleteLater);
	this->connect(request_obj, &HttpRequest::complete, request_obj, &HttpRequest::deleteLater);
	request_thread->start();

	return;
}

void CourseOverviewWidget::getCourseNoticeRequestSuccess(const QJsonObject &data) {
	this->m_notice_card_widget->
		setContentText(data["notice_text"].toString());

	return;
}