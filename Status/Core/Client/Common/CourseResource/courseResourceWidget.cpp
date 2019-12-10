#include "courseResourceWidget.h"


CourseResourceWidget::CourseResourceWidget(QWidget *parent)
	: QWidget(parent), m_upload_file_dialog(nullptr) {
	m_ui.setupUi(this);

	// ——信号连接
	this->connect(this->m_ui.upload_btn, &QPushButton::clicked,
		this, &CourseResourceWidget::openFileDialog);
	this->connect(this->m_ui.refresh_btn, &QPushButton::clicked,
		this, &CourseResourceWidget::getFileInfoListRequest);
}

CourseResourceWidget::~CourseResourceWidget() {

}

void CourseResourceWidget::updateAllData(const QString& course_id) {
	this->setCourseId(course_id);
	this->getFileInfoListRequest();

	return;
}

void CourseResourceWidget::openUploadFileDialog(const QString &file_path) {
	QFileInfo info(file_path);

	this->m_upload_file_dialog = new UploadFileDialog(info, this->m_course_id, this);
	this->m_upload_file_dialog->setModal(true);  // 模态（这里与直接用exec()有区别）
	this->m_upload_file_dialog->show();

	return;
}

void CourseResourceWidget::updateFileListWidget(
	const QList<QMap<QString, QVariant>> &info_list) {
	QListWidgetItem *item;
	FileItemWidget *item_widget;
	QMap<QString, QVariant> info_temp;

	this->getIntoLoadingStatus();
	this->m_ui.file_listWidget->clear();
	for (int index = 0; index < info_list.count(); index++) {
		item = new QListWidgetItem(this->m_ui.file_listWidget);
		info_temp = info_list[index];
		item_widget = new FileItemWidget(info_temp["course_id"].toString(),
			info_temp["file_id"].toString(), info_temp["filename"].toString(),
			info_temp["upload_timestamp"].toInt(), info_temp["uploader"].toString(),
			info_temp["file_size"].toInt(), this->m_ui.file_listWidget);

		item->setSizeHint(QSize(item_widget->width(), item_widget->height()));
		this->m_ui.file_listWidget->addItem(item);
		this->m_ui.file_listWidget->setItemWidget(item, item_widget);
		
		this->m_ui.file_count_text->
			setText(QString::number(this->m_ui.file_listWidget->count()));
		QApplication::processEvents();  // 防止GUI假死
	}
	this->updateFileCount(info_list);
	this->getOutFromLoadingStatus();

	return;
}

void CourseResourceWidget::updateFileInfoList(const QJsonObject &data) {
	QMap<QString, QVariant> *info_temp;
	QJsonObject *json_obj_temp = nullptr;
	QJsonArray *json_arr = &data["file_info_list"].toArray();

	// ——加载file_info_list
	this->m_file_info_list.clear();
	for (int index = 0; index < json_arr->count(); index++) {
		json_obj_temp = &json_arr->at(index).toObject();
		info_temp = new QMap<QString, QVariant>;

		info_temp->insert("course_id", json_obj_temp->value("uid").toString());
		info_temp->insert("file_id", json_obj_temp->value("file_id").toString());
		info_temp->insert("filename", json_obj_temp->value("filename").toString());
		info_temp->insert("upload_timestamp", json_obj_temp->value("upload_timestamp").toInt());
		info_temp->insert("uploader", json_obj_temp->value("uploader").toString());
		info_temp->insert("file_size", json_obj_temp->value("file_size").toInt());

		this->m_file_info_list.append(*info_temp);
	}

	return;
}

void CourseResourceWidget::updateFileCount(const QList<QMap<QString, QVariant>> &info_list) {
	this->m_ui.file_count_text->setText(QString::number(info_list.count()));
	
	return;
}

void CourseResourceWidget::getIntoLoadingStatus() {
	this->m_ui.loading_tips_text->show();
	this->m_ui.refresh_btn->setDisabled(true);

	return;
}

void CourseResourceWidget::getOutFromLoadingStatus() {
	this->m_ui.loading_tips_text->hide();
	this->m_ui.refresh_btn->setDisabled(false);

	return;
}

void CourseResourceWidget::openFileDialog() {
	//获得文件路径，并且判断是否为空
	QString file_path = QFileDialog::getOpenFileName(this, "open", "./", "ALL(*.*)");
	if (file_path.isEmpty()) {
		return;
	}

	this->openUploadFileDialog(file_path);

	return;
}

void CourseResourceWidget::getFileInfoListRequest() {
	// ——不变
	QJsonObject request_json_obj;
	QString url = "http://" + ReadConf::G_HTTP_HOST + ":"
		+ QString::number(ReadConf::G_HTTP_PORT);
	HttpRequest *request_obj = new HttpRequest;
	QThread *request_thread = new QThread;
	request_obj->moveToThread(request_thread);

	// ——可变
	//     ——固定数据
	request_json_obj["account_type"] = user->getAccountType();
	request_json_obj["uid"] = user->getUid();
	request_json_obj["username"] = user->getUsername();
	//     ——可变数据
	request_json_obj["course_id"] = this->m_course_id;
	request_obj->request(QUrl(url + "/getCourseResourceList"), request_json_obj);
	this->connect(request_obj, &HttpRequest::success,
		this, &CourseResourceWidget::getFileInfoListRequestSuccess);

	// ——不变
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::quit);
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::deleteLater);
	this->connect(request_obj, &HttpRequest::complete, request_obj, &HttpRequest::deleteLater);
	request_thread->start();

	return;
}

void CourseResourceWidget::getFileInfoListRequestSuccess(const QJsonObject &data) {
	this->updateFileInfoList(data);
	this->updateFileListWidget(this->m_file_info_list);

	return;
}