#include "t_handleRaiseHandWidget.h"


TeacherHandleRaiseHandWidget::TeacherHandleRaiseHandWidget(QWidget *parent)
	: QWidget(parent) {
	m_ui.setupUi(this);

	this->setAutoFillBackground(false);
	this->setAttribute(Qt::WA_TranslucentBackground, true);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint | Qt::Popup);
}

TeacherHandleRaiseHandWidget::~TeacherHandleRaiseHandWidget() {

}

void TeacherHandleRaiseHandWidget::addMemberInHandleRaiseHandWidget(const QPixmap &user_pic,
	const QString &username, const int &timestamp) {
	QListWidgetItem *item = new QListWidgetItem;
	TeacherRaiseHandItemWidget *item_widget = new TeacherRaiseHandItemWidget(user_pic,
		username, timestamp, this->m_ui.raise_hand_view);

	this->m_ui.raise_hand_view->addItem(item);
	this->m_ui.raise_hand_view->setItemWidget(item, item_widget);

	return;
}

void TeacherHandleRaiseHandWidget::removeMemberFromSpeechWidget(const int row) {
	if (row == -1) {
		return;
	}

	this->m_ui.raise_hand_view->takeItem(row);

	return;
}
