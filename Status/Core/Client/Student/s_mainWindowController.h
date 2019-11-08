#pragma once
#pragma execution_character_set("utf-8")  
#include <QStack>
#include "s_mainWindow.h"
#include "Core/Model/user.h"
#include "Core/Model/course.h"
#include "Core/Client/Student/OnlineClassroom/s_onlineClassroomController.h"
#include "Core/Component/toast.h"


class SMainWindowController : public QObject {
	Q_OBJECT

public:
	SMainWindowController(SMainWindow *win, User* user);
	virtual ~SMainWindowController();
	void undo();  // ���ڷ���
	void redo();  // ����ǰ��

	void showOnlineClassroomWidget();
	void buttonPush(QAbstractButton *button);

protected:
	SMainWindow *m_win;
	User *m_user;
	SOnlineClassroomController *m_online_classroom_controller;
	QStack<QAbstractButton*> m_child_widget_undo_stack;  // �л��Ӵ��ķ���ջ
	QStack<QAbstractButton*> m_child_widget_redo_stack;  // �л��Ӵ���ǰ��ջ

	void clearWidget();
};