#pragma once
#include "tenterdialog.h"
#include "Core/Model/user.h"
#include "Core/Component/toast.h"

class TEnterController : public QObject {
	Q_OBJECT

signals:
	void createLesson(QMap<QString, QVariant> &data);

public:
	TEnterController(QObject *parent = nullptr);
	virtual ~TEnterController();

	void showEnterDialog(QWidget *parent, QList<QMap<QString, QVariant>> &data_list);
	void hideEnterDialog();

protected:
	TEnterDialog *m_online_classroom_enter_dialog;

	void initEnterDialog(QWidget *parent, QList<QMap<QString, QVariant>> &data_list);
	void emitSignalCreateLesson();
};