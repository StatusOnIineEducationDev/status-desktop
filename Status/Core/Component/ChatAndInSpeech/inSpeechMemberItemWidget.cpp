#include "inSpeechMemberItemWidget.h"


InSpeechMemberItemWidget::InSpeechMemberItemWidget(const QPixmap &user_pic, 
	const QString &username, QWidget *parent)
	: QWidget(parent) {
	m_ui.setupUi(this);

	this->m_ui.user_pic->setPixmap(user_pic);
	this->m_ui.username_text->setText(username);
}

InSpeechMemberItemWidget::~InSpeechMemberItemWidget() {

}