#pragma once
#include <QWidget>
#include "ui_c_courseOverviewWidget.h"


class CourseOverviewWidget : public QWidget {
	Q_OBJECT

public:
	CourseOverviewWidget(QWidget *parent = nullptr);
	~CourseOverviewWidget();
	const Ui::CourseOverviewWidget& ui() const { return this->m_ui; };

protected:
	Ui::CourseOverviewWidget m_ui;

	CourseOverviewWidget *m_course_base_widget;
};