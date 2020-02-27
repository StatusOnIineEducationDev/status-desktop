#include "c_tipsDialog.h"


TipsDialog::TipsDialog(QWidget *parent)
	: QDialog(parent) {
	m_ui.setupUi(this);
	// 窗口属性设置
	this->setWindowFlag(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground, true);

	// 阴影
	QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
	shadow_effect->setOffset(0, 0);
	shadow_effect->setColor(Qt::gray);
	shadow_effect->setBlurRadius(10);
	this->m_ui.layout->setGraphicsEffect(shadow_effect);

	// 信号绑定
	this->connect(this->m_ui.confirm_btn, &QPushButton::clicked,
		this, &TipsDialog::emitSignalConfirm);
	this->connect(this->m_ui.cancel_btn, &QPushButton::clicked,
		this, &TipsDialog::emitSignalCancel);
}

TipsDialog::~TipsDialog() {

}

void TipsDialog::setText(QString &text) {
	this->m_ui.text->setText(text);

	return;
}

void TipsDialog::setConfirmText(QString &text) {
	this->m_ui.confirm_btn->setText(text);

	return;
}

void TipsDialog::setCancelText(QString &text) {
	this->m_ui.cancel_btn->setText(text);

	return;
}

void TipsDialog::emitSignalConfirm() {

	emit this->confirm();
	this->close();

	return;
}

void TipsDialog::emitSignalCancel() {

	emit this->cancel();
	this->close();

	return;
}

void TipsDialog::mouseMoveEvent(QMouseEvent *event) {
	// 计算鼠标当前位置
	// 如果鼠标在title bar且左键按下，则执行移动
	if (this->is_moving) {
		this->move(this->pos() + event->pos() - this->start_pos);
	}

	return;
}

void TipsDialog::mousePressEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton) {
		this->is_pressed = true;
		this->start_pos = QPoint(event->pos().x(), event->pos().y());
		if (this->start_pos.x() < this->width() && this->start_pos.y() < 35) {
			this->is_moving = true;
		}
	}

	return;
}

void TipsDialog::mouseReleaseEvent(QMouseEvent *event) {
	this->is_pressed = false;
	this->is_moving = false;

	return;
}