#pragma once
#include <QtWidgets/QMainWindow>
#include <QListView>
#include "ui_t_courseManagementWidget.h"
#include "Core/Client/Teacher/t_mainWindow.h"


class TCourseManagementWidget : public QWidget {
	Q_OBJECT

signals:
	void windowResized();

public:
	TCourseManagementWidget(TMainWindow *parent = Q_NULLPTR);
	virtual ~TCourseManagementWidget();
	const Ui::TCourseManagementWidget& ui() const { return this->m_ui; };

	void handleWindowResized() { emit this->windowResized(); };

private:
	Ui::TCourseManagementWidget m_ui;
};