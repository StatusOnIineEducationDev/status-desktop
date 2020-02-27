#include "t_mainWindow.h"


TeacherMainWindow::TeacherMainWindow(QWidget *QWidget)
	: MainWindow(QWidget), m_function_button_widget(nullptr), 
	m_course_management_widget(nullptr), m_online_classroom_widget(nullptr) {
	
	this->m_ui.client_type_text->setText("��ʦ��");

	this->loadFunctionButtonWidget();

	this->switchCourseMangementWidget();
}

TeacherMainWindow::~TeacherMainWindow() {

};

void TeacherMainWindow::clearWidget() {
	// �����γ̹���
	if (this->m_course_management_widget != nullptr) {
		this->m_course_management_widget->hide();
		delete this->m_course_management_widget;
		this->m_course_management_widget = nullptr;
	}
	// �������߽���
	if (this->m_online_classroom_widget != nullptr) {
		this->m_online_classroom_widget->hide();
		if (user->getUserStatus() == UserStatus::Free) {
			delete this->m_online_classroom_widget;
			this->m_online_classroom_widget = nullptr;
		}
	}

	return;
}

void TeacherMainWindow::switchCourseMangementWidget() {
	this->clearWidget();  // ����������е�ǰ��ʾ���Ӵ�
	if (this->m_course_management_widget == nullptr) {
		this->m_course_management_widget = new TeacherCourseManagementWidget(this);  // ��̬�����Ӵ�
		this->m_ui.widget_layout->addWidget(this->m_course_management_widget);
	}
	this->m_course_management_widget->show();

	return;
}

void TeacherMainWindow::switchOnlineClassroomWidget() {
	this->clearWidget();  // ����������е�ǰ��ʾ���Ӵ�
	if (this->m_online_classroom_widget == nullptr) {
		this->m_online_classroom_widget = new TeacherOnlineClassroomWidget(this);  // ��̬�����Ӵ�
		this->m_ui.widget_layout->addWidget(this->m_online_classroom_widget);

		// �����źŰ�
		this->connect(this->m_online_classroom_widget,
			&TeacherOnlineClassroomWidget::quitLessonRequestSuccess,
			this,
			&TeacherMainWindow::switchOnlineClassroomWidget);
		// �����źŰ�
		this->connect(this->m_online_classroom_widget,
			&TeacherOnlineClassroomWidget::closeEnterDialog,
			this->m_function_button_widget->ui().course_management_btn,
			&QPushButton::click);
	}
	this->m_online_classroom_widget->show();

	return;
}

void TeacherMainWindow::loadFunctionButtonWidget() {
	// �������ع�����
	this->m_function_button_widget = new TeacherFunctionButtonWidget(this);
	this->m_ui.function_button_widget_layout->
		addWidget(this->m_function_button_widget);

	// �����ź�����
	Ui::TeacherFunctionButtonWidget button_ui = this->m_function_button_widget->ui();

	this->connect(button_ui.online_classroom_btn, &QPushButton::clicked,
		this, &TeacherMainWindow::switchOnlineClassroomWidget);
	this->connect(button_ui.course_management_btn, &QPushButton::clicked,
		this, &TeacherMainWindow::switchCourseMangementWidget);

	return;
}