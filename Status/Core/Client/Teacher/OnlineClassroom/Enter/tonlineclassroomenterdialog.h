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

	bool is_pressed;  // �������Ƿ���
	bool is_moving;  // �����ƶ�
	QPoint start_pos;  // ����������ʱ������

	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
};