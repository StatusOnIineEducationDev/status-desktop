#include "sonlineclassroomwidget.h"

const int PEN_WIDTH = 3;
const int RUBBER_WIDTH = 20;

SOnlineClassroomWidget::SOnlineClassroomWidget(SMainWindow *parent) : QWidget(parent) {
	m_ui.setupUi(this);
	m_ui.function_tabWidget->setAttribute(Qt::WA_StyledBackground);  // tab����ʾ����ɫ
	this->connect(parent, &SMainWindow::windowResized, this, &SOnlineClassroomWidget::handleWindowResized);

	QScrollArea *scroll_area;
	QPen pen, rubber;

	// �źŰ�
	this->connect(this->m_ui.pen_width_slider, &QSlider::valueChanged, this, &SOnlineClassroomWidget::setPenWidth);
	this->connect(this->m_ui.rubber_width_slider, &QSlider::valueChanged, this, &SOnlineClassroomWidget::setRubberWidth);
	this->connect(this->m_ui.pen_width_edit, &QLineEdit::textEdited, this, &SOnlineClassroomWidget::setPenSlider);  // ����ı�ֵʱ���������ź�
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

	// ��ʼ��
	scroll_area = new QScrollArea();

	this->m_board_id = 1;

	this->m_board = new WhiteBoard();  // �ȴ���һ������
	this->m_board_list.append(this->m_board);  // ��������֮��
	scroll_area->setWidget(this->m_board);
	scroll_area->setStyleSheet("QScrollArea{border:none;background-color:transparent;}QScrollBar:vertical{border:none;background-color:#ffffff;width:10px;}QScrollBar:vertical:hover{border:none;background-color:rgb(220,220,220);width:10px;}QScrollBar::handle:vertical{border-radius:5px;background:rgb(220,220,220);min-height:20px;}QScrollBar::handle:vertical:hover{border-radius:5px;background:rgb(200,200,200);min-height:20px;}QScrollBar::add-line:vertical{height:0;subcontrol-position:bottom;subcontrol-origin:margin;}QScrollBar::sub-line:vertical{height:0px;subcontrol-position:top;subcontrol-origin:margin;}QScrollBar:horizontal{border:none;background-color:#ffffff;height:10px;}QScrollBar:horizontal:hover{border:none;background-color:rgb(220,220,220);height:10px;}QScrollBar::handle:horizontal{border-radius:5px;background:rgb(220,220,220);min-width:20px;}QScrollBar::handle:horizontal:hover{border-radius:5px;background:rgb(200,200,200);min-width:20px;}QScrollBar::add-line:horizontal{width:0;subcontrol-position:bottom;subcontrol-origin:margin;}QScrollBar::sub-line:horizontal{width:0px;subcontrol-position:top;subcontrol-origin:margin;}");
	this->m_ui.board_tabWidget->addTab(scroll_area, "board_1");  // ���һ������
	this->m_ui.black_pen_btn->click();  // Ĭ��Ϊ�ڱʣ�ģ����
	// ���ʡ���Ƥ��Ĭ�Ͽ��
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
	�������ʴ�ϸ
	value-qslider���ص�ֵ
*/
void SOnlineClassroomWidget::setPenWidth(int value) {
	QPen pen = this->m_board->getPen();

	this->m_ui.pen_width_edit->setText(QString::number(value));
	pen.setWidth(value);
	this->m_board->setPen(pen);

	return;
}

/*
	����pen_slider
*/
void SOnlineClassroomWidget::setPenSlider() {
	QString text = this->m_ui.pen_width_edit->text();
	int value = text.toInt();

	// ��ֵ�������
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
	������Ƥ�ߴ�ϸ
	value-qslider���ص�ֵ
*/
void SOnlineClassroomWidget::setRubberWidth(int value) {
	QPen rubber = this->m_board->getRubber();

	this->m_ui.rubber_width_edit->setText(QString::number(value));
	rubber.setWidth(value);
	this->m_board->setRubber(rubber);

	return;
}

/*
	����rubber_slider
*/
void SOnlineClassroomWidget::setRubberSlider() {
	QString text = this->m_ui.rubber_width_edit->text();
	int value = text.toInt();

	// ��ֵ�������
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
	ѡ���ɫ����
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
	ѡ����ɫ����
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
	ѡ���ɫ����
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
	�Զ��廭����ɫ
*/
void SOnlineClassroomWidget::chooseColorPen() {
	QColorDialog color_dlg; //������ɫѡ�����Ի���
	QRgb color = color_dlg.getRgba();
	QString color_str = QString::number(color, 16); // ����һ��QRgb -> QString
	QPen pen = this->m_board->getPen();

	pen.setBrush(QColor(color));
	this->showCurrentColor("#" + color_str);
	this->m_board->setPen(pen);
	this->m_board->setToolType(WhiteBoard::PEN);

	return;
}

/*
	ѡ������ı�
*/
void SOnlineClassroomWidget::chooseText() {
	this->m_board->setToolType(WhiteBoard::TEXT);

	return;
}

/*
	ѡ����Ƥ��
*/
void SOnlineClassroomWidget::chooseRubber() {
	this->m_board->setToolType(WhiteBoard::RUBBER);

	return;
}

/*
	ѡ��ֱ�߹���
*/
void SOnlineClassroomWidget::chooseLine() {
	QPen pen = this->m_board->getPen();

	this->m_board->setPen(pen);
	this->m_board->setToolType(WhiteBoard::LINE);

	return;
}

/*
	ѡ����ι���
*/
void SOnlineClassroomWidget::chooseRect() {
	QPen pen = this->m_board->getPen();

	this->m_board->setPen(pen);
	this->m_board->setToolType(WhiteBoard::RECT);

	return;
}

/*
	ѡ����Բ����
*/
void SOnlineClassroomWidget::chooseEllipse() {
	QPen pen = this->m_board->getPen();

	this->m_board->setPen(pen);
	this->m_board->setToolType(WhiteBoard::ELLIPSE);

	return;
}

/*
	����
	Ϊʲô��ѡ��ֱ���ò���Ϊm_board�е�undo��
	��Ϊthis->m_board�Ǳ仯�ģ�clearͬ��
*/
void SOnlineClassroomWidget::undo() {
	this->m_board->mouseUndo();

	return;
}

/*
	���
*/
void SOnlineClassroomWidget::clear() {
	this->m_board->mouseClear();

	return;
}

/*
	��ʾ��ǰ��ɫ
*/
void SOnlineClassroomWidget::showCurrentColor(QString color) {

	this->m_ui.color_pen_btn->setStyleSheet("QPushButton{border: 5px solid " + color + ";background-color: #FCFCFC;}QPushButton:hover{ background - color:#E3E3E3; }QPushButton:checked{ background - color: #CACACA; }");

	return;
}

/*
	�½�����
*/
void SOnlineClassroomWidget::addBoard() {
	QScrollArea *scroll_area = new QScrollArea();
	QPen pen, rubber;

	this->m_board = new WhiteBoard();  // �ȴ���һ������
	this->m_board_list.append(this->m_board);  // ��������֮��
	scroll_area->setWidget(this->m_board);
	scroll_area->setStyleSheet("QScrollArea{border:none;background-color:transparent;}QScrollBar:vertical{border:none;background-color:#ffffff;width:10px;}QScrollBar:vertical:hover{border:none;background-color:rgb(220,220,220);width:10px;}QScrollBar::handle:vertical{border-radius:5px;background:rgb(220,220,220);min-height:20px;}QScrollBar::handle:vertical:hover{border-radius:5px;background:rgb(200,200,200);min-height:20px;}QScrollBar::add-line:vertical{height:0;subcontrol-position:bottom;subcontrol-origin:margin;}QScrollBar::sub-line:vertical{height:0px;subcontrol-position:top;subcontrol-origin:margin;}QScrollBar:horizontal{border:none;background-color:#ffffff;height:10px;}QScrollBar:horizontal:hover{border:none;background-color:rgb(220,220,220);height:10px;}QScrollBar::handle:horizontal{border-radius:5px;background:rgb(220,220,220);min-width:20px;}QScrollBar::handle:horizontal:hover{border-radius:5px;background:rgb(200,200,200);min-width:20px;}QScrollBar::add-line:horizontal{width:0;subcontrol-position:bottom;subcontrol-origin:margin;}QScrollBar::sub-line:horizontal{width:0px;subcontrol-position:top;subcontrol-origin:margin;}");
	this->m_ui.board_tabWidget->addTab(scroll_area, "board_" + QString::number(++this->m_board_id));  // ���һ������
	this->m_ui.board_tabWidget->setCurrentIndex(this->m_ui.board_tabWidget->count() - 1);  // �л������½��Ļ���
	this->m_ui.board_tabWidget->setTabsClosable(true);  // ִ����Ӳ������ǻ��������϶�����1������ִ��ɾ������
	this->m_ui.black_pen_btn->click();  // Ĭ��Ϊ�ڱʣ�ģ����
	// ���ʡ���Ƥ��Ĭ�Ͽ��
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
	�رջ���
	index-�л��źŴ�����tab�±�
*/
void SOnlineClassroomWidget::deleteBoard(int index) {
	WhiteBoard *delete_m_board = this->m_board_list[index];

	this->m_board_list.removeAt(index);
	delete delete_m_board;

	this->m_ui.board_tabWidget->removeTab(index);

	// �����ʣһ�����壬�޷��ر�
	if (this->m_ui.board_tabWidget->count() == 1) {
		this->m_ui.board_tabWidget->setTabsClosable(false);
	}

	return;
}

/*
	�л�����
	��m_board����ǰ�������壩����Ϊ��ǰѡ��Ļ���
	index-�л��źŴ�����tab�±�
*/
void SOnlineClassroomWidget::changeBoard(int index) {
	QPen pen, rubber;
	QColor color;
	WhiteBoard::ToolType tool_Type;

	this->m_board = this->m_board_list[index];  // �л���������
	pen = this->m_board->getPen();  // ��ȡ��ǰ����ı�
	color = pen.color();  // ��ȡ��ǰ����ı���ɫ
	rubber = this->m_board->getRubber();  // ��ȡ��ǰ�������Ƥ��
	tool_Type = this->m_board->getToolType();  // ��ȡ��ǰ����ĵ�ǰѡ�񹤾�


	this->showCurrentColor("#" + QString::number(qRgb(color.red(), color.green(), color.blue()), 16));  // ������ɫ��ʾ
	this->m_ui.pen_width_slider->setValue(pen.width());  // ���û��ʡ���Ƥ�߿��
	this->m_ui.rubber_width_slider->setValue(rubber.width());

	// ��������
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