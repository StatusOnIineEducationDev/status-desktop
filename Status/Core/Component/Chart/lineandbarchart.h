#pragma once
#pragma execution_character_set("utf-8")
#include <QtCharts>
#include <QLineSeries>
#include <QAreaSeries>
#include <QScatterSeries>

class LineAndBarChart : public QChart {
	Q_OBJECT

public:
	LineAndBarChart(QList<qreal> &values, QString &label, QColor &color, QObject *parent);
	virtual ~LineAndBarChart();

protected:
	QLineSeries *m_line_series;
	QBarSeries *m_bar_series;
};