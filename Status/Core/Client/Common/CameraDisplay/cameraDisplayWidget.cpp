#include "cameraDisplayWidget.h"


CameraDisplayWidget::CameraDisplayWidget(QWidget *parent)
	: QWidget(parent) {
	m_ui.setupUi(this);

}

CameraDisplayWidget::~CameraDisplayWidget() {

}

void CameraDisplayWidget::mineCameraDisplay(QImage &frame) {
	this->m_ui.frame_label->setPixmap(QPixmap::fromImage(frame));

	return;
}