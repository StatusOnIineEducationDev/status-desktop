#include "chatAndInSpeechWidget.h"


ChatAndInSpeechWidget::ChatAndInSpeechWidget(QWidget *parent)
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
	ChatItemOtherWidget *chat_item_widget =
		new ChatItemOtherWidget(user_pic, username,content,
			timestamp, this->m_ui.chat_view);

	chat_item->setSizeHint(QSize(chat_item_widget->width(), chat_item_widget->height()));
	this->m_ui.chat_view->addItem(chat_item);
	this->m_ui.chat_view->setItemWidget(chat_item, chat_item_widget);

	return;
}

void ChatAndInSpeechWidget::addMyContentToChatWiget(const QPixmap &user_pic,
	const QString &username, const QString &content, const int &timestamp) {
	QListWidgetItem *chat_item = new QListWidgetItem;
	ChatItemMineWidget *chat_item_widget =
		new ChatItemMineWidget(user_pic, username, content,
			timestamp, this->m_ui.chat_view);

	chat_item->setSizeHint(QSize(chat_item_widget->width(), chat_item_widget->height()));
	this->m_ui.chat_view->addItem(chat_item);
	this->m_ui.chat_view->setItemWidget(chat_item, chat_item_widget);

	return;
}

void ChatAndInSpeechWidget::chatBan() {
	QJsonObject request_json_obj;
	ChatStatus chat_status = ChatStatus::ChatFree;

	if (this->m_ui.chat_ban_btn->isChecked()) {
		chat_status = ChatStatus::ChatBaned;
	}

	// ——请求数据
	request_json_obj["command"] = TransportCmd::ChatBan;
	request_json_obj["chat_status"] = chat_status;
	emit lessonConnectionDataReady(request_json_obj);

	return;
}

void ChatAndInSpeechWidget::chatClear() {
	m_ui.chat_view->clear();

	return;
}

void ChatAndInSpeechWidget::sendChatContent() {
	QJsonObject json_obj;

	if (this->m_ui.chat_text_edit->text() == "") {
		this->handleChatError(ChatError::BlankContentError);
	}
	else {
		json_obj["command"] = TransportCmd::SendChatContent;
		json_obj["chat_timestamp"] = (int)QDateTime::currentDateTime().toTime_t();
		json_obj["text"] = this->m_ui.chat_text_edit->text();
		emit this->lessonConnectionDataReady(json_obj);
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

void ChatAndInSpeechWidget::handleCommandSendChatContent(QJsonObject &data) {
	QPixmap user_pic = QPixmap(":/pic/Resources/material/pic/student.png");

	this->addMyContentToChatWiget(user_pic, data["username"].toString(), 
		data["text"].toString(), data["chat_timestamp"].toInt());

	return;
}

void ChatAndInSpeechWidget::handleCommandRecvChatContent(QJsonObject &data) {
	QPixmap user_pic;

	switch (AccountType(data["account_type"].toInt())) {
	case AccountType::Teacher:
		user_pic = QPixmap(":/pic/Resources/material/pic/teacher.png"); break;
	case AccountType::Student:
		user_pic = QPixmap(":/pic/Resources/material/pic/student.png");  break;

		this->addOtherContentToChatWiget(user_pic, data["username"].toString(),
			data["text"].toString(), data["chat_timestamp"].toInt());

		return;
	}
}

void ChatAndInSpeechWidget::handleCommandChatBan(QJsonObject &data) {
	switch (ChatStatus(data["chat_status"].toInt())) {
	case ChatStatus::ChatFree:
		this->m_ui.tips_text->setText("");
		break;
	case ChatStatus::ChatBaned:
		this->m_ui.tips_text->setText("全员禁言中");
		break;
	}

	return;
}