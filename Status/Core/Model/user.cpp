#include "Core/Model/user.h"

User::User(QString &uid, QString &username, Gender &gender, QList<CourseBase> *courses_base_list)
	: UserBase(uid, username, gender), m_courses_base_list(courses_base_list) {

}

Teacher::Teacher(QString &uid, QString &username, Gender &gender, QList<CourseBase> *courses_base_list)
	: User(uid, username, gender, courses_base_list) {

}