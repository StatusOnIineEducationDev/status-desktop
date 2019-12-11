#pragma once
#pragma execution_character_set("utf-8")  
#include <QDialog>
#include <QMouseEvent>
#include <QFileInfo>
#include "ui_c_uploadFileDialog.h"
#include "Core/Tools/tools.h"
#include "Core/Network/httpRequest.h"
#include "Core/Client/conf.h"
#include "Core/Model/user.h"


class UploadFileDialog : public QDialog {
	Q_OBJECT

signals:
	void uploadSuccess();

public:
	UploadFileDialog(const QFileInfo &info, const QString &course_id,
		QWidget *parent = nullptr);
	~UploadFileDialog();
	const Ui::UploadFileDialog& ui() const { return this->m_ui; };

	void setCourseId(const QString &course_id) { this->m_course_id = course_id; return; }

protected:
	void upload();
	void uploadCourseResourceRequest();
	void uploadCourseResourceRequestSuccess(const QJsonObject &data);

	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

	Ui::UploadFileDialog m_ui;

	QFileInfo m_info;
	QString m_course_id;

	bool is_pressed;  // 鼠标左键是否按下
	bool is_moving;  // 正在移动
	QPoint start_pos;  // 鼠标左键点下时的坐标
};