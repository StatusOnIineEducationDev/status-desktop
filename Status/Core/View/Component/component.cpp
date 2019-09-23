#include "component.h"

PaintWidget::PaintWidget(QWidget *parent) : QWidget(parent) {
	// 初始化
	this->is_drawing = false;
	this->is_texting = false;
	this->tool_type = PEN;
	this->rubber.setBrush(QImage(":/pic/Resources/material/pic/paper.png"));
	this->pen.setCapStyle(Qt::RoundCap);  // 末端圆形（都是为了抗锯齿）
	this->pen.setJoinStyle(Qt::RoundJoin);  // 连接处圆形
	this->rubber.setCapStyle(Qt::RoundCap);
	this->rubber.setJoinStyle(Qt::RoundJoin);

	this->setMinimumWidth(2048);
	this->setMinimumHeight(2048);
	this->board_image = QImage(":/pic/Resources/material/pic/paper.png");
	this->temp_image = QImage(":/pic/Resources/material/pic/paper.png");

	// 信号绑定
	this->connect(&this->edit, &QLineEdit::returnPressed, this, &PaintWidget::endEdit);  // 响应QLineEdit的回车
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

	// 有可能宽度变化了，调整指针大小
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
	清空画板
*/
void PaintWidget::clear() {
	this->board_image = QImage(":/pic/Resources/material/pic/paper.png");
	this->temp_image = QImage(":/pic/Resources/material/pic/paper.png");

	update();

	return;
}

/*
	撤销操作
*/
void PaintWidget::undo() {
	if (!this->image_stack.isEmpty()) {
		this->board_image = this->image_stack.pop();  // 上一操作出栈
		update();
	}

	return;
}


/*
	结束图片、文字编辑
*/
void PaintWidget::endEdit() {
	ToolType temp_tool_type = this->tool_type;  // 保存在此次点击前选择的操作

	if (this->is_texting) {
		this->tool_type = PaintWidget::TEXT;  // 先切换为文本工具
		this->paint(this->board_image);  // 把文本绘在画板上
		this->edit.hide();
		this->edit.clear();
		this->tool_type = temp_tool_type;
		this->is_texting = false;
	}
	
	return;
}

/*
	(画图函数)调用这个函数就是调用重绘函数，把图画在image上
*/
void PaintWidget::paint(QImage &image) {
	QPainter painter(&image); // 把图画在image(image是painterDevice类型参数，由于是引用，其实就是画在image上)
	painter.setRenderHint(QPainter::Antialiasing, true);  // 抗锯齿

	if (this->tool_type == RUBBER) {
		painter.setPen(this->rubber);
	}
	else {
		painter.setPen(this->pen);
	}

	switch (this->tool_type) {
	case PEN:
	case RUBBER:
		painter.drawLine(this->last_point, this->end_point);  // 画线，由于鼠标移动事件会调用此函数，因此lastPoint和endPoint相距近似为0，因此可近似看成画点，点连起来就是画笔的痕迹了
		this->last_point = this->end_point;  // 把终点复制给起点
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

	update();  // 刷新
}


/*
	绘图函数
	通过update()触发
*/
void PaintWidget::paintEvent(QPaintEvent *event) {
	QPainter painter(this);
	if (this->is_drawing == true) {
		// 如果正在绘图，既鼠标点击或者正在移动，画在temp_image上
		painter.drawImage(0, 0, this->temp_image);  
	}
	else {
		// 否则画在画板上
		painter.drawImage(0, 0, this->board_image);  
	}
}

/*
	重写鼠标点击事件
	只处理鼠标左键的点击
*/
void PaintWidget::mousePressEvent(QMouseEvent *event) {	
	this->image_stack.push(this->board_image);  // 当前画板进栈，撤销备用
	
	// 鼠标按下且为左键
	if (event->button() == Qt::LeftButton) {
		// 如果有未完成的图片、文本等操作，先结束并绘在画板上
		this->endEdit();

		// 如果选择的是“插入文本”，则先不绘图
		if (this->tool_type == TEXT) {
			this->is_texting = true;
			// 在鼠标位置显示一个文本框
			this->edit.setGeometry(event->pos().x(), event->pos().y(), 100, 25);
			this->edit.setParent(this);
			this->edit.show();
			this->edit.setFocus();
		}
		else {
			this->last_point = event->pos();  // 设置起点为鼠标按下的点
			this->end_point = event->pos();  // 设置终点为鼠标按下的点
			this->is_drawing = true;  // 开始绘图
		}	
	}

	return;
}

/*
	重写鼠标移动事件
*/
void PaintWidget::mouseMoveEvent(QMouseEvent *event) { //重点理解部分

	if (event->buttons() & Qt::LeftButton) {//-------------------------鼠标按下左键并移动
		this->end_point = event->pos();//-----------------------------------鼠标每移动一次都刷新终点
		this->temp_image = this->board_image;

		// 如果为画笔或橡皮檫，直接画在画板
		if (this->tool_type == PEN || this->tool_type == RUBBER) {
			this->paint(this->board_image);
		}
		// 否则启用双缓冲绘图
		else {
			this->paint(this->temp_image);
		}
		
	}

	return;
}


/*
	重写鼠标释放事件
*/
void PaintWidget::mouseReleaseEvent(QMouseEvent *event) {
	this->is_drawing = false; // 绘图完毕
	this->paint(this->board_image); // 把最后一点画在image画布上

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

AreaChart::AreaChart(QLineSeries *series) {
	//this->m_series = series;
	QPen pen(QColor(131, 105, 203), 2);
	QFont font("微软雅黑", 10);

	this->m_series = new QLineSeries();
	this->m_series->setPen(pen);
	*this->m_series << QPointF(1, 59) << QPointF(3, 77) << QPointF(7, 64) << QPointF(9, 75) << QPointF(12, 62) << QPointF(16, 72) << QPointF(18, 54);

	this->m_area_series = new QAreaSeries(this->m_series);  // 创建面积
	QColor a = this->m_series->color();
	a.setAlpha(100);

	this->m_area_series->setBrush(a);

	this->addSeries(m_area_series);  // 添加面积
	this->addSeries(m_series);  // 添加线（这两个顺序不可调换，必须先添加面积再添加描线，要保证描线绘在面积之上）


	this->setMargins(QMargins(0, 0, 0, 0));  // 设置外边距为0
	this->legend()->setVisible(false);  // 隐藏图例

	// 坐标轴初始化
	this->createDefaultAxes();  // 创建坐标轴
	this->axisX()->setLabelsFont(font);
	this->axisX()->setLabelsColor(QColor(153, 153, 153));
	this->axisX()->setLabelsFont(font);
	this->axisX()->setRange(0, this->m_series->points().constLast().x() + 1);
	this->axisY()->setLabelsFont(font);
	this->axisY()->setLabelsColor(QColor(153, 153, 153));
	this->axisY()->setLabelsFont(font);
	this->axisY()->setRange(0, 100);
}