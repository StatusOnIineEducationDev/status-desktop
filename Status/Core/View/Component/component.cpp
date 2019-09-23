#include "component.h"

PaintWidget::PaintWidget(QWidget *parent) : QWidget(parent) {
	// ��ʼ��
	this->is_drawing = false;
	this->is_texting = false;
	this->tool_type = PEN;
	this->rubber.setBrush(QImage(":/pic/Resources/material/pic/paper.png"));
	this->pen.setCapStyle(Qt::RoundCap);  // ĩ��Բ�Σ�����Ϊ�˿���ݣ�
	this->pen.setJoinStyle(Qt::RoundJoin);  // ���Ӵ�Բ��
	this->rubber.setCapStyle(Qt::RoundCap);
	this->rubber.setJoinStyle(Qt::RoundJoin);

	this->setMinimumWidth(2048);
	this->setMinimumHeight(2048);
	this->board_image = QImage(":/pic/Resources/material/pic/paper.png");
	this->temp_image = QImage(":/pic/Resources/material/pic/paper.png");

	// �źŰ�
	this->connect(&this->edit, &QLineEdit::returnPressed, this, &PaintWidget::endEdit);  // ��ӦQLineEdit�Ļس�
}	

QPen PaintWidget::getPen() {
	return this->pen;
}

QPen PaintWidget::getRubber() {
	return this->rubber;
}

PaintWidget::ToolType PaintWidget::getToolType() {
	return this->tool_type;
}

void PaintWidget::setPen(QPen pen) {
	this->pen = pen;

	return;
}

void PaintWidget::setRubber(QPen rubber) {
	QCursor cursor;
	QPixmap cursor_pic;

	this->rubber = rubber;

	// �п��ܿ�ȱ仯�ˣ�����ָ���С
	if (this->tool_type == RUBBER) {
		cursor_pic = QPixmap(":/cursor/Resources/material/cursor/rubber.png");
		cursor_pic = cursor_pic.scaled(QSize(this->rubber.width(), this->rubber.width()));
		cursor = QCursor(cursor_pic, -1, -1);
		this->setCursor(cursor);
	}

	return;
}

void PaintWidget::setToolType(ToolType tool_type) {
	QCursor cursor;
	QPixmap cursor_pic;

	this->tool_type = tool_type;

	switch (this->tool_type) {
	case LINE:
	case RECT:
	case ELLIPSE:
		cursor_pic = QPixmap(":/cursor/Resources/material/cursor/shape.png");
		cursor = QCursor(cursor_pic, -1, -1);
		this->setCursor(cursor);
		break;
	case TEXT:
		cursor_pic = QPixmap(":/cursor/Resources/material/cursor/text.png");
		cursor = QCursor(cursor_pic, -1, 0);
		this->setCursor(cursor);
		break;
	case PEN:
		cursor_pic = QPixmap(":/cursor/Resources/material/cursor/pen.png");
		cursor = QCursor(cursor_pic, 0, 20);
		this->setCursor(cursor);
		break;
	case RUBBER:
		cursor_pic = QPixmap(":/cursor/Resources/material/cursor/rubber.png");
		cursor_pic = cursor_pic.scaled(QSize(this->rubber.width(), this->rubber.width()));
		cursor = QCursor(cursor_pic, -1, -1);
		this->setCursor(cursor);
		break;
	}

	return;
}

/*
	��ջ���
*/
void PaintWidget::clear() {
	this->board_image = QImage(":/pic/Resources/material/pic/paper.png");
	this->temp_image = QImage(":/pic/Resources/material/pic/paper.png");

	update();

	return;
}

/*
	��������
*/
void PaintWidget::undo() {
	if (!this->image_stack.isEmpty()) {
		this->board_image = this->image_stack.pop();  // ��һ������ջ
		update();
	}

	return;
}


