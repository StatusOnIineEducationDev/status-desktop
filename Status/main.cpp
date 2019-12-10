#pragma execution_character_set("utf-8")  
#include <QApplication>
#include "Core/Model/user.h"
#include "Core/Client/conf.h"
#include "Core/Client/Common/Login/loginWindow.h"


User *user = nullptr;

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	ReadConf::read();

	LoginWindow	*login_win = new LoginWindow;
	login_win->show();

	return app.exec();
}

//#pragma execution_character_set("utf-8")  
//#include <QtWidgets/QApplication>
//#include "Core/Client/Common/Login/loginWindow.h"
//
//User *user = nullptr;
//
//int main(int argc, char *argv[]) {
//	QApplication app(argc, argv);
//	
//	CourseBasic course_base1(QString("101"), QString("���ݽṹ"));
//	CourseBasic course_base2(QString("102"), QString("������������ͳ��"));
//	CourseBasic course_base3(QString("103"), QString("���������"));
//	CourseBasic course_base4(QString("104"), QString("���ݿ�ϵͳԭ��"));
//	CourseBasic course_base5(QString("105"), QString("�������"));
//	QList<CourseBasic> courses_base_list;
//	courses_base_list.append(course_base1);
//	courses_base_list.append(course_base2);
//	courses_base_list.append(course_base3);
//	courses_base_list.append(course_base4);
//	courses_base_list.append(course_base5);
//	user = new User(
//		QPixmap(":/pic/Resources/material/pic/teacher.png"),
//		QString("10001"), 
//		QString("��ʦ"), 
//		courses_base_list, 
//		AccountType::Teacher, 
//		UserStatus::Free);
//
//	LoginWindow	*widget = new LoginWindow;
//	widget->show();
//
//	return app.exec();
//}
