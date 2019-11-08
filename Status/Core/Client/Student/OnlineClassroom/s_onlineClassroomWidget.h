#pragma once

#include <QtWidgets/QMainWindow>
#include <QList>
#include <QScrollArea>
#include <QColorDialog>
#include "ui_s_onlineClassroomWidget.h"
#include "ui_s_inSpeechRemovableWidget.h"
#include "Core/Component/WhiteBoard/whiteBoard.h"
#include "Core/Client/Student/s_mainWindow.h"


class SOnlineClassroomWidget : public QWidget {
	Q_OBJECT

public:
	SOnlineClassroomWidget(SMainWindow *parent = Q_NULLPTR);
	~SOnlineClassroomWidget();

	const Ui::SOnlineClassroomWidget& ui() const { return this->m_ui; };
	WhiteBoard* board() const { return this->m_board; }

	void handleWindowResized() { emit this->windowResized(); };

signals:
	void windowResized();

public slots:
	/*工具栏——调整画笔粗细*/
	void setPenWidth(int value);
	/*工具栏——调整橡皮檫粗细*/
	void setRubberWidth(int value);
	/*工具栏——调整画笔Slider*/
	void setPenSlider();
	/*工具栏——调整橡皮檫Slider*/
	void setRubberSlider();
	/*工具栏——选择黑笔*/
	void chooseBlackPen();
	/*工具栏——选择蓝笔*/
	void chooseBluePen();
	/*工具栏——选择红笔*/
	void chooseRedPen();
	/*工具栏——自定义画笔颜色*/
	void chooseColorPen();
	/*工具栏——选择添加文本*/
	void chooseText();
	/*工具栏——选择橡皮檫*/
	void chooseRubber();
	/*工具栏——选择直线工具*/
	void chooseLine();
	/*工具栏——选择矩形工具*/
	void chooseRect();
	/*工具栏——选择椭圆工具*/
	void chooseEllipse();
	/*工具栏——撤销*/
	void undo();
	/*工具栏——清空*/
	void clear();
	/*在工具栏“颜色”按钮边框处显示当前颜色*/
	void showCurrentColor(QString rgb);
	/*新建画板*/
	void addBoard();
	/*删除画板*/
	void deleteBoard(int index);
	/*切换画板*/
	void changeBoard(int index);

private:
	Ui::SOnlineClassroomWidget m_ui;

	WhiteBoard *m_board;  // 当前控制的画板
	QList<WhiteBoard*> m_board_list;  // 已创建的画板
	int m_board_id;  // 创建的画板id计数
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
