#include <QJsonDocument>
#include <QDataStream>
#include <QJsonObject>

#include "socket.h"


Connection::Connection(QObject *parent)
	: QObject(parent), m_total_bytes(-1){
	this->QObject::connect(this, &Connection::readySend, this, &Connection::realSend);
}

Connection::~Connection() {
	this->disconnect();
}

void Connection::connect(const QString &host_name, quint16 port) {
	this->m_socket.connectToHost(host_name, port);
	this->QObject::connect(&this->m_socket, &QTcpSocket::readyRead, this, &Connection::recvToBuffer);

	return;
}

void Connection::disconnect() {
	this->m_socket.disconnectFromHost();

	return;
}

void Connection::send(QJsonObject &data) {
	qRegisterMetaType<QJsonObject>("QJsonObject&");  // 这句要加
	emit this->readySend(data);

	return;
}

void Connection::realSend(QJsonObject &data) {
	/*
		这里定义的包结构为：
		———————————————
		|| data长度 4Bytes || data  ||
		———————————————
		但实际上将json_byte_arr放进去后，数据包就变成了（暂时不了解是为什么）
		—————————————————————————
		|| data长度 4Bytes || data长度 4Bytes ||  data  ||
		—————————————————————————
	*/
	int total_bytes = 0;
	QByteArray push_byte_arr;  // 最终发送的数据
	QDataStream output(&push_byte_arr, QIODevice::WriteOnly);
	QByteArray json_byte_arr = QJsonDocument(data).toJson(QJsonDocument::Compact);

	total_bytes = json_byte_arr.size();
	output << total_bytes << json_byte_arr;

	this->m_socket.write(push_byte_arr);

	return;
}

QJsonObject Connection::recv() {
	return this->m_json_buffer.takeFirst();
}

void Connection::recvToBuffer() {
	QByteArray recv_byte_arr, json_byte_arr, length_byte_arr;
	QJsonObject *recv_json_obj;

	// ——读入到自定义的bytes缓冲区
	recv_byte_arr = m_socket.readAll();
	this->m_bytes_buffer.append(recv_byte_arr);

	// ——解析
	do {
		if (this->m_bytes_buffer.size() >= 4 && this->m_total_bytes == -1) {
			// ——先把头4个byte读出来，属header
			for (int index = 0; index < 4; index++) {
				length_byte_arr.append(this->m_bytes_buffer[index]);
			}
			this->m_bytes_buffer = this->m_bytes_buffer.remove(0, 4);
			// ——这里的四个字节为16进制
			//     然而，以下方式都是不行的： 
			//     (×)  length_byte_arr.toInt()
			//     (×)  length_byte_arr.toHex()
			//     (×)  length_byte_arr.toHex().toInt()
			this->m_total_bytes = QString(length_byte_arr.toHex()).toInt(nullptr, 16);
			length_byte_arr.clear();
		}

		// ——读data段
		if (this->m_bytes_buffer.size() >= this->m_total_bytes && this->m_total_bytes != -1) {
			for (int index = 0; index < this->m_total_bytes; index++) {
				json_byte_arr.append(this->m_bytes_buffer[index]);
			}
			this->m_bytes_buffer = this->m_bytes_buffer.remove(0, this->m_total_bytes);

			this->m_total_bytes = -1;
			recv_json_obj = new QJsonObject(QJsonDocument::fromJson(json_byte_arr).object());
			json_byte_arr.clear();
			this->m_json_buffer.append(*recv_json_obj);
			emit this->bufferReadyRead();
		}
	} while (this->m_bytes_buffer.size() >= 4 && this->m_total_bytes == -1);

	return;
}


