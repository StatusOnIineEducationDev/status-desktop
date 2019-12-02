#pragma once
#include <QWidget>
#include "ui_c_courseManagementWidget.h"
#include "courseBaseWidget.h"

class CourseManagementWidget : public QWidget {
	Q_OBJECT

signals:
	void courseSwitched(const QString &course_id);

public:
	CourseManagementWidget(QWidget *parent = nullptr);
	~CourseManagementWidget();
	const Ui::CourseManagementWidget& ui() const { return this->m_ui; };

protected:
	void loadCourseBaseWidget();
	
	void emitSignalCourseSwitched(const int index);

	Ui::CourseManagementWidget m_ui;

	CourseBaseWidget *m_course_base_widget;
};