#pragma once

#include <QString>
#include <QList>
#include "Core/Model/model_base.h"


class User : public UserBase {
public:
	User(QString &uid, QString &m_username, Gender &m_gender, QList<CourseBase> *m_courses_base_list);
	virtual ~User() {};
	void setCourseBaseList(QList<CourseBase> *courses_base_list) { this->m_courses_base_list = courses_base_list; };
	const QList<CourseBase>* coursesBaseList() const { return this->m_courses_base_list; };

private:
	QList<CourseBase> *m_courses_base_list;  // 课堂基本信息列表
};


class Teacher : public User {
public:
	Teacher(QString &uid, QString &username, Gender &gender, QList<CourseBase> *courses_base_list);
	~Teacher() {};
protected:

};


class Student : public User {
public:

protected:

};