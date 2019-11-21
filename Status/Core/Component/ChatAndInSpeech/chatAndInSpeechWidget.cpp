#include "chatAndInSpeechWidget.h"


ChatAndInSpeechWidget::ChatAndInSpeechWidget(QWidget *parent = nullptr)
	: QWidget(parent) {
	m_ui.setupUi(this);

	this->connect(this->m_ui.send_btn, &QPushButton::clicked, this, &ChatAndInSpeechWidget::sendChatContent);
	this->connect(this->m_ui.chat_ban_btn, &QPushButton::clicked, this, &ChatAndInSpeechWidget::chatBan);
	this->connect(this->m_ui.chat_clear_btn, &QPushButton::clicked, this, &ChatAndInSpeechWidget::chatClear);
}

ChatAndInSpeechWidget::~ChatAndInSpeechWidget() {

}

void ChatAndInSpeechWidget::addMemberToSpeechWidget(const QPixmap &user_pic,
	const QString &username) {
	QListWidgetItem *item = new QListWidgetItem;
	InSpeechMemberItemWidget *item_widget = new InSpeechMemberItemWidget(user_pic, 
		username, this->m_ui.in_speech_member_view);

	this->m_ui.in_speech_member_view->addItem(item);
	this->m_ui.in_speech_member_view->setItemWidget(item, item_widget);

	return;
}

void ChatAndInSpeechWidget::removeMemberFromSpeechWidget(const int row) {
	if (row == -1) {
		return;
	}

	this->m_ui.in_speech_member_view->takeItem(row);
	
	return;
}

void ChatAndInSpeechWidget::addOtherContentToChatWiget(const QPixmap &user_pic,
	const QString &username, const QString &content, const int &timestamp) {
	QListWidgetItem *chat_item = new QListWidgetItem;
	ChatItemWidget<Ui::ChatItemOtherWidget> *chat_item_widget =
		new ChatItemWidget<Ui::ChatItemOtherWidget>(user_pic, username,content, 
			timestamp, this->m_ui.chat_view);

	chat_item->setSizeHint(QSize(chat_item_widget->width(), chat_item_widget->height()));
	this->m_ui.chat_view->addItem(chat_item);
	this->m_ui.chat_view->setItemWidget(chat_item, chat_item_widget);

	return;
}

void ChatAndInSpeechWidget::addMyContentToChatWiget(const QPixmap &user_pic,
	const QString &username, const QString &content, const int &timestamp) {
	QListWidgetItem *chat_item = new QListWidgetItem;
	ChatItemWidget<Ui::ChatItemMineWidget> *chat_item_widget =
		new ChatItemWidget<Ui::ChatItemMineWidget>(user_pic, username, content,
			timestamp, this->m_ui.chat_view);

	chat_item->setSizeHint(QSize(chat_item_widget->width(), chat_item_widget->height()));
	this->m_ui.chat_view->addItem(chat_item);
	this->m_ui.chat_view->setItemWidget(chat_item, chat_item_widget);

	return;
}

void ChatAndInSpeechWidget::chatBan() {
	if (this->m_ui.chat_ban_btn->isChecked()) {
		emit this->chatBanned();
		this->m_ui.tips_text->setText("全员禁言中");
	}
	else {
		emit this->chatAllowed();
		this->m_ui.tips_text->setText("");
	}

	return;
}

void ChatAndInSpeechWidget::chatClear() {
	m_ui.chat_view->clear();

	return;
}

void ChatAndInSpeechWidget::sendChatContent() {
	if (this->m_ui.chat_text_edit->text() == "") {
		this->handleChatError(ChatError::BlankContentError);
	}
	else {
		emit this->chatSend(this->m_ui.chat_text_edit->text());
		this->m_ui.chat_text_edit->clear();
	}

	return;
}

void ChatAndInSpeechWidget::handleChatError(ChatError chat_error) {
	Toast *toast;

	switch (chat_error) {
	case ChatError::BlankContentError:
		toast = new Toast("不能发送空白消息");
		toast->show();
		this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);
		break;
	}
}