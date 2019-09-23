#include "teacher_interaction_widget.h"

const int PEN_WIDTH = 3;
const int RUBBER_WIDTH = 20;

TeacherInteractionWidget::TeacherInteractionWidget(QWidget *parent): QWidget(parent) {
	ui.setupUi(this);

	QScrollArea *scroll_area;
	QPen pen, rubber;

	// �źŰ�
	this->connect(this->ui.pen_width_slider, &QSlider::valueChanged, this, &TeacherInteractionWidget::setPenWidth);
	this->connect(this->ui.rubber_width_slider, &QSlider::valueChanged, this, &TeacherInteractionWidget::setRubberWidth);
	this->connect(this->ui.pen_width_edit, &QLineEdit::textEdited, this, &TeacherInteractionWidget::setPenSlider);  // ����ı�ֵʱ���������ź�
	this->connect(this->ui.rubber_width_edit, &QLineEdit::textEdited, this, &TeacherInteractionWidget::setRubberSlider);
	this->connect(this->ui.black_pen_btn, &QPushButton::clicked, this, &TeacherInteractionWidget::chooseBlackPen);
	this->connect(this->ui.blue_pen_btn, &QPushButton::clicked, this, &TeacherInteractionWidget::chooseBluePen);
	this->connect(this->ui.red_pen_btn, &QPushButton::clicked, this, &TeacherInteractionWidget::chooseRedPen);
	this->connect(this->ui.color_pen_btn, &QPushButton::clicked, this, &TeacherInteractionWidget::chooseColorPen);
	this->connect(this->ui.text_btn, &QPushButton::clicked, this, &TeacherInteractionWidget::chooseText);
	this->connect(this->ui.rubber_btn, &QPushButton::clicked, this, &TeacherInteractionWidget::chooseRubber);
	this->connect(this->ui.line_btn, &QPushButton::clicked, this, &TeacherInteractionWidget::chooseLine);
	this->connect(this->ui.rect_btn, &QPushButton::clicked, this, &TeacherInteractionWidget::chooseRect);
	this->connect(this->ui.ellipse_btn, &QPushButton::clicked, this, &TeacherInteractionWidget::chooseEllipse);      
	this->connect(this->ui.undo_btn, &QPushButton::clicked, this, &TeacherInteractionWidget::undo);
	this->connect(this->ui.clear_btn, &QPushButton::clicked, this, &TeacherInteractionWidget::clear);
	this->connect(this->ui.add_board_btn, &QPushButton::clicked, this, &TeacherInteractionWidget::addBoard);
	this->connect(this->ui.board_tabWidget, &QTabWidget::tabCloseRequested, this, &TeacherInteractionWidget::deleteBoard);
	this->connect(this->ui.board_tabWidget, &QTabWidget::currentChanged, this, &TeacherInteractionWidget::changeBoard);

	// ��ʼ��
	scroll_area = new QScrollArea();

	this->board_id = 1;

	this->board = new PaintWidget();  // �ȴ���һ������
	this->board_list.append(this->board);  // ��������֮��
	scroll_area->setWidget(this->board);
	scroll_area->setStyleSheet("QScrollArea{border:none;background-color:transparent;}QScrollBar:vertical{border:none;background-color:#ffffff;width:10px;}QScrollBar:vertical:hover{border:none;background-color:rgb(220,220,220);width:10px;}QScrollBar::handle:vertical{border-radius:5px;background:rgb(220,220,220);min-height:20px;}QScrollBar::handle:vertical:hover{border-radius:5px;background:rgb(200,200,200);min-height:20px;}QScrollBar::add-line:vertical{height:0;subcontrol-position:bottom;subcontrol-origin:margin;}QScrollBar::sub-line:vertical{height:0px;subcontrol-position:top;subcontrol-origin:margin;}QScrollBar:horizontal{border:none;background-color:#ffffff;height:10px;}QScrollBar:horizontal:hover{border:none;background-color:rgb(220,220,220);height:10px;}QScrollBar::handle:horizontal{border-radius:5px;background:rgb(220,220,220);min-width:20px;}QScrollBar::handle:horizontal:hover{border-radius:5px;background:rgb(200,200,200);min-width:20px;}QScrollBar::add-line:horizontal{width:0;subcontrol-position:bottom;subcontrol-origin:margin;}QScrollBar::sub-line:horizontal{width:0px;subcontrol-position:top;subcontrol-origin:margin;}");
	this->ui.board_tabWidget->addTab(scroll_area, "board_1");  // ���һ������
	this->ui.black_pen_btn->click();  // Ĭ��Ϊ�ڱʣ�ģ����
	// ���ʡ���Ƥ��Ĭ�Ͽ��
	pen = this->board->getPen();
	pen.setWidth(PEN_WIDTH); 
	this->board->setPen(pen);
	this->ui.pen_width_slider->setValue(PEN_WIDTH);
	this->ui.pen_width_edit->setText(QString::number(PEN_WIDTH));

	rubber = this->board->getRubber();
	rubber.setWidth(RUBBER_WIDTH);
	this->board->setRubber(rubber);
	this->ui.rubber_width_slider->setValue(RUBBER_WIDTH);
	this->ui.rubber_width_edit->setText(QString::number(RUBBER_WIDTH));
}