/*
	����ͼƬ�����ֱ༭
*/
void PaintWidget::endEdit() {
	ToolType temp_tool_type = this->tool_type;  // �����ڴ˴ε��ǰѡ��Ĳ���

	if (this->is_texting) {
		this->tool_type = PaintWidget::TEXT;  // ���л�Ϊ�ı�����
		this->paint(this->board_image);  // ���ı����ڻ�����
		this->edit.hide();
		this->edit.clear();
		this->tool_type = temp_tool_type;
		this->is_texting = false;
	}
	
	return;
}

/*
	(��ͼ����)��������������ǵ����ػ溯������ͼ����image��
*/
void PaintWidget::paint(QImage &image) {
	QPainter painter(&image); // ��ͼ����image(image��painterDevice���Ͳ��������������ã���ʵ���ǻ���image��)
	painter.setRenderHint(QPainter::Antialiasing, true);  // �����

	if (this->tool_type == RUBBER) {
		painter.setPen(this->rubber);
	}
	else {
		painter.setPen(this->pen);
	}

	switch (this->tool_type) {
	case PEN:
	case RUBBER:
		painter.drawLine(this->last_point, this->end_point);  // ���ߣ���������ƶ��¼�����ô˺��������lastPoint��endPoint������Ϊ0����˿ɽ��ƿ��ɻ��㣬�����������ǻ��ʵĺۼ���
		this->last_point = this->end_point;  // ���յ㸴�Ƹ����
		break;
	case LINE:
		painter.drawLine(this->last_point, this->end_point);
		break;
	case RECT: 
		painter.drawRect(this->last_point.x(), this->last_point.y(), this->end_point.x() - this->last_point.x(), this->end_point.y() - this->last_point.y());
		break;
	case ELLIPSE:
		painter.drawEllipse(this->last_point.x(), this->last_point.y(), this->end_point.x() - this->last_point.x(), this->end_point.y() - this->last_point.y());
		break;
	case TEXT:
		painter.setFont(this->edit.font());
		painter.drawText(this->edit.x(), this->edit.y() + (this->edit.height() / 1.35), this->edit.text());
	}

	update();  // ˢ��
}


/*
	��ͼ����
	ͨ��update()����
*/
void PaintWidget::paintEvent(QPaintEvent *event) {
	QPainter painter(this);
	if (this->is_drawing == true) {
		// ������ڻ�ͼ������������������ƶ�������temp_image��
		painter.drawImage(0, 0, this->temp_image);  
	}
	else {
		// �����ڻ�����
		painter.drawImage(0, 0, this->board_image);  
	}
}

/*
	��д������¼�
	ֻ�����������ĵ��
*/
void PaintWidget::mousePressEvent(QMouseEvent *event) {	
	this->image_stack.push(this->board_image);  // ��ǰ�����ջ����������
	
	// ��갴����Ϊ���
	if (event->button() == Qt::LeftButton) {
		// �����δ��ɵ�ͼƬ���ı��Ȳ������Ƚ��������ڻ�����
		this->endEdit();

		// ���ѡ����ǡ������ı��������Ȳ���ͼ
		if (this->tool_type == TEXT) {
			this->is_texting = true;
			// �����λ����ʾһ���ı���
			this->edit.setGeometry(event->pos().x(), event->pos().y(), 100, 25);
			this->edit.setParent(this);
			this->edit.show();
			this->edit.setFocus();
		}
		else {
			this->last_point = event->pos();  // �������Ϊ��갴�µĵ�
			this->end_point = event->pos();  // �����յ�Ϊ��갴�µĵ�
			this->is_drawing = true;  // ��ʼ��ͼ
		}	
	}

	return;
}

/*
	��д����ƶ��¼�
*/
void PaintWidget::mouseMoveEvent(QMouseEvent *event) { //�ص���ⲿ��

	if (event->buttons() & Qt::LeftButton) {//-------------------------��갴��������ƶ�
		this->end_point = event->pos();//-----------------------------------���ÿ�ƶ�һ�ζ�ˢ���յ�
		this->temp_image = this->board_image;

		// ���Ϊ���ʻ���Ƥ�ߣ�ֱ�ӻ��ڻ���
		if (this->tool_type == PEN || this->tool_type == RUBBER) {
			this->paint(this->board_image);
		}
		// ��������˫�����ͼ
		else {
			this->paint(this->temp_image);
		}
		
	}

	return;
}


