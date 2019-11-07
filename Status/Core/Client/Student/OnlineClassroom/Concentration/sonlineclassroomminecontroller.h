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

	AreaChartDynamic *m_concentration_area_chart;  // רע�����ͼ
	AreaChartDynamic *m_concentration_area_chart_min;  // רע�����ͼ�����ԣ�
	QList<QMap<QString, QVariant>> m_concentration_list;  // רע������
	QList<QMap<QString, QVariant>> m_real_time_data_list;  // ����ʵʱ����


	void handleCommandConcentrationData(QJsonObject &data);
};