#include "teacher_main_window.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QChartView>

TeacherMainWindow::TeacherMainWindow(QWidget *parent): QMainWindow(parent) {
	ui.setupUi(this);

	// ��ʼ��
	this->is_pressed = false;
	this->is_moving = false;
	this->is_resizing = false;
	this->teacher_course_widget = nullptr;
	this->teacher_interaction_widget = nullptr;

	this->showTeacherCourseWidget();  // Ĭ����ҳ

	// ������������
	this->setWindowFlag(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground, true);

	// �źŰ�
	this->connect(this->ui.course_btn, &QPushButton::clicked, this, &TeacherMainWindow::showTeacherCourseWidget);
	this->connect(this->ui.interaction_btn, &QPushButton::clicked, this, &TeacherMainWindow::showTeacherInteractionWidget);
	this->connect(this->ui.full_or_normal_btn, &QPushButton::clicked, this, &TeacherMainWindow::setWindowFull);
}

TeacherMainWindow::~TeacherMainWindow() {
	if (this->teacher_course_widget != nullptr) {
		delete this->teacher_course_widget;
	}
	if (this->teacher_interaction_widget != nullptr) {
		delete this->teacher_interaction_widget;
	}
}

/*
	�л�����ʱ����
	�����ǰ���Ӵ�
*/
void TeacherMainWindow::clearWidget() {
	// �γ̹���
	if (this->teacher_course_widget != nullptr) {
		// �����غ�ɾ������������������ӡ
		this->teacher_course_widget->hide();
		this->ui.widget_layout->removeWidget(this->teacher_course_widget);
		delete this->teacher_course_widget;
		this->teacher_course_widget = nullptr;  // ��ʼ��ָ��
	}
	// ʵʱ����
	else if (this->teacher_interaction_widget != nullptr) {
		this->teacher_interaction_widget->hide();
	}

	return;
}

/*
	�л������γ̹����Ӵ�
*/
void TeacherMainWindow::showTeacherCourseWidget() {
	this->clearWidget();  // ����������е�ǰ��ʾ���Ӵ�
	this->teacher_course_widget = new TeacherCourseWidget();  // ��̬�����Ӵ�
	this->ui.widget_layout->addWidget(this->teacher_course_widget);  // ������layout��
	this->teacher_course_widget->show();  // ��ʾ

	return;
}


/*
	�л�����ʵʱ�������Ӵ�
*/
void TeacherMainWindow::showTeacherInteractionWidget() {
	this->clearWidget();  // ����������е�ǰ��ʾ���Ӵ�
	if (this->teacher_interaction_widget == nullptr) {
		this->teacher_interaction_widget = new TeacherInteractionWidget();  // ��̬�����Ӵ�
	}
	this->ui.widget_layout->addWidget(this->teacher_interaction_widget);  // ������layout��
	this->teacher_interaction_widget->show();  // ��ʾ

	return;
}


/*
	��󻯴���
*/
void TeacherMainWindow::setWindowFull() {
	QRect window = QApplication::desktop()->availableGeometry();
	this->setGeometry(-5, -5, window.width() + 10, window.height() + 10);

	// �����ۺ���
	this->disconnect(this->ui.full_or_normal_btn, &QPushButton::clicked, this, &TeacherMainWindow::setWindowFull);
	this->connect(this->ui.full_or_normal_btn, &QPushButton::clicked, this, &TeacherMainWindow::setWindowNormal);

	// ����tooltip
	this->ui.full_or_normal_btn->setToolTip(QString::fromLocal8Bit("���»�ԭ"));

	return;
}


/*
	��ԭ����
*/
void TeacherMainWindow::setWindowNormal() {
	QRect window = QApplication::desktop()->availableGeometry();
	QPoint central_point = QPoint(window.width() / 2, window.height() / 2);

	// ����Ļ������ʾ���»�ԭ�Ĵ���
	this->setGeometry(central_point.x() - (this->baseSize().width() / 2), central_point.y() - (this->baseSize().height() / 2), this->baseSize().width(), this->baseSize().height());

	// �����ۺ���
	this->disconnect(this->ui.full_or_normal_btn, &QPushButton::clicked, this, &TeacherMainWindow::setWindowNormal);
	this->connect(this->ui.full_or_normal_btn, &QPushButton::clicked, this, &TeacherMainWindow::setWindowFull);

	// ����tooltip
	this->ui.full_or_normal_btn->setToolTip(QString::fromLocal8Bit("���"));

	return;
}

/*
	��д����¼�
	���ڴ����϶�������
*/
void TeacherMainWindow::mouseMoveEvent(QMouseEvent *event) {
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
		// �����Ѿ����
		if (ui.full_or_normal_btn->isChecked()) {
			ui.full_or_normal_btn->setChecked(false);
			this->setWindowNormal();
		}
		// δ���
		else {
			ui.full_or_normal_btn->setChecked(true);
			this->setWindowFull();
		}
	}
}