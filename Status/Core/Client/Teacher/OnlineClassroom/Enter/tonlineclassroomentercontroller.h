#pragma once
#include "tonlineclassroomenterdialog.h"
#include "Core/Model/user.h"
#include "Core/Component/toast.h"

class TOnlineClassroomEnterController : public QObject {
	Q_OBJECT

signals:
	void createLesson(QMap<QString, QVariant> &data);

public:
	TOnlineClassroomEnterController(QObject *parent = nullptr);
	virtual ~TOnlineClassroomEnterController();

	void showOnlineClassroomEnterDialog(QWidget *parent, QList<QMap<QString, QVariant>> &data_list);
	void hideOnlineClassroomEnterDialog();

protected:
	TOnlineClassroomEnterDialog *m_online_classroom_enter_dialog;

	void initOnlineClassroomEnterDialog(QWidget *parent, QList<QMap<QString, QVariant>> &data_list);
	void emitSignalCreateLesson();
};