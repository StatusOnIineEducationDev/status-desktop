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
#include <QtWidgets/QPushButton>
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
    QSpacerItem *horizontalSpacer;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout;
    QLabel *name_text;
    QLabel *label_5;
    QPushButton *all_btn;
    QSpacerItem *horizontalSpacer_2;
    QFrame *concentration_area_chart;
    QGridLayout *gridLayout_11;
    QLabel *label_14;
    QtCharts::QChartView *concentration_area_chart_widget;
    QLabel *label_13;
    QLabel *label_12;
    QFrame *text_info_frame;
    QGridLayout *gridLayout_4;
    QFrame *conc_frame;
    QGridLayout *gridLayout_13;
    QLabel *concentration_value_text;
    QLabel *label_16;
    QFrame *time_frame;
    QGridLayout *gridLayout_3;
    QLabel *time_text;
    QLabel *label_17;
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
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setStyleSheet(QString::fromUtf8("border: none;"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        name_text = new QLabel(frame_3);
        name_text->setObjectName(QString::fromUtf8("name_text"));
        name_text->setMinimumSize(QSize(0, 40));
        name_text->setMaximumSize(QSize(16777215, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        name_text->setFont(font);
        name_text->setStyleSheet(QString::fromUtf8("color: #333333;\n"
"border: none;"));
        name_text->setScaledContents(true);

        horizontalLayout->addWidget(name_text);

        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(0, 40));
        label_5->setMaximumSize(QSize(16777215, 40));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: #333333;\n"
"border: none;"));
        label_5->setScaledContents(true);

        horizontalLayout->addWidget(label_5);


        gridLayout_2->addWidget(frame_3, 0, 0, 1, 1);

        all_btn = new QPushButton(frame_2);
        all_btn->setObjectName(QString::fromUtf8("all_btn"));
        all_btn->setMinimumSize(QSize(100, 30));
        all_btn->setMaximumSize(QSize(100, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        all_btn->setFont(font1);
        all_btn->setCursor(QCursor(Qt::PointingHandCursor));
        all_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 15px;\n"
"	border: 1px solid #1296db;\n"
"	color: #1296db;\n"
"	background: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E6E6E6;\n"
"}"));

        gridLayout_2->addWidget(all_btn, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 3, 1, 1);

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
        sizePolicy.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy);
        label_14->setMinimumSize(QSize(0, 0));
        label_14->setMaximumSize(QSize(16777215, 16777215));
        label_14->setFont(font1);
        label_14->setStyleSheet(QString::fromUtf8("color: #999999;\n"
"background: none;"));
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(label_14, 2, 0, 1, 3);

        concentration_area_chart_widget = new QtCharts::QChartView(concentration_area_chart);
        concentration_area_chart_widget->setObjectName(QString::fromUtf8("concentration_area_chart_widget"));
        concentration_area_chart_widget->setMinimumSize(QSize(0, 0));
        concentration_area_chart_widget->setMaximumSize(QSize(16777215, 16777215));
        concentration_area_chart_widget->setStyleSheet(QString::fromUtf8("border: 1px solid #1296db;"));

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


        gridLayout_2->addWidget(concentration_area_chart, 1, 0, 1, 4);

        text_info_frame = new QFrame(frame_2);
        text_info_frame->setObjectName(QString::fromUtf8("text_info_frame"));
        sizePolicy.setHeightForWidth(text_info_frame->sizePolicy().hasHeightForWidth());
        text_info_frame->setSizePolicy(sizePolicy);
        text_info_frame->setStyleSheet(QString::fromUtf8("border: none;"));
        text_info_frame->setFrameShape(QFrame::StyledPanel);
        text_info_frame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(text_info_frame);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(30, -1, -1, -1);
        conc_frame = new QFrame(text_info_frame);
        conc_frame->setObjectName(QString::fromUtf8("conc_frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(conc_frame->sizePolicy().hasHeightForWidth());
        conc_frame->setSizePolicy(sizePolicy1);
        conc_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: none;\n"
"	border: 2px solid #1296db;\n"
"	border-top: none;\n"
"	border-right: none;\n"
"	border-bottom: none;\n"
"}"));
        conc_frame->setFrameShape(QFrame::StyledPanel);
        conc_frame->setFrameShadow(QFrame::Raised);
        gridLayout_13 = new QGridLayout(conc_frame);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        concentration_value_text = new QLabel(conc_frame);
        concentration_value_text->setObjectName(QString::fromUtf8("concentration_value_text"));
        concentration_value_text->setMinimumSize(QSize(0, 0));
        concentration_value_text->setMaximumSize(QSize(16777215, 16777215));
        concentration_value_text->setFont(font);
        concentration_value_text->setStyleSheet(QString::fromUtf8("color: #333333;\n"
"border: none;"));
        concentration_value_text->setScaledContents(true);
        concentration_value_text->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_13->addWidget(concentration_value_text, 1, 0, 1, 1);

        label_16 = new QLabel(conc_frame);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMinimumSize(QSize(0, 0));
        label_16->setMaximumSize(QSize(16777215, 16777215));
        label_16->setFont(font1);
        label_16->setStyleSheet(QString::fromUtf8("color: #999999;\n"
"border: none;"));

        gridLayout_13->addWidget(label_16, 0, 0, 1, 1);


        gridLayout_4->addWidget(conc_frame, 0, 0, 1, 1);

        time_frame = new QFrame(text_info_frame);
        time_frame->setObjectName(QString::fromUtf8("time_frame"));
        time_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: none;\n"
