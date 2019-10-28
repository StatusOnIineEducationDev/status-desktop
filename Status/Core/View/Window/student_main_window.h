#pragma once

#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include "ui_student_main_window.h"


class StudentMainWindow : public QMainWindow {
	Q_OBJECT

public:
	StudentMainWindow(QWidget *parent = Q_NULLPTR);
	virtual ~StudentMainWindow();
	const Ui::StudentMainWindow& ui() const { return this->m_ui; };

public slots:
	/*��󻯴���*/
	void setWindowFull();
	/*��ԭ����*/
	void setWindowNormal();

private:
	Ui::StudentMainWindow m_ui;

	bool is_pressed;  // �������Ƿ���
	bool is_moving;  // �����ƶ�
	bool is_resizing;  // �������Ŵ���
	QPoint start_pos;  // ����������ʱ������

	/*��д����¼������ڴ����϶�*/
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);
};