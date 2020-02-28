#include "loading.h"


LoadingMask::LoadingMask(QWidget *parent)
	: QWidget(parent) {
	m_ui.setupUi(this);

	this->setAttribute(Qt::WA_TranslucentBackground, true);

	this->resizeMask();
	this->animation();
}

LoadingMask::~LoadingMask() {

}

void LoadingMask::resizeMask() {
	if (this->parentWidget() == nullptr) {
		return;
	}

	this->setGeometry(0, 0, this->parentWidget()->width(), this->parentWidget()->height());

	return;
}

void LoadingMask::animation() {
	QPropertyAnimation *s1_a_1, *s1_a_2, *s2_a_1, *s2_a_2, *s2_a_3, *s2_a_4, *s3_a_1, *s3_a_2;
	QSequentialAnimationGroup *square_animation_1, *square_animation_2, *square_animation_3;
	int duration = 200;

	s1_a_1 = new QPropertyAnimation(this->m_ui.square_1, "geometry", this);
	s1_a_1->setStartValue(QRect(21, 0, 3, 20));
	s1_a_1->setEndValue(QRect(21, 6, 3, 10));
	s1_a_1->setDuration(2 * duration);
	s1_a_2 = new QPropertyAnimation(this->m_ui.square_1, "geometry", this);
	s1_a_2->setStartValue(QRect(21, 6, 3, 10));
	s1_a_2->setEndValue(QRect(21, 0, 3, 20));
	s1_a_2->setDuration(2 * duration);
	square_animation_1 = new QSequentialAnimationGroup(this);
	square_animation_1->addAnimation(s1_a_1);
	square_animation_1->addAnimation(s1_a_2);
	square_animation_1->setLoopCount(-1);

	s2_a_1 = new QPropertyAnimation(this->m_ui.square_2, "geometry", this);
	s2_a_1->setStartValue(QRect(29, 3, 3, 15));
	s2_a_1->setEndValue(QRect(29, 6, 3, 10));
	s2_a_1->setDuration(duration);
	s2_a_2 = new QPropertyAnimation(this->m_ui.square_2, "geometry", this);
	s2_a_2->setStartValue(QRect(29, 6, 3, 10));
	s2_a_2->setEndValue(QRect(29, 3, 3, 15));
	s2_a_2->setDuration(duration);
	s2_a_3 = new QPropertyAnimation(this->m_ui.square_2, "geometry", this);
	s2_a_3->setStartValue(QRect(29, 3, 3, 15));
	s2_a_3->setEndValue(QRect(29, 0, 3, 20));
	s2_a_3->setDuration(duration);
	s2_a_4 = new QPropertyAnimation(this->m_ui.square_2, "geometry", this);
	s2_a_4->setStartValue(QRect(29, 0, 3, 20));
	s2_a_4->setEndValue(QRect(29, 3, 3, 15));
	s2_a_4->setDuration(duration);
	square_animation_2 = new QSequentialAnimationGroup(this);
	square_animation_2->addAnimation(s2_a_1);
	square_animation_2->addAnimation(s2_a_2);
	square_animation_2->addAnimation(s2_a_3);
	square_animation_2->addAnimation(s2_a_4);
	square_animation_2->setLoopCount(-1);

	s3_a_1 = new QPropertyAnimation(this->m_ui.square_3, "geometry", this);
	s3_a_1->setStartValue(QRect(37, 6, 3, 10));
	s3_a_1->setEndValue(QRect(37, 0, 3, 20));
	s3_a_1->setDuration(2 * duration);
	s3_a_2 = new QPropertyAnimation(this->m_ui.square_3, "geometry", this);
	s3_a_2->setStartValue(QRect(37, 0, 3, 20));
	s3_a_2->setEndValue(QRect(37, 6, 3, 10));
	s3_a_2->setDuration(2 * duration);
	square_animation_3 = new QSequentialAnimationGroup(this);
	square_animation_3->addAnimation(s3_a_1);
	square_animation_3->addAnimation(s3_a_2);
	square_animation_3->setLoopCount(-1);

	square_animation_1->start();
	square_animation_2->start();
	square_animation_3->start();

	return;
}


// ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
// ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！


