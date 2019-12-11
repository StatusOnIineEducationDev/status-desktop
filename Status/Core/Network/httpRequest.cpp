#include "httpRequest.h"


HttpRequest::HttpRequest()
	: manager(nullptr) {
	this->manager = new QNetworkAccessManager;

	this->connect(this->manager, &QNetworkAccessManager::finished, 
		this, &HttpRequest::finished);
}

HttpRequest::~HttpRequest() {

}

void HttpRequest::request(QUrl &url, QJsonObject &json_data) {
	QNetworkRequest request_obj(url);
	QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
	QHttpPart json_part;

	// ！！JSON何蛍
	json_part.setHeader(QNetworkRequest::ContentTypeHeader, "multipart/form-data");
	json_part.setHeader(QNetworkRequest::ContentDispositionHeader, "form-data; name=\"json\"");
	json_part.setBody(QJsonDocument(json_data).toJson(QJsonDocument::Compact));
	
	multiPart->append(json_part);
	this->reply = this->manager->post(request_obj, multiPart);
	multiPart->setParent(reply);

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

// ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
// ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！

FileUpload::FileUpload()
	: manager(nullptr) {
	this->manager = new QNetworkAccessManager;

	this->connect(this->manager, &QNetworkAccessManager::finished,
		this, &FileUpload::finished);
}

FileUpload::~FileUpload() {

}

void FileUpload::request(QUrl &url, QJsonObject &json_data, QFile &file_data) {
	QFileInfo file_info(file_data.fileName());
	QNetworkRequest request_obj(url);
	QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
	QHttpPart json_part, file_part;

	// ！！JSON何蛍
	json_part.setHeader(QNetworkRequest::ContentTypeHeader, "multipart/form-data");
	json_part.setHeader(QNetworkRequest::ContentDispositionHeader, "form-data; name=\"json\"");
	json_part.setBody(QJsonDocument(json_data).toJson(QJsonDocument::Compact));

	// ！！猟周何蛍
	file_data.open(QIODevice::ReadOnly);
	file_part.setHeader(QNetworkRequest::ContentTypeHeader, "multipart/form-data");
	file_part.setHeader(QNetworkRequest::ContentDispositionHeader, "form-data; name=\"file\"; filename=\"" + file_info.fileName() + "\"");
	file_part.setBodyDevice(&file_data);

	multiPart->append(json_part);
	multiPart->append(file_part);
	this->reply = this->manager->post(request_obj, multiPart);
	multiPart->setParent(reply);

	return;
}

void FileUpload::finished(QNetworkReply *reply) {
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

// ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
// ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！

FileDownload::FileDownload()
	: manager(nullptr) {
	this->manager = new QNetworkAccessManager;

	this->connect(this->manager, &QNetworkAccessManager::finished,
		this, &FileDownload::finished);
}

FileDownload::~FileDownload() {

}

void FileDownload::request(QUrl &url, QJsonObject &json_data, QString &filename) {
	this->m_filename = filename;

	QNetworkRequest request_obj(url);
	QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
	QHttpPart json_part;

	// ！！JSON何蛍
	json_part.setHeader(QNetworkRequest::ContentTypeHeader, "multipart/form-data");
	json_part.setHeader(QNetworkRequest::ContentDispositionHeader, "form-data; name=\"json\"");
	json_part.setBody(QJsonDocument(json_data).toJson(QJsonDocument::Compact));

	multiPart->append(json_part);
	this->reply = this->manager->post(request_obj, multiPart);
	multiPart->setParent(reply);

	return;
}

void FileDownload::finished(QNetworkReply *reply) {
	QNetworkReply::NetworkError error = reply->error();
	QByteArray data_byte_arr = reply->readAll();
		
	switch (error) {
	case QNetworkReply::NetworkError::NoError:
		emit this->success(data_byte_arr, this->m_filename);
		break;
	default:
		emit this->fail(error);
	}

	emit this->complete();
	reply->deleteLater();
	this->manager->deleteLater();

	return;
}