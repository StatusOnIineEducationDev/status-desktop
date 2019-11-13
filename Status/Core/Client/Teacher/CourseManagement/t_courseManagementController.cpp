#include "t_courseManagementController.h"


TCourseManagementController::TCourseManagementController(User *user, QObject *parent)
	:QObject(parent), m_user(user) {
		
}

TCourseManagementController::~TCourseManagementController() {
	delete this->m_course_management_widget;
}

void TCourseManagementController::showCourseManagementWidget(TMainWindow *parent) {
	this->initCourseManagementWidget(parent);

	// ������ʾ
	parent->ui().widget_layout->addWidget(this->m_course_management_widget);
	this->m_course_management_widget->show();

	return;
}

void TCourseManagementController::hideCourseManagementWidget(TMainWindow *parent) {
	parent->ui().widget_layout->removeWidget(this->m_course_management_widget);
	this->m_course_management_widget->hide();

	return;
}

void TCourseManagementController::initCourseManagementWidget(TMainWindow *parent) {
	Ui::TCourseManagementWidget ui;

	// ��������online_classroom_widget
	this->m_course_management_widget = new TCourseManagementWidget(parent);
	//this->initAffiliatedWidget();
	ui = this->m_course_management_widget->ui();

	// ������ʼ������
	this->updateCourseComboBox();

	// �����źŰ�
	this->connect(parent, &TMainWindow::windowResized, this->m_course_management_widget, &TCourseManagementWidget::handleWindowResized);
	
	// ������������

	return;
}

void TCourseManagementController::updateCourseComboBox() {
	Ui::TCourseManagementWidget ui = this->m_course_management_widget->ui();

	for (int index = 0; index < this->m_user->coursesBaseList()->count(); index++) {
		ui.courses_comboBox->addItem(this->m_user->coursesBaseList()->at(index).courseName());
	}

	return;
}