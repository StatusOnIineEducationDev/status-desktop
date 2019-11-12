#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_s_onlineClassroomWidget.h"
#include "ui_s_inSpeechRemovableWidget.h"
#include "Core/Client/Student/s_mainWindow.h"


class SOnlineClassroomWidget : public QWidget {
	Q_OBJECT

public:
	SOnlineClassroomWidget(SMainWindow *parent = Q_NULLPTR);
	~SOnlineClassroomWidget();

	const Ui::SOnlineClassroomWidget& ui() const { return this->m_ui; };

	void handleWindowResized() { emit this->windowResized(); };

signals:
	void windowResized();

private:
	Ui::SOnlineClassroomWidget m_ui;
};


class SInSpeechRemovableWidget : public QWidget {
	Q_OBJECT

public:
	SInSpeechRemovableWidget(SOnlineClassroomWidget *parent = Q_NULLPTR);
	~SInSpeechRemovableWidget();

	const Ui::SInSpeechRemovableWidget& ui() const { return this->m_ui; };

	void handleWindowResized() { emit this->windowResized(); };

signals:
	void windowResized();

private:
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

	void updatePos();

	Ui::SInSpeechRemovableWidget m_ui;

	bool is_pressed;  // 鼠标左键是否按下
	QPoint start_pos;  // 鼠标左键点下时的坐标
};
