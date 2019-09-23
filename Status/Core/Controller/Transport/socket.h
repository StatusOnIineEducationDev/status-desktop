#pragma once

#include <QTcpSocket>

const QString SERVER_ADDRESS = "127.0.0.1";
const quint16 SERVER_PORT = 5000;

class Request : public QTcpSocket {
	Q_OBJECT
public:

public slots:
	/*��������*/
	void request(const QString &command, const QString &type, const QJsonObject &data);
	/*����fail�ź�*/
	void emitFailSignal(QAbstractSocket::SocketError socketError);

signals:
	void success(const QJsonObject &result);
	void fail(QAbstractSocket::SocketError socketError);
	void complete();

private:
	/*���������������*/
	bool socketConnect();
	/*�ر��������������*/
	bool socketClose();
	/*������Ϣ*/
	bool socketSend(const QJsonObject &info);
	/*������Ϣ*/
	bool socketRecv();
};