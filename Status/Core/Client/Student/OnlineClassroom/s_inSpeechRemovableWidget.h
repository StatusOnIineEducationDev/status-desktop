#pragma once
#include <QWidget>
#include <QMouseEvent>
#include "ui_s_inSpeechRemovableWidget.h"
#include "Core/Tools/tools.h"

class StudentInSpeechRemovableWidget : public QWidget {
	Q_OBJECT

public:
	StudentInSpeechRemovableWidget(QWidget *parent = nullptr);
	~StudentInSpeechRemovableWidget();
	const Ui::StudentInSpeechRemovableWidget& ui() const { return this->m_ui; };

	void updateInSpeechLastTime();

protected:
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

	void updatePos();

	Ui::StudentInSpeechRemovableWidget m_ui;

	bool is_pressed;  // 鼠标左键是否按下
	QPoint start_pos;  // 鼠标左键点下时的坐标
};