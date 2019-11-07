#include "sonlineclassroomchatcontroller.h"


SOnlineClassroomChatController::SOnlineClassroomChatController(SOnlineClassroomWidget *online_classroom_widget, QObject *parent)
	: QObject(parent), m_online_classroom_widget(online_classroom_widget) {
	Ui::SOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();

	this->connect(ui.flexible_frame_btn, &QPushButton::clicked, this, &SOnlineClassroomChatController::showFlexibleFrame);
	this->connect(ui.send_btn, &QPushButton::clicked, this, &SOnlineClassroomChatController::sendChatContent);
	this->connect(ui.chat_clear_btn, &QPushButton::clicked, this, &SOnlineClassroomChatController::chatClear);
}

SOnlineClassroomChatController::~SOnlineClassroomChatController() {

}

void SOnlineClassroomChatController::handleCommandSendChatContent(QJsonObject &data) {
	Ui::SOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();
	QListWidgetItem *chat_item = new QListWidgetItem;
	CChatItemMineWidget *chat_item_widget = new CChatItemMineWidget(ui.chat_view);
	QTextBrowser *chat_textBrowser = chat_item_widget->ui().chat_textBrowser;
	int text_width, text_height, chat_textBrowser_width, row_count,
		old_chat_textBrowser_height, new_chat_textBrowser_height;
	Toast *toast;
	QFont font;
	QFontMetrics fm(font);  // 计算字体的高度和宽度（px）
	QRect rect = fm.boundingRect(data["text"].toString());

	switch (ChatStatus(data["chat_status"].toInt())) {
	case ChatStatus::ChatFree:
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

		// ——计算文本行数
		// 通过获取text_edit中的文本长度与textBrowser的宽度
		// 相除向上取整获得行数
		text_width = rect.width();
		chat_textBrowser_width = 174;
		row_count = ceil((double)text_width / (double)chat_textBrowser_width);

		// ——计算textBrowser高度
		// 同时调整widget的高度
		// 这里需要记录原本textBrowser的高度与新的高度
		// 以便计算增量，改变widget高度
		text_height = chat_textBrowser->fontMetrics().lineSpacing();
		old_chat_textBrowser_height = chat_textBrowser->height();
		chat_textBrowser->setFixedHeight(text_height * row_count);
		new_chat_textBrowser_height = chat_textBrowser->height();
		chat_item_widget->setFixedHeight(chat_item_widget->height() + (new_chat_textBrowser_height - old_chat_textBrowser_height));

		chat_item->setSizeHint(QSize(chat_item_widget->width(), chat_item_widget->height()));
		ui.chat_view->addItem(chat_item);
		ui.chat_view->setItemWidget(chat_item, chat_item_widget);
		break;
	case ChatStatus::ChatBaned:
		toast = new Toast("当前处于禁言状态中");
		toast->show();
		this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);
	}

	return;
}

void SOnlineClassroomChatController::handleCommandRecvChatContent(QJsonObject &data) {
	Ui::SOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();
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

	// ——计算文本行数
	// 通过获取text_edit中的文本长度与textBrowser的宽度
	// 相除向上取整获得行数
	QFont font = chat_textBrowser->font();  // 获取文本框字体
	QFontMetrics fm(font);  // 计算字体的高度和宽度（px）
	QRect rect = fm.boundingRect(data["text"].toString());

	text_width = rect.width();
	chat_textBrowser_width = 174;
	row_count = ceil((double)text_width / (double)chat_textBrowser_width);

	// ——计算textBrowser高度
	// 同时调整widget的高度
	// 这里需要记录原本textBrowser的高度与新的高度
	// 以便计算增量，改变widget高度
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

void SOnlineClassroomChatController::handleCommandChatBan(QJsonObject &data) {
	Ui::SOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();

	switch (ChatStatus(data["chat_status"].toInt())) {
	case ChatStatus::ChatFree:
		ui.tips_text->setText("");
		break;
	case ChatStatus::ChatBaned:
		ui.tips_text->setText("全员禁言中");
		break;
	}

	return;
}

void SOnlineClassroomChatController::showFlexibleFrame() {
	Ui::SOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();

	ui.flexible_main_area->show();
	this->disconnect(ui.flexible_frame_btn, &QPushButton::clicked, this, &SOnlineClassroomChatController::showFlexibleFrame);
	this->connect(ui.flexible_frame_btn, &QPushButton::clicked, this, &SOnlineClassroomChatController::hideFlexibleFrame);

	return;
}

void SOnlineClassroomChatController::hideFlexibleFrame() {
	Ui::SOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();

	ui.flexible_main_area->hide();
	this->disconnect(ui.flexible_frame_btn, &QPushButton::clicked, this, &SOnlineClassroomChatController::hideFlexibleFrame);
	this->connect(ui.flexible_frame_btn, &QPushButton::clicked, this, &SOnlineClassroomChatController::showFlexibleFrame);

	return;
}

void SOnlineClassroomChatController::sendChatContent() {
	Ui::SOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();
	QJsonObject request_json_obj;
	Toast *toast;

	if (ui.chat_text_edit->text() == "") {
		toast = new Toast("不能发送空白消息");
		toast->show();
		this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);
	}
	else {
		// ——请求数据
		request_json_obj["command"] = TransportCmd::SendChatContent;
		request_json_obj["timestamp"] = (int)QDateTime::currentDateTime().toTime_t();
		request_json_obj["text"] = ui.chat_text_edit->text();
		emit this->lessonConnectionDataReady(request_json_obj);

		ui.chat_text_edit->clear();
	}

	return;
}

void SOnlineClassroomChatController::chatClear() {
	Ui::SOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();

	ui.chat_view->clear();

	return;
}
