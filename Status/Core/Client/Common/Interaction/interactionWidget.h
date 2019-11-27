#pragma once
#include <QWidget>
#include "ui_c_interactionWidget.h"
#include "WhiteBoard/whiteBoardWidget.h"
#include "ChatAndInSpeech/chatAndInSpeechWidget.h"


class InteractionWidget : public QWidget {
	Q_OBJECT

public:
	InteractionWidget(QWidget *parent = nullptr);
	virtual ~InteractionWidget();
	const Ui::InteractionWidget& ui() const { return this->m_ui; };
	WhiteBoardWidget* whiteBoardWidget() const { return this->m_white_board_widget; };
	ChatAndInSpeechWidget*chatAndInSpeechWidget() const 
	{ return this->m_chat_and_in_speech_widget; };

protected:
	void showChatAndInSpeechWidget();
	void hideChatAndInSpeechWidget();

	Ui::InteractionWidget m_ui;
	WhiteBoardWidget *m_white_board_widget;
	ChatAndInSpeechWidget *m_chat_and_in_speech_widget;
};
