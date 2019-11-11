#include "s_courseManagementWidget.h"

SCourseManagementWidget::SCourseManagementWidget(SMainWindow *parent) : QWidget(parent) {
	m_ui.setupUi(this);

	m_ui.courses_comboBox->setView(new QListView());  // 这个应该是有关comboBox的样式

	this->connect(parent, &SMainWindow::windowResized, this, &SCourseManagementWidget::handleWindowResized);
}

SCourseManagementWidget::~SCourseManagementWidget() {

}