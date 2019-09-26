#pragma once

#include <QString>
#include <QDatetime>

class LessonBase {
public:
	LessonBase(QString &lesson_id, QDateTime &start_datetime, QDateTime &end_datetime);
	virtual ~LessonBase() {};
	void setLessonId(QString &lesson_id) { this->m_lesson_id = lesson_id; return; };
	void setStartDateTime(QDateTime &start_datetime) { this->m_start_datetime = start_datetime; return; };
	void setEndDateTime(QDateTime &end_datetime) { this->m_end_datetime = end_datetime; return; };
	const QString& lessonId() const { return this->m_lesson_id; };
	const QDateTime& startDatetime() const { return this->m_start_datetime; };
	const QDateTime& endDatetime() const { return this->m_end_datetime; };

protected:
	QString m_lesson_id;  // ����id
	QDateTime m_start_datetime;  // �Ͽ�ʱ��
	QDateTime m_end_datetime;  // ����ʱ��
};


class CourseBase {
public:
	CourseBase(QString &course_id, QString &course_name);
	virtual ~CourseBase() {};
	void setCourseId(QString &course_id) { this->m_course_id = course_id; return; };
	void setCourseNmae(QString &course_name) { this->m_course_name = course_name; return; };
	const QString& courseId() const { return this->m_course_id; };
	const QString& courseName() const { return this->m_course_name; };


protected:
	QString m_course_id;  // ����id
	QString m_course_name;  // ������
};


class UserBase {
public:
	enum Gender {
		MALE = 0,
		FEMALE
	};

	UserBase(QString &uid, QString &username, Gender &gender);
	virtual ~UserBase() {};
	void setUid(QString &uid) { this->m_uid = uid; return; };
	void setUseranme(QString &username) { this->m_username; return; };
	void setGender(Gender &gender) { this->m_gender = gender; return; };
	const QString& uid() const { return this->m_uid; };
	const QString& username() const { return this->m_username; };
	const Gender& gender() const { return this->m_gender; };

protected:
	QString m_uid;  // �û�id
	QString m_username;  // �û���
	Gender m_gender;  // �Ա�
};