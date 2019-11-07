#include "sonlineclassroomwidget.h"

const int PEN_WIDTH = 3;
const int RUBBER_WIDTH = 20;

SOnlineClassroomWidget::SOnlineClassroomWidget(SMainWindow *parent) : QWidget(parent) {
	m_ui.setupUi(this);
	m_ui.function_tabWidget->setAttribute(Qt::WA_StyledBackground);  // tab栏显示背景色
	this->connect(parent, &SMainWindow::windowResized, this, &SOnlineClassroomWidget::handleWindowResized);

	QScrollArea *scroll_area;
	QPen pen, rubber;

	// 信号绑定
	this->connect(this->m_ui.pen_width_slider, &QSlider::valueChanged, this, &SOnlineClassroomWidget::setPenWidth);
	this->connect(this->m_ui.rubber_width_slider, &QSlider::valueChanged, this, &SOnlineClassroomWidget::setRubberWidth);
	this->connect(this->m_ui.pen_width_edit, &QLineEdit::textEdited, this, &SOnlineClassroomWidget::setPenSlider);  // 程序改变值时，不触发信号
	this->connect(this->m_ui.rubber_width_edit, &QLineEdit::textEdited, this, &SOnlineClassroomWidget::setRubberSlider);
	this->connect(this->m_ui.black_pen_btn, &QPushButton::clicked, this, &SOnlineClassroomWidget::chooseBlackPen);
	this->connect(this->m_ui.blue_pen_btn, &QPushButton::clicked, this, &SOnlineClassroomWidget::chooseBluePen);
	this->connect(this->m_ui.red_pen_btn, &QPushButton::clicked, this, &SOnlineClassroomWidget::chooseRedPen);
	this->connect(this->m_ui.color_pen_btn, &QPushButton::clicked, this, &SOnlineClassroomWidget::chooseColorPen);
	this->connect(this->m_ui.text_btn, &QPushButton::clicked, this, &SOnlineClassroomWidget::chooseText);
	this->connect(this->m_ui.rubber_btn, &QPushButton::clicked, this, &SOnlineClassroomWidget::chooseRubber);
	this->connect(this->m_ui.line_btn, &QPushButton::clicked, this, &SOnlineClassroomWidget::chooseLine);
	this->connect(this->m_ui.rect_btn, &QPushButton::clicked, this, &SOnlineClassroomWidget::chooseRect);
	this->connect(this->m_ui.ellipse_btn, &QPushButton::clicked, this, &SOnlineClassroomWidget::chooseEllipse);
	this->connect(this->m_ui.undo_btn, &QPushButton::clicked, this, &SOnlineClassroomWidget::undo);
	this->connect(this->m_ui.clear_btn, &QPushButton::clicked, this, &SOnlineClassroomWidget::clear);
	this->connect(this->m_ui.add_board_btn, &QPushButton::clicked, this, &SOnlineClassroomWidget::addBoard);
	this->connect(this->m_ui.board_tabWidget, &QTabWidget::tabCloseRequested, this, &SOnlineClassroomWidget::deleteBoard);
	this->connect(this->m_ui.board_tabWidget, &QTabWidget::currentChanged, this, &SOnlineClassroomWidget::changeBoard);

	// 初始化
	scroll_area = new QScrollArea();

	this->m_board_id = 1;

	this->m_board = new WhiteBoard();  // 先创建一个画板
	this->m_board_list.append(this->m_board);  // 加入链表之中
	scroll_area->setWidget(this->m_board);
	scroll_area->setStyleSheet("QScrollArea{border:none;background-color:transparent;}QScrollBar:vertical{border:none;background-color:#ffffff;width:10px;}QScrollBar:vertical:hover{border:none;background-color:rgb(220,220,220);width:10px;}QScrollBar::handle:vertical{border-radius:5px;background:rgb(220,220,220);min-height:20px;}QScrollBar::handle:vertical:hover{border-radius:5px;background:rgb(200,200,200);min-height:20px;}QScrollBar::add-line:vertical{height:0;subcontrol-position:bottom;subcontrol-origin:margin;}QScrollBar::sub-line:vertical{height:0px;subcontrol-position:top;subcontrol-origin:margin;}QScrollBar:horizontal{border:none;background-color:#ffffff;height:10px;}QScrollBar:horizontal:hover{border:none;background-color:rgb(220,220,220);height:10px;}QScrollBar::handle:horizontal{border-radius:5px;background:rgb(220,220,220);min-width:20px;}QScrollBar::handle:horizontal:hover{border-radius:5px;background:rgb(200,200,200);min-width:20px;}QScrollBar::add-line:horizontal{width:0;subcontrol-position:bottom;subcontrol-origin:margin;}QScrollBar::sub-line:horizontal{width:0px;subcontrol-position:top;subcontrol-origin:margin;}");
	this->m_ui.board_tabWidget->addTab(scroll_area, "board_1");  // 添加一个画板
	this->m_ui.black_pen_btn->click();  // 默认为黑笔，模拟点击
	// 画笔、橡皮檫默认宽度
	pen = this->m_board->getPen();
	pen.setWidth(PEN_WIDTH);
	this->m_board->setPen(pen);
	this->m_ui.pen_width_slider->setValue(PEN_WIDTH);
	this->m_ui.pen_width_edit->setText(QString::number(PEN_WIDTH));

	rubber = this->m_board->getRubber();
	rubber.setWidth(RUBBER_WIDTH);
	this->m_board->setRubber(rubber);
	this->m_ui.rubber_width_slider->setValue(RUBBER_WIDTH);
	this->m_ui.rubber_width_edit->setText(QString::number(RUBBER_WIDTH));
}

