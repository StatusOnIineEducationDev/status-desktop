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
//	CourseBasic course_base1(QString("101"), QString("数据结构"));
//	CourseBasic course_base2(QString("102"), QString("概率论与数理统计"));
//	CourseBasic course_base3(QString("103"), QString("计算机网络"));
//	CourseBasic course_base4(QString("104"), QString("数据库系统原理"));
//	CourseBasic course_base5(QString("105"), QString("软件工程"));
//	QList<CourseBasic> courses_base_list;
//	courses_base_list.append(course_base1);
//	courses_base_list.append(course_base2);
//	courses_base_list.append(course_base3);
//	courses_base_list.append(course_base4);
//	courses_base_list.append(course_base5);
//	user = new User(
//		QPixmap(":/pic/Resources/material/pic/teacher.png"),
//		QString("10001"), 
//		QString("教师"), 
//		courses_base_list, 
//		AccountType::Teacher, 
//		UserStatus::Free);
//
//	LoginWindow	*widget = new LoginWindow;
//	widget->show();
//
//	return app.exec();
//}
