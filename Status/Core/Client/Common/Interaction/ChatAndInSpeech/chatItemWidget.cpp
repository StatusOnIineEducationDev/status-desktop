#include "chatItemWidget.h"


ChatItemOtherWidget::ChatItemOtherWidget(const QPixmap &user_pic, const QString &username,
	const QString &content, const int &timestamp, QWidget *parent)
	: QWidget(parent) {
	m_ui.setupUi(this);

	this->m_ui.user_pic->setPixmap(user_pic);
	this->m_ui.username_text->setText(username);
	this->m_ui.chat_textBrowser->setText(content);
	this->m_ui.time_text->setText(QDateTime::fromTime_t(timestamp).toString("hh:mm:ss"));

	this->resizeItemWidget(content);
}

ChatItemOtherWidget::~ChatItemOtherWidget() {

}

void ChatItemOtherWidget::resizeItemWidget(const QString &content) {
	int text_width, text_height, chat_textBrowser_width, row_count,
		old_chat_textBrowser_height, new_chat_textBrowser_height;
	// ���������ı�����
	// ͨ����ȡtext_edit�е��ı�������textBrowser�Ŀ��
	// �������ȡ���������
	QFont font = this->m_ui.chat_textBrowser->font();  // ��ȡ�ı�������
	QFontMetrics fm(font);  // ��������ĸ߶ȺͿ�ȣ�px��
	QRect rect = fm.boundingRect(content);

	text_width = rect.width();
	chat_textBrowser_width = 174;
	row_count = ceil((double)text_width / (double)chat_textBrowser_width);

	// ��������textBrowser�߶�
	// ͬʱ����widget�ĸ߶�
	// ������Ҫ��¼ԭ��textBrowser�ĸ߶����µĸ߶�
	// �Ա�����������ı�widget�߶�
	text_height = this->m_ui.chat_textBrowser->fontMetrics().lineSpacing();
	old_chat_textBrowser_height = this->m_ui.chat_textBrowser->height();
	this->m_ui.chat_textBrowser->setFixedHeight(text_height * row_count);
	new_chat_textBrowser_height = this->m_ui.chat_textBrowser->height();
	this->setFixedHeight(this->height() + 
		(new_chat_textBrowser_height - old_chat_textBrowser_height));

	return;
}


ChatItemMineWidget::ChatItemMineWidget(const QPixmap &user_pic, const QString &username,
	const QString &content, const int &timestamp, QWidget *parent)
	: QWidget(parent) {
	m_ui.setupUi(this);

	this->m_ui.user_pic->setPixmap(user_pic);
	this->m_ui.username_text->setText(username);
	this->m_ui.chat_textBrowser->setText(content);
	this->m_ui.time_text->setText(QDateTime::fromTime_t(timestamp).toString("hh:mm:ss"));

	this->resizeItemWidget(content);
}

ChatItemMineWidget::~ChatItemMineWidget() {

}

void ChatItemMineWidget::resizeItemWidget(const QString &content) {
	int text_width, text_height, chat_textBrowser_width, row_count,
		old_chat_textBrowser_height, new_chat_textBrowser_height;
	// ���������ı�����
	// ͨ����ȡtext_edit�е��ı�������textBrowser�Ŀ��
	// �������ȡ���������
	QFont font = this->m_ui.chat_textBrowser->font();  // ��ȡ�ı�������
	QFontMetrics fm(font);  // ��������ĸ߶ȺͿ�ȣ�px��
	QRect rect = fm.boundingRect(content);

	text_width = rect.width();
	chat_textBrowser_width = 174;
	row_count = ceil((double)text_width / (double)chat_textBrowser_width);

	// ��������textBrowser�߶�
	// ͬʱ����widget�ĸ߶�
	// ������Ҫ��¼ԭ��textBrowser�ĸ߶����µĸ߶�
	// �Ա�����������ı�widget�߶�
	text_height = this->m_ui.chat_textBrowser->fontMetrics().lineSpacing();
	old_chat_textBrowser_height = this->m_ui.chat_textBrowser->height();
	this->m_ui.chat_textBrowser->setFixedHeight(text_height * row_count);
	new_chat_textBrowser_height = this->m_ui.chat_textBrowser->height();
	this->setFixedHeight(this->height() +
		(new_chat_textBrowser_height - old_chat_textBrowser_height));

	return;
}