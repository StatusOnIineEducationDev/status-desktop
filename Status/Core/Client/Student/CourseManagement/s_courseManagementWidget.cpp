#include "s_courseManagementWidget.h"

SCourseManagementWidget::SCourseManagementWidget(SMainWindow *parent) : QWidget(parent) {
	m_ui.setupUi(this);
	this->connect(parent, &SMainWindow::windowResized, this, &SCourseManagementWidget::handleWindowResized);
}

SCourseManagementWidget::~SCourseManagementWidget() {

}