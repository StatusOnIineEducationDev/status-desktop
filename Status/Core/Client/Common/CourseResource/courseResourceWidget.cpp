#include "courseResourceWidget.h"


CourseResourceWidget::CourseResourceWidget(QWidget *parent)
	: QWidget(parent) {
	m_ui.setupUi(this);

	// ——信号连接

	QMap<QString, QVariant> info;
	info["file_id"] = "111";
	info["filename"] = "拉拉啊啦啦啦.txt";
	info["upload_timestamp"] = 1575301104;
	info["uploader"] = "教师";
	info["file_size"] = 111;
	this->m_file_info_list.append(info);
	this->m_file_info_list.append(info);
	this->m_file_info_list.append(info);
	this->m_file_info_list.append(info);

	this->updateFileListWidget();
}

CourseResourceWidget::~CourseResourceWidget() {

}

void CourseResourceWidget::updateFileListWidget() {
	QListWidgetItem *item;
	FileItemWidget *item_widget;
	QMap<QString, QVariant> info_temp;

	for (int index = 0; index < this->m_file_info_list.count(); index++) {
		item = new QListWidgetItem(this->m_ui.file_listWidget);
		info_temp = this->m_file_info_list[index];
		item_widget = new FileItemWidget(info_temp["filename"].toString(), 
			info_temp["upload_timestamp"].toInt(), info_temp["uploader"].toString(),
			info_temp["file_size"].toInt(), this->m_ui.file_listWidget);

		item->setSizeHint(QSize(item_widget->width(), item_widget->height()));
		this->m_ui.file_listWidget->addItem(item);
		this->m_ui.file_listWidget->setItemWidget(item, item_widget);
	}

	return;
}