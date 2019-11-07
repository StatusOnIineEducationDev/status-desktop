#include "tmainwindowcontroller.h"


TMainWindowController::TMainWindowController(TMainWindow *win, User *user)
	: m_win(win), m_user(user), m_online_classroom_controller(nullptr) {
	Ui::TMainWindow ui = this->m_win->ui();

	this->m_win->show();

	this->connect(ui.course_btn, &QPushButton::clicked, this, &TMainWindowController::showTeacherCourseWidget);
	this->connect(ui.interaction_btn, &QPushButton::clicked, this, &TMainWindowController::showOnlineClassroomWidget);
	this->connect(ui.buttonGroup, static_cast<void (QButtonGroup::*)(QAbstractButton*)>(&QButtonGroup::buttonPressed), this, &TMainWindowController::buttonPush);
	this->connect(ui.undo_btn, &QPushButton::clicked, this, &TMainWindowController::undo);
	this->connect(ui.redo_btn, &QPushButton::clicked, this, &TMainWindowController::redo);

	// ——默认首页
	this->showTeacherCourseWidget();

	// ——默认设置
	ui.undo_btn->setEnabled(false);
	ui.redo_btn->setEnabled(false);
}

TMainWindowController::~TMainWindowController() {
	if (this->m_win != nullptr) {
		delete this->m_win;
	}
	if (this->m_user != nullptr) {
		delete this->m_user;
	}
	if (this->m_online_classroom_controller != nullptr) {
		delete this->m_online_classroom_controller;
	}
}

void TMainWindowController::clearWidget() {
	// 实时互动
	if (this->m_online_classroom_controller != nullptr) {
		if (this->m_user->userStatus() != UserStatus::InClass) {
			delete this->m_online_classroom_controller;
			this->m_online_classroom_controller = nullptr;
		}
		else {
			this->m_win->ui().widget_layout->removeWidget(this->m_online_classroom_controller->onlineClassroomWidget());
		}
	}

	return;
}

void TMainWindowController::showTeacherCourseWidget() {
	this->clearWidget();  // 先清除主窗中当前显示的子窗
	//this->m_teacher_course_widget_controller = new TeacherCourseWidgetController(this->m_win, this->m_user);  // 动态创建子窗

	return;
}

void TMainWindowController::showOnlineClassroomWidget() {
	this->clearWidget();  // 先清除主窗中当前显示的子窗
	if (this->m_online_classroom_controller == nullptr) {
		this->m_online_classroom_controller = new TOnlineClassroomController(this->m_user, this);  // 动态创建子窗
		this->m_online_classroom_controller->showOnlineClassroomWidget(this->m_win);
	}

	return;
}

void TMainWindowController::undo() {
	QAbstractButton *now_child_widget_button = this->m_win->ui().buttonGroup->checkedButton();
	QAbstractButton *last_child_widget_button = this->m_child_widget_undo_stack.pop();

	this->m_child_widget_redo_stack.push(now_child_widget_button);
	this->m_win->ui().redo_btn->setEnabled(true);
	// ——这里模拟点击，但需要避免触发入栈信号，造成循环，因此点击前先取消连接
	this->disconnect(this->m_win->ui().buttonGroup, static_cast<void (QButtonGroup::*)(QAbstractButton*)>(&QButtonGroup::buttonPressed), this, &TMainWindowController::buttonPush);
	last_child_widget_button->click();
	this->connect(this->m_win->ui().buttonGroup, static_cast<void (QButtonGroup::*)(QAbstractButton*)>(&QButtonGroup::buttonPressed), this, &TMainWindowController::buttonPush);


	// 如果栈空，按钮不可用
	if (this->m_child_widget_undo_stack.isEmpty()) {
		this->m_win->ui().undo_btn->setEnabled(false);
	}

	return;
}

void TMainWindowController::redo() {
	QAbstractButton *now_child_widget_button = this->m_win->ui().buttonGroup->checkedButton();
	QAbstractButton *next_child_widget_button = this->m_child_widget_redo_stack.pop();

	this->m_child_widget_undo_stack.push(now_child_widget_button);
	this->m_win->ui().undo_btn->setEnabled(true);
	// ——这里模拟点击，但需要避免触发入栈信号，造成循环，因此点击前先取消连接
	this->disconnect(this->m_win->ui().buttonGroup, static_cast<void (QButtonGroup::*)(QAbstractButton*)>(&QButtonGroup::buttonPressed), this, &TMainWindowController::buttonPush);
	next_child_widget_button->click();
	this->connect(this->m_win->ui().buttonGroup, static_cast<void (QButtonGroup::*)(QAbstractButton*)>(&QButtonGroup::buttonPressed), this, &TMainWindowController::buttonPush);


	// 如果栈空，按钮不可用
	if (this->m_child_widget_redo_stack.isEmpty()) {
		this->m_win->ui().redo_btn->setEnabled(false);
	}

	return;
}

void TMainWindowController::buttonPush(QAbstractButton *button) {
	QAbstractButton *last_child_widget_button = this->m_win->ui().buttonGroup->checkedButton();  // 点击此按钮前的上一按钮

	this->m_child_widget_undo_stack.push(last_child_widget_button);

	this->m_win->ui().undo_btn->setEnabled(true);
	// ——前进栈清空，同时禁止前进
	this->m_child_widget_redo_stack.clear();
	this->m_win->ui().redo_btn->setEnabled(false);

	return;
}