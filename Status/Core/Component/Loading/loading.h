#pragma once
#pragma execution_character_set("utf-8")
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QWidget>
#include "ui_c_loadingMask.h"
#include "ui_c_loadingWidget.h"


class LoadingMask : public QWidget {
	Q_OBJECT

public:
	LoadingMask(QWidget *parent = nullptr);
	virtual ~LoadingMask();
	const Ui::LoadingMask& ui() const { return this->m_ui; };

	void setTipsText(const QString &text) { this->m_ui.tips_text->setText(text); return; };
	void resizeMask();

protected:
	Ui::LoadingMask m_ui;
	
	void animation();
};


class LoadingWidget : public QWidget {
	Q_OBJECT

public:
	LoadingWidget(QWidget *parent = nullptr);
	virtual ~LoadingWidget();
	const Ui::LoadingWidget& ui() const { return this->m_ui; };

	void setTipsText(const QString &text) { this->m_ui.tips_text->setText(text); return; };

protected:
	Ui::LoadingWidget m_ui;

	void setPos(QWidget *parent);
	void animation();
};
