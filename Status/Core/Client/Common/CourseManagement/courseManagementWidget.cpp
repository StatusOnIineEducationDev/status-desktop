#include "courseManagementWidget.h"


CourseManagementWidget::CourseManagementWidget(QWidget *parent)
	: QWidget(parent) {
	m_ui.setupUi(this);
	this->m_ui.function_tabWidget->setAttribute(Qt::WA_StyledBackground);  // tabÀ¸ÏÔÊ¾±³¾°É«

	this->loadCourseBasicWidget();
}

CourseManagementWidget::~CourseManagementWidget() {

}

void CourseManagementWidget::loadCourseBasicWidget() {
	this->m_course_basic_widget = new CourseBasicWidget(this);
	this->m_ui.course_base_widget_layout->addWidget(this->m_course_basic_widget);

	return;
}
