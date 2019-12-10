#pragma once
#include <QWidget>
#include "ui_c_courseManagementWidget.h"
#include "courseBasicWidget.h"


class CourseManagementWidget : public QWidget {
	Q_OBJECT

public:
	CourseManagementWidget(QWidget *parent = nullptr);
	~CourseManagementWidget();
	const Ui::CourseManagementWidget& ui() const { return this->m_ui; };
	const CourseBasicWidget* courseBasicWidget() const { return this->m_course_basic_widget; };

protected:
	void loadCourseBasicWidget();

	Ui::CourseManagementWidget m_ui;

	CourseBasicWidget *m_course_basic_widget;
};