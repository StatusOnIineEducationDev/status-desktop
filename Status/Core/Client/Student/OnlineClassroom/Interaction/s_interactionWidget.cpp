#include "s_interactionWidget.h"

StudentInteractionWidget::StudentInteractionWidget(QWidget *parent)
	: InteractionWidget(parent) {
	Ui::ChatAndInSpeechWidget ui = this->m_chat_and_in_speech_widget->ui();

	// ����ѧ����û����Щ���������ԡ��Ƴ������г�Ա��
	ui.chat_ban_btn->hide(); 
	ui.remove_btn->hide();
	
}
StudentInteractionWidget::~StudentInteractionWidget() {

}