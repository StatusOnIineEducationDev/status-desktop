#include "Core/Controller/teacher_controller.h"
#include "Core/Transport/http_request.h"
#include "Core/online_education.h"
#pragma execution_character_set("utf-8")  


TeacherCourseWidgetController::TeacherCourseWidgetController(TeacherMainWindow *win, User *user)
	: m_win(win), m_user(user), m_teacher_course_widget(nullptr), m_course(nullptr), m_lessons_list(nullptr) {
	this->m_teacher_course_widget = new TeacherCourseWidget(this->m_win);
	Ui::TeacherCourseWidget ui = this->m_teacher_course_widget->ui();

	this->m_win->ui().widget_layout->addWidget(this->m_teacher_course_widget);  // ������layout��
	this->m_teacher_course_widget->show();  // ��ʾ

	this->connect(ui.courses_comboBox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &TeacherCourseWidgetController::getCourseBaseInfoRequest);
	this->connect(ui.emotions_report_botton_group, static_cast<void (QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked), this, &TeacherCourseWidgetController::updateEmotionReportBarChart);

	this->updateCourseComboBox();
}

TeacherCourseWidgetController::~TeacherCourseWidgetController() {
	if (this->m_teacher_course_widget != nullptr) {
		delete this->m_teacher_course_widget;
	}
	if (this->m_course != nullptr) {
		delete this->m_course;
	}
	if (this->m_lessons_list != nullptr) {
		delete this->m_lessons_list;
	}
}

void TeacherCourseWidgetController::updateCourseComboBox() {
	Ui::TeacherCourseWidget ui = this->m_teacher_course_widget->ui();

	for (int index = 0; index < this->m_user->coursesBaseList()->count(); index++) {
		ui.courses_comboBox->addItem(this->m_user->coursesBaseList()->at(index).courseName());
	}
}

void TeacherCourseWidgetController::updateAreaChartPointInfo(const QPointF &point) {
	Ui::TeacherCourseWidget ui = this->m_teacher_course_widget->ui();
	const Lesson *lesson_obj = &this->m_lessons_list->at(point.x() - 1);

	ui.point_datetime->setText(lesson_obj->startDatetime().toString("yyyy-mm-dd"));
	ui.point_title->setText("רע�ȣ�");

	// ��������label��ɫ
	QPalette palette;
	if (point.y() >= 85) {
		palette.setColor(QPalette::WindowText, QColor(36, 173, 29));
		ui.point_concentration->setText(QString::number(point.y()) + " ����");
	}
	else if (point.y() >= 60) {
		palette.setColor(QPalette::WindowText, QColor(249, 211, 26));
		ui.point_concentration->setText(QString::number(point.y()) + " һ��");
	}
	else {
		palette.setColor(QPalette::WindowText, QColor(240, 80, 80));
		ui.point_concentration->setText(QString::number(point.y()) + " �");
	}
	ui.point_concentration->setPalette(palette);
}

void TeacherCourseWidgetController::getCourseBaseInfoRequest(const int &current_index) {
	QJsonObject request_json_obj;
	HttpRequest *request_obj = new HttpRequest;
	QThread *request_thread = new QThread;
	request_obj->moveToThread(request_thread);

	// ������������
	request_json_obj["uid"] = this->m_user->uid();
	request_json_obj["course_id"] = this->m_user->coursesBaseList()->at(current_index).courseId();

	request_obj->request(QUrl("http://127.0.0.1:5000/getCourseBaseInfo"), request_json_obj);
	this->connect(request_obj, &HttpRequest::success, this, &TeacherCourseWidgetController::getCourseBaseInfoSuccess);
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::quit);
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::deleteLater);
	this->connect(request_obj, &HttpRequest::complete, request_obj, &HttpRequest::deleteLater);
	request_thread->start();

	return;
}

