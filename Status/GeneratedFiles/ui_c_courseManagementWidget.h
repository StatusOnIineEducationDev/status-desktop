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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CourseManagementWidget
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *course_base_widget_layout;
    QGridLayout *gridLayout_5;
    QGridLayout *function_btn_widget_layout;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *CourseManagementWidget)
    {
        if (CourseManagementWidget->objectName().isEmpty())
            CourseManagementWidget->setObjectName(QString::fromUtf8("CourseManagementWidget"));
        CourseManagementWidget->resize(825, 625);
        CourseManagementWidget->setMinimumSize(QSize(825, 625));
        CourseManagementWidget->setStyleSheet(QString::fromUtf8("QWidget#CourseManagementmWidget {\n"
"	background: #ffffff;\n"
"}"));
        gridLayout_2 = new QGridLayout(CourseManagementWidget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        course_base_widget_layout = new QGridLayout();
        course_base_widget_layout->setObjectName(QString::fromUtf8("course_base_widget_layout"));

        gridLayout_2->addLayout(course_base_widget_layout, 1, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));

        gridLayout_2->addLayout(gridLayout_5, 2, 0, 1, 1);

        function_btn_widget_layout = new QGridLayout();
        function_btn_widget_layout->setObjectName(QString::fromUtf8("function_btn_widget_layout"));

        gridLayout_2->addLayout(function_btn_widget_layout, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 3, 0, 1, 1);


        retranslateUi(CourseManagementWidget);

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
