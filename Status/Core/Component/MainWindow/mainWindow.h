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

	bool is_pressed;  // �������Ƿ���
	bool is_moving;  // �����ƶ�
	bool is_resizing;  // �������Ŵ���
	QPoint start_pos;  // ����������ʱ������

	QStack<QAbstractButton*> m_child_widget_undo_stack;  // �л��Ӵ��ķ���ջ
	QStack<QAbstractButton*> m_child_widget_redo_stack;  // �л��Ӵ���ǰ��ջ
};
