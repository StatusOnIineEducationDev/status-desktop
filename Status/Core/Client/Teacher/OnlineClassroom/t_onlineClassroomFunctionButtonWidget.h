#pragma once

#include <QWidget>
#include "ui_t_onlineClassroomFunctionButtonWidget.h"


class TeacherOnlineClassroomFunctionButtonWidget : public QWidget {
	Q_OBJECT

public:
	TeacherOnlineClassroomFunctionButtonWidget(QWidget *parent = nullptr);
	~TeacherOnlineClassroomFunctionButtonWidget();
	const Ui::TeacherOnlineClassroomFunctionButtonWidget& ui() const
	{ return this->m_ui; };

protected:
	Ui::TeacherOnlineClassroomFunctionButtonWidget m_ui;
};

