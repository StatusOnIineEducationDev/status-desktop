#pragma once
#include <QWidget>
#include "ui_s_functionButtonWidget.h"


class StudentFunctionButtonWidget : public QWidget {
	Q_OBJECT

public:
	StudentFunctionButtonWidget(QWidget *parent = nullptr);
	virtual ~StudentFunctionButtonWidget();
	const Ui::StudentFunctionButtonWidget& ui() const { return this->m_ui; };

protected:
	Ui::StudentFunctionButtonWidget m_ui;
};

