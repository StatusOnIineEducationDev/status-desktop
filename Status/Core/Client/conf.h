#pragma once
#include <QSettings>
#include <qDebug>

class ReadConf {
public:
	static void read() {
		QSettings *m_conf = new QSettings("Core/Client/conf.ini", QSettings::IniFormat);

		G_HTTP_HOST = m_conf->value("http_server/host").toString();
		G_HTTP_PORT = m_conf->value("http_server/port").toInt();
		G_SOCKET_HOST = m_conf->value("socket_server/host").toString();
		G_SOCKET_PORT = m_conf->value("socket_server/port").toInt();

		delete m_conf;

		return;
	};

	static QString G_HTTP_HOST;
	static quint16 G_HTTP_PORT;
	static QString G_SOCKET_HOST;
	static quint16 G_SOCKET_PORT;
};
