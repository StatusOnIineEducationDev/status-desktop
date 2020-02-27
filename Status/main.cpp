#pragma execution_character_set("utf-8")  
#include <QApplication>
#include "Core/Model/user.h"
#include "Core/Client/conf.h"
#include "Core/Client/Common/Login/loginWindow.h"

#include "Core/Client/Common/Tips/c_tipsDialog.h"

User *user = nullptr;

int main(int argc, char *argv[]) {
	/*
		������Ҷ�
	*/
	QApplication app(argc, argv);
	ReadConf::read();

	LoginWindow *login_win = new LoginWindow;
	login_win->show();

	/*
		����д����	
	*/
	//TipsDialog *win = new TipsDialog;
	//win->show();


	return app.exec();
}
