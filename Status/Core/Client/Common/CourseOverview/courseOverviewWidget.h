#pragma once
#pragma execution_character_set("utf-8")  
#include <QWidget>
#include <QJsonObject>
#include <QGraphicsDropShadowEffect>
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

	void getCourseIntroductionRequest(const QString &course_id);
	void getCourseIntroductionSuccess(const QJsonObject &data);
	void getCourseNoticeRequest(const QString &course_id);
	void getCourseNoticeSuccess(const QJsonObject &data);

	Ui::CourseOverviewWidget m_ui;

	TextInfoCardWidget *m_introduction_card_widget;
	TextInfoCardWidget *m_notice_card_widget;
};