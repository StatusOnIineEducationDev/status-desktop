#include "s_courseManagementController.h"


SCourseManagementController::SCourseManagementController(User *user, QObject *parent)
	:QObject(parent), m_user(user) {
		
}

SCourseManagementController::~SCourseManagementController() {
	delete this->m_course_management_widget;
}

void SCourseManagementController::showCourseManagementWidget(SMainWindow *parent) {
	this->initCourseManagementWidget(parent);

	// ——显示
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

	// ——创建online_classroom_widget
	this->m_course_management_widget = new SCourseManagementWidget(parent);
	//this->initAffiliatedWidget();
	ui = this->m_course_management_widget->ui();

	// ——初始化数据
	this->updateCourseComboBox();

	// ——信号绑定
	this->connect(parent, &SMainWindow::windowResized, this->m_course_management_widget, &SCourseManagementWidget::handleWindowResized);
	
	// ——其他设置

	return;
}

void SCourseManagementController::updateCourseComboBox() {
	Ui::SCourseManagementWidget ui = this->m_course_management_widget->ui();

	for (int index = 0; index < this->m_user->coursesBaseList()->count(); index++) {
		ui.courses_comboBox->addItem(this->m_user->coursesBaseList()->at(index).courseName());
	}

	return;
}