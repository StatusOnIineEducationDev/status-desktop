#include "s_mainWindow.h"


StudentMainWindow::StudentMainWindow(QWidget *QWidget)
	: MainWindow(QWidget), m_function_button_widget(nullptr),
	m_online_classroom_widget(nullptr) {
	this->m_function_button_widget = new StudentFunctionButtonWidget(this);
	this->m_ui.function_button_widget_layout->
		addWidget(this->m_function_button_widget);

	Ui::StudentFunctionButtonWidget button_ui = this->m_function_button_widget->ui();
	this->connect(button_ui.online_classroom_btn, &QPushButton::clicked,
		this, &StudentMainWindow::switchOnlineClassroomWidget);
}

StudentMainWindow::~StudentMainWindow() {

};

void StudentMainWindow::clearWidget() {
	// �������߽���
	if (this->m_online_classroom_widget != nullptr) {
		this->m_online_classroom_widget->hide();
		if (User::G_USER_STATUS == UserStatus::Free) {
			delete this->m_online_classroom_widget;
			this->m_online_classroom_widget = nullptr;
		}
	}

	return;
}

void StudentMainWindow::switchOnlineClassroomWidget() {
	this->clearWidget();  // ����������е�ǰ��ʾ���Ӵ�
	if (this->m_online_classroom_widget == nullptr) {
		this->m_online_classroom_widget = new StudentOnlineClassroomWidget(this);  // ��̬�����Ӵ�
		this->m_ui.widget_layout->addWidget(this->m_online_classroom_widget);
	}
	this->m_online_classroom_widget->show();

	return;
}