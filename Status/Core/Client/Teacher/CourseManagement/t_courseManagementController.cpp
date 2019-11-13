#include "t_courseManagementController.h"


TCourseManagementController::TCourseManagementController(User *user, QObject *parent)
	:QObject(parent), m_user(user) {
		
}

TCourseManagementController::~TCourseManagementController() {
	delete this->m_course_management_widget;
}

void TCourseManagementController::showCourseManagementWidget(TMainWindow *parent) {
	this->initCourseManagementWidget(parent);

	// ——显示
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

	// ——创建online_classroom_widget
	this->m_course_management_widget = new TCourseManagementWidget(parent);
	//this->initAffiliatedWidget();
	ui = this->m_course_management_widget->ui();

	// ——初始化数据
	this->updateCourseComboBox();

	// ——信号绑定
	this->connect(parent, &TMainWindow::windowResized, this->m_course_management_widget, &TCourseManagementWidget::handleWindowResized);
	
	// ——其他设置

	return;
}

void TCourseManagementController::updateCourseComboBox() {
	Ui::TCourseManagementWidget ui = this->m_course_management_widget->ui();

	for (int index = 0; index < this->m_user->coursesBaseList()->count(); index++) {
		ui.courses_comboBox->addItem(this->m_user->coursesBaseList()->at(index).courseName());
	}

	return;
}