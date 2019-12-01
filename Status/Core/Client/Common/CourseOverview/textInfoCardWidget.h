#pragma once
#include <QWidget>
#include "ui_c_textInfoCardWidget.h"


class TextInfoCardWidget : public QWidget {
	Q_OBJECT

signals:
	void editFinished();

public:
	TextInfoCardWidget(QWidget *parent = nullptr);
	~TextInfoCardWidget();
	const Ui::TextInfoCardWidget& ui() const { return this->m_ui; };

	void edit();
	void finished();
	void setTitle(const QString &title);
	void setContentText(const QString &content_text);

protected:
	void switchReadOnlyStyleSheet();
	void switchEditStyleSheet();

	void updateWordsNowCount();

	Ui::TextInfoCardWidget m_ui;
};