#include "t_handleRaiseHandWidget.h"


TeacherHandleRaiseHandWidget::TeacherHandleRaiseHandWidget(QWidget *parent)
	: QWidget(parent) {
	m_ui.setupUi(this);

	this->init();

	this->setAutoFillBackground(false);
	this->setAttribute(Qt::WA_TranslucentBackground, true);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint | Qt::Popup);
}

TeacherHandleRaiseHandWidget::~TeacherHandleRaiseHandWidget() {

}

void TeacherHandleRaiseHandWidget::init() {
	// ——信号绑定
	this->connect(this->m_ui.accept_btn, &QPushButton::clicked,
		this, &TeacherHandleRaiseHandWidget::acceptRaiseHand);
	this->connect(this->m_ui.refuse_btn, &QPushButton::clicked,
		this, &TeacherHandleRaiseHandWidget::refuseRaiseHand);

	return;
}

void TeacherHandleRaiseHandWidget::addMemberInHandleRaiseHandWidget(const QPixmap &user_pic,
	const QString &username, const int &timestamp) {
	QListWidgetItem *item = new QListWidgetItem;
	TeacherRaiseHandItemWidget *item_widget = new TeacherRaiseHandItemWidget(user_pic,
		username, timestamp, this->m_ui.raise_hand_view);

	item->setSizeHint(QSize(item_widget->width(), item_widget->height()));
	this->m_ui.raise_hand_view->addItem(item);
	this->m_ui.raise_hand_view->setItemWidget(item, item_widget);

	return;
}

void TeacherHandleRaiseHandWidget::removeMemberFormHandleRaiseHandWidget(const int row) {
	if (row == -1) {
		return;
	}

	this->m_ui.raise_hand_view->takeItem(row);

	return;
}

void TeacherHandleRaiseHandWidget::handleCommandRaiseHand(QJsonObject &data) {
	QMap<QString, QVariant> info;
	QPixmap user_pic = QPixmap(":/pic/Resources/material/pic/student.png");

	info["student_id"] = data["uid"].toString();
	info["username"] = data["username"].toString();
	info["timestamp"] = data["timestamp"].toInt();

	this->m_rasie_hand_info_list.append(info);
	emit this->rasieHandInfoListChange(this->m_rasie_hand_info_list.count());
	this->addMemberInHandleRaiseHandWidget(user_pic,
		data["username"].toString(), data["timestamp"].toInt());

	return;
}

void TeacherHandleRaiseHandWidget::handleCommandResultOfRaiseHand(QJsonObject &data) {
	QMap<QString, QVariant> info;

	if (ApplicationStatus(data["application_status"].toInt()) == ApplicationStatus::Accepted) {
		info["student_id"] = data["student_id"].toString();
		info["username"] = data["username"].toString();
		
		emit this->raiseHandAccepted(info);
	}

	// ——处理handle_raise_hand_widget
	for (int index = 0; index < this->m_rasie_hand_info_list.count(); index++) {
		if (this->m_rasie_hand_info_list[index]["student_id"].toString() == data["student_id"].toString()) {
			this->m_rasie_hand_info_list.removeAt(index);
			emit this->rasieHandInfoListChange(this->m_rasie_hand_info_list.count());
			this->removeMemberFormHandleRaiseHandWidget(index);
			break;
		}
	}

	return;
}

void TeacherHandleRaiseHandWidget::acceptRaiseHand() {
	QJsonObject request_json_obj;
	int row = this->m_ui.raise_hand_view->currentRow();

	if (row != -1) {
		request_json_obj["command"] = TransportCmd::ResultOfRaiseHand;
		request_json_obj["application_status"] = ApplicationStatus::Accepted;
		request_json_obj["student_id"] =
			this->m_rasie_hand_info_list[row]["student_id"].toString();
		emit this->lessonConnectionDataReady(request_json_obj);
	}

	return;
}

void TeacherHandleRaiseHandWidget::refuseRaiseHand() {
	QJsonObject request_json_obj;
	int row = this->m_ui.raise_hand_view->currentRow();

	if (row != -1) {
		request_json_obj["command"] = TransportCmd::ResultOfRaiseHand;
		request_json_obj["application_status"] = ApplicationStatus::Refused;
		request_json_obj["student_id"] =
			this->m_rasie_hand_info_list[row]["student_id"].toString();
		emit this->lessonConnectionDataReady(request_json_obj);
	}

	return;
}
