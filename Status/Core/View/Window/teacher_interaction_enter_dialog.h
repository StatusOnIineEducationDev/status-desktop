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

	bool is_pressed;  // �������Ƿ���
	bool is_moving;  // �����ƶ�
	QPoint start_pos;  // ����������ʱ������

	/*��д����¼������ڴ����϶�*/
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
};