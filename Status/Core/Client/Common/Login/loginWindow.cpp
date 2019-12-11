#include "loginWindow.h"


LoginWindow::LoginWindow(QWidget *parent) 
	: QMainWindow(parent), is_pressed(false), is_moving(false) {
	m_ui.setupUi(this);

	// 窗口属性设置
	this->setWindowFlag(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground, true);

	// 信号绑定
	this->connect(this->m_ui.confirm_btn, &QPushButton::clicked,
		this, &LoginWindow::login);
}

LoginWindow::~LoginWindow() {

}

void LoginWindow::login() {
	if (this->m_ui.account_edit->text() == "") {
		this->m_ui.warn_text->setText("请输入账号");
		return;
	}
	else if (this->m_ui.password_edit->text() == "") {
		this->m_ui.warn_text->setText("请输入密码");
		return;
	}
	
	this->loginRequest();

	return;
}

void LoginWindow::loginRequest() {
	this->loginRunningAnimation();
	
	// ——不变
	QJsonObject request_json_obj;
	QString url = "http://" + ReadConf::G_HTTP_HOST + ":"
		+ QString::number(ReadConf::G_HTTP_PORT);
	HttpRequest *request_obj = new HttpRequest;
	QThread *request_thread = new QThread;
	request_obj->moveToThread(request_thread);

	// ——可变
	//     ——可变数据
	if (this->m_ui.teacher_btn->isChecked()) {
		request_json_obj["account_type"] = AccountType::Teacher;
	}
	else {
		request_json_obj["account_type"] = AccountType::Student;
	}
	request_json_obj["account"] = this->m_ui.account_edit->text();
	request_json_obj["pwd"] = this->m_ui.password_edit->text();
	request_obj->request(QUrl(url + "/user/loginPC"), request_json_obj);
	this->connect(request_obj, &HttpRequest::success,
		this, &LoginWindow::loginRequestSuccess);

	// ——不变
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::quit);
	this->connect(request_obj, &HttpRequest::complete, request_thread, &QThread::deleteLater);
	this->connect(request_obj, &HttpRequest::complete, request_obj, &HttpRequest::deleteLater);
	request_thread->start();

	return;
}

void LoginWindow::loginRequestSuccess(const QJsonObject &data) {
	this->loginResetAnimation();

	ErrorCode err = ErrorCode(data["error_code"].toInt());

	switch (err) {
	case NoError:
		this->m_ui.warn_text->setText("");
		this->loadLoginData(data);
		switch (user->getAccountType()) {
		case AccountType::Teacher: this->loadTeacherClient(); break;
		case AccountType::Student: this->loadStudentClient(); break;
		}
		break;
	case AccountTypeError:
		this->m_ui.warn_text->setText("账号类型错误，请重试");
		break;
	case AccountNotFoundError:
	case PasswordError:
		this->m_ui.warn_text->setText("账号或密码错误，请重试");
		break;
	}

	return;
}

void LoginWindow::loginRunningAnimation() {
	QPropertyAnimation *frame_animation, *logo_animation, *point_1_animation, 
		*point_2_animation, *point_3_animation;
	QParallelAnimationGroup *point_animation;

	frame_animation = new QPropertyAnimation(this->m_ui.main_frame, "pos", this);
	frame_animation->setDuration(1000);
	frame_animation->setStartValue(this->m_ui.main_frame->pos());
	frame_animation->setEndValue(QPoint(0, 610));
	frame_animation->setEasingCurve(QEasingCurve::OutQuart);

	logo_animation = new QPropertyAnimation(this->m_ui.logo_pic, "pos", this);
	logo_animation->setDuration(1000);
	logo_animation->setStartValue(this->m_ui.logo_pic->pos());
	logo_animation->setEndValue(QPoint(275, 55));
	logo_animation->setEasingCurve(QEasingCurve::OutQuart);

	point_1_animation = new QPropertyAnimation(this->m_ui.point_1, "pos", this);
	point_1_animation->setDuration(2000);
	point_1_animation->setStartValue(QPoint(0, 115));
	point_1_animation->setEndValue(QPoint(610, 115));
	point_1_animation->setEasingCurve(QEasingCurve::OutInCubic);
	point_2_animation = new QPropertyAnimation(this->m_ui.point_2, "pos", this);
	point_2_animation->setDuration(2500);
	point_2_animation->setStartValue(QPoint(-50, 115));
	point_2_animation->setEndValue(QPoint(610, 115));
	point_2_animation->setEasingCurve(QEasingCurve::OutInCubic);
	point_3_animation = new QPropertyAnimation(this->m_ui.point_3, "pos", this);
	point_3_animation->setDuration(3000);
	point_3_animation->setStartValue(QPoint(-100, 115));
	point_3_animation->setEndValue(QPoint(610, 115));
	point_3_animation->setEasingCurve(QEasingCurve::OutInCubic);
	point_animation = new QParallelAnimationGroup(this);
	point_animation->addAnimation(point_1_animation);
	point_animation->addAnimation(point_2_animation);
	point_animation->addAnimation(point_3_animation);
	point_animation->setLoopCount(10);

	frame_animation->start();
	logo_animation->start();
	point_animation->start();

	return;
}

