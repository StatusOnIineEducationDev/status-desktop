#pragma once
#pragma execution_character_set("utf-8")
#include <QThread>
#include "Core/Client/Student/OnlineClassroom/s_onlineclassroomWidget.h"
#include "Core/Network/socket.h"
#include "Core/Client/onlineEdu.h"
#include "Core/Client/conf.h"


class SWhiteBoardController : public QObject {
	Q_OBJECT

public:
	SWhiteBoardController(SOnlineClassroomWidget *online_classroom_widget, QObject *parent = nullptr);
	virtual ~SWhiteBoardController();

	void createPaintConnection(QString course_id, QString lesson_id, QString uid);
	void distroyPaintConnection();

protected:
	void handlePaintConnectionRecv();
	void handleCommandPaintCommand(QJsonObject &data);
	void sendPaintCommand(QJsonObject &data);

	void setPaintConnectionSendBaseInfo(QString course_id, QString lesson_id, QString uid);
	
	SOnlineClassroomWidget *m_online_classroom_widget;
	Connection *m_paint_connection;  // »­°åµÄTcpÁ¬½Ó
	QMap<QString, QVariant> m_send_base_info;
};