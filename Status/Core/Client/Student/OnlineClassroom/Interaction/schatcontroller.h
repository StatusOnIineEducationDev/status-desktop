#pragma once
#pragma execution_character_set("utf-8")
#include <QThread>
#include <QTextBrowser>
#include <QDateTime>
#include "Core/Client/Student/OnlineClassroom/sonlineclassroomwidget.h"
#include "Core/Client/Common/clistwidgetitem.h"
#include "Core/Component/toast.h"
#include "Core/Network/socket.h"
#include "Core/Client/online_education.h"


class SChatController : public QObject {
	Q_OBJECT

signals:
	void lessonConnectionDataReady(QJsonObject &data);

public:
	SChatController(SOnlineClassroomWidget *online_classroom_widget, QObject *parent = nullptr);
	virtual ~SChatController();

	void handleCommandSendChatContent(QJsonObject &data);
	void handleCommandRecvChatContent(QJsonObject &data);
	void handleCommandChatBan(QJsonObject &data);

protected:
	void showFlexibleFrame();
	void hideFlexibleFrame();

	void sendChatContent();
	void chatBan();
	void chatClear();

	SOnlineClassroomWidget *m_online_classroom_widget;
};