void LoginWindow::loginResetAnimation() {
	QPropertyAnimation *frame_animation, *logo_animation, *point_1_animation,
		*point_2_animation, *point_3_animation;
	QParallelAnimationGroup *point_animation;

	frame_animation = new QPropertyAnimation(this->m_ui.main_frame, "pos", this);
	frame_animation->setDuration(1000);
	frame_animation->setStartValue(this->m_ui.main_frame->pos());
	frame_animation->setEndValue(QPoint(0, 40));
	frame_animation->setEasingCurve(QEasingCurve::OutQuart);

	logo_animation = new QPropertyAnimation(this->m_ui.logo_pic, "pos", this);
	logo_animation->setDuration(1000);
	logo_animation->setStartValue(this->m_ui.logo_pic->pos());
	logo_animation->setEndValue(QPoint(275, 0));
	logo_animation->setEasingCurve(QEasingCurve::OutQuart);

	frame_animation->start();
	logo_animation->start();

	return;
}

void LoginWindow::loadLoginData(const QJsonObject &data) {
	QString uid = data["uid"].toString(),
		username = data["username"].toString();
	AccountType account_type = AccountType(data["account_type"].toInt());
	UserStatus user_status = UserStatus(data["user_status"].toInt());
	QList<CourseBasic> course_list;
	CourseBasic *course_temp;

	QJsonArray arr = data["course_list"].toArray();
	// ——加载course_list
	for (int index = 0; index < arr.count(); index++) {
		course_temp = new CourseBasic(arr[index].toObject()["course_id"].toString(),
			arr[index].toObject()["course_name"].toString());
		course_list.append(*course_temp);
	}

	// ——创建用户类
	user = new User(QPixmap(":/pic/Resources/material/pic/teacher.png"),
		uid, username, course_list, account_type, user_status);

	return;
}

void LoginWindow::loadTeacherClient() {
	TeacherMainWindow *win = new TeacherMainWindow;

	// ——信号绑定
	this->connect(win, &TeacherMainWindow::close,
		this, &LoginWindow::close);
	this->connect(win->ui().logout_btn, &QPushButton::clicked,
		this, &LoginWindow::show);

	// ——其他
	Toast::setWin(win);
	this->hide();
	win->show();
	
	return;
}

void LoginWindow::loadStudentClient() {
	StudentMainWindow *win = new StudentMainWindow;

	// ——信号绑定
	this->connect(win, &StudentMainWindow::close,
		this, &LoginWindow::close);
	this->connect(win->ui().logout_btn, &QPushButton::clicked,
		this, &LoginWindow::show);

	// ——其他
	Toast::setWin(win);
	this->hide();
	win->show();

	return;
}

void LoginWindow::mouseMoveEvent(QMouseEvent *event) {
	// 计算鼠标当前位置
	// 如果鼠标在title bar且左键按下，则执行移动
	if (this->is_moving) {
		this->move(this->pos() + event->pos() - this->start_pos);
	}

	return;
}

void LoginWindow::mousePressEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton) {
		this->is_pressed = true;
		this->start_pos = QPoint(event->pos().x(), event->pos().y());
		if (this->start_pos.x() < this->width() && this->start_pos.y() < 35) {
			this->is_moving = true;
		}
	}

	return;
}

void LoginWindow::mouseReleaseEvent(QMouseEvent *event) {
	this->is_pressed = false;
	this->is_moving = false;

	return;
}