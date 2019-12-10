#include "Core/Tools/tools.h"

QString formatTime(int secs) {
	QString hh, mm, ss;
	int hour, min, sec;

	sec = secs % 60;
	min = (secs / 60) % 60;
	hour = (secs / 3600);

	ss = QString::number(sec).sprintf("%02d", sec);
	mm = QString::number(min).sprintf("%02d", min);
	hh = QString::number(hour).sprintf("%02d", hour);

	return hh + ":" + mm + ":" + ss;
}

// 字节转KB、MB、GB
QString formatSize(qint64 bytes) {
	QString strUnit;
	double dSize = bytes * 1.0;
	if (dSize <= 0) {
		dSize = 0.0;
	}
	else if (dSize < 1024) {
		strUnit = "B";
	}
	else if (dSize < 1024 * 1024) {
		dSize /= 1024;
		strUnit = "KB";
	}
	else if (dSize < 1024 * 1024 * 1024) {
		dSize /= (1024 * 1024);
		strUnit = "MB";
	}
	else {
		dSize /= (1024 * 1024 * 1024);
		strUnit = "GB";
	}

	return QString("%1 %2").arg(QString::number(dSize, 'f', 2)).arg(strUnit);
}

// 速度转KB/S、MB/S、GB/S
QString formatSpeed(double speed) {
	QString strUnit;
	if (speed <= 0) {
		speed = 0;
		strUnit = "B/S";
	}
	else if (speed < 1024) {
		strUnit = "B/S";
	}
	else if (speed < 1024 * 1024) {
		speed /= 1024;
		strUnit = "KB/S";
	}
	else if (speed < 1024 * 1024 * 1024) {
		speed /= (1024 * 1024);
		strUnit = "MB/S";
	}
	else {
		speed /= (1024 * 1024 * 1024);
		strUnit = "GB/S";
	}

	QString strSpeed = QString::number(speed, 'f', 2);
	return QString("%1 %2").arg(strSpeed).arg(strUnit);
}