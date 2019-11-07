#include "WhiteBoard.h"

WhiteBoard::WhiteBoard(QWidget *parent) : QWidget(parent) {
	// ��ʼ��
	this->m_is_typing = false;

	this->m_mouse_is_drawing = false;
	this->m_mouse_tool_type = PEN;
	this->m_mouse_rubber.setBrush(QPixmap(":/pic/Resources/material/pic/paper.png"));
	this->m_mouse_pen.setCapStyle(Qt::RoundCap);  // ĩ��Բ�Σ�����Ϊ�˿���ݣ�
	this->m_mouse_pen.setJoinStyle(Qt::RoundJoin);  // ���Ӵ�Բ��
	this->m_mouse_rubber.setCapStyle(Qt::RoundCap);
	this->m_mouse_rubber.setJoinStyle(Qt::RoundJoin);

	this->m_command_is_drawing = false;
	this->m_command_tool_type = PEN;
	this->m_command_rubber.setBrush(QPixmap(":/pic/Resources/material/pic/paper.png"));
	this->m_command_pen.setCapStyle(Qt::RoundCap);  // ĩ��Բ�Σ�����Ϊ�˿���ݣ�
	this->m_command_pen.setJoinStyle(Qt::RoundJoin);  // ���Ӵ�Բ��
	this->m_command_rubber.setCapStyle(Qt::RoundCap);
	this->m_command_rubber.setJoinStyle(Qt::RoundJoin);

	this->setMinimumWidth(2048);
	this->setMinimumHeight(2048);
	this->m_board_image = QPixmap(":/pic/Resources/material/pic/paper.png");
	this->m_temp_image = QPixmap(":/pic/Resources/material/pic/paper.png");

	// �źŰ�
	this->connect(&this->m_mouse_edit, &QLineEdit::returnPressed, this, &WhiteBoard::endEdit);  // ��ӦQLineEdit�Ļس�
}

void WhiteBoard::setRubber(QPen rubber) {
	QCursor cursor;
	QPixmap cursor_pic;

	this->m_mouse_rubber = rubber;

	// �п��ܿ�ȱ仯�ˣ�����ָ���С
	if (this->m_mouse_tool_type == RUBBER) {
		cursor_pic = QPixmap(":/cursor/Resources/material/cursor/rubber.png");
		cursor_pic = cursor_pic.scaled(QSize(this->m_mouse_rubber.width(), this->m_mouse_rubber.width()));
		cursor = QCursor(cursor_pic, -1, -1);
		this->setCursor(cursor);
	}

	return;
}

void WhiteBoard::setToolType(ToolType tool_type) {
	QCursor cursor;
	QPixmap cursor_pic;

	this->m_mouse_tool_type = tool_type;

	switch (this->m_mouse_tool_type) {
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
		cursor_pic = cursor_pic.scaled(QSize(this->m_mouse_rubber.width(), this->m_mouse_rubber.width()));
		cursor = QCursor(cursor_pic, -1, -1);
		this->setCursor(cursor);
		break;
	}

	return;
}

void WhiteBoard::mouseClear() {
	this->m_board_image = QPixmap(":/pic/Resources/material/pic/paper.png");
	this->m_temp_image = QPixmap(":/pic/Resources/material/pic/paper.png");

	update();
	emit paintCommandReady(this->createPaintCommand(PaintType::Clear));

	return;
}

void WhiteBoard::mouseUndo() {
	if (!this->m_image_stack.isEmpty()) {
		this->m_board_image = this->m_image_stack.pop();  // ��һ������ջ
		update();
		emit paintCommandReady(this->createPaintCommand(PaintType::Undo));
	}

	return;
}

void WhiteBoard::commandClear() {
	this->m_board_image = QPixmap(":/pic/Resources/material/pic/paper.png");
	this->m_temp_image = QPixmap(":/pic/Resources/material/pic/paper.png");

	update();

	return;
}

void WhiteBoard::commandUndo() {
	if (!this->m_image_stack.isEmpty()) {
		this->m_board_image = this->m_image_stack.pop();  // ��һ������ջ
		update();
	}

	return;
}

