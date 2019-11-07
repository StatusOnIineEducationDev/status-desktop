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


class TChatController : public QObject {
	Q_OBJECT

signals:
	void lessonConnectionDataReady(QJsonObject &data);

public:
	TChatController(TOnlineClassroomWidget *online_classroom_widget, QObject *parent = nullptr);
	virtual ~TChatController();

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
