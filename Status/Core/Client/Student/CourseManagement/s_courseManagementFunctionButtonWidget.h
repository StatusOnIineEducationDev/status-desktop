#pragma once
#include <QWidget>
#include "ui_s_courseManagementFunctionButtonWidget.h"


class StudentCourseManagementFunctionButtonWidget : public QWidget {
	Q_OBJECT

public:
	StudentCourseManagementFunctionButtonWidget(QWidget *parent = nullptr);
	~StudentCourseManagementFunctionButtonWidget();
	const Ui::StudentCourseManagementFunctionButtonWidget& ui() const 
	{ return this->m_ui; };

protected:
	Ui::StudentCourseManagementFunctionButtonWidget m_ui;
};
