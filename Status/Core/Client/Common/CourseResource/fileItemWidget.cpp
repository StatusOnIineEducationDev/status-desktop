#include "fileItemWidget.h"


FileItemWidget::FileItemWidget(const QString &filename, const int &upload_timetsamp,
const QString &uploader, const int &file_size, QWidget *parent)
	: QWidget(parent) {
	m_ui.setupUi(this);

	// 截取文件名 文件类型
	int index = filename.lastIndexOf(".");
	QString plain_filename = filename.left(index),
		file_type = filename.mid(index + 1);

	this->m_ui.file_type_pic->
		setPixmap(QPixmap(":/file_type/Resources/material/file_type/" + file_type + ".png"));
	this->m_ui.filename_text->setText(plain_filename);
	this->m_ui.upload_time_text->
		setText(QDateTime::fromTime_t(upload_timetsamp).toString("yyyy-MM-dd hh:mm:ss"));
	this->m_ui.uploader_text->setText(uploader);
	this->m_ui.uploader_text->setText(QString::number(file_size));
}

FileItemWidget::~FileItemWidget() {

}