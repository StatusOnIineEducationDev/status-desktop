#include "teacher_course_widget.h"
#include "Core/View/Component/component.h"
#include "Core/Controller/Transport/socket.h"
#include "Core/Controller/Transport/http_request.h"
#include <QNetworkAccessManager>

TeacherCourseWidget::TeacherCourseWidget(QWidget *parent) : QWidget(parent) {
	ui.setupUi(this);

	ui.courses_comboBox->setView(new QListView());

	QChart *a = new AreaChart();
	ui.area_chart_widget->setChart(a);
	ui.area_chart_widget->setRenderHint(QPainter::Antialiasing);

	HttpRequest *request_obj = new HttpRequest();
	QThread *request_thread = new QThread;
	request_obj->moveToThread(request_thread);
	QJsonObject request_json_obj;
	request_json_obj["a"] = "aaaaaaaaaaa";

	request_obj->request(QUrl("http://49.235.16.174:5000/helloworld"), request_json_obj);
	this->connect(request_obj, &HttpRequest::success, this, &TeacherCourseWidget::test);
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::quit);
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::deleteLater);
	request_thread->start();
}


void TeacherCourseWidget::test(QJsonObject data) {
	qDebug() << data << "success";
}