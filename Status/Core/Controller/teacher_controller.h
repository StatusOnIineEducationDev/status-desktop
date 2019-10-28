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
	// ������ȡ�γ̻�����Ϣ
	void getCourseBaseInfoRequest(const int &current_index); 
	void getCourseBaseInfoSuccess(const QJsonObject &data);
	//void geCourseBaseInfoFail();
	// ������ȡ���п�����Ϣ
	void getLessonsInfoRequest(const QString &course_id);
	void getLessonsInfoSuccess(const QJsonObject &data);
	//void geLessonsInfoFail();
	// ������ȡ����ѧ����Ϣ
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
	// ������������
	void createLesson();
	// ������ʼ�Ͽ�
	void beginLesson();

protected:
	// �������γ�ʼ��
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

	// �����������
	Camera *m_camera;  // ����ͷ����
	Connection *m_lesson_connection;  // ���ÿε�Tcp����
	Connection *m_paint_connection;  // �����Tcp����
	Room m_room;  // ��ǰ�ķ�����Ϣ
};


class TeacherController : public QObject {
	Q_OBJECT

public:
	TeacherController(TeacherMainWindow *win, User* user);
	virtual ~TeacherController();

public slots:
	/*�л������γ̹����Ӵ�*/
	void showTeacherCourseWidget();
	/*�л�����ʵʱ�������Ӵ�*/
	void showTeacherInteractionWidget();

protected:
	TeacherMainWindow *m_win;
	User *m_user;
	TeacherCourseWidgetController *m_teacher_course_widget_controller;
	TeacherInteractionWidgetController *m_teacher_interaction_widget_controller;

	/*�л�����ʱ���ã������ǰ���Ӵ�*/
	void clearWidget();
};