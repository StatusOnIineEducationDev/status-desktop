#pragma once
#pragma execution_character_set("utf-8")  
#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QJsonObject>
#include <QListView>
#include <QMouseEvent>
#include "ui_t_createCourseDialog.h"
#include "Core/Component/Toast/toast.h"
#include "Core/Component/Loading/loading.h"
#include "Core/Network/httpRequest.h"
#include "Core/Client/conf.h"
#include "Core/Model/user.h"


class TeacherCreateCourseDialog : public QDialog {
	Q_OBJECT

signals:
	void createCourseSuccess();

public:
	TeacherCreateCourseDialog(QWidget *parent = nullptr);
	~TeacherCreateCourseDialog();
	const Ui::TeacherCreateCourseDialog& ui() const { return this->m_ui; };

protected:
	void nextStep();
	void lastStep();
	void createCourse();

	void getCoursePictureFromLocal();

	void createCourseRequest();
	void createCourseRequestSuccess(const QJsonObject &data);
	void uploadCoursePictureRequest(const QString &course_id);
	void uploadCoursePictureRequestSuccess(const QJsonObject &data);

	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

	Ui::TeacherCreateCourseDialog m_ui;
	
	QFileInfo m_pic_info;  // 上传的图片信息

	bool is_pressed;  // 鼠标左键是否按下
	bool is_moving;  // 正在移动
	QPoint start_pos;  // 鼠标左键点下时的坐标
};