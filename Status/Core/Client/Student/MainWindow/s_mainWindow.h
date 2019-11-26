#pragma once
#include "s_functionButtonWidget.h"
#include "../../Common/MainWindow/mainWindow.h"
#include "../OnlineClassroom/s_onlineClassroomWidget.h"


class StudentMainWindow : public MainWindow {
	Q_OBJECT

signals:
	void windowResized();

public:
	StudentMainWindow(QWidget *parent = nullptr);
	virtual ~StudentMainWindow();
	
	virtual void clearWidget();
	void switchOnlineClassroomWidget();

protected:
	StudentFunctionButtonWidget *m_function_button_widget;
	StudentOnlineClassroomWidget *m_online_classroom_widget;
};