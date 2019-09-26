#include "Core/Model/model_base.h"


LessonBase::LessonBase(QString &lesson_id, QDateTime &start_datetime, QDateTime &end_datetime) 
	: m_lesson_id(lesson_id), m_start_datetime(start_datetime), m_end_datetime(end_datetime) {

}

//**************************************************************************************************
//**************************************************************************************************


CourseBase::CourseBase(QString &course_id, QString &course_name) : m_course_id(course_id), m_course_name(course_name) {

}

//**************************************************************************************************
//**************************************************************************************************

UserBase::UserBase(QString &uid, QString &username, Gender &gender)
	: m_uid(uid), m_username(username), m_gender(gender) {

}