#pragma once
#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include <QDesktopWidget>
#include <QApplication>
#include <QStack>
#include "ui_c_mainWindow.h"


class MainWindow : public QMainWindow {
	Q_OBJECT

signals:
	void windowResized();

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	virtual ~MainWindow() {};
	const Ui::MainWindow& ui() const { return this->m_ui; };

protected:
	void setWindowFull();
	void setWindowNormal();

	void undo();
	void redo();
	void buttonPush(QAbstractButton *button);

	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);

	Ui::MainWindow m_ui;

	bool is_pressed;  // 鼠标左键是否按下
	bool is_moving;  // 正在移动
	bool is_resizing;  // 正在缩放窗口
	QPoint start_pos;  // 鼠标左键点下时的坐标

	QStack<QAbstractButton*> m_child_widget_undo_stack;  // 切换子窗的返回栈
	QStack<QAbstractButton*> m_child_widget_redo_stack;  // 切换子窗的前加栈
};
