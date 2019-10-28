#pragma once

#include <QUdpSocket>
#include "Core/View/Window/student_main_window.h"
#include "Core/View/Window/student_interaction_widget.h"
#include "Core/View/Window/student_interaction_enter_dialog.h"
#include "Core/View/Component/camera.h"
#include "Core/View/Component/chart.h"
#include "Core/Transport/socket.h"
#include "Core/Model/user.h"


class StudentInteractionWidgetController : public QObject {
	Q_OBJECT

public:
	StudentInteractionWidgetController(StudentMainWindow *win, User *user);
	virtual ~StudentInteractionWidgetController();

public slots:
	void openCamera();
	void mineCameraDisplay(QImage &frame);
	void startSendCameraFrame();
	void sendMineCameraFrame();
	void handleLessonConnectionRecv();
	void handlePaintConnectionRecv();
	// ——获取所有课程状态
	void getCoursesListStatusRequest();
	void getCoursesListStatusSuccess(const QJsonObject &data);
	//void getCoursesListStatusFail();
	// ——申请加入课堂
	void joinInLesson();

protected:
	// ——二段初始化
	void enterDialogInit();
	void interactionWidgetInit();

	void handleCommandJoinInLesson(QJsonObject &data);
	void handleCommandBeginLesson(QJsonObject &data);
	void handleCommandConcentrationData(QJsonObject &data);
	void handleCommandPaintCommand(QJsonObject &data);
	void updateRoomBaseInfo(const QJsonObject &data);
	void createLessonConnection();
	void createPaintConnection();

	StudentMainWindow *m_win;  // 主窗
	User *m_user;
	StudentInteractionWidget *m_student_interaction_widget;
	StudentInteractionEnterDialog *m_student_interaction_enter_dialog;

	// ——课堂相关
	Camera *m_camera;  // 摄像头对象
	Connection *m_lesson_connection;  // 该堂课的Tcp连接
	Connection *m_paint_connection;  // 画板的Tcp连接
	AreaChartDynamic *m_concentration_area_chart;  // 专注度面积图
	AreaChartDynamicMin *m_concentration_area_chart_min;  // 专注度面积图（缩略）
	QList<Concentration> m_concentration_list;  // 专注度数据
	Room m_room;  // 当前的房间信息
};


class StudentController : public QObject {
	Q_OBJECT

public:
	StudentController(StudentMainWindow *win, User* user);
	virtual ~StudentController();

public slots:
	/*切换至“实时互动”子窗*/
	void showStudentInteractionWidget();

protected:
	StudentMainWindow *m_win;
	User *m_user;
	StudentInteractionWidgetController *m_student_interaction_widget_controller;

	/*切换窗口时调用，清除当前的子窗*/
	void clearWidget();
};