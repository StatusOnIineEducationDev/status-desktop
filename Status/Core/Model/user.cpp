#include "Core/Model/user.h"

User::User(QString &uid, QString &username, QList<CourseBase> *courses_base_list, UserStatus user_status)
	: m_uid(uid), m_username(username), m_courses_base_list(courses_base_list), m_user_status(user_status) {

}
