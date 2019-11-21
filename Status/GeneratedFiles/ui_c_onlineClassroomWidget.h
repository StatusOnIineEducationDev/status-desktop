/********************************************************************************
** Form generated from reading UI file 'c_onlineClassroomWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_ONLINECLASSROOMWIDGET_H
#define UI_C_ONLINECLASSROOMWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "qchartview.h"

QT_BEGIN_NAMESPACE

class Ui_OnlineClassroomWidget
{
public:
    QGridLayout *gridLayout;
    QPushButton *begin_lesson_btn;
    QFrame *function_btn_frame;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_35;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *raise_hand_btn;
    QPushButton *quit_lesson_btn;
    QFrame *frame;
    QGridLayout *gridLayout_7;
    QFrame *camera_frame;
    QGridLayout *gridLayout_18;
    QGridLayout *camera_widget_layout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_8;
    QLabel *begin_time_text;
    QLabel *label_13;
    QLabel *label_19;
    QLabel *lesson_id_text;
    QLabel *create_time_text;
    QLabel *concentration_text;
    QLabel *label_17;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_12;
    QLabel *label_18;
    QWidget *widget_content;
    QtCharts::QChartView *concentration_area_chart_min_widget;
    QLabel *label_32;
    QLabel *label_4;
    QLabel *label_15;
    QLabel *label_31;
    QLabel *teacher_name_text;
    QLabel *label_14;
    QLabel *label_11;
    QLabel *last_time_text;
    QLabel *room_name_text;
    QSpacerItem *verticalSpacer_5;
    QTabWidget *function_tabWidget;

    void setupUi(QWidget *OnlineClassroomWidget)
    {
        if (OnlineClassroomWidget->objectName().isEmpty())
            OnlineClassroomWidget->setObjectName(QString::fromUtf8("OnlineClassroomWidget"));
        OnlineClassroomWidget->resize(825, 625);
        OnlineClassroomWidget->setStyleSheet(QString::fromUtf8("QWidget#OnlineClassroomWidget {\n"
"	background: #ffffff;\n"
"}"));
        gridLayout = new QGridLayout(OnlineClassroomWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        begin_lesson_btn = new QPushButton(OnlineClassroomWidget);
        begin_lesson_btn->setObjectName(QString::fromUtf8("begin_lesson_btn"));
        begin_lesson_btn->setMinimumSize(QSize(200, 30));
        begin_lesson_btn->setMaximumSize(QSize(200, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        begin_lesson_btn->setFont(font);
        begin_lesson_btn->setCursor(QCursor(Qt::PointingHandCursor));
        begin_lesson_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #ffffff;\n"
"	border: none;\n"
"	border-left: 1px solid #E8ECEC;\n"
"	background-color: #1296db;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #0E71A4;\n"
"}"));
        begin_lesson_btn->setCheckable(false);

        gridLayout->addWidget(begin_lesson_btn, 1, 1, 1, 1);

        function_btn_frame = new QFrame(OnlineClassroomWidget);
        function_btn_frame->setObjectName(QString::fromUtf8("function_btn_frame"));
        function_btn_frame->setMinimumSize(QSize(0, 30));
        function_btn_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: #f0f0f0;\n"
"	border: none;\n"
"	border-bottom: 1px solid #E8ECEC;\n"
"}"));
        function_btn_frame->setFrameShape(QFrame::StyledPanel);
        function_btn_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(function_btn_frame);
        horizontalLayout_4->setSpacing(20);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(10, 0, 10, 0);
        label_35 = new QLabel(function_btn_frame);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        label_35->setFont(font1);
        label_35->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	color: #666666;\n"
"	background: none;\n"
"	border: none;\n"
"}"));

        horizontalLayout_4->addWidget(label_35);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_11);

        raise_hand_btn = new QPushButton(function_btn_frame);
        raise_hand_btn->setObjectName(QString::fromUtf8("raise_hand_btn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(raise_hand_btn->sizePolicy().hasHeightForWidth());
        raise_hand_btn->setSizePolicy(sizePolicy);
        raise_hand_btn->setMinimumSize(QSize(0, 25));
        raise_hand_btn->setMaximumSize(QSize(16777215, 25));
        raise_hand_btn->setFont(font1);
        raise_hand_btn->setCursor(QCursor(Qt::PointingHandCursor));
        raise_hand_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #666666;\n"
"	background: none;\n"
"	border: none;\n"
"	border-radius: 5px;\n"
"	padding-left: 5px;\n"
"	padding-right: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #dedede;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/button/Resources/material/button/raise_hand.png"), QSize(), QIcon::Normal, QIcon::Off);
        raise_hand_btn->setIcon(icon);
        raise_hand_btn->setIconSize(QSize(15, 15));

        horizontalLayout_4->addWidget(raise_hand_btn);

        quit_lesson_btn = new QPushButton(function_btn_frame);
        quit_lesson_btn->setObjectName(QString::fromUtf8("quit_lesson_btn"));
        sizePolicy.setHeightForWidth(quit_lesson_btn->sizePolicy().hasHeightForWidth());
        quit_lesson_btn->setSizePolicy(sizePolicy);
        quit_lesson_btn->setMinimumSize(QSize(0, 25));
        quit_lesson_btn->setMaximumSize(QSize(16777215, 25));
        quit_lesson_btn->setFont(font1);
        quit_lesson_btn->setCursor(QCursor(Qt::PointingHandCursor));
        quit_lesson_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #666666;\n"
"	background: none;\n"
"	border: none;\n"
"	border-radius: 5px;\n"
"	padding-left: 5px;\n"
"	padding-right: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #dedede;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/button/Resources/material/button/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        quit_lesson_btn->setIcon(icon1);
        quit_lesson_btn->setIconSize(QSize(15, 15));

        horizontalLayout_4->addWidget(quit_lesson_btn);


        gridLayout->addWidget(function_btn_frame, 0, 0, 1, 2);

        frame = new QFrame(OnlineClassroomWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(200, 325));
        frame->setMaximumSize(QSize(200, 16777215));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border-left: 1px solid #E8ECEC;\n"
"	background-color: #ffffff;\n"
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
"    width: 5px;\n"
"}\n"
"\n"
"QScrollBar:vertical:hover {\n"
"    border: none;\n"
"    background-color: rgb(220, 220, 220);\n"
"    width: 5px;\n"
"}\n"
"\n"
"\n"
"/*\346\273\232\345\212\250\346\235\241*/\n"
"QScrollBar::handle:vertical {\n"
"	border-radius: 2px;\n"
"    background: rgb(220, 220, 220);\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"/*\346\273\232\345\212\250\346\235\241\357\274\232\346\202\254\346\265\256*/\n"
"QScrollBar::handle:vertical:hover {\n"
"	border-radius: 2px;\n"
"    background: rgb(200, 200, 200);\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"/*\344\270\213\347\256\255\345\244\264*/\n"
"QScrollBar::add-line:vertical {\n"
"    height: 0;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol"
                        "-origin: margin;\n"
