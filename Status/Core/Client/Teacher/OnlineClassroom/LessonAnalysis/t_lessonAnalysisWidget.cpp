#include "t_lessonAnalysisWidget.h"


TeacherLessonAnalysisWidget::TeacherLessonAnalysisWidget(QWidget *parent)
	: QWidget(parent), m_member_widget(nullptr), m_need_username_json(true) {
	m_ui.setupUi(this);
	
	this->m_member_widget = new MemberWidget(this);
	this->m_ui.member_layout->addWidget(this->m_member_widget);
}

TeacherLessonAnalysisWidget::~TeacherLessonAnalysisWidget() {

}

void TeacherLessonAnalysisWidget::handleCommandRefreshOnlineList(QJsonObject &data) {
	QJsonArray add_list, remove_list;

	this->m_online_list = data["online_list"].toArray();
	add_list = data["add_list"].toArray();
	remove_list = data["remove_list"].toArray();

	if (data["has_username_json"].toBool()) {
		this->m_username_json = data["username_json"].toObject();
		qDebug() << this->m_username_json;
	}

	// 添加新增在线的
	for (int i = 0; i < add_list.count(); i++) {
		// add_list[i].toString() != user->getUid()
		if (true) {
			if (m_username_json.contains(add_list[i].toString())) {
				this->m_member_widget->addMember(
					add_list[i].toString(),
					this->m_username_json.take(add_list[i].toString()).toString(),
					QPixmap(":/pic/Resources/material/pic/student.png"),
					QPixmap(":/pic/Resources/material/pic/online.png"));
			}
			else {
				this->m_need_username_json = true;
			}
		}
	}
	// 移除不在线的item
	for (int i = 0; i < remove_list.count(); i++) {
		this->m_member_widget->removeMember(remove_list[i].toString());
	}
	

	return;
}

void TeacherLessonAnalysisWidget::refreshOnlineList() {
	QJsonObject request_json_obj;

	// ——请求数据
	request_json_obj["command"] = TransportCmd::RefreshOnlineList;
	request_json_obj["online_list"] = this->m_online_list;
	request_json_obj["need_username_json"] = m_need_username_json;

	if (m_need_username_json) {
		m_need_username_json = false;
	}

	emit lessonConnectionDataReady(request_json_obj);

	return;
}