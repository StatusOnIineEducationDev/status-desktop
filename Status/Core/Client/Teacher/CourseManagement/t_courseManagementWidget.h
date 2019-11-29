#pragma once
#pragma execution_character_set("utf-8")  
#include <QWidget>
#include "../../Common/CourseManagement/courseManagementWidget.h"
#include "t_courseManagementFunctionButtonWidget.h"
#include "CourseOverview/t_courseOverviewWidget.h"


class TeacherCourseManagementWidget : public CourseManagementWidget {
	Q_OBJECT

public:
	TeacherCourseManagementWidget(QWidget *parent = nullptr);
	virtual ~TeacherCourseManagementWidget();

protected:
	void loadFunctionButtonWidget();
	void loadCourseOverviewWidget();

	TeacherCourseManagementFunctionButtonWidget *m_function_button_widget;
	TeacherCourseOverviewWidget *m_course_overview_widget;
};