"}\n"
"\n"
"/*\344\270\212\347\256\255\345\244\264*/\n"
"QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame);
        gridLayout_7->setSpacing(0);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        camera_frame = new QFrame(frame);
        camera_frame->setObjectName(QString::fromUtf8("camera_frame"));
        camera_frame->setMinimumSize(QSize(200, 130));
        camera_frame->setMaximumSize(QSize(130, 16777215));
        camera_frame->setFrameShape(QFrame::StyledPanel);
        camera_frame->setFrameShadow(QFrame::Raised);
        gridLayout_18 = new QGridLayout(camera_frame);
        gridLayout_18->setSpacing(0);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        gridLayout_18->setContentsMargins(0, 0, 0, 0);
        camera_widget_layout = new QGridLayout();
        camera_widget_layout->setObjectName(QString::fromUtf8("camera_widget_layout"));

        gridLayout_18->addLayout(camera_widget_layout, 0, 0, 1, 1);


        gridLayout_7->addWidget(camera_frame, 2, 5, 1, 1);

        scrollArea = new QScrollArea(frame);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMinimumSize(QSize(200, 0));
        scrollArea->setMaximumSize(QSize(200, 16777215));
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 198, 433));
        scrollAreaWidgetContents->setMinimumSize(QSize(198, 0));
        scrollAreaWidgetContents->setMaximumSize(QSize(198, 16777215));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	border: none;\n"
