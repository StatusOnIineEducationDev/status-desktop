#pragma once
#pragma execution_character_set("utf-8")
#include <QJsonArray>
#include <QList>
#include <QtConcurrent>
#include "t_onlineClassroomController.h"
#include "Core/Client/Teacher/t_mainWindow.h"
#include "Core/Client/Teacher/OnlineClassroom/Enter/t_enterController.h"
#include "Core/Client/Teacher/OnlineClassroom/Interaction/t_whiteBoardController.h"
#include "Core/Client/Teacher/OnlineClassroom/Interaction/t_chatController.h"
#include "Core/Hardware/camera.h"
#include "Core/Network/socket.h"
#include "Core/Client/conf.h"
#include "Core/Tools/tools.h"


class TOnlineClassroomController : public QObject{
	Q_OBJECT

public:
	TOnlineClassroomController(User *user, QObject *parent = nullptr);
	virtual ~TOnlineClassroomController();

	TOnlineClassroomWidget *onlineClassroomWidget() const { return this->m_online_classroom_widget; };

	void showOnlineClassroomWidget(TMainWindow *parent);
	void hideOnlineClassroomWidget(TMainWindow *parent);
	void lessonConnectionSend(QJsonObject &data);

protected:
	void initOnlineClassroomWidget(TMainWindow *parent);
	void initAffiliatedWidget();
	void initController();

	void createLessonConnection();
	void distroyLessonConnection();
	void handleLessonConnectionRecv();
	void handleCommandCreateLesson(QJsonObject &data);
	void handleCommandBeginLesson(QJsonObject &data);
	void handleCommandEndLesson(QJsonObject &data);
	void handleCommandRaiseHand(QJsonObject &data);
	void handleCommandResultOfRaiseHand(QJsonObject &data);
	void handleCommandRemoveMemberFromInSpeech(QJsonObject &data);

	void createLesson(QMap<QString, QVariant> &data);
	void beginLesson();
	void endLesson();
	void releaseResources();

	void openCamera();
	void distroyCamera();
	void mineCameraDisplay(QImage &frame);

	void updateLastTime();

	void showHandleRaiseHandWidget();
	void updateHandleRaiseHandWidgetInfo(int row = -1);
	void updateInSpeechWidgetInfo();
	void acceptRaiseHand();
	void refuseRaiseHand();
	void removeMemberFromInSpeech();

	TEnterController *m_enter_controller;
	TWhiteBoardController *m_white_board_controller;
	TChatController *m_chat_controller;

	TOnlineClassroomWidget *m_online_classroom_widget;
	THandleRaiseHandWidget *m_handle_raise_hand_widget;
	User *m_user;
	Camera *m_camera;  // 摄像头对象
	QTimer m_lesson_timer;  // 1秒定时器
	Connection *m_lesson_connection;  // 该堂课的Tcp连接
	Room m_room;  // 当前的房间信息
	/*
		|-info(m_rasie_hand_info_list)
			|-student_id(QString)
			|-username(QString)
			|-timestamp(int)
	*/
	QList<QMap<QString, QVariant>> m_rasie_hand_info_list;  // 举手信息
	/*
		|-info(m_in_speech_list)
			|-student_id(QString)
			|-username(QString)
	*/
	QList<QMap<QString, QVariant>> m_in_speech_list;  // 发言中信息
};