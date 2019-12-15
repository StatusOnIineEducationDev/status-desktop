#pragma once
#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include "ui_s_enterDialog.h"
#include "Core/Component/Toast/toast.h"


class StudentEnterDialog : public QDialog {
	Q_OBJECT

signals:
	void joinInLesson(QString &course_id, QString &course_name);

public:
	StudentEnterDialog(QWidget *parent = nullptr);
	~StudentEnterDialog();
	const Ui::StudentEnterDialog& ui() const { return this->m_ui; };

	void loadData(QList<QMap<QString, QVariant>> &data_list);

protected:
	void emitSignalJoinInLesson();

	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

	Ui::StudentEnterDialog m_ui;

	bool is_pressed;  // �������Ƿ���
	bool is_moving;  // �����ƶ�
	QPoint start_pos;  // ����������ʱ������
};