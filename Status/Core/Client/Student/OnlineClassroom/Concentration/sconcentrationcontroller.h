#pragma once
#include "Core/Client/Student/OnlineClassroom/sonlineclassroomwidget.h"
#include "Core/Component/Chart/areachartdynamic.h"



class SConcentrationController : public QObject {
	Q_OBJECT

signals:
	void lessonConnectionDataReady(QJsonObject &data);

public:
	SConcentrationController(
		SOnlineClassroomWidget *online_classroom_widget, QObject *parent);
	virtual ~SConcentrationController();

	void handleCommandConcentrationFinalData(QJsonObject &data);
	void handleCommandConcentrationRealTimeData(QJsonObject &data);

protected:
	SOnlineClassroomWidget *m_online_classroom_widget;

	AreaChartDynamic *m_concentration_area_chart;  // רע�����ͼ
	AreaChartDynamic *m_concentration_area_chart_min;  // רע�����ͼ�����ԣ�
	/*
		|-info(m_final_data_list)
			|-concentration_value(int)
			|-fatigue_value(int)
			|-toward_score(int)
			|-emotion_score(int)
			|-timestamp(int)
	*/
	QList<QMap<QString, QVariant>> m_final_data_list;  // רע������

	void updateEmotionPercentageChart(QJsonObject &data);
	void updateRealTimeDataFrame(QJsonObject &data);
	void updateFinalDataFrame(QJsonObject &data);
	void updateDynamicAreaChat(QJsonObject &data);
};