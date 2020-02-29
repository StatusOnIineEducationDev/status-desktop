#pragma once
#include <QWidget>
#include <qDebug>
#include <QJsonArray>
#include "ui_t_lessonAnalysisWidget.h"
#include "Core/Client/Common/Member/memberWidget.h"
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
	void refreshOnlineList();

protected:
	QJsonArray m_online_list;  // 当前在线列表中的uid列表
	QJsonObject m_username_json;  // 当前课程所有用户的用户名
	bool m_need_username_json;  // 是否需要更新用户名json数据

	Ui::TeacherLessonAnalysisWidget m_ui;
	MemberWidget *m_member_widget;
};
