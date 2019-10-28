#include "component.h"

QWidget* Toast::m_win = nullptr;

Toast::Toast(QString &text)
	: QLabel(m_win) {
	this->init(); 
	this->setInfoText(text);
}

Toast::Toast(const char *text)
	: QLabel(m_win) {
	this->init();
	this->setInfoText(QString(text));
}

void Toast::init() {
	QFont font;

	font.setFamily("Microsoft Yahei");
	font.setPointSize(this->m_point_size);
	this->setFont(font);
	this->setAlignment(Qt::AlignCenter);
	this->setStyleSheet("QLabel{color:white;background-color:rgba(0,0,0,150);border-radius:5px;}");

	// ��������
	this->m_effect = new QGraphicsOpacityEffect(this);
	this->m_effect->setOpacity(1.0);
	this->setGraphicsEffect(this->m_effect);

	this->m_show_animation = new QPropertyAnimation(this->m_effect, "opacity", this);
	this->m_show_animation->setDuration(500);
	this->m_show_animation->setStartValue(0);
	this->m_show_animation->setEndValue(1.0);

	this->m_hide_animation = new QPropertyAnimation(this->m_effect, "opacity", this);
	this->m_hide_animation->setDuration(500);
	this->m_hide_animation->setStartValue(1.0);
	this->m_hide_animation->setEndValue(0);

	// �����źŰ�
	this->connect(&this->timer, &QTimer::timeout, this, &Toast::hide);

	return; 
}

void Toast::setWin(QWidget *win) {
	Toast::m_win = win;

	return;
}

void Toast::setInfoText(QString &text) {
	int text_width, text_height;
	int x, y, width, height;

	this->setText(text);
	// ������ȡ�ı�����
	this->adjustSize();
	text_width = this->width();
	text_height = this->height();
	// �����������ô�С��λ��
	width = text_width + 2 * this->m_padding_left_right;
	height = text_height + 2 * this->m_padding_top_bottom;
	x = (this->m_win->width() / 2) - (text_width / 2);
	y = 9 * (this->m_win->height() / 10);
	this->setGeometry(x, y, width, height);

	return;
}

void Toast::show() {
	this->timer.start(2500);
	this->QLabel::show();
	this->m_show_animation->start();

	return;
}

void Toast::hide() {
	this->m_hide_animation->start();
	this->connect(this->m_hide_animation, &QPropertyAnimation::finished, this, &QLabel::hide);
	this->connect(this->m_hide_animation, &QPropertyAnimation::finished, this, &Toast::emitCompleteSignal);

	return;
}

void Toast::emitCompleteSignal() {
	emit this->complete();

	return;
}


//**************************************************************************************************
//**************************************************************************************************


PaintWidget::PaintWidget(QWidget *parent) : QWidget(parent) {
	// ��ʼ��
	this->m_is_drawing = false;
	this->m_is_typing = false;
	this->m_tool_type = PEN;
	this->m_rubber.setBrush(QPixmap(":/pic/Resources/material/pic/paper.png"));
	this->m_pen.setCapStyle(Qt::RoundCap);  // ĩ��Բ�Σ�����Ϊ�˿���ݣ�
	this->m_pen.setJoinStyle(Qt::RoundJoin);  // ���Ӵ�Բ��
	this->m_rubber.setCapStyle(Qt::RoundCap);
	this->m_rubber.setJoinStyle(Qt::RoundJoin);

	this->setMinimumWidth(2048);
	this->setMinimumHeight(2048);
	this->m_board_image = QPixmap(":/pic/Resources/material/pic/paper.png");
	this->m_temp_image = QPixmap(":/pic/Resources/material/pic/paper.png");

	// �źŰ�
	this->connect(&this->m_edit, &QLineEdit::returnPressed, this, &PaintWidget::endEdit);  // ��ӦQLineEdit�Ļس�
}	

QPen PaintWidget::getPen() {
	return this->m_pen;
}

QPen PaintWidget::getRubber() {
	return this->m_rubber;
}

PaintWidget::ToolType PaintWidget::getToolType() {
	return this->m_tool_type;
}

void PaintWidget::setBoardImage(QPixmap &board_image) {
	this->m_board_image = board_image;
	this->update();
	
	return;
}

void PaintWidget::setPen(QPen pen) {
	this->m_pen = pen;

	return;
}

void PaintWidget::setRubber(QPen rubber) {
	QCursor cursor;
	QPixmap cursor_pic;

	this->m_rubber = rubber;

	// �п��ܿ�ȱ仯�ˣ�����ָ���С
	if (this->m_tool_type == RUBBER) {
		cursor_pic = QPixmap(":/cursor/Resources/material/cursor/rubber.png");
		cursor_pic = cursor_pic.scaled(QSize(this->m_rubber.width(), this->m_rubber.width()));
		cursor = QCursor(cursor_pic, -1, -1);
		this->setCursor(cursor);
	}

	return;
}

