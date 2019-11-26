#include "t_enterDialog.h"


TeacherEnterDialog::TeacherEnterDialog(QWidget *parent)
	: QDialog(parent) {
	m_ui.setupUi(this);
	// 窗口属性设置
	this->setWindowFlag(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground, true);

	// 信号绑定
	this->connect(this->m_ui.confirm_btn, &QPushButton::clicked,
		this, &TeacherEnterDialog::emitSignalCreateLesson);
}

TeacherEnterDialog::~TeacherEnterDialog() {

}

void TeacherEnterDialog::loadData(QList<QMap<QString, QVariant>> &data_list) {
	QTableWidgetItem *course_id_item_temp = nullptr,
		*course_name_item_temp = nullptr;

	// ——写入table
	this->m_ui.courses_table->setRowCount(data_list.count());
	for (int index = 0; index < data_list.count(); index++) {
		course_id_item_temp = new QTableWidgetItem(data_list[index]["course_id"].toString());
		course_id_item_temp->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

		course_name_item_temp = new QTableWidgetItem(data_list[index]["course_name"].toString());
		course_name_item_temp->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);


		this->m_ui.courses_table->setItem(index, 0, course_id_item_temp);
		this->m_ui.courses_table->setItem(index, 1, course_name_item_temp);
	}

	return;
}

void TeacherEnterDialog::emitSignalCreateLesson() {
	int row = this->m_ui.courses_table->currentRow();

	if (row == -1) {
		Toast *toast = new Toast("请先选择一个课程");
		toast->show();
		this->connect(toast, &Toast::complete, toast, &Toast::deleteLater);
	}
	else {
		emit this->createLesson(this->m_ui.courses_table->item(row, 0)->text(),
			this->m_ui.courses_table->item(row, 1)->text());
	}

	return;
}

void TeacherEnterDialog::mouseMoveEvent(QMouseEvent *event) {
	// 计算鼠标当前位置
	// 如果鼠标在title bar且左键按下，则执行移动
	if (this->is_moving) {
		this->move(this->pos() + event->pos() - this->start_pos);
	}

	return;
}

void TeacherEnterDialog::mousePressEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton) {
		this->is_pressed = true;
		this->start_pos = QPoint(event->pos().x(), event->pos().y());
		if (this->start_pos.x() < this->width() && this->start_pos.y() < 35) {
			this->is_moving = true;
		}
	}

	return;
}

void TeacherEnterDialog::mouseReleaseEvent(QMouseEvent *event) {
	this->is_pressed = false;
	this->is_moving = false;

	return;
}