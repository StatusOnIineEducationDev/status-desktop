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
	bool is_pressed;  // �������Ƿ񱻰���
	QPoint start_pos;  // ����������ʱ������

	/*��Ӧ�ı��Ĵ�С�볤��*/
	void adjustTextLengthAndSize();
	/*��д����¼�����˫���ƶ��ؼ�*/
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

	/*��ջ���*/
	void clear();
	/*��������*/
	void undo();
	/*����ͼƬ�����ֱ༭*/
	void endEdit();

private:
	QStack<QImage> image_stack; // ��������ջ
	QImage board_image;  // ����
	QImage temp_image; // ���廭��
	LineEdit edit;  // �ı���
	QPen pen;  // ����
	QPen rubber;  // ��Ƥ��
	QPoint last_point;  // ��ͼ����һ����
	QPoint end_point;  // ��ͼ�����һ����
	ToolType tool_type;  // Ŀǰѡ�еĹ������� 
	bool is_drawing;  // �Ƿ����ڻ�ͼ
	bool is_texting;  // �Ƿ����������ı�

	/*��ͼ���������ͨ��update()����paintEvent()*/
	void paint(QImage &theImage);
	/*��ͼ������update()����*/
	void paintEvent(QPaintEvent *event);
	/*��д����¼�*/
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