void PaintWidget::setToolType(ToolType tool_type) {
	QCursor cursor;
	QPixmap cursor_pic;

	this->m_tool_type = tool_type;

	switch (this->m_tool_type) {
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
		cursor_pic = cursor_pic.scaled(QSize(this->m_rubber.width(), this->m_rubber.width()));
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
	this->m_board_image = QPixmap(":/pic/Resources/material/pic/paper.png");
	this->m_temp_image = QPixmap(":/pic/Resources/material/pic/paper.png");

	update();
	emit paintCommandReady(this->createPaintCommand(PaintType::Clear));

	return;
}

/*
	��������
*/
void PaintWidget::undo() {
	if (!this->m_image_stack.isEmpty()) {
		this->m_board_image = this->m_image_stack.pop();  // ��һ������ջ
		update();
		emit paintCommandReady(this->createPaintCommand(PaintType::Undo));
	}

	return;
}


/*
	��paint_command��ͼ
*/
void PaintWidget::paintByPaintCommand(QJsonObject &paint_command) {
	PaintType paint_type = PaintType(paint_command["paint_type"].toInt());
	bool is_drawing = paint_command["is_drawing"].toBool();

	// ����ͬ������
	this->m_tool_type = ToolType(paint_command["tool_type"].toInt());
	this->m_last_point = QPoint(paint_command["last_point_x"].toInt(), paint_command["last_point_y"].toInt());
	this->m_end_point = QPoint(paint_command["end_point_x"].toInt(), paint_command["end_point_y"].toInt());
	this->m_rubber.setWidth(paint_command["rubber_width"].toInt());
	this->m_pen.setWidth(paint_command["pen_width"].toInt());
	this->m_pen.setColor(paint_command["color"].toString().toUInt(nullptr, 16));
	this->m_edit.setGeometry(paint_command["edit_x"].toInt(), paint_command["edit_y"].toInt(), paint_command["edit_width"].toInt(), paint_command["edit_height"].toInt());
	this->m_edit.setText(paint_command["edit_text"].toString());
	
	switch (paint_type) {
	case Paint:
		// �������Ϊ���ʻ���Ƥ�ߣ�ֱ�ӻ��ڻ���
		if (this->m_tool_type == PEN || this->m_tool_type == RUBBER) {
			this->paint(this->m_board_image);
		}
		// �����������ã�˫�����ͼ������Ҳ��˫���壬ֻ�ǲ��ѻ�ͼ������ʾ
		else {
			if (!is_drawing) {
				this->paint(this->m_board_image);
			}
		}
		break;
	case Clear:
		this->clear();
		break;
	case Undo:
		this->undo();
		break;
	case Push:
		this->m_image_stack.push(this->m_board_image);  // ��ǰ�����ջ����������
		break;
	}

	return;
}

/*
	����ͼƬ�����ֱ༭
*/
void PaintWidget::endEdit() {
	ToolType temp_tool_type = this->m_tool_type;  // �����ڴ˴ε��ǰѡ��Ĳ���

	if (this->m_is_typing) {
		this->m_tool_type = PaintWidget::TEXT;  // ���л�Ϊ�ı�����
		this->paint(this->m_board_image);  // ���ı����ڻ�����
		this->m_edit.hide();
		this->m_edit.clear();
		this->m_tool_type = temp_tool_type;
		this->m_is_typing = false;
	}
	
	return;
}

/*
	(��ͼ����)��������������ǵ����ػ溯������ͼ����image��
*/
void PaintWidget::paint(QPixmap &image) {
	QPainter painter(&image); // ��ͼ����image(image��painterDevice���Ͳ��������������ã���ʵ���ǻ���image��)
	QPoint last_point = this->m_last_point, end_point = this->m_end_point;


	painter.setRenderHint(QPainter::Antialiasing, true);  // �����

	if (this->m_tool_type == RUBBER) {
		painter.setPen(this->m_rubber);
	}
	else {
		painter.setPen(this->m_pen);
	}

	switch (this->m_tool_type) {
	case PEN:
	case RUBBER:
		painter.drawLine(this->m_last_point, this->m_end_point);  // ���ߣ���������ƶ��¼�����ô˺��������lastPoint��endPoint������Ϊ0����˿ɽ��ƿ��ɻ��㣬�����������ǻ��ʵĺۼ���
		//this->m_last_point = this->m_end_point;  // ���յ㸴�Ƹ����
		break;
	case LINE:
		painter.drawLine(this->m_last_point, this->m_end_point);
		break;
	case RECT: 
		painter.drawRect(this->m_last_point.x(), this->m_last_point.y(), this->m_end_point.x() - this->m_last_point.x(), this->m_end_point.y() - this->m_last_point.y());
		break;
	case ELLIPSE:
		painter.drawEllipse(this->m_last_point.x(), this->m_last_point.y(), this->m_end_point.x() - this->m_last_point.x(), this->m_end_point.y() - this->m_last_point.y());
		break;
	case TEXT:
		painter.setFont(this->m_edit.font());
		painter.drawText(this->m_edit.x(), this->m_edit.y() + (this->m_edit.height() / 1.35), this->m_edit.text());
	}

	update();  // ˢ��
	emit paintCommandReady(this->createPaintCommand(PaintType::Paint));
	if (this->m_tool_type == PEN || this->m_tool_type == RUBBER) {
		this->m_last_point = this->m_end_point;  // ���յ㸴�Ƹ����
	}

	return;
}

/*
	����paint_command
*/
QJsonObject PaintWidget::createPaintCommand(PaintType paint_type) {
	QJsonObject paint_command;

	paint_command["paint_type"] = paint_type;
	paint_command["tool_type"] = this->m_tool_type;
	paint_command["last_point_x"] = this->m_last_point.x();
	paint_command["last_point_y"] = this->m_last_point.y();
	paint_command["end_point_x"] = this->m_end_point.x();
	paint_command["end_point_y"] = this->m_end_point.y();
	paint_command["rubber_width"] = this->m_rubber.width();
	paint_command["pen_width"] = this->m_pen.width();
	paint_command["color"] = QString::number(qRgb(this->m_pen.color().red(), this->m_pen.color().green(), this->m_pen.color().blue()), 16);
	paint_command["edit_x"] = this->m_edit.x();
	paint_command["edit_y"] = this->m_edit.y();
	paint_command["edit_width"] = this->m_edit.width();
	paint_command["edit_height"] = this->m_edit.height();
	paint_command["edit_text"] = this->m_edit.text();
	paint_command["is_drawing"] = this->m_is_drawing;

	return paint_command;
}

/*
	��ͼ����
	ͨ��update()����
*/
void PaintWidget::paintEvent(QPaintEvent *event) {
	QPainter painter(this);
	if (this->m_is_drawing == true) {
		// ������ڻ�ͼ������������������ƶ�������temp_image��
		painter.drawPixmap(0, 0, this->m_temp_image);
	}
	else {
		// �����ڻ�����
		painter.drawPixmap(0, 0, this->m_board_image);
	}

	return;
}

/*
	��д������¼�
	ֻ�����������ĵ��
*/
void PaintWidget::mousePressEvent(QMouseEvent *event) {	
	this->m_image_stack.push(this->m_board_image);  // ��ǰ�����ջ����������
	emit paintCommandReady(this->createPaintCommand(PaintType::Push));
	
	// ��갴����Ϊ���
	if (event->button() == Qt::LeftButton) {
		// �����δ��ɵ�ͼƬ���ı��Ȳ������Ƚ��������ڻ�����
		this->endEdit();

		// ���ѡ����ǡ������ı��������Ȳ���ͼ
		if (this->m_tool_type == TEXT) {
			this->m_is_typing = true;
			// �����λ����ʾһ���ı���
			this->m_edit.setGeometry(event->pos().x(), event->pos().y(), 100, 25);
			this->m_edit.setParent(this);
			this->m_edit.show();
			this->m_edit.setFocus();
		}
		else {
			this->m_last_point = event->pos();  // �������Ϊ��갴�µĵ�
			this->m_end_point = event->pos();  // �����յ�Ϊ��갴�µĵ�
			this->m_is_drawing = true;  // ��ʼ��ͼ
		}	
	}

	return;
}

/*
	��д����ƶ��¼�
*/
void PaintWidget::mouseMoveEvent(QMouseEvent *event) {
	if (event->buttons() & Qt::LeftButton) {  // ��갴��������ƶ�
		this->m_end_point = event->pos();  // ���ÿ�ƶ�һ�ζ�ˢ���յ�
		this->m_temp_image = this->m_board_image;

		// ���Ϊ���ʻ���Ƥ�ߣ�ֱ�ӻ��ڻ���
		if (this->m_tool_type == PEN || this->m_tool_type == RUBBER) {
			this->paint(this->m_board_image);
		}
		// ��������˫�����ͼ
		else {
			this->paint(this->m_temp_image);
		}
		
	}

	return;
}


/*
	��д����ͷ��¼�
*/
void PaintWidget::mouseReleaseEvent(QMouseEvent *event) {
	this->m_is_drawing = false; // ��ͼ���
	this->paint(this->m_board_image); // �����һ�㻭��image������

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

