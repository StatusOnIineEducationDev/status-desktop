#pragma once
#pragma execution_character_set("utf-8")  
#include <QWidget>
#include "ui_t_onlineClassroomFunctionButtonWidget.h"


class TeacherOnlineClassroomFunctionButtonWidget : public QWidget {
	Q_OBJECT

public:
	TeacherOnlineClassroomFunctionButtonWidget(QWidget *parent = nullptr);
	~TeacherOnlineClassroomFunctionButtonWidget();
	const Ui::TeacherOnlineClassroomFunctionButtonWidget& ui() const
	{ return this->m_ui; };

	void updateRaiseHandButton(int count);

protected:
	Ui::TeacherOnlineClassroomFunctionButtonWidget m_ui;
};

