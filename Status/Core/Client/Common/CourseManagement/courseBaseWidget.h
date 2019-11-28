#pragma once
#include <QWidget>
#include "ui_c_courseBaseWidget.h"


class CourseBaseWidget : public QWidget {
	Q_OBJECT

public:
	CourseBaseWidget(QWidget *parent = nullptr);
	virtual ~CourseBaseWidget();
	const Ui::CourseBaseWidget& ui() const { return this->m_ui; };

protected:
	Ui::CourseBaseWidget m_ui;
};
