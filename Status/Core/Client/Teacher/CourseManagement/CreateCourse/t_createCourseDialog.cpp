#include "t_createCourseDialog.h"


TeacherCreateCourseDialog::TeacherCreateCourseDialog(QWidget *parent)
	: QDialog(parent) {
	m_ui.setupUi(this);

	// ����������Ӱ
	QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
	shadow_effect->setOffset(0, 0);
	shadow_effect->setColor(Qt::gray);
	shadow_effect->setBlurRadius(10);
	this->m_ui.shadow->setGraphicsEffect(shadow_effect);

	// ����������������
	this->setWindowFlag(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground, true);

	// ��������
	this->m_ui.course_classify->setView(new QListView(this));  // ���Ӧ�����й�comboBox����ʽ
	this->m_ui.tabWidget->tabBar()->hide();                
	this->m_ui.back_btn->hide();  // ����һ������ťĬ������
	this->m_ui.confirm_btn->hide();  // ��ȷ�ϴ�������ťĬ������
	this->m_ui.finish_btn->hide();  // ����ɡ���ťĬ������

	// �����źŰ�
	this->connect(this->m_ui.next_btn, &QPushButton::clicked,
		this, &TeacherCreateCourseDialog::nextStep);
	this->connect(this->m_ui.back_btn, &QPushButton::clicked,
		this, &TeacherCreateCourseDialog::lastStep);
	this->connect(this->m_ui.confirm_btn, &QPushButton::clicked,
		this, &TeacherCreateCourseDialog::createCourse);
	this->connect(this->m_ui.finish_btn, &QPushButton::clicked,
		this, &TeacherCreateCourseDialog::close);
	this->connect(this->m_ui.choose_pic_btn, &QPushButton::clicked,
		this, &TeacherCreateCourseDialog::getCoursePictureFromLocal);
}

TeacherCreateCourseDialog::~TeacherCreateCourseDialog() {

}

void TeacherCreateCourseDialog::nextStep() {
	// �����Ϸ��Լ��
	QString course_name_text = this->m_ui.course_name_edit->text();
	Toast *toast;

	if (course_name_text == "") {
		toast = new Toast("������γ�����");
		toast->show();
		this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);

		return;
	}
	else if (course_name_text.count() > 40) {
		toast = new Toast("�γ����ƹ���");
		toast->show();
		this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);

		return;
	}

	this->m_ui.tabWidget->setCurrentIndex(1);

	// �����޸Ľ�����ʾ��ǰ����
	this->m_ui.intro_logo_frame->setStyleSheet(
		"QFrame {\
			background: rgba(18, 150, 214, 50);\
			border-radius: 30px;\
			border: none;\
		}"); 
	this->m_ui.intro_title->setStyleSheet("color: #1296d6;");
	this->m_ui.line_2->setStyleSheet("background: rgba(18, 150, 214, 50);");
	this->m_ui.intro_pic->
		setPixmap(QPixmap(":/pic/Resources/material/pic/introduction_on.png"));

	this->m_ui.next_btn->hide();
	this->m_ui.confirm_btn->show();
	this->m_ui.back_btn->show();

	return;
}

void TeacherCreateCourseDialog::lastStep() {
	this->m_ui.tabWidget->setCurrentIndex(0);

	// �����޸Ľ�����ʾ����ԭ��
	this->m_ui.intro_logo_frame->setStyleSheet(
		"QFrame {\
			background: #fafafa;\
			border-radius: 30px;\
			border: none;\
		}");
	this->m_ui.intro_title->setStyleSheet("color: #999999;");
	this->m_ui.line_2->setStyleSheet("");
	this->m_ui.intro_pic->
		setPixmap(QPixmap(":/pic/Resources/material/pic/introduction.png"));

	this->m_ui.next_btn->show();
	this->m_ui.confirm_btn->hide();
	this->m_ui.back_btn->hide();

	return;
}

void TeacherCreateCourseDialog::createCourse() {
	// �����Ϸ��Լ��
	QString introduction_text = this->m_ui.course_introduction_edit->toPlainText();
	Toast *toast;

	if (introduction_text == "") {
		toast = new Toast("������γ̽���");
		toast->show();
		this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);

		return;
	}
	else if (introduction_text.count() > 40) {
		toast = new Toast("�γ̽��ܹ���");
		toast->show();
		this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);

		return;
	}

	this->createCourseRequest();

	return;
}

void TeacherCreateCourseDialog::getCoursePictureFromLocal() {
	//����ļ�·���������ж��Ƿ�Ϊ��
	QString path = 
		QFileDialog::getOpenFileName(this, "open", "./", "Image Files(*.jpg *.png)");
	if (path.isEmpty()) {
		return;
	}

	this->m_pic_info = QFileInfo(path);
	this->m_ui.course_pic->setPixmap(QPixmap(path));

	return;
}

