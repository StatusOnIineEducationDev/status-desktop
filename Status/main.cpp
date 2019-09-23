#include <QtWidgets/QApplication>
#include "Core/View/Window/teacher_main_window.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TeacherMainWindow w;
	w.show();

	return a.exec();
}