SOnlineClassroomWidget::~SOnlineClassroomWidget() {
	for (int index = 0; index < this->m_board_list.count(); index++) {
		if (this->m_board_list[index] != nullptr) {
			delete this->m_board_list[index];
		}
	}
}

/*
	调整画笔粗细
	value-qslider传回的值
*/
void SOnlineClassroomWidget::setPenWidth(int value) {
	QPen pen = this->m_board->getPen();

	this->m_ui.pen_width_edit->setText(QString::number(value));
	pen.setWidth(value);
	this->m_board->setPen(pen);

	return;
}

/*
	调整pen_slider
*/
void SOnlineClassroomWidget::setPenSlider() {
	QString text = this->m_ui.pen_width_edit->text();
	int value = text.toInt();

	// 数值溢出处理
	if (value > 99) {
		this->m_ui.pen_width_edit->setText("99");
	}
	if (value < 1) {
		this->m_ui.pen_width_edit->setText("1");
	}

	this->m_ui.pen_width_slider->setValue(text.toInt());

	return;
}

/*
	调整橡皮檫粗细
	value-qslider传回的值
*/
void SOnlineClassroomWidget::setRubberWidth(int value) {
	QPen rubber = this->m_board->getRubber();

	this->m_ui.rubber_width_edit->setText(QString::number(value));
	rubber.setWidth(value);
	this->m_board->setRubber(rubber);

	return;
}

/*
	调整rubber_slider
*/
void SOnlineClassroomWidget::setRubberSlider() {
	QString text = this->m_ui.rubber_width_edit->text();
	int value = text.toInt();

	// 数值溢出处理
	if (value > 99) {
		this->m_ui.rubber_width_edit->setText("99");
	}
	if (value < 1) {
		this->m_ui.rubber_width_edit->setText("1");
	}

	this->m_ui.rubber_width_slider->setValue(text.toInt());

	return;
}

/*
	选择黑色画笔
*/
void SOnlineClassroomWidget::chooseBlackPen() {
	QPen pen = this->m_board->getPen();

	pen.setBrush(QColor(0, 0, 0));
	this->showCurrentColor("rgb(0, 0, 0)");
	this->m_board->setPen(pen);
	this->m_board->setToolType(WhiteBoard::PEN);

	return;
}

/*
	选择蓝色画笔
*/
void SOnlineClassroomWidget::chooseBluePen() {
	QPen pen = this->m_board->getPen();

	pen.setBrush(QColor(18, 150, 219));
	this->showCurrentColor("rgb(18, 150, 219)");
	this->m_board->setPen(pen);
	this->m_board->setToolType(WhiteBoard::PEN);

	return;
}

/*
	选择红色画笔
*/
void SOnlineClassroomWidget::chooseRedPen() {
	QPen pen = this->m_board->getPen();

	pen.setBrush(QColor(216, 30, 6));
	this->showCurrentColor("rgb(216, 30, 6)");
	this->m_board->setPen(pen);
	this->m_board->setToolType(WhiteBoard::PEN);

	return;
}

/*
	自定义画笔颜色
*/
void SOnlineClassroomWidget::chooseColorPen() {
	QColorDialog color_dlg; //调出颜色选择器对话框
	QRgb color = color_dlg.getRgba();
	QString color_str = QString::number(color, 16); // 这是一个QRgb -> QString
	QPen pen = this->m_board->getPen();

	pen.setBrush(QColor(color));
	this->showCurrentColor("#" + color_str);
	this->m_board->setPen(pen);
	this->m_board->setToolType(WhiteBoard::PEN);

	return;
}

