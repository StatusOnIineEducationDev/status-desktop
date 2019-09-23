/********************************************************************************
** Form generated from reading UI file 'Status.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATUS_H
#define UI_STATUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatusClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *StatusClass)
    {
        if (StatusClass->objectName().isEmpty())
            StatusClass->setObjectName(QString::fromUtf8("StatusClass"));
        StatusClass->resize(600, 400);
        menuBar = new QMenuBar(StatusClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        StatusClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(StatusClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        StatusClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(StatusClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        StatusClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(StatusClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        StatusClass->setStatusBar(statusBar);

        retranslateUi(StatusClass);

        QMetaObject::connectSlotsByName(StatusClass);
    } // setupUi

    void retranslateUi(QMainWindow *StatusClass)
    {
        StatusClass->setWindowTitle(QCoreApplication::translate("StatusClass", "Status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StatusClass: public Ui_StatusClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATUS_H
