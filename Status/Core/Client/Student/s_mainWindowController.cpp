#include "s_mainWindowController.h"


SMainWindowController::SMainWindowController(SMainWindow *win, User *user)
	: m_win(win), m_user(user), m_online_classroom_controller(nullptr),
	m_course_management_controller(nullptr){
	Ui::SMainWindow ui = this->m_win->ui();

	this->m_win->show();

	this->connect(ui.course_btn, &QPushButton::clicked, this, &SMainWindowController::showCourseManagementWidget);
	this->connect(ui.interaction_btn, &QPushButton::clicked, this, &SMainWindowController::showOnlineClassroomWidget);
	this->connect(ui.buttonGroup, static_cast<void (QButtonGroup::*)(QAbstractButton*)>(&QButtonGroup::buttonPressed), this, &SMainWindowController::buttonPush);
	this->connect(ui.undo_btn, &QPushButton::clicked, this, &SMainWindowController::undo);
	this->connect(ui.redo_btn, &QPushButton::clicked, this, &SMainWindowController::redo);

	// ����Ĭ����ҳ
	this->showCourseManagementWidget();

	// ����Ĭ������
	ui.undo_btn->setEnabled(false);
	ui.redo_btn->setEnabled(false);
}

SMainWindowController::~SMainWindowController() {
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

void SMainWindowController::clearWidget() {
	// �������ù���
	if (this->m_course_management_controller != nullptr) {
		this->m_course_management_controller->hideCourseManagementWidget(this->m_win);
		delete this->m_course_management_controller;
		this->m_course_management_controller = nullptr;
		}
	// �������߽���
	if (this->m_online_classroom_controller != nullptr) {
		this->m_online_classroom_controller->hideOnlineClassroomWidget(this->m_win);
		if (this->m_user->userStatus() != UserStatus::InClass) {
			delete this->m_online_classroom_controller;
			this->m_online_classroom_controller = nullptr;
		}
	}

	return;
}

void SMainWindowController::showCourseManagementWidget() {
	this->clearWidget();  // ����������е�ǰ��ʾ���Ӵ�
	if (this->m_course_management_controller == nullptr) {
		this->m_course_management_controller = new SCourseManagementController(this->m_user, this);  // ��̬�����Ӵ�
	}
	this->m_course_management_controller->showCourseManagementWidget(this->m_win);

	return;
}

void SMainWindowController::showOnlineClassroomWidget() {
	this->clearWidget();  // ����������е�ǰ��ʾ���Ӵ�
	if (this->m_online_classroom_controller == nullptr) {
		this->m_online_classroom_controller = new SOnlineClassroomController(this->m_user);  // ��̬�����Ӵ�
	}
	this->m_online_classroom_controller->showOnlineClassroomWidget(this->m_win);

	return;
}

void SMainWindowController::undo() {
	QAbstractButton *now_child_widget_button = this->m_win->ui().buttonGroup->checkedButton();
	QAbstractButton *last_child_widget_button = this->m_child_widget_undo_stack.pop();

	this->m_child_widget_redo_stack.push(now_child_widget_button);
	this->m_win->ui().redo_btn->setEnabled(true);
	// ��������ģ����������Ҫ���ⴥ����ջ�źţ����ѭ������˵��ǰ��ȡ������
	this->disconnect(this->m_win->ui().buttonGroup, static_cast<void (QButtonGroup::*)(QAbstractButton*)>(&QButtonGroup::buttonPressed), this, &SMainWindowController::buttonPush);
	last_child_widget_button->click();
	this->connect(this->m_win->ui().buttonGroup, static_cast<void (QButtonGroup::*)(QAbstractButton*)>(&QButtonGroup::buttonPressed), this, &SMainWindowController::buttonPush);


	// ���ջ�գ���ť������
	if (this->m_child_widget_undo_stack.isEmpty()) {
		this->m_win->ui().undo_btn->setEnabled(false);
	}

	return;
}

void SMainWindowController::redo() {
	QAbstractButton *now_child_widget_button = this->m_win->ui().buttonGroup->checkedButton();
	QAbstractButton *next_child_widget_button = this->m_child_widget_redo_stack.pop();

	this->m_child_widget_undo_stack.push(now_child_widget_button);
	this->m_win->ui().undo_btn->setEnabled(true);
	// ��������ģ����������Ҫ���ⴥ����ջ�źţ����ѭ������˵��ǰ��ȡ������
	this->disconnect(this->m_win->ui().buttonGroup, static_cast<void (QButtonGroup::*)(QAbstractButton*)>(&QButtonGroup::buttonPressed), this, &SMainWindowController::buttonPush);
	next_child_widget_button->click();
	this->connect(this->m_win->ui().buttonGroup, static_cast<void (QButtonGroup::*)(QAbstractButton*)>(&QButtonGroup::buttonPressed), this, &SMainWindowController::buttonPush);


	// ���ջ�գ���ť������
	if (this->m_child_widget_redo_stack.isEmpty()) {
		this->m_win->ui().redo_btn->setEnabled(false);
	}

	return;
}

void SMainWindowController::buttonPush(QAbstractButton *button) {
	QAbstractButton *last_child_widget_button = this->m_win->ui().buttonGroup->checkedButton();  // ����˰�ťǰ����һ��ť

	this->m_child_widget_undo_stack.push(last_child_widget_button);

	this->m_win->ui().undo_btn->setEnabled(true);
	// ����ǰ��ջ��գ�ͬʱ��ֹǰ��
	this->m_child_widget_redo_stack.clear();
	this->m_win->ui().redo_btn->setEnabled(false);

	return;
}