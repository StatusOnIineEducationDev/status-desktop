#pragma once

#include <QTcpSocket>

const QString SERVER_ADDRESS = "127.0.0.1";
const quint16 SERVER_PORT = 5000;

class Request : public QTcpSocket {
	Q_OBJECT
public:

public slots:
	/*发起请求*/
	void request(const QString &command, const QString &type, const QJsonObject &data);
	/*发射fail信号*/
	void emitFailSignal(QAbstractSocket::SocketError socketError);

signals:
	void success(const QJsonObject &result);
	void fail(QAbstractSocket::SocketError socketError);
	void complete();

private:
	/*与服务器建立连接*/
	bool socketConnect();
	/*关闭与服务器的连接*/
	bool socketClose();
	/*发送信息*/
	bool socketSend(const QJsonObject &info);
	/*接收信息*/
	bool socketRecv();
};