#pragma once
#pragma execution_character_set("utf-8")
#include <QThread>
#include "Core/Client/Teacher/OnlineClassroom/tonlineclassroomwidget.h"
#include "Core/Network/socket.h"
#include "Core/Client/online_education.h"
#include "Core/Client/conf.h"


class TWhiteBoardController : public QObject {
	Q_OBJECT

public:
	TWhiteBoardController(TOnlineClassroomWidget *online_classroom_widget, QObject *parent = nullptr);
	virtual ~TWhiteBoardController();

	void createPaintConnection(QMap<QString, QVariant> &data);
	void distroyPaintConnection();

protected:
	void handlePaintConnectionRecv();
	void handleCommandPaintCommand(QJsonObject &data);
	void sendPaintCommand(QJsonObject &data);

	void setPaintConnectionSendBaseInfo(QString uid, QString course_id, QString lesson_id);
	
	TOnlineClassroomWidget *m_online_classroom_widget;
	Connection *m_paint_connection;  // »­°åµÄTcpÁ¬½Ó
	QMap<QString, QVariant> m_send_base_info;
};