/*
	选择添加文本
*/
void SOnlineClassroomWidget::chooseText() {
	this->m_board->setToolType(WhiteBoard::TEXT);

	return;
}

/*
	选择橡皮檫
*/
void SOnlineClassroomWidget::chooseRubber() {
	this->m_board->setToolType(WhiteBoard::RUBBER);

	return;
}

/*
	选择直线工具
*/
void SOnlineClassroomWidget::chooseLine() {
	QPen pen = this->m_board->getPen();

	this->m_board->setPen(pen);
	this->m_board->setToolType(WhiteBoard::LINE);

	return;
}

/*
	选择矩形工具
*/
void SOnlineClassroomWidget::chooseRect() {
	QPen pen = this->m_board->getPen();

	this->m_board->setPen(pen);
	this->m_board->setToolType(WhiteBoard::RECT);

	return;
}

/*
	选择椭圆工具
*/
void SOnlineClassroomWidget::chooseEllipse() {
	QPen pen = this->m_board->getPen();

	this->m_board->setPen(pen);
	this->m_board->setToolType(WhiteBoard::ELLIPSE);

	return;
}

/*
	撤销
	为什么不选择直接让槽设为m_board中的undo？
	因为this->m_board是变化的，clear同理
*/
void SOnlineClassroomWidget::undo() {
	this->m_board->mouseUndo();

	return;
}

/*
	清空
*/
void SOnlineClassroomWidget::clear() {
	this->m_board->mouseClear();

	return;
}

/*
	显示当前颜色
*/
void SOnlineClassroomWidget::showCurrentColor(QString color) {

	this->m_ui.color_pen_btn->setStyleSheet("QPushButton{border: 5px solid " + color + ";background-color: #FCFCFC;}QPushButton:hover{ background - color:#E3E3E3; }QPushButton:checked{ background - color: #CACACA; }");

	return;
}

/*
	新建画板
*/
void SOnlineClassroomWidget::addBoard() {
	QScrollArea *scroll_area = new QScrollArea();
	QPen pen, rubber;

	this->m_board = new WhiteBoard();  // 先创建一个画板
	this->m_board_list.append(this->m_board);  // 加入链表之中
	scroll_area->setWidget(this->m_board);
	scroll_area->setStyleSheet("QScrollArea{border:none;background-color:transparent;}QScrollBar:vertical{border:none;background-color:#ffffff;width:10px;}QScrollBar:vertical:hover{border:none;background-color:rgb(220,220,220);width:10px;}QScrollBar::handle:vertical{border-radius:5px;background:rgb(220,220,220);min-height:20px;}QScrollBar::handle:vertical:hover{border-radius:5px;background:rgb(200,200,200);min-height:20px;}QScrollBar::add-line:vertical{height:0;subcontrol-position:bottom;subcontrol-origin:margin;}QScrollBar::sub-line:vertical{height:0px;subcontrol-position:top;subcontrol-origin:margin;}QScrollBar:horizontal{border:none;background-color:#ffffff;height:10px;}QScrollBar:horizontal:hover{border:none;background-color:rgb(220,220,220);height:10px;}QScrollBar::handle:horizontal{border-radius:5px;background:rgb(220,220,220);min-width:20px;}QScrollBar::handle:horizontal:hover{border-radius:5px;background:rgb(200,200,200);min-width:20px;}QScrollBar::add-line:horizontal{width:0;subcontrol-position:bottom;subcontrol-origin:margin;}QScrollBar::sub-line:horizontal{width:0px;subcontrol-position:top;subcontrol-origin:margin;}");
	this->m_ui.board_tabWidget->addTab(scroll_area, "board_" + QString::number(++this->m_board_id));  // 添加一个画板
	this->m_ui.board_tabWidget->setCurrentIndex(this->m_ui.board_tabWidget->count() - 1);  // 切换到最新建的画板
	this->m_ui.board_tabWidget->setTabsClosable(true);  // 执行添加操作，那画板数量肯定大于1，可以执行删除操作
	this->m_ui.black_pen_btn->click();  // 默认为黑笔，模拟点击
	// 画笔、橡皮檫默认宽度
	pen = this->m_board->getPen();
	pen.setWidth(PEN_WIDTH);
	this->m_board->setPen(pen);
	this->m_ui.pen_width_slider->setValue(PEN_WIDTH);
	this->m_ui.pen_width_edit->setText(QString::number(PEN_WIDTH));

	rubber = this->m_board->getRubber();
	rubber.setWidth(RUBBER_WIDTH);
	this->m_board->setRubber(rubber);
	this->m_ui.rubber_width_slider->setValue(RUBBER_WIDTH);
	this->m_ui.rubber_width_edit->setText(QString::number(RUBBER_WIDTH));

	return;
}

