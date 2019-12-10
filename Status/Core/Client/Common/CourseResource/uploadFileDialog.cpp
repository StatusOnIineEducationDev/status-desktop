#include "uploadFileDialog.h"


UploadFileDialog::UploadFileDialog(const QFileInfo &info, const QString &course_id, 
	QWidget *parent)
	: QDialog(parent), m_info(info), m_course_id(course_id){
	m_ui.setupUi(this);
	// 窗口属性设置
	this->setWindowFlag(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground, true);

	// ——数据刷新
	// 截取文件名 文件类型
	QString file_type = info.fileName().mid(info.fileName().lastIndexOf(".") + 1);
	this->m_ui.file_type_pic->
		setPixmap(QPixmap(":/file_type/Resources/material/file_type/" + file_type + ".png"));
	this->m_ui.filename_text->setText(info.fileName());
	this->m_ui.file_size_text->setText(formatSize(info.size()));

	this->uploadCourseResourceRequest();

	// ——绑定信号
	this->connect(this->m_ui.confirm_btn, &QPushButton::clicked,
		this, &UploadFileDialog::deleteLater);
}

UploadFileDialog::~UploadFileDialog() {

}

void UploadFileDialog::uploadCourseResourceRequest() {
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
	QFile *file = new QFile(this->m_info.filePath(), this);
	request_obj->request(QUrl(url + "/uploadCourseResource"), request_json_obj, *file);
	this->connect(request_obj, &HttpRequest::success,
		this, &UploadFileDialog::uploadCourseResourceRequestSuccess);

	// ——不变
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::quit);
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::deleteLater);
	this->connect(request_obj, &HttpRequest::complete, request_obj, &HttpRequest::deleteLater);
	request_thread->start();

	return;
}

void UploadFileDialog::uploadCourseResourceRequestSuccess() {
	this->m_ui.confirm_btn->setDisabled(false);
	this->m_ui.progressBar->setValue(100);

	return;
}

void UploadFileDialog::mouseMoveEvent(QMouseEvent *event) {
	// 计算鼠标当前位置
	// 如果鼠标在title bar且左键按下，则执行移动
	if (this->is_moving) {
		this->move(this->pos() + event->pos() - this->start_pos);
	}

	return;
}

void UploadFileDialog::mousePressEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton) {
		this->is_pressed = true;
		this->start_pos = QPoint(event->pos().x(), event->pos().y());
		if (this->start_pos.x() < this->width() && this->start_pos.y() < 35) {
			this->is_moving = true;
		}
	}

	return;
}

void UploadFileDialog::mouseReleaseEvent(QMouseEvent *event) {
	this->is_pressed = false;
	this->is_moving = false;

	return;
}