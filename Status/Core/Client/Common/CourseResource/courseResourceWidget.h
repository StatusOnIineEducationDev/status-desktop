#pragma once
#pragma execution_character_set("utf-8")
#include <QWidget>
#include <QJsonObject>
#include <QJsonArray>
#include <QFileDialog>
#include "ui_c_courseResourceWidget.h"
#include "fileItemWidget.h"
#include "uploadFileDialog.h"
#include "Core/Network/httpRequest.h"
#include "Core/Model/user.h"
#include "Core/Client/conf.h"


class CourseResourceWidget : public QWidget {
	Q_OBJECT

public:
	CourseResourceWidget(QWidget *parent = nullptr);
	virtual ~CourseResourceWidget();
	const Ui::CourseResourceWidget& ui() const { return this->m_ui; };

	void setCourseId(const QString &course_id) { this->m_course_id = course_id; return; };
	void updateAllData(const QString& course_id);

protected:
	void openUploadFileDialog(const QString &file_path);

	void updateFileListWidget(const QList<QMap<QString, QVariant>> &info_list);
	void updateFileInfoList(const QJsonObject &data);
	void updateFileCount(const QList<QMap<QString, QVariant>> &info_list);

	void getIntoLoadingStatus();
	void getOutFromLoadingStatus();
	void openFileDialog();

	void getFileInfoListRequest();
	void getFileInfoListRequestSuccess(const QJsonObject &data);

	Ui::CourseResourceWidget m_ui;

	UploadFileDialog *m_upload_file_dialog;

	QString m_course_id;
	/*
		|-info(m_file_info_list)
			|-course_id(QString)
			|-file_id(QString)
			|-filename(QString)
			|-upload_timestamp(int)
			|-uploader(QString)
			|-file_size(int)(单位：Byte)
	*/
	QList<QMap<QString, QVariant>> m_file_info_list;  // 文件信息
};