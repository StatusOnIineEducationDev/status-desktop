#include "chatItemWidget.h"


template <typename Widget>
ChatItemWidget<Widget>::ChatItemWidget(const QPixmap &user_pic, const QString &username,
	const QString &content, const int &timestamp, QWidget *parent)
	: QWidget(parent) {
	m_ui.setupUi(this);

	this->m_ui.user_pic->setPixmap(user_pic);
	this->m_ui.username_text->setText(username);
	this->m_ui.chat_textBrowser->setText(content);
	this->m_ui.time_text->setText(
		QDateTime::fromTime_t(data["timestamp"].toInt()).toString("hh:mm:ss"));

	this->resizeItemWidget(content);
}

template <typename Widget>
ChatItemWidget<Widget>::~ChatItemWidget() {

}

template <typename Widget>
void ChatItemWidget<Widget>::resizeItemWidget(const QString &content) {
	int text_width, text_height, chat_textBrowser_width, row_count,
		old_chat_textBrowser_height, new_chat_textBrowser_height;
	// ——计算文本行数
	// 通过获取text_edit中的文本长度与textBrowser的宽度
	// 相除向上取整获得行数
	QFont font = chat_textBrowser->font();  // 获取文本框字体
	QFontMetrics fm(font);  // 计算字体的高度和宽度（px）
	QRect rect = fm.boundingRect(content);

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

	return;
}