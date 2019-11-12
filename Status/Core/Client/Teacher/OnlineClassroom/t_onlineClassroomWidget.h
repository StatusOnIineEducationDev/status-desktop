#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_t_onlineClassroomWidget.h"
#include "ui_t_handleRaiseHandWidget.h"
#include "Core/Client/Teacher/t_mainWindow.h"


class TOnlineClassroomWidget : public QWidget {
	Q_OBJECT

signals:
	void windowResized();

public:
	TOnlineClassroomWidget(TMainWindow *parent = Q_NULLPTR);
	~TOnlineClassroomWidget();
	
	const Ui::TOnlineClassroomWidget& ui() const { return this->m_ui; };

	void handleWindowResized() { emit this->windowResized(); };

private:
	Ui::TOnlineClassroomWidget m_ui;
};


class THandleRaiseHandWidget : public QWidget {
	Q_OBJECT

public:
	THandleRaiseHandWidget(TOnlineClassroomWidget *parent = Q_NULLPTR);
	~THandleRaiseHandWidget();
	const Ui::THandleRaiseHandWidget& ui() const { return this->m_ui; };

	void updataPos();

private:
	Ui::THandleRaiseHandWidget m_ui;
	TOnlineClassroomWidget *m_parent;
};