TeacherInteractionWidget::~TeacherInteractionWidget() {
	for (int index = 0; index < this->board_list.count(); index++) {
		if (this->board_list[index] != nullptr) {
			delete this->board_list[index];
		}
	}
}

/*
	�������ʴ�ϸ
	value-qslider���ص�ֵ
*/
void TeacherInteractionWidget::setPenWidth(int value) {
	QPen pen = this->board->getPen();

	this->ui.pen_width_edit->setText(QString::number(value));
	pen.setWidth(value);
	this->board->setPen(pen);

	return;
}

/*
	����pen_slider
*/
void TeacherInteractionWidget::setPenSlider() {
	QString text = this->ui.pen_width_edit->text();
	int value = text.toInt();

	// ��ֵ�������
	if (value > 99) {
		this->ui.pen_width_edit->setText("99");
	}
	if (value < 1) {
		this->ui.pen_width_edit->setText("1");
	}

	this->ui.pen_width_slider->setValue(text.toInt());

	return;
}
 
/*
	������Ƥ�ߴ�ϸ
	value-qslider���ص�ֵ
*/
void TeacherInteractionWidget::setRubberWidth(int value) {
	QPen rubber = this->board->getRubber();

	this->ui.rubber_width_edit->setText(QString::number(value));
	rubber.setWidth(value);
	this->board->setRubber(rubber);

	return;
}

/*
	����rubber_slider
*/
void TeacherInteractionWidget::setRubberSlider() {
	QString text = this->ui.rubber_width_edit->text();
	int value = text.toInt();

	// ��ֵ�������
	if (value > 99) {
		this->ui.rubber_width_edit->setText("99");
	}
	if (value < 1) {
		this->ui.rubber_width_edit->setText("1");
	}

	this->ui.rubber_width_slider->setValue(text.toInt());

	return;
}

/*
	ѡ���ɫ����
*/
void TeacherInteractionWidget::chooseBlackPen() {
	QPen pen = this->board->getPen();

	pen.setBrush(QColor(0, 0, 0));
	this->showCurrentColor("rgb(0, 0, 0)");
	this->board->setPen(pen);
	this->board->setToolType(PaintWidget::PEN);

	return;
}

/*
	ѡ����ɫ����
*/
void TeacherInteractionWidget::chooseBluePen() {
	QPen pen = this->board->getPen();

	pen.setBrush(QColor(18, 150, 219));
	this->showCurrentColor("rgb(18, 150, 219)");
	this->board->setPen(pen);
	this->board->setToolType(PaintWidget::PEN);

	return;
}

