#pragma once
#include <QWidget>
#include <QDateTime>
#include "ui_c_fileItemWidget.h"


class FileItemWidget : public QWidget {
	Q_OBJECT

public:
	FileItemWidget(const QString &filename, const int &upload_timetsamp, 
		const QString &uploader, const int &file_size, QWidget *parent = nullptr);
	virtual ~FileItemWidget();
	const Ui::FileItemWidget& ui() const { return this->m_ui; };

private:
	Ui::FileItemWidget m_ui;
};
