#include "toast.h"

QWidget* Toast::s_win = nullptr;

Toast::Toast(QString &text)
	: QLabel(s_win) {
	this->init(); 
	this->setInfoText(text);
}

Toast::Toast(const char *text)
	: QLabel(s_win) {
	this->init();
	this->setInfoText(QString(text));
}

void Toast::init() {
	QFont font;

	font.setFamily("Microsoft Yahei");
	font.setPointSize(this->m_point_size);
	this->setFont(font);
	this->setAlignment(Qt::AlignCenter);
	this->setStyleSheet("QLabel{color:white;background-color:rgba(0,0,0,150);border-radius:5px;}");

	// ——动画
	this->m_effect = new QGraphicsOpacityEffect(this);
	this->m_effect->setOpacity(1.0);
	this->setGraphicsEffect(this->m_effect);

	this->m_show_animation = new QPropertyAnimation(this->m_effect, "opacity", this);
	this->m_show_animation->setDuration(500);
	this->m_show_animation->setStartValue(0);
	this->m_show_animation->setEndValue(1.0);

	this->m_hide_animation = new QPropertyAnimation(this->m_effect, "opacity", this);
	this->m_hide_animation->setDuration(500);
	this->m_hide_animation->setStartValue(1.0);
	this->m_hide_animation->setEndValue(0);

	// ——信号绑定
	this->connect(&this->timer, &QTimer::timeout, this, &Toast::hide);

	return; 
}

void Toast::setWin(QWidget *win) {
	Toast::s_win = win;

	return;
}

void Toast::setInfoText(QString &text) {
	int text_width, text_height;
	int x, y, width, height;

	this->setText(text);
	// ——获取文本长度
	this->adjustSize();
	text_width = this->width();
	text_height = this->height();
	// ——重新设置大小和位置
	width = text_width + 2 * this->m_padding_left_right;
	height = text_height + 2 * this->m_padding_top_bottom;
	x = (this->s_win->width() / 2) - (text_width / 2);
	y = 9 * (this->s_win->height() / 10);
	this->setGeometry(x, y, width, height);

	return;
}

void Toast::setInfoText(const char *text) {
	this->setInfoText(QString(text));

	return;
}

void Toast::show() {
	this->timer.start(2500);
	this->QLabel::show();
	this->m_show_animation->start();

	return;
}

void Toast::hide() {
	this->m_hide_animation->start();
	this->connect(this->m_hide_animation, &QPropertyAnimation::finished, this, &QLabel::hide);
	this->connect(this->m_hide_animation, &QPropertyAnimation::finished, this, &Toast::emitCompleteSignal);

	return;
}

void Toast::emitCompleteSignal() {
	emit this->complete();

	return;
}

