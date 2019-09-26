#include <QtWidgets/QApplication>
#include "Core/View/Window/teacher_main_window.h"
#include "Core/Controller/controller.h"
#pragma execution_character_set("utf-8")  

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	TeacherMainWindow *win = new TeacherMainWindow();

	CourseBase course_base(QString("101"), QString("数据结构"));
	QList<CourseBase> *courses_base_list = new QList<CourseBase>();
	courses_base_list->append(course_base);
	courses_base_list->append(course_base);
	User::Gender gender = User::Gender::MALE;
	Teacher *user = new Teacher(QString("10001"), QString("你爸爸"), gender, courses_base_list);

	TeacherController *teacher_controller = new TeacherController(win, user);

	return app.exec();
}
