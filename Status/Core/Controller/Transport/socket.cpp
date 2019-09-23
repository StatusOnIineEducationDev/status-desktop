#include "Core/Controller/Transport/socket.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QAbstractSocket>

/*
	���������������
*/
bool Request::socketConnect() {
	this->connect(this, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this, &Request::emitFailSignal);
	this->connectToHost(SERVER_ADDRESS, SERVER_PORT);  // ��������

	return this->waitForConnected();
}

/*
	�ر��������������
*/
bool Request::socketClose() {
	this->disconnectFromHost();;  // �ر�����

	return this->waitForDisconnected();
}

bool Request::socketSend(const QJsonObject &info) {
	QByteArray packet = QJsonDocument(info).toJson(QJsonDocument::Compact);
	
	this->write(QJsonDocument(info).toJson(QJsonDocument::Compact));  // ������Ϣ
	this->flush();

	return true;
}

bool Request::socketRecv() {
	/*
		packet: ���յ����ݰ�
		QJsonParseError: ���ڼ�������Ƿ�ɹ�
		json_doc: ���յ���json�ĵ�
	*/
	QByteArray packet;
	QJsonParseError json_error;
	QJsonDocument json_doc;

	if (waitForReadyRead()) {
		packet = this->readAll();
	}
	

	json_doc = QJsonDocument::fromJson(packet, &json_error);
	if (!json_doc.isNull() && json_doc.isObject() && json_error.error == QJsonParseError::NoError) {
		emit this->success(json_doc.object());  // ���˰������ȥ
		return true;
	}
	else {
		return false;
	}
}

void Request::request(const QString &command, const QString &type, const QJsonObject &data) {
	/*
		request_json_obj: ���͵�json����key����"command"��"type"��"data"
	*/
	QJsonObject request_json_obj;

	// �����ӣ�����ʧ����ֱ���˳�
	if (!this->socketConnect()) { 
		return;
	}

	request_json_obj["command"] = command;
	request_json_obj["type"] = type;
	request_json_obj["data"] = data;

	this->socketSend(request_json_obj);
	this->socketRecv();

	this->socketClose();

	return;
}

void Request::emitFailSignal(QAbstractSocket::SocketError socketError) {
	// ����һ��request������ֻ����һ��fail�ź�
	emit this->fail(socketError);
	this->disconnect(this, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this, &Request::emitFailSignal);

	return;
}