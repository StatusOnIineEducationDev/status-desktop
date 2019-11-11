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
	void hideCourseManagementWidget(SMainWindow *parent);

protected:
	void initCourseManagementWidget(SMainWindow *parent);
	//void initAffiliatedWidget();
	//void initController();

	void updateCourseComboBox();

	SCourseManagementWidget *m_course_management_widget;

	User *m_user;
};