#include "Core/Controller/Transport/socket.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QAbstractSocket>

/*
	与服务器建立连接
*/
bool Request::socketConnect() {
	this->connect(this, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this, &Request::emitFailSignal);
	this->connectToHost(SERVER_ADDRESS, SERVER_PORT);  // 建立连接

	return this->waitForConnected();
}

/*
	关闭与服务器的连接
*/
bool Request::socketClose() {
	this->disconnectFromHost();;  // 关闭连接

	return this->waitForDisconnected();
}

bool Request::socketSend(const QJsonObject &info) {
	QByteArray packet = QJsonDocument(info).toJson(QJsonDocument::Compact);
	
	this->write(QJsonDocument(info).toJson(QJsonDocument::Compact));  // 发送信息
	this->flush();

	return true;
}

bool Request::socketRecv() {
	/*
		packet: 接收的数据包
		QJsonParseError: 用于检验解析是否成功
		json_doc: 接收到的json文档
	*/
	QByteArray packet;
	QJsonParseError json_error;
	QJsonDocument json_doc;

	if (waitForReadyRead()) {
		packet = this->readAll();
	}
	

	json_doc = QJsonDocument::fromJson(packet, &json_error);
	if (!json_doc.isNull() && json_doc.isObject() && json_error.error == QJsonParseError::NoError) {
		emit this->success(json_doc.object());  // 将此包发射出去
		return true;
	}
	else {
		return false;
	}
}

void Request::request(const QString &command, const QString &type, const QJsonObject &data) {
	/*
		request_json_obj: 发送的json对象，key包含"command"、"type"、"data"
	*/
	QJsonObject request_json_obj;

	// 先连接，连接失败则直接退出
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
	// 对于一次request，至多只发射一次fail信号
	emit this->fail(socketError);
	this->disconnect(this, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this, &Request::emitFailSignal);

	return;
}