void TeacherCourseWidgetController::getCourseBaseInfoSuccess(const QJsonObject &data) {
	QString course_id = data["course_id"].toString(), course_name = data["course_name"].toString(), 
		course_key = data["course_key"].toString();
	QDateTime creation_timestamp = QDateTime::fromTime_t(data["creation_timestamp"].toDouble());
	int concentration_avg = data["concentration_avg"].toInt(), num_of_like = data["num_of_like"].toInt();

	QJsonObject *json_obj_temp = nullptr;
	QString uid_temp, username_temp, course_id_temp;
	RoleBase::Gender gender_temp;
	QDateTime start_datetime_temp, end_datetime_temp;
	QList<RoleBase> *teachers_list = new QList<RoleBase>;  // ���ڸÿγ̵Ľ�ʦ����
	QList<RoleBase> *students_list = new QList<RoleBase>;  // ѡ��ÿγ̵�ѧ������
	QList<LessonBase> *lessons_list = new QList<LessonBase>;  // ����ɵĿ�������
	QJsonArray *teachers_list_json_arr = &data["teachers_list"].toArray();
	QJsonArray *students_list_json_arr = &data["students_list"].toArray();
	QJsonArray *lessons_list_json_arr = &data["lessons_list"].toArray();

	// ��������teachers_list
	for (int index = 0; index < teachers_list_json_arr->count(); index++) {
		json_obj_temp = &teachers_list_json_arr->at(index).toObject();
		uid_temp = json_obj_temp->value("uid").toString();
		username_temp = json_obj_temp->value("username").toString();
		gender_temp = RoleBase::Gender(json_obj_temp->value("gender").toInt());  // c++�������ﲻ����int��ö�ٵ�ֱ�ӻ�ת��������������ǿ��ת��
		
		teachers_list->append(RoleBase(uid_temp, username_temp, gender_temp));
	}

	// ��������students_list
	for (int index = 0; index < students_list_json_arr->count(); index++) {
		json_obj_temp = &students_list_json_arr->at(index).toObject();
		uid_temp = json_obj_temp->value("uid").toString();
		username_temp = json_obj_temp->value("username").toString();
		gender_temp = RoleBase::Gender(json_obj_temp->value("gender").toInt());

		students_list->append(RoleBase(uid_temp, username_temp, gender_temp));
	}

	// ��������lessons_list
	for (int index = 0; index < lessons_list_json_arr->count(); index++) {
		json_obj_temp = &lessons_list_json_arr->at(index).toObject();
		course_id_temp = json_obj_temp->value("lesson_id").toString();
		start_datetime_temp = QDateTime::fromTime_t(json_obj_temp->value("start_timestamp").toDouble());
		end_datetime_temp = QDateTime::fromTime_t(json_obj_temp->value("start_timestamp").toDouble());

		lessons_list->append(LessonBase(course_id_temp, start_datetime_temp, end_datetime_temp));
	}

	// ����ʵ����Course
	if (this->m_course != nullptr) {
		delete this->m_course;
	}

	this->m_course = new Course(course_id, course_name, *teachers_list, *students_list, *lessons_list, 
		creation_timestamp, course_key, concentration_avg, num_of_like);

	delete teachers_list;
	delete students_list;
	delete lessons_list;

	this->updateRoomBaseInfo();
	this->getLessonsInfoRequest(this->m_course->courseId());

	return;
}

void TeacherCourseWidgetController::getLessonsInfoRequest(const QString &course_id) {
	QJsonObject request_json_obj;
	HttpRequest *request_obj = new HttpRequest;
	QThread *request_thread = new QThread;
	request_obj->moveToThread(request_thread);

	// ������������
	request_json_obj["uid"] = this->m_user->uid();
	request_json_obj["course_id"] = this->m_course->courseId();

	request_obj->request(QUrl("http://127.0.0.1:5000/getLessonsInfo"), request_json_obj);
	this->connect(request_obj, &HttpRequest::success, this, &TeacherCourseWidgetController::getLessonsInfoSuccess);
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::quit);
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::deleteLater);
	this->connect(request_obj, &HttpRequest::complete, request_obj, &HttpRequest::deleteLater);
	request_thread->start();

	return;
}