/*
	��д����ͷ��¼�
*/
void PaintWidget::mouseReleaseEvent(QMouseEvent *event) {
	this->is_drawing = false; // ��ͼ���
	this->paint(this->board_image); // �����һ�㻭��image������

	return;
}

//**************************************************************************************************
//**************************************************************************************************

LineEdit::LineEdit(QLineEdit *parent) {
	this->is_pressed = false;
	QFont font = this->font();

	font.setFamily("΢���ź�");
	font.setPointSize(12);
	this->setFont(font);
	this->resize(100, 25);
	this->setStyleSheet("border: 2px dashed  #000000;");

	// �źŰ�
	this->connect(this, &QLineEdit::textChanged, this, &LineEdit::adjustTextLengthAndSize);
}

/*
	����Ӧ�ı��Ĵ�С�볤��
*/
void LineEdit::adjustTextLengthAndSize() {

	QFont font = this->font();  // ��ȡ�ı�������
	QString text = this->text();  // ��ȡ�ı����ı�����
	QFontMetrics fm(font);  // ��������ĸ߶ȺͿ�ȣ�px��
	QRect rect = fm.boundingRect(text);

	this->resize(rect.width() + 10, rect.height() + 10);

	return;
}

/*
	��д����¼�
	���ڿؼ��϶�
*/
void LineEdit::mouseDoubleClickEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton) {
		this->setCursor(Qt::SizeAllCursor);  // ���������ʽ
		this->is_pressed = true;
		this->start_pos = QPoint(event->pos().x(), event->pos().y());
	}

	return;
}

void LineEdit::mouseMoveEvent(QMouseEvent *event) {
	// ������굱ǰλ��
	// ������������£���ִ���ƶ�
	if (this->is_pressed) {
		this->move(this->pos() + event->pos() - this->start_pos);
	}

	return;
}

void LineEdit::mouseReleaseEvent(QMouseEvent *event) {
	this->setCursor(Qt::ArrowCursor);  // �ָ������ʽ
	this->is_pressed = false;

	return;
}

//**************************************************************************************************
//**************************************************************************************************

AreaChart::AreaChart(QLineSeries *series) {
	//this->m_series = series;
	QPen pen(QColor(131, 105, 203), 2);
	QFont font("΢���ź�", 10);

	this->m_series = new QLineSeries();
	this->m_series->setPen(pen);
	*this->m_series << QPointF(1, 59) << QPointF(3, 77) << QPointF(7, 64) << QPointF(9, 75) << QPointF(12, 62) << QPointF(16, 72) << QPointF(18, 54);

	this->m_area_series = new QAreaSeries(this->m_series);  // �������
	QColor a = this->m_series->color();
	a.setAlpha(100);

	this->m_area_series->setBrush(a);

	this->addSeries(m_area_series);  // ������
	this->addSeries(m_series);  // ����ߣ�������˳�򲻿ɵ�������������������������ߣ�Ҫ��֤���߻������֮�ϣ�


	this->setMargins(QMargins(0, 0, 0, 0));  // ������߾�Ϊ0
	this->legend()->setVisible(false);  // ����ͼ��

	// �������ʼ��
	this->createDefaultAxes();  // ����������
	this->axisX()->setLabelsFont(font);
	this->axisX()->setLabelsColor(QColor(153, 153, 153));
	this->axisX()->setLabelsFont(font);
	this->axisX()->setRange(0, this->m_series->points().constLast().x() + 1);
	this->axisY()->setLabelsFont(font);
	this->axisY()->setLabelsColor(QColor(153, 153, 153));
	this->axisY()->setLabelsFont(font);
	this->axisY()->setRange(0, 100);
}