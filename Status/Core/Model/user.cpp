#include "Core/Model/user.h"

User::User(const QPixmap &user_pic, const QString &uid, const QString &username,
	const QList<CourseBasic> &course_list, const AccountType &account_type,
	const UserStatus &user_status)
	: m_user_pic(user_pic), m_uid(uid), m_username(username), 
	m_course_list(course_list), m_account_type(account_type), 
	m_user_status(user_status) {

}

User::~User() {

}