void TeacherCourseWidgetController::getLessonsInfoSuccess(const QJsonObject &data) { 
	Ui::TeacherCourseWidget ui = this->m_teacher_course_widget->ui();
	QJsonArray lessons_list_json_arr = data["lessons_list"].toArray();
	QJsonObject *lesson_json_obj_temp = nullptr, *teacher_json_obj_temp = nullptr;

	QJsonArray *students_list_json_arr_temp = nullptr, *concentrations_list_json_arr_temp = nullptr;
	QJsonObject *student_json_obj_temp = nullptr, *concentration_json_obj_temp = nullptr, *emotions_statistic_map_json_obj_temp = nullptr;

	RoleBase *teacher_temp = nullptr;
	QList<RoleBase> *students_list = nullptr;  // ���ε�ѧ������
	QString uid_temp, username_temp, course_id_temp;
	RoleBase::Gender gender_temp;

	QList<Concentration> *concentrations_list = nullptr;
	int value_temp;
	QDateTime datetime_temp;

	QMap<QString, int> *emotions_statistic_map = nullptr;
	
	if (this->m_lessons_list != nullptr) {
		delete this->m_lessons_list;
	}
	this->m_lessons_list = new QList<Lesson>;

	for (int index = 0; index < lessons_list_json_arr.count(); index++) {
		lesson_json_obj_temp = &lessons_list_json_arr[index].toObject();

		// ��������teacher
		teacher_json_obj_temp = &lesson_json_obj_temp->value("teacher").toObject();
		
		uid_temp = teacher_json_obj_temp->value("uid").toString();
		username_temp = teacher_json_obj_temp->value("username").toString();
		gender_temp = RoleBase::Gender(teacher_json_obj_temp->value("gender").toInt());

		if (teacher_temp != nullptr) {
			delete teacher_temp;
		}
		teacher_temp = new RoleBase(uid_temp, username_temp, gender_temp);

		// ��������students_list
		students_list_json_arr_temp = &lesson_json_obj_temp->value("students_list").toArray();

		if (students_list != nullptr) {
			delete students_list;
		}
		students_list = new QList<RoleBase>;
		for (int student_index = 0; student_index < students_list_json_arr_temp->count(); student_index++) {
			student_json_obj_temp = &students_list_json_arr_temp->at(student_index).toObject();
			uid_temp = student_json_obj_temp->value("uid").toString();
			username_temp = student_json_obj_temp->value("username").toString();
			gender_temp = RoleBase::Gender(student_json_obj_temp->value("gender").toInt());

			students_list->append(RoleBase(uid_temp, username_temp, gender_temp));
		}

		// ��������concentrations_list
		concentrations_list_json_arr_temp = &lesson_json_obj_temp->value("concentrations_list").toArray();

		if (concentrations_list != nullptr) {
			delete concentrations_list;
		}
		concentrations_list = new QList<Concentration>;
		for (int concentration_index = 0; concentration_index < concentrations_list_json_arr_temp->count(); concentration_index++) {
			concentration_json_obj_temp = &concentrations_list_json_arr_temp->at(concentration_index).toObject();
			value_temp = concentration_json_obj_temp->value("value").toInt();
			datetime_temp = QDateTime::fromTime_t(concentration_json_obj_temp->value("timestamp").toDouble());

			concentrations_list->append(Concentration(value_temp, datetime_temp));
		}

		// ��������emotions_statistic_map
		emotions_statistic_map_json_obj_temp = &lesson_json_obj_temp->value("emotions_statistic_map").toObject();

		emotions_statistic_map = new QMap<QString, int>;
		emotions_statistic_map->insert(QString("angry"), emotions_statistic_map_json_obj_temp->value("angry").toInt());
		emotions_statistic_map->insert(QString("disgust"), emotions_statistic_map_json_obj_temp->value("disgust").toInt());
		emotions_statistic_map->insert(QString("fear"), emotions_statistic_map_json_obj_temp->value("fear").toInt());
		emotions_statistic_map->insert(QString("happy"), emotions_statistic_map_json_obj_temp->value("happy").toInt());
		emotions_statistic_map->insert(QString("sad"), emotions_statistic_map_json_obj_temp->value("sad").toInt());
		emotions_statistic_map->insert(QString("surprise"), emotions_statistic_map_json_obj_temp->value("surprise").toInt());
		emotions_statistic_map->insert(QString("neutral"), emotions_statistic_map_json_obj_temp->value("neutral").toInt());

		m_lessons_list->append(Lesson(lesson_json_obj_temp->value("lesson_id").toString(), 
			QDateTime::fromTime_t(lesson_json_obj_temp->value("start_timestamp").toDouble()), 
			QDateTime::fromTime_t(lesson_json_obj_temp->value("end_timestamp").toDouble()),
			*teacher_temp, *students_list, *concentrations_list, *emotions_statistic_map));
	}

	delete teacher_temp;
	delete students_list;
	delete concentrations_list;
	delete emotions_statistic_map;

	this->updateAreaChart();
	this->updateEmotionReportPercentageChart();
	this->updateEmotionReportBarChart(ui.emotions_report_botton_group->id(ui.all_btn));

	return;
}

void TeacherCourseWidgetController::updateRoomBaseInfo() {
	Ui::TeacherCourseWidget ui = this->m_teacher_course_widget->ui();
	int num_of_teachers = this->m_course->teachersList().count(),
		num_of_students = this->m_course->studentsList().count(),
		total = this->m_course->studentsList().count() + this->m_course->teachersList().count(),
		num_of_lessons = this->m_course->lessonsList().count(),
		concentration_avg = this->m_course->concentrationAvg(),
		num_of_like = this->m_course->numOfLike(),
		row_count = 0;
	const RoleBase *obj_temp;
	QTableWidgetItem *uid_item_temp = nullptr,
		*username_item_temp = nullptr,
		*role_item_temp = nullptr;

	// ����dataҳ
	ui.create_datetime_text->setText(this->m_course->creationDateTime().toString("yyyy-mm-dd hh:mm:ss"));
	ui.course_id_text->setText(this->m_course->courseId());
	ui.data_1_text->setText(QString::number(total));
	ui.data_2_text->setText(QString::number(num_of_lessons));
	ui.data_3_text->setText(QString::number(concentration_avg));
	ui.data_4_text->setText(QString::number(num_of_like));
	ui.course_key_text->setText(this->m_course->courseKey());

	// ����memberҳ
	ui.num_of_teachers_text->setText(QString::number(num_of_teachers));
	ui.num_of_students_text->setText(QString::number(num_of_students));
	ui.total_text->setText(QString::number(total));

		// ����tablewidget
	ui.member_table->setRowCount(total);
	for (int index = 0; index < this->m_course->teachersList().count(); index++) {
		obj_temp = &this->m_course->teachersList().at(index);
		uid_item_temp = new QTableWidgetItem(obj_temp->uid());
		uid_item_temp->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

		username_item_temp = new QTableWidgetItem(QIcon(":/pic/Resources/material/pic/teacher.png"), obj_temp->username());
		username_item_temp->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

		role_item_temp = new QTableWidgetItem(QString("��ʦ"));
		role_item_temp->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		
		ui.member_table->setItem(row_count, 0, uid_item_temp);
		ui.member_table->setItem(row_count, 1, username_item_temp);
		ui.member_table->setItem(row_count, 2, role_item_temp);
		row_count++;
	}
	for (int index = 0; index < this->m_course->studentsList().count(); index++) {
		obj_temp = &this->m_course->studentsList().at(index);
		uid_item_temp = new QTableWidgetItem(obj_temp->uid());
		uid_item_temp->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

		username_item_temp = new QTableWidgetItem(QIcon(":/pic/Resources/material/pic/student.png"), obj_temp->username());
		username_item_temp->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

		role_item_temp = new QTableWidgetItem(QString("ѧ��"));
		role_item_temp->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

		ui.member_table->setItem(row_count, 0, uid_item_temp);
		ui.member_table->setItem(row_count, 1, username_item_temp);
		ui.member_table->setItem(row_count, 2, role_item_temp);
		row_count++;
	}

	return;
}

