#pragma once
#include "Core/Client/Student/OnlineClassroom/sonlineclassroomwidget.h"
#include "Core/Component/Chart/areachartdynamic.h"



class SOnlineClassroomConcentrationController : public QObject {
	Q_OBJECT

signals:
	void joinInLesson(QMap<QString, QVariant> &data);

public:
	SOnlineClassroomConcentrationController(QObject *parent = nullptr);
	virtual ~SOnlineClassroomConcentrationController();

protected:
	SOnlineClassroomWidget *m_online_classroom_widget;

	AreaChartDynamic *m_concentration_area_chart;  // 专注度面积图
	AreaChartDynamic *m_concentration_area_chart_min;  // 专注度面积图（缩略）
	QList<QMap<QString, QVariant>> m_concentration_list;  // 专注度数据
	QList<QMap<QString, QVariant>> m_real_time_data_list;  // 其他实时数据


	void handleCommandConcentrationData(QJsonObject &data);
};