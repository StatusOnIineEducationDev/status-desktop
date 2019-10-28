#include "teacher_main_window.h"
#include <QDesktopWidget>
#include <QApplication>

TeacherMainWindow::TeacherMainWindow(QWidget *parent): QMainWindow(parent) {
	m_ui.setupUi(this);

	// 初始化
	this->is_pressed = false;
	this->is_moving = false;
	this->is_resizing = false;

	// 窗口属性设置
	this->setWindowFlag(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground, true);

	// 信号绑定
	this->connect(this->m_ui.full_or_normal_btn, &QPushButton::clicked, this, &TeacherMainWindow::setWindowFull);
}


/*
	最大化窗口
*/
void TeacherMainWindow::setWindowFull() {
	QRect window = QApplication::desktop()->availableGeometry();
	this->setGeometry(-5, -5, window.width() + 10, window.height() + 10);

	// 更换槽函数
	this->disconnect(this->m_ui.full_or_normal_btn, &QPushButton::clicked, this, &TeacherMainWindow::setWindowFull);
	this->connect(this->m_ui.full_or_normal_btn, &QPushButton::clicked, this, &TeacherMainWindow::setWindowNormal);

	// 设置tooltip
	this->m_ui.full_or_normal_btn->setToolTip(QString::fromLocal8Bit("向下还原"));

	return;
}


/*
	还原窗口
*/
void TeacherMainWindow::setWindowNormal() {
	QRect window = QApplication::desktop()->availableGeometry();
	QPoint central_point = QPoint(window.width() / 2, window.height() / 2);

	// 在屏幕中心显示向下还原的窗口
	this->setGeometry(central_point.x() - (this->baseSize().width() / 2), central_point.y() - (this->baseSize().height() / 2), this->baseSize().width(), this->baseSize().height());

	// 更换槽函数
	this->disconnect(this->m_ui.full_or_normal_btn, &QPushButton::clicked, this, &TeacherMainWindow::setWindowNormal);
	this->connect(this->m_ui.full_or_normal_btn, &QPushButton::clicked, this, &TeacherMainWindow::setWindowFull);

	// 设置tooltip
	this->m_ui.full_or_normal_btn->setToolTip(QString::fromLocal8Bit("最大化"));

	return;
}

/*
	重写鼠标事件
	用于窗口拖动、缩放
*/
void TeacherMainWindow::mouseMoveEvent(QMouseEvent *event) {
	// 计算鼠标当前位置
	// 如果鼠标在title bar且左键按下，则执行移动
	if (this->is_moving) {
		this->move(this->pos() + event->pos() - this->start_pos);
	}
	else if (this->is_resizing) {
		// 窗体缩放
		this->resize(QSize(event->pos().x(), event->pos().y()));
	}

	return;
}

void TeacherMainWindow::mousePressEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton) {
		this->is_pressed = true;
		this->start_pos = QPoint(event->pos().x(), event->pos().y());
		if (this->start_pos.x() < this->width() && this->start_pos.y() < 40) {
			this->is_moving = true;
		}
		else if (this->start_pos.x() > this->width() - 20 && this->start_pos.y() > this->height() - 20) {
			this->is_resizing = true;
		}
	}

	return;
}

void TeacherMainWindow::mouseReleaseEvent(QMouseEvent *event) {
	this->is_pressed = false;
	this->is_moving = false;
	this->is_resizing = false;

	return;
}

void TeacherMainWindow::mouseDoubleClickEvent(QMouseEvent *event) {
	if (this->start_pos.x() < this->width() && this->start_pos.y() < 40) {
		// 窗口已经最大化
		if (m_ui.full_or_normal_btn->isChecked()) {
			m_ui.full_or_normal_btn->setChecked(false);
			this->setWindowNormal();
		}
		// 未最大化
		else {
			m_ui.full_or_normal_btn->setChecked(true);
			this->setWindowFull();
		}
	}
}