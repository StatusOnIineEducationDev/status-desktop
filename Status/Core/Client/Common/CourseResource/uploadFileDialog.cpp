#include "uploadFileDialog.h"


UploadFileDialog::UploadFileDialog(const QFileInfo &info, const QString &course_id, 
	QWidget *parent)
	: QDialog(parent), m_info(info), m_course_id(course_id){
	m_ui.setupUi(this);
	// ������������
	this->setWindowFlag(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground, true);

	// ��������ˢ��
	// ��ȡ�ļ��� �ļ�����
	QString file_type = info.fileName().mid(info.fileName().lastIndexOf(".") + 1);
	this->m_ui.file_type_pic->
		setPixmap(QPixmap(":/file_type/Resources/material/file_type/" + file_type + ".png"));
	this->m_ui.resource_title_edit->setText(info.fileName());
	this->m_ui.filename_text->setText(info.fileName());
	this->m_ui.file_size_text->setText(formatSize(info.size()));

	// �������ź�
	this->connect(this->m_ui.confirm_btn, &QPushButton::clicked,
		this, &UploadFileDialog::upload);
}

UploadFileDialog::~UploadFileDialog() {

}

void UploadFileDialog::upload() {
	this->m_ui.confirm_btn->setDisabled(true);
	this->m_ui.resource_title_edit->setDisabled(true);
	this->uploadCourseResourceRequest();

	return;
}

void UploadFileDialog::uploadCourseResourceRequest() {
	// ��������
	QJsonObject request_json_obj;
	QString url = "http://" + ReadConf::G_HTTP_HOST + ":"
		+ QString::number(ReadConf::G_HTTP_PORT);
	FileUpload *request_obj = new FileUpload;
	QThread *request_thread = new QThread;
	request_obj->moveToThread(request_thread);

	// �����ɱ�
	//     �����̶�����
	request_json_obj["account_type"] = user->getAccountType();
	request_json_obj["uid"] = user->getUid();
	request_json_obj["username"] = user->getUsername();
	//     �����ɱ�����
	request_json_obj["course_id"] = this->m_course_id;
	request_json_obj["resource_title"] = this->m_ui.resource_title_edit->text();
	request_json_obj["filename"] = this->m_info.fileName();
	request_json_obj["file_size"] = this->m_info.size();
	QFile *file = new QFile(this->m_info.filePath(), this);
	request_obj->request(QUrl(url + "/courseResource/uploadCourseResource"), request_json_obj, *file);
	this->connect(request_obj, &FileUpload::success,
		this, &UploadFileDialog::uploadCourseResourceRequestSuccess);

	// ��������
	this->connect(request_obj, &FileUpload::complete, request_thread, &QThread::quit);
	this->connect(request_obj, &FileUpload::complete, request_thread, &QThread::deleteLater);
	this->connect(request_obj, &FileUpload::complete, request_obj, &FileUpload::deleteLater);
	request_thread->start();

	return;
}

void UploadFileDialog::uploadCourseResourceRequestSuccess(const QJsonObject &data) {
	ErrorCode err = ErrorCode(data["error_code"].toInt());

	this->m_ui.confirm_btn->setDisabled(false);

	switch (err) {
	case NoError:
		this->disconnect(this->m_ui.confirm_btn, &QPushButton::clicked,
			this, &UploadFileDialog::upload);
		this->connect(this->m_ui.confirm_btn, &QPushButton::clicked,
			this, &UploadFileDialog::close);
		this->m_ui.progressBar->setValue(100);
		this->m_ui.confirm_btn->setText("���");
		emit this->uploadSuccess();
		break;
	case CourseResourceTitleDuplicateError:
		this->m_ui.resource_title_edit->setDisabled(false);
		this->m_ui.warn_text->setText("��Դ�����ظ�");
		break;
	}

	

	return;
}

void UploadFileDialog::mouseMoveEvent(QMouseEvent *event) {
	// ������굱ǰλ��
	// ��������title bar��������£���ִ���ƶ�
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