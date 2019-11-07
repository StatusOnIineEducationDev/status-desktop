#pragma once
#pragma execution_character_set("utf-8")  
#include <QtCharts>
#include <QLineSeries>
#include <QAreaSeries>
#include <QScatterSeries>
#include <qstring.h>

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

