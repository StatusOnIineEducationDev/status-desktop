#pragma once

#include "Core/View/Window/teacher_main_window.h"
#include "Core/Model/user.h"
#include "Core/Model/course.h"

class TeacherControllerBase : public QObject {
	Q_OBJECT

public:
	TeacherControllerBase(TeacherMainWindow *win, Teacher *user);
	virtual ~TeacherControllerBase() {};
	void setWin(TeacherMainWindow* win) { this->m_win = win; return; };
	void setUser(Teacher* user) { this->m_user = user; return; };
	const TeacherMainWindow* win() const { return this->m_win; };
	const Teacher* user() const { return this->m_user; };

protected:
	TeacherMainWindow* m_win;
	Teacher* m_user;
};



class TeacherCourseWidgetController : public TeacherControllerBase {
	Q_OBJECT

public:
	TeacherCourseWidgetController(TeacherMainWindow *win, Teacher *user);
	virtual ~TeacherCourseWidgetController() {};

public slots:
	void connectInit();
	void updateCourseComboBox();
	void getCourseDataRequest(const int &current_index);
	void getCourseDataSuccess(const QJsonObject &data);
	//void getCourseDataFail();

private:
	void updateCourseBaseInfo();

	Course *m_course;
};



class TeacherController : public TeacherCourseWidgetController {
	Q_OBJECT

public:
	TeacherController(TeacherMainWindow *win, Teacher* user);
	virtual ~TeacherController() {};
};