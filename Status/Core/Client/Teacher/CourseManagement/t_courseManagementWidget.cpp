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
	// ——加载功能条
	this->m_function_button_widget = new TeacherCourseManagementFunctionButtonWidget(this);
	this->m_ui.function_btn_widget_layout->
		addWidget(this->m_function_button_widget);

	// ——信号连接

	return;
}

void TeacherCourseManagementWidget::loadCourseOverviewWidget() {
	// ——加载课程概况页
	this->m_course_overview_widget = new TeacherCourseOverviewWidget(this);
	this->m_ui.function_tabWidget->addTab(this->m_course_overview_widget, "课程概况");
	
	// 显式刷新
	this->m_course_overview_widget->
		updateAllData(User::G_COURSES_BASE_LIST->at(0).courseId());
	
	// ——信号绑定
	this->connect(this->courseBaseWidget(), &CourseBaseWidget::courseSwitched,
		this->m_course_overview_widget, &TeacherCourseOverviewWidget::updateAllData);

	return;
}

void TeacherCourseManagementWidget::loadCourseResourceWidget() {
	// ——加载课程资源页
	this->m_course_resource_widget = new TeacherCourseResourceWidget(this);
	this->m_ui.function_tabWidget->addTab(this->m_course_resource_widget, "课程资源");

	// ——信号绑定
	this->connect(this->courseBaseWidget(), &CourseBaseWidget::courseSwitched,
		this->m_course_resource_widget, &TeacherCourseResourceWidget::updateAllData);

	return;
}