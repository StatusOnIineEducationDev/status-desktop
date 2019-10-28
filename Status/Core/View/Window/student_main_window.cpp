#include "Core/View/Window/student_main_window.h"
#include <QApplication>
#include <QDesktopWidget>

StudentMainWindow::StudentMainWindow(QWidget *parent)
	: QMainWindow(parent) {
	m_ui.setupUi(this);

	// ��ʼ��
	this->is_pressed = false;
	this->is_moving = false;
	this->is_resizing = false;

	// ������������
	this->setWindowFlag(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground, true);

	// �źŰ�
	this->connect(this->m_ui.full_or_normal_btn, &QPushButton::clicked, this, &StudentMainWindow::setWindowFull);
}

StudentMainWindow::~StudentMainWindow() {

}

/*
	��󻯴���
*/
void StudentMainWindow::setWindowFull() {
	QRect window = QApplication::desktop()->availableGeometry();
	this->setGeometry(-5, -5, window.width() + 10, window.height() + 10);

	// �����ۺ���
	this->disconnect(this->m_ui.full_or_normal_btn, &QPushButton::clicked, this, &StudentMainWindow::setWindowFull);
	this->connect(this->m_ui.full_or_normal_btn, &QPushButton::clicked, this, &StudentMainWindow::setWindowNormal);

	// ����tooltip
	this->m_ui.full_or_normal_btn->setToolTip(QString::fromLocal8Bit("���»�ԭ"));

	return;
}

/*
	��ԭ����
*/
void StudentMainWindow::setWindowNormal() {
	QRect window = QApplication::desktop()->availableGeometry();
	QPoint central_point = QPoint(window.width() / 2, window.height() / 2);

	// ����Ļ������ʾ���»�ԭ�Ĵ���
	this->setGeometry(central_point.x() - (this->baseSize().width() / 2), central_point.y() - (this->baseSize().height() / 2), this->baseSize().width(), this->baseSize().height());

	// �����ۺ���
	this->disconnect(this->m_ui.full_or_normal_btn, &QPushButton::clicked, this, &StudentMainWindow::setWindowNormal);
	this->connect(this->m_ui.full_or_normal_btn, &QPushButton::clicked, this, &StudentMainWindow::setWindowFull);

	// ����tooltip
	this->m_ui.full_or_normal_btn->setToolTip(QString::fromLocal8Bit("���"));

	return;
}

/*
	��д����¼�
	���ڴ����϶�������
*/
void StudentMainWindow::mouseMoveEvent(QMouseEvent *event) {
	// ������굱ǰλ��
	// ��������title bar��������£���ִ���ƶ�
	if (this->is_moving) {
		this->move(this->pos() + event->pos() - this->start_pos);
	}
	else if (this->is_resizing) {
		// ��������
		this->resize(QSize(event->pos().x(), event->pos().y()));
	}

	return;
}

void StudentMainWindow::mousePressEvent(QMouseEvent *event) {
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

void StudentMainWindow::mouseReleaseEvent(QMouseEvent *event) {
	this->is_pressed = false;
	this->is_moving = false;
	this->is_resizing = false;

	return;
}

void StudentMainWindow::mouseDoubleClickEvent(QMouseEvent *event) {
	if (this->start_pos.x() < this->width() && this->start_pos.y() < 40) {
		// �����Ѿ����
		if (m_ui.full_or_normal_btn->isChecked()) {
			m_ui.full_or_normal_btn->setChecked(false);
			this->setWindowNormal();
		}
		// δ���
		else {
			m_ui.full_or_normal_btn->setChecked(true);
			this->setWindowFull();
		}
	}
}