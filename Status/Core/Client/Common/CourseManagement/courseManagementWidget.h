#pragma once

#include <QWidget>
#include "ui_c_courseManagementWidget.h"
#include "courseBaseWidget.h"

class CourseManagementWidget : public QWidget {
	Q_OBJECT

public:
	CourseManagementWidget(QWidget *parent = nullptr);
	~CourseManagementWidget();
	const Ui::CourseManagementWidget& ui() const { return this->m_ui; };

protected:
	void loadCourseBaseWidget();

	Ui::CourseManagementWidget m_ui;

	CourseBaseWidget *m_course_base_widget;
};