#include "WhiteBoard.h"

WhiteBoard::WhiteBoard(QWidget *parent) : QWidget(parent) {
	// 初始化
	this->m_is_typing = false;

	this->m_mouse_is_drawing = false;
	this->m_mouse_tool_type = PEN;
	this->m_mouse_rubber.setBrush(QPixmap(":/pic/Resources/material/pic/paper.png"));
	this->m_mouse_pen.setCapStyle(Qt::RoundCap);  // 末端圆形（都是为了抗锯齿）
	this->m_mouse_pen.setJoinStyle(Qt::RoundJoin);  // 连接处圆形
	this->m_mouse_rubber.setCapStyle(Qt::RoundCap);
	this->m_mouse_rubber.setJoinStyle(Qt::RoundJoin);

	this->m_command_is_drawing = false;
	this->m_command_tool_type = PEN;
	this->m_command_rubber.setBrush(QPixmap(":/pic/Resources/material/pic/paper.png"));
	this->m_command_pen.setCapStyle(Qt::RoundCap);  // 末端圆形（都是为了抗锯齿）
	this->m_command_pen.setJoinStyle(Qt::RoundJoin);  // 连接处圆形
	this->m_command_rubber.setCapStyle(Qt::RoundCap);
	this->m_command_rubber.setJoinStyle(Qt::RoundJoin);

	this->setMinimumWidth(2048);
	this->setMinimumHeight(2048);
	this->m_board_image = QPixmap(":/pic/Resources/material/pic/paper.png");
	this->m_temp_image = QPixmap(":/pic/Resources/material/pic/paper.png");

	// 信号绑定
	this->connect(&this->m_mouse_edit, &QLineEdit::returnPressed, this, &WhiteBoard::endEdit);  // 响应QLineEdit的回车
}

void WhiteBoard::setRubber(QPen rubber) {
	QCursor cursor;
	QPixmap cursor_pic;

	this->m_mouse_rubber = rubber;

	// 有可能宽度变化了，调整指针大小
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
		this->m_board_image = this->m_image_stack.pop();  // 上一操作出栈
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
		this->m_board_image = this->m_image_stack.pop();  // 上一操作出栈
		update();
	}

	return;
}

void WhiteBoard::paintByPaintCommand(QJsonObject &paint_command) {
	PaintType paint_type = PaintType(paint_command["paint_type"].toInt());
	cv::Mat board_mat;

	bool is_command_drawing = paint_command["is_drawing"].toBool();

	// ——同步属性
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
		// ——如果为画笔或橡皮檫，直接画在画板
		if (this->m_command_tool_type == PEN || this->m_command_tool_type == RUBBER) {
			this->commandPaint(this->m_board_image);
		}
		// ——否则启用（双缓冲绘图）这里也不双缓冲，只是不把画图过程显示
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
		this->m_image_stack.push(this->m_board_image);  // 当前画板进栈，撤销备用
		break;
	}

	return;
}

void WhiteBoard::endEdit() {
	ToolType temp_tool_type = this->m_mouse_tool_type;  // 保存在此次点击前选择的操作

	if (this->m_is_typing) {
		this->m_mouse_tool_type = WhiteBoard::TEXT;  // 先切换为文本工具
		this->mousePaint(this->m_board_image);  // 把文本绘在画板上
		this->m_mouse_edit.hide();
		this->m_mouse_edit.clear();
		this->m_mouse_tool_type = temp_tool_type;
		this->m_is_typing = false;
	}

	return;
}

