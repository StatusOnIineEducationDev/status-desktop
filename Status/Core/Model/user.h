#pragma once
#include <QString>
#include <QList>
#include <QPixmap>
#include "Core/Model/course.h"
#include "Core/Client/onlineEdu.h"

class User;

extern User *user;

class User {
public:
	User(const QPixmap &user_pic, const QString &uid, const QString &username,
		const QList<CourseBasic> &course_list, const AccountType &account_type,
		const UserStatus &user_status);
	~User();

	const QPixmap& getUserPic() const { return this->m_user_pic; };
	const QString& getUid() const { return this->m_uid; };
	const QString& getUsername() const { return this->m_username; };
	const QList<CourseBasic> &getCourseList() const { return this->m_course_list; };
	const AccountType &getAccountType() const { return this->m_account_type; };
	const UserStatus &getUserStatus() const { return this->m_user_status; };
	void setUserPic(const QPixmap &user_pic) { this->m_user_pic = user_pic; return; };
	void setUid(const int &uid) { this->m_uid = uid; return; };
	void setUsername(const QString &username) { this->m_username = username; return; };
	void setCourseList(const QList<CourseBasic> &course_list) { this->m_course_list = course_list; return; };
	void setAccountType(const AccountType &account_type) { this->m_account_type = account_type; return; };
	void setUserStatus(const UserStatus &user_status) { this->m_user_status = user_status; return; };


protected:
	QPixmap m_user_pic;  // 用户头像
	QString m_uid;  // id
	QString m_username;  // 用户名
	QList<CourseBasic> m_course_list;  // 课堂基本信息列表
	AccountType m_account_type;
	UserStatus m_user_status;  // 用户当前状态（Free/InClass）
};


