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

	static QPixmap G_USER_PIC;  // �û�ͷ��
	static QString G_UID;  // id
	static QString G_USERNAME;  // �û���
	static QList<CourseBase> *G_COURSES_BASE_LIST;  // ���û�����Ϣ�б�
	static AccountType G_ACCOUNT_TYPE;
	static UserStatus G_USER_STATUS;  // �û���ǰ״̬��Free/InClass��
};


