#pragma once
#pragma execution_character_set("utf-8")
#include <QWidget>
#include "ui_c_courseResourceWidget.h"
#include "fileItemWidget.h"


class CourseResourceWidget : public QWidget {
	Q_OBJECT

public:
	CourseResourceWidget(QWidget *parent = nullptr);
	virtual ~CourseResourceWidget();
	const Ui::CourseResourceWidget& ui() const { return this->m_ui; };

	void updateAllData() {};

protected:
	void updateFileListWidget();

	Ui::CourseResourceWidget m_ui;

	/*
		|-info(m_file_info_list)
			|-file_id(QString)
			|-filename(QString)
			|-upload_timestamp(int)
			|-uploader(QString)
			|-file_size(int)(单位：Byte)
	*/
	QList<QMap<QString, QVariant>> m_file_info_list;  // 文件信息
};