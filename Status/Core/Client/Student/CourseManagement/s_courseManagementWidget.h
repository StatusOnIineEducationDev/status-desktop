#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_s_courseManagementWidget.h"
#include "Core/Client/Student/s_mainWindow.h"


class SCourseManagementWidget : public QWidget {
	Q_OBJECT

signals:
	void windowResized();

public:
	SCourseManagementWidget(SMainWindow *parent = Q_NULLPTR);
	virtual ~SCourseManagementWidget();
	const Ui::SCourseManagementWidget& ui() const { return this->m_ui; };

	void handleWindowResized() { emit this->windowResized(); };

private:
	Ui::SCourseManagementWidget m_ui;
};