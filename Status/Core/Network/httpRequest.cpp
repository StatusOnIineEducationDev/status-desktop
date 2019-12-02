#include "httpRequest.h"


HttpRequest::HttpRequest()
	: manager(nullptr) {
	this->manager = new QNetworkAccessManager;

	this->connect(this->manager, &QNetworkAccessManager::finished, 
		this, &HttpRequest::finished);
}

HttpRequest::~HttpRequest() {

}

void HttpRequest::request(QUrl &url, QJsonObject &data) {
	QNetworkRequest request_obj(url);
	QByteArray data_byte_arr = QJsonDocument(data).toJson(QJsonDocument::Compact);

	request_obj.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
	this->reply = this->manager->post(request_obj, data_byte_arr);

	return;
}

void HttpRequest::finished(QNetworkReply *reply) {
	QNetworkReply::NetworkError error = reply->error();
	QByteArray data_byte_arr = reply->readAll();
	QJsonDocument data_json_doc = QJsonDocument::fromJson(data_byte_arr);

	switch (error) {
	case QNetworkReply::NetworkError::NoError:
		emit this->success(data_json_doc.object());
		break;
	default:
		emit this->fail(error);
	}

	emit this->complete();
	reply->deleteLater();
	this->manager->deleteLater();

	return;
}