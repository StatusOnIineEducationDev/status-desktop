#include "s_onlineclassroomWidget.h"


SOnlineClassroomWidget::SOnlineClassroomWidget(SMainWindow *parent) : QWidget(parent) {
	m_ui.setupUi(this);
	m_ui.function_tabWidget->setAttribute(Qt::WA_StyledBackground);  // tabÀ¸ÏÔÊ¾±³¾°É«
	this->connect(parent, &SMainWindow::windowResized, this, &SOnlineClassroomWidget::handleWindowResized);
}

SOnlineClassroomWidget::~SOnlineClassroomWidget() {

}



SInSpeechRemovableWidget::SInSpeechRemovableWidget(SOnlineClassroomWidget *parent)
	: QWidget(parent) {
	m_ui.setupUi(this);

	int x = parent->width() - this->width() - parent->ui().frame->width(),
		y = 30;
	this->setGeometry(x, y, this->width(), this->height());

	this->connect(parent, &SOnlineClassroomWidget::windowResized, this, &SInSpeechRemovableWidget::updatePos);
}

SInSpeechRemovableWidget::~SInSpeechRemovableWidget() {

}

void SInSpeechRemovableWidget::mouseMoveEvent(QMouseEvent *event) {
	QPoint pos = this->pos() + event->pos() - this->start_pos;
	int max_x = this->parentWidget()->width() - this->width(),
		max_y = this->parentWidget()->height() - this->height();

	if (pos.x() >= 0 && pos.y() >= 0 && pos.x() <= max_x && pos.y() <= max_y) {
		this->move(pos);
	}
	
	return;
}

void SInSpeechRemovableWidget::mousePressEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton) {
		this->is_pressed = true;
		this->start_pos = QPoint(event->pos().x(), event->pos().y());
	}

	return;
}

void SInSpeechRemovableWidget::mouseReleaseEvent(QMouseEvent *event) {
	this->is_pressed = false;

	return;
}

void SInSpeechRemovableWidget::updatePos() {
	int max_x = this->parentWidget()->width() - this->width(),
		max_y = this->parentWidget()->height() - this->height(),
		x = this->pos().x(),
		y = this->pos().y();

	if (this->pos().x() < 0) {
		x = 0;
	}
	if (this->pos().y() < 0) {
		y = 0;
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