/*
	ѡ���ɫ����
*/
void TeacherInteractionWidget::chooseRedPen() {
	QPen pen = this->board->getPen();

	pen.setBrush(QColor(216, 30, 6));
	this->showCurrentColor("rgb(216, 30, 6)");
	this->board->setPen(pen);
	this->board->setToolType(PaintWidget::PEN);

	return;
}

/*
	�Զ��廭����ɫ
*/
void TeacherInteractionWidget::chooseColorPen() {
	QColorDialog color_dlg; //������ɫѡ�����Ի���
	QRgb color = color_dlg.getRgba();
	QString color_str = QString::number(color, 16); // ����һ��QRgb -> QString
	QPen pen = this->board->getPen();

	pen.setBrush(QColor(color));
	this->showCurrentColor("#" + color_str);
	this->board->setPen(pen);
	this->board->setToolType(PaintWidget::PEN);

	return;
}

/*
	ѡ������ı�
*/
void TeacherInteractionWidget::chooseText() {
	this->board->setToolType(PaintWidget::TEXT);
	
	return;
}

/*
	ѡ����Ƥ��
*/
void TeacherInteractionWidget::chooseRubber() {
	this->board->setToolType(PaintWidget::RUBBER);

	return;
}

/*
	ѡ��ֱ�߹���
*/
void TeacherInteractionWidget::chooseLine() {
	QPen pen = this->board->getPen();

	this->board->setPen(pen);
	this->board->setToolType(PaintWidget::LINE);

	return;
}

/*
	ѡ����ι���
*/
void TeacherInteractionWidget::chooseRect() {
	QPen pen = this->board->getPen();

	this->board->setPen(pen);
	this->board->setToolType(PaintWidget::RECT);

	return;
}

/*
	ѡ����Բ����
*/
void TeacherInteractionWidget::chooseEllipse() {
	QPen pen = this->board->getPen();

	this->board->setPen(pen);
	this->board->setToolType(PaintWidget::ELLIPSE);

	return;
}

/*
	����
	Ϊʲô��ѡ��ֱ���ò���Ϊboard�е�undo��
	��Ϊthis->board�Ǳ仯�ģ�clearͬ��
*/
void TeacherInteractionWidget::undo() {
	this->board->undo();

	return;
}

/*
	���
*/
void TeacherInteractionWidget::clear() {
	this->board->clear();

	return;
}

/*
	��ʾ��ǰ��ɫ
*/
void TeacherInteractionWidget::showCurrentColor(QString color) {

	this->ui.color_pen_btn->setStyleSheet("QPushButton{border: 5px solid " + color + ";background-color: #FCFCFC;}QPushButton:hover{ background - color:#E3E3E3; }QPushButton:checked{ background - color: #CACACA; }");

	return;
}

