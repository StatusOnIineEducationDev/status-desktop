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
	~TeacherMainWindow();

public slots:
	/*切换至“课程管理”子窗*/
	void showTeacherCourseWidget();
	/*切换至“实时互动”子窗*/
	void showTeacherInteractionWidget();
	/*最大化窗口*/
	void setWindowFull();
	/*还原窗口*/
	void setWindowNormal();

private:
	Ui::TeacherMainWindow ui;

	TeacherCourseWidget *teacher_course_widget;  // 课程管理子窗
	TeacherInteractionWidget *teacher_interaction_widget;  // 实时互动子窗
	bool is_pressed;  // 鼠标左键是否按下
	bool is_moving;  // 正在移动
	bool is_resizing;  // 正在缩放窗口
	QPoint start_pos;  // 鼠标左键点下时的坐标

	/*切换窗口时调用，清除当前的子窗*/
	void clearWidget();

	/*重写鼠标事件，用于窗体拖动*/
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);
};