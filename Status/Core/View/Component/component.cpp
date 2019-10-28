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

	// ——动画
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

	// ——信号绑定
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
	// ——获取文本长度
	this->adjustSize();
	text_width = this->width();
	text_height = this->height();
	// ——重新设置大小和位置
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
	// 初始化
	this->m_is_drawing = false;
	this->m_is_typing = false;
	this->m_tool_type = PEN;
	this->m_rubber.setBrush(QPixmap(":/pic/Resources/material/pic/paper.png"));
	this->m_pen.setCapStyle(Qt::RoundCap);  // 末端圆形（都是为了抗锯齿）
	this->m_pen.setJoinStyle(Qt::RoundJoin);  // 连接处圆形
	this->m_rubber.setCapStyle(Qt::RoundCap);
	this->m_rubber.setJoinStyle(Qt::RoundJoin);

	this->setMinimumWidth(2048);
	this->setMinimumHeight(2048);
	this->m_board_image = QPixmap(":/pic/Resources/material/pic/paper.png");
	this->m_temp_image = QPixmap(":/pic/Resources/material/pic/paper.png");

	// 信号绑定
	this->connect(&this->m_edit, &QLineEdit::returnPressed, this, &PaintWidget::endEdit);  // 响应QLineEdit的回车
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

	// 有可能宽度变化了，调整指针大小
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
	清空画板
*/
void PaintWidget::clear() {
	this->m_board_image = QPixmap(":/pic/Resources/material/pic/paper.png");
	this->m_temp_image = QPixmap(":/pic/Resources/material/pic/paper.png");

	update();
	emit paintCommandReady(this->createPaintCommand(PaintType::Clear));

	return;
}

/*
	撤销操作
*/
void PaintWidget::undo() {
	if (!this->m_image_stack.isEmpty()) {
		this->m_board_image = this->m_image_stack.pop();  // 上一操作出栈
		update();
		emit paintCommandReady(this->createPaintCommand(PaintType::Undo));
	}

	return;
}


/*
	以paint_command绘图
*/
void PaintWidget::paintByPaintCommand(QJsonObject &paint_command) {
	PaintType paint_type = PaintType(paint_command["paint_type"].toInt());
	bool is_drawing = paint_command["is_drawing"].toBool();

	// ——同步属性
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
		// ——如果为画笔或橡皮檫，直接画在画板
		if (this->m_tool_type == PEN || this->m_tool_type == RUBBER) {
			this->paint(this->m_board_image);
		}
		// ——否则启用（双缓冲绘图）这里也不双缓冲，只是不把画图过程显示
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
		this->m_image_stack.push(this->m_board_image);  // 当前画板进栈，撤销备用
		break;
	}

	return;
}

/*
	结束图片、文字编辑
*/
void PaintWidget::endEdit() {
	ToolType temp_tool_type = this->m_tool_type;  // 保存在此次点击前选择的操作

	if (this->m_is_typing) {
		this->m_tool_type = PaintWidget::TEXT;  // 先切换为文本工具
		this->paint(this->m_board_image);  // 把文本绘在画板上
		this->m_edit.hide();
		this->m_edit.clear();
		this->m_tool_type = temp_tool_type;
		this->m_is_typing = false;
	}
	
	return;
}

