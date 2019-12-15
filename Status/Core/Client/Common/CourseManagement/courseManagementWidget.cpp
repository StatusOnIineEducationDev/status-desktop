#include "courseManagementWidget.h"


CourseManagementWidget::CourseManagementWidget(QWidget *parent)
	: QWidget(parent) {
	m_ui.setupUi(this);
	this->m_ui.function_tabWidget->setAttribute(Qt::WA_StyledBackground);  // tab栏显示背景色

	this->loadCourseBasicWidget();
}

CourseManagementWidget::~CourseManagementWidget() {

}

void CourseManagementWidget::getCourseListRequest() {
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

	request_obj->request(QUrl(url + "/user/getCourseList"),
		request_json_obj);
	this->connect(request_obj, &HttpRequest::success,
		this, &CourseManagementWidget::getCourseListRequestSuccess);

	// ——不变
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::quit);
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::deleteLater);
	this->connect(request_obj, &HttpRequest::complete, request_obj, &HttpRequest::deleteLater);
	request_thread->start();

	return;
}

void CourseManagementWidget::getCourseListRequestSuccess(const QJsonObject &data) {
	ErrorCode err = ErrorCode(data["error_code"].toInt());

	switch (err) {
	case NoError:
		this->loadCourseListData(data["course_list"].toArray());
		break;
	}

	return;
}

void CourseManagementWidget::loadCourseBasicWidget() {
	this->m_course_basic_widget = new CourseBasicWidget(this);
	this->m_ui.course_base_widget_layout->addWidget(this->m_course_basic_widget);

	return;
}

void CourseManagementWidget::loadCourseListData(const QJsonArray &data) {
	QList<CourseBasic> course_list;
	CourseBasic *course_temp;

	// ——加载course_list
	for (int index = 0; index < data.count(); index++) {
		course_temp = new CourseBasic(data[index].toObject()["course_id"].toString(),
			data[index].toObject()["course_name"].toString());
		course_list.append(*course_temp);
	}
	user->setCourseList(course_list);
	this->m_course_basic_widget->updateCourseComboBox();

	return;
}