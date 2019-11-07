#pragma once
#pragma execution_character_set("utf-8")  
#include <QWidget>
#include <QLabel>
#include <QColor>
#include <QPen>
#include <QFont>
#include <QMouseEvent>
#include <QPainter>
#include <QPoint>
#include <QStack>
#include <QJsonObject>
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <opencv2/core/core.hpp>  
#include "lineedit.h"
#include "Core/Tools/pic_tools.h"

class WhiteBoard : public QWidget {
	Q_OBJECT

public:
	WhiteBoard(QWidget *parent = Q_NULLPTR);
	enum ToolType { PEN, RUBBER, LINE, RECT, ELLIPSE, TEXT };
	enum PaintType { Image, Paint, Clear, Undo, Push };
	enum PaintWay { Command, Mouse };

	QPixmap& getBoardImage() { return this->m_board_image; };
	QPen getPen() { return this->m_mouse_pen; };
	QPen getRubber() { return this->m_mouse_rubber; };
	ToolType getToolType() { return this->m_mouse_tool_type; };
	void setBoardImage(QPixmap &board_image) { this->m_board_image = board_image; this->update(); return; };
	void setPen(QPen pen) { this->m_mouse_pen = pen; return; };
	void setRubber(QPen rubber);
	void setToolType(ToolType tool_type);

	void mouseClear();
	void mouseUndo();
	void endEdit();
	void paintByPaintCommand(QJsonObject &paint_command);

signals:
	void paintCommandReady(QJsonObject &data);

private:
	QJsonObject createPaintCommand(PaintType paint_type);
	/*mousePaint鼠标绘图函数，其会通过update()调用paintEvent()*/
	void mousePaint(QPixmap &theImage);
	/*commandPaint命令绘图函数，其会通过update()调用paintEvent()*/
	void commandPaint(QPixmap &theImage);
	void commandClear();
	void commandUndo();
	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

	QStack<QPixmap> m_image_stack; // 已做操作栈
	QPixmap m_board_image;  // 画板
	QPixmap m_temp_image; // 缓冲画板
	bool m_is_typing;  // 是否正在输入文本

	// ——鼠标绘图
	bool m_mouse_is_drawing;  // （鼠标绘图）是否正在绘图
	LineEdit m_mouse_edit;  // （鼠标绘图）文本框
	QPen m_mouse_pen;  // （鼠标绘图）画笔
	QPen m_mouse_rubber;  // （鼠标绘图）橡皮檫
	QPoint m_mouse_last_point;  // （鼠标绘图）绘图的上一个点
	QPoint m_mouse_end_point;  // （鼠标绘图）绘图的最后一个点
	ToolType m_mouse_tool_type;  // （鼠标绘图）目前选中的工具类型 

	// ——命令绘图
	bool m_command_is_drawing;  // （命令绘图）是否正在绘图
	LineEdit m_command_edit;  // （命令绘图）文本框
	QPen m_command_pen;  // （命令绘图）画笔
	QPen m_command_rubber;  // （命令绘图）橡皮檫
	QPoint m_command_last_point;  // （命令绘图）绘图的上一个点
	QPoint m_command_end_point;  // （命令绘图）绘图的最后一个点
	ToolType m_command_tool_type;  // （命令绘图）目前选中的工具类型 
};