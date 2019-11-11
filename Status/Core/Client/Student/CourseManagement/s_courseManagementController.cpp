#include "s_courseManagementController.h"


SCourseManagementController::SCourseManagementController(User *user, QObject *parent)
	:QObject(parent), m_user(user) {
		
}

SCourseManagementController::~SCourseManagementController() {

}

void SCourseManagementController::showCourseManagementWidget(SMainWindow *parent) {
	this->initCourseManagementWidget(parent);

	// ������ʾ
	parent->ui().widget_layout->addWidget(this->m_course_management_widget);
	this->m_course_management_widget->show();

	return;
}

void SCourseManagementController::initCourseManagementWidget(SMainWindow *parent) {
	Ui::SCourseManagementWidget ui;

	// ��������online_classroom_widget
	this->m_course_management_widget = new SCourseManagementWidget(parent);
	//this->initAffiliatedWidget();
	ui = this->m_course_management_widget->ui();

	// �����źŰ�
	this->connect(parent, &SMainWindow::windowResized, this->m_course_management_widget, &SCourseManagementWidget::handleWindowResized);
	
	// ������������

	return;
}