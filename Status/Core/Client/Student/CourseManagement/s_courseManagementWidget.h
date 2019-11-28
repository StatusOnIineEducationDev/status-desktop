#pragma once
#include <QWidget>
#include "../../Common/CourseManagement/courseManagementWidget.h"
#include "s_courseManagementFunctionButtonWidget.h"


class StudentCourseManagementWidget : public CourseManagementWidget {
	Q_OBJECT

public:
	StudentCourseManagementWidget(QWidget *parent = nullptr);
	virtual ~StudentCourseManagementWidget();

protected:
	void loadFunctionButtonWidget();

	StudentCourseManagementFunctionButtonWidget *m_function_button_widget;
};