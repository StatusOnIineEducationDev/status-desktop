#include "t_enterController.h"


TEnterController::TEnterController(QObject *parent) 
	:QObject(parent), m_online_classroom_enter_dialog(nullptr) {

}

TEnterController::~TEnterController() {

}

void TEnterController::initEnterDialog(QWidget *parent, QList<QMap<QString, QVariant>> &data_list) {
	/*
		|-data(QMap<QString, QVariant>)
			|-course_id(QString)
			|-course_name(QString)
	*/
	Ui::TEnterDialog ui;
	QTableWidgetItem *course_id_item_temp = nullptr,
		*course_name_item_temp = nullptr;

	// ——enter dialog初始化
	this->m_online_classroom_enter_dialog = new TEnterDialog(parent);
	this->m_online_classroom_enter_dialog->setModal(true);  // 模态（这里与直接用exec()有区别）
	ui = this->m_online_classroom_enter_dialog->ui();

	// ——写入table
	ui.courses_table->setRowCount(data_list.count());
	for (int index = 0; index < data_list.count(); index++) {
		course_id_item_temp = new QTableWidgetItem(data_list[index]["course_id"].toString());
		course_id_item_temp->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

		course_name_item_temp = new QTableWidgetItem(data_list[index]["course_name"].toString());
		course_name_item_temp->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

		ui.courses_table->setItem(index, 0, course_id_item_temp);
		ui.courses_table->setItem(index, 1, course_name_item_temp);
	}

	// ——绑定信号
	this->connect(ui.confirm_btn, &QPushButton::clicked, this, &TEnterController::emitSignalCreateLesson);

	return;
}

void TEnterController::showEnterDialog(QWidget *parent, QList<QMap<QString, QVariant>> &data_list) {
	this->initEnterDialog(parent, data_list);
	this->m_online_classroom_enter_dialog->show();

	return;
}

void TEnterController::hideEnterDialog() {
	this->m_online_classroom_enter_dialog->hide();
	this->deleteLater();

	return;
}

void TEnterController::emitSignalCreateLesson() {
	Ui::TEnterDialog ui = this->m_online_classroom_enter_dialog->ui();
	int row = ui.courses_table->currentRow();
	QMap<QString, QVariant> data;

	if (row == -1) {
		Toast *toast = new Toast("请先选择一个课程");
		toast->show();
		this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);
	}
	else {
		data["course_id"] = ui.courses_table->item(row, 0)->text();
		data["course_name"] = ui.courses_table->item(row, 1)->text();
		emit this->createLesson(data);
	}

	return;
}