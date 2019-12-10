#include "mainWindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	m_ui.setupUi(this);

	this->updateUserInfo();

	// ��ʼ��
	this->is_pressed = false;
	this->is_moving = false;
	this->is_resizing = false;

	// ������������
	this->setWindowFlag(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground, true);

	// �źŰ�
	this->connect(this->m_ui.full_or_normal_btn, &QPushButton::clicked, this, &MainWindow::setWindowFull);
}

void MainWindow::updateUserInfo() {
	this->m_ui.username_text->setText(user->getUsername());
	this->m_ui.user_pic->setPixmap(user->getUserPic());

	return;
}

void MainWindow::setWindowFull() {
	QRect window = QApplication::desktop()->availableGeometry();
	this->setGeometry(-5, -5, window.width() + 10, window.height() + 10);

	// �����ۺ���
	this->disconnect(this->m_ui.full_or_normal_btn, &QPushButton::clicked, this, &MainWindow::setWindowFull);
	this->connect(this->m_ui.full_or_normal_btn, &QPushButton::clicked, this, &MainWindow::setWindowNormal);

	// ����tooltip
	this->m_ui.full_or_normal_btn->setToolTip(QString::fromLocal8Bit("���»�ԭ"));

	emit this->windowResized();

	return;
}

void MainWindow::setWindowNormal() {
	QRect window = QApplication::desktop()->availableGeometry();
	QPoint central_point = QPoint(window.width() / 2, window.height() / 2);

	// ����Ļ������ʾ���»�ԭ�Ĵ���
	this->setGeometry(central_point.x() - (this->baseSize().width() / 2), central_point.y() - (this->baseSize().height() / 2), this->baseSize().width(), this->baseSize().height());

	// �����ۺ���
	this->disconnect(this->m_ui.full_or_normal_btn, &QPushButton::clicked, this, &MainWindow::setWindowNormal);
	this->connect(this->m_ui.full_or_normal_btn, &QPushButton::clicked, this, &MainWindow::setWindowFull);

	// ����tooltip
	this->m_ui.full_or_normal_btn->setToolTip(QString::fromLocal8Bit("���"));

	emit this->windowResized();

	return;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
	// ������굱ǰλ��
	// ��������title bar��������£���ִ���ƶ�
	if (this->is_moving) {
		this->move(this->pos() + event->pos() - this->start_pos);
	}
	else if (this->is_resizing) {
		// ��������
		this->resize(QSize(event->pos().x(), event->pos().y()));
		emit this->windowResized();
	}

	return;
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
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

void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
	this->is_pressed = false;
	this->is_moving = false;
	this->is_resizing = false;

	return;
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event) {
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