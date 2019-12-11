#pragma once
#include <QWidget>
#include <QDateTime>
#include "ui_c_fileItemWidget.h"
#include "Core/Tools/tools.h"


class FileItemWidget : public QWidget {
	Q_OBJECT

public:
	FileItemWidget(const QString &course_id, const QString &file_id, 
		const QString &resource_title, const QString &filename, 
		const int &upload_timestamp, const QString &uploader, const int &file_size, 
		QWidget *parent = nullptr);
	virtual ~FileItemWidget();
	const Ui::FileItemWidget& ui() const { return this->m_ui; };

	const QString& getCourseId() const { return this->m_course_id; };
	const QString& getFileId() const { return this->m_file_id; };
	const QString& getResourceTitle() const { return this->m_resource_title; };
	const QString& getFilename() const { return this->m_filename; };
	const int& getUploadTimestamp() const { return this->m_upload_timestamp; };
	const QString& getUploader() const { return this->m_uploader; };
	const int& getFileSize() const { return this->m_file_size; };

protected:
	Ui::FileItemWidget m_ui;

	QString m_course_id;
	QString m_file_id;
	QString m_resource_title;
	QString m_filename;
	int m_upload_timestamp;
	QString m_uploader;
	int m_file_size;
};
