#pragma once
#include <QWidget>
#include <QListView>
#include <QJsonObject>
#include "ui_c_courseBasicWidget.h"
#include "Core/Network/httpRequest.h"
#include "Core/Model/user.h"
#include "Core/Client/conf.h"


class CourseBasicWidget : public QWidget {
	Q_OBJECT

signals:
	void courseSwitched(const QString &course_id);

public:
	CourseBasicWidget(QWidget *parent = nullptr);
	virtual ~CourseBasicWidget();
	const Ui::CourseBasicWidget& ui() const { return this->m_ui; };

	void updateAllData(const QString &course_id);
	void updateCourseComboBox();

protected:
	void emitSignalCourseSwitched(const int index);

	void getCourseBasicInfoRequest(const QString &course_id);
	void getCourseBasicInfoRequestSuccess(const QJsonObject &data);

	Ui::CourseBasicWidget m_ui;
};