void WhiteBoard::mousePaint(QPixmap &image) {
	QPainter painter(&image); // 把图画在image(image是painterDevice类型参数，由于是引用，其实就是画在image上)
	QPoint last_point = this->m_mouse_last_point, end_point = this->m_mouse_end_point;


	painter.setRenderHint(QPainter::Antialiasing, true);  // 抗锯齿

	if (this->m_mouse_tool_type == RUBBER) {
		painter.setPen(this->m_mouse_rubber);
	}
	else {
		painter.setPen(this->m_mouse_pen);
	}

	switch (this->m_mouse_tool_type) {
	case PEN:
	case RUBBER:
		painter.drawLine(this->m_mouse_last_point, this->m_mouse_end_point);  // 画线，由于鼠标移动事件会调用此函数，因此lastPoint和endPoint相距近似为0，因此可近似看成画点，点连起来就是画笔的痕迹了
		//this->m_mouse_last_point = this->m_mouse_end_point;  // 把终点复制给起点
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

	update();  // 刷新
	emit paintCommandReady(this->createPaintCommand(PaintType::Paint));
	if (this->m_mouse_tool_type == PEN || this->m_mouse_tool_type == RUBBER) {
		this->m_mouse_last_point = this->m_mouse_end_point;  // 把终点复制给起点
	}

	return;
}

void WhiteBoard::commandPaint(QPixmap &image) {
	QPainter painter(&image); // 把图画在image(image是painterDevice类型参数，由于是引用，其实就是画在image上)
	QPoint last_point = this->m_command_last_point, end_point = this->m_command_end_point;


	painter.setRenderHint(QPainter::Antialiasing, true);  // 抗锯齿

	if (this->m_command_tool_type == RUBBER) {
		painter.setPen(this->m_command_rubber);
	}
	else {
		painter.setPen(this->m_command_pen);
	}

	switch (this->m_command_tool_type) {
	case PEN:
	case RUBBER:
		painter.drawLine(this->m_command_last_point, this->m_command_end_point);  // 画线，由于鼠标移动事件会调用此函数，因此lastPoint和endPoint相距近似为0，因此可近似看成画点，点连起来就是画笔的痕迹了
		//this->m_command_last_point = this->m_command_end_point;  // 把终点复制给起点
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

	update();  // 刷新

	if (this->m_command_tool_type == PEN || this->m_command_tool_type == RUBBER) {
		this->m_command_last_point = this->m_command_end_point;  // 把终点复制给起点
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
		// 如果正在绘图，既鼠标点击或者正在移动，画在temp_image上
		painter.drawPixmap(0, 0, this->m_temp_image);
	}
	else {
		// 否则画在画板上
		painter.drawPixmap(0, 0, this->m_board_image);
	}

	return;
}

void WhiteBoard::mousePressEvent(QMouseEvent *event) {
	this->m_image_stack.push(this->m_board_image);  // 当前画板进栈，撤销备用
	emit paintCommandReady(this->createPaintCommand(PaintType::Push));

	// 鼠标按下且为左键
	if (event->button() == Qt::LeftButton) {
		// 如果有未完成的图片、文本等操作，先结束并绘在画板上
		this->endEdit();

		// 如果选择的是“插入文本”，则先不绘图
		if (this->m_mouse_tool_type == TEXT) {
			this->m_is_typing = true;
			// 在鼠标位置显示一个文本框
			this->m_mouse_edit.setGeometry(event->pos().x(), event->pos().y(), 100, 25);
			this->m_mouse_edit.setParent(this);
			this->m_mouse_edit.show();
			this->m_mouse_edit.setFocus();
		}
		else {
			this->m_mouse_last_point = event->pos();  // 设置起点为鼠标按下的点
			this->m_mouse_end_point = event->pos();  // 设置终点为鼠标按下的点
			this->m_mouse_is_drawing = true;  // 开始绘图
		}
	}

	return;
}

void WhiteBoard::mouseMoveEvent(QMouseEvent *event) {
	if (event->buttons() & Qt::LeftButton) {  // 鼠标按下左键并移动
		this->m_mouse_end_point = event->pos();  // 鼠标每移动一次都刷新终点
		this->m_temp_image = this->m_board_image;

		// 如果为画笔或橡皮檫，直接画在画板
		if (this->m_mouse_tool_type == PEN || this->m_mouse_tool_type == RUBBER) {
			this->mousePaint(this->m_board_image);
		}
		// 否则启用双缓冲绘图
		else {
			this->mousePaint(this->m_temp_image);
		}

	}

	return;
}

void WhiteBoard::mouseReleaseEvent(QMouseEvent *event) {
	this->m_mouse_is_drawing = false; // 绘图完毕
	this->mousePaint(this->m_board_image); // 把最后一点画在image画布上

	return;
}