void WhiteBoard::paintByPaintCommand(QJsonObject &paint_command) {
	PaintType paint_type = PaintType(paint_command["paint_type"].toInt());
	cv::Mat board_mat;

	bool is_command_drawing = paint_command["is_drawing"].toBool();

	// ����ͬ������
	this->m_command_tool_type = ToolType(paint_command["tool_type"].toInt());
	this->m_command_last_point = QPoint(paint_command["last_point_x"].toInt(), paint_command["last_point_y"].toInt());
	this->m_command_end_point = QPoint(paint_command["end_point_x"].toInt(), paint_command["end_point_y"].toInt());
	this->m_command_rubber.setWidth(paint_command["rubber_width"].toInt());
	this->m_command_pen.setWidth(paint_command["pen_width"].toInt());
	this->m_command_pen.setColor(paint_command["color"].toString().toUInt(nullptr, 16));
	this->m_command_edit.setGeometry(paint_command["edit_x"].toInt(), paint_command["edit_y"].toInt(), paint_command["edit_width"].toInt(), paint_command["edit_height"].toInt());
	this->m_command_edit.setText(paint_command["edit_text"].toString());

	switch (paint_type) {
	case Paint:
		// �������Ϊ���ʻ���Ƥ�ߣ�ֱ�ӻ��ڻ���
		if (this->m_command_tool_type == PEN || this->m_command_tool_type == RUBBER) {
			this->commandPaint(this->m_board_image);
		}
		// �����������ã�˫�����ͼ������Ҳ��˫���壬ֻ�ǲ��ѻ�ͼ������ʾ
		else {
			if (!is_command_drawing) {
				this->commandPaint(this->m_board_image);
			}
		}
		break;
	case Clear:
		this->commandClear();
		break;
	case Undo:
		this->commandUndo();
		break;
	case Push:
		this->m_image_stack.push(this->m_board_image);  // ��ǰ�����ջ����������
		break;
	}

	return;
}

void WhiteBoard::endEdit() {
	ToolType temp_tool_type = this->m_mouse_tool_type;  // �����ڴ˴ε��ǰѡ��Ĳ���

	if (this->m_is_typing) {
		this->m_mouse_tool_type = WhiteBoard::TEXT;  // ���л�Ϊ�ı�����
		this->mousePaint(this->m_board_image);  // ���ı����ڻ�����
		this->m_mouse_edit.hide();
		this->m_mouse_edit.clear();
		this->m_mouse_tool_type = temp_tool_type;
		this->m_is_typing = false;
	}

	return;
}

void WhiteBoard::mousePaint(QPixmap &image) {
	QPainter painter(&image); // ��ͼ����image(image��painterDevice���Ͳ��������������ã���ʵ���ǻ���image��)
	QPoint last_point = this->m_mouse_last_point, end_point = this->m_mouse_end_point;


	painter.setRenderHint(QPainter::Antialiasing, true);  // �����

	if (this->m_mouse_tool_type == RUBBER) {
		painter.setPen(this->m_mouse_rubber);
	}
	else {
		painter.setPen(this->m_mouse_pen);
	}

	switch (this->m_mouse_tool_type) {
	case PEN:
	case RUBBER:
		painter.drawLine(this->m_mouse_last_point, this->m_mouse_end_point);  // ���ߣ���������ƶ��¼�����ô˺��������lastPoint��endPoint������Ϊ0����˿ɽ��ƿ��ɻ��㣬�����������ǻ��ʵĺۼ���
		//this->m_mouse_last_point = this->m_mouse_end_point;  // ���յ㸴�Ƹ����
		break;
	case LINE:
		painter.drawLine(this->m_mouse_last_point, this->m_mouse_end_point);
		break;
	case RECT:
		painter.drawRect(this->m_mouse_last_point.x(), this->m_mouse_last_point.y(), this->m_mouse_end_point.x() - this->m_mouse_last_point.x(), this->m_mouse_end_point.y() - this->m_mouse_last_point.y());
		break;
	case ELLIPSE:
		painter.drawEllipse(this->m_mouse_last_point.x(), this->m_mouse_last_point.y(), this->m_mouse_end_point.x() - this->m_mouse_last_point.x(), this->m_mouse_end_point.y() - this->m_mouse_last_point.y());
		break;
	case TEXT:
		painter.setFont(this->m_mouse_edit.font());
		painter.drawText(this->m_mouse_edit.x(), this->m_mouse_edit.y() + (this->m_mouse_edit.height() / 1.35), this->m_mouse_edit.text());
	}

	update();  // ˢ��
	emit paintCommandReady(this->createPaintCommand(PaintType::Paint));
	if (this->m_mouse_tool_type == PEN || this->m_mouse_tool_type == RUBBER) {
		this->m_mouse_last_point = this->m_mouse_end_point;  // ���յ㸴�Ƹ����
	}

	return;
}

