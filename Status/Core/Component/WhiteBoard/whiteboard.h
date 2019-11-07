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
	/*mousePaint����ͼ���������ͨ��update()����paintEvent()*/
	void mousePaint(QPixmap &theImage);
	/*commandPaint�����ͼ���������ͨ��update()����paintEvent()*/
	void commandPaint(QPixmap &theImage);
	void commandClear();
	void commandUndo();
	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

	QStack<QPixmap> m_image_stack; // ��������ջ
	QPixmap m_board_image;  // ����
	QPixmap m_temp_image; // ���廭��
	bool m_is_typing;  // �Ƿ����������ı�

	// ��������ͼ
	bool m_mouse_is_drawing;  // ������ͼ���Ƿ����ڻ�ͼ
	LineEdit m_mouse_edit;  // ������ͼ���ı���
	QPen m_mouse_pen;  // ������ͼ������
	QPen m_mouse_rubber;  // ������ͼ����Ƥ��
	QPoint m_mouse_last_point;  // ������ͼ����ͼ����һ����
	QPoint m_mouse_end_point;  // ������ͼ����ͼ�����һ����
	ToolType m_mouse_tool_type;  // ������ͼ��Ŀǰѡ�еĹ������� 

	// ���������ͼ
	bool m_command_is_drawing;  // �������ͼ���Ƿ����ڻ�ͼ
	LineEdit m_command_edit;  // �������ͼ���ı���
	QPen m_command_pen;  // �������ͼ������
	QPen m_command_rubber;  // �������ͼ����Ƥ��
	QPoint m_command_last_point;  // �������ͼ����ͼ����һ����
	QPoint m_command_end_point;  // �������ͼ����ͼ�����һ����
	ToolType m_command_tool_type;  // �������ͼ��Ŀǰѡ�еĹ������� 
};