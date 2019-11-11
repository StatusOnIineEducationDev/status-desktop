#include "s_concentrationController.h"


SConcentrationController::SConcentrationController(
	SOnlineClassroomWidget *online_classroom_widget, QObject *parent)
	: QObject(parent), m_online_classroom_widget(online_classroom_widget) {
	Ui::SOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();
	QThread *chart_thread = new QThread(this->m_online_classroom_widget);

	/*
		把两张chart放入一个新的线程中
		这样避免了在chart刷新时的卡顿
	*/
	// ——专注度面积图
	this->m_concentration_area_chart = new AreaChartDynamic(QColor(18, 150, 219), this->m_online_classroom_widget);
	ui.concentration_area_chart_widget->setChart(this->m_concentration_area_chart);
	ui.concentration_area_chart_widget->setRenderHint(QPainter::Antialiasing);
	// ——专注度(缩略)面积图
	this->m_concentration_area_chart_min = new AreaChartDynamic(QColor(18, 150, 219), this->m_online_classroom_widget);
	ui.concentration_area_chart_min_widget->setChart(this->m_concentration_area_chart_min);
	ui.concentration_area_chart_min_widget->setRenderHint(QPainter::Antialiasing);

	this->m_concentration_area_chart->moveToThread(chart_thread);
	this->m_concentration_area_chart_min->moveToThread(chart_thread);
}

SConcentrationController::~SConcentrationController() {

}

void SConcentrationController::handleCommandConcentrationFinalData(QJsonObject &data) {
	QMap<QString, QVariant> info;

	info["concentration_value"] = data["concentration_value"].toInt();
	info["fatigue_value"] = data["fatigue_value"].toInt();
	info["toward_score"] = data["toward_score"].toInt();
	info["emotion_score"] = data["emotion_score"].toInt();
	info["timestamp"] = data["timestamp"].toInt();
	this->m_final_data_list.append(info);

	this->updateFinalDataFrame(data);
	this->updateDynamicAreaChat(data);

	return;
}

void SConcentrationController::handleCommandConcentrationRealTimeData(QJsonObject &data) {
	this->updateEmotionPercentageChart(data);
	this->updateRealTimeDataFrame(data);

	return;
}

void SConcentrationController::updateEmotionPercentageChart(QJsonObject &data) {
	Ui::SOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();
	int angry_times = data["angry_times"].toInt(),
		disgust_times = data["disgust_times"].toInt(),
		fear_times = data["fear_times"].toInt(),
		happy_times = data["happy_times"].toInt(),
		sad_times = data["sad_times"].toInt(),
		surprise_times = data["surprise_times"].toInt(),
		neutral_times = data["neutral_times"].toInt(),
		total_times = angry_times + disgust_times 
					+ fear_times + happy_times + sad_times 
					+ surprise_times + neutral_times;

	// ——更新progressbar
	ui.angry_progressBar->setValue(angry_times);
	ui.disgust_progressBar->setValue(disgust_times);
	ui.fear_progressBar->setValue(fear_times);
	ui.happy_progressBar->setValue(happy_times);
	ui.sad_progressBar->setValue(sad_times);
	ui.surprise_progressBar->setValue(surprise_times);
	ui.neutral_progressBar->setValue(neutral_times);

	// ——更新text
	//  ——times
	ui.angry_times_text->setText(QString::number(angry_times));
	ui.disgust_times_text->setText(QString::number(disgust_times));
	ui.fear_times_text->setText(QString::number(fear_times));
	ui.happy_times_text->setText(QString::number(happy_times));
	ui.sad_times_text->setText(QString::number(sad_times));
	ui.surprise_times_text->setText(QString::number(surprise_times));
	ui.neutral_times_text->setText(QString::number(neutral_times));
	//  ——percent
	ui.angry_percent_text->setText(QString::number(angry_times / total_times));
	ui.disgust_percent_text->setText(QString::number(disgust_times / total_times));
	ui.fear_percent_text->setText(QString::number(fear_times / total_times));
	ui.happy_percent_text->setText(QString::number(happy_times / total_times));
	ui.sad_percent_text->setText(QString::number(sad_times / total_times));
	ui.surprise_percent_text->setText(QString::number(surprise_times / total_times));
	ui.neutral_percent_text->setText(QString::number(neutral_times / total_times));

	return;
}

void SConcentrationController::updateRealTimeDataFrame(QJsonObject &data) {

	return;
}

void SConcentrationController::updateFinalDataFrame(QJsonObject &data) {
	Ui::SOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();

	ui.concentration_value_text->setText(QString::number(data["concentration_value"].toInt()));
	ui.fatigue_value_text->setText(QString::number(data["fatigue_value"].toInt()));
	ui.toward_score_text->setText(QString::number(data["toward_score"].toInt()));
	ui.emotion_score_text->setText(QString::number(data["emotion_score"].toInt()));

	return;
}

void SConcentrationController::updateDynamicAreaChat(QJsonObject &data) {
	int timestamp = data["timestamp"].toInt(),
		concentration_value = data["concentration_value"].toInt();

	// ——更新专注度图
	this->m_concentration_area_chart->append(timestamp, concentration_value);
	this->m_concentration_area_chart_min->append(timestamp, concentration_value);

	return;
}