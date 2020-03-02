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

	QJsonArray m_online_list;  // 当前在线列表中的uid列表
	QJsonObject m_username_json;  // 当前课程所有用户的用户名
	bool m_need_username_json;  // 是否需要更新用户名json数据

	QString m_checked_uid;  // 正在查看的信息的uid（默认查看的是课堂，是‘lesson’）
	int m_lastly_timestamp;  // 最近一次更新的时间戳

	AreaChartDynamic *m_concentration_area_chart;  // 专注度面积图

	Ui::TeacherLessonAnalysisWidget m_ui;
	MemberWidget *m_member_widget;
};
