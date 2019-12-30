#pragma once
#include <QWidget>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QListWidgetItem>
#include "ui_c_courseAnalysisWidget.h"
#include "courseAnalysisRankItemWidget.h"
#include "Core/Client/conf.h"
#include "Core/Component/Toast/toast.h"
#include "Core/Component/Loading/loading.h"
#include "Core/Client/onlineEdu.h"
#include "Core/Network/httpRequest.h"
#include "Core/Model/user.h"


class CourseAnalysisWidget : public QWidget {
	Q_OBJECT

signals:
	void loadHtmlFinished(QString &course_id);

public:
	CourseAnalysisWidget(QWidget *parent = nullptr);
	virtual ~CourseAnalysisWidget();
	const Ui::CourseAnalysisWidget& ui() const { return this->m_ui; };

	void setCourseId(const QString &course_id) { this->m_course_id = course_id; return; };
	void updateAllData(const QString &course_id);

protected:
	void loadHtml();
	void emitSignalLoadHtmlFinished();
	void loadConcCmprChartFinished();

	void updateConcCmprChart();
	void updateConcCmprChartRequest();
	void updateConcCmprChartRequestSuccess(const QJsonObject &data);

	void updateRank();
	void updateRankRequest();
	void updateRankRequestSuccess(const QJsonObject &data);
	void updateRankListWidget(const QJsonArray &data);

	Ui::CourseAnalysisWidget m_ui;

	QString m_course_id;

	bool conc_cmpr_chart_finished;
};
