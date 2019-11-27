#include "t_onlineClassroomFunctionButtonWidget.h"


TeacherOnlineClassroomFunctionButtonWidget::TeacherOnlineClassroomFunctionButtonWidget
(QWidget *parent) : QWidget(parent) {
	m_ui.setupUi(this);

}

TeacherOnlineClassroomFunctionButtonWidget::~TeacherOnlineClassroomFunctionButtonWidget() {

}

void TeacherOnlineClassroomFunctionButtonWidget::updateRaiseHandButton(int count) {
	// ——更新按钮信息
	if (count > 0) {
		this->m_ui.raise_hand_btn->
			setIcon(QIcon(":/button/Resources/material/button/raise_hand_new.png"));
		this->m_ui.raise_hand_btn->
			setText("举手(" + QString::number(count) + ")");
	}
	else {
		this->m_ui.raise_hand_btn->
			setIcon(QIcon(":/button/Resources/material/button/raise_hand.png"));
		this->m_ui.raise_hand_btn->
			setText("举手");
	}

	return;
}