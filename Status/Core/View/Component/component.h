#pragma once

#include <QWidget>
#include <QColor>
#include <QPen>
#include <QFont>
#include <QMouseEvent>
#include <QPainter>
#include <QLineEdit>
#include <QPoint>
#include <QStack>
#include <QtCharts>
#include <QLineSeries>

class LineEdit : public QLineEdit {
	Q_OBJECT

public:
	LineEdit(QLineEdit *parent = Q_NULLPTR);

private:
	bool is_pressed;  // 鼠标左键是否被按下
	QPoint start_pos;  // 鼠标左键点下时的坐标

	/*适应文本的大小与长度*/
	void adjustTextLengthAndSize();
	/*重写鼠标事件——双击移动控件*/
	void mouseDoubleClickEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
};

class PaintWidget : public QWidget {
	Q_OBJECT


public:
	PaintWidget(QWidget *parent = Q_NULLPTR);
	enum ToolType { PEN, RUBBER, LINE, RECT, ELLIPSE, TEXT };

	QPen getPen();
	QPen getRubber();
	ToolType getToolType();
	void setPen(QPen pen);
	void setRubber(QPen rubber);
	void setToolType(ToolType tool_type);

	/*清空画板*/
	void clear();
	/*撤销操作*/
	void undo();
	/*结束图片、文字编辑*/
	void endEdit();

private:
	QStack<QImage> image_stack; // 已做操作栈
	QImage board_image;  // 画板
	QImage temp_image; // 缓冲画板
	LineEdit edit;  // 文本框
	QPen pen;  // 画笔
	QPen rubber;  // 橡皮檫
	QPoint last_point;  // 绘图的上一个点
	QPoint end_point;  // 绘图的最后一个点
	ToolType tool_type;  // 目前选中的工具类型 
	bool is_drawing;  // 是否正在绘图
	bool is_texting;  // 是否正在输入文本

	/*绘图函数，其会通过update()调用paintEvent()*/
	void paint(QImage &theImage);
	/*绘图函数，update()调用*/
	void paintEvent(QPaintEvent *event);
	/*重写鼠标事件*/
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
};

class AreaChart :public QChart {
	Q_OBJECT

public:
	AreaChart(QLineSeries *series = nullptr);

private:
	QLineSeries *m_series;
	QAreaSeries *m_area_series;
};
