#include "Core/View/Component/chart.h"
#pragma execution_character_set("utf-8")  


AreaChart::AreaChart(QList<qreal> &values, QColor &color, QObject *parent)
	: m_line_series(nullptr), m_check_point_series(nullptr), m_area_series(nullptr), m_scatter_series(nullptr) {
	this->setParent(parent);

	// ——样式
	QPen pen(color, 2);
	QList<QPointF> point_list;

	this->m_line_series = new QLineSeries(this);
	this->m_line_series->setPen(pen);
	for (int index = 0; index < values.count(); index++) {
		point_list.append(QPointF(index + 1, values[index]));
	}
	this->m_line_series->append(point_list);

	this->m_area_series = new QAreaSeries(this);  // 创建面积
	this->m_area_series->setUpperSeries(this->m_line_series);
	this->m_scatter_series = new QScatterSeries(this);  // 创建散点
	this->m_scatter_series->append(this->m_line_series->points());
	color.setAlpha(100);
	this->m_area_series->setBrush(color);
	this->m_scatter_series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
	this->m_scatter_series->setMarkerSize(8);
	this->m_scatter_series->setBorderColor(color);
	this->m_scatter_series->setBrush(QColor(255, 255, 255));

	// ——坐标轴初始化
	QValueAxis *axis_x = new QValueAxis(this), *axis_y = new QValueAxis(this);
	axis_x->setLabelsColor(QColor(153, 153, 153));
	axis_x->setRange(1, this->m_line_series->points().constLast().x());
	axis_x->setTickCount(this->m_line_series->points().count());
	axis_x->setGridLineVisible(false);
	axis_x->setLabelFormat("%d");
	axis_y->setLabelsColor(QColor(153, 153, 153));
	axis_y->setRange(0, 100);
	axis_y->setLabelFormat("%d");

	// ——绘图
	this->addSeries(this->m_area_series);  // 添加面积
	this->addSeries(this->m_line_series);  // 添加线
	this->addSeries(this->m_scatter_series);  // 添加散点（这三个顺序不可调换，必须先添加面积再添加描线，要保证描线绘在面积之上）
	this->setAxisX(axis_x);
	this->setAxisY(axis_y);
	this->m_area_series->attachAxis(axis_x);
	this->m_area_series->attachAxis(axis_y);
	this->m_line_series->attachAxis(axis_x);
	this->m_line_series->attachAxis(axis_y);
	this->m_scatter_series->attachAxis(axis_x);
	this->m_scatter_series->attachAxis(axis_y);
	this->setAnimationOptions(QChart::AnimationOption::SeriesAnimations);

	// ——其他控制
	this->setMargins(QMargins(0, 0, 0, 0));  // 设置外边距为0
	this->legend()->setVisible(false);  // 隐藏图例

	// ——信号绑定
	this->connect(this->m_scatter_series, &QScatterSeries::hovered, this, &AreaChart::checkPoint);
}

AreaChart::~AreaChart() {
	if (this->m_line_series != nullptr) { delete this->m_line_series; }
	if (this->m_check_point_series != nullptr) { delete this->m_check_point_series; }
	if (this->m_area_series != nullptr) { delete this->m_area_series; }
	if (this->m_scatter_series != nullptr) { delete this->m_scatter_series; }
}

void AreaChart::checkPoint(const QPointF &point, bool state) {
	if (state) {
		// ——画线
		if (this->m_check_point_series != nullptr) {
			delete this->m_check_point_series;
		}
		this->m_check_point_series = new QLineSeries;

		QPen pen = this->m_line_series->pen();
		pen.setWidth(1);
		this->m_check_point_series->setPen(pen);

		this->m_check_point_series->append(QPointF(point.x(), 0));
		this->m_check_point_series->append(QPointF(point.x(), 100));

		this->addSeries(this->m_check_point_series);
		this->m_check_point_series->attachAxis(this->m_scatter_series->attachedAxes()[0]);
		this->m_check_point_series->attachAxis(this->m_scatter_series->attachedAxes()[1]);

		// ——更新label
		emit this->hovered(point);
	}

	return;
}


//**************************************************************************************************
//**************************************************************************************************


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
	this->m_line_series->setName(label+"变化趋势");
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
	if (this->m_line_series != nullptr) { delete this->m_line_series; }
	if (this->m_bar_series != nullptr) { delete this->m_bar_series; }
}


//**************************************************************************************************
//**************************************************************************************************


AreaChartDynamicMin::AreaChartDynamicMin(QColor &color, QObject *parent)
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

void AreaChartDynamicMin::append(double &timestamp, int &value) {
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


//**************************************************************************************************
//**************************************************************************************************


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

void AreaChartDynamic::append(double &timestamp, int &value) {
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