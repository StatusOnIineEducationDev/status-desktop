#pragma once

#include "ui_c_chatItemOtherWidget.h"
#include "ui_c_chatItemMineWidget.h"
#include "ui_c_inSpeechMemberItemWidget.h"
#include "ui_c_raiseHandItemWidget.h"
#include <QtWidgets/QMainWindow>
#include <QListView>


class CChatItemOtherWidget : public QWidget {
	Q_OBJECT

public:
	CChatItemOtherWidget(QWidget *parent = Q_NULLPTR);
	const Ui::CChatItemOtherWidget& ui() const { return this->m_ui; };

private:
	Ui::CChatItemOtherWidget m_ui;
};


class CChatItemMineWidget : public QWidget {
	Q_OBJECT

public:
	CChatItemMineWidget(QWidget *parent = Q_NULLPTR);
	const Ui::CChatItemMineWidget& ui() const { return this->m_ui; };

private:
	Ui::CChatItemMineWidget m_ui;
};


class CInSpeechMemberItemWidget : public QWidget {
	Q_OBJECT

public:
	CInSpeechMemberItemWidget(QWidget *parent = Q_NULLPTR);
	const Ui::CInSpeechMemberItemWidget& ui() const { return this->m_ui; };

private:
	Ui::CInSpeechMemberItemWidget m_ui;
};


class CRaiseHandItemWidget : public QWidget {
	Q_OBJECT

public:
	CRaiseHandItemWidget(QWidget *parent = Q_NULLPTR);
	const Ui::CRaiseHandItemWidget& ui() const { return this->m_ui; };

private:
	Ui::CRaiseHandItemWidget m_ui;
};
