#include <QtWidgets/QApplication>
#include "Core/Client/Teacher/t_mainWindow.h"
#include "Core/Client/Teacher/t_mainWindowController.h"
#include "Core/Client/Student/s_mainWindow.h"
#include "Core/Client/Student/s_mainWindowController.h"
#include "Core/Component/toast.h"
#include "Core/Client/onlineEdu.h"
#include "Core/Client/conf.h"
#include "Core/Client/Common/login.h"
#pragma execution_character_set("utf-8")  

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	
	ReadConf::read();
	LoginWindow *login_win = new LoginWindow;
	login_win->show();

	return app.exec();
}