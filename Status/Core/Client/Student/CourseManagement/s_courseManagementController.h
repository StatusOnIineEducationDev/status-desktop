#pragma once
#include "s_courseManagementWidget.h"
#include "Core/Model/user.h"
#include "Core/Component/toast.h"


class SCourseManagementController : public QObject {
	Q_OBJECT

public:
	SCourseManagementController(User *user, QObject *parent = nullptr);
	virtual ~SCourseManagementController();

	SCourseManagementWidget *courseManagementWidget() const { return this->m_course_management_widget; };

	void showCourseManagementWidget(SMainWindow *parent);

protected:
	void initCourseManagementWidget(SMainWindow *parent);
	//void initAffiliatedWidget();
	//void initController();

	SCourseManagementWidget *m_course_management_widget;

	User *m_user;
};