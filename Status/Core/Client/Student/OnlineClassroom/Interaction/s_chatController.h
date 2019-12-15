#pragma once
#pragma execution_character_set("utf-8")
#include <QThread>
#include <QTextBrowser>
#include <QDateTime>
#include <QJsonObject>
#include "Core/Client/Student/OnlineClassroom/s_onlineclassroomWidget.h"
#include "Core/Client/Common/c_listWidgetItem.h"
#include "Core/Component/Toast/toast.h"
#include "Core/Network/socket.h"
#include "Core/Client/onlineEdu.h"


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
