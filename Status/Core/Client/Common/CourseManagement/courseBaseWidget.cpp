#include "courseBaseWidget.h"


CourseBaseWidget::CourseBaseWidget(QWidget *parent)
	: QWidget(parent) {
	m_ui.setupUi(this);
	m_ui.courses_comboBox->setView(new QListView(this));  // 这个应该是有关comboBox的样式

	this->updateCourseComboBox();
}

CourseBaseWidget::~CourseBaseWidget() {

}

void CourseBaseWidget::updateCourseComboBox() {
	for (int index = 0; index < User::G_COURSES_BASE_LIST->count(); index++) {
		this->m_ui.courses_comboBox->
			addItem(User::G_COURSES_BASE_LIST->at(index).courseName());
	}

	return;
}
