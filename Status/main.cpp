#include <QtWidgets/QApplication>
#include "Core/Client/Student/MainWindow/s_mainWindow.h"
#include "Core/Client/Teacher/MainWindow/t_mainWindow.h"
#include "Core/Model/course.h"
#include "Core/Model/user.h"
#include "Core/Component/toast.h"
#include "Core/Client/onlineEdu.h"
#include "Core/Client/conf.h"
#pragma execution_character_set("utf-8")  

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

	CourseBase course_base1(QString("101"), QString("数据结构"));
	CourseBase course_base2(QString("102"), QString("概率论与数理统计"));
	CourseBase course_base3(QString("103"), QString("计算机网络"));
	CourseBase course_base4(QString("104"), QString("数据库系统原理"));
	CourseBase course_base5(QString("105"), QString("软件工程"));
	QList<CourseBase> *courses_base_list = new QList<CourseBase>();
	courses_base_list->append(course_base1);
	courses_base_list->append(course_base2);
	courses_base_list->append(course_base3);
	courses_base_list->append(course_base4);
	courses_base_list->append(course_base5);
	
	User::createUser(
		QPixmap(":/pic/Resources/material/pic/teacher.png"),
		QString("10001"), 
		QString("教师"), 
		courses_base_list, 
		AccountType::Teacher, 
		UserStatus::Free);
	TeacherMainWindow *t_win = new TeacherMainWindow;
	t_win->show();
	Toast::setWin(t_win);
	/*User::createUser(
		QPixmap(":/pic/Resources/material/pic/student.png"),
		QString("10002"), 
		QString("学生"), 
		courses_base_list, 
		AccountType::Student, 
		UserStatus::Free);
	StudentMainWindow *s_win = new StudentMainWindow;
	s_win->show();
	Toast::setWin(s_win);*/

	ReadConf::read();

	return app.exec();
}