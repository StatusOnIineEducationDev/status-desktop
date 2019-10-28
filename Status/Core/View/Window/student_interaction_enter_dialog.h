#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_student_interaction_enter_dialog.h"

class StudentInteractionEnterDialog : public QDialog {
	Q_OBJECT

public:
	StudentInteractionEnterDialog(QWidget *parent = Q_NULLPTR);
	~StudentInteractionEnterDialog();
	const Ui::StudentInteractionEnterDialog& ui() const { return this->m_ui; };

private:
	Ui::StudentInteractionEnterDialog m_ui;

	bool is_pressed;  // �������Ƿ���
	bool is_moving;  // �����ƶ�
	QPoint start_pos;  // ����������ʱ������

	/*��д����¼������ڴ����϶�*/
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
};