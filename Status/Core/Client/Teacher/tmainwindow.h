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