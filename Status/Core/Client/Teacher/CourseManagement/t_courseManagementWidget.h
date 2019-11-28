#pragma once
#include <QWidget>
#include "../../Common/CourseManagement/courseManagementWidget.h"
#include "t_courseManagementFunctionButtonWidget.h"


class TeacherCourseManagementWidget : public CourseManagementWidget {
	Q_OBJECT

public:
	TeacherCourseManagementWidget(QWidget *parent = nullptr);
	virtual ~TeacherCourseManagementWidget();

protected:
	void loadFunctionButtonWidget();

	TeacherCourseManagementFunctionButtonWidget *m_function_button_widget;
};