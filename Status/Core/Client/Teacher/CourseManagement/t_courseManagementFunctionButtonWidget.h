#pragma once
#include <QWidget>
#include "ui_t_courseManagementFunctionButtonWidget.h"


class TeacherCourseManagementFunctionButtonWidget : public QWidget {
	Q_OBJECT

public:
	TeacherCourseManagementFunctionButtonWidget(QWidget *parent = nullptr);
	~TeacherCourseManagementFunctionButtonWidget();
	const Ui::TeacherCourseManagementFunctionButtonWidget& ui() const
	{ return this->m_ui; };

protected:
	Ui::TeacherCourseManagementFunctionButtonWidget m_ui;
};
