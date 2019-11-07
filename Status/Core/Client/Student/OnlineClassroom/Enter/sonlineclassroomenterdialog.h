#pragma once
#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include "ui_sonlineclassroomenterdialog.h"


class SOnlineClassroomEnterDialog : public QDialog {
	Q_OBJECT

public:
	SOnlineClassroomEnterDialog(QWidget *parent = Q_NULLPTR);
	~SOnlineClassroomEnterDialog();
	const Ui::SOnlineClassroomEnterDialog& ui() const { return this->m_ui; };

private:
	Ui::SOnlineClassroomEnterDialog m_ui;

	bool is_pressed;  // �������Ƿ���
	bool is_moving;  // �����ƶ�
	QPoint start_pos;  // ����������ʱ������

	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
};