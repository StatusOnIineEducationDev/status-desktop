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
	// �������ع�����
	this->m_function_button_widget = new TeacherCourseManagementFunctionButtonWidget(this);
	this->m_ui.function_btn_widget_layout->
		addWidget(this->m_function_button_widget);

	// �����ź�����
	Ui::TeacherCourseManagementFunctionButtonWidget ui = this->m_function_button_widget->ui();
	this->connect(ui.create_course_btn, &QPushButton::clicked,
		this, &TeacherCourseManagementWidget::loadCreateCourseDialog);

	return;
}

void TeacherCourseManagementWidget::loadCourseOverviewWidget() {
	// �������ؿγ̸ſ�ҳ
	this->m_course_overview_widget = new TeacherCourseOverviewWidget(this);
	this->m_ui.function_tabWidget->addTab(this->m_course_overview_widget, "�γ̸ſ�");
	
	// ��ʽˢ��
	this->m_course_overview_widget->
		updateAllData(user->getCourseList().at(0).courseId());
	
	// �����źŰ�
	this->connect(this->courseBasicWidget(), &CourseBasicWidget::courseSwitched,
		this->m_course_overview_widget, &TeacherCourseOverviewWidget::updateAllData);

	return;
}

void TeacherCourseManagementWidget::loadCourseResourceWidget() {
	// �������ؿγ���Դҳ
	this->m_course_resource_widget = new TeacherCourseResourceWidget(this);
	this->m_ui.function_tabWidget->addTab(this->m_course_resource_widget, "�γ���Դ");

	// ��ʽˢ��
	this->m_course_resource_widget->
		updateAllData(user->getCourseList().at(0).courseId());

	// �����źŰ�
	this->connect(this->courseBasicWidget(), &CourseBasicWidget::courseSwitched,
		this->m_course_resource_widget, &TeacherCourseResourceWidget::updateAllData);

	return;
}

void TeacherCourseManagementWidget::loadCourseAnalysisWidget() {
	// �������ؿγ̷���ҳ
	this->m_course_analysis_widget = new TeacherCourseAnalysisWidget(this);
	this->m_ui.function_tabWidget->addTab(this->m_course_analysis_widget, "�γ̷���");

	// �����״���ʽˢ��
	this->m_course_analysis_widget->setCourseId(user->getCourseList().at(0).courseId());
	this->connect(this->m_course_analysis_widget, &TeacherCourseAnalysisWidget::loadHtmlFinished,
		this->m_course_analysis_widget, &TeacherCourseAnalysisWidget::updateAllData);
	// �����źŰ�
	this->connect(this->courseBasicWidget(), &CourseBasicWidget::courseSwitched,
		this->m_course_analysis_widget, &TeacherCourseAnalysisWidget::updateAllData);

	return;
}

void TeacherCourseManagementWidget::loadCreateCourseDialog() {
	// �������ش����γ̴���
	this->m_create_course_dialog = new TeacherCreateCourseDialog(this);
	this->m_create_course_dialog->setModal(true);  // ģ̬��������ֱ����exec()������
	this->m_create_course_dialog->show();

	// �����źŰ�
	this->connect(this->m_create_course_dialog, &TeacherCreateCourseDialog::createCourseSuccess,
		this, &TeacherCourseManagementWidget::getCourseListRequest);

	return;
}