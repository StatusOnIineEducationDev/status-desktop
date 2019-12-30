#pragma once
#include <QWidget>
#include <QDateTime>
#include "ui_c_courseAnalysisRankItemWidget.h"


class CourseAnalysisRankItemWidget : public QWidget {
	Q_OBJECT

public:
	CourseAnalysisRankItemWidget(const QString &user_pic_url, const QString &username, 
		const int &times, const int &concentration, const int &rank, 
		QWidget *parent = nullptr);
	virtual ~CourseAnalysisRankItemWidget();
	const Ui::CourseAnalysisRankItemWidget& ui() const { return this->m_ui; };

protected:
	Ui::CourseAnalysisRankItemWidget m_ui;
};
