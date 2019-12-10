#pragma once
#include <QThread>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QHttpMultiPart>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QFileInfo>
#include <QDataStream>


class HttpRequest: public QObject {
	Q_OBJECT

public:
	HttpRequest();
	virtual ~HttpRequest();
	void request(QUrl &url, QJsonObject &json_data);
	void request(QUrl &url, QJsonObject &json_data, QFile &file_data);

public slots:
	void finished(QNetworkReply *reply);

signals:
	void success(const QJsonObject &data);
	void fail(QNetworkReply::NetworkError error);
	void complete();

private:
	QNetworkAccessManager *manager;
	QNetworkReply *reply;
};
