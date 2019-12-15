#pragma once
#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include "ui_t_enterDialog.h"
#include "Core/Component/Toast/toast.h"


class TeacherEnterDialog : public QDialog {
	Q_OBJECT

signals:
	void createLesson(QString &course_id, QString &course_name);

public:
	TeacherEnterDialog(QWidget *parent = Q_NULLPTR);
	~TeacherEnterDialog();
	const Ui::TeacherEnterDialog& ui() const { return this->m_ui; };

	void loadData(QList<QMap<QString, QVariant>> &data_list);

protected:
	Ui::TeacherEnterDialog m_ui;

	void emitSignalCreateLesson();

	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

	bool is_pressed;  // 鼠标左键是否按下
	bool is_moving;  // 正在移动
	QPoint start_pos;  // 鼠标左键点下时的坐标
};