#include "courseManagementWidget.h"


CourseManagementWidget::CourseManagementWidget(QWidget *parent)
	: QWidget(parent) {
	m_ui.setupUi(this);
	
	this->loadCourseBaseWidget();
}

CourseManagementWidget::~CourseManagementWidget() {

}

void CourseManagementWidget::loadCourseBaseWidget() {
	this->m_course_base_widget = new CourseBaseWidget(this);
	this->m_ui.course_base_widget_layout->addWidget(this->m_course_base_widget);

	return;
}