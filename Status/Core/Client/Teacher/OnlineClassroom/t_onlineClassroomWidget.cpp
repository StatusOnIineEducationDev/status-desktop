#include "t_onlineClassroomWidget.h"


TOnlineClassroomWidget::TOnlineClassroomWidget(TMainWindow *parent): QWidget(parent) {
	m_ui.setupUi(this);
	m_ui.function_tabWidget->setAttribute(Qt::WA_StyledBackground);  // tabÀ¸ÏÔÊ¾±³¾°É«
	this->connect(parent, &TMainWindow::windowResized, this, &TOnlineClassroomWidget::handleWindowResized);
}

TOnlineClassroomWidget::~TOnlineClassroomWidget() {

}




THandleRaiseHandWidget::THandleRaiseHandWidget(TOnlineClassroomWidget *parent)
	: QWidget(parent), m_parent(parent) {
	m_ui.setupUi(this);

	this->connect(parent, &TOnlineClassroomWidget::windowResized, this, &THandleRaiseHandWidget::updataPos);
}

THandleRaiseHandWidget::~THandleRaiseHandWidget() {

}

void THandleRaiseHandWidget::updataPos() {
	Ui::TOnlineClassroomWidget ui = this->m_parent->ui();
	int btn_width = ui.raise_hand_btn->width(),
		btn_height = ui.raise_hand_btn->height(),
		btn_x = ui.raise_hand_btn->x(),
		btn_y = ui.raise_hand_btn->y(),

		x = btn_x - this->width() + btn_width,
		y = btn_y + btn_height;

	this->setGeometry(x, y, this->width(), this->height());

	return;
}