void TeacherCourseWidgetController::updateAreaChart() {
	Ui::TeacherCourseWidget ui = this->m_teacher_course_widget->ui();
	QList<qreal> concentration_value_list;
	int concentration_sum_temp = 0;
	int concentration_avg_temp = 0;
	const QList<Concentration> *concentrations_list_temp;

	for (int index = 0; index < this->m_lessons_list->count(); index++) {
		concentrations_list_temp = &this->m_lessons_list->at(index).concentrationsList();
		concentration_sum_temp = 0;
		for (int concentration_index = 0; concentration_index < concentrations_list_temp->count(); concentration_index++) {
			concentration_sum_temp += concentrations_list_temp->at(concentration_index).value();
		}
		concentration_avg_temp = concentration_sum_temp / concentrations_list_temp->count();
		concentration_value_list.append(concentration_avg_temp);
	}

	AreaChart *area_chart = new AreaChart(concentration_value_list, QColor(131, 105, 203), this->m_teacher_course_widget);
	ui.area_chart_widget->setChart(area_chart);
	ui.area_chart_widget->setRenderHint(QPainter::Antialiasing);

	this->connect(area_chart, &AreaChart::hovered, this, &TeacherCourseWidgetController::updateAreaChartPointInfo);

	return;
}

void TeacherCourseWidgetController::updateEmotionReportPercentageChart() {
	Ui::TeacherCourseWidget ui = this->m_teacher_course_widget->ui();
	int angry_count = 0, disgust_count = 0, fear_count = 0, happy_count = 0, sad_count = 0, surprise_count = 0, neutral_count = 0, emotions_count = 0;
	const QMap<QString, int> *emotions_statistic_map_temp;

	for (int index = 0; index < this->m_lessons_list->count(); index++) {
		emotions_statistic_map_temp = &this->m_lessons_list->at(index).emotionsStatisticMap();

		angry_count += emotions_statistic_map_temp->value("angry");
		disgust_count += emotions_statistic_map_temp->value("disgust");
		fear_count += emotions_statistic_map_temp->value("fear");
		happy_count += emotions_statistic_map_temp->value("happy");
		sad_count += emotions_statistic_map_temp->value("sad");
		surprise_count += emotions_statistic_map_temp->value("surprise");
		neutral_count += emotions_statistic_map_temp->value("neutral");
	}
	emotions_count = angry_count + disgust_count + fear_count + happy_count + sad_count + surprise_count + neutral_count;

	// ����progress barˢ��
	ui.angry_times_text->setText(QString::number(angry_count));
	ui.angry_percent_text->setText(QString::number(int((angry_count / double(emotions_count)) * 100)));
	// ����Ϊ�˱�����ֵ��С������ʾ�����������progressbar�̶���С��ʾֵΪ4
	if ((angry_count / double(emotions_count)) * 100 >= 4) {
		ui.angry_progressBar->setValue((angry_count / double(emotions_count)) * 100);
	}

	ui.disgust_times_text->setText(QString::number(disgust_count));
	ui.disgust_percent_text->setText(QString::number(int((disgust_count / double(emotions_count)) * 100)));
	if ((disgust_count / double(emotions_count)) * 100 >= 4) {
		ui.disgust_progressBar->setValue((disgust_count / double(emotions_count)) * 100);
	}

	ui.fear_times_text->setText(QString::number(fear_count));
	ui.fear_percent_text->setText(QString::number(int((fear_count / double(emotions_count)) * 100)));
	if ((fear_count / double(emotions_count)) * 100 >= 4) {
		ui.fear_progressBar->setValue((fear_count / double(emotions_count)) * 100);
	}

	ui.happy_times_text->setText(QString::number(happy_count));
	ui.happy_percent_text->setText(QString::number(int((happy_count / double(emotions_count)) * 100)));
	if ((happy_count / double(emotions_count)) * 100 >= 4) {
		ui.happy_progressBar->setValue((happy_count / double(emotions_count)) * 100);
	}

	ui.sad_times_text->setText(QString::number(sad_count));
	ui.sad_percent_text->setText(QString::number(int((sad_count / double(emotions_count)) * 100)));
	if ((sad_count / double(emotions_count)) * 100 >= 4) {
		ui.sad_progressBar->setValue((sad_count / double(emotions_count)) * 100);
	}

	ui.surprise_times_text->setText(QString::number(surprise_count));
	ui.surprise_percent_text->setText(QString::number(int((surprise_count / double(emotions_count)) * 100)));
	if ((surprise_count / double(emotions_count)) * 100 >= 4) {
		ui.surprise_progressBar->setValue((surprise_count / double(emotions_count)) * 100);
	}

	ui.neutral_times_text->setText(QString::number(neutral_count));
	ui.neutral_percent_text->setText(QString::number(int((neutral_count / double(emotions_count)) * 100)));
	if ((neutral_count / double(emotions_count)) * 100 >= 4) {
		ui.neutral_progressBar->setValue((neutral_count / double(emotions_count)) * 100);
	}

	return;
}

