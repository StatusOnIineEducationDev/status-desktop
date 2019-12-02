#pragma once
#pragma execution_character_set("utf-8")  
#include <QWidget>
#include <QJsonObject>
#include <QMetaType>
#include "ui_c_courseOverviewWidget.h"
#include "Core/Network/httpRequest.h"
#include "Core/Model/user.h"
#include "Core/Client/conf.h"
#include "textInfoCardWidget.h"


class CourseOverviewWidget : public QWidget {
	Q_OBJECT

public:
	CourseOverviewWidget(QWidget *parent = nullptr);
	~CourseOverviewWidget();
	const Ui::CourseOverviewWidget& ui() const { return this->m_ui; };

	void updateAllData(const QString &course_id);

protected:
	void loadIntroductionCardWidget();
	void loadNoticeCardWidget();

	void getIntroductionRequest(const QString &course_id);
	void getIntroductionSuccess(QJsonObject &data);
	void getNoticeRequest(const QString &course_id);
	void getNoticeSuccess(QJsonObject &data);

	Ui::CourseOverviewWidget m_ui;

	TextInfoCardWidget *m_introduction_card_widget;
	TextInfoCardWidget *m_notice_card_widget;
};