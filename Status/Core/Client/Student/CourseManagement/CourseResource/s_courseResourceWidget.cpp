#include "s_courseResourceWidget.h"

StudentCourseResourceWidget::StudentCourseResourceWidget(QWidget *parent)
	: CourseResourceWidget(parent) {
	// ����ѧ����û���ϴ���ɾ����Դ�Ĳ���
	this->m_ui.upload_btn->hide();
	this->m_ui.delete_btn->hide();

}
StudentCourseResourceWidget::~StudentCourseResourceWidget() {

}