#pragma execution_character_set("utf-8")  
#include <QApplication>
#include "Core/Model/user.h"
#include "Core/Client/conf.h"
#include "Core/Client/Common/Login/loginWindow.h"

#include "Core/Client/Common/Member/memberWidget.h"

User *user = nullptr;

int main(int argc, char *argv[]) {
	/*
		这里别乱动
	*/
	QApplication app(argc, argv);
	ReadConf::read();

	LoginWindow *login_win = new LoginWindow;
	login_win->show();

	/*
		测试写这里	
	*/
	//MemberWidget *win = new MemberWidget;
	//win->show();

	//for (int i = 0; i < 100; i++) {
	//	win->addMember(
	//		QString::number(i), "213123",
	//		QPixmap(":/pic/Resources/material/pic/student.png"),
	//		QPixmap(":/pic/Resources/material/pic/online.png"));
	//}
	//win->setMemberStatusPic("999", QPixmap(":/pic/Resources/material/pic/offline.png"));

	return app.exec();
}
