#include "memberWidget.h"


MemberWidget::MemberWidget(QWidget *parent)
	: QWidget(parent) {
	m_ui.setupUi(this);

}

MemberWidget::~MemberWidget() {

}

void MemberWidget::addMember(const QString &uid, const QString &username,
	const QPixmap &user_pic, const QPixmap &status_pic) {
	QListWidgetItem *item = new QListWidgetItem;
	MemberItemWidget *item_widget = new MemberItemWidget(uid, username, user_pic, 
		status_pic, this->m_ui.member_view);

	item->setSizeHint(QSize(item_widget->width(), item_widget->height()));
	this->m_ui.member_view->addItem(item);
	this->m_ui.member_view->setItemWidget(item, item_widget);

	return;
}

void MemberWidget::addMemberAtTop(const QString &uid, const QString &username,
	const QPixmap &user_pic, const QPixmap &status_pic) {
	QListWidgetItem *item = new QListWidgetItem;
	MemberItemWidget *item_widget = new MemberItemWidget(uid, username, user_pic,
		status_pic, this->m_ui.member_view);

	item->setSizeHint(QSize(item_widget->width(), item_widget->height()));
	this->m_ui.member_view->insertItem(0, item);
	this->m_ui.member_view->setItemWidget(item, item_widget);

	return;
}

void MemberWidget::removeMember(const QString &uid) {
	QListWidgetItem *item;
	QWidget *item_widget;

	for (int i = 0; i < this->m_ui.member_view->count(); i++) {
		item = this->m_ui.member_view->item(i);
		item_widget = this->m_ui.member_view->itemWidget(item);
		if (uid == item_widget->findChild<QLabel*>("uid_text")->text()) {
			this->m_ui.member_view->takeItem(i);
		}
	}

	return;
}

void MemberWidget::setMemberStatusPic(const QString &uid, const QPixmap &status_pic) {
	QWidget *item_widget = this->findItemWidget(uid);

	if (item_widget != nullptr) {
		item_widget->findChild<QLabel*>("status_pic")->setPixmap(status_pic);
	}

	return;
}

QJsonArray MemberWidget::getUidJsonAarry() {
	QListWidgetItem *item;
	QWidget *item_widget;
	QJsonArray uid_json_arr;

	for (int i = 0; i < this->m_ui.member_view->count(); i++) {
		item = this->m_ui.member_view->item(i);
		item_widget = this->m_ui.member_view->itemWidget(item);
		uid_json_arr.append(item_widget->findChild<QLabel*>("uid_text")->text());
	}

	return uid_json_arr;
}

QWidget* MemberWidget::findItemWidget(const QString &uid) {
	QListWidgetItem *item;
	QWidget *item_widget;

	for (int i = 0; i < this->m_ui.member_view->count(); i++) {
		item = this->m_ui.member_view->item(i);
		item_widget = this->m_ui.member_view->itemWidget(item);
		if (uid == item_widget->findChild<QLabel*>("uid_text")->text()) {
			return item_widget;
		}
	}

	return nullptr;
}
