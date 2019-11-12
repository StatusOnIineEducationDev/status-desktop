#include "t_whiteBoardController.h"


const int PEN_WIDTH = 3;
const int RUBBER_WIDTH = 20;

TWhiteBoardController::TWhiteBoardController(TOnlineClassroomWidget *online_classroom_widget, QObject *parent)
	: QObject(parent), m_online_classroom_widget(online_classroom_widget) {
	Ui::TOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();
	this->initWhiteBoard();
}

TWhiteBoardController::~TWhiteBoardController() {

}

void TWhiteBoardController::createPaintConnection(QString course_id, QString lesson_id, QString uid) {
	QJsonObject paint_request_json_obj;
	this->m_paint_connection = new Connection;
	QThread *connection_thread = new QThread(this->m_online_classroom_widget);
	this->m_paint_connection->moveToThread(connection_thread);
	connection_thread->start();

	this->m_paint_connection->connect(ReadConf::G_SOCKET_HOST, ReadConf::G_SOCKET_PORT);

	paint_request_json_obj["command"] = TransportCmd::CreatePaintConnection;
	paint_request_json_obj["account_type"] = AccountType::Teacher;
	paint_request_json_obj["course_id"] = course_id;
	paint_request_json_obj["lesson_id"] = lesson_id;
	paint_request_json_obj["uid"] = uid;

	this->m_paint_connection->send(paint_request_json_obj);

	this->setPaintConnectionSendBaseInfo(course_id, lesson_id, uid);

	// ——信号绑定
	this->connect(this->m_board, &WhiteBoard::paintCommandReady, this, &TWhiteBoardController::sendPaintCommand);
	this->connect(this->m_paint_connection, &Connection::bufferReadyRead, this, &TWhiteBoardController::handlePaintConnectionRecv);

	return;
}

void TWhiteBoardController::distroyPaintConnection() {
	QThread *thread = this->m_paint_connection->thread();

	this->disconnect(this->m_board, &WhiteBoard::paintCommandReady, this, &TWhiteBoardController::sendPaintCommand);
	delete this->m_paint_connection;
	this->m_paint_connection = nullptr;
	thread->exit(0);

	return;
}

void TWhiteBoardController::handlePaintConnectionRecv() {
	QJsonObject data = this->m_paint_connection->recv();
	TransportCmd cmd = TransportCmd(data["command"].toInt());

	switch (cmd) {
	case TransportCmd::PaintCommand: handleCommandPaintCommand(data); break;
	}

	return;
}

void TWhiteBoardController::handleCommandPaintCommand(QJsonObject &data) {
	this->m_board->paintByPaintCommand(data);

	return;
}

void TWhiteBoardController::sendPaintCommand(QJsonObject &data) {
	data["command"] = TransportCmd::PaintCommand;
	data["account_type"] = AccountType::Teacher;
	data["course_id"] = this->m_send_base_info["course_id"].toString();
	data["lesson_id"] = this->m_send_base_info["lesson_id"].toString();
	data["uid"] = this->m_send_base_info["uid"].toString();

	this->m_paint_connection->realSend(data);
}

void TWhiteBoardController::setPaintConnectionSendBaseInfo(QString course_id, QString lesson_id, QString uid) {
	this->m_send_base_info["uid"] = uid;
	this->m_send_base_info["course_id"] = course_id;
	this->m_send_base_info["lesson_id"] = lesson_id;

	return;
}

