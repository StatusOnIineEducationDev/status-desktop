#pragma once

#include <QWidget>
#include <QDateTime>
#include <QTimer>
#include <QJsonObject>
#include "ui_c_onlineClassroomWidget.h"
#include "Core/Tools/tools.h"
#include "Core/Tools/base64.h"
#include "Core/Hardware/camera.h"
#include "Core/Network/socket.h"
#include "Core/Model/user.h"
#include "Core/Client/conf.h"


class OnlineClassroomWidget : public QWidget {
	Q_OBJECT

signals:
	void quitLessonSuccess();

public:
	OnlineClassroomWidget(QWidget *parent = nullptr);
	~OnlineClassroomWidget();
	const Ui::OnlineClassroomWidget& ui() const { return this->m_ui; };

	void lessonConnectionSend(QJsonObject &data);

protected:
	void createLessonConnection();
	void distroyLessonConnection();
	virtual void handleLessonConnectionRecv() {};

	void openCamera();
	void distroyCamera();
	void sendMineCameraFrame();

	void updateLessonInfo(QString &course_name, QString &course_id, 
		QString &lesson_id, QString &teacher_name, QString &teacher_id, 
		CourseStatus &course_status, int create_timestamp, int begin_timestamp = -1);
	void updateBeginTime(int begin_timestamp);
	void updateLastTime(int begin_timestamp, int now_timestamp);
	void updateCourseStatus(CourseStatus &course_status);

	Ui::OnlineClassroomWidget m_ui;

	Camera *m_camera;  // 摄像头对象
	QTimer m_lesson_timer;  // 1秒定时器
	Connection *m_lesson_connection;  // 该堂课的Tcp连接
	/*
		|-info(m_room)
			|-room_name(QString)
			|-course_id(QString)
			|-lesson_id(QString)
			|-teacher_id(QString)
			|-teacher_name(QString)
			|-create_time(int)
			|-begin_time(int)
			|-course_status(CourseStatus)
	*/
	QMap<QString, QVariant> m_room;  // 当前的房间信息
	/*
		|-info(m_in_speech_list)
			|-student_id(QString)
			|-username(QString)
	*/
	QList<QMap<QString, QVariant>> m_in_speech_list;  // 发言中信息
};