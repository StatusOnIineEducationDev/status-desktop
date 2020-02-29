/********************************************************************************
** Form generated from reading UI file 't_lessonAnalysisWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_T_LESSONANALYSISWIDGET_H
#define UI_T_LESSONANALYSISWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "qchartview.h"

QT_BEGIN_NAMESPACE

class Ui_TeacherLessonAnalysisWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer;
    QFrame *concentration_area_chart;
    QGridLayout *gridLayout_11;
    QLabel *label_14;
    QtCharts::QChartView *concentration_area_chart_widget;
    QLabel *label_13;
    QLabel *label_12;
    QSpacerItem *verticalSpacer;
    QGridLayout *member_layout;

    void setupUi(QWidget *TeacherLessonAnalysisWidget)
    {
        if (TeacherLessonAnalysisWidget->objectName().isEmpty())
            TeacherLessonAnalysisWidget->setObjectName(QString::fromUtf8("TeacherLessonAnalysisWidget"));
        TeacherLessonAnalysisWidget->resize(615, 565);
        gridLayout = new QGridLayout(TeacherLessonAnalysisWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(TeacherLessonAnalysisWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: #ffffff;\n"
"	border-bottom: 1px solid #E8ECEC;\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setStyleSheet(QString::fromUtf8("border: none;"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_6 = new QLabel(frame_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(0, 40));
        label_6->setMaximumSize(QSize(16777215, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("color: #333333;\n"
"border: none;"));
        label_6->setScaledContents(true);

        horizontalLayout->addWidget(label_6);

        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(0, 40));
        label_5->setMaximumSize(QSize(16777215, 40));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: #333333;\n"
"border: none;"));
        label_5->setScaledContents(true);

        horizontalLayout->addWidget(label_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_2->addWidget(frame_3, 0, 0, 1, 1);

        concentration_area_chart = new QFrame(frame_2);
        concentration_area_chart->setObjectName(QString::fromUtf8("concentration_area_chart"));
        concentration_area_chart->setMinimumSize(QSize(0, 0));
        concentration_area_chart->setStyleSheet(QString::fromUtf8("QFrame#concentration_area_chart {\n"
"	background-color: #ffffff;\n"
"	border: none;\n"
"}"));
        concentration_area_chart->setFrameShape(QFrame::StyledPanel);
        concentration_area_chart->setFrameShadow(QFrame::Raised);
        gridLayout_11 = new QGridLayout(concentration_area_chart);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 9, 20, 9);
        label_14 = new QLabel(concentration_area_chart);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(0, 0));
        label_14->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        label_14->setFont(font1);
        label_14->setStyleSheet(QString::fromUtf8("color: #999999;\n"
"background: none;"));
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(label_14, 2, 0, 1, 3);

        concentration_area_chart_widget = new QtCharts::QChartView(concentration_area_chart);
        concentration_area_chart_widget->setObjectName(QString::fromUtf8("concentration_area_chart_widget"));
        concentration_area_chart_widget->setMinimumSize(QSize(0, 200));
        concentration_area_chart_widget->setMaximumSize(QSize(16777215, 250));
        concentration_area_chart_widget->setStyleSheet(QString::fromUtf8("border: 1px solid #1296db;\n"
"background: none;"));

        gridLayout_11->addWidget(concentration_area_chart_widget, 0, 1, 2, 2);

        label_13 = new QLabel(concentration_area_chart);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMaximumSize(QSize(25, 16777215));
        label_13->setFont(font1);
        label_13->setStyleSheet(QString::fromUtf8("color: #999999;\n"
"background: none;"));
        label_13->setScaledContents(true);
        label_13->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        gridLayout_11->addWidget(label_13, 1, 0, 1, 1);

        label_12 = new QLabel(concentration_area_chart);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMaximumSize(QSize(25, 16777215));
        label_12->setFont(font1);
        label_12->setStyleSheet(QString::fromUtf8("color: #999999;\n"
"background: none;"));
        label_12->setScaledContents(true);
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout_11->addWidget(label_12, 0, 0, 1, 1);


        gridLayout_2->addWidget(concentration_area_chart, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 1, 1);


        gridLayout->addWidget(frame_2, 0, 1, 2, 1);

        member_layout = new QGridLayout();
        member_layout->setObjectName(QString::fromUtf8("member_layout"));

        gridLayout->addLayout(member_layout, 0, 2, 2, 1);


        retranslateUi(TeacherLessonAnalysisWidget);

        QMetaObject::connectSlotsByName(TeacherLessonAnalysisWidget);
    } // setupUi

    void retranslateUi(QWidget *TeacherLessonAnalysisWidget)
    {
        TeacherLessonAnalysisWidget->setWindowTitle(QCoreApplication::translate("TeacherLessonAnalysisWidget", "Form", nullptr));
        label_6->setText(QCoreApplication::translate("TeacherLessonAnalysisWidget", "Name", nullptr));
        label_5->setText(QCoreApplication::translate("TeacherLessonAnalysisWidget", "\347\232\204\350\257\276\345\240\202\347\212\266\346\200\201\345\210\206\346\236\220", nullptr));
        label_14->setText(QCoreApplication::translate("TeacherLessonAnalysisWidget", "\347\216\260\345\234\250", nullptr));
        label_13->setText(QCoreApplication::translate("TeacherLessonAnalysisWidget", "0", nullptr));
        label_12->setText(QCoreApplication::translate("TeacherLessonAnalysisWidget", "100", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeacherLessonAnalysisWidget: public Ui_TeacherLessonAnalysisWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_T_LESSONANALYSISWIDGET_H
