#pragma once

#include <QWidget>
#include <QDateTime>
#include <QTimer>
#include <QJsonObject>
#include "ui_c_onlineClassroomWidget.h"
#include "../CameraDisplay/cameraDisplayWidget.h"
#include "Core/Component/Chart/areaChartDynamic.h"
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
	void loadCameraDisplayWidget();
	void loadConcentrationAreaChart();

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
	void updateLastTime();
	void updateCourseStatus(CourseStatus &course_status);
	void updateDynamicAreaChat(int concentration_timestamp, int concentration_value);

	Ui::OnlineClassroomWidget m_ui;

	CameraDisplayWidget *m_camera_display_widget;
	AreaChartDynamic *m_concentration_area_chart;  // רע�����ͼ�����ԣ�

	Camera *m_camera;  // ����ͷ����
	QTimer m_lesson_timer;  // 1�붨ʱ��
	Connection *m_lesson_connection;  // ���ÿε�Tcp����
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
	QMap<QString, QVariant> m_room;  // ��ǰ�ķ�����Ϣ
		/*
		|-info(m_final_data_list)
			|-concentration_value(int)
			|-fatigue_value(int)
			|-toward_score(int)
			|-emotion_score(int)
			|-concentration_timestamp(int)
	*/
	QList<QMap<QString, QVariant>> m_final_data_list;  // רע������
};