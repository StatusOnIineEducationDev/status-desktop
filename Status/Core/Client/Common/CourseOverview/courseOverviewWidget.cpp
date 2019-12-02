#include "courseOverviewWidget.h"


CourseOverviewWidget::CourseOverviewWidget(QWidget *parent)
	: QWidget(parent) {
	m_ui.setupUi(this);

	qRegisterMetaType<QJsonObject>("QJsonObject&");  //ע��QJsonObject&����

	this->loadIntroductionCardWidget();
	this->loadNoticeCardWidget();
}

CourseOverviewWidget::~CourseOverviewWidget() {

}

void CourseOverviewWidget::updateAllData(const QString &course_id) {
	this->getIntroductionRequest(course_id);
	this->getNoticeRequest(course_id);

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

void CourseOverviewWidget::getIntroductionRequest(const QString &course_id) {
	// ��������
	QJsonObject request_json_obj;
	QString url = "http://" + ReadConf::G_HTTP_HOST + ":"
		+ QString::number(ReadConf::G_HTTP_PORT);
	HttpRequest *request_obj = new HttpRequest;
	QThread *request_thread = new QThread;
	request_obj->moveToThread(request_thread);

	// �����ɱ�
	//     �����̶�����
	request_json_obj["account_type"] = User::G_ACCOUNT_TYPE;
	request_json_obj["uid"] = User::G_UID;
	request_json_obj["username"] = User::G_USERNAME;
	//     �����ɱ�����
	request_json_obj["course_id"] = course_id;
	request_obj->request(QUrl(url + "/getCourseIntroduction"), request_json_obj);
	this->connect(request_obj, &HttpRequest::success,
		this, &CourseOverviewWidget::getIntroductionSuccess);

	// ��������
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::quit);
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::deleteLater);
	this->connect(request_obj, &HttpRequest::complete, request_obj, &HttpRequest::deleteLater);
	request_thread->start();

	return;
}

void CourseOverviewWidget::getIntroductionSuccess(QJsonObject &data) {
	this->m_introduction_card_widget->
		setContentText(data["introduction_text"].toString());
	qDebug() << data["introduction_text"].toString();
	return;
}

void CourseOverviewWidget::getNoticeRequest(const QString &course_id) {
	// ��������
	QJsonObject request_json_obj;
	QString url = "http://" + ReadConf::G_HTTP_HOST + ":"
		+ QString::number(ReadConf::G_HTTP_PORT);
	HttpRequest *request_obj = new HttpRequest;
	QThread *request_thread = new QThread;
	request_obj->moveToThread(request_thread);

	// �����ɱ�
	//     �����̶�����
	request_json_obj["account_type"] = User::G_ACCOUNT_TYPE;
	request_json_obj["uid"] = User::G_UID;
	request_json_obj["username"] = User::G_USERNAME;
	//     �����ɱ�����
	request_json_obj["course_id"] = course_id;
	request_obj->request(QUrl(url + "/getCourseNotice"), request_json_obj);
	this->connect(request_obj, &HttpRequest::success,
		this, &CourseOverviewWidget::getNoticeSuccess);

	// ��������
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::quit);
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::deleteLater);
	this->connect(request_obj, &HttpRequest::complete, request_obj, &HttpRequest::deleteLater);
	request_thread->start();

	return;
}

void CourseOverviewWidget::getNoticeSuccess(QJsonObject &data) {
	this->m_notice_card_widget->
		setContentText(data["notice_text"].toString());
	qDebug() << data["notice_text"].toString();
	return;
}