void TeacherCourseWidgetController::updateEmotionReportBarChart(int button_id) {
	Ui::TeacherCourseWidget ui = this->m_teacher_course_widget->ui();
	QChart *chart = nullptr;
	LineAndBarChart *line_and_bar_chart;
	QFont font("΢���ź�", 10);
	QBarSet *angry_set = new QBarSet("����"), *disgust_set = new QBarSet("���"), 
		*fear_set = new QBarSet("�־�"), *happy_set = new QBarSet("����"),
		*sad_set = new QBarSet("����"), *surprise_set = new QBarSet("����"), 
		*neutral_set = new QBarSet("ƽ��");
	QList<qreal> angry_value_list, disgust_value_list, fear_value_list, happy_value_list,
		sad_value_list, surprise_value_list, neutral_value_list;
	int angry_btn_id = ui.emotions_report_botton_group->id(ui.angry_btn),
		disgust_btn_id = ui.emotions_report_botton_group->id(ui.disgust_btn),
		fear_btn_id = ui.emotions_report_botton_group->id(ui.fear_btn),
		happy_btn_id = ui.emotions_report_botton_group->id(ui.happy_btn),
		sad_btn_id = ui.emotions_report_botton_group->id(ui.sad_btn),
		surprise_btn_id = ui.emotions_report_botton_group->id(ui.surprise_btn),
		neutral_btn_id = ui.emotions_report_botton_group->id(ui.neutral_btn),
		all_btn_id = ui.emotions_report_botton_group->id(ui.all_btn);

	QBarSeries *bar_series = new QBarSeries();
	const QMap<QString, int> *emotions_statistic_map_temp;

	if (button_id == angry_btn_id) {
		for (int index = 0; index < this->m_lessons_list->count(); index++) {
			emotions_statistic_map_temp = &this->m_lessons_list->at(index).emotionsStatisticMap();
			angry_value_list.append(emotions_statistic_map_temp->value("angry"));
		}
		line_and_bar_chart = new LineAndBarChart(angry_value_list, QString("����"), QColor(108, 111, 192), this->m_teacher_course_widget);
	}
	else if (button_id == disgust_btn_id) {
		for (int index = 0; index < this->m_lessons_list->count(); index++) {
			emotions_statistic_map_temp = &this->m_lessons_list->at(index).emotionsStatisticMap();
			disgust_value_list.append(emotions_statistic_map_temp->value("disgust"));
		}
		line_and_bar_chart = new LineAndBarChart(disgust_value_list, QString("���"), QColor(35, 183, 229), this->m_teacher_course_widget);
	}
	else if (button_id == fear_btn_id) {
		for (int index = 0; index < this->m_lessons_list->count(); index++) {
			emotions_statistic_map_temp = &this->m_lessons_list->at(index).emotionsStatisticMap();
			fear_value_list.append(emotions_statistic_map_temp->value("fear"));
		}
		line_and_bar_chart = new LineAndBarChart(fear_value_list, QString("�־�"), QColor(249, 211, 26), this->m_teacher_course_widget);
	}
	else if (button_id == happy_btn_id) {
		for (int index = 0; index < this->m_lessons_list->count(); index++) {
			emotions_statistic_map_temp = &this->m_lessons_list->at(index).emotionsStatisticMap();
			happy_value_list.append(emotions_statistic_map_temp->value("happy"));
		}
		line_and_bar_chart = new LineAndBarChart(happy_value_list, QString("����"), QColor(36, 173, 29), this->m_teacher_course_widget);
	}
	else if (button_id == sad_btn_id) {
		for (int index = 0; index < this->m_lessons_list->count(); index++) {
			emotions_statistic_map_temp = &this->m_lessons_list->at(index).emotionsStatisticMap();
			sad_value_list.append(emotions_statistic_map_temp->value("sad"));
		}
		line_and_bar_chart = new LineAndBarChart(sad_value_list, QString("����"), QColor(240, 80, 80), this->m_teacher_course_widget);
	}
	else if (button_id == surprise_btn_id) {
		for (int index = 0; index < this->m_lessons_list->count(); index++) {
			emotions_statistic_map_temp = &this->m_lessons_list->at(index).emotionsStatisticMap();
			surprise_value_list.append(emotions_statistic_map_temp->value("surprise"));
		}
		line_and_bar_chart = new LineAndBarChart(surprise_value_list, QString("����"), QColor(57, 62, 81), this->m_teacher_course_widget);
	}
	else if (button_id == neutral_btn_id) {
		for (int index = 0; index < this->m_lessons_list->count(); index++) {
			emotions_statistic_map_temp = &this->m_lessons_list->at(index).emotionsStatisticMap();
			neutral_value_list.append(emotions_statistic_map_temp->value("neutral"));
		}
		line_and_bar_chart = new LineAndBarChart(neutral_value_list, QString("ƽ��"), QColor(0, 160, 230), this->m_teacher_course_widget);
	}
	else {
		// �������ݳ�ʼ��
		for (int index = 0; index < this->m_lessons_list->count(); index++) {
			emotions_statistic_map_temp = &this->m_lessons_list->at(index).emotionsStatisticMap();
			angry_set->append(emotions_statistic_map_temp->value("angry"));
			disgust_set->append(emotions_statistic_map_temp->value("disgust"));
			fear_set->append(emotions_statistic_map_temp->value("fear"));
			happy_set->append(emotions_statistic_map_temp->value("happy"));
			sad_set->append(emotions_statistic_map_temp->value("sad"));
			surprise_set->append(emotions_statistic_map_temp->value("surprise"));
			neutral_set->append(emotions_statistic_map_temp->value("neutral"));
		}

		// ������ɫ����
		angry_set->setColor(QColor(108, 111, 192));
		disgust_set->setColor(QColor(35, 183, 229));
		fear_set->setColor(QColor(249, 211, 26));
		happy_set->setColor(QColor(36, 173, 29));
		sad_set->setColor(QColor(240, 80, 80));
		surprise_set->setColor(QColor(57, 62, 81));
		neutral_set->setColor(QColor(0, 160, 230));

		// �������
		bar_series->append(angry_set);
		bar_series->append(disgust_set);
		bar_series->append(fear_set);
		bar_series->append(happy_set);
		bar_series->append(sad_set);
		bar_series->append(surprise_set);
		bar_series->append(neutral_set);

		// �����������ʼ��
		QStringList categories;
		for (int index = 0; index < this->m_lessons_list->count(); index++) {
			categories.append(QString::number(index + 1));
		}
		QBarCategoryAxis *axis_x = new QBarCategoryAxis(this->m_teacher_course_widget);
		axis_x->append(categories);
		QValueAxis *axis_y = new QValueAxis(this->m_teacher_course_widget);

		axis_x->setLabelsFont(font);
		axis_x->setLabelsColor(QColor(153, 153, 153));
		axis_x->setGridLineVisible(false);
		axis_y->setLabelsFont(font);
		axis_y->setLabelsColor(QColor(153, 153, 153));
		axis_y->setLabelFormat("%d");

		// ������ͼ
		chart = new QChart();
		chart->setParent(this->m_teacher_course_widget);
		chart->addSeries(bar_series);
		chart->setMargins(QMargins(0, 0, 0, 0));  // ������߾�Ϊ0
		chart->setAxisX(axis_x);
		chart->setAxisY(axis_y);
		bar_series->attachAxis(axis_x);  // attachAxis Ҫ���� setAxis��
		bar_series->attachAxis(axis_y);
		chart->setAnimationOptions(QChart::AnimationOption::SeriesAnimations);

		// ����ͼ��
		chart->legend()->setFont(font);
		chart->legend()->setAlignment(Qt::AlignBottom);
	}

	if (button_id == all_btn_id) {
		ui.emotion_report_bar_chart_widget->setChart(chart);
	}
	else {
		ui.emotion_report_bar_chart_widget->setChart(line_and_bar_chart);
		ui.emotion_report_bar_chart_widget->setRenderHint(QPainter::Antialiasing);
	}

	return;
}


