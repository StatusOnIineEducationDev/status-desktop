#pragma once
#include <QWidget>
#include "../../Common/CourseManagement/courseManagementWidget.h"
#include "s_courseManagementFunctionButtonWidget.h"
#include "CourseResource/s_courseResourceWidget.h"


class StudentCourseManagementWidget : public CourseManagementWidget {
	Q_OBJECT

public:
	StudentCourseManagementWidget(QWidget *parent = nullptr);
	virtual ~StudentCourseManagementWidget();

protected:
	void loadFunctionButtonWidget();
	void loadCourseResourceWidget();

	StudentCourseManagementFunctionButtonWidget *m_function_button_widget;
	StudentCourseResourceWidget *m_course_resource_widget;
};