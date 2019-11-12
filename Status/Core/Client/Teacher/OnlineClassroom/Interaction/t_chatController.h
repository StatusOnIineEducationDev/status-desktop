#pragma once
#pragma execution_character_set("utf-8")
#include <QThread>
#include <QTextBrowser>
#include <QDateTime>
#include <QJsonObject>
#include "Core/Client/Teacher/OnlineClassroom/t_onlineClassroomWidget.h"
#include "Core/Client/Common/c_listWidgetItem.h"
#include "Core/Component/toast.h"
#include "Core/Network/socket.h"
#include "Core/Client/onlineEdu.h"


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
