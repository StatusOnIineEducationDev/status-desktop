#pragma once
#include <QDebug>
#include <QImage>
#include <QPixmap>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgproc/types_c.h"

// 将cv::Mat转化位QImage
QImage cvMatToQImage(const cv::Mat &inMat);

//将cv::Mat转化为QPixmap
QPixmap cvMatToQPixmap(const cv::Mat &inMat);
//将QImage转化为cv::Mat

cv::Mat QImageToCvMat(const QImage &inImage, bool inCloneImageData = true);

//将QPixmap转化为cv::Mat
cv::Mat QPixmapToCvMat(const QPixmap &inPixmap, bool inCloneImageData = true);
