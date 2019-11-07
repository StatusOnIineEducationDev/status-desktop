#pragma once
#pragma execution_character_set("utf-8")
#include <QJsonArray>
#include <QList>
#include "sonlineclassroomwidget.h"
#include "Core/Client/Student/smainwindow.h"
#include "Core/Client/Student/OnlineClassroom/Enter/sentercontroller.h"
#include "Core/Client/Student/OnlineClassroom/Interaction/swhiteboardcontroller.h"
#include "Core/Client/Student/OnlineClassroom/Interaction/schatcontroller.h"
#include "Core/Client/Student/OnlineClassroom/Concentration/sconcentrationcontroller.h"
#include "Core/Hardware/camera.h"
#include "Core/Network/socket.h"
#include "Core/Tools/base64.h"
#include "Core/Tools/tools.h"
#include "Core/Client/conf.h"


class SOnlineClassroomController : public QObject {
	Q_OBJECT

public:
	SOnlineClassroomController(User *user, QObject *parent = nullptr);
	virtual ~SOnlineClassroomController();

	SOnlineClassroomWidget *onlineClassroomWidget() const { return this->m_online_classroom_widget; };

	void showOnlineClassroomWidget(SMainWindow *parent);
	void lessonConnectionSend(QJsonObject &data);

protected:
	void initOnlineClassroomWidget(SMainWindow *parent);
	void initAffiliatedWidget();
	void initController();

	void createLessonConnection();
	void handleLessonConnectionRecv();
	void handleCommandJoinInLesson(QJsonObject &data);
	void handleCommandBeginLesson(QJsonObject &data);
	void handleCommandConcentrationData(QJsonObject &data);
	void handleCommandEndLesson(QJsonObject &data);
	void handleCommandRaiseHand(QJsonObject &data);
	void handleCommandResultOfRaiseHand(QJsonObject &data);
	void handleCommandRemoveMemberFromInSpeech(QJsonObject &data);


	void joinInLesson(QMap<QString, QVariant> &data);
	void lessonBegin();

	void openCamera();
	void mineCameraDisplay(QImage &frame);
	void sendMineCameraFrame();

	void updateRoomInfo(const QJsonObject &data);
	void updateLastTime();

	void raiseHand();
	void updateInSpeechWidgetInfo();
	void showInSpeechRemovableWidget();
	void updateInSpeechLastTime();
	void endSpeech();

	SEnterController *m_enter_controller;
	SWhiteBoardController *m_white_board_controller;
	SChatController *m_chat_controller;
	SConcentrationController *m_concentration_controller;

	SOnlineClassroomWidget *m_online_classroom_widget;
	SInSpeechRemovableWidget *m_in_speech_removeable_widget;
	User *m_user;
	Camera *m_camera;  // 摄像头对象
	QTimer m_lesson_timer;  // 1秒定时器
	Connection *m_lesson_connection;  // 该堂课的Tcp连接
	Room m_room;  // 当前的房间信息
	/*
		|-info(m_in_speech_list)
			|-student_id(QString)
			|-username(QString)
	*/
	QList<QMap<QString, QVariant>> m_in_speech_list;  // 发言中信息
};