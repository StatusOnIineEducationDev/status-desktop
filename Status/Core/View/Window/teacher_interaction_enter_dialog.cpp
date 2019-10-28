#include "teacher_interaction_enter_dialog.h"
#include <QMouseEvent>

TeacherInteractionEnterDialog::TeacherInteractionEnterDialog(QWidget *parent)
	: QDialog(parent) {
	m_ui.setupUi(this);
	// 窗口属性设置
	this->setWindowFlag(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground, true);

	// 信号绑定
}

TeacherInteractionEnterDialog::~TeacherInteractionEnterDialog() {

}

/*
	重写鼠标事件
	用于窗口拖动
*/
void TeacherInteractionEnterDialog::mouseMoveEvent(QMouseEvent *event) {
	// 计算鼠标当前位置
	// 如果鼠标在title bar且左键按下，则执行移动
	if (this->is_moving) {
		this->move(this->pos() + event->pos() - this->start_pos);
	}

	return;
}

void TeacherInteractionEnterDialog::mousePressEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton) {
		this->is_pressed = true;
		this->start_pos = QPoint(event->pos().x(), event->pos().y());
		if (this->start_pos.x() < this->width() && this->start_pos.y() < 35) {
			this->is_moving = true;
		}
	}

	return;
}

void TeacherInteractionEnterDialog::mouseReleaseEvent(QMouseEvent *event) {
	this->is_pressed = false;
	this->is_moving = false;

	return;
}