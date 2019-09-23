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
	void test(QJsonObject data);

signals:
	void operate(const QString &command, const QString &type, const QJsonObject &data);

private:
	Ui::TeacherCourseWidget ui;
};
