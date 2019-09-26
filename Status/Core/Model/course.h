#pragma once

#include <QString>
#include <QDatetime>
#include <QList>
#include <QVector>
#include "Core/Model/user.h"
#include "Core/Model/model_base.h"


class Concentration {
public:

protected:
	int m_value;  // רע����ֵ
	QDateTime m_datetime;  // ��¼ʱ��
	//int m_fatigue;  // ƣ�Ͷ�
	//Emotion emotion;  // ����
	//int m_num_of_yawn;  // ���Ƿ����
};


class Lesson : public LessonBase {
public:
	enum Emotion {
		ANGRY = 0,
		DISGUST,
		FEAR,
		HAPPY,
		SAD,
		SURPRISE,
		NEUTRAL
	};

	Lesson(QString &lesson_id, QDateTime &start_datetime, QDateTime &end_datetime, UserBase &teacher, QList<UserBase> *students_list, QList<Concentration> *concentrations_list,
		QList<int> *emotions_statistic_list);
	virtual ~Lesson() {};
	void setTeacher(UserBase &teacher) { this->m_teacher = teacher; return; };
	void setStudentsList(QList<UserBase> *students_list) { this->m_students_list = students_list; return; };
	void setConcentrationsList(QList<Concentration> *concentrations_list) { this->m_concentrations_list = concentrations_list; return; };
	void setEmotionStatisticList(QList<int> *emotions_statistic_list) { this->m_emotions_statistic_list = emotions_statistic_list; return; };
	const UserBase& teacher() const { return this->m_teacher; };
	const QList<UserBase>* studentsList() const { return this->m_students_list; };
	const QList<Concentration>* concentrationsList() const { return this->m_concentrations_list; };
	const QList<int>* emotionsStatisticList() const { return this->m_emotions_statistic_list; };

protected:
	UserBase m_teacher;  // ���ÿε��ڿν�ʦ
	QList<UserBase> *m_students_list;  // ���ε�ѧ������
	QList<Concentration> *m_concentrations_list;  // ���ÿε�רע����������
	QList<int> *m_emotions_statistic_list;  // ��������ִ�������
};


class Course : public CourseBase{
public:
	Course(QString &course_id, QString &course_name, QList<UserBase> *teachers_list, QList<UserBase> *students_list, QList<LessonBase> *lessons_list);
	virtual ~Course() {};
	void setTeachersList(QList<UserBase> *teachers_list) { this->m_teachers_list = teachers_list; return; };
	void setStudentsList(QList<UserBase> *students_list) { this->m_students_list = students_list; return; };
	void setLessonsList(QList<LessonBase> *lessons_list) { this->m_lessons_list = lessons_list; return; };
	void setCourseKey(QString &course_key) { this->m_course_key = course_key; return; }
	void setNumOfLike(int &num_of_like) { this->m_num_of_like = num_of_like; return; }
	const QList<UserBase>* teachersList() const { return this->m_teachers_list; };
	const QList<UserBase>* studentsList() const { return this->m_students_list; };
	const QList<LessonBase>* lessonsList() const { return this->m_lessons_list; };
	const QString courseKey() const { return this->m_course_key; }
	const int numOfLike() const { return this->m_num_of_like; }

protected:
	QList<UserBase> *m_teachers_list;  // ���ڸÿγ̵Ľ�ʦ����
	QList<UserBase> *m_students_list;  // ѡ��ÿγ̵�ѧ������
	QList<LessonBase> *m_lessons_list;  // ����ɵĿ�������
	QString m_course_key;  // ѡ����
	int m_num_of_like;  // ������

};
