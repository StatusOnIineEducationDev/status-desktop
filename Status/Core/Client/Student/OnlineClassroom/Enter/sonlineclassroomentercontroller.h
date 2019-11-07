#pragma once
#include "sonlineclassroomenterdialog.h"
#include "Core/Model/user.h"
#include "Core/Component/toast.h"

class SOnlineClassroomEnterController : public QObject {
	Q_OBJECT

signals:
	void joinInLesson(QMap<QString, QVariant> &data);

public:
	SOnlineClassroomEnterController(QObject *parent = nullptr);
	virtual ~SOnlineClassroomEnterController();

	void showOnlineClassroomEnterDialog(QWidget *parent, QList<QMap<QString, QVariant>> &data_list);
	void hideOnlineClassroomEnterDialog();

protected:
	SOnlineClassroomEnterDialog *m_online_classroom_enter_dialog;

	void initOnlineClassroomEnterDialog(QWidget *parent, QList<QMap<QString, QVariant>> &data_list);
	void emitSignalJoinInLesson();
};