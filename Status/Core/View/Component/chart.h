#pragma once
#include <QtCharts>
#include <QLineSeries>
#include <QAreaSeries>
#include <QScatterSeries>


class AreaChart : public QChart {
	Q_OBJECT

public:
	AreaChart(QList<qreal> &values, QColor &color, QObject *parent);
	virtual ~AreaChart();

public slots:
	void checkPoint(const QPointF &point, bool state);

signals:
	void hovered(const QPointF &point);


protected:
	QLineSeries *m_line_series;
	QLineSeries *m_check_point_series;
	QAreaSeries *m_area_series;
	QScatterSeries *m_scatter_series;
};


class LineAndBarChart : public QChart {
	Q_OBJECT

public:
	LineAndBarChart(QList<qreal> &values, QString &label, QColor &color, QObject *parent);
	virtual ~LineAndBarChart();

protected:
	QLineSeries *m_line_series;
	QBarSeries *m_bar_series;
};


class AreaChartDynamicMin : public QChart {
	Q_OBJECT

public:
	AreaChartDynamicMin(QColor &color, QObject *parent);
	void append(double &timestamp, int &value);

protected:
	int m_range_max;
	double m_origin_x;
	QLineSeries *m_line_series;
	QAreaSeries *m_area_series;
};


class AreaChartDynamic : public QChart {
	Q_OBJECT

public:
	AreaChartDynamic(QColor &color, QObject *parent);
	void append(double &timestamp, int &value);

protected:
	int m_range_max;
	double m_origin_x;
	QLineSeries *m_line_series;
	QAreaSeries *m_area_series;
};