void WhiteBoard::commandPaint(QPixmap &image) {
	QPainter painter(&image); // ��ͼ����image(image��painterDevice���Ͳ��������������ã���ʵ���ǻ���image��)
	QPoint last_point = this->m_command_last_point, end_point = this->m_command_end_point;


	painter.setRenderHint(QPainter::Antialiasing, true);  // �����

	if (this->m_command_tool_type == RUBBER) {
		painter.setPen(this->m_command_rubber);
	}
	else {
		painter.setPen(this->m_command_pen);
	}

	switch (this->m_command_tool_type) {
	case PEN:
	case RUBBER:
		painter.drawLine(this->m_command_last_point, this->m_command_end_point);  // ���ߣ���������ƶ��¼�����ô˺��������lastPoint��endPoint������Ϊ0����˿ɽ��ƿ��ɻ��㣬�����������ǻ��ʵĺۼ���
		//this->m_command_last_point = this->m_command_end_point;  // ���յ㸴�Ƹ����
		break;
	case LINE:
		painter.drawLine(this->m_command_last_point, this->m_command_end_point);
		break;
	case RECT:
		painter.drawRect(this->m_command_last_point.x(), this->m_command_last_point.y(), this->m_command_end_point.x() - this->m_command_last_point.x(), this->m_command_end_point.y() - this->m_command_last_point.y());
		break;
	case ELLIPSE:
		painter.drawEllipse(this->m_command_last_point.x(), this->m_command_last_point.y(), this->m_command_end_point.x() - this->m_command_last_point.x(), this->m_command_end_point.y() - this->m_command_last_point.y());
		break;
	case TEXT:
		painter.setFont(this->m_command_edit.font());
		painter.drawText(this->m_command_edit.x(), this->m_command_edit.y() + (this->m_command_edit.height() / 1.35), this->m_command_edit.text());
	}

	update();  // ˢ��

	if (this->m_command_tool_type == PEN || this->m_command_tool_type == RUBBER) {
		this->m_command_last_point = this->m_command_end_point;  // ���յ㸴�Ƹ����
	}

	return;
}

QJsonObject WhiteBoard::createPaintCommand(PaintType paint_type) {
	QJsonObject paint_command;

	paint_command["paint_type"] = paint_type;
	paint_command["tool_type"] = this->m_mouse_tool_type;
	paint_command["last_point_x"] = this->m_mouse_last_point.x();
	paint_command["last_point_y"] = this->m_mouse_last_point.y();
	paint_command["end_point_x"] = this->m_mouse_end_point.x();
	paint_command["end_point_y"] = this->m_mouse_end_point.y();
	paint_command["rubber_width"] = this->m_mouse_rubber.width();
	paint_command["pen_width"] = this->m_mouse_pen.width();
	paint_command["color"] = QString::number(qRgb(this->m_mouse_pen.color().red(), this->m_mouse_pen.color().green(), this->m_mouse_pen.color().blue()), 16);
	paint_command["edit_x"] = this->m_mouse_edit.x();
	paint_command["edit_y"] = this->m_mouse_edit.y();
	paint_command["edit_width"] = this->m_mouse_edit.width();
	paint_command["edit_height"] = this->m_mouse_edit.height();
	paint_command["edit_text"] = this->m_mouse_edit.text();
	paint_command["is_drawing"] = this->m_mouse_is_drawing;

	return paint_command;
}

void WhiteBoard::paintEvent(QPaintEvent *event) {
	QPainter painter(this);
	if (this->m_mouse_is_drawing == true) {
		// ������ڻ�ͼ������������������ƶ�������temp_image��
		painter.drawPixmap(0, 0, this->m_temp_image);
	}
	else {
		// �����ڻ�����
		painter.drawPixmap(0, 0, this->m_board_image);
	}

	return;
}

void WhiteBoard::mousePressEvent(QMouseEvent *event) {
	this->m_image_stack.push(this->m_board_image);  // ��ǰ�����ջ����������
	emit paintCommandReady(this->createPaintCommand(PaintType::Push));

	// ��갴����Ϊ���
	if (event->button() == Qt::LeftButton) {
		// �����δ��ɵ�ͼƬ���ı��Ȳ������Ƚ��������ڻ�����
		this->endEdit();

		// ���ѡ����ǡ������ı��������Ȳ���ͼ
		if (this->m_mouse_tool_type == TEXT) {
			this->m_is_typing = true;
			// �����λ����ʾһ���ı���
			this->m_mouse_edit.setGeometry(event->pos().x(), event->pos().y(), 100, 25);
			this->m_mouse_edit.setParent(this);
			this->m_mouse_edit.show();
			this->m_mouse_edit.setFocus();
		}
		else {
			this->m_mouse_last_point = event->pos();  // �������Ϊ��갴�µĵ�
			this->m_mouse_end_point = event->pos();  // �����յ�Ϊ��갴�µĵ�
			this->m_mouse_is_drawing = true;  // ��ʼ��ͼ
		}
	}

	return;
}

void WhiteBoard::mouseMoveEvent(QMouseEvent *event) {
	if (event->buttons() & Qt::LeftButton) {  // ��갴��������ƶ�
		this->m_mouse_end_point = event->pos();  // ���ÿ�ƶ�һ�ζ�ˢ���յ�
		this->m_temp_image = this->m_board_image;

		// ���Ϊ���ʻ���Ƥ�ߣ�ֱ�ӻ��ڻ���
		if (this->m_mouse_tool_type == PEN || this->m_mouse_tool_type == RUBBER) {
			this->mousePaint(this->m_board_image);
		}
		// ��������˫�����ͼ
		else {
			this->mousePaint(this->m_temp_image);
		}

	}

	return;
}

void WhiteBoard::mouseReleaseEvent(QMouseEvent *event) {
	this->m_mouse_is_drawing = false; // ��ͼ���
	this->mousePaint(this->m_board_image); // �����һ�㻭��image������

	return;
}