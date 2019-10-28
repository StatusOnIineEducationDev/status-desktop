#pragma once

#include <QTcpSocket>
#include <QUdpSocket>
#include <QObject>
#include <QByteArray>
#include <QTimer>

class Connection : public QObject{
	Q_OBJECT

public:
	Connection();
	~Connection();
	void connect(const QString &host_name, quint16 port);
	void disconnect();
	void send(QJsonObject &data);
	QJsonObject recv();

public slots:
	void recvToBuffer();
	void realSend(QJsonObject &data);

signals:
	void bufferReadyRead();
	void readySend(QJsonObject &data);

protected:
	int m_total_bytes;
	QTcpSocket m_socket;
	QByteArray m_bytes_buffer;
	QList<QJsonObject> m_json_buffer;
};