//**************************************************************************************************
//**************************************************************************************************


TeacherInteractionWidgetController::TeacherInteractionWidgetController(TeacherMainWindow *win, User *user)
	: m_win(win), m_user(user), m_teacher_interaction_widget(nullptr), m_teacher_interaction_enter_dialog(nullptr) {
	// �������γ�ʼ��
	this->interactionWidgetInit();  // interaction_widget��ʼ��
	this->enterDialogInit();  // enter_dialog��ʼ��
	
}

TeacherInteractionWidgetController::~TeacherInteractionWidgetController() {
	if (this->m_teacher_interaction_widget != nullptr) {
		delete this->m_teacher_interaction_widget;
	}
}

void TeacherInteractionWidgetController::enterDialogInit() {
	Ui::TeacherInteractionEnterDialog ui;
	QTableWidgetItem *course_id_item_temp = nullptr,
		*course_name_item_temp = nullptr;
	const QList<CourseBase> *list = this->m_user->coursesBaseList();
	const CourseBase *obj_temp = nullptr;

	// ����enter dialog��ʼ��
	this->m_teacher_interaction_enter_dialog = new TeacherInteractionEnterDialog(this->m_teacher_interaction_widget);
	this->m_teacher_interaction_enter_dialog->setModal(true);  // ģ̬��������ֱ����exec()������
	this->m_teacher_interaction_enter_dialog->show();
	ui = this->m_teacher_interaction_enter_dialog->ui();

	// ����д��table
	ui.courses_table->setRowCount(list->count());
	for (int index = 0; index < list->count(); index++) {
		obj_temp = &list->at(index);
		course_id_item_temp = new QTableWidgetItem(obj_temp->courseId());
		course_id_item_temp->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

		course_name_item_temp = new QTableWidgetItem(obj_temp->courseName());
		course_name_item_temp->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

		ui.courses_table->setItem(index, 0, course_id_item_temp);
		ui.courses_table->setItem(index, 1, course_name_item_temp);
	}

	// �������ź�
	this->connect(ui.confirm_btn, &QPushButton::clicked, this, &TeacherInteractionWidgetController::createLesson);

	return;
}

