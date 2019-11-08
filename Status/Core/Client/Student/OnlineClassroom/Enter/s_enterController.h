#pragma once
#include "s_enterDialog.h"
#include "Core/Model/user.h"
#include "Core/Component/toast.h"

class SEnterController : public QObject {
	Q_OBJECT

signals:
	void joinInLesson(QMap<QString, QVariant> &data);

public:
	SEnterController(QObject *parent = nullptr);
	virtual ~SEnterController();

	void showEnterDialog(QWidget *parent, QList<QMap<QString, QVariant>> &data_list);
	void hideEnterDialog();

protected:
	SEnterDialog *m_online_classroom_enter_dialog;

	void initEnterDialog(QWidget *parent, QList<QMap<QString, QVariant>> &data_list);
	void emitSignalJoinInLesson();
};