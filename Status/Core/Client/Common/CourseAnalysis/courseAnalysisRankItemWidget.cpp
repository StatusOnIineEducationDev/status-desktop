#include "courseAnalysisRankItemWidget.h"


CourseAnalysisRankItemWidget::CourseAnalysisRankItemWidget(const QString &user_pic_url,
	const QString &username, const int &times, const int &concentration,
	const int &rank, QWidget *parent)
	: QWidget(parent) {
	m_ui.setupUi(this);

	this->m_ui.username_text->setText(username);
	this->m_ui.times_text->setText(QString::number(times));
	this->m_ui.concentration_text->setText(QString::number(concentration));
	this->m_ui.rank_text->setText(QString::number(rank));

	if (user_pic_url == "null_str") {
		this->m_ui.user_pic->setPixmap(QPixmap(":/pic/Resources/material/pic/student.png"));
	}
}

CourseAnalysisRankItemWidget::~CourseAnalysisRankItemWidget() {

}