void TWhiteBoardController::initWhiteBoard() {
	Ui::TOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();
	QScrollArea *scroll_area;
	QPen pen, rubber;

	// ——工具栏信号绑定
	this->toolBarSignalConnect();

	// ——初始化
	scroll_area = new QScrollArea();

	this->m_board_id = 1;

	this->m_board = new WhiteBoard(this->m_online_classroom_widget);  // 先创建一个画板
	this->m_board_list.append(this->m_board);  // 加入链表之中
	scroll_area->setWidget(this->m_board);
	scroll_area->setStyleSheet("QScrollArea{border:none;background-color:transparent;}QScrollBar:vertical{border:none;background-color:#ffffff;width:10px;}QScrollBar:vertical:hover{border:none;background-color:rgb(220,220,220);width:10px;}QScrollBar::handle:vertical{border-radius:5px;background:rgb(220,220,220);min-height:20px;}QScrollBar::handle:vertical:hover{border-radius:5px;background:rgb(200,200,200);min-height:20px;}QScrollBar::add-line:vertical{height:0;subcontrol-position:bottom;subcontrol-origin:margin;}QScrollBar::sub-line:vertical{height:0px;subcontrol-position:top;subcontrol-origin:margin;}QScrollBar:horizontal{border:none;background-color:#ffffff;height:10px;}QScrollBar:horizontal:hover{border:none;background-color:rgb(220,220,220);height:10px;}QScrollBar::handle:horizontal{border-radius:5px;background:rgb(220,220,220);min-width:20px;}QScrollBar::handle:horizontal:hover{border-radius:5px;background:rgb(200,200,200);min-width:20px;}QScrollBar::add-line:horizontal{width:0;subcontrol-position:bottom;subcontrol-origin:margin;}QScrollBar::sub-line:horizontal{width:0px;subcontrol-position:top;subcontrol-origin:margin;}");
	ui.board_tabWidget->addTab(scroll_area, "board_1");  // 添加一个画板
	ui.black_pen_btn->click();  // 默认为黑笔，模拟点击
	// ——画笔、橡皮檫默认宽度
	pen = this->m_board->getPen();
	pen.setWidth(PEN_WIDTH);
	this->m_board->setPen(pen);
	ui.pen_width_slider->setValue(PEN_WIDTH);
	ui.pen_width_edit->setText(QString::number(PEN_WIDTH));

	rubber = this->m_board->getRubber();
	rubber.setWidth(RUBBER_WIDTH);
	this->m_board->setRubber(rubber);
	ui.rubber_width_slider->setValue(RUBBER_WIDTH);
	ui.rubber_width_edit->setText(QString::number(RUBBER_WIDTH));
}

void TWhiteBoardController::toolBarSignalConnect() {
	Ui::TOnlineClassroomWidget ui = this->m_online_classroom_widget->ui();

	// 工具栏按钮信号绑定
	this->connect(ui.pen_width_slider, &QSlider::valueChanged, this, &TWhiteBoardController::setPenWidth);
	this->connect(ui.rubber_width_slider, &QSlider::valueChanged, this, &TWhiteBoardController::setRubberWidth);
	this->connect(ui.pen_width_edit, &QLineEdit::textEdited, this, &TWhiteBoardController::setPenSlider);  // 程序改变值时，不触发信号
	this->connect(ui.rubber_width_edit, &QLineEdit::textEdited, this, &TWhiteBoardController::setRubberSlider);
	this->connect(ui.black_pen_btn, &QPushButton::clicked, this, &TWhiteBoardController::chooseBlackPen);
	this->connect(ui.blue_pen_btn, &QPushButton::clicked, this, &TWhiteBoardController::chooseBluePen);
	this->connect(ui.red_pen_btn, &QPushButton::clicked, this, &TWhiteBoardController::chooseRedPen);
	this->connect(ui.color_pen_btn, &QPushButton::clicked, this, &TWhiteBoardController::chooseColorPen);
	this->connect(ui.text_btn, &QPushButton::clicked, this, &TWhiteBoardController::chooseText);
	this->connect(ui.rubber_btn, &QPushButton::clicked, this, &TWhiteBoardController::chooseRubber);
	this->connect(ui.line_btn, &QPushButton::clicked, this, &TWhiteBoardController::chooseLine);
	this->connect(ui.rect_btn, &QPushButton::clicked, this, &TWhiteBoardController::chooseRect);
	this->connect(ui.ellipse_btn, &QPushButton::clicked, this, &TWhiteBoardController::chooseEllipse);
	this->connect(ui.undo_btn, &QPushButton::clicked, this, &TWhiteBoardController::undo);
	this->connect(ui.clear_btn, &QPushButton::clicked, this, &TWhiteBoardController::clear);
	this->connect(ui.add_board_btn, &QPushButton::clicked, this, &TWhiteBoardController::addBoard);
	this->connect(ui.board_tabWidget, &QTabWidget::tabCloseRequested, this, &TWhiteBoardController::deleteBoard);
	this->connect(ui.board_tabWidget, &QTabWidget::currentChanged, this, &TWhiteBoardController::changeBoard);
	
	return;
}

void TWhiteBoardController::setPenWidth(int value) {
	QPen pen = this->m_board->getPen();

	this->m_online_classroom_widget->ui().pen_width_edit->setText(QString::number(value));
	pen.setWidth(value);
	this->m_board->setPen(pen);

	return;
}

void TWhiteBoardController::setPenSlider() {
	QString text = this->m_online_classroom_widget->ui().pen_width_edit->text();
	int value = text.toInt();

	// 数值溢出处理
	if (value > 99) {
		this->m_online_classroom_widget->ui().pen_width_edit->setText("99");
	}
	if (value < 1) {
		this->m_online_classroom_widget->ui().pen_width_edit->setText("1");
	}

	this->m_online_classroom_widget->ui().pen_width_slider->setValue(text.toInt());

	return;
}

