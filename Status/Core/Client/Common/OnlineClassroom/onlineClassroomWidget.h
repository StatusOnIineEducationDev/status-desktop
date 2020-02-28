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
#include "Core/Component/Loading/loading.h"
#include "Core/Client/Common/MainWindow/mainWindow.h"


class OnlineClassroomWidget : public QWidget {
	Q_OBJECT

signals:
	void quitLessonRequestSuccess();
	void closeEnterDialog();

public:
	OnlineClassroomWidget(MainWindow *parent = nullptr);
	~OnlineClassroomWidget();
	const Ui::OnlineClassroomWidget& ui() const { return this->m_ui; };

	void lessonConnectionSend(QJsonObject &data);

protected:
	void loadCameraDisplayWidget();
	void loadConcentrationAreaChart();
	void loadWaitingMask();

	void createLessonConnection();
	void distroyLessonConnection();
	virtual void handleLessonConnectionRecv() {};

	void openCamera();
	void closeCamera();
	void distroyCamera();
	void sendMineCameraFrame();

	void updateLessonInfo(QString &course_name, QString &course_id, 
		QString &lesson_id, QString &teacher_name, QString &teacher_id, 
		CourseStatus &course_status, int create_timestamp, int begin_timestamp = -1);
	void updateBeginTime(int begin_timestamp);
	void updateLastTime();
	void updateCourseStatus(CourseStatus &course_status);
	void updateDynamicAreaChat(int concentration_timestamp, int concentration_value);

	void emitSignalCloseEnterDialog();

	void setWarningText(const QString &text) 
	{ this->m_ui.warning_text->setText(text); return; };

	Ui::OnlineClassroomWidget m_ui;

	CameraDisplayWidget *m_camera_display_widget;
	AreaChartDynamic *m_concentration_area_chart;  // 专注度面积图（缩略）

	LoadingMask *m_loading_mask;
	MainWindow *m_main_win;

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
		|-info(m_final_data_list)
			|-concentration_value(int)
			|-concentration_timestamp(int)
	*/
	QList<QMap<QString, QVariant>> m_final_data_list;  // 专注度数据
};