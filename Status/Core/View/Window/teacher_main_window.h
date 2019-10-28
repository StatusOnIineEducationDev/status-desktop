#pragma once

#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include "ui_teacher_main_window.h"
#include "teacher_course_widget.h"
#include "teacher_interaction_widget.h"

class TeacherMainWindow: public QMainWindow {
	Q_OBJECT

public:
	TeacherMainWindow(QWidget *parent = Q_NULLPTR);
	virtual ~TeacherMainWindow() {};
	const Ui::TeacherMainWindow& ui() const { return this->m_ui; };

	/*最大化窗口*/
	void setWindowFull();
	/*还原窗口*/
	void setWindowNormal();

private:
	Ui::TeacherMainWindow m_ui;

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