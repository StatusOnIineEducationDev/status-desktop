#pragma once
#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include <QDesktopWidget>
#include <QApplication>
#include "ui_tmainwindow.h"


class TMainWindow : public QMainWindow {
	Q_OBJECT

signals:
	void windowResized();

public:
	TMainWindow(QWidget *parent = Q_NULLPTR);
	virtual ~TMainWindow() {};
	const Ui::TMainWindow& ui() const { return this->m_ui; };

	void setWindowFull();
	void setWindowNormal();

private:
	Ui::TMainWindow m_ui;

	bool is_pressed;  // 鼠标左键是否按下
	bool is_moving;  // 正在移动
	bool is_resizing;  // 正在缩放窗口
	QPoint start_pos;  // 鼠标左键点下时的坐标

	/*重写鼠标事件，用于窗体拖动*/
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);
};