#include "Core/Controller/controller.h"
#include "Core/Transport/http_request.h"
#include <typeinfo>


TeacherControllerBase::TeacherControllerBase(TeacherMainWindow *win, Teacher* user) : m_win(win), m_user(user) {
	this->m_win->show();
}


//**************************************************************************************************
//**************************************************************************************************


TeacherCourseWidgetController::TeacherCourseWidgetController(TeacherMainWindow *win, Teacher* user) : TeacherControllerBase(win, user), m_course(nullptr) {
	this->connect(this->m_win->ui().course_btn, &QPushButton::clicked, this, &TeacherCourseWidgetController::connectInit);  // �л����γ�ҳʱ����ʼ���ź�/��
	this->connect(this->m_win->ui().course_btn, &QPushButton::clicked, this, &TeacherCourseWidgetController::updateCourseComboBox);  // ˢ��combobox
	this->connectInit();
	this->updateCourseComboBox();
}

void TeacherCourseWidgetController::connectInit() {
	this->connect(this->m_win->teacherCourseWidget()->ui().courses_comboBox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &TeacherCourseWidgetController::getCourseDataRequest);
}

void TeacherCourseWidgetController::updateCourseComboBox() {
	for (int index = 0; index < this->user()->coursesBaseList()->count(); index++) {
		this->m_win->teacherCourseWidget()->ui().courses_comboBox->addItem(this->user()->coursesBaseList()->at(index).courseName());
	}
}

void TeacherCourseWidgetController::getCourseDataRequest(const int &current_index) {
	QJsonObject request_json_obj;
	HttpRequest *request_obj = new HttpRequest;
	QThread *request_thread = new QThread;
	request_obj->moveToThread(request_thread);

	// ������������
	request_json_obj["uid"] = this->m_user->uid();
	request_json_obj["course_id"] = this->m_user->coursesBaseList()->at(current_index).courseId();

	request_obj->request(QUrl("http://127.0.0.1:5000/getCourseData"), request_json_obj);
	this->connect(request_obj, &HttpRequest::success, this, &TeacherCourseWidgetController::getCourseDataSuccess);
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::quit);
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::deleteLater);
	this->connect(request_obj, &HttpRequest::complete, request_obj, &HttpRequest::deleteLater);
	request_thread->start();

	return;
}

void TeacherCourseWidgetController::getCourseDataSuccess(const QJsonObject &data) {
	QJsonObject *json_obj_temp;
	QString uid_temp, username_temp, course_id_temp;
	UserBase::Gender gender_temp;
	QDateTime start_datetime_temp, end_datetime_temp;
	QList<UserBase> *teachers_list = new QList<UserBase>;  // ���ڸÿγ̵Ľ�ʦ����
	QList<UserBase> *students_list = new QList<UserBase>;  // ѡ��ÿγ̵�ѧ������
	QList<LessonBase> *lessons_list = new QList<LessonBase>;  // ����ɵĿ�������
	QJsonArray teachers_list_json_arr = data["teachers_list"].toArray();
	QJsonArray students_list_json_arr = data["students_list"].toArray();
	QJsonArray lessons_list_json_arr = data["lessons_list"].toArray();

	// ��������teachers_list
	for (int index = 0; index < teachers_list_json_arr.count(); index++) {
		json_obj_temp = &teachers_list_json_arr[index].toObject();
		uid_temp = json_obj_temp->value("uid").toString();
		username_temp = json_obj_temp->value("username").toString();
		gender_temp = UserBase::Gender(json_obj_temp->value("gender").toInt());  // c++�������ﲻ����int��ö�ٵ�ֱ�ӻ�ת��������������ǿ��ת��
		
		teachers_list->append(UserBase(uid_temp, username_temp, gender_temp));
	}

	// ��������students_list
	for (int index = 0; index < students_list_json_arr.count(); index++) {
		json_obj_temp = &students_list_json_arr[index].toObject();
		uid_temp = json_obj_temp->value("uid").toString();
		username_temp = json_obj_temp->value("username").toString();
		gender_temp = UserBase::Gender(json_obj_temp->value("gender").toInt());

		students_list->append(UserBase(uid_temp, username_temp, gender_temp));
	}

	// ��������lessons_list
	for (int index = 0; index < lessons_list_json_arr.count(); index++) {
		json_obj_temp = &lessons_list_json_arr[index].toObject();
		course_id_temp = json_obj_temp->value("course_id").toString();
		start_datetime_temp = QDateTime::fromTime_t(json_obj_temp->value("start_timestamp").toDouble());
		end_datetime_temp = QDateTime::fromTime_t(json_obj_temp->value("start_timestamp").toDouble());

		lessons_list->append(LessonBase(course_id_temp, start_datetime_temp, end_datetime_temp));
	}

	// ����ʵ����Course
	if (this->m_course != nullptr) {
		delete this->m_course;
	}
	this->m_course = new Course(data["course_id"].toString(), data["course_name"].toString(), teachers_list, students_list, lessons_list);

	this->updateCourseBaseInfo();

	return;
}

void TeacherCourseWidgetController::updateCourseBaseInfo() {
	Ui::TeacherCourseWidget ui = this->m_win->teacherCourseWidget()->ui();
	int total = this->m_course->studentsList()->count() + this->m_course->teachersList()->count();
	int num_of_lessons = this->m_course->lessonsList()->count();

	ui.course_id_text->setText(this->m_course->courseId());
	ui.data_1_text->setText(QString::number(total));
	ui.data_2_text->setText(QString::number(num_of_lessons));
	ui.data_3_text->setText("");
	ui.data_4_text->setText("");
	ui.course_key_text->setText("");
}

//**************************************************************************************************
//**************************************************************************************************


TeacherController::TeacherController(TeacherMainWindow *win, Teacher* user) : TeacherCourseWidgetController(win, user) {

}