"	background-color: #ffffff;\n"
"}"));
        gridLayout_8 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(9, 9, -1, -1);
        begin_time_text = new QLabel(scrollAreaWidgetContents);
        begin_time_text->setObjectName(QString::fromUtf8("begin_time_text"));
        begin_time_text->setFont(font1);
        begin_time_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));

        gridLayout_8->addWidget(begin_time_text, 6, 2, 1, 6);

        label_13 = new QLabel(scrollAreaWidgetContents);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font1);
        label_13->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));
        label_13->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_13, 10, 5, 1, 2);

        label_19 = new QLabel(scrollAreaWidgetContents);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font1);
        label_19->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));
        label_19->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_19, 4, 0, 1, 2);

        lesson_id_text = new QLabel(scrollAreaWidgetContents);
        lesson_id_text->setObjectName(QString::fromUtf8("lesson_id_text"));
        lesson_id_text->setFont(font1);
        lesson_id_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));

        gridLayout_8->addWidget(lesson_id_text, 1, 2, 1, 6);

        create_time_text = new QLabel(scrollAreaWidgetContents);
        create_time_text->setObjectName(QString::fromUtf8("create_time_text"));
        create_time_text->setFont(font1);
        create_time_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));

        gridLayout_8->addWidget(create_time_text, 4, 2, 1, 6);

        concentration_text = new QLabel(scrollAreaWidgetContents);
        concentration_text->setObjectName(QString::fromUtf8("concentration_text"));
        concentration_text->setFont(font1);
        concentration_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));
        concentration_text->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_8->addWidget(concentration_text, 11, 2, 1, 6);

        label_17 = new QLabel(scrollAreaWidgetContents);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(12);
        label_17->setFont(font2);
        label_17->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #666666;\n"
"}"));

        gridLayout_8->addWidget(label_17, 8, 0, 1, 8);

        verticalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_8->addItem(verticalSpacer_6, 7, 0, 1, 8);

        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font1);
        label_12->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_12, 10, 2, 1, 2);

        label_18 = new QLabel(scrollAreaWidgetContents);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font1);
        label_18->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));
        label_18->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_18, 1, 0, 1, 2);

        widget_content = new QWidget(scrollAreaWidgetContents);
        widget_content->setObjectName(QString::fromUtf8("widget_content"));
        widget_content->setMinimumSize(QSize(0, 80));
        widget_content->setMaximumSize(QSize(16777215, 120));
        widget_content->setStyleSheet(QString::fromUtf8(""));
        concentration_area_chart_min_widget = new QtCharts::QChartView(widget_content);
        concentration_area_chart_min_widget->setObjectName(QString::fromUtf8("concentration_area_chart_min_widget"));
        concentration_area_chart_min_widget->setGeometry(QRect(18, 0, 141, 80));
        concentration_area_chart_min_widget->setStyleSheet(QString::fromUtf8("border: 1px solid #1296db;"));

        gridLayout_8->addWidget(widget_content, 12, 0, 1, 8);

        label_32 = new QLabel(scrollAreaWidgetContents);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setFont(font1);
        label_32->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));
        label_32->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_32, 2, 0, 1, 2);

        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));

        gridLayout_8->addWidget(label_4, 9, 0, 1, 2);

        label_15 = new QLabel(scrollAreaWidgetContents);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font1);
        label_15->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));

        gridLayout_8->addWidget(label_15, 11, 0, 1, 2);

        label_31 = new QLabel(scrollAreaWidgetContents);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setFont(font1);
        label_31->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));
        label_31->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_31, 6, 0, 1, 2);

        teacher_name_text = new QLabel(scrollAreaWidgetContents);
        teacher_name_text->setObjectName(QString::fromUtf8("teacher_name_text"));
        teacher_name_text->setFont(font1);
        teacher_name_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));

        gridLayout_8->addWidget(teacher_name_text, 2, 2, 1, 6);

        label_14 = new QLabel(scrollAreaWidgetContents);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font1);
        label_14->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_14, 10, 4, 1, 1);

        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));

        gridLayout_8->addWidget(label_11, 10, 0, 1, 2);

        last_time_text = new QLabel(scrollAreaWidgetContents);
        last_time_text->setObjectName(QString::fromUtf8("last_time_text"));
        last_time_text->setFont(font1);
        last_time_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));
        last_time_text->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_8->addWidget(last_time_text, 9, 2, 1, 6);

        room_name_text = new QLabel(scrollAreaWidgetContents);
        room_name_text->setObjectName(QString::fromUtf8("room_name_text"));
        room_name_text->setFont(font2);
        room_name_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #666666;\n"
