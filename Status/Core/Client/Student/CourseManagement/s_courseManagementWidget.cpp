#include "s_courseManagementWidget.h"

StudentCourseManagementWidget::StudentCourseManagementWidget(QWidget *parent)
	: CourseManagementWidget(parent) {
	this->loadFunctionButtonWidget();
}

StudentCourseManagementWidget::~StudentCourseManagementWidget() {

}

void StudentCourseManagementWidget::loadFunctionButtonWidget() {
	// �������ع�����
	this->m_function_button_widget = new StudentCourseManagementFunctionButtonWidget(this);
	this->m_ui.function_btn_widget_layout->
		addWidget(this->m_function_button_widget);

	// �����ź�����

	return;
}