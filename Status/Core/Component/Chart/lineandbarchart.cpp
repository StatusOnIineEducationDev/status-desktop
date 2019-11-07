#include "lineandbarchart.h"
#pragma execution_character_set("utf-8")  

LineAndBarChart::LineAndBarChart(QList<qreal> &values, QString &label, QColor &color, QObject *parent)
	: m_bar_series(nullptr), m_line_series(nullptr) {
	this->setParent(parent);  // 给本类指定父容器

	QBarSet *bar_set;
	QStringList categories;
	QList<QPointF> point_list;
	QBarCategoryAxis *axis_x;
	QValueAxis *axis_y;

	bar_set = new QBarSet(label, this);
	bar_set->append(values);
	bar_set->setColor(color);
	this->m_bar_series = new QBarSeries(this);
	this->m_bar_series->append(bar_set);
	this->m_line_series = new QLineSeries(this);
	for (int index = 0; index < values.count(); index++) {
		point_list.append(QPointF(index, values[index]));
	}
	this->m_line_series->append(point_list);

	// ——坐标轴初始化
	for (int index = 0; index < values.count(); index++) {
		categories.append(QString::number(index + 1));
	}
	axis_x = new QBarCategoryAxis(this);
	axis_x->append(categories);
	axis_x->setLabelsColor(QColor(153, 153, 153));
	axis_x->setGridLineVisible(false);
	axis_y = new QValueAxis(this);
	axis_y->setLabelsColor(QColor(153, 153, 153));
	axis_y->setLabelFormat("%d");

	// ——图例
	this->legend()->setAlignment(Qt::AlignBottom);

	// ——绘图
	this->addSeries(this->m_bar_series);
	this->addSeries(this->m_line_series);
	this->m_line_series->setName(label + "变化趋势");
	this->setMargins(QMargins(0, 0, 0, 0));  // 设置外边距为0
	this->setAxisX(axis_x);
	this->setAxisY(axis_y);
	this->m_bar_series->attachAxis(axis_x);  // attachAxis 要放在 setAxis后
	this->m_bar_series->attachAxis(axis_y);
	this->m_line_series->attachAxis(axis_x);
	this->m_line_series->attachAxis(axis_y);
	this->setAnimationOptions(QChart::AnimationOption::SeriesAnimations);
}

LineAndBarChart::~LineAndBarChart() {
	// 都绑定了parent，不需要手动释放
}