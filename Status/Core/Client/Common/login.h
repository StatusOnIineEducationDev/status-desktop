#pragma once
#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include <QDesktopWidget>
#include <QApplication>
#include "ui_c_loginWindow.h"
#include "Core/Client/Teacher/t_mainWindow.h"
#include "Core/Client/Teacher/t_mainWindowController.h"
#include "Core/Client/Student/s_mainWindow.h"
#include "Core/Client/Student/s_mainWindowController.h"

class LoginWindow : public QMainWindow {
	Q_OBJECT

public:
	LoginWindow(QWidget *parent = Q_NULLPTR);
	virtual ~LoginWindow();
	const Ui::LoginWindow& ui() const { return this->m_ui; };
	
	void login();

private:
	Ui::LoginWindow m_ui;

	TMainWindow *t_win;
	SMainWindow *s_win;
	TMainWindowController *teacher_controller;
	SMainWindowController *student_controller;
};