void TWhiteBoardController::setRubberWidth(int value) {
	QPen rubber = this->m_board->getRubber();

	this->m_online_classroom_widget->ui().rubber_width_edit->setText(QString::number(value));
	rubber.setWidth(value);
	this->m_board->setRubber(rubber);

	return;
}

void TWhiteBoardController::setRubberSlider() {
	QString text = this->m_online_classroom_widget->ui().rubber_width_edit->text();
	int value = text.toInt();

	// 数值溢出处理
	if (value > 99) {
		this->m_online_classroom_widget->ui().rubber_width_edit->setText("99");
	}
	if (value < 1) {
		this->m_online_classroom_widget->ui().rubber_width_edit->setText("1");
	}

	this->m_online_classroom_widget->ui().rubber_width_slider->setValue(text.toInt());

	return;
}

void TWhiteBoardController::chooseBlackPen() {
	QPen pen = this->m_board->getPen();

	pen.setBrush(QColor(0, 0, 0));
	this->showCurrentColor("rgb(0, 0, 0)");
	this->m_board->setPen(pen);
	this->m_board->setToolType(WhiteBoard::PEN);

	return;
}

void TWhiteBoardController::chooseBluePen() {
	QPen pen = this->m_board->getPen();

	pen.setBrush(QColor(18, 150, 219));
	this->showCurrentColor("rgb(18, 150, 219)");
	this->m_board->setPen(pen);
	this->m_board->setToolType(WhiteBoard::PEN);

	return;
}

void TWhiteBoardController::chooseRedPen() {
	QPen pen = this->m_board->getPen();

	pen.setBrush(QColor(216, 30, 6));
	this->showCurrentColor("rgb(216, 30, 6)");
	this->m_board->setPen(pen);
	this->m_board->setToolType(WhiteBoard::PEN);

	return;
}

