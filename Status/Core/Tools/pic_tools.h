#pragma once
#include <QDebug>
#include <QImage>
#include <QPixmap>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgproc/types_c.h"

// ��cv::Matת��λQImage
QImage cvMatToQImage(const cv::Mat &inMat);

//��cv::Matת��ΪQPixmap
QPixmap cvMatToQPixmap(const cv::Mat &inMat);
//��QImageת��Ϊcv::Mat

cv::Mat QImageToCvMat(const QImage &inImage, bool inCloneImageData = true);

//��QPixmapת��Ϊcv::Mat
cv::Mat QPixmapToCvMat(const QPixmap &inPixmap, bool inCloneImageData = true);
