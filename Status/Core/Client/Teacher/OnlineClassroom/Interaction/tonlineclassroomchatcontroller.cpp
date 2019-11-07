#include "tonlineclassroomchatcontroller.h"


TOnlineClassroomChatController::TOnlineClassroomChatController(TOnlineClassroomWidget *online_classroom_widget, QObject *parent)
	: QObject(parent), m_online_classroom_widget(online_classroom_widget) {
	Ui::TOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();

	this->connect(ui.flexible_frame_btn, &QPushButton::clicked, this, &TOnlineClassroomChatController::showFlexibleFrame);
	this->connect(ui.send_btn, &QPushButton::clicked, this, &TOnlineClassroomChatController::sendChatContent);
	this->connect(ui.chat_ban_btn, &QPushButton::clicked, this, &TOnlineClassroomChatController::chatBan);
	this->connect(ui.chat_clear_btn, &QPushButton::clicked, this, &TOnlineClassroomChatController::chatClear);
}

TOnlineClassroomChatController::~TOnlineClassroomChatController() {

}

void TOnlineClassroomChatController::handleCommandSendChatContent(QJsonObject &data) {
	Ui::TOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();
	QListWidgetItem *chat_item = new QListWidgetItem;
	CChatItemMineWidget *chat_item_widget = new CChatItemMineWidget(ui.chat_view);
	QTextBrowser *chat_textBrowser = chat_item_widget->ui().chat_textBrowser;
	int text_width, text_height, chat_textBrowser_width, row_count,
		old_chat_textBrowser_height, new_chat_textBrowser_height;

	chat_textBrowser->setText(data["text"].toString());
	chat_item_widget->ui().time_text->setText(QDateTime::fromTime_t(data["timestamp"].toInt()).toString("hh:mm:ss"));
	chat_item_widget->ui().username_text->setText(data["username"].toString());
	switch (AccountType(data["account_type"].toInt())) {
	case AccountType::Teacher:
		chat_item_widget->ui().user_pic->setPixmap(QPixmap(":/pic/Resources/material/pic/teacher.png"));
		break;
	case AccountType::Student:
		chat_item_widget->ui().user_pic->setPixmap(QPixmap(":/pic/Resources/material/pic/student.png"));
		break;
	}

	// ���������ı�����
	// ͨ����ȡtext_edit�е��ı�������textBrowser�Ŀ��
	// �������ȡ���������
	QFont font = chat_textBrowser->font();  // ��ȡ�ı�������
	QFontMetrics fm(font);  // ��������ĸ߶ȺͿ�ȣ�px��
	QRect rect = fm.boundingRect(data["text"].toString());

	text_width = rect.width();
	chat_textBrowser_width = 174;
	row_count = ceil((double)text_width / (double)chat_textBrowser_width);

	// ��������textBrowser�߶�
	// ͬʱ����widget�ĸ߶�
	// ������Ҫ��¼ԭ��textBrowser�ĸ߶����µĸ߶�
	// �Ա�����������ı�widget�߶�
	text_height = chat_textBrowser->fontMetrics().lineSpacing();
	old_chat_textBrowser_height = chat_textBrowser->height();
	chat_textBrowser->setFixedHeight(text_height * row_count);
	new_chat_textBrowser_height = chat_textBrowser->height();
	chat_item_widget->setFixedHeight(chat_item_widget->height() + (new_chat_textBrowser_height - old_chat_textBrowser_height));

	chat_item->setSizeHint(QSize(chat_item_widget->width(), chat_item_widget->height()));
	ui.chat_view->addItem(chat_item);
	ui.chat_view->setItemWidget(chat_item, chat_item_widget);

	return;
}

