#pragma once

#include <QThread>
#include <QImage>
#include <QList>
#include <QHostAddress>

class ImageSend : public QThread {
	Q_OBJECT

public:
	ImageSend(const QHostAddress &host, quint16 port);
	void send(QPixmap &image);
	void run();
	void stop();

protected:
	bool running_flag;
	QList<QPixmap> m_image_list;
	QHostAddress m_host;
	quint16 m_port;

signals:
	void finished();
};