void TeacherInteractionWidgetController::interactionWidgetInit() {
	Ui::TeacherInteractionWidget ui;

	this->m_teacher_interaction_widget = new TeacherInteractionWidget(this->m_win);
	ui = this->m_teacher_interaction_widget->ui();
	this->m_win->ui().widget_layout->addWidget(this->m_teacher_interaction_widget);  // ������layout��
	this->m_teacher_interaction_widget->show();  // ��ʾ

	// �źŰ�
	this->connect(ui.begin_lesson_btn, &QPushButton::clicked, this, &TeacherInteractionWidgetController::beginLesson);
}

void TeacherInteractionWidgetController::openCamera() {
	this->m_camera = new Camera(this->m_teacher_interaction_widget);

	this->connect(this->m_camera, &Camera::readyRead, this, &TeacherInteractionWidgetController::mineCameraDisplay);

	this->m_camera->open();

	return;
}

void TeacherInteractionWidgetController::mineCameraDisplay(QImage &frame) {
	Ui::TeacherInteractionWidget ui = this->m_teacher_interaction_widget->ui();

	ui.mine_camera_label->setPixmap(QPixmap::fromImage(frame));

	return;
}

void TeacherInteractionWidgetController::handleLessonConnectionRecv() {
	QJsonObject data = this->m_lesson_connection->recv();
	TransportCmd cmd = TransportCmd(data["command"].toInt());

	switch (cmd) {
	case TransportCmd::CreateLesson: handleCommandCreateLesson(data); break;
	}

	return;
}

void TeacherInteractionWidgetController::handlePaintConnectionRecv() {
	QJsonObject data = this->m_paint_connection->recv();
	TransportCmd cmd = TransportCmd(data["command"].toInt());

	switch (cmd) {
	case TransportCmd::PaintCommand: handleCommandPaintCommand(data); break;
	}

	return;
}

void TeacherInteractionWidgetController::createLessonConnection() {
	this->m_lesson_connection = new Connection;
	QThread *request_thread = new QThread;
	this->m_lesson_connection->moveToThread(request_thread);
	request_thread->start();

	//this->m_lesson_connection->connect("49.235.16.174", 5002);
	this->m_lesson_connection->connect("127.0.0.1", 5002);

	// �����źŰ�
	this->connect(this->m_lesson_connection, &Connection::bufferReadyRead, this, &TeacherInteractionWidgetController::handleLessonConnectionRecv);

	return;
}

void TeacherInteractionWidgetController::createPaintConnection() {
	this->m_paint_connection = new Connection;
	QThread *request_thread = new QThread;
	this->m_paint_connection->moveToThread(request_thread);
	request_thread->start();

	//this->m_lesson_connection->connect("49.235.16.174", 5002);
	this->m_paint_connection->connect("127.0.0.1", 5002);

	// �����źŰ�
	this->connect(this->m_paint_connection, &Connection::bufferReadyRead, this, &TeacherInteractionWidgetController::handlePaintConnectionRecv);

	return;
}

void TeacherInteractionWidgetController::createLesson() {
	Ui::TeacherInteractionEnterDialog ui = this->m_teacher_interaction_enter_dialog->ui();
	int row = ui.courses_table->currentRow();
	if (row == -1) {
		Toast *toast = new Toast("����ѡ��һ���γ�");
		toast->show();
		this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);
	}
	else {
		QJsonObject request_json_obj;
		QJsonArray courses_id_json_arr;
		QString course_id, course_name;

		this->createLessonConnection();
		this->createPaintConnection();
		course_id = ui.courses_table->item(row, 0)->text();
		course_name = ui.courses_table->item(row, 1)->text();

		// ������������
		request_json_obj["course_id"] = course_id;
		request_json_obj["course_name"] = course_name;
		request_json_obj["uid"] = this->m_user->uid();
		request_json_obj["username"] = this->m_user->username();

		request_json_obj["command"] = TransportCmd::CreateLesson;
		this->m_lesson_connection->send(request_json_obj);
		request_json_obj["command"] = TransportCmd::CreatePaintConnection;
		this->m_paint_connection->send(request_json_obj);
	}

	return;
}

