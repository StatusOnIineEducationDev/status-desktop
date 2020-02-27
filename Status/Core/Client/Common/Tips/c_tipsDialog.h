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

	bool is_pressed;  // 鼠标左键是否按下
	bool is_moving;  // 正在移动
	QPoint start_pos;  // 鼠标左键点下时的坐标
};