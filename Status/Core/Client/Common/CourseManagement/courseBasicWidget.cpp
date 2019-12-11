#include "courseBasicWidget.h"


CourseBasicWidget::CourseBasicWidget(QWidget *parent)
	: QWidget(parent){
	m_ui.setupUi(this);
	m_ui.courses_comboBox->setView(new QListView(this));  // 这个应该是有关comboBox的样式

	// ——信号连接
	QComboBox *comboBox = this->m_ui.courses_comboBox;
	this->connect(comboBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this, &CourseBasicWidget::emitSignalCourseSwitched);
	this->connect(this, &CourseBasicWidget::courseSwitched,
		this, &CourseBasicWidget::updateAllData);

	this->updateCourseComboBox();
}

CourseBasicWidget::~CourseBasicWidget() {

}

void CourseBasicWidget::updateAllData(const QString &course_id) {
	this->getCourseBasicInfoRequest(course_id);

	return;
}

void CourseBasicWidget::updateCourseComboBox() {
	for (int index = 0; index < user->getCourseList().count(); index++) {
		this->m_ui.courses_comboBox->
			addItem(user->getCourseList().at(index).courseName());
	}

	return;
}

void CourseBasicWidget::emitSignalCourseSwitched(const int index) {
	QString course_id = user->getCourseList().at(index).courseId();

	emit this->courseSwitched(course_id);

	return;
}

void CourseBasicWidget::getCourseBasicInfoRequest(const QString &course_id) {
	// ——不变
	QJsonObject request_json_obj;
	QString url = "http://" + ReadConf::G_HTTP_HOST + ":"
		+ QString::number(ReadConf::G_HTTP_PORT);
	HttpRequest *request_obj = new HttpRequest;
	QThread *request_thread = new QThread;
	request_obj->moveToThread(request_thread);

	// ——可变
	//     ——固定数据
	request_json_obj["account_type"] = user->getAccountType();
	request_json_obj["uid"] = user->getUid();
	request_json_obj["username"] = user->getUsername();
	//     ——可变数据
	request_json_obj["course_id"] = course_id;
	request_obj->request(QUrl(url + "/course/getCourseBasicInfo"), request_json_obj);
	this->connect(request_obj, &HttpRequest::success,
		this, &CourseBasicWidget::getCourseBasicInfoRequestSuccess);

	// ——不变
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::quit);
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::deleteLater);
	this->connect(request_obj, &HttpRequest::complete, request_obj, &HttpRequest::deleteLater);
	request_thread->start();

	return;
}

void CourseBasicWidget::getCourseBasicInfoRequestSuccess(const QJsonObject &data) {
	ErrorCode err = ErrorCode(data["error_code"].toInt());

	switch (err) {
	case NoError:
		this->m_ui.create_time_text->setText(
			QDateTime::fromTime_t(data["create_timestamp"].toInt()).toString("yyyy-MM-dd"));
		this->m_ui.course_id_text->setText(data["course_id"].toString());
		break;
	case CourseNotFoundError:
		break;
	}

	return;
}