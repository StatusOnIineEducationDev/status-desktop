#include "t_courseManagementWidget.h"


TeacherCourseManagementWidget::TeacherCourseManagementWidget(QWidget *parent)
	: CourseManagementWidget(parent) {
	this->loadFunctionButtonWidget();
	this->loadCourseOverviewWidget();
	this->loadCourseResourceWidget();
}

TeacherCourseManagementWidget::~TeacherCourseManagementWidget() {

}

void TeacherCourseManagementWidget::loadFunctionButtonWidget() {
	// �������ع�����
	this->m_function_button_widget = new TeacherCourseManagementFunctionButtonWidget(this);
	this->m_ui.function_btn_widget_layout->
		addWidget(this->m_function_button_widget);

	// �����ź�����

	return;
}

void TeacherCourseManagementWidget::loadCourseOverviewWidget() {
	// �������ؿγ̸ſ�ҳ
	this->m_course_overview_widget = new TeacherCourseOverviewWidget(this);
	this->m_ui.function_tabWidget->addTab(this->m_course_overview_widget, "�γ̸ſ�");
	
	// ��ʽˢ��
	this->m_course_overview_widget->
		updateAllData(User::G_COURSES_BASE_LIST->at(0).courseId());
	
	// �����źŰ�
	this->connect(this->courseBaseWidget(), &CourseBaseWidget::courseSwitched,
		this->m_course_overview_widget, &TeacherCourseOverviewWidget::updateAllData);

	return;
}

void TeacherCourseManagementWidget::loadCourseResourceWidget() {
	// �������ؿγ���Դҳ
	this->m_course_resource_widget = new TeacherCourseResourceWidget(this);
	this->m_ui.function_tabWidget->addTab(this->m_course_resource_widget, "�γ���Դ");

	// �����źŰ�
	this->connect(this->courseBaseWidget(), &CourseBaseWidget::courseSwitched,
		this->m_course_resource_widget, &TeacherCourseResourceWidget::updateAllData);

	return;
}