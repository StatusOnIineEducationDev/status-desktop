#include "courseManagementWidget.h"


CourseManagementWidget::CourseManagementWidget(QWidget *parent)
	: QWidget(parent) {
	m_ui.setupUi(this);
	this->m_ui.function_tabWidget->setAttribute(Qt::WA_StyledBackground);  // tab栏显示背景色

	this->loadCourseBaseWidget();
}

CourseManagementWidget::~CourseManagementWidget() {

}

void CourseManagementWidget::loadCourseBaseWidget() {
	this->m_course_base_widget = new CourseBaseWidget(this);
	this->m_ui.course_base_widget_layout->addWidget(this->m_course_base_widget);

	// ——信号连接
	QComboBox *comboBox = this->m_course_base_widget->ui().courses_comboBox;
	this->connect(comboBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this, &CourseManagementWidget::emitSignalCourseSwitched);

	return;
}

void CourseManagementWidget::emitSignalCourseSwitched(const int index) {
	QString course_id = User::G_COURSES_BASE_LIST->at(index).courseId();

	emit this->courseSwitched(course_id);

	return;
}