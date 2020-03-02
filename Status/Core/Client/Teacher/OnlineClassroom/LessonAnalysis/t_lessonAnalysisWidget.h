#pragma once
#pragma execution_character_set("utf-8")  
#include <QWidget>
#include <QJsonArray>
#include "ui_t_lessonAnalysisWidget.h"
#include "Core/Client/Common/Member/memberWidget.h"
#include "Core/Component/Chart/areaChartDynamic.h"
#include "Core/Model/user.h"


class TeacherLessonAnalysisWidget : public QWidget {
	Q_OBJECT

signals:
	void lessonConnectionDataReady(QJsonObject &data);

public:
	TeacherLessonAnalysisWidget(QWidget *parent = nullptr);
	virtual ~TeacherLessonAnalysisWidget();
	const Ui::TeacherLessonAnalysisWidget& ui() const { return this->m_ui; };
	MemberWidget* memberWidget() const { return this->m_member_widget; };

	void handleCommandRefreshOnlineList(QJsonObject &data);
	void handleCommandGetStudentConc(QJsonObject &data);

	void refreshOnlineList();
	void getStudentConc();

protected:
	void changeCheckedUid(QListWidgetItem *item);
	void updateDynamicAreaChat(int concentration_timestamp, int concentration_value);
	void loadConcentrationAreaChart();

	QJsonArray m_online_list;  // ��ǰ�����б��е�uid�б�
	QJsonObject m_username_json;  // ��ǰ�γ������û����û���
	bool m_need_username_json;  // �Ƿ���Ҫ�����û���json����

	QString m_checked_uid;  // ���ڲ鿴����Ϣ��uid��Ĭ�ϲ鿴���ǿ��ã��ǡ�lesson����
	int m_lastly_timestamp;  // ���һ�θ��µ�ʱ���

	AreaChartDynamic *m_concentration_area_chart;  // רע�����ͼ

	Ui::TeacherLessonAnalysisWidget m_ui;
	MemberWidget *m_member_widget;
};