/*
	(画图函数)调用这个函数就是调用重绘函数，把图画在image上
*/
void PaintWidget::paint(QPixmap &image) {
	QPainter painter(&image); // 把图画在image(image是painterDevice类型参数，由于是引用，其实就是画在image上)
	QPoint last_point = this->m_last_point, end_point = this->m_end_point;


	painter.setRenderHint(QPainter::Antialiasing, true);  // 抗锯齿

	if (this->m_tool_type == RUBBER) {
		painter.setPen(this->m_rubber);
	}
	else {
		painter.setPen(this->m_pen);
	}

	switch (this->m_tool_type) {
	case PEN:
	case RUBBER:
		painter.drawLine(this->m_last_point, this->m_end_point);  // 画线，由于鼠标移动事件会调用此函数，因此lastPoint和endPoint相距近似为0，因此可近似看成画点，点连起来就是画笔的痕迹了
		//this->m_last_point = this->m_end_point;  // 把终点复制给起点
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

	update();  // 刷新
	emit paintCommandReady(this->createPaintCommand(PaintType::Paint));
	if (this->m_tool_type == PEN || this->m_tool_type == RUBBER) {
		this->m_last_point = this->m_end_point;  // 把终点复制给起点
	}

	return;
}

/*
	创建paint_command
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
	绘图函数
	通过update()触发
*/
void PaintWidget::paintEvent(QPaintEvent *event) {
	QPainter painter(this);
	if (this->m_is_drawing == true) {
		// 如果正在绘图，既鼠标点击或者正在移动，画在temp_image上
		painter.drawPixmap(0, 0, this->m_temp_image);
	}
	else {
		// 否则画在画板上
		painter.drawPixmap(0, 0, this->m_board_image);
	}

	return;
}

/*
	重写鼠标点击事件
	只处理鼠标左键的点击
*/
void PaintWidget::mousePressEvent(QMouseEvent *event) {	
	this->m_image_stack.push(this->m_board_image);  // 当前画板进栈，撤销备用
	emit paintCommandReady(this->createPaintCommand(PaintType::Push));
	
	// 鼠标按下且为左键
	if (event->button() == Qt::LeftButton) {
		// 如果有未完成的图片、文本等操作，先结束并绘在画板上
		this->endEdit();

		// 如果选择的是“插入文本”，则先不绘图
		if (this->m_tool_type == TEXT) {
			this->m_is_typing = true;
			// 在鼠标位置显示一个文本框
			this->m_edit.setGeometry(event->pos().x(), event->pos().y(), 100, 25);
			this->m_edit.setParent(this);
			this->m_edit.show();
			this->m_edit.setFocus();
		}
		else {
			this->m_last_point = event->pos();  // 设置起点为鼠标按下的点
			this->m_end_point = event->pos();  // 设置终点为鼠标按下的点
			this->m_is_drawing = true;  // 开始绘图
		}	
	}

	return;
}

/*
	重写鼠标移动事件
*/
void PaintWidget::mouseMoveEvent(QMouseEvent *event) {
	if (event->buttons() & Qt::LeftButton) {  // 鼠标按下左键并移动
		this->m_end_point = event->pos();  // 鼠标每移动一次都刷新终点
		this->m_temp_image = this->m_board_image;

		// 如果为画笔或橡皮檫，直接画在画板
		if (this->m_tool_type == PEN || this->m_tool_type == RUBBER) {
			this->paint(this->m_board_image);
		}
		// 否则启用双缓冲绘图
		else {
			this->paint(this->m_temp_image);
		}
		
	}

	return;
}


/*
	重写鼠标释放事件
*/
void PaintWidget::mouseReleaseEvent(QMouseEvent *event) {
	this->m_is_drawing = false; // 绘图完毕
	this->paint(this->m_board_image); // 把最后一点画在image画布上

	return;
}


//**************************************************************************************************
//**************************************************************************************************


LineEdit::LineEdit(QLineEdit *parent) {
	this->is_pressed = false;
	QFont font = this->font();

	font.setFamily("微软雅黑");
	font.setPointSize(12);
	this->setFont(font);
	this->resize(100, 25);
	this->setStyleSheet("border: 2px dashed  #000000;");

	// 信号绑定
	this->connect(this, &QLineEdit::textChanged, this, &LineEdit::adjustTextLengthAndSize);
}

/*
	自适应文本的大小与长度
*/
void LineEdit::adjustTextLengthAndSize() {

	QFont font = this->font();  // 获取文本框字体
	QString text = this->text();  // 获取文本框文本内容
	QFontMetrics fm(font);  // 计算字体的高度和宽度（px）
	QRect rect = fm.boundingRect(text);

	this->resize(rect.width() + 10, rect.height() + 10);

	return;
}

/*
	重写鼠标事件
	用于控件拖动
*/
void LineEdit::mouseDoubleClickEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton) {
		this->setCursor(Qt::SizeAllCursor);  // 更改鼠标样式
		this->is_pressed = true;
		this->start_pos = QPoint(event->pos().x(), event->pos().y());
	}

	return;
}

void LineEdit::mouseMoveEvent(QMouseEvent *event) {
	// 计算鼠标当前位置
	// 如果鼠标左键按下，则执行移动
	if (this->is_pressed) {
		this->move(this->pos() + event->pos() - this->start_pos);
	}

	return;
}

void LineEdit::mouseReleaseEvent(QMouseEvent *event) {
	this->setCursor(Qt::ArrowCursor);  // 恢复鼠标样式
	this->is_pressed = false;

	return;
}


//**************************************************************************************************
//**************************************************************************************************

