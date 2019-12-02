#include "courseBaseWidget.h"


CourseBaseWidget::CourseBaseWidget(QWidget *parent)
	: QWidget(parent) {
	m_ui.setupUi(this);
	m_ui.courses_comboBox->setView(new QListView(this));  // 这个应该是有关comboBox的样式

	// ——信号连接
	QComboBox *comboBox = this->m_ui.courses_comboBox;
	this->connect(comboBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this, &CourseBaseWidget::emitSignalCourseSwitched);
	this->connect(this, &CourseBaseWidget::courseSwitched,
		this, &CourseBaseWidget::updateAllData);

	this->updateCourseComboBox();
}

CourseBaseWidget::~CourseBaseWidget() {

}

void CourseBaseWidget::updateAllData(const QString &course_id) {
	this->getCourseBaseInfoRequest(course_id);

	return;
}

void CourseBaseWidget::updateCourseComboBox() {
	for (int index = 0; index < User::G_COURSES_BASE_LIST->count(); index++) {
		this->m_ui.courses_comboBox->
			addItem(User::G_COURSES_BASE_LIST->at(index).courseName());
	}

	return;
}

void CourseBaseWidget::emitSignalCourseSwitched(const int index) {
	QString course_id = User::G_COURSES_BASE_LIST->at(index).courseId();

	emit this->courseSwitched(course_id);

	return;
}

void CourseBaseWidget::getCourseBaseInfoRequest(const QString &course_id) {
	// ——不变
	QJsonObject request_json_obj;
	QString url = "http://" + ReadConf::G_HTTP_HOST + ":"
		+ QString::number(ReadConf::G_HTTP_PORT);
	HttpRequest *request_obj = new HttpRequest;
	QThread *request_thread = new QThread;
	request_obj->moveToThread(request_thread);

	// ——可变
	//     ——固定数据
	request_json_obj["account_type"] = User::G_ACCOUNT_TYPE;
	request_json_obj["uid"] = User::G_UID;
	request_json_obj["username"] = User::G_USERNAME;
	//     ——可变数据
	request_json_obj["course_id"] = course_id;
	request_obj->request(QUrl(url + "/getCourseBaseInfo"), request_json_obj);
	this->connect(request_obj, &HttpRequest::success,
		this, &CourseBaseWidget::getCourseBaseInfoSuccess);

	// ——不变
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::quit);
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::deleteLater);
	this->connect(request_obj, &HttpRequest::complete, request_obj, &HttpRequest::deleteLater);
	request_thread->start();

	return;
}

void CourseBaseWidget::getCourseBaseInfoSuccess(const QJsonObject &data) {
	this->m_ui.create_time_text->setText(
		QDateTime::fromTime_t(data["create_timestamp"].toInt()).toString("yyyy-MM-dd"));
	this->m_ui.course_id_text->setText(data["course_id"].toString());

	return;
}