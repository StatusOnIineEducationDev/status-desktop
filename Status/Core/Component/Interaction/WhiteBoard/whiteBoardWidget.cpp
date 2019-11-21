#include "whiteBoardWidget.h"


const int PEN_WIDTH = 3;
const int RUBBER_WIDTH = 20;

WhiteBoardWidget::WhiteBoardWidget(QWidget *parent) 
	: QWidget(parent), m_board(nullptr), m_interactive_board(nullptr), m_board_id(1) {
	m_ui.setupUi(this);

	this->initWhiteBoardArea();
}

WhiteBoardWidget::~WhiteBoardWidget() {
	
}

void WhiteBoardWidget::setInteractiveWhiteBoardDisabled(bool flag) {
	if (this->m_interactive_board == nullptr) {
		return;
	}

	this->m_interactive_board->setBoardDisabled(flag);
	this->setToolBarDisabled(flag);
	
	return;
}

void WhiteBoardWidget::initWhiteBoardArea() {
	this->createInteractiveWhiteBoard();

	// ——工具栏信号绑定
	this->toolBarSignalConnect();

	return;
}

void WhiteBoardWidget::createInteractiveWhiteBoard() {
	QScrollArea *scroll_area = new QScrollArea(this->m_ui.board_tabWidget);
	QPen pen, rubber;

	this->m_board = new WhiteBoard(scroll_area);  // 先创建一个画板
	this->m_interactive_board = this->m_board;
	this->m_board_list.append(this->m_board);  // 加入链表之中

	scroll_area->setWidget(this->m_board);
	this->m_ui.board_tabWidget->addTab(scroll_area, "互动画板");  // 添加一个画板
	this->m_ui.black_pen_btn->click();  // 默认为黑笔，模拟点击
	// ——画笔、橡皮檫默认宽度
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

	// ——设置该画板不可关闭
	this->m_ui.board_tabWidget->tabBar()->setTabButton(0, QTabBar::RightSide, nullptr);

	return;
}

void WhiteBoardWidget::toolBarSignalConnect() {
	// 工具栏按钮信号绑定
	this->connect(this->m_ui.pen_width_slider, &QSlider::valueChanged, this, &WhiteBoardWidget::setPenWidth);
	this->connect(this->m_ui.rubber_width_slider, &QSlider::valueChanged, this, &WhiteBoardWidget::setRubberWidth);
	this->connect(this->m_ui.pen_width_edit, &QLineEdit::textEdited, this, &WhiteBoardWidget::setPenSlider);  // 程序改变值时，不触发信号
	this->connect(this->m_ui.rubber_width_edit, &QLineEdit::textEdited, this, &WhiteBoardWidget::setRubberSlider);
	this->connect(this->m_ui.black_pen_btn, &QPushButton::clicked, this, &WhiteBoardWidget::chooseBlackPen);
	this->connect(this->m_ui.blue_pen_btn, &QPushButton::clicked, this, &WhiteBoardWidget::chooseBluePen);
	this->connect(this->m_ui.red_pen_btn, &QPushButton::clicked, this, &WhiteBoardWidget::chooseRedPen);
	this->connect(this->m_ui.color_pen_btn, &QPushButton::clicked, this, &WhiteBoardWidget::chooseColorPen);
	this->connect(this->m_ui.text_btn, &QPushButton::clicked, this, &WhiteBoardWidget::chooseText);
	this->connect(this->m_ui.rubber_btn, &QPushButton::clicked, this, &WhiteBoardWidget::chooseRubber);
	this->connect(this->m_ui.line_btn, &QPushButton::clicked, this, &WhiteBoardWidget::chooseLine);
	this->connect(this->m_ui.rect_btn, &QPushButton::clicked, this, &WhiteBoardWidget::chooseRect);
	this->connect(this->m_ui.ellipse_btn, &QPushButton::clicked, this, &WhiteBoardWidget::chooseEllipse);
	this->connect(this->m_ui.undo_btn, &QPushButton::clicked, this, &WhiteBoardWidget::undo);
	this->connect(this->m_ui.clear_btn, &QPushButton::clicked, this, &WhiteBoardWidget::clear);
	this->connect(this->m_ui.add_board_btn, &QPushButton::clicked, this, &WhiteBoardWidget::addBoard);
	this->connect(this->m_ui.board_tabWidget, &QTabWidget::tabCloseRequested, this, &WhiteBoardWidget::deleteBoard);
	this->connect(this->m_ui.board_tabWidget, &QTabWidget::currentChanged, this, &WhiteBoardWidget::changeBoard);

	return;
}

