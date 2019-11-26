#include "t_mainWindow.h"


TeacherMainWindow::TeacherMainWindow(QWidget *QWidget)
	: MainWindow(QWidget), m_function_button_widget(nullptr),
	m_online_classroom_widget(nullptr) {
	this->m_function_button_widget = new TeacherFunctionButtonWidget(this);
	this->m_ui.function_button_widget_layout->
		addWidget(this->m_function_button_widget);

	Ui::TeacherFunctionButtonWidget button_ui = this->m_function_button_widget->ui();
	this->connect(button_ui.online_classroom_btn, &QPushButton::clicked,
		this, &TeacherMainWindow::switchOnlineClassroomWidget);
}

TeacherMainWindow::~TeacherMainWindow() {

};

void TeacherMainWindow::clearWidget() {
	// ——在线教室
	if (this->m_online_classroom_widget != nullptr) {
		this->m_online_classroom_widget->hide();
		if (User::G_USER_STATUS == UserStatus::Free) {
			delete this->m_online_classroom_widget;
			this->m_online_classroom_widget = nullptr;
		}
	}

	return;
}

void TeacherMainWindow::switchOnlineClassroomWidget() {
	this->clearWidget();  // 先清除主窗中当前显示的子窗
	if (this->m_online_classroom_widget == nullptr) {
		this->m_online_classroom_widget = new TeacherOnlineClassroomWidget(this);  // 动态创建子窗
		this->m_ui.widget_layout->addWidget(this->m_online_classroom_widget);
	}
	this->m_online_classroom_widget->show();

	return;
}