#include "textInfoCardWidget.h"


TextInfoCardWidget::TextInfoCardWidget(QWidget *parent)
	: QWidget(parent) {
	m_ui.setupUi(this);

	this->m_ui.edit_tool_frame->hide();  // 编辑工具栏默认隐藏

	// ——信号绑定
	this->connect(this->m_ui.edit_btn, &QPushButton::clicked,
		this, &TextInfoCardWidget::edit);
	this->connect(this->m_ui.confirm_btn, &QPushButton::clicked,
		this, &TextInfoCardWidget::finished);
	this->connect(this->m_ui.content_TextEdit, &QPlainTextEdit::textChanged,
		this, &TextInfoCardWidget::updateWordsNowCount);
}

TextInfoCardWidget::~TextInfoCardWidget() {

}

void TextInfoCardWidget::edit() {
	this->m_ui.content_TextEdit->setReadOnly(false);  // 设置为可编辑
	this->m_ui.edit_tool_frame->show();
	this->m_ui.edit_btn->hide();
	this->m_ui.now_count_text->
		setText(QString::number(this->m_ui.content_TextEdit->toPlainText().count()));

	this->switchEditStyleSheet();

	return;
}

void TextInfoCardWidget::finished() {
	this->m_ui.content_TextEdit->setReadOnly(true);  // 设置为不可编辑
	this->m_ui.content_TextEdit->
		setTextInteractionFlags(Qt::NoTextInteraction);  // 不能进行任何鼠标操作
	this->m_ui.edit_tool_frame->hide();
	this->m_ui.edit_btn->show();

	this->switchReadOnlyStyleSheet();

	emit this->editFinished();

	return;
}

void TextInfoCardWidget::setTitle(const QString &title) {
	this->m_ui.title_text->setText(title);

	return;
}

void TextInfoCardWidget::setContentText(const QString &content_text) {
	this->m_ui.content_TextEdit->setPlainText(content_text);

	return;
}

void TextInfoCardWidget::switchReadOnlyStyleSheet() {
	this->m_ui.content_frame->setStyleSheet(
		"QFrame {\
			border: 1px solid #ffffff;\
			border-top-left-radius: 5px;\
			border-top-right-radius: 5px;\
			color: #666666;\
			background: #ffffff;\
		}");

	return;
}

void TextInfoCardWidget::switchEditStyleSheet() {
	this->m_ui.content_frame->setStyleSheet(
		"QFrame {\
			border: 1px solid #E8ECEC;\
			border-top-left-radius: 5px;\
			border-top-right-radius: 5px;\
			color: #333333;\
			background: #fafafa;\
		}");

	return;
}

void TextInfoCardWidget::updateWordsNowCount() {
	QString content_text = this->m_ui.content_TextEdit->toPlainText();
	int now_count = content_text.count(),
		max_count = 200;

	this->m_ui.now_count_text->setText(QString::number(now_count));

	if (now_count > max_count) {
		this->m_ui.confirm_btn->setDisabled(true);
		this->m_ui.now_count_text->setStyleSheet("color: red;");
	}
	else {
		this->m_ui.confirm_btn->setDisabled(false);
		this->m_ui.now_count_text->setStyleSheet("color: #999999;");
	}

	return;
}