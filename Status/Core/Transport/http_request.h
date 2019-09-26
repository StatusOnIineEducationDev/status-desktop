#pragma once

#include <QThread>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QJsonObject>
#include <QJsonDocument>

class HttpRequest: public QObject {
	Q_OBJECT

public:
	HttpRequest();
	void request(QUrl &url, QJsonObject &data);

public slots:
	void finished(QNetworkReply *reply);

signals:
	void success(const QJsonObject data);
	void fail(QNetworkReply::NetworkError error);
	void complete();

private:
	static QNetworkAccessManager *manager;
	QNetworkReply *reply;
};
