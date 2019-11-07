#pragma once
#pragma execution_character_set("utf-8")
#include <QThread>
#include <QTextBrowser>
#include <QDateTime>
#include "Core/Client/Teacher/OnlineClassroom/tonlineclassroomwidget.h"
#include "Core/Client/Common/clistwidgetitem.h"
#include "Core/Component/toast.h"
#include "Core/Network/socket.h"
#include "Core/Client/online_education.h"


class TOnlineClassroomChatController : public QObject {
	Q_OBJECT

signals:
	void lessonConnectionDataReady(QJsonObject &data);

public:
	TOnlineClassroomChatController(TOnlineClassroomWidget *online_classroom_widget, QObject *parent = nullptr);
	virtual ~TOnlineClassroomChatController();

	void handleCommandSendChatContent(QJsonObject &data);
	void handleCommandRecvChatContent(QJsonObject &data);
	void handleCommandChatBan(QJsonObject &data);

protected:
	void showFlexibleFrame();
	void hideFlexibleFrame();

	void sendChatContent();
	void chatBan();
	void chatClear();

	TOnlineClassroomWidget *m_online_classroom_widget;
};
