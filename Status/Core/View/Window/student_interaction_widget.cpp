#include "student_interaction_widget.h"

const int PEN_WIDTH = 3;
const int RUBBER_WIDTH = 20;

StudentInteractionWidget::StudentInteractionWidget(QWidget *parent) : QWidget(parent) {
	m_ui.setupUi(this);

	QScrollArea *scroll_area;
	QPen pen, rubber;

	// 信号绑定
	this->connect(this->m_ui.pen_width_slider, &QSlider::valueChanged, this, &StudentInteractionWidget::setPenWidth);
	this->connect(this->m_ui.rubber_width_slider, &QSlider::valueChanged, this, &StudentInteractionWidget::setRubberWidth);
	this->connect(this->m_ui.pen_width_edit, &QLineEdit::textEdited, this, &StudentInteractionWidget::setPenSlider);  // 程序改变值时，不触发信号
	this->connect(this->m_ui.rubber_width_edit, &QLineEdit::textEdited, this, &StudentInteractionWidget::setRubberSlider);
	this->connect(this->m_ui.black_pen_btn, &QPushButton::clicked, this, &StudentInteractionWidget::chooseBlackPen);
	this->connect(this->m_ui.blue_pen_btn, &QPushButton::clicked, this, &StudentInteractionWidget::chooseBluePen);
	this->connect(this->m_ui.red_pen_btn, &QPushButton::clicked, this, &StudentInteractionWidget::chooseRedPen);
	this->connect(this->m_ui.color_pen_btn, &QPushButton::clicked, this, &StudentInteractionWidget::chooseColorPen);
	this->connect(this->m_ui.text_btn, &QPushButton::clicked, this, &StudentInteractionWidget::chooseText);
	this->connect(this->m_ui.rubber_btn, &QPushButton::clicked, this, &StudentInteractionWidget::chooseRubber);
	this->connect(this->m_ui.line_btn, &QPushButton::clicked, this, &StudentInteractionWidget::chooseLine);
	this->connect(this->m_ui.rect_btn, &QPushButton::clicked, this, &StudentInteractionWidget::chooseRect);
	this->connect(this->m_ui.ellipse_btn, &QPushButton::clicked, this, &StudentInteractionWidget::chooseEllipse);
	this->connect(this->m_ui.undo_btn, &QPushButton::clicked, this, &StudentInteractionWidget::undo);
	this->connect(this->m_ui.clear_btn, &QPushButton::clicked, this, &StudentInteractionWidget::clear);
	this->connect(this->m_ui.add_board_btn, &QPushButton::clicked, this, &StudentInteractionWidget::addBoard);
	this->connect(this->m_ui.board_tabWidget, &QTabWidget::tabCloseRequested, this, &StudentInteractionWidget::deleteBoard);
	this->connect(this->m_ui.board_tabWidget, &QTabWidget::currentChanged, this, &StudentInteractionWidget::changeBoard);

	// 初始化
	scroll_area = new QScrollArea();

	this->m_board_id = 1;

	this->m_board = new PaintWidget();  // 先创建一个画板
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

StudentInteractionWidget::~StudentInteractionWidget() {
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
void StudentInteractionWidget::setPenWidth(int value) {
	QPen pen = this->m_board->getPen();

	this->m_ui.pen_width_edit->setText(QString::number(value));
	pen.setWidth(value);
	this->m_board->setPen(pen);

	return;
}

/*
	调整pen_slider
*/
void StudentInteractionWidget::setPenSlider() {
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
void StudentInteractionWidget::setRubberWidth(int value) {
	QPen rubber = this->m_board->getRubber();

	this->m_ui.rubber_width_edit->setText(QString::number(value));
	rubber.setWidth(value);
	this->m_board->setRubber(rubber);

	return;
}

/*
	调整rubber_slider
*/
void StudentInteractionWidget::setRubberSlider() {
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
void StudentInteractionWidget::chooseBlackPen() {
	QPen pen = this->m_board->getPen();

	pen.setBrush(QColor(0, 0, 0));
	this->showCurrentColor("rgb(0, 0, 0)");
	this->m_board->setPen(pen);
	this->m_board->setToolType(PaintWidget::PEN);

	return;
}

/*
	选择蓝色画笔
*/
void StudentInteractionWidget::chooseBluePen() {
	QPen pen = this->m_board->getPen();

	pen.setBrush(QColor(18, 150, 219));
	this->showCurrentColor("rgb(18, 150, 219)");
	this->m_board->setPen(pen);
	this->m_board->setToolType(PaintWidget::PEN);

	return;
}

/*
	选择红色画笔
*/
void StudentInteractionWidget::chooseRedPen() {
	QPen pen = this->m_board->getPen();

	pen.setBrush(QColor(216, 30, 6));
	this->showCurrentColor("rgb(216, 30, 6)");
	this->m_board->setPen(pen);
	this->m_board->setToolType(PaintWidget::PEN);

	return;
}

/*
	自定义画笔颜色
*/
void StudentInteractionWidget::chooseColorPen() {
	QColorDialog color_dlg; //调出颜色选择器对话框
	QRgb color = color_dlg.getRgba();
	QString color_str = QString::number(color, 16); // 这是一个QRgb -> QString
	QPen pen = this->m_board->getPen();

	pen.setBrush(QColor(color));
	this->showCurrentColor("#" + color_str);
	this->m_board->setPen(pen);
	this->m_board->setToolType(PaintWidget::PEN);

	return;
}

/*
	选择添加文本
*/
void StudentInteractionWidget::chooseText() {
	this->m_board->setToolType(PaintWidget::TEXT);

	return;
}

/*
	选择橡皮檫
*/
void StudentInteractionWidget::chooseRubber() {
	this->m_board->setToolType(PaintWidget::RUBBER);

	return;
}

/*
	选择直线工具
*/
void StudentInteractionWidget::chooseLine() {
	QPen pen = this->m_board->getPen();

	this->m_board->setPen(pen);
	this->m_board->setToolType(PaintWidget::LINE);

	return;
}

/*
	选择矩形工具
*/
void StudentInteractionWidget::chooseRect() {
	QPen pen = this->m_board->getPen();

	this->m_board->setPen(pen);
	this->m_board->setToolType(PaintWidget::RECT);

	return;
}

/*
	选择椭圆工具
*/
void StudentInteractionWidget::chooseEllipse() {
	QPen pen = this->m_board->getPen();

	this->m_board->setPen(pen);
	this->m_board->setToolType(PaintWidget::ELLIPSE);

	return;
}

/*
	撤销
	为什么不选择直接让槽设为m_board中的undo？
	因为this->m_board是变化的，clear同理
*/
void StudentInteractionWidget::undo() {
	this->m_board->undo();

	return;
}

/*
	清空
*/
void StudentInteractionWidget::clear() {
	this->m_board->clear();

	return;
}

/*
	显示当前颜色
*/
void StudentInteractionWidget::showCurrentColor(QString color) {

	this->m_ui.color_pen_btn->setStyleSheet("QPushButton{border: 5px solid " + color + ";background-color: #FCFCFC;}QPushButton:hover{ background - color:#E3E3E3; }QPushButton:checked{ background - color: #CACACA; }");

	return;
}

/*
	新建画板
*/
void StudentInteractionWidget::addBoard() {
	QScrollArea *scroll_area = new QScrollArea();
	QPen pen, rubber;

	this->m_board = new PaintWidget();  // 先创建一个画板
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
void StudentInteractionWidget::deleteBoard(int index) {
	PaintWidget *delete_m_board = this->m_board_list[index];

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
void StudentInteractionWidget::changeBoard(int index) {
	QPen pen, rubber;
	QColor color;
	PaintWidget::ToolType tool_Type;

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
	case PaintWidget::PEN:
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
	case PaintWidget::RUBBER:
		this->m_ui.rubber_btn->setChecked(true);
		break;
	case PaintWidget::LINE:
		this->m_ui.line_btn->setChecked(true);
		break;
	case PaintWidget::RECT:
		this->m_ui.rect_btn->setChecked(true);
		break;
	case PaintWidget::ELLIPSE:
		this->m_ui.ellipse_btn->setChecked(true);
		break;
	case PaintWidget::TEXT:
		this->m_ui.text_btn->setChecked(true);
		break;
	}

	return;
}