void TeacherInteractionWidgetController::beginLesson() {
	QJsonObject request_json_obj;
	Toast *toast = new Toast("��ʼ�Ͽ�");

	// ������������
	request_json_obj["command"] = TransportCmd::BeginLesson;
	request_json_obj["course_id"] = this->m_room.courseId();
	request_json_obj["lesson_id"] = this->m_room.lessonId();

	// �������ﲻ��send������ᱨ���̴߳���
	this->m_lesson_connection->realSend(request_json_obj);

	// ���������ɹ�
	toast->show();
	this->connect(this->m_teacher_interaction_widget->board(), &PaintWidget::paintCommandReady, this, &TeacherInteractionWidgetController::sendPaintCommand);

	return;
}

void TeacherInteractionWidgetController::handleCommandCreateLesson(QJsonObject &data) {
	Ui::TeacherInteractionEnterDialog ui = this->m_teacher_interaction_enter_dialog->ui();
	Toast *toast = new Toast;
	const CourseBase *course = &this->m_user->coursesBaseList()->at(this->m_teacher_interaction_enter_dialog->ui().courses_table->selectedItems().first()->row());

	// ������ʼ�����䣨���ã�����
	this->m_room.setRoomName(course->courseName());
	this->m_room.setCourseId(course->courseId());
	this->m_room.setLessonId(data["lesson_id"].toString());
	this->m_room.setTeacherId(this->m_user->uid());
	this->m_room.setTeacherName(this->m_user->username());

	this->m_teacher_interaction_enter_dialog->hide();
	this->openCamera();

	toast->setInfoText(QString("�����ɹ�"));
	toast->show();
	this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);

	return;
}

void TeacherInteractionWidgetController::handleCommandPaintCommand(QJsonObject &data) {
	this->m_teacher_interaction_widget->board()->paintByPaintCommand(data);

	return;
}

void TeacherInteractionWidgetController::sendPaintCommand(QJsonObject &data) {
	data["command"] = TransportCmd::PaintCommand;
	data["course_id"] = this->m_room.courseId();
	data["lesson_id"] = this->m_room.lessonId();
	data["uid"] = this->m_user->uid();

	this->m_paint_connection->realSend(data);

	return;
}

//**************************************************************************************************
//**************************************************************************************************


TeacherController::TeacherController(TeacherMainWindow *win, User *user) 
	: m_win(win), m_user(user), m_teacher_course_widget_controller(nullptr), m_teacher_interaction_widget_controller(nullptr) {
	Ui::TeacherMainWindow ui = this->m_win->ui();

	this->m_win->show();

	this->connect(ui.course_btn, &QPushButton::clicked, this, &TeacherController::showTeacherCourseWidget);
	this->connect(ui.interaction_btn, &QPushButton::clicked, this, &TeacherController::showTeacherInteractionWidget);

	// ����Ĭ����ҳ
	this->showTeacherCourseWidget();
}

TeacherController::~TeacherController() {
	if (this->m_win != nullptr) {
		delete this->m_win;
	}
	if (this->m_user != nullptr) {
		delete this->m_user;
	}
	if (this->m_teacher_course_widget_controller != nullptr) {
		delete this->m_teacher_course_widget_controller;
	}
	if (this->m_teacher_interaction_widget_controller != nullptr) {
		delete this->m_teacher_interaction_widget_controller;
	}
}

/*
	�л�����ʱ����
	�����ǰ���Ӵ�
*/
void TeacherController::clearWidget() {
	// �γ̹���
	if (this->m_teacher_course_widget_controller != nullptr) {
		delete this->m_teacher_course_widget_controller;
		this->m_teacher_course_widget_controller = nullptr;
	}
	// ʵʱ����
	else if (this->m_teacher_interaction_widget_controller != nullptr) {
		delete this->m_teacher_interaction_widget_controller;
		this->m_teacher_interaction_widget_controller = nullptr;
	}

	return;
}

/*
	�л������γ̹����Ӵ�
*/
void TeacherController::showTeacherCourseWidget() {
	this->clearWidget();  // ����������е�ǰ��ʾ���Ӵ�
	this->m_teacher_course_widget_controller = new TeacherCourseWidgetController(this->m_win, this->m_user);  // ��̬�����Ӵ�

	return;
}

/*
	�л�����ʵʱ�������Ӵ�
*/
void TeacherController::showTeacherInteractionWidget() {
	this->clearWidget();  // ����������е�ǰ��ʾ���Ӵ�
	if (this->m_teacher_interaction_widget_controller == nullptr) {
		this->m_teacher_interaction_widget_controller = new TeacherInteractionWidgetController(this->m_win, this->m_user);  // ��̬�����Ӵ�
	}

	return;
}