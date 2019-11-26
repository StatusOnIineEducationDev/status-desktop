#pragma once
#include <QWidget>
#include <QDateTime>
#include <QJsonObject>
#include "ui_t_handleRaiseHandWidget.h"
#include "t_raiseHandItemWidget.h"
#include "Core/Client/onlineEdu.h"



class TeacherHandleRaiseHandWidget : public QWidget {
	Q_OBJECT

public:
	TeacherHandleRaiseHandWidget(QWidget *parent = nullptr);
	~TeacherHandleRaiseHandWidget();
	const Ui::TeacherHandleRaiseHandWidget& ui() const { return this->m_ui; };

	void addMemberInHandleRaiseHandWidget(const QPixmap &user_pic, 
		const QString &username, const int &timestamp);
	void removeMemberFromSpeechWidget(const int row);
protected:
	Ui::TeacherHandleRaiseHandWidget m_ui;
};
