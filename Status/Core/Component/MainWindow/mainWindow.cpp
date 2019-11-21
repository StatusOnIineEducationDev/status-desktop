#include "mainWindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	m_ui.setupUi(this);

	// 初始化
	this->is_pressed = false;
	this->is_moving = false;
	this->is_resizing = false;

	// 窗口属性设置
	this->setWindowFlag(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground, true);

	// 信号绑定
	this->connect(this->m_ui.full_or_normal_btn, &QPushButton::clicked, this, &MainWindow::setWindowFull);
}

void MainWindow::setWindowFull() {
	QRect window = QApplication::desktop()->availableGeometry();
	this->setGeometry(-5, -5, window.width() + 10, window.height() + 10);

	// 更换槽函数
	this->disconnect(this->m_ui.full_or_normal_btn, &QPushButton::clicked, this, &MainWindow::setWindowFull);
	this->connect(this->m_ui.full_or_normal_btn, &QPushButton::clicked, this, &MainWindow::setWindowNormal);

	// 设置tooltip
	this->m_ui.full_or_normal_btn->setToolTip(QString::fromLocal8Bit("向下还原"));

	emit this->windowResized();

	return;
}

void MainWindow::setWindowNormal() {
	QRect window = QApplication::desktop()->availableGeometry();
	QPoint central_point = QPoint(window.width() / 2, window.height() / 2);

	// 在屏幕中心显示向下还原的窗口
	this->setGeometry(central_point.x() - (this->baseSize().width() / 2), central_point.y() - (this->baseSize().height() / 2), this->baseSize().width(), this->baseSize().height());

	// 更换槽函数
	this->disconnect(this->m_ui.full_or_normal_btn, &QPushButton::clicked, this, &MainWindow::setWindowNormal);
	this->connect(this->m_ui.full_or_normal_btn, &QPushButton::clicked, this, &MainWindow::setWindowFull);

	// 设置tooltip
	this->m_ui.full_or_normal_btn->setToolTip(QString::fromLocal8Bit("最大化"));

	emit this->windowResized();

	return;
}

void MainWindow::undo() {
	QAbstractButton *now_child_widget_button = this->m_ui.list_buttonGroup->checkedButton();
	QAbstractButton *last_child_widget_button = this->m_child_widget_undo_stack.pop();

	this->m_child_widget_redo_stack.push(now_child_widget_button);
	this->m_ui.redo_btn->setEnabled(true);
	// ——这里模拟点击，但需要避免触发入栈信号，造成循环，因此点击前先取消连接
	this->disconnect(this->m_ui.list_buttonGroup, static_cast<void (QButtonGroup::*)(QAbstractButton*)>(&QButtonGroup::buttonPressed), this, &TMainWindowController::buttonPush);
	last_child_widget_button->click();
	this->connect(this->m_ui.list_buttonGroup, static_cast<void (QButtonGroup::*)(QAbstractButton*)>(&QButtonGroup::buttonPressed), this, &TMainWindowController::buttonPush);


	// 如果栈空，按钮不可用
	if (this->m_child_widget_undo_stack.isEmpty()) {
		this->m_ui.undo_btn->setEnabled(false);
	}

	return;
}

void MainWindow::redo() {
	QAbstractButton *now_child_widget_button = this->m_ui.buttonGroup->checkedButton();
	QAbstractButton *next_child_widget_button = this->m_child_widget_redo_stack.pop();

	this->m_child_widget_undo_stack.push(now_child_widget_button);
	this->m_ui.undo_btn->setEnabled(true);
	// ——这里模拟点击，但需要避免触发入栈信号，造成循环，因此点击前先取消连接
	this->disconnect(this->m_ui.list_buttonGroup, static_cast<void (QButtonGroup::*)(QAbstractButton*)>(&QButtonGroup::buttonPressed), this, &TMainWindowController::buttonPush);
	next_child_widget_button->click();
	this->connect(this->m_ui.list_buttonGroup, static_cast<void (QButtonGroup::*)(QAbstractButton*)>(&QButtonGroup::buttonPressed), this, &TMainWindowController::buttonPush);


	// 如果栈空，按钮不可用
	if (this->m_child_widget_redo_stack.isEmpty()) {
		this->m_ui.redo_btn->setEnabled(false);
	}

	return;
}

void MainWindow::buttonPush(QAbstractButton *button) {
	QAbstractButton *last_child_widget_button = this->m_ui.list_buttonGroup->checkedButton();  // 点击此按钮前的上一按钮

	this->m_child_widget_undo_stack.push(last_child_widget_button);

	this->m_ui.undo_btn->setEnabled(true);
	// ——前进栈清空，同时禁止前进
	this->m_child_widget_redo_stack.clear();
	this->m_ui.redo_btn->setEnabled(false);

	return;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
	// 计算鼠标当前位置
	// 如果鼠标在title bar且左键按下，则执行移动
	if (this->is_moving) {
		this->move(this->pos() + event->pos() - this->start_pos);
	}
	else if (this->is_resizing) {
		// 窗体缩放
		this->resize(QSize(event->pos().x(), event->pos().y()));
		emit this->windowResized();
	}

	return;
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton) {
		this->is_pressed = true;
		this->start_pos = QPoint(event->pos().x(), event->pos().y());
		if (this->start_pos.x() < this->width() && this->start_pos.y() < 40) {
			this->is_moving = true;
		}
		else if (this->start_pos.x() > this->width() - 20 && this->start_pos.y() > this->height() - 20) {
			this->is_resizing = true;
		}
	}

	return;
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
	this->is_pressed = false;
	this->is_moving = false;
	this->is_resizing = false;

	return;
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event) {
	if (this->start_pos.x() < this->width() && this->start_pos.y() < 40) {
		// 窗口已经最大化
		if (m_ui.full_or_normal_btn->isChecked()) {
			m_ui.full_or_normal_btn->setChecked(false);
			this->setWindowNormal();
		}
		// 未最大化
		else {
			m_ui.full_or_normal_btn->setChecked(true);
			this->setWindowFull();
		}
	}
}