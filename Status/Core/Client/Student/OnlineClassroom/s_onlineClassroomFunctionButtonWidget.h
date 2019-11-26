#pragma once

#include <QWidget>
#include "ui_s_onlineClassroomFunctionButtonWidget.h"


class StudentOnlineClassroomFunctionButtonWidget : public QWidget {
	Q_OBJECT

public:
	StudentOnlineClassroomFunctionButtonWidget(QWidget *parent = nullptr);
	~StudentOnlineClassroomFunctionButtonWidget();
	const Ui::StudentOnlineClassroomFunctionButtonWidget& ui() const 
	{ return this->m_ui; };

protected:
	Ui::StudentOnlineClassroomFunctionButtonWidget m_ui;
};

