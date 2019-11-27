#include "login.h"

LoginWindow::LoginWindow(QWidget *parent)
	: QMainWindow(parent) {
	m_ui.setupUi(this);


	// �źŰ�
	this->connect(this->m_ui.confirm_btn, &QPushButton::clicked, 
		this, &LoginWindow::login);
}

LoginWindow::~LoginWindow() {

}

void LoginWindow::login() {
	CourseBase course_base1(QString("101"), QString("���ݽṹ"));
	CourseBase course_base2(QString("102"), QString("������������ͳ��"));
	CourseBase course_base3(QString("103"), QString("���������"));
	CourseBase course_base4(QString("104"), QString("���ݿ�ϵͳԭ��"));
	CourseBase course_base5(QString("105"), QString("�������"));
	QList<CourseBase> *courses_base_list = new QList<CourseBase>();
	courses_base_list->append(course_base1);
	courses_base_list->append(course_base2);
	courses_base_list->append(course_base3);
	courses_base_list->append(course_base4);
	courses_base_list->append(course_base5);
	User *user = new User(QString("10001"), QString("��ʦ"), courses_base_list, UserStatus::Free);
	User *user_2 = new User(QString("10002"), QString("ѧ��"), courses_base_list, UserStatus::Free);

	if (this->m_ui.student_checkBox->isChecked()) {
		s_win = new SMainWindow();
		student_controller = new SMainWindowController(s_win, user_2);
		Toast::setWin(s_win);
	}
	else {
		t_win = new TMainWindow();
		teacher_controller = new TMainWindowController(t_win, user);
		Toast::setWin(t_win);
	}

	return;
}