void WhiteBoardWidget::setToolBarDisabled(bool flag) {
	this->m_ui.pen_width_edit->setDisabled(flag);
	this->m_ui.rubber_width_edit->setDisabled(flag);
	this->m_ui.pen_width_slider->setDisabled(flag);
	this->m_ui.rubber_width_slider->setDisabled(flag);
	this->m_ui.pen_width_edit->setDisabled(flag);
	this->m_ui.black_pen_btn->setDisabled(flag);
	this->m_ui.blue_pen_btn->setDisabled(flag);
	this->m_ui.red_pen_btn->setDisabled(flag);
	this->m_ui.color_pen_btn->setDisabled(flag);
	this->m_ui.text_btn->setDisabled(flag);
	this->m_ui.rubber_btn->setDisabled(flag);
	this->m_ui.line_btn->setDisabled(flag);
	this->m_ui.rect_btn->setDisabled(flag);
	this->m_ui.ellipse_btn->setDisabled(flag);
	this->m_ui.undo_btn->setDisabled(flag);
	this->m_ui.clear_btn->setDisabled(flag);

	return;
}

void WhiteBoardWidget::setPenWidth(int value) {
	QPen pen = this->m_board->getPen();

	this->m_ui.pen_width_edit->setText(QString::number(value));
	pen.setWidth(value);
	this->m_board->setPen(pen);

	return;
}

void WhiteBoardWidget::setPenSlider() {
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

void WhiteBoardWidget::setRubberWidth(int value) {
	QPen rubber = this->m_board->getRubber();

	this->m_ui.rubber_width_edit->setText(QString::number(value));
	rubber.setWidth(value);
	this->m_board->setRubber(rubber);

	return;
}

void WhiteBoardWidget::setRubberSlider() {
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

void WhiteBoardWidget::chooseBlackPen() {
	QPen pen = this->m_board->getPen();

	pen.setBrush(QColor(0, 0, 0));
	this->showCurrentColor("rgb(0, 0, 0)");
	this->m_board->setPen(pen);
	this->m_board->setToolType(WhiteBoard::PEN);

	return;
}

void WhiteBoardWidget::chooseBluePen() {
	QPen pen = this->m_board->getPen();

	pen.setBrush(QColor(18, 150, 219));
	this->showCurrentColor("rgb(18, 150, 219)");
	this->m_board->setPen(pen);
	this->m_board->setToolType(WhiteBoard::PEN);

	return;
}

void WhiteBoardWidget::chooseRedPen() {
	QPen pen = this->m_board->getPen();

	pen.setBrush(QColor(216, 30, 6));
	this->showCurrentColor("rgb(216, 30, 6)");
	this->m_board->setPen(pen);
	this->m_board->setToolType(WhiteBoard::PEN);

	return;
}

void WhiteBoardWidget::chooseColorPen() {
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

void WhiteBoardWidget::chooseText() {
	this->m_board->setToolType(WhiteBoard::TEXT);

	return;
}

void WhiteBoardWidget::chooseRubber() {
	this->m_board->setToolType(WhiteBoard::RUBBER);

	return;
}

void WhiteBoardWidget::chooseLine() {
	QPen pen = this->m_board->getPen();

	this->m_board->setPen(pen);
	this->m_board->setToolType(WhiteBoard::LINE);

	return;
}

void WhiteBoardWidget::chooseRect() {
	QPen pen = this->m_board->getPen();

	this->m_board->setPen(pen);
	this->m_board->setToolType(WhiteBoard::RECT);

	return;
}

void WhiteBoardWidget::chooseEllipse() {
	QPen pen = this->m_board->getPen();

	this->m_board->setPen(pen);
	this->m_board->setToolType(WhiteBoard::ELLIPSE);

	return;
}

void WhiteBoardWidget::undo() {
	this->m_board->mouseUndo();

	return;
}

void WhiteBoardWidget::clear() {
	this->m_board->mouseClear();

	return;
}

void WhiteBoardWidget::showCurrentColor(QString color) {
	this->m_ui.color_pen_btn->setStyleSheet("QPushButton{border: 5px solid " + color + ";background-color: #FCFCFC;}QPushButton:hover{ background - color:#E3E3E3; }QPushButton:checked{ background - color: #CACACA; }");

	return;
}

void WhiteBoardWidget::addBoard() {
	QScrollArea *scroll_area = new QScrollArea(this->m_ui.board_tabWidget);
	QPen pen, rubber;

	this->m_board = new WhiteBoard(scroll_area);  // 先创建一个画板
	this->m_board_list.append(this->m_board);  // 加入链表之中
	scroll_area->setWidget(this->m_board);
	this->m_ui.board_tabWidget->addTab(scroll_area, "画板_" + QString::number(++this->m_board_id));  // 添加一个画板
	this->m_ui.board_tabWidget->setCurrentIndex(this->m_ui.board_tabWidget->count() - 1);  // 切换到最新建的画板
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

void WhiteBoardWidget::deleteBoard(int index) {
	WhiteBoard *delete_m_board = this->m_board_list[index];

	this->m_board_list.removeAt(index);
	delete delete_m_board;

	this->m_ui.board_tabWidget->removeTab(index);

	return;
}

void WhiteBoardWidget::changeBoard(int index) {
	QPen pen, rubber;
	QColor color;
	WhiteBoard::ToolType tool_Type;

	this->m_board = this->m_board_list[index];  // 切换工作画板
	this->setToolBarDisabled(this->m_board->getBoardDisabled()); // 工具栏可用设置
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