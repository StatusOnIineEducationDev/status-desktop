#pragma once
#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include <QDesktopWidget>
#include <QApplication>
#include "ui_smainwindow.h"


class SMainWindow : public QMainWindow {
	Q_OBJECT

signals:
	void windowResized();

public:
	SMainWindow(QWidget *parent = Q_NULLPTR);
	virtual ~SMainWindow();
	const Ui::SMainWindow& ui() const { return this->m_ui; };

	void setWindowFull();
	void setWindowNormal();

private:
	Ui::SMainWindow m_ui;

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