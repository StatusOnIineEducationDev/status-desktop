#include "memberItemWidget.h"


MemberItemWidget::MemberItemWidget(const QString &uid, const QString &username,
	const QPixmap &user_pic, const QPixmap &status_pic, QWidget *parent)
	: QWidget(parent) {
	m_ui.setupUi(this);

	this->m_ui.user_pic->setPixmap(user_pic);
	this->m_ui.uid_text->setText(uid);
	this->m_ui.username_text->setText(username);
	this->m_ui.status_pic->setPixmap(status_pic);
}

MemberItemWidget::~MemberItemWidget() {

}