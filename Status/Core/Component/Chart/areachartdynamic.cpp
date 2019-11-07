#include "areachartdynamic.h"

AreaChartDynamic::AreaChartDynamic(QColor &color, QObject *parent)
	: m_range_max(60), m_origin_x(-1) {
	this->setParent(parent);

	// ——样式
	QPen pen(color, 1);

	this->m_line_series = new QLineSeries(this);
	this->m_line_series->setPen(pen);
	this->m_area_series = new QAreaSeries(this);
	this->m_area_series->setUpperSeries(this->m_line_series);
	color.setAlpha(25);
	this->m_area_series->setBrush(color);

	// ——坐标轴初始化
	QValueAxis *axis_x = new QValueAxis(this), *axis_y = new QValueAxis(this);
	axis_x->setRange(0, this->m_range_max);
	axis_x->setGridLineVisible(false);
	axis_x->setVisible(false);
	axis_y->setRange(0, 100);
	axis_y->setGridLineVisible(false);
	axis_y->setVisible(false);

	// ——绘图
	this->addSeries(this->m_area_series);  // 添加面积
	this->addSeries(this->m_line_series);  // 添加线
	this->setAxisX(axis_x);
	this->setAxisY(axis_y);
	this->m_area_series->attachAxis(axis_x);
	this->m_area_series->attachAxis(axis_y);
	this->m_line_series->attachAxis(axis_x);
	this->m_line_series->attachAxis(axis_y);

	// ——其他控制
	this->setMargins(QMargins(0, 0, 0, 0));  // 设置边距为0
	this->layout()->setContentsMargins(0, 0, 0, 0);
	this->setBackgroundRoundness(0);       //设置背景区域无圆角
	this->legend()->setVisible(false);  // 隐藏图例
}

void AreaChartDynamic::append(int &timestamp, int &value) {
	// 更新原点
	if (this->m_origin_x < 0) {
		this->m_origin_x = timestamp;
	}

	this->m_line_series->append(timestamp - this->m_origin_x, value);

	if (timestamp - this->m_origin_x > this->m_range_max) {
		this->axisX()->setRange(timestamp - this->m_origin_x - this->m_range_max, timestamp - this->m_origin_x);
	}

	return;
}