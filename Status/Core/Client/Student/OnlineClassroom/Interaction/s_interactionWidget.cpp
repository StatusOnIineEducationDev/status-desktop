#include "s_interactionWidget.h"

StudentInteractionWidget::StudentInteractionWidget(QWidget *parent)
	: InteractionWidget(parent) {
	Ui::ChatAndInSpeechWidget ui = this->m_chat_and_in_speech_widget->ui();

	// ——学生端没有这些操作（禁言、移除发言中成员）
	ui.chat_ban_btn->hide(); 
	ui.remove_btn->hide();
	
}
StudentInteractionWidget::~StudentInteractionWidget() {

}