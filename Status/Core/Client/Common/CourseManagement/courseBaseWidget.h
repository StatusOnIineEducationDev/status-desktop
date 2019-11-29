#pragma once
#include <QWidget>
#include <QListView>
#include "ui_c_courseBaseWidget.h"
#include "Core/Model/user.h"


class CourseBaseWidget : public QWidget {
	Q_OBJECT

public:
	CourseBaseWidget(QWidget *parent = nullptr);
	virtual ~CourseBaseWidget();
	const Ui::CourseBaseWidget& ui() const { return this->m_ui; };

	void updateCourseComboBox();

protected:
	Ui::CourseBaseWidget m_ui;
};
