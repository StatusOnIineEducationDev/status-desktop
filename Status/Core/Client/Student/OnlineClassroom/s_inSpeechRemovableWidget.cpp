#include "s_inSpeechRemovableWidget.h"


StudentInSpeechRemovableWidget::StudentInSpeechRemovableWidget(QWidget *parent)
	: QWidget(parent) {
	m_ui.setupUi(this);

	this->hide();
	this->setGeometry(this->x(), 30, this->width(), this->height());
}

StudentInSpeechRemovableWidget::~StudentInSpeechRemovableWidget() {

}

void StudentInSpeechRemovableWidget::updateInSpeechLastTime() {
	QString time_text = this->m_ui.time_text->text();
	static int count = 0;

	/*
		����ļ�ʱ��׼ȷ��ʱ����˲���¼ʱ��
		���ǲ��þ�̬�����Ļ�������Ҫ����
		��time_textΪ��0��������count
		�ڽ������Ժ󣬻Ὣtime_text����Ϊ��00:00:00��������һ������flag
	*/
	if (time_text == "00:00:00") {
		count = 0;
	}

	count++;
	this->m_ui.time_text->setText(formatTime(count));

	return;
}

void StudentInSpeechRemovableWidget::mouseMoveEvent(QMouseEvent *event) {
	QPoint pos = this->pos() + event->pos() - this->start_pos;
	int max_x = this->parentWidget()->width() - this->width(),
		max_y = this->parentWidget()->height() - this->height();

	if (pos.x() >= 0 && pos.y() >= 30 && pos.x() <= max_x && pos.y() <= max_y) {
		this->move(pos);
	}

	return;
}

void StudentInSpeechRemovableWidget::mousePressEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton) {
		this->is_pressed = true;
		this->start_pos = QPoint(event->pos().x(), event->pos().y());
	}

	return;
}

void StudentInSpeechRemovableWidget::mouseReleaseEvent(QMouseEvent *event) {
	this->is_pressed = false;

	return;
}

void StudentInSpeechRemovableWidget::updatePos() {
	int max_x = this->parentWidget()->width() - this->width(),
		max_y = this->parentWidget()->height() - this->height(),
		x = this->pos().x(),
		y = this->pos().y();

	if (this->pos().x() < 0) {
		x = 0;
	}
	if (this->pos().y() < 30) {
		y = 30;
	}
	if (this->pos().x() > max_x) {
		x = max_x;
	}
	if (this->pos().y() > max_y) {
		y = max_y;
	}
	this->setGeometry(x, y, this->width(), this->height());

	return;
}