/*
	�½�����
*/
void TeacherInteractionWidget::addBoard() {
	QScrollArea *scroll_area = new QScrollArea();
	QPen pen, rubber;

	this->board = new PaintWidget();  // �ȴ���һ������
	this->board_list.append(this->board);  // ��������֮��
	scroll_area->setWidget(this->board);
	scroll_area->setStyleSheet("QScrollArea{border:none;background-color:transparent;}QScrollBar:vertical{border:none;background-color:#ffffff;width:10px;}QScrollBar:vertical:hover{border:none;background-color:rgb(220,220,220);width:10px;}QScrollBar::handle:vertical{border-radius:5px;background:rgb(220,220,220);min-height:20px;}QScrollBar::handle:vertical:hover{border-radius:5px;background:rgb(200,200,200);min-height:20px;}QScrollBar::add-line:vertical{height:0;subcontrol-position:bottom;subcontrol-origin:margin;}QScrollBar::sub-line:vertical{height:0px;subcontrol-position:top;subcontrol-origin:margin;}QScrollBar:horizontal{border:none;background-color:#ffffff;height:10px;}QScrollBar:horizontal:hover{border:none;background-color:rgb(220,220,220);height:10px;}QScrollBar::handle:horizontal{border-radius:5px;background:rgb(220,220,220);min-width:20px;}QScrollBar::handle:horizontal:hover{border-radius:5px;background:rgb(200,200,200);min-width:20px;}QScrollBar::add-line:horizontal{width:0;subcontrol-position:bottom;subcontrol-origin:margin;}QScrollBar::sub-line:horizontal{width:0px;subcontrol-position:top;subcontrol-origin:margin;}");
	this->ui.board_tabWidget->addTab(scroll_area, "board_" + QString::number(++this->board_id));  // ���һ������
	this->ui.board_tabWidget->setCurrentIndex(this->ui.board_tabWidget->count() - 1);  // �л������½��Ļ���
	this->ui.board_tabWidget->setTabsClosable(true);  // ִ����Ӳ������ǻ��������϶�����1������ִ��ɾ������
	this->ui.black_pen_btn->click();  // Ĭ��Ϊ�ڱʣ�ģ����
	// ���ʡ���Ƥ��Ĭ�Ͽ��
	pen = this->board->getPen();
	pen.setWidth(PEN_WIDTH);
	this->board->setPen(pen);
	this->ui.pen_width_slider->setValue(PEN_WIDTH);
	this->ui.pen_width_edit->setText(QString::number(PEN_WIDTH));

	rubber = this->board->getRubber();
	rubber.setWidth(RUBBER_WIDTH);
	this->board->setRubber(rubber);
	this->ui.rubber_width_slider->setValue(RUBBER_WIDTH);
	this->ui.rubber_width_edit->setText(QString::number(RUBBER_WIDTH));

	return;
}

/*
	�رջ���
	index-�л��źŴ�����tab�±�
*/
void TeacherInteractionWidget::deleteBoard(int index) {
	PaintWidget *delete_board = this->board_list[index];

	this->board_list.removeAt(index);
	delete delete_board;

	this->ui.board_tabWidget->removeTab(index);
	
	// �����ʣһ�����壬�޷��ر�
	if (this->ui.board_tabWidget->count() == 1) {
		this->ui.board_tabWidget->setTabsClosable(false);
	}

	return;
}

/*
	�л�����
	��board����ǰ�������壩����Ϊ��ǰѡ��Ļ���
	index-�л��źŴ�����tab�±�
*/
void TeacherInteractionWidget::changeBoard(int index) {
	QPen pen, rubber;
	QColor color;
	PaintWidget::ToolType tool_Type;

	this->board = this->board_list[index];  // �л���������
	pen = this->board->getPen();  // ��ȡ��ǰ����ı�
	color = pen.color();  // ��ȡ��ǰ����ı���ɫ
	rubber = this->board->getRubber();  // ��ȡ��ǰ�������Ƥ��
	tool_Type = this->board->getToolType();  // ��ȡ��ǰ����ĵ�ǰѡ�񹤾�


	this->showCurrentColor("#" + QString::number(qRgb(color.red(), color.green(), color.blue()), 16));  // ������ɫ��ʾ
	this->ui.pen_width_slider->setValue(pen.width());  // ���û��ʡ���Ƥ�߿��
	this->ui.rubber_width_slider->setValue(rubber.width());

	// ��������
	switch (tool_Type) {
	case PaintWidget::PEN:
		if (color == QColor(0, 0, 0)) {
			this->ui.black_pen_btn->setChecked(true);
		}
		else if (color == QColor(18, 150, 219)) {
			this->ui.blue_pen_btn->setChecked(true);
		}
		else if (color == QColor(216, 30, 6)) {
			this->ui.red_pen_btn->setChecked(true);
		}
			
		break;
	case PaintWidget::RUBBER:
		this->ui.rubber_btn->setChecked(true);
		break;
	case PaintWidget::LINE:
		this->ui.line_btn->setChecked(true);
		break;
	case PaintWidget::RECT:
		this->ui.rect_btn->setChecked(true);
		break;
	case PaintWidget::ELLIPSE:
		this->ui.ellipse_btn->setChecked(true);
		break;
	case PaintWidget::TEXT:
		this->ui.text_btn->setChecked(true);
		break;
	}

	return;
}
