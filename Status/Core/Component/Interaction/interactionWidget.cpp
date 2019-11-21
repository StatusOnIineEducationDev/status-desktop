#include "interactionWidget.h"


InteractionWidget::InteractionWidget(QWidget *parent)
	: QWidget(parent), m_white_board_widget(nullptr),
	m_chat_and_in_speech_widget(nullptr) {
	m_ui.setupUi(this);

	this->m_white_board_widget = new WhiteBoardWidget(this);
	this->m_ui.white_board_widget_layout->addWidget(this->m_white_board_widget);
	this->m_chat_and_in_speech_widget = new ChatAndInSpeechWidget(this);
	this->m_ui.chat_and_in_speech_layout->addWidget(this->m_chat_and_in_speech_widget);

	this->connect(this->m_ui.flexible_frame_btn, &QPushButton::clicked, this, &InteractionWidget::showChatAndInSpeechWidget);
}

InteractionWidget::~InteractionWidget() {

}

void InteractionWidget::showChatAndInSpeechWidget() {
	if (this->m_chat_and_in_speech_widget == nullptr) {
		return;
	}

	this->m_chat_and_in_speech_widget->show();
	this->disconnect(this->m_ui.flexible_frame_btn, &QPushButton::clicked, this, &InteractionWidget::showChatAndInSpeechWidget);
	this->connect(this->m_ui.flexible_frame_btn, &QPushButton::clicked, this, &InteractionWidget::hideChatAndInSpeechWidget);

	return;
}

void InteractionWidget::hideChatAndInSpeechWidget() {
	if (this->m_chat_and_in_speech_widget == nullptr) {
		return;
	}

	this->m_chat_and_in_speech_widget->hide();
	this->disconnect(this->m_ui.flexible_frame_btn, &QPushButton::clicked, this, &InteractionWidget::hideChatAndInSpeechWidget);
	this->connect(this->m_ui.flexible_frame_btn, &QPushButton::clicked, this, &InteractionWidget::showChatAndInSpeechWidget);

	return;
}