/*
	关闭画板
	index-切换信号传出的tab下标
*/
void SOnlineClassroomWidget::deleteBoard(int index) {
	WhiteBoard *delete_m_board = this->m_board_list[index];

	this->m_board_list.removeAt(index);
	delete delete_m_board;

	this->m_ui.board_tabWidget->removeTab(index);

	// 如果仅剩一个画板，无法关闭
	if (this->m_ui.board_tabWidget->count() == 1) {
		this->m_ui.board_tabWidget->setTabsClosable(false);
	}

	return;
}

/*
	切换画板
	将m_board（当前工作画板）设置为当前选择的画板
	index-切换信号传出的tab下标
*/
void SOnlineClassroomWidget::changeBoard(int index) {
	QPen pen, rubber;
	QColor color;
	WhiteBoard::ToolType tool_Type;

	this->m_board = this->m_board_list[index];  // 切换工作画板
	pen = this->m_board->getPen();  // 获取当前画板的笔
	color = pen.color();  // 获取当前画板的笔颜色
	rubber = this->m_board->getRubber();  // 获取当前画板的橡皮檫
	tool_Type = this->m_board->getToolType();  // 获取当前画板的当前选择工具


	this->showCurrentColor("#" + QString::number(qRgb(color.red(), color.green(), color.blue()), 16));  // 设置颜色显示
	this->m_ui.pen_width_slider->setValue(pen.width());  // 设置画笔、橡皮檫宽度
	this->m_ui.rubber_width_slider->setValue(rubber.width());

	// 工具重置
	switch (tool_Type) {
	case WhiteBoard::PEN:
		if (color == QColor(0, 0, 0)) {
			this->m_ui.black_pen_btn->setChecked(true);
		}
		else if (color == QColor(18, 150, 219)) {
			this->m_ui.blue_pen_btn->setChecked(true);
		}
		else if (color == QColor(216, 30, 6)) {
			this->m_ui.red_pen_btn->setChecked(true);
		}

		break;
	case WhiteBoard::RUBBER:
		this->m_ui.rubber_btn->setChecked(true);
		break;
	case WhiteBoard::LINE:
		this->m_ui.line_btn->setChecked(true);
		break;
	case WhiteBoard::RECT:
		this->m_ui.rect_btn->setChecked(true);
		break;
	case WhiteBoard::ELLIPSE:
		this->m_ui.ellipse_btn->setChecked(true);
		break;
	case WhiteBoard::TEXT:
		this->m_ui.text_btn->setChecked(true);
		break;
	}

	return;
}



SInSpeechRemovableWidget::SInSpeechRemovableWidget(SOnlineClassroomWidget *parent)
	: QWidget(parent) {
	m_ui.setupUi(this);

	int x = parent->width() - this->width() - parent->ui().frame->width(),
		y = 30;
	this->setGeometry(x, y, this->width(), this->height());

	this->connect(parent, &SOnlineClassroomWidget::windowResized, this, &SInSpeechRemovableWidget::updatePos);
}

SInSpeechRemovableWidget::~SInSpeechRemovableWidget() {

}

void SInSpeechRemovableWidget::mouseMoveEvent(QMouseEvent *event) {
	QPoint pos = this->pos() + event->pos() - this->start_pos;
	int max_x = this->parentWidget()->width() - this->width(),
		max_y = this->parentWidget()->height() - this->height();

	if (pos.x() >= 0 && pos.y() >= 0 && pos.x() <= max_x && pos.y() <= max_y) {
		this->move(pos);
	}
	
	return;
}

void SInSpeechRemovableWidget::mousePressEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton) {
		this->is_pressed = true;
		this->start_pos = QPoint(event->pos().x(), event->pos().y());
	}

	return;
}

void SInSpeechRemovableWidget::mouseReleaseEvent(QMouseEvent *event) {
	this->is_pressed = false;

	return;
}

void SInSpeechRemovableWidget::updatePos() {
	int max_x = this->parentWidget()->width() - this->width(),
		max_y = this->parentWidget()->height() - this->height(),
		x = this->pos().x(),
		y = this->pos().y();

	if (this->pos().x() < 0) {
		x = 0;
	}
	if (this->pos().y() < 0) {
		y = 0;
	}
	if (this->pos().x() > max_x) {
		x = max_x;
	}
	if (this->pos().y() > max_y) {
		y = max_y;
	}
	this->setGeometry(x, y, this->width(), this->height());

	return;
}