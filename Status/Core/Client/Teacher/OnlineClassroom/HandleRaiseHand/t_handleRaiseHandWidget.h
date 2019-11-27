#pragma once
#include <QWidget>
#include <QDateTime>
#include <QJsonObject>
#include "ui_t_handleRaiseHandWidget.h"
#include "t_raiseHandItemWidget.h"
#include "Core/Client/onlineEdu.h"



class TeacherHandleRaiseHandWidget : public QWidget {
	Q_OBJECT

signals:
	void lessonConnectionDataReady(QJsonObject &data);
	void rasieHandInfoListChange(int count);
	void raiseHandAccepted(QMap<QString, QVariant> &info);

public:
	TeacherHandleRaiseHandWidget(QWidget *parent = nullptr);
	~TeacherHandleRaiseHandWidget();
	const Ui::TeacherHandleRaiseHandWidget& ui() const { return this->m_ui; };

	void handleCommandRaiseHand(QJsonObject &data);
	void handleCommandResultOfRaiseHand(QJsonObject &data);

	void acceptRaiseHand();
	void refuseRaiseHand();

protected:
	void init();

	void addMemberInHandleRaiseHandWidget(const QPixmap &user_pic, 
		const QString &username, const int &timestamp);
	void removeMemberFormHandleRaiseHandWidget(const int row);

	Ui::TeacherHandleRaiseHandWidget m_ui;

	/*
		|-info(m_rasie_hand_info_list)
			|-student_id(QString)
			|-username(QString)
			|-timestamp(int)
	*/
	QList<QMap<QString, QVariant>> m_rasie_hand_info_list;  // 举手信息
};
