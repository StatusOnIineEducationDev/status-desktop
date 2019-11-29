/********************************************************************************
** Form generated from reading UI file 'c_courseManagementWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_COURSEMANAGEMENTWIDGET_H
#define UI_C_COURSEMANAGEMENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CourseManagementWidget
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *function_btn_widget_layout;
    QTabWidget *function_tabWidget;
    QGridLayout *course_base_widget_layout;

    void setupUi(QWidget *CourseManagementWidget)
    {
        if (CourseManagementWidget->objectName().isEmpty())
            CourseManagementWidget->setObjectName(QString::fromUtf8("CourseManagementWidget"));
        CourseManagementWidget->resize(825, 625);
        CourseManagementWidget->setMinimumSize(QSize(825, 625));
        CourseManagementWidget->setStyleSheet(QString::fromUtf8("QWidget#CourseManagementWidget {\n"
"	background: #fafafa;\n"
"}"));
        gridLayout_2 = new QGridLayout(CourseManagementWidget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        function_btn_widget_layout = new QGridLayout();
        function_btn_widget_layout->setObjectName(QString::fromUtf8("function_btn_widget_layout"));

        gridLayout_2->addLayout(function_btn_widget_layout, 0, 0, 1, 1);

        function_tabWidget = new QTabWidget(CourseManagementWidget);
        function_tabWidget->setObjectName(QString::fromUtf8("function_tabWidget"));
        function_tabWidget->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        function_tabWidget->setFont(font);
        function_tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab {\n"
"	padding-top: 0px;\n"
"	margin-left: 10px;\n"
"	margin-right: 10px;\n"
"	color: #999999;\n"
"	height: 40px;\n"
"	width: 70px;\n"
"	border: none;\n"
"	background: none;\n"
"}\n"
"\n"
"QTabWidget {\n"
"	background: #fafafa;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"	border-bottom: 2px solid #999999;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"	color: #1296db;\n"
"	border-bottom: 2px solid #1296db;\n"
"}\n"
"\n"
"QTabWidget#function_tabWidget::pane {\n"
"	border-top: 1px solid #E8ECEC;\n"
"}\n"
"\n"
"QTabWidget#function_tabWidget::tab-bar {\n"
"	alignment:center;\n"
"}"));

        gridLayout_2->addWidget(function_tabWidget, 2, 0, 1, 1);

        course_base_widget_layout = new QGridLayout();
        course_base_widget_layout->setObjectName(QString::fromUtf8("course_base_widget_layout"));

        gridLayout_2->addLayout(course_base_widget_layout, 1, 0, 1, 1);


        retranslateUi(CourseManagementWidget);

        function_tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(CourseManagementWidget);
    } // setupUi

    void retranslateUi(QWidget *CourseManagementWidget)
    {
        CourseManagementWidget->setWindowTitle(QCoreApplication::translate("CourseManagementWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CourseManagementWidget: public Ui_CourseManagementWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_COURSEMANAGEMENTWIDGET_H
