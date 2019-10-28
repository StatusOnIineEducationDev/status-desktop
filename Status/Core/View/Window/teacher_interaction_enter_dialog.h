#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_teacher_interaction_enter_dialog.h"

class TeacherInteractionEnterDialog : public QDialog {
	Q_OBJECT

public:
	TeacherInteractionEnterDialog(QWidget *parent = Q_NULLPTR);
	~TeacherInteractionEnterDialog();
	const Ui::TeacherInteractionEnterDialog& ui() const { return this->m_ui; };

private:
	Ui::TeacherInteractionEnterDialog m_ui;

	bool is_pressed;  // 鼠标左键是否按下
	bool is_moving;  // 正在移动
	QPoint start_pos;  // 鼠标左键点下时的坐标

	/*重写鼠标事件，用于窗体拖动*/
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
};