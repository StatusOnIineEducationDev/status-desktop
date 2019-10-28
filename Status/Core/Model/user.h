#pragma once

#include <QString>
#include <QList>
#include "Core/Model/course.h"

class User {
public:
	User(QString &uid, QString &m_username, QList<CourseBase> *m_courses_base_list);
	virtual ~User() {};
	void setUid(QString &uid) { this->m_uid = uid; return; };
	void setUseranme(QString &username) { this->m_username; return; };
	const QString& uid() const { return this->m_uid; };
	const QString& username() const { return this->m_username; };
	void setCourseBaseList(QList<CourseBase> *courses_base_list) { this->m_courses_base_list = courses_base_list; };
	QList<CourseBase>* coursesBaseList() const { return this->m_courses_base_list; };

private:
	QString m_uid;
	QString m_username;
	QList<CourseBase> *m_courses_base_list;  // 课堂基本信息列表
};