LoadingWidget::LoadingWidget(QWidget *parent)
	: QWidget(parent) {
	m_ui.setupUi(this);

	this->setAttribute(Qt::WA_TranslucentBackground, true);

	this->setPos(parent);
	this->animation();
}

LoadingWidget::~LoadingWidget() {

}

void LoadingWidget::setPos(QWidget *parent) {
	if (parent == nullptr) {
		return;
	}

	int x = (parent->width() / 2) - (this->width() / 2),
		y = 10;

	this->setGeometry(x, y, this->width(), this->height());

	return;
}

void LoadingWidget::animation() {
	QPropertyAnimation *s1_a_1, *s1_a_2, *s2_a_1, *s2_a_2, *s2_a_3, *s2_a_4, *s3_a_1, *s3_a_2;
	QSequentialAnimationGroup *square_animation_1, *square_animation_2, *square_animation_3;
	int duration = 200;

	s1_a_1 = new QPropertyAnimation(this->m_ui.square_1, "geometry", this);
	s1_a_1->setStartValue(QRect(21, 0, 3, 20));
	s1_a_1->setEndValue(QRect(21, 6, 3, 10));
	s1_a_1->setDuration(2 * duration);
	s1_a_2 = new QPropertyAnimation(this->m_ui.square_1, "geometry", this);
	s1_a_2->setStartValue(QRect(21, 6, 3, 10));
	s1_a_2->setEndValue(QRect(21, 0, 3, 20));
	s1_a_2->setDuration(2 * duration);
	square_animation_1 = new QSequentialAnimationGroup(this);
	square_animation_1->addAnimation(s1_a_1);
	square_animation_1->addAnimation(s1_a_2);
	square_animation_1->setLoopCount(-1);

	s2_a_1 = new QPropertyAnimation(this->m_ui.square_2, "geometry", this);
	s2_a_1->setStartValue(QRect(29, 3, 3, 15));
	s2_a_1->setEndValue(QRect(29, 6, 3, 10));
	s2_a_1->setDuration(duration);
	s2_a_2 = new QPropertyAnimation(this->m_ui.square_2, "geometry", this);
	s2_a_2->setStartValue(QRect(29, 6, 3, 10));
	s2_a_2->setEndValue(QRect(29, 3, 3, 15));
	s2_a_2->setDuration(duration);
	s2_a_3 = new QPropertyAnimation(this->m_ui.square_2, "geometry", this);
	s2_a_3->setStartValue(QRect(29, 3, 3, 15));
	s2_a_3->setEndValue(QRect(29, 0, 3, 20));
	s2_a_3->setDuration(duration);
	s2_a_4 = new QPropertyAnimation(this->m_ui.square_2, "geometry", this);
	s2_a_4->setStartValue(QRect(29, 0, 3, 20));
	s2_a_4->setEndValue(QRect(29, 3, 3, 15));
	s2_a_4->setDuration(duration);
	square_animation_2 = new QSequentialAnimationGroup(this);
	square_animation_2->addAnimation(s2_a_1);
	square_animation_2->addAnimation(s2_a_2);
	square_animation_2->addAnimation(s2_a_3);
	square_animation_2->addAnimation(s2_a_4);
	square_animation_2->setLoopCount(-1);

	s3_a_1 = new QPropertyAnimation(this->m_ui.square_3, "geometry", this);
	s3_a_1->setStartValue(QRect(37, 6, 3, 10));
	s3_a_1->setEndValue(QRect(37, 0, 3, 20));
	s3_a_1->setDuration(2 * duration);
	s3_a_2 = new QPropertyAnimation(this->m_ui.square_3, "geometry", this);
	s3_a_2->setStartValue(QRect(37, 0, 3, 20));
	s3_a_2->setEndValue(QRect(37, 6, 3, 10));
	s3_a_2->setDuration(2 * duration);
	square_animation_3 = new QSequentialAnimationGroup(this);
	square_animation_3->addAnimation(s3_a_1);
	square_animation_3->addAnimation(s3_a_2);
	square_animation_3->setLoopCount(-1);

	square_animation_1->start();
	square_animation_2->start();
	square_animation_3->start();

	return;
}