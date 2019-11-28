#pragma once
#include "s_functionButtonWidget.h"
#include "../../Common/MainWindow/mainWindow.h"
#include "../CourseManagement/s_courseManagementWidget.h"
#include "../OnlineClassroom/s_onlineClassroomWidget.h"


class StudentMainWindow : public MainWindow {
	Q_OBJECT

signals:
	void windowResized();

public:
	StudentMainWindow(QWidget *parent = nullptr);
	virtual ~StudentMainWindow();
	
	virtual void clearWidget();
	void switchCourseMangementWidget();
	void switchOnlineClassroomWidget();

protected:
	void loadFunctionButtonWidget();

	StudentFunctionButtonWidget *m_function_button_widget;

	StudentCourseManagementWidget *m_course_management_widget;
	StudentOnlineClassroomWidget *m_online_classroom_widget;
};