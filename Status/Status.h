#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Status.h"

class Status : public QMainWindow
{
	Q_OBJECT

public:
	Status(QWidget *parent = Q_NULLPTR);

private:
	Ui::StatusClass ui;
};
