#pragma once
#include "t_functionButtonWidget.h"
#include "../../Common/MainWindow/mainWindow.h"
#include "../OnlineClassroom/t_onlineClassroomWidget.h"


class TeacherMainWindow : public MainWindow {
	Q_OBJECT

signals:
	void windowResized();

public:
	TeacherMainWindow(QWidget *parent = nullptr);
	virtual ~TeacherMainWindow();
	
	virtual void clearWidget();
	void switchOnlineClassroomWidget();

protected:
	TeacherFunctionButtonWidget *m_function_button_widget;
	TeacherOnlineClassroomWidget *m_online_classroom_widget;
};