void TOnlineClassroomChatController::handleCommandRecvChatContent(QJsonObject &data) {
	Ui::TOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();
	QListWidgetItem *chat_item = new QListWidgetItem;
	CChatItemOtherWidget *chat_item_widget = new CChatItemOtherWidget(ui.chat_view);
	QTextBrowser *chat_textBrowser = chat_item_widget->ui().chat_textBrowser;
	int text_width, text_height, chat_textBrowser_width, row_count,
		old_chat_textBrowser_height, new_chat_textBrowser_height;

	chat_textBrowser->setText(data["text"].toString());
	chat_item_widget->ui().time_text->setText(QDateTime::fromTime_t(data["timestamp"].toInt()).toString("hh:mm:ss"));
	chat_item_widget->ui().username_text->setText(data["username"].toString());
	switch (AccountType(data["account_type"].toInt())) {
	case AccountType::Teacher:
		chat_item_widget->ui().user_pic->setPixmap(QPixmap(":/pic/Resources/material/pic/teacher.png"));
		break;
	case AccountType::Student:
		chat_item_widget->ui().user_pic->setPixmap(QPixmap(":/pic/Resources/material/pic/student.png"));
		break;
	}

	// ���������ı�����
	// ͨ����ȡtext_edit�е��ı�������textBrowser�Ŀ��
	// �������ȡ���������
	QFont font = chat_textBrowser->font();  // ��ȡ�ı�������
	QFontMetrics fm(font);  // ��������ĸ߶ȺͿ�ȣ�px��
	QRect rect = fm.boundingRect(data["text"].toString());

	text_width = rect.width();
	chat_textBrowser_width = 174;
	row_count = ceil((double)text_width / (double)chat_textBrowser_width);

	// ��������textBrowser�߶�
	// ͬʱ����widget�ĸ߶�
	// ������Ҫ��¼ԭ��textBrowser�ĸ߶����µĸ߶�
	// �Ա�����������ı�widget�߶�
	text_height = chat_textBrowser->fontMetrics().lineSpacing();
	old_chat_textBrowser_height = chat_textBrowser->height();
	chat_textBrowser->setFixedHeight(text_height * row_count);
	new_chat_textBrowser_height = chat_textBrowser->height();
	chat_item_widget->setFixedHeight(chat_item_widget->height() + (new_chat_textBrowser_height - old_chat_textBrowser_height));

	chat_item->setSizeHint(QSize(chat_item_widget->width(), chat_item_widget->height()));
	ui.chat_view->addItem(chat_item);
	ui.chat_view->setItemWidget(chat_item, chat_item_widget);

	return;
}

void TOnlineClassroomChatController::handleCommandChatBan(QJsonObject &data) {
	Ui::TOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();

	switch (ChatStatus(data["chat_status"].toInt())) {
	case ChatStatus::ChatFree:
		ui.tips_text->setText("");
		break;
	case ChatStatus::ChatBaned:
		ui.tips_text->setText("ȫԱ������");
		break;
	}

	return;
}

void TOnlineClassroomChatController::showFlexibleFrame() {
	Ui::TOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();

	ui.flexible_main_area->show();
	this->disconnect(ui.flexible_frame_btn, &QPushButton::clicked, this, &TOnlineClassroomChatController::showFlexibleFrame);
	this->connect(ui.flexible_frame_btn, &QPushButton::clicked, this, &TOnlineClassroomChatController::hideFlexibleFrame);

	return;
}

void TOnlineClassroomChatController::hideFlexibleFrame() {
	Ui::TOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();

	ui.flexible_main_area->hide();
	this->disconnect(ui.flexible_frame_btn, &QPushButton::clicked, this, &TOnlineClassroomChatController::hideFlexibleFrame);
	this->connect(ui.flexible_frame_btn, &QPushButton::clicked, this, &TOnlineClassroomChatController::showFlexibleFrame);

	return;
}

void TOnlineClassroomChatController::sendChatContent() {
	Ui::TOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();
	QJsonObject request_json_obj;
	Toast *toast;

	if (ui.chat_text_edit->text() == "") {
		toast = new Toast("���ܷ��Ϳհ���Ϣ");
		toast->show();
		this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);
	}
	else {
		// ������������
		request_json_obj["command"] = TransportCmd::SendChatContent;
		request_json_obj["timestamp"] = (int)QDateTime::currentDateTime().toTime_t();
		request_json_obj["text"] = ui.chat_text_edit->text();
		emit this->lessonConnectionDataReady(request_json_obj);

		ui.chat_text_edit->clear();
	}

	return;
}

void TOnlineClassroomChatController::chatBan() {
	Ui::TOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();
	QJsonObject request_json_obj;
	ChatStatus chat_status = ChatStatus::ChatFree;

	if (ui.chat_ban_btn->isChecked()) {
		chat_status = ChatStatus::ChatBaned;
	}

	// ������������
	request_json_obj["command"] = TransportCmd::ChatBan;
	request_json_obj["chat_status"] = chat_status;
	emit lessonConnectionDataReady(request_json_obj);


	return;
}

void TOnlineClassroomChatController::chatClear() {
	Ui::TOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();

	ui.chat_view->clear();

	return;
}
