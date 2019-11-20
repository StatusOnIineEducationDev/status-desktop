#pragma once

#include <QWidget>
#include <QScrollArea>
#include <QTabBar>
#include <QColorDialog>
#include "ui_c_whiteBoardWidget.h"
#include "whiteboard.h"


class WhiteBoardWidget : public QWidget {
	Q_OBJECT

public:
	WhiteBoardWidget(QWidget *parent = nullptr);
	~WhiteBoardWidget();
	const Ui::WhiteBoardWidget& ui() const { return this->m_ui; };
	WhiteBoard* interactiveBoard() const { return this->m_interactive_board; };

	void setInteractiveWhiteBoardDisabled(bool flag);

protected:
	void initWhiteBoardArea();
	void createInteractiveWhiteBoard();
	void toolBarSignalConnect();
	void setToolBarDisabled(bool flag);
	void setPenWidth(int value);
	void setRubberWidth(int value);
	void setPenSlider();
	void setRubberSlider();
	void chooseBlackPen();
	void chooseBluePen();
	void chooseRedPen();
	void chooseColorPen();
	void chooseText();
	void chooseRubber();
	void chooseLine();
	void chooseRect();
	void chooseEllipse();
	void undo();
	void clear();
	void showCurrentColor(QString rgb);
	void addBoard();
	void deleteBoard(int index);
	void changeBoard(int index);

	Ui::WhiteBoardWidget m_ui;
	
	WhiteBoard *m_board;  // 当前控制的画板
	WhiteBoard *m_interactive_board;  // 互动画板
	QList<WhiteBoard*> m_board_list;  // 已创建的画板
	int m_board_id;  // 创建的画板id计数
};
