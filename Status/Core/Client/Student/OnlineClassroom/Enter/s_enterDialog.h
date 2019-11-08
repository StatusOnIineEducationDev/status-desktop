#pragma once
#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include "ui_s_enterDialog.h"


class SEnterDialog : public QDialog {
	Q_OBJECT

public:
	SEnterDialog(QWidget *parent = Q_NULLPTR);
	~SEnterDialog();
	const Ui::SEnterDialog& ui() const { return this->m_ui; };

private:
	Ui::SEnterDialog m_ui;

	bool is_pressed;  // �������Ƿ���
	bool is_moving;  // �����ƶ�
	QPoint start_pos;  // ����������ʱ������

	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
};