#pragma once

#include <QWidget>
#include "ui_c_chatItemOtherWidget.h"
#include "ui_c_chatItemMineWidget.h"


template <typename Widget>
class ChatItemWidget : public QWidget {
public:
	ChatItemWidget(const QPixmap &user_pic, const QString &username,
		const QString &content, const int &timestamp, QWidget *parent = nullptr);
	~ChatItemWidget();
	const Widget& ui() const { return this->m_ui; };

private:
	void resizeItemWidget(const QString &content);

	Widget m_ui;
};
