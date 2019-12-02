#pragma once
#include <QThread>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QJsonObject>
#include <QJsonDocument>


class HttpRequest: public QObject {
	Q_OBJECT

public:
	HttpRequest();
	virtual ~HttpRequest();
	void request(QUrl &url, QJsonObject &data);

public slots:
	void finished(QNetworkReply *reply);

signals:
	void success(QJsonObject &data);
	void fail(QNetworkReply::NetworkError error);
	void complete();

private:
	QNetworkAccessManager *manager;
	QNetworkReply *reply;
};
