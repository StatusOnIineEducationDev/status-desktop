#include "Core/Model/course.h"

LessonBase::LessonBase(const QString &lesson_id, const QDateTime &start_datetime, const QDateTime &end_datetime)
	: m_lesson_id(lesson_id), m_start_datetime(start_datetime), m_end_datetime(end_datetime) {

}


//**************************************************************************************************
//**************************************************************************************************


CourseBasic::CourseBasic(const QString &course_id, const QString &course_name) 
	: m_course_id(course_id), m_course_name(course_name) {

}


//**************************************************************************************************
//**************************************************************************************************


RoleBase::RoleBase(const QString &uid, const QString &username, const Gender &gender)
	: m_uid(uid), m_username(username), m_gender(gender) {

}

Concentration::Concentration(const int &concentration_value, const QDateTime &datetime)
	: m_concentration_value(concentration_value), m_datetime(datetime) {

}


//**************************************************************************************************
//**************************************************************************************************


Lesson::Lesson(const QString &lesson_id, const QDateTime &start_datetime, const QDateTime &end_datetime, const RoleBase &teacher,
	const QList<RoleBase> &students_list, const QList<Concentration> &concentrations_list, const QMap<QString, int> &emotions_statistic_map)
	: LessonBase(lesson_id, start_datetime, end_datetime), m_teacher(teacher), m_students_list(students_list), 
	m_concentrations_list(concentrations_list),m_emotions_statistic_map(emotions_statistic_map) {

}

//**************************************************************************************************
//**************************************************************************************************

Course::Course(const QString &course_id, const QString &course_name, const QList<RoleBase> &teachers_list, const QList<RoleBase> &students_list,
	const QList<LessonBase> &lessons_list, const QDateTime &creation_datetime, const QString &course_key, const int &concentration_avg, const int &num_of_like)
	: CourseBasic(course_id, course_name), m_teachers_list(teachers_list), m_students_list(students_list), m_lessons_list(lessons_list), 
	m_creation_datetime(creation_datetime), m_course_key(course_key), m_concentration_avg(concentration_avg), m_num_of_like(num_of_like) {

}


//**************************************************************************************************
//**************************************************************************************************


Teacher::Teacher(QString &uid, QString &username, Gender &gender)
	: RoleBase(uid, username, gender) {

}


//**************************************************************************************************
//**************************************************************************************************


//Student::Student(QString &uid, QString &username, Gender &gender, int &concentration_avg)
//	: RoleBase(uid, username, gender, courses_base_list)


//**************************************************************************************************
//**************************************************************************************************
Room::Room(const QString &room_name, const QString &course_id, const QString &lesson_id, const QString &teacher_id, const QString &teacher_name)
	: m_room_name(room_name), m_course_id(course_id), m_lesson_id(lesson_id), m_teacher_id(teacher_id), m_teacher_name(teacher_name) {

}

Room::~Room() {

}
