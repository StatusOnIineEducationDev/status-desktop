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
	virtual ~TeacherMainWindow();
	const Ui::TeacherMainWindow& ui() const { return this->m_ui; };
	const TeacherCourseWidget* teacherCourseWidget() const { return this->teacher_course_widget; }
	const TeacherInteractionWidget* teacherInteractionWidget() const { return this->teacher_interaction_widget; }

public slots:
	/*�л������γ̹����Ӵ�*/
	void showTeacherCourseWidget();
	/*�л�����ʵʱ�������Ӵ�*/
	void showTeacherInteractionWidget();
	/*��󻯴���*/
	void setWindowFull();
	/*��ԭ����*/
	void setWindowNormal();

private:
	Ui::TeacherMainWindow m_ui;

	TeacherCourseWidget *teacher_course_widget;  // �γ̹����Ӵ�
	TeacherInteractionWidget *teacher_interaction_widget;  // ʵʱ�����Ӵ�
	bool is_pressed;  // �������Ƿ���
	bool is_moving;  // �����ƶ�
	bool is_resizing;  // �������Ŵ���
	QPoint start_pos;  // ����������ʱ������

	/*�л�����ʱ���ã������ǰ���Ӵ�*/
	void clearWidget();

	/*��д����¼������ڴ����϶�*/
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);
};