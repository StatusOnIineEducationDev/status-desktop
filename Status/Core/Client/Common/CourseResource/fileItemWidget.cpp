#include "fileItemWidget.h"


FileItemWidget::FileItemWidget(const QString &course_id, const QString &file_id,
	const QString &filename, const int &upload_timestamp, const QString &uploader,
	const int &file_size, QWidget *parent)
	: m_course_id(course_id), m_file_id(file_id), m_filename(filename), 
	m_upload_timestamp(upload_timestamp), m_uploader(uploader), m_file_size(file_size),
	QWidget(parent) {
	m_ui.setupUi(this);

	// 截取文件名 文件类型
	QString file_type = filename.mid(filename.lastIndexOf(".") + 1);

	this->m_ui.file_type_pic->
		setPixmap(QPixmap(":/file_type/Resources/material/file_type/" + file_type + ".png"));
	this->m_ui.filename_text->setText(filename);
	this->m_ui.upload_time_text->
		setText(QDateTime::fromTime_t(upload_timestamp).toString("yyyy-MM-dd hh:mm:ss"));
	this->m_ui.uploader_text->setText(uploader);
	this->m_ui.file_size_text->setText(formatSize(file_size));
}

FileItemWidget::~FileItemWidget() {

}