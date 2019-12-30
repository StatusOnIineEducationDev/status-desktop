#include "courseAnalysisWidget.h"
#include<QTimer>

CourseAnalysisWidget::CourseAnalysisWidget(QWidget *parent)
	:QWidget(parent) {
	m_ui.setupUi(this);

	this->loadHtml();
}

CourseAnalysisWidget::~CourseAnalysisWidget() {

}

void CourseAnalysisWidget::loadHtml() {
	this->conc_cmpr_chart_finished = false;
	this->connect(this->m_ui.lesson_cmpr_chartView->page(), &QWebEnginePage::loadFinished,
		this, &CourseAnalysisWidget::loadConcCmprChartFinished);
	this->m_ui.lesson_cmpr_chartView->
		load(QUrl("qrc:/CourseAnalysis/Resources/ECharts/lessonConcCmprChart.html"));

	return;
}

void CourseAnalysisWidget::emitSignalLoadHtmlFinished() {
	if (this->conc_cmpr_chart_finished) {
		emit this->loadHtmlFinished(QString(""));
	}

	return;
}

void CourseAnalysisWidget::loadConcCmprChartFinished() {
	this->conc_cmpr_chart_finished = true;
	this->emitSignalLoadHtmlFinished();

	return;
};

void CourseAnalysisWidget::updateAllData(const QString& course_id) {
	if (course_id != "") {
		this->setCourseId(course_id);
	}

	this->updateConcCmprChart();
	this->updateRank();

	return;
}

void CourseAnalysisWidget::updateConcCmprChart() {
	this->updateConcCmprChartRequest();

	return;
}

void CourseAnalysisWidget::updateConcCmprChartRequest() {
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
	request_json_obj["course_id"] = this->m_course_id;
	request_obj->request(QUrl(url + "/course/getConcCmprChartData"), request_json_obj);
	this->connect(request_obj, &HttpRequest::success,
		this, &CourseAnalysisWidget::updateConcCmprChartRequestSuccess);

	// ——不变
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::quit);
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::deleteLater);
	this->connect(request_obj, &HttpRequest::complete, request_obj, &HttpRequest::deleteLater);
	request_thread->start();

	// ——等待动画
	LoadingWidget *loading_widget = new LoadingWidget(this->m_ui.lesson_cmpr_chartView);
	this->connect(request_obj, &HttpRequest::complete, loading_widget, &LoadingWidget::deleteLater);
	loading_widget->setTipsText("加载中...");
	loading_widget->show();

	return;
}

void CourseAnalysisWidget::updateConcCmprChartRequestSuccess(const QJsonObject &data) {
	QString option, js;
	QJsonObject paint_data;
	ErrorCode err = ErrorCode(data["error_code"].toInt());

	switch (err) {
	case NoError:
		paint_data["value"] = data["value"];
		paint_data["x_label"] = data["x_label"];
		paint_data["width"] = this->m_ui.lesson_cmpr_chartView->width();
		paint_data["height"] = this->m_ui.lesson_cmpr_chartView->height();

		option = QJsonDocument(paint_data).toJson(QJsonDocument::Compact);
		js = QString("init(%1)").arg(option);
		this->m_ui.lesson_cmpr_chartView->page()->runJavaScript(js);
		break;
	}

	return;
}

void CourseAnalysisWidget::updateRank() {
	this->m_ui.rank_listWidget->clear();
	this->updateRankRequest();
	
	return;
}

void CourseAnalysisWidget::updateRankRequest() {
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
	request_json_obj["course_id"] = this->m_course_id;
	request_obj->request(QUrl(url + "/course/getConcRankData"), request_json_obj);
	this->connect(request_obj, &HttpRequest::success,
		this, &CourseAnalysisWidget::updateRankRequestSuccess);

	// ——不变
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::quit);
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::deleteLater);
	this->connect(request_obj, &HttpRequest::complete, request_obj, &HttpRequest::deleteLater);
	request_thread->start();

	// ——等待动画
	LoadingWidget *loading_widget = new LoadingWidget(this->m_ui.rank_listWidget);
	this->connect(request_obj, &HttpRequest::complete, loading_widget, &LoadingWidget::deleteLater);
	loading_widget->setTipsText("加载中...");
	loading_widget->show();

	return;
}

void CourseAnalysisWidget::updateRankRequestSuccess(const QJsonObject &data) {
	ErrorCode err = ErrorCode(data["error_code"].toInt());

	switch (err) {
	case NoError:
		this->updateRankListWidget(data["rank_list"].toArray());
		break;
	}

	return;
}

void CourseAnalysisWidget::updateRankListWidget(const QJsonArray &data) {
	QListWidgetItem *item;
	CourseAnalysisRankItemWidget *item_widget;

	for (int index = 0; index < data.count(); index++) {
		item = new QListWidgetItem(this->m_ui.rank_listWidget);
		item_widget = new CourseAnalysisRankItemWidget(data[index]["user_pic"].toString(),
			data[index]["username"].toString(), data[index]["times"].toInt(), 
			data[index]["concentration"].toInt(), data[index]["rank"].toInt(), 
			this->m_ui.rank_listWidget);

		item->setSizeHint(QSize(item_widget->width(), item_widget->height()));
		this->m_ui.rank_listWidget->addItem(item);
		this->m_ui.rank_listWidget->setItemWidget(item, item_widget);

		QApplication::processEvents();  // 防止GUI假死
	}

	return;
}

