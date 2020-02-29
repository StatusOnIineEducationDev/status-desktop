#pragma once
#include <QWidget>
#include "ui_c_memberItemWidget.h"


class MemberItemWidget : public QWidget {
	Q_OBJECT

public:
	MemberItemWidget(const QString &uid, const QString &username,
		const QPixmap &user_pic, const QPixmap &status_pic, QWidget *parent = nullptr);
	virtual ~MemberItemWidget();
	const Ui::MemberItemWidget& ui() const { return this->m_ui; };

protected:
	Ui::MemberItemWidget m_ui;
};