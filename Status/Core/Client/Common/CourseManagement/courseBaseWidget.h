#pragma once
#include <QWidget>
#include <QListView>
#include <QJsonObject>
#include "ui_c_courseBaseWidget.h"
#include "Core/Network/httpRequest.h"
#include "Core/Model/user.h"
#include "Core/Client/conf.h"


class CourseBaseWidget : public QWidget {
	Q_OBJECT

signals:
	void courseSwitched(const QString &course_id);

public:
	CourseBaseWidget(QWidget *parent = nullptr);
	virtual ~CourseBaseWidget();
	const Ui::CourseBaseWidget& ui() const { return this->m_ui; };

	void updateAllData(const QString &course_id);

protected:
	void updateCourseComboBox();
	void emitSignalCourseSwitched(const int index);

	void getCourseBaseInfoRequest(const QString &course_id);
	void getCourseBaseInfoSuccess(const QJsonObject &data);

	Ui::CourseBaseWidget m_ui;
};
