#pragma once
#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include "ui_t_enterDialog.h"


class TEnterDialog : public QDialog {
	Q_OBJECT

public:
	TEnterDialog(QWidget *parent = Q_NULLPTR);
	~TEnterDialog();
	const Ui::TEnterDialog& ui() const { return this->m_ui; };

private:
	Ui::TEnterDialog m_ui;

	bool is_pressed;  // �������Ƿ���
	bool is_moving;  // �����ƶ�
	QPoint start_pos;  // ����������ʱ������

	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
};