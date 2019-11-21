#pragma once
#pragma execution_character_set("utf-8")
#include <QLineEdit>
#include <QMouseEvent>


class LineEdit : public QLineEdit {
	Q_OBJECT

public:
	LineEdit(QLineEdit *parent = Q_NULLPTR);

private:
	bool is_pressed;  // �������Ƿ񱻰���
	QPoint start_pos;  // ����������ʱ������

	void adjustTextLengthAndSize();

	void mouseDoubleClickEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
};