#include "Core/Model/course.h"


Lesson::Lesson(QString &lesson_id, QDateTime &start_datetime, QDateTime &end_datetime, UserBase &teacher,
	QList<UserBase> *students_list, QList<Concentration> *concentrations_list, QList<int> *emotions_statistic_list)
	: LessonBase(lesson_id, start_datetime, end_datetime), m_teacher(teacher), m_students_list(students_list), 
	m_concentrations_list(concentrations_list),m_emotions_statistic_list(emotions_statistic_list) {

}

//**************************************************************************************************
//**************************************************************************************************

Course::Course(QString &course_id, QString &course_name, QList<UserBase> *teachers_list, QList<UserBase> *students_list, QList<LessonBase> *lessons_list)
	: CourseBase(course_id, course_name), m_teachers_list(teachers_list), m_students_list(students_list), m_lessons_list(lessons_list) {

}
