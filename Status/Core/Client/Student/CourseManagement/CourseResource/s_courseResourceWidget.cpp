#include "s_courseResourceWidget.h"

StudentCourseResourceWidget::StudentCourseResourceWidget(QWidget *parent)
	: CourseResourceWidget(parent) {
	// ——学生端没有上传和删除资源的操作
	this->m_ui.upload_btn->hide();
	this->m_ui.delete_btn->hide();

}
StudentCourseResourceWidget::~StudentCourseResourceWidget() {

}