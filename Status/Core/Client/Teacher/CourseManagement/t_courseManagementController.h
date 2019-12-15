#pragma once
#include "t_courseManagementWidget.h"
#include "Core/Model/user.h"
#include "Core/Component/Toast/toast.h"


class TCourseManagementController : public QObject {
	Q_OBJECT

public:
	TCourseManagementController(User *user, QObject *parent = nullptr);
	virtual ~TCourseManagementController();

	TCourseManagementWidget *courseManagementWidget() const { return this->m_course_management_widget; };

	void showCourseManagementWidget(TMainWindow *parent);
	void hideCourseManagementWidget(TMainWindow *parent);

protected:
	void initCourseManagementWidget(TMainWindow *parent);
	//void initAffiliatedWidget();
	//void initController();

	void updateCourseComboBox();

	TCourseManagementWidget *m_course_management_widget;

	User *m_user;
};