#pragma once

#include <QLabel>
#include <QImage>
#include <QThread>
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <opencv2/core/core.hpp>  

class Camera : public QThread {
	Q_OBJECT

public:
	Camera(QWidget *parent = nullptr);
	virtual ~Camera();
	void open() { this->m_cap.open(0); this->start(); return; };
	void close() { this->m_cap.release(); return; };
	bool isOpened() { return this->m_had_opened; };
	void run();
	void stop() { this->m_running_flag = false; return; };
	const QImage& getFrameImage() { return this->m_frame_img; };
	const cv::Mat& getFrameMat() { return this->m_frame_mat; };

signals:
	void readyRead(QImage &frame);
	void hadOpened();

protected:
	bool m_had_opened;
	bool m_running_flag;
	cv::VideoCapture m_cap;
	cv::Mat m_frame_mat;
	QImage m_frame_img;
	QWidget *m_parent;
};