void TWhiteBoardController::chooseColorPen() {
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

void TWhiteBoardController::chooseText() {
	this->m_board->setToolType(WhiteBoard::TEXT);

	return;
}

void TWhiteBoardController::chooseRubber() {
	this->m_board->setToolType(WhiteBoard::RUBBER);

	return;
}

void TWhiteBoardController::chooseLine() {
	QPen pen = this->m_board->getPen();

	this->m_board->setPen(pen);
	this->m_board->setToolType(WhiteBoard::LINE);

	return;
}

void TWhiteBoardController::chooseRect() {
	QPen pen = this->m_board->getPen();

	this->m_board->setPen(pen);
	this->m_board->setToolType(WhiteBoard::RECT);

	return;
}

void TWhiteBoardController::chooseEllipse() {
	QPen pen = this->m_board->getPen();

	this->m_board->setPen(pen);
	this->m_board->setToolType(WhiteBoard::ELLIPSE);

	return;
}

void TWhiteBoardController::undo() {
	this->m_board->mouseUndo();

	return;
}

void TWhiteBoardController::clear() {
	this->m_board->mouseClear();

	return;
}

void TWhiteBoardController::showCurrentColor(QString color) {

	this->m_online_classroom_widget->ui().color_pen_btn->setStyleSheet("QPushButton{border: 5px solid " + color + ";background-color: #FCFCFC;}QPushButton:hover{ background - color:#E3E3E3; }QPushButton:checked{ background - color: #CACACA; }");

	return;
}

void TWhiteBoardController::addBoard() {
	QScrollArea *scroll_area = new QScrollArea();
	QPen pen, rubber;

	this->m_board = new WhiteBoard();  // 先创建一个画板
	this->m_board_list.append(this->m_board);  // 加入链表之中
	scroll_area->setWidget(this->m_board);
	scroll_area->setStyleSheet("QScrollArea{border:none;background-color:transparent;}QScrollBar:vertical{border:none;background-color:#ffffff;width:10px;}QScrollBar:vertical:hover{border:none;background-color:rgb(220,220,220);width:10px;}QScrollBar::handle:vertical{border-radius:5px;background:rgb(220,220,220);min-height:20px;}QScrollBar::handle:vertical:hover{border-radius:5px;background:rgb(200,200,200);min-height:20px;}QScrollBar::add-line:vertical{height:0;subcontrol-position:bottom;subcontrol-origin:margin;}QScrollBar::sub-line:vertical{height:0px;subcontrol-position:top;subcontrol-origin:margin;}QScrollBar:horizontal{border:none;background-color:#ffffff;height:10px;}QScrollBar:horizontal:hover{border:none;background-color:rgb(220,220,220);height:10px;}QScrollBar::handle:horizontal{border-radius:5px;background:rgb(220,220,220);min-width:20px;}QScrollBar::handle:horizontal:hover{border-radius:5px;background:rgb(200,200,200);min-width:20px;}QScrollBar::add-line:horizontal{width:0;subcontrol-position:bottom;subcontrol-origin:margin;}QScrollBar::sub-line:horizontal{width:0px;subcontrol-position:top;subcontrol-origin:margin;}");
	this->m_online_classroom_widget->ui().board_tabWidget->addTab(scroll_area, "board_" + QString::number(++this->m_board_id));  // 添加一个画板
	this->m_online_classroom_widget->ui().board_tabWidget->setCurrentIndex(this->m_online_classroom_widget->ui().board_tabWidget->count() - 1);  // 切换到最新建的画板
	this->m_online_classroom_widget->ui().board_tabWidget->setTabsClosable(true);  // 执行添加操作，那画板数量肯定大于1，可以执行删除操作
	this->m_online_classroom_widget->ui().black_pen_btn->click();  // 默认为黑笔，模拟点击
	// 画笔、橡皮檫默认宽度
	pen = this->m_board->getPen();
	pen.setWidth(PEN_WIDTH);
	this->m_board->setPen(pen);
	this->m_online_classroom_widget->ui().pen_width_slider->setValue(PEN_WIDTH);
	this->m_online_classroom_widget->ui().pen_width_edit->setText(QString::number(PEN_WIDTH));

	rubber = this->m_board->getRubber();
	rubber.setWidth(RUBBER_WIDTH);
	this->m_board->setRubber(rubber);
	this->m_online_classroom_widget->ui().rubber_width_slider->setValue(RUBBER_WIDTH);
	this->m_online_classroom_widget->ui().rubber_width_edit->setText(QString::number(RUBBER_WIDTH));

	return;
}

void TWhiteBoardController::deleteBoard(int index) {
	WhiteBoard *delete_m_board = this->m_board_list[index];

	this->m_board_list.removeAt(index);
	delete delete_m_board;

	this->m_online_classroom_widget->ui().board_tabWidget->removeTab(index);

	// 如果仅剩一个画板，无法关闭
	if (this->m_online_classroom_widget->ui().board_tabWidget->count() == 1) {
		this->m_online_classroom_widget->ui().board_tabWidget->setTabsClosable(false);
	}

	return;
}

void TWhiteBoardController::changeBoard(int index) {
	QPen pen, rubber;
	QColor color;
	WhiteBoard::ToolType tool_Type;

	this->m_board = this->m_board_list[index];  // 切换工作画板
	pen = this->m_board->getPen();  // 获取当前画板的笔
	color = pen.color();  // 获取当前画板的笔颜色
	rubber = this->m_board->getRubber();  // 获取当前画板的橡皮檫
	tool_Type = this->m_board->getToolType();  // 获取当前画板的当前选择工具


	this->showCurrentColor("#" + QString::number(qRgb(color.red(), color.green(), color.blue()), 16));  // 设置颜色显示
	this->m_online_classroom_widget->ui().pen_width_slider->setValue(pen.width());  // 设置画笔、橡皮檫宽度
	this->m_online_classroom_widget->ui().rubber_width_slider->setValue(rubber.width());

	// 工具重置
	switch (tool_Type) {
	case WhiteBoard::PEN:
		if (color == QColor(0, 0, 0)) {
			this->m_online_classroom_widget->ui().black_pen_btn->setChecked(true);
		}
		else if (color == QColor(18, 150, 219)) {
			this->m_online_classroom_widget->ui().blue_pen_btn->setChecked(true);
		}
		else if (color == QColor(216, 30, 6)) {
			this->m_online_classroom_widget->ui().red_pen_btn->setChecked(true);
		}

		break;
	case WhiteBoard::RUBBER:
		this->m_online_classroom_widget->ui().rubber_btn->setChecked(true);
		break;
	case WhiteBoard::LINE:
		this->m_online_classroom_widget->ui().line_btn->setChecked(true);
		break;
	case WhiteBoard::RECT:
		this->m_online_classroom_widget->ui().rect_btn->setChecked(true);
		break;
	case WhiteBoard::ELLIPSE:
		this->m_online_classroom_widget->ui().ellipse_btn->setChecked(true);
		break;
	case WhiteBoard::TEXT:
		this->m_online_classroom_widget->ui().text_btn->setChecked(true);
		break;
	}

	return;
}
