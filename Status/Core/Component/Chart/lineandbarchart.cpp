#include "lineandbarchart.h"
#pragma execution_character_set("utf-8")  

LineAndBarChart::LineAndBarChart(QList<qreal> &values, QString &label, QColor &color, QObject *parent)
	: m_bar_series(nullptr), m_line_series(nullptr) {
	this->setParent(parent);  // ������ָ��������

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

	// �����������ʼ��
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

	// ����ͼ��
	this->legend()->setAlignment(Qt::AlignBottom);

	// ������ͼ
	this->addSeries(this->m_bar_series);
	this->addSeries(this->m_line_series);
	this->m_line_series->setName(label + "�仯����");
	this->setMargins(QMargins(0, 0, 0, 0));  // ������߾�Ϊ0
	this->setAxisX(axis_x);
	this->setAxisY(axis_y);
	this->m_bar_series->attachAxis(axis_x);  // attachAxis Ҫ���� setAxis��
	this->m_bar_series->attachAxis(axis_y);
	this->m_line_series->attachAxis(axis_x);
	this->m_line_series->attachAxis(axis_y);
	this->setAnimationOptions(QChart::AnimationOption::SeriesAnimations);
}

LineAndBarChart::~LineAndBarChart() {
	// ������parent������Ҫ�ֶ��ͷ�
}