#include <QtWidgets/QApplication>
#include "Core/Client/Teacher/t_mainWindow.h"
#include "Core/Client/Teacher/t_mainWindowController.h"
#include "Core/Client/Student/s_mainWindow.h"
#include "Core/Client/Student/s_mainWindowController.h"
#include "Core/Component/toast.h"
#include "Core/Client/onlineEdu.h"
#include "Core/Client/conf.h"
#pragma execution_character_set("utf-8")  

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);

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
	User *user = new User(QString("10001"), QString("��ְ�"), courses_base_list, UserStatus::Free);
	User *user_2 = new User(QString("10002"), QString("��ְ�"), courses_base_list, UserStatus::Free);

	TMainWindow *t_win = new TMainWindow();
	SMainWindow *s_win = new SMainWindow();
	TMainWindowController *teacher_controller = new TMainWindowController(t_win, user);
	SMainWindowController *student_controller = new SMainWindowController(s_win, user_2);

	Toast::setWin(t_win);
	ReadConf::read();

	return app.exec();
}