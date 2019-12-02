/********************************************************************************
** Form generated from reading UI file 'c_courseOverviewWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_COURSEOVERVIEWWIDGET_H
#define UI_C_COURSEOVERVIEWWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CourseOverviewWidget
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QVBoxLayout *widget_layout;

    void setupUi(QWidget *CourseOverviewWidget)
    {
        if (CourseOverviewWidget->objectName().isEmpty())
            CourseOverviewWidget->setObjectName(QString::fromUtf8("CourseOverviewWidget"));
        CourseOverviewWidget->resize(825, 450);
        CourseOverviewWidget->setStyleSheet(QString::fromUtf8("QWidget#CourseOverviewWidget {\n"
"	background: #fafafa;\n"
"}\n"
"\n"
"QScrollArea#scrollArea {\n"
"	border: none;\n"
"	background-color:transparent;\n"
"}\n"
"\n"
"/*\346\225\264\344\275\223*/\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background-color: #F3F4F8;\n"
"    width: 10px;\n"
"}\n"
"\n"
"QScrollBar:vertical:hover {\n"
"    border: none;\n"
"    background-color: rgb(220, 220, 220);\n"
"    width: 10px;\n"
"}\n"
"\n"
"\n"
"/*\346\273\232\345\212\250\346\235\241*/\n"
"QScrollBar::handle:vertical {\n"
"	border-radius: 5px;\n"
"    background: rgb(220, 220, 220);\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"/*\346\273\232\345\212\250\346\235\241\357\274\232\346\202\254\346\265\256*/\n"
"QScrollBar::handle:vertical:hover {\n"
"	border-radius: 5px;\n"
"    background: rgb(200, 200, 200);\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"/*\344\270\213\347\256\255\345\244\264*/\n"
"QScrollBar::add-line:vertical {\n"
"    height: 0;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
""
                        "}\n"
"\n"
"/*\344\270\212\347\256\255\345\244\264*/\n"
"QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}"));
        gridLayout = new QGridLayout(CourseOverviewWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(CourseOverviewWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMaximumSize(QSize(16777215, 16777215));
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 825, 450));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 0));
        scrollAreaWidgetContents->setMaximumSize(QSize(1200, 16777215));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8("border: none;\n"
"background: #ffffff;"));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget_layout = new QVBoxLayout();
        widget_layout->setObjectName(QString::fromUtf8("widget_layout"));

        gridLayout_2->addLayout(widget_layout, 1, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(CourseOverviewWidget);

        QMetaObject::connectSlotsByName(CourseOverviewWidget);
    } // setupUi

    void retranslateUi(QWidget *CourseOverviewWidget)
    {
        CourseOverviewWidget->setWindowTitle(QCoreApplication::translate("CourseOverviewWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CourseOverviewWidget: public Ui_CourseOverviewWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_COURSEOVERVIEWWIDGET_H
