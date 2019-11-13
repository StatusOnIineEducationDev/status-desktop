#include "t_courseManagementWidget.h"

TCourseManagementWidget::TCourseManagementWidget(TMainWindow *parent) : QWidget(parent) {
	m_ui.setupUi(this);

	m_ui.courses_comboBox->setView(new QListView());  // ���Ӧ�����й�comboBox����ʽ

	this->connect(parent, &TMainWindow::windowResized, this, &TCourseManagementWidget::handleWindowResized);
}

TCourseManagementWidget::~TCourseManagementWidget() {

}