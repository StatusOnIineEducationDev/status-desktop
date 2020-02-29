#pragma once
#include <QWidget>
#include <QListView>
#include <QJsonObject>
#include "ui_c_memberWidget.h"
#include "Core/Client/onlineEdu.h"
#include "memberItemWidget.h"


class MemberWidget : public QWidget {
	Q_OBJECT

signals:
	void lessonConnectionDataReady(QJsonObject &data);

public:
	MemberWidget(QWidget *parent = nullptr);
	virtual ~MemberWidget();
	const Ui::MemberWidget& ui() const { return this->m_ui; };

	void addMember(const QString &uid, const QString &username, 
		const QPixmap &user_pic, const QPixmap &status_pic);
	void removeMember(const QString &uid);
	void setMemberStatusPic(const QString &uid, const QPixmap &status_pic);

protected:
	QWidget* findItemWidget(const QString &uid);

	Ui::MemberWidget m_ui;
};