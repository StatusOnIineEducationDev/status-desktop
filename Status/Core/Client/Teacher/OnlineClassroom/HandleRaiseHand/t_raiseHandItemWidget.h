#pragma once
#include <QWidget>
#include <QDateTime>
#include "ui_t_raiseHandItemWidget.h"


class TeacherRaiseHandItemWidget : public QWidget {
	Q_OBJECT

public:
	TeacherRaiseHandItemWidget(const QPixmap &user_pic, const QString &username,
		const int &timestamp, QWidget *parent = nullptr);
	const Ui::TeacherRaiseHandItemWidget& ui() const { return this->m_ui; };

private:
	Ui::TeacherRaiseHandItemWidget m_ui;
};
