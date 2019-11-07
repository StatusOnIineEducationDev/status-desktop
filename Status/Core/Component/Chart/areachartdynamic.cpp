#include "areachartdynamic.h"

AreaChartDynamic::AreaChartDynamic(QColor &color, QObject *parent)
	: m_range_max(60), m_origin_x(-1) {
	this->setParent(parent);

	// ������ʽ
	QPen pen(color, 1);

	this->m_line_series = new QLineSeries(this);
	this->m_line_series->setPen(pen);
	this->m_area_series = new QAreaSeries(this);
	this->m_area_series->setUpperSeries(this->m_line_series);
	color.setAlpha(25);
	this->m_area_series->setBrush(color);

	// �����������ʼ��
	QValueAxis *axis_x = new QValueAxis(this), *axis_y = new QValueAxis(this);
	axis_x->setRange(0, this->m_range_max);
	axis_x->setGridLineVisible(false);
	axis_x->setVisible(false);
	axis_y->setRange(0, 100);
	axis_y->setGridLineVisible(false);
	axis_y->setVisible(false);

	// ������ͼ
	this->addSeries(this->m_area_series);  // ������
	this->addSeries(this->m_line_series);  // �����
	this->setAxisX(axis_x);
	this->setAxisY(axis_y);
	this->m_area_series->attachAxis(axis_x);
	this->m_area_series->attachAxis(axis_y);
	this->m_line_series->attachAxis(axis_x);
	this->m_line_series->attachAxis(axis_y);

	// ������������
	this->setMargins(QMargins(0, 0, 0, 0));  // ���ñ߾�Ϊ0
	this->layout()->setContentsMargins(0, 0, 0, 0);
	this->setBackgroundRoundness(0);       //���ñ���������Բ��
	this->legend()->setVisible(false);  // ����ͼ��
}

void AreaChartDynamic::append(int &timestamp, int &value) {
	// ����ԭ��
	if (this->m_origin_x < 0) {
		this->m_origin_x = timestamp;
	}

	this->m_line_series->append(timestamp - this->m_origin_x, value);

	if (timestamp - this->m_origin_x > this->m_range_max) {
		this->axisX()->setRange(timestamp - this->m_origin_x - this->m_range_max, timestamp - this->m_origin_x);
	}

	return;
}