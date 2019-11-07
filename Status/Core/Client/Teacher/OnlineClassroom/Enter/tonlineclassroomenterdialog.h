#pragma once
#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include "ui_tonlineclassroomenterdialog.h"


class TOnlineClassroomEnterDialog : public QDialog {
	Q_OBJECT

public:
	TOnlineClassroomEnterDialog(QWidget *parent = Q_NULLPTR);
	~TOnlineClassroomEnterDialog();
	const Ui::TOnlineClassroomEnterDialog& ui() const { return this->m_ui; };

private:
	Ui::TOnlineClassroomEnterDialog m_ui;

	bool is_pressed;  // 鼠标左键是否按下
	bool is_moving;  // 正在移动
	QPoint start_pos;  // 鼠标左键点下时的坐标

	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
};