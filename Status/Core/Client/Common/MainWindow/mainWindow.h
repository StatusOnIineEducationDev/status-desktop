#pragma once
#include <QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include <QDesktopWidget>
#include <QApplication>
#include <QStack>
#include "ui_c_mainWindow.h"
#include "Core/Model/user.h"


class MainWindow : public QMainWindow {
	Q_OBJECT

signals:
	void windowResized();

public:
	MainWindow(QWidget *parent = nullptr);
	virtual ~MainWindow() {};
	const Ui::MainWindow& ui() const { return this->m_ui; };

	virtual void clearWidget() {};

	void updateUserInfo();

protected: 
	void setWindowFull();
	void setWindowNormal();

	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);

	Ui::MainWindow m_ui;

	bool is_pressed;  // �������Ƿ���
	bool is_moving;  // �����ƶ�
	bool is_resizing;  // �������Ŵ���
	QPoint start_pos;  // ����������ʱ������
};
