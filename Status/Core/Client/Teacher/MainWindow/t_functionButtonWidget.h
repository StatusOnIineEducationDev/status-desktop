#pragma once
#include <QWidget>
#include "ui_t_functionButtonWidget.h"

class TeacherFunctionButtonWidget : public QWidget {
	Q_OBJECT

public:
	TeacherFunctionButtonWidget(QWidget *parent = nullptr);
	virtual ~TeacherFunctionButtonWidget();
	const Ui::TeacherFunctionButtonWidget& ui() const { return this->m_ui; };

protected:
	Ui::TeacherFunctionButtonWidget m_ui;
};

