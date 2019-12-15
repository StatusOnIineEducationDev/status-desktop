#include "s_courseManagementWidget.h"

StudentCourseManagementWidget::StudentCourseManagementWidget(QWidget *parent)
	: CourseManagementWidget(parent) {
	this->loadFunctionButtonWidget();
	this->loadCourseResourceWidget();

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

void StudentCourseManagementWidget::loadCourseResourceWidget() {
	// �������ؿγ���Դҳ
	this->m_course_resource_widget = new StudentCourseResourceWidget(this);
	this->m_ui.function_tabWidget->addTab(this->m_course_resource_widget, "�γ���Դ");

	// ��ʽˢ��
	this->m_course_resource_widget->
		updateAllData(user->getCourseList().at(0).courseId());

	// �����źŰ�
	this->connect(this->courseBasicWidget(), &CourseBasicWidget::courseSwitched,
		this->m_course_resource_widget, &StudentCourseResourceWidget::updateAllData);

	return;
}