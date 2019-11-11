#include "s_courseManagementController.h"


SCourseManagementController::SCourseManagementController(User *user, QObject *parent)
	:QObject(parent), m_user(user) {
		
}

SCourseManagementController::~SCourseManagementController() {
	delete this->m_course_management_widget;
}

void SCourseManagementController::showCourseManagementWidget(SMainWindow *parent) {
	this->initCourseManagementWidget(parent);

	// ������ʾ
	parent->ui().widget_layout->addWidget(this->m_course_management_widget);
	this->m_course_management_widget->show();

	return;
}

void SCourseManagementController::hideCourseManagementWidget(SMainWindow *parent) {
	parent->ui().widget_layout->removeWidget(this->m_course_management_widget);
	this->m_course_management_widget->hide();

	return;
}


void SCourseManagementController::initCourseManagementWidget(SMainWindow *parent) {
	Ui::SCourseManagementWidget ui;

	// ��������online_classroom_widget
	this->m_course_management_widget = new SCourseManagementWidget(parent);
	//this->initAffiliatedWidget();
	ui = this->m_course_management_widget->ui();

	// ������ʼ������
	this->updateCourseComboBox();

	// �����źŰ�
	this->connect(parent, &SMainWindow::windowResized, this->m_course_management_widget, &SCourseManagementWidget::handleWindowResized);
	
	// ������������

	return;
}

void SCourseManagementController::updateCourseComboBox() {
	Ui::SCourseManagementWidget ui = this->m_course_management_widget->ui();

	for (int index = 0; index < this->m_user->coursesBaseList()->count(); index++) {
		ui.courses_comboBox->addItem(this->m_user->coursesBaseList()->at(index).courseName());
	}

	return;
}