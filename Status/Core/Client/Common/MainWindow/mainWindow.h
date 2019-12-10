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

	bool is_pressed;  // 鼠标左键是否按下
	bool is_moving;  // 正在移动
	bool is_resizing;  // 正在缩放窗口
	QPoint start_pos;  // 鼠标左键点下时的坐标
};
