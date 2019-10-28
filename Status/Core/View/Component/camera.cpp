#include "Core/View/Component/camera.h"

QImage cvMat_to_QImage(const cv::Mat &mat) {
	switch (mat.type()) {
		// 8-bit, 4 channel
	case CV_8UC4:
	{
		QImage image(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB32);
		return image;
	}

	// 8-bit, 3 channel
	case CV_8UC3:
	{
		QImage image(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
		return image.rgbSwapped();
	}

	// 8-bit, 1 channel
	case CV_8UC1:
	{
		static QVector<QRgb>  sColorTable;
		// only create our color table once
		if (sColorTable.isEmpty()) {
			for (int i = 0; i < 256; ++i)
				sColorTable.push_back(qRgb(i, i, i));
		}
		QImage image(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
		image.setColorTable(sColorTable);
		return image;
	}

	default:
		qDebug("Image format is not supported: depth=%d and %d channels\n", mat.depth(), mat.channels());
		break;
	}
	return QImage();
}

Camera::Camera(QWidget *parent)
	: m_parent(parent), m_had_opened(false), m_running_flag(true) {
	this->connect(this->m_parent, &QWidget::destroyed, this, &Camera::stop);
	this->connect(this, &Camera::finished, this, &Camera::deleteLater);

	qRegisterMetaType<QImage>("QImage&");  // 这句要加
}

Camera::~Camera() {
	this->exit(0);
}

void Camera::run() {
	this->m_running_flag = true;
	while (this->m_running_flag) {
		this->m_cap >> this->m_frame_mat;
		// ——摄像头能正常读取帧
		if (!this->m_frame_mat.empty()) {
			// ——发射“已开启信号”
			if (!this->m_had_opened) {
				this->m_had_opened = true;
				emit this->hadOpened();
			}
			this->m_frame_img = cvMat_to_QImage(this->m_frame_mat);
			emit this->readyRead(this->m_frame_img);
		}
	}

	return;
}