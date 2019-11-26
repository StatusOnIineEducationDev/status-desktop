#pragma once

#include <QString>
#include <QList>
#include <QPixmap>
#include "Core/Model/course.h"
#include "Core/Client/onlineEdu.h"

class User {
public:
	static void createUser(QPixmap &user_pic, QString &uid, QString &username,
		QList<CourseBase> *courses_base_list, AccountType account_type,
		UserStatus user_status) {

		G_USER_PIC = user_pic
		G_UID = uid;
		G_USERNAME = username;
		G_COURSES_BASE_LIST = courses_base_list;
		G_ACCOUNT_TYPE = account_type;
		G_USER_STATUS = user_status;

		return;
	}

	static QPixmap G_USER_PIC;  // 用户头像
	static QString G_UID;  // id
	static QString G_USERNAME;  // 用户名
	static QList<CourseBase> *G_COURSES_BASE_LIST;  // 课堂基本信息列表
	static AccountType G_ACCOUNT_TYPE;
	static UserStatus G_USER_STATUS;  // 用户当前状态（Free/InClass）
};


