#pragma once

#include <QString>
#include <QList>
#include "Core/Model/course.h"
#include "Core/Client/online_education.h"

class User {
public:
	User(QString &uid, QString &m_username, QList<CourseBase> *m_courses_base_list, UserStatus user_status);
	virtual ~User() {};
	void setUid(QString &uid) { this->m_uid = uid; return; };
	void setUseranme(QString &username) { this->m_username; return; };
	void setCourseBaseList(QList<CourseBase> *courses_base_list) { this->m_courses_base_list = courses_base_list; };
	void setUserStatus(UserStatus user_status) { this->m_user_status = user_status; };
	const QString& uid() const { return this->m_uid; };
	const QString& username() const { return this->m_username; };
	const UserStatus& userStatus() const { return this->m_user_status; };
	QList<CourseBase>* coursesBaseList() const { return this->m_courses_base_list; };

private:
	QString m_uid;  // id
	QString m_username;  // �û���
	QList<CourseBase> *m_courses_base_list;  // ���û�����Ϣ�б�
	UserStatus m_user_status;  // �û���ǰ״̬��Free/InClass��
};


