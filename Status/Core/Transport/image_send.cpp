#include <QBuffer>
#include <QUdpSocket>
#include <QPixmap>
#include "Core/Transport/image_send.h"


ImageSend::ImageSend(const QHostAddress &host, quint16 port)
	: m_host(host), m_port(port), running_flag(true){

}

void ImageSend::send(QPixmap &image) {
	this->m_image_list.append(image);

	return;
}

void ImageSend::run() {
	while (running_flag) {
		if (!this->m_image_list.isEmpty()) {
			QByteArray image_byte_arr;
			QBuffer buffer(&image_byte_arr);
			QUdpSocket udp_socket;

			this->m_image_list[0].save(&buffer, "PNG");
			udp_socket.writeDatagram(image_byte_arr, this->m_host, this->m_port);
			this->m_image_list.removeAt(0);
			qDebug() << "send_ok";
			qDebug() << image_byte_arr.length();
			emit finished();
		}
	}
	
	return;
}

void ImageSend::stop() {
	this->running_flag = false;

	return;
}