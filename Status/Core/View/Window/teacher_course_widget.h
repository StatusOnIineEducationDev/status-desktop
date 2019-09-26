#pragma once

#include "ui_teacher_course_widget.h"
#include <QtWidgets/QMainWindow>
#include <QListView>
#include <QThread>
#include <QNetworkReply>

class TeacherCourseWidget : public QWidget {
	Q_OBJECT

public:
	TeacherCourseWidget(QWidget *parent = Q_NULLPTR);
	const Ui::TeacherCourseWidget& ui() const { return this->m_ui; };

private:
	Ui::TeacherCourseWidget m_ui;
};
