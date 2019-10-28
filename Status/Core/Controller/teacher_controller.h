#pragma once

#include "Core/View/Window/teacher_main_window.h"
#include "Core/View/Component/camera.h"
#include "Core/View/Component/chart.h"
#include "Core/Transport/socket.h"
#include "Core/Model/user.h"
#include "Core/Model/course.h"
#include "Core/Transport/image_send.h"
#include "Core/View/Window/teacher_interaction_enter_dialog.h"

class TeacherCourseWidgetController : public QObject {
	Q_OBJECT

public:
	TeacherCourseWidgetController(TeacherMainWindow *win, User *user);
	virtual ~TeacherCourseWidgetController();

public slots:
	void updateCourseComboBox();
	void updateAreaChartPointInfo(const QPointF &point);
	// ——获取课程基本信息
	void getCourseBaseInfoRequest(const int &current_index); 
	void getCourseBaseInfoSuccess(const QJsonObject &data);
	//void geCourseBaseInfoFail();
	// ——获取所有课堂信息
	void getLessonsInfoRequest(const QString &course_id);
	void getLessonsInfoSuccess(const QJsonObject &data);
	//void geLessonsInfoFail();
	// ——获取单个学生信息
	//void getStudentInfoRequest(const QString &uid);
	//void getStudentInfoSuccess(const QJsonObject &data);
	//void getStudentInfoFail();

protected:
	void updateRoomBaseInfo();
	void updateAreaChart();
	void updateEmotionReportPercentageChart();
	void updateEmotionReportBarChart(int button_id);

	TeacherMainWindow *m_win;
	User *m_user;
	TeacherCourseWidget *m_teacher_course_widget;
	Course *m_course;
	QList<Lesson> *m_lessons_list;
};


class TeacherInteractionWidgetController : public QObject {
	Q_OBJECT

public:
	TeacherInteractionWidgetController(TeacherMainWindow *win, User *user);
	virtual ~TeacherInteractionWidgetController();

public slots:
	void openCamera();
	void mineCameraDisplay(QImage &frame);
	void handleLessonConnectionRecv();
	void handlePaintConnectionRecv();
	void sendPaintCommand(QJsonObject &data);
	// ——创建课室
	void createLesson();
	// ——开始上课
	void beginLesson();

protected:
	// ——二段初始化
	void enterDialogInit();
	void interactionWidgetInit();

	void createLessonConnection();
	void createPaintConnection();
	void handleCommandCreateLesson(QJsonObject &data);
	void handleCommandPaintCommand(QJsonObject &data);

	TeacherMainWindow *m_win;
	User *m_user;
	TeacherInteractionWidget *m_teacher_interaction_widget;
	TeacherInteractionEnterDialog *m_teacher_interaction_enter_dialog;

	// ——课堂相关
	Camera *m_camera;  // 摄像头对象
	Connection *m_lesson_connection;  // 该堂课的Tcp连接
	Connection *m_paint_connection;  // 画板的Tcp连接
	Room m_room;  // 当前的房间信息
};


class TeacherController : public QObject {
	Q_OBJECT

public:
	TeacherController(TeacherMainWindow *win, User* user);
	virtual ~TeacherController();

public slots:
	/*切换至“课程管理”子窗*/
	void showTeacherCourseWidget();
	/*切换至“实时互动”子窗*/
	void showTeacherInteractionWidget();

protected:
	TeacherMainWindow *m_win;
	User *m_user;
	TeacherCourseWidgetController *m_teacher_course_widget_controller;
	TeacherInteractionWidgetController *m_teacher_interaction_widget_controller;

	/*切换窗口时调用，清除当前的子窗*/
	void clearWidget();
};