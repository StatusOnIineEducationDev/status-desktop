#pragma once
#pragma execution_character_set("utf-8")  
#include <QtCharts>
#include <QLineSeries>
#include <QAreaSeries>


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