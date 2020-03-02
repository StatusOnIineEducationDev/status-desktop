#include "t_lessonAnalysisWidget.h"


TeacherLessonAnalysisWidget::TeacherLessonAnalysisWidget(QWidget *parent)
	: QWidget(parent), m_member_widget(nullptr), m_need_username_json(true),
	m_concentration_area_chart(nullptr), m_checked_uid("lesson"), m_lastly_timestamp(-1) {
	m_ui.setupUi(this);
	
	this->m_member_widget = new MemberWidget(this);
	this->m_ui.member_layout->addWidget(this->m_member_widget);

	// ��������רע�����ͼ�����ԣ�
	this->loadConcentrationAreaChart();

	// �źŰ�
	this->connect(this->m_member_widget->ui().member_view, &QListWidget::currentItemChanged,
		this, &TeacherLessonAnalysisWidget::changeCheckedUid);
}

TeacherLessonAnalysisWidget::~TeacherLessonAnalysisWidget() {

}

void TeacherLessonAnalysisWidget::handleCommandRefreshOnlineList(QJsonObject &data) {
	QJsonArray add_list, remove_list;
	QString uid;

	add_list = data["add_list"].toArray();
	remove_list = data["remove_list"].toArray();

	if (data["has_username_json"].toBool()) {
		this->m_username_json = data["username_json"].toObject();
	}

	// ����������ߵ�
	for (int i = 0; i < add_list.count(); i++) {
		uid = add_list[i].toString();
		if (m_username_json.contains(uid) &&
			this->m_member_widget->findItemWidget(uid) == nullptr) {
			if (add_list[i].toString() != user->getUid()) {
				this->m_member_widget->addMember(
					uid,
					this->m_username_json.value(uid).toString(),
					QPixmap(":/pic/Resources/material/pic/student.png"),
					QPixmap(":/pic/Resources/material/pic/online.png"));
			}
			// �����ʶ�Լ�
			else {
				this->m_member_widget->addMemberAtTop(
					uid,
					this->m_username_json.value(uid).toString() + "(��)",
					QPixmap(":/pic/Resources/material/pic/teacher.png"),
					QPixmap(":/pic/Resources/material/pic/online.png"));
			}
		}
		else {
			this->m_need_username_json = true;
		}
	}
	// �Ƴ������ߵ�item
	for (int i = 0; i < remove_list.count(); i++) {
		this->m_member_widget->removeMember(remove_list[i].toString());
	}
	
	this->m_online_list = this->m_member_widget->getUidJsonAarry();

	return;
}

void TeacherLessonAnalysisWidget::handleCommandGetStudentConc(QJsonObject &data) {
	QString checked_uid = data["checked_uid"].toString();

	if (checked_uid == "lesson") {
		this->m_ui.name_text->setText("��ǰ����");
	}
	else {
		this->m_ui.name_text->setText(this->m_username_json.value(checked_uid).toString());
	}
	
	// ˢ��רע������
	if (data["concentration_timestamp"].toInt() != this->m_lastly_timestamp) {
		this->m_ui.concentration_value_text->setText(
			QString::number(data["concentration_value"].toInt()));
		this->m_ui.time_text->setText(
			QDateTime::fromTime_t(
				data["concentration_timestamp"].toInt()).toString("yyyy-MM-dd hh:mm:ss"));
		this->m_lastly_timestamp = data["concentration_timestamp"].toInt();
		this->updateDynamicAreaChat(
			data["concentration_timestamp"].toInt(),
			data["concentration_value"].toInt());
	}
	
	return;
}

void TeacherLessonAnalysisWidget::refreshOnlineList() {
	QJsonObject request_json_obj;

	// ������������
	request_json_obj["command"] = TransportCmd::RefreshOnlineList;
	request_json_obj["online_list"] = this->m_online_list;
	request_json_obj["need_username_json"] = m_need_username_json;

	if (m_need_username_json) {
		m_need_username_json = false;
	}

	emit lessonConnectionDataReady(request_json_obj);

	return;
}

void TeacherLessonAnalysisWidget::getStudentConc() {
	QJsonObject request_json_obj;

	// ������������
	request_json_obj["command"] = TransportCmd::GetStudentConc;
	request_json_obj["checked_uid"] = this->m_checked_uid;

	emit lessonConnectionDataReady(request_json_obj);

	return;
}

void TeacherLessonAnalysisWidget::changeCheckedUid(QListWidgetItem *item) {
	QWidget *item_widget;
	QString uid;

	// ���ͼ
	this->m_concentration_area_chart->clear();

	item_widget = this->m_member_widget->ui().member_view->itemWidget(item);
	uid = item_widget->findChild<QLabel*>("uid_text")->text();
	// ������������ʦ�Լ������л����鿴ȫ�������Ϣ
	if (uid == user->getUid()) {
		uid = "lesson";
	}
	
	this->m_checked_uid = uid;

	return;
}

void TeacherLessonAnalysisWidget::updateDynamicAreaChat(
	int concentration_timestamp, int concentration_value) {
	// ��������רע��ͼ
	this->m_concentration_area_chart->append(concentration_timestamp, concentration_value);

	return;
}

void TeacherLessonAnalysisWidget::loadConcentrationAreaChart() {
	// ��������רע�����ͼ�����ԣ�
	if (m_concentration_area_chart != nullptr) {
		delete m_concentration_area_chart;
	}
	this->m_concentration_area_chart = new AreaChartDynamic(QColor(18, 150, 219), this);
	this->m_ui.concentration_area_chart_widget->
		setChart(this->m_concentration_area_chart);
	this->m_ui.concentration_area_chart_widget->
		setRenderHint(QPainter::Antialiasing);

	return;
}