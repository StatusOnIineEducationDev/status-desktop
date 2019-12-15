#pragma once
#pragma execution_character_set("utf-8")
#include <QTimer>
#include <QLabel>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>


class Toast : public QLabel {
	Q_OBJECT

signals:
	void complete();

public slots:
	void hide();

public:
	Toast(QString &text);
	Toast(const char *text = nullptr);
	static void setWin(QWidget *win);
	void setInfoText(QString &text);
	void setInfoText(const char *text = nullptr);
	void show();

private slots:
	void emitCompleteSignal();

private:
	void init();

	const int m_point_size = 10;  // toast×ÖÌå´óÐ¡
	const int m_padding_left_right = 25;  // toast±ß¾à
	const int m_padding_top_bottom = 10;  // toast±ß¾à

	static QWidget *s_win;

	QTimer timer;
	QGraphicsOpacityEffect *m_effect;
	QPropertyAnimation *m_show_animation;
	QPropertyAnimation *m_hide_animation;
};




