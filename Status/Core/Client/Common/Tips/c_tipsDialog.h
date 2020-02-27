#pragma once
#include <QtWidgets/QMainWindow>
#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>
#include "ui_c_tipsDialog.h"


class TipsDialog : public QDialog {
	Q_OBJECT

signals:
	void confirm();
	void cancel();

public:
	TipsDialog(QWidget *parent = Q_NULLPTR);
	~TipsDialog();
	const Ui::TipsDialog& ui() const { return this->m_ui; };

	void setText(QString &text);
	void setConfirmText(QString &text);
	void setCancelText(QString &text);

protected:
	Ui::TipsDialog m_ui;

	void emitSignalConfirm();
	void emitSignalCancel();

	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

	bool is_pressed;  // �������Ƿ���
	bool is_moving;  // �����ƶ�
	QPoint start_pos;  // ����������ʱ������
};