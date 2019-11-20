#pragma once
#include <QWidget>
#include "ui_c_inSpeechMemberItemWidget.h"


class InSpeechMemberItemWidget : public QWidget {
	Q_OBJECT

public:
	InSpeechMemberItemWidget(const QPixmap &user_pic, const QString &username,
		QWidget *parent = nullptr);
	virtual ~InSpeechMemberItemWidget();
	const Ui::InSpeechMemberItemWidget& ui() const { return this->m_ui; };

protected:
	Ui::InSpeechMemberItemWidget m_ui;
};