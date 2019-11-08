#pragma once
#pragma execution_character_set("utf-8")  
#include <QStack>
#include "t_mainWindow.h"
#include "Core/Model/user.h"
#include "Core/Model/course.h"
#include "Core/Client/Teacher/OnlineClassroom/t_onlineClassroomController.h"
#include "Core/Component/toast.h"


class TMainWindowController : public QObject {
	Q_OBJECT

public:
	TMainWindowController(TMainWindow *win, User* user);
	virtual ~TMainWindowController();
	void undo();  // 窗口返回
	void redo();  // 窗口前进

	void showTeacherCourseWidget();
	void showOnlineClassroomWidget();
	void buttonPush(QAbstractButton *button);

protected:
	TMainWindow *m_win;
	User *m_user;
	//TeacherCourseWidgetController *m_teacher_course_widget_controller;
	TOnlineClassroomController *m_online_classroom_controller;
	QStack<QAbstractButton*> m_child_widget_undo_stack;  // 切换子窗的返回栈
	QStack<QAbstractButton*> m_child_widget_redo_stack;  // 切换子窗的前加栈

	void clearWidget();
};