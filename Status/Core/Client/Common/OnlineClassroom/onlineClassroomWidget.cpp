#include "onlineClassroomWidget.h"


OnlineClassroomWidget::OnlineClassroomWidget(QWidget *parent)
	: QWidget(parent) {
	m_ui.setupUi(this);

	this->m_ui.function_tabWidget->setAttribute(Qt::WA_StyledBackground);  // tab栏显示背景色
}

OnlineClassroomWidget::~OnlineClassroomWidget() {

}

void OnlineClassroomWidget::lessonConnectionSend(QJsonObject &data) {
	// ——请求数据
	data["account_type"] = User::G_ACCOUNT_TYPE;
	data["timestamp"] = (int)QDateTime::currentDateTime().toTime_t();
	data["course_id"] = this->m_room["course_id"].toString();
	data["lesson_id"] = this->m_room["lesson_id"].toString();
	data["uid"] = User::G_UID;
	data["username"] = User::G_USERNAME;

	// ——这里不用send，否则会报跨线程错误
	this->m_lesson_connection->realSend(data);
}

void OnlineClassroomWidget::createLessonConnection() {
	this->m_lesson_connection = new Connection;
	QThread *connection_thread = new QThread(this);
	this->m_lesson_connection->moveToThread(connection_thread);
	connection_thread->start();

	this->m_lesson_connection->connect(ReadConf::G_SOCKET_HOST, ReadConf::G_SOCKET_PORT);

	// ——信号绑定
	this->connect(this->m_lesson_connection, &Connection::bufferReadyRead, 
		this, &OnlineClassroomWidget::handleLessonConnectionRecv);

	return;
}

void OnlineClassroomWidget::distroyLessonConnection() {
	if (this->m_lesson_connection == nullptr) {
		return;
	}

	QThread *del_thread;

	del_thread = this->m_lesson_connection->thread();
	delete this->m_lesson_connection;
	this->m_lesson_connection = nullptr;
	del_thread->exit(0);
	this->connect(del_thread, &QThread::finished, del_thread, &QThread::deleteLater);

	return;
}

void OnlineClassroomWidget::openCamera() {
	this->m_camera = new Camera(this);

	this->m_camera->open();

	return;
}

void OnlineClassroomWidget::distroyCamera() {
	if (this->m_camera == nullptr) {
		return;
	}

	delete this->m_camera;

	return;
}

void OnlineClassroomWidget::sendMineCameraFrame() {
	if (!this->m_camera->isOpened()) {
		return;
	}

	cv::Mat frame_mat = this->m_camera->getFrameMat();
	QJsonObject json_obj;

	// ——cv::Mat 转 base64
	std::vector<unsigned char> mat_encode_vector;
	std::string mat_encode_str;
	const char *mat_encode_char;
	QString base64_str;

	cv::imencode(".jpg", frame_mat, mat_encode_vector);
	mat_encode_str.append(mat_encode_vector.begin(), mat_encode_vector.end());
	mat_encode_char = mat_encode_str.c_str();
	base64_str = QString::fromStdString(base64_encode(mat_encode_char, mat_encode_str.size()));

	json_obj["command"] = TransportCmd::StudentCameraFrameData;
	json_obj["frame_mat"] = base64_str;
	json_obj["frame_timestamp"] = (int)QDateTime::currentDateTime().toTime_t();
	this->lessonConnectionSend(json_obj);

	return;
}

void OnlineClassroomWidget::updateLessonInfo(QString &course_name, QString &course_id,
	QString &lesson_id, QString &teacher_name, QString &teacher_id, 
	CourseStatus &course_status, int create_timestamp, int begin_timestamp) {
	// ——更新map
	this->m_room["course_name"] = course_name;
	this->m_room["course_id"] = course_id;
	this->m_room["lesson_id"] = lesson_id;
	this->m_room["teacher_id"] = teacher_id;
	this->m_room["teacher_name"] = teacher_name;
	this->m_room["course_status"] = course_status;
	this->m_room["create_timestamp"] = create_timestamp;
	this->m_room["begin_timestamp"] = begin_timestamp;

	// ——刷新ui
	this->m_ui.room_name_text->setText(course_name);
	this->m_ui.lesson_id_text->setText(lesson_id);
	this->m_ui.teacher_name_text->setText(teacher_name);
	this->m_ui.create_time_text->setText(
		QDateTime::fromTime_t(create_timestamp).toString("hh:mm:ss"));
	if (begin_timestamp != -1) {
		this->m_ui.begin_time_text->setText(
			QDateTime::fromTime_t(begin_timestamp).toString("hh:mm:ss"));

	}

	return;
}

void OnlineClassroomWidget::updateBeginTime(int begin_timestamp) {
	// ——更新map
	this->m_room["begin_timestamp"] = begin_timestamp;

	// ——刷新ui
	this->m_ui.begin_time_text->setText(
		QDateTime::fromTime_t(begin_timestamp).toString("hh:mm:ss"));

	return;
}

void OnlineClassroomWidget::updateLastTime(int begin_timestamp, int now_timestamp) {
	/*
		这里需要准确计时
		采用时间戳相减计算时间
	*/
	this->m_ui.last_time_text->setText(formatTime(now_timestamp - begin_timestamp));

	return;
}

void OnlineClassroomWidget::updateCourseStatus(CourseStatus &course_status) {
	// ——更新map
	this->m_room["course_status"] = course_status;

	return;
}