"	border: 2px dashed #1296db;\n"
"	border-top: none;\n"
"	border-right: none;\n"
"	border-bottom: none;\n"
"}"));
        time_frame->setFrameShape(QFrame::StyledPanel);
        time_frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(time_frame);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        time_text = new QLabel(time_frame);
        time_text->setObjectName(QString::fromUtf8("time_text"));
        time_text->setMinimumSize(QSize(0, 0));
        time_text->setMaximumSize(QSize(16777215, 16777215));
        time_text->setFont(font);
        time_text->setStyleSheet(QString::fromUtf8("color: #333333;\n"
"border: none;"));
        time_text->setScaledContents(true);
        time_text->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(time_text, 1, 0, 1, 1);

        label_17 = new QLabel(time_frame);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMinimumSize(QSize(0, 0));
        label_17->setMaximumSize(QSize(16777215, 16777215));
        label_17->setFont(font1);
        label_17->setStyleSheet(QString::fromUtf8("color: #999999;\n"
"border: none;"));

        gridLayout_3->addWidget(label_17, 0, 0, 1, 1);


        gridLayout_4->addWidget(time_frame, 0, 1, 1, 1);


        gridLayout_2->addWidget(text_info_frame, 2, 0, 1, 4);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer, 3, 0, 1, 4);


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
        name_text->setText(QCoreApplication::translate("TeacherLessonAnalysisWidget", "-", nullptr));
        label_5->setText(QCoreApplication::translate("TeacherLessonAnalysisWidget", "\347\232\204\350\257\276\345\240\202\347\212\266\346\200\201\345\210\206\346\236\220", nullptr));
        all_btn->setText(QCoreApplication::translate("TeacherLessonAnalysisWidget", "\346\237\245\347\234\213\345\205\250\347\217\255", nullptr));
        label_14->setText(QCoreApplication::translate("TeacherLessonAnalysisWidget", "\347\216\260\345\234\250", nullptr));
        label_13->setText(QCoreApplication::translate("TeacherLessonAnalysisWidget", "0", nullptr));
        label_12->setText(QCoreApplication::translate("TeacherLessonAnalysisWidget", "100", nullptr));
        concentration_value_text->setText(QCoreApplication::translate("TeacherLessonAnalysisWidget", "-", nullptr));
        label_16->setText(QCoreApplication::translate("TeacherLessonAnalysisWidget", "\345\256\236\346\227\266\344\270\223\346\263\250\345\272\246", nullptr));
        time_text->setText(QCoreApplication::translate("TeacherLessonAnalysisWidget", "-", nullptr));
        label_17->setText(QCoreApplication::translate("TeacherLessonAnalysisWidget", "\346\233\264\346\226\260\346\227\266\351\227\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeacherLessonAnalysisWidget: public Ui_TeacherLessonAnalysisWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_T_LESSONANALYSISWIDGET_H
