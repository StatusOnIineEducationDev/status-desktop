#pragma once
#pragma execution_character_set("utf-8")
#include <QLineEdit>
#include <QMouseEvent>


class LineEdit : public QLineEdit {
	Q_OBJECT

public:
	LineEdit(QLineEdit *parent = Q_NULLPTR);

private:
	bool is_pressed;  // 鼠标左键是否被按下
	QPoint start_pos;  // 鼠标左键点下时的坐标

	void adjustTextLengthAndSize();

	void mouseDoubleClickEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
};