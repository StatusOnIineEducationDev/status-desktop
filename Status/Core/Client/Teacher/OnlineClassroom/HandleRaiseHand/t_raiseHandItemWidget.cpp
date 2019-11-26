#include "t_raiseHandItemWidget.h"


TeacherRaiseHandItemWidget::TeacherRaiseHandItemWidget(const QPixmap &user_pic, 
	const QString &username, const int &timestamp, QWidget *parent)
	: QWidget(parent) {
	m_ui.setupUi(this);

	this->m_ui.user_pic->setPixmap(user_pic);
	this->m_ui.username_text->setText(username);
	this->m_ui.time_text->setText(QDateTime::fromTime_t(timestamp).toString("hh:mm:ss"));
}