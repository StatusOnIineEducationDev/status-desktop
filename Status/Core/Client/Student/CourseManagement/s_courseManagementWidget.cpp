#include "s_courseManagementWidget.h"

StudentCourseManagementWidget::StudentCourseManagementWidget(QWidget *parent)
	: CourseManagementWidget(parent) {
	this->loadFunctionButtonWidget();
	this->loadCourseResourceWidget();

}

StudentCourseManagementWidget::~StudentCourseManagementWidget() {

}

void StudentCourseManagementWidget::loadFunctionButtonWidget() {
	// ——加载功能条
	this->m_function_button_widget = new StudentCourseManagementFunctionButtonWidget(this);
	this->m_ui.function_btn_widget_layout->
		addWidget(this->m_function_button_widget);

	// ——信号连接

	return;
}

void StudentCourseManagementWidget::loadCourseResourceWidget() {
	// ——加载课程资源页
	this->m_course_resource_widget = new StudentCourseResourceWidget(this);
	this->m_ui.function_tabWidget->addTab(this->m_course_resource_widget, "课程资源");

	// 显式刷新
	this->m_course_resource_widget->
		updateAllData(user->getCourseList().at(0).courseId());

	// ——信号绑定
	this->connect(this->courseBasicWidget(), &CourseBasicWidget::courseSwitched,
		this->m_course_resource_widget, &StudentCourseResourceWidget::updateAllData);

	return;
}