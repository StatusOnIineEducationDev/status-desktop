#pragma once

#include <QtWidgets/QMainWindow>
#include <QList>
#include <QScrollArea>
#include <QColorDialog>
#include "ui_teacher_interaction_widget.h"
#include "Core/View/Component/component.h"

class TeacherInteractionWidget : public QWidget {
	Q_OBJECT

public:
	TeacherInteractionWidget(QWidget *parent = Q_NULLPTR);
	~TeacherInteractionWidget();

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
	Ui::TeacherInteractionWidget ui;

	PaintWidget *board;  // 当前控制的画板
	QList<PaintWidget*> board_list;  // 已创建的画板
	int board_id;  // 创建的画板id计数
};
