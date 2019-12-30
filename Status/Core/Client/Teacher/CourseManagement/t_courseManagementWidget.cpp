#include "t_courseManagementWidget.h"


TeacherCourseManagementWidget::TeacherCourseManagementWidget(QWidget *parent)
	: CourseManagementWidget(parent) {
	this->loadFunctionButtonWidget();
	this->loadCourseOverviewWidget();
	this->loadCourseResourceWidget();
	this->loadCourseAnalysisWidget();
}

TeacherCourseManagementWidget::~TeacherCourseManagementWidget() {

}

void TeacherCourseManagementWidget::loadFunctionButtonWidget() {
	// ——加载功能条
	this->m_function_button_widget = new TeacherCourseManagementFunctionButtonWidget(this);
	this->m_ui.function_btn_widget_layout->
		addWidget(this->m_function_button_widget);

	// ——信号连接
	Ui::TeacherCourseManagementFunctionButtonWidget ui = this->m_function_button_widget->ui();
	this->connect(ui.create_course_btn, &QPushButton::clicked,
		this, &TeacherCourseManagementWidget::loadCreateCourseDialog);

	return;
}

void TeacherCourseManagementWidget::loadCourseOverviewWidget() {
	// ——加载课程概况页
	this->m_course_overview_widget = new TeacherCourseOverviewWidget(this);
	this->m_ui.function_tabWidget->addTab(this->m_course_overview_widget, "课程概况");
	
	// 显式刷新
	this->m_course_overview_widget->
		updateAllData(user->getCourseList().at(0).courseId());
	
	// ——信号绑定
	this->connect(this->courseBasicWidget(), &CourseBasicWidget::courseSwitched,
		this->m_course_overview_widget, &TeacherCourseOverviewWidget::updateAllData);

	return;
}

void TeacherCourseManagementWidget::loadCourseResourceWidget() {
	// ——加载课程资源页
	this->m_course_resource_widget = new TeacherCourseResourceWidget(this);
	this->m_ui.function_tabWidget->addTab(this->m_course_resource_widget, "课程资源");

	// 显式刷新
	this->m_course_resource_widget->
		updateAllData(user->getCourseList().at(0).courseId());

	// ——信号绑定
	this->connect(this->courseBasicWidget(), &CourseBasicWidget::courseSwitched,
		this->m_course_resource_widget, &TeacherCourseResourceWidget::updateAllData);

	return;
}

void TeacherCourseManagementWidget::loadCourseAnalysisWidget() {
	// ——加载课程分析页
	this->m_course_analysis_widget = new TeacherCourseAnalysisWidget(this);
	this->m_ui.function_tabWidget->addTab(this->m_course_analysis_widget, "课程分析");

	// ——首次显式刷新
	this->m_course_analysis_widget->setCourseId(user->getCourseList().at(0).courseId());
	this->connect(this->m_course_analysis_widget, &TeacherCourseAnalysisWidget::loadHtmlFinished,
		this->m_course_analysis_widget, &TeacherCourseAnalysisWidget::updateAllData);
	// ——信号绑定
	this->connect(this->courseBasicWidget(), &CourseBasicWidget::courseSwitched,
		this->m_course_analysis_widget, &TeacherCourseAnalysisWidget::updateAllData);

	return;
}

void TeacherCourseManagementWidget::loadCreateCourseDialog() {
	// ——加载创建课程窗口
	this->m_create_course_dialog = new TeacherCreateCourseDialog(this);
	this->m_create_course_dialog->setModal(true);  // 模态（这里与直接用exec()有区别）
	this->m_create_course_dialog->show();

	// ——信号绑定
	this->connect(this->m_create_course_dialog, &TeacherCreateCourseDialog::createCourseSuccess,
		this, &TeacherCourseManagementWidget::getCourseListRequest);

	return;
}