#pragma once

#include <QWidget>
#include <QLabel>
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
#include <QAreaSeries>


class Toast : public QLabel {
	Q_OBJECT

public:
	Toast(QString &text);
	Toast(const char *text = nullptr);
	static void setWin(QWidget *win);
	void setInfoText(QString &text);
	void show();

public slots:
	void hide();

private slots:
	void emitCompleteSignal();

signals:
	void complete();

private:
	const int m_point_size = 10;  // toast字体大小
	const int m_padding_left_right = 25;  // toast边距
	const int m_padding_top_bottom = 10;  // toast边距

	static QWidget *m_win;
	
	QTimer timer;
	QGraphicsOpacityEffect *m_effect;
	QPropertyAnimation *m_show_animation;
	QPropertyAnimation *m_hide_animation;

	void init();
};


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
	enum PaintType { Paint, Clear, Undo, Push };

	QPixmap& getBoardImage() { return this->m_board_image; };
	QPen getPen();
	QPen getRubber();
	ToolType getToolType();
	void setBoardImage(QPixmap &board_image);
	void setPen(QPen pen);
	void setRubber(QPen rubber);
	void setToolType(ToolType tool_type);

	/*清空画板*/
	void clear();
	/*撤销操作*/
	void undo();
	/*结束图片、文字编辑*/
	void endEdit();
	/*使用命令绘图*/
	void paintByPaintCommand(QJsonObject &paint_command);

signals:
	void paintCommandReady(QJsonObject &data);

private:
	QJsonObject createPaintCommand(PaintType paint_type);
	/*绘图函数，其会通过update()调用paintEvent()*/
	void paint(QPixmap &theImage);
	/*绘图函数，update()调用*/
	void paintEvent(QPaintEvent *event);
	/*重写鼠标事件*/
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

	QStack<QPixmap> m_image_stack; // 已做操作栈
	QPixmap m_board_image;  // 画板
	QPixmap m_temp_image; // 缓冲画板
	LineEdit m_edit;  // 文本框
	QPen m_pen;  // 画笔
	QPen m_rubber;  // 橡皮檫
	QPoint m_last_point;  // 绘图的上一个点
	QPoint m_end_point;  // 绘图的最后一个点
	ToolType m_tool_type;  // 目前选中的工具类型 
	bool m_is_drawing;  // 是否正在绘图
	bool m_is_typing;  // 是否正在输入文本
};