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