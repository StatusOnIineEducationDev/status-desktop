#pragma once

#include <QWidget>
#include "ui_c_onlineClassroomWidget.h"


class OnlineClassroomWidget : public QWidget {
	Q_OBJECT

public:
	OnlineClassroomWidget(QWidget *parent = nullptr);
	~OnlineClassroomWidget();
	const Ui::OnlineClassroomWidget& ui() const { return this->m_ui; };

protected:
	Ui::OnlineClassroomWidget m_ui;
};