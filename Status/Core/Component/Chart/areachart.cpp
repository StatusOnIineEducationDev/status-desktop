#include "areachart.h"
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
	// 都绑定了parent，不需要手动释放
}

void AreaChart::checkPoint(const QPointF &point, bool state) {
	if (state) {
		// ——画线
		if (this->m_check_point_series != nullptr) {
			delete this->m_check_point_series;
		}
		this->m_check_point_series = new QLineSeries(this);

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