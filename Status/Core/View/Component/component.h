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
	const int m_point_size = 10;  // toast�����С
	const int m_padding_left_right = 25;  // toast�߾�
	const int m_padding_top_bottom = 10;  // toast�߾�

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
	enum PaintType { Paint, Clear, Undo, Push };

	QPixmap& getBoardImage() { return this->m_board_image; };
	QPen getPen();
	QPen getRubber();
	ToolType getToolType();
	void setBoardImage(QPixmap &board_image);
	void setPen(QPen pen);
	void setRubber(QPen rubber);
	void setToolType(ToolType tool_type);

	/*��ջ���*/
	void clear();
	/*��������*/
	void undo();
	/*����ͼƬ�����ֱ༭*/
	void endEdit();
	/*ʹ�������ͼ*/
	void paintByPaintCommand(QJsonObject &paint_command);

signals:
	void paintCommandReady(QJsonObject &data);

private:
	QJsonObject createPaintCommand(PaintType paint_type);
	/*��ͼ���������ͨ��update()����paintEvent()*/
	void paint(QPixmap &theImage);
	/*��ͼ������update()����*/
	void paintEvent(QPaintEvent *event);
	/*��д����¼�*/
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

	QStack<QPixmap> m_image_stack; // ��������ջ
	QPixmap m_board_image;  // ����
	QPixmap m_temp_image; // ���廭��
	LineEdit m_edit;  // �ı���
	QPen m_pen;  // ����
	QPen m_rubber;  // ��Ƥ��
	QPoint m_last_point;  // ��ͼ����һ����
	QPoint m_end_point;  // ��ͼ�����һ����
	ToolType m_tool_type;  // Ŀǰѡ�еĹ������� 
	bool m_is_drawing;  // �Ƿ����ڻ�ͼ
	bool m_is_typing;  // �Ƿ����������ı�
};