void TeacherCreateCourseDialog::createCourseRequest() {
	// ��������
	QJsonObject request_json_obj;
	QString url = "http://" + ReadConf::G_HTTP_HOST + ":"
		+ QString::number(ReadConf::G_HTTP_PORT);
	HttpRequest *request_obj = new HttpRequest;
	QThread *request_thread = new QThread;
	request_obj->moveToThread(request_thread);

	// �����ɱ�
	//     �����̶�����
	request_json_obj["account_type"] = user->getAccountType();
	request_json_obj["uid"] = user->getUid();
	request_json_obj["username"] = user->getUsername();
	//     �����ɱ�����
	request_json_obj["course_name"] = this->m_ui.course_name_edit->text();
	request_json_obj["classify"] = this->m_ui.course_classify->currentText();
	request_json_obj["introduction"] = this->m_ui.course_introduction_edit->toPlainText();
	request_obj->request(QUrl(url + "/course/createCourse"),
		request_json_obj);
	this->connect(request_obj, &HttpRequest::success,
		this, &TeacherCreateCourseDialog::createCourseRequestSuccess);

	// ��������
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::quit);
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::deleteLater);
	this->connect(request_obj, &HttpRequest::complete, request_obj, &HttpRequest::deleteLater);
	request_thread->start();

	// �����ȴ�����
	LoadingMask *loading_mask = new LoadingMask(this->m_ui.main_area);
	this->connect(request_obj, &HttpRequest::complete, loading_mask, &LoadingMask::deleteLater);
	loading_mask->setTipsText("������...");
	loading_mask->show();

	return;
}

void TeacherCreateCourseDialog::createCourseRequestSuccess(const QJsonObject &data) {
	ErrorCode err = ErrorCode(data["error_code"].toInt());

	switch (err) {
	case NoError:
		this->uploadCoursePictureRequest(data["course_id"].toString());
		break;
	}

	return;
}

void TeacherCreateCourseDialog::uploadCoursePictureRequest(const QString &course_id) {
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
	request_json_obj["course_id"] = course_id;
	request_json_obj["filename"] = this->m_pic_info.fileName();
	QFile *file = new QFile(this->m_pic_info.filePath(), this);
	request_obj->request(QUrl(url + "/course/uploadCoursePicture"), request_json_obj, *file);
	this->connect(request_obj, &FileUpload::success,
		this, &TeacherCreateCourseDialog::uploadCoursePictureRequestSuccess);

	// ��������
	this->connect(request_obj, &FileUpload::complete, request_thread, &QThread::quit);
	this->connect(request_obj, &FileUpload::complete, request_thread, &QThread::deleteLater);
	this->connect(request_obj, &FileUpload::complete, request_obj, &FileUpload::deleteLater);
	request_thread->start();

	return;
}

void TeacherCreateCourseDialog::uploadCoursePictureRequestSuccess(const QJsonObject &data) {
	ErrorCode err = ErrorCode(data["error_code"].toInt());

	switch (err) {
	case NoError:
		//this->m_ui.tabWidget->setCurrentIndex(2);

		//// �����޸Ľ�����ʾ��ǰ����
		//this->m_ui.finish_logo_frame->setStyleSheet(
		//	"QFrame {\
		//		background: rgba(18, 150, 214, 50);\
		//		border-radius: 30px;\
		//		border: none;\
		//	}");
		//this->m_ui.finish_title->setStyleSheet("color: #1296d6;");
		//this->m_ui.finish_pic->
		//	setPixmap(QPixmap(":/pic/Resources/material/pic/complete_on.png"));
		Toast *toast = toast = new Toast("�����ɹ�");
		toast->show();
		this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);

		emit this->createCourseSuccess();
		this->deleteLater();

		break;
	}

	return;
}

void TeacherCreateCourseDialog::mouseMoveEvent(QMouseEvent *event) {
	// ������굱ǰλ��
	// ��������title bar��������£���ִ���ƶ�
	if (this->is_moving) {
		this->move(this->pos() + event->pos() - this->start_pos);
	}

	return;
}

void TeacherCreateCourseDialog::mousePressEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton) {
		this->is_pressed = true;
		this->start_pos = QPoint(event->pos().x(), event->pos().y());
		if (this->start_pos.x() < this->width() && this->start_pos.y() < 35) {
			this->is_moving = true;
		}
	}

	return;
}

void TeacherCreateCourseDialog::mouseReleaseEvent(QMouseEvent *event) {
	this->is_pressed = false;
	this->is_moving = false;

	return;
}