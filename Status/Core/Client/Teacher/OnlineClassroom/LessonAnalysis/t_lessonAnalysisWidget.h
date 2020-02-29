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
	QJsonArray m_online_list;  // ��ǰ�����б��е�uid�б�
	QJsonObject m_username_json;  // ��ǰ�γ������û����û���
	bool m_need_username_json;  // �Ƿ���Ҫ�����û���json����

	Ui::TeacherLessonAnalysisWidget m_ui;
	MemberWidget *m_member_widget;
};
