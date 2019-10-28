#pragma once

#include <QString>
#include <QMap>
#include <QDatetime>
#include <QList>
#include <QVector>


class LessonBase {
public:
	LessonBase(const QString &lesson_id, const QDateTime &start_datetime, const QDateTime &end_datetime);
	virtual ~LessonBase() {};
	void setLessonId(const QString &lesson_id) { this->m_lesson_id = lesson_id; return; };
	void setStartDateTime(const QDateTime &start_datetime) { this->m_start_datetime = start_datetime; return; };
	void setEndDateTime(const QDateTime &end_datetime) { this->m_end_datetime = end_datetime; return; };
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
	CourseBase() {};
	CourseBase(const QString &course_id, const QString &course_name);
	virtual ~CourseBase() {};
	void setCourseId(const QString &course_id) { this->m_course_id = course_id; return; };
	void setCourseNmae(const QString &course_name) { this->m_course_name = course_name; return; };
	const QString& courseId() const { return this->m_course_id; };
	const QString& courseName() const { return this->m_course_name; };


protected:
	QString m_course_id;  // ����id
	QString m_course_name;  // ������
};


class RoleBase {
public:
	enum Gender {
		MALE = 0,
		FEMALE
	};

	RoleBase(const QString &uid, const QString &username, const Gender &gender);
	virtual ~RoleBase() {};
	void setUid(const QString &uid) { this->m_uid = uid; return; };
	void setUseranme(const QString &username) { this->m_username; return; };
	void setGender(const Gender &gender) { this->m_gender = gender; return; };
	const QString& uid() const { return this->m_uid; };
	const QString& username() const { return this->m_username; };
	const Gender& gender() const { return this->m_gender; };

protected:
	QString m_uid;  // �û�id
	QString m_username;  // �û���
	Gender m_gender;  // �Ա�
};


class Concentration {
public:
	Concentration() {};
	Concentration(const int &value, const QDateTime &datetime);
	virtual ~Concentration() {};
	void setValue(const int &value) { this->m_value = value; return; };
	void setDateTime(const QDateTime &datetime) { this->m_datetime = datetime; return; };
	const int& value() const { return this->m_value; };
	const QDateTime& datetime() const { return this->m_datetime; };

protected:
	int m_value;  // רע����ֵ 
	QDateTime m_datetime;  // ��¼ʱ��
};


class Lesson : public LessonBase {
public:
	Lesson(const QString &lesson_id, const QDateTime &start_datetime, const QDateTime &end_datetime, const RoleBase &teacher, const QList<RoleBase> &students_list, const QList<Concentration> &concentrations_list,
		const QMap<QString, int> &emotions_statistic_map);
	virtual ~Lesson() {};
	void setTeacher(RoleBase &teacher) { this->m_teacher = teacher; return; };
	void setStudentsList(QList<RoleBase> &students_list) { this->m_students_list = students_list; return; };
	void setConcentrationsList(QList<Concentration> &concentrations_list) { this->m_concentrations_list = concentrations_list; return; };
	void setEmotionStatisticList(QMap<QString, int> &emotions_statistic_map) { this->m_emotions_statistic_map = emotions_statistic_map; return; };
	const RoleBase& teacher() const { return this->m_teacher; };
	const QList<RoleBase>& studentsList() const { return this->m_students_list; };
	const QList<Concentration>& concentrationsList() const { return this->m_concentrations_list; };
	const QMap<QString, int>& emotionsStatisticMap() const { return this->m_emotions_statistic_map; };

protected:
	RoleBase m_teacher;  // ���ÿε��ڿν�ʦ
	QList<RoleBase> m_students_list;  // ���ε�ѧ������
	QList<Concentration> m_concentrations_list;  // ���ÿε�רע����������
	QMap<QString, int> m_emotions_statistic_map;  // ��������ִ�������
};


class Course : public CourseBase{
public:
	Course(const QString &course_id, const QString &course_name, const QList<RoleBase> &teachers_list, const QList<RoleBase> &students_list,
		const QList<LessonBase> &lessons_list, const QDateTime &creation_datetime, const QString &course_key, const int &concentration_avg, const int &num_of_like);
	virtual ~Course() {};
	void setTeachersList(QList<RoleBase> &teachers_list) { this->m_teachers_list = teachers_list; return; };
	void setStudentsList(QList<RoleBase> &students_list) { this->m_students_list = students_list; return; };
	void setLessonsList(QList<LessonBase> &lessons_list) { this->m_lessons_list = lessons_list; return; };
	void setCreationDateTime(QDateTime &creation_datetime) { this->m_creation_datetime = creation_datetime; return; };
	void setCourseKey(QString &course_key) { this->m_course_key = course_key; return; }
	void setConcentrationAvg(int &concentration_avg) { this->m_concentration_avg = concentration_avg; return; }
	void setNumOfLike(int &num_of_like) { this->m_num_of_like = num_of_like; return; }
	const QList<RoleBase>& teachersList() const { return this->m_teachers_list; };
	const QList<RoleBase>& studentsList() const { return this->m_students_list; };
	const QList<LessonBase>& lessonsList() const { return this->m_lessons_list; };
	const QDateTime& creationDateTime() const { return this->m_creation_datetime; };
	const QString& courseKey() const { return this->m_course_key; };
	const int& concentrationAvg() const { return this->m_concentration_avg; };
	const int& numOfLike() const { return this->m_num_of_like; };

protected:
	QList<RoleBase> m_teachers_list;  // ���ڸÿγ̵Ľ�ʦ����
	QList<RoleBase> m_students_list;  // ѡ��ÿγ̵�ѧ������
	QList<LessonBase> m_lessons_list;  // ����ɵĿ�������
	QDateTime m_creation_datetime;  // �γ̴���ʱ��
	QString m_course_key;  // ѡ����
	int m_concentration_avg;  // ƽ��רע��
	int m_num_of_like;  // ������

};


class Room {
public:
	Room() {};
	Room(const QString &room_name, const QString &course_id, const QString &lesson_id, const QString &teacher_id, const QString &teacher_name);
	~Room();
	void setRoomName(const QString &room_name) { this->m_room_name = room_name; return; };
	void setCourseId(const QString &course_id) { this->m_course_id = course_id; };
	void setLessonId(const QString &lesson_id) { this->m_lesson_id = lesson_id; return; };
	void setTeacherId(const QString &teacher_id) { this->m_teacher_id = teacher_id; return; };
	void setTeacherName(const QString &teacher_name) { this->m_teacher_name = teacher_name; return; };
	QString& roomName() { return this->m_room_name; };
	QString& courseId() { return this->m_course_id; };
	QString& lessonId() { return this->m_lesson_id; };
	QString& teacherId() { return this->m_teacher_id; };
	QString& teacherName() { return this->m_teacher_name; };

protected:
	QString m_room_name;
	QString m_course_id;
	QString m_lesson_id;
	QString m_teacher_id;
	QString m_teacher_name;
};


class Teacher : public RoleBase {
public:
	Teacher(QString &uid, QString &username, Gender &gender);
	virtual ~Teacher() {};
protected:

};


class Student : public RoleBase {
public:
	Student(QString &uid, QString &username, Gender &gender, int &concentration_avg);
	~Student() {};
	void setConcentrationAvg(int &concentration_avg) { this->m_concentration_avg = concentration_avg; return; };
	int& concentrationAvg() { return this->m_concentration_avg; };

protected:
	int m_concentration_avg;
};