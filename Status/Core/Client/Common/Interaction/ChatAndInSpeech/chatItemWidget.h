#pragma once

#include <QWidget>
#include <QDateTime>
#include <QFont>
#include "ui_c_chatItemOtherWidget.h"
#include "ui_c_chatItemMineWidget.h"


class ChatItemOtherWidget : public QWidget {
public:
	ChatItemOtherWidget(const QPixmap &user_pic, const QString &username,
		const QString &content, const int &timestamp, QWidget *parent = nullptr);
	~ChatItemOtherWidget();
	const Ui::ChatItemOtherWidget& ui() const { return this->m_ui; };

private:
	void resizeItemWidget(const QString &content);

	Ui::ChatItemOtherWidget m_ui;
};


class ChatItemMineWidget : public QWidget {
public:
	ChatItemMineWidget(const QPixmap &user_pic, const QString &username,
		const QString &content, const int &timestamp, QWidget *parent = nullptr);
	~ChatItemMineWidget();
	const Ui::ChatItemMineWidget& ui() const { return this->m_ui; };

private:
	void resizeItemWidget(const QString &content);

	Ui::ChatItemMineWidget m_ui;
};
