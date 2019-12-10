#pragma once
#pragma execution_character_set("utf-8")
#include <QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include <QJsonObject>
#include <QJsonArray>
#include "ui_c_loginWindow.h"
#include "Core/Network/httpRequest.h"
#include "Core/Client/conf.h"
#include "Core/Model/user.h"
#include "Core/Client/onlineEdu.h"
#include "Core/Client/Student/MainWindow/s_mainWindow.h"
#include "Core/Client/Teacher/MainWindow/t_mainWindow.h"


class LoginWindow : public QMainWindow {
	Q_OBJECT

public:
	LoginWindow(QWidget *parent = nullptr);
	virtual ~LoginWindow();
	const Ui::LoginWindow& ui() const { return this->m_ui; };

protected:
	void login();
	void loginRequest();
	void loginRequestSuccess(const QJsonObject &data);
	
	void loadLoginData(const QJsonObject &data);
	void loadTeacherClient();
	void loadStudentClient();

	void loginRunningAnimation();
	void loginResetAnimation();

	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

	Ui::LoginWindow m_ui;

	bool is_pressed;  // �������Ƿ���
	bool is_moving;  // �����ƶ�
	QPoint start_pos;  // ����������ʱ������
};