"}"));

        gridLayout_8->addWidget(room_name_text, 0, 0, 1, 8);

        verticalSpacer_5 = new QSpacerItem(171, 548, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(verticalSpacer_5, 14, 0, 1, 8);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_7->addWidget(scrollArea, 1, 5, 1, 1);


        gridLayout->addWidget(frame, 2, 1, 1, 1);

        function_tabWidget = new QTabWidget(OnlineClassroomWidget);
        function_tabWidget->setObjectName(QString::fromUtf8("function_tabWidget"));
        function_tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab {\n"
"	padding-top: 0px;\n"
"	color: #999999;\n"
"	border: none;\n"
"	height: 30px;\n"
"	width: 70px;\n"
"	background: none;\n"
"}\n"
"\n"
"QTabWidget {\n"
"	background: #ffffff;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"	background-color: #E6E6E6;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"	color: #1296db;\n"
"}\n"
"\n"
"QTabWidget#function_tabWidget::pane {\n"
"	border-top: 1px solid #E8ECEC;\n"
"}\n"
"\n"
"QTabWidget#function_tabWidget::tab-bar {\n"
"	alignment:left;\n"
"}"));

        gridLayout->addWidget(function_tabWidget, 1, 0, 2, 1);


        retranslateUi(OnlineClassroomWidget);

        function_tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(OnlineClassroomWidget);
    } // setupUi

    void retranslateUi(QWidget *OnlineClassroomWidget)
    {
        OnlineClassroomWidget->setWindowTitle(QCoreApplication::translate("OnlineClassroomWidget", "Form", nullptr));
        begin_lesson_btn->setText(QCoreApplication::translate("OnlineClassroomWidget", "Variable Button", nullptr));
        label_35->setText(QCoreApplication::translate("OnlineClassroomWidget", "\345\234\250\347\272\277\346\225\231\345\256\244", nullptr));
        raise_hand_btn->setText(QCoreApplication::translate("OnlineClassroomWidget", "\344\270\276\346\211\213", nullptr));
        quit_lesson_btn->setText(QCoreApplication::translate("OnlineClassroomWidget", "\351\200\200\345\207\272", nullptr));
        begin_time_text->setText(QCoreApplication::translate("OnlineClassroomWidget", "-", nullptr));
        label_13->setText(QCoreApplication::translate("OnlineClassroomWidget", "-", nullptr));
        label_19->setText(QCoreApplication::translate("OnlineClassroomWidget", "    \345\210\233\345\273\272\346\227\266\351\227\264\357\274\232", nullptr));
        lesson_id_text->setText(QCoreApplication::translate("OnlineClassroomWidget", "-", nullptr));
        create_time_text->setText(QCoreApplication::translate("OnlineClassroomWidget", "-", nullptr));
        concentration_text->setText(QCoreApplication::translate("OnlineClassroomWidget", "-", nullptr));
        label_17->setText(QCoreApplication::translate("OnlineClassroomWidget", "\342\227\217 \350\257\276\345\240\202\346\246\202\345\206\265", nullptr));
        label_12->setText(QCoreApplication::translate("OnlineClassroomWidget", "-", nullptr));
        label_18->setText(QCoreApplication::translate("OnlineClassroomWidget", "    \350\257\276\345\240\202\345\217\267\357\274\232", nullptr));
        label_32->setText(QCoreApplication::translate("OnlineClassroomWidget", "    \345\275\223\345\211\215\346\225\231\345\270\210\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("OnlineClassroomWidget", "    \345\267\262\350\277\233\350\241\214\357\274\232", nullptr));
        label_15->setText(QCoreApplication::translate("OnlineClassroomWidget", "    \344\270\223\346\263\250\345\272\246\357\274\232", nullptr));
        label_31->setText(QCoreApplication::translate("OnlineClassroomWidget", "    \345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", nullptr));
        teacher_name_text->setText(QCoreApplication::translate("OnlineClassroomWidget", "-", nullptr));
        label_14->setText(QCoreApplication::translate("OnlineClassroomWidget", "/", nullptr));
        label_11->setText(QCoreApplication::translate("OnlineClassroomWidget", "    \345\210\260\350\257\276\344\272\272\346\225\260\357\274\232", nullptr));
        last_time_text->setText(QCoreApplication::translate("OnlineClassroomWidget", "00:00:00", nullptr));
        room_name_text->setText(QCoreApplication::translate("OnlineClassroomWidget", "-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OnlineClassroomWidget: public Ui_OnlineClassroomWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_ONLINECLASSROOMWIDGET_H
