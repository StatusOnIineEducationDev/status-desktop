#pragma once

#include <QString>
#include <QMap>
#include <QDatetime>
#include <QList>
#include <QVector>
#include "Core/Client/onlineEdu.h" 


class CourseBasic {
public:
	CourseBasic() {};
	CourseBasic(const QString &course_id, const QString &course_name);
	virtual ~CourseBasic() {};
	void setCourseId(const int &course_id) { this->m_course_id = course_id; return; };
	void setCourseNmae(const QString &course_name) { this->m_course_name = course_name; return; };
	const QString& courseId() const { return this->m_course_id; };
	const QString& courseName() const { return this->m_course_name; };


protected:
	QString m_course_id;  // ¿ÎÌÃid
	QString m_course_name;  // ¿ÎÌÃÃû
};
