/********************************************************************************
** Form generated from reading UI file 'c_courseAnalysisWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_COURSEANALYSISWIDGET_H
#define UI_C_COURSEANALYSISWIDGET_H

#include <QtCore/QVariant>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CourseAnalysisWidget
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QFrame *analysis_frame;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer;
    QFrame *lesson_cmpr_frame;
    QGridLayout *gridLayout_4;
    QLabel *label_3;
    QFrame *frame_9;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QWebEngineView *lesson_cmpr_chartView;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QFrame *rank_frame;
    QGridLayout *gridLayout_5;
    QLabel *label_4;
    QListWidget *rank_listWidget;
    QLabel *label_5;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_2;
    QGridLayout *gridLayout_6;
    QLabel *label_10;
    QWebEngineView *webEngineView;
    QLabel *label_16;
    QLabel *label_11;
    QSpacerItem *horizontalSpacer_5;
    QFrame *frame_3;
    QGridLayout *gridLayout_7;
    QLabel *label_12;
    QWebEngineView *webEngineView_2;
    QLabel *label_17;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_6;
    QFrame *frame_4;
    QGridLayout *gridLayout_8;
    QWebEngineView *webEngineView_3;
    QLabel *label_14;
    QLabel *label_18;
    QLabel *label_15;
    QSpacerItem *verticalSpacer_4;
    QFrame *rank_title_frame;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_3;
    QFrame *course_frame;

    void setupUi(QWidget *CourseAnalysisWidget)
    {
        if (CourseAnalysisWidget->objectName().isEmpty())
            CourseAnalysisWidget->setObjectName(QString::fromUtf8("CourseAnalysisWidget"));
        CourseAnalysisWidget->resize(1275, 863);
        CourseAnalysisWidget->setStyleSheet(QString::fromUtf8("QWidget#Form {\n"
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
"}\n"
"\n"
"/*\344"
                        "\270\212\347\256\255\345\244\264*/\n"
"QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
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
"/*****************************************************/\n"
"\n"
"/*\346\225\264\344\275\223*/\n"
"QScrollBar:horizontal {\n"
"    border: none;\n"
"    background-color: #F3F4F8;\n"
"    height: 10px;\n"
"}\n"
"\n"
"QScrollBar:vertical:horizontal {\n"
"    border: none;\n"
"    background-color: rgb(220, 220, 220);\n"
"    height: 10px;\n"
"}\n"
"\n"
"/*\346\273\232\345\212\250\346\235\241*/\n"
"QScrollBar::handle:horizontal {\n"
"	border-radius: 5px;\n"
"    background: rgb(220, 220, 220);\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"/*\346\273\232\345\212\250\346\235\241\357\274\232\346\202\254\346"
                        "\265\256*/\n"
"QScrollBar::handle:horizontal:hover {\n"
"	border-radius: 5px;\n"
"    background: rgb(200, 200, 200);\n"
"    min-width: 20px;\n"
"}\n"
"\n"
"/*\344\270\213\347\256\255\345\244\264*/\n"
"QScrollBar::add-line:horizontal {\n"
"    width: 0;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"/*\344\270\212\347\256\255\345\244\264*/\n"
"QScrollBar::sub-line:horizontal {\n"
"    width: 0px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"\n"
"QScrollBar:horizontal {\n"
"    border: none;\n"
"    background-color: #F3F4F8;\n"
"    height: 10px;\n"
"}\n"
"\n"
"QScrollBar:vertical:horizontal {\n"
"    border: none;\n"
"    background-color: rgb(220, 220, 220);\n"
"    height: 10px;\n"
"}"));
        gridLayout = new QGridLayout(CourseAnalysisWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(CourseAnalysisWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -40, 1700, 1000));
        scrollAreaWidgetContents->setMinimumSize(QSize(1700, 1000));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8("QWidget#scrollAreaWidgetContents {\n"
"	background: #ffffff;\n"
"}"));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        analysis_frame = new QFrame(scrollAreaWidgetContents);
        analysis_frame->setObjectName(QString::fromUtf8("analysis_frame"));
        analysis_frame->setFrameShape(QFrame::StyledPanel);
        analysis_frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(analysis_frame);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 2, 0, 1, 1);

        lesson_cmpr_frame = new QFrame(analysis_frame);
        lesson_cmpr_frame->setObjectName(QString::fromUtf8("lesson_cmpr_frame"));
        lesson_cmpr_frame->setMinimumSize(QSize(0, 400));
        lesson_cmpr_frame->setMaximumSize(QSize(16777215, 400));
        lesson_cmpr_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: none;\n"
"	border: 1px solid #E8ECEC;\n"
"	border-top: none;\n"
"	border-right: none;\n"
"	border-left: none;\n"
"}"));
        lesson_cmpr_frame->setFrameShape(QFrame::StyledPanel);
        lesson_cmpr_frame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(lesson_cmpr_frame);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setVerticalSpacing(0);
        gridLayout_4->setContentsMargins(10, 10, 10, 10);
        label_3 = new QLabel(lesson_cmpr_frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: #666666;\n"
"background: none;\n"
"border: none;"));

        gridLayout_4->addWidget(label_3, 1, 3, 1, 1);

        frame_9 = new QFrame(lesson_cmpr_frame);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setMinimumSize(QSize(10, 10));
        frame_9->setMaximumSize(QSize(10, 10));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        frame_9->setFont(font1);
        frame_9->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: #c5a4ff;\n"
"	border-radius: 5px;\n"
"}"));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);

        gridLayout_4->addWidget(frame_9, 1, 2, 1, 1);

        label = new QLabel(lesson_cmpr_frame);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("color: #333333;\n"
"background: none;\n"
"border: none;"));

        gridLayout_4->addWidget(label, 1, 1, 1, 1);

        label_2 = new QLabel(lesson_cmpr_frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: #666666;\n"
"background: none;\n"
"border: none;"));

        gridLayout_4->addWidget(label_2, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 1, 4, 1, 1);

        lesson_cmpr_chartView = new QWebEngineView(lesson_cmpr_frame);
        lesson_cmpr_chartView->setObjectName(QString::fromUtf8("lesson_cmpr_chartView"));
        lesson_cmpr_chartView->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout_4->addWidget(lesson_cmpr_chartView, 3, 0, 1, 5);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 1, 0, 2, 1);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_4->addItem(verticalSpacer_2, 0, 0, 1, 2);


        gridLayout_3->addWidget(lesson_cmpr_frame, 0, 0, 1, 1);

        rank_frame = new QFrame(analysis_frame);
        rank_frame->setObjectName(QString::fromUtf8("rank_frame"));
        rank_frame->setMinimumSize(QSize(0, 400));
        rank_frame->setMaximumSize(QSize(16777215, 400));
        rank_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: none;\n"
"	border: 1px solid #E8ECEC;\n"
"	border-top: none;\n"
"	border-right: none;\n"
"	border-left: none;\n"
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
"}\n"
"\n"
"/*"
                        "\344\270\212\347\256\255\345\244\264*/\n"
"QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
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
"/*****************************************************/\n"
"\n"
"/*\346\225\264\344\275\223*/\n"
"QScrollBar:horizontal {\n"
"    border: none;\n"
"    background-color: #F3F4F8;\n"
"    height: 10px;\n"
"}\n"
"\n"
"QScrollBar:vertical:horizontal {\n"
"    border: none;\n"
"    background-color: rgb(220, 220, 220);\n"
"    height: 10px;\n"
"}\n"
"\n"
"/*\346\273\232\345\212\250\346\235\241*/\n"
"QScrollBar::handle:horizontal {\n"
"	border-radius: 5px;\n"
"    background: rgb(220, 220, 220);\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"/*\346\273\232\345\212\250\346\235\241\357\274\232\346\202\254"
                        "\346\265\256*/\n"
"QScrollBar::handle:horizontal:hover {\n"
"	border-radius: 5px;\n"
"    background: rgb(200, 200, 200);\n"
"    min-width: 20px;\n"
"}\n"
"\n"
"/*\344\270\213\347\256\255\345\244\264*/\n"
"QScrollBar::add-line:horizontal {\n"
"    width: 0;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"/*\344\270\212\347\256\255\345\244\264*/\n"
"QScrollBar::sub-line:horizontal {\n"
"    width: 0px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"\n"
"QScrollBar:horizontal {\n"
"    border: none;\n"
"    background-color: #F3F4F8;\n"
"    height: 10px;\n"
"}\n"
"\n"
"QScrollBar:vertical:horizontal {\n"
"    border: none;\n"
"    background-color: rgb(220, 220, 220);\n"
"    height: 10px;\n"
"}"));
        rank_frame->setFrameShape(QFrame::StyledPanel);
        rank_frame->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(rank_frame);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setVerticalSpacing(0);
        gridLayout_5->setContentsMargins(10, 10, 10, 10);
        label_4 = new QLabel(rank_frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("color: #333333;\n"
"background: none;\n"
"border: none;"));

        gridLayout_5->addWidget(label_4, 1, 1, 1, 1);

        rank_listWidget = new QListWidget(rank_frame);
        rank_listWidget->setObjectName(QString::fromUtf8("rank_listWidget"));
        rank_listWidget->setStyleSheet(QString::fromUtf8("border: none;"));
        rank_listWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

        gridLayout_5->addWidget(rank_listWidget, 6, 1, 1, 1);

        label_5 = new QLabel(rank_frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: #666666;\n"
"background: none;\n"
"border: none;"));

        gridLayout_5->addWidget(label_5, 2, 1, 1, 1);

        frame = new QFrame(rank_frame);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 150));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setMinimumSize(QSize(0, 0));
        frame_2->setMaximumSize(QSize(16777215, 16777215));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: none;\n"
"	border: none;\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_2);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_10 = new QLabel(frame_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(15);
        font3.setBold(true);
        font3.setWeight(75);
        label_10->setFont(font3);
        label_10->setStyleSheet(QString::fromUtf8("color: #333333;\n"
"background: none;\n"
"border: none;"));
        label_10->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_6->addWidget(label_10, 0, 2, 1, 1);

        webEngineView = new QWebEngineView(frame_2);
        webEngineView->setObjectName(QString::fromUtf8("webEngineView"));
        webEngineView->setMinimumSize(QSize(100, 100));
        webEngineView->setMaximumSize(QSize(100, 100));
        webEngineView->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout_6->addWidget(webEngineView, 0, 0, 2, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        label_16 = new QLabel(frame_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        sizePolicy.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy);
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setWeight(75);
        label_16->setFont(font4);
        label_16->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_6->addWidget(label_16, 0, 3, 1, 1);

        label_11 = new QLabel(frame_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8("color: #666666;\n"
"background: none;\n"
"border: none;"));
        label_11->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_6->addWidget(label_11, 1, 2, 1, 2);


        horizontalLayout_2->addWidget(frame_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setMinimumSize(QSize(0, 0));
        frame_3->setMaximumSize(QSize(16777215, 16777215));
        frame_3->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: none;\n"
"	border: none;\n"
"}"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame_3);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_12 = new QLabel(frame_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);
        label_12->setFont(font2);
        label_12->setStyleSheet(QString::fromUtf8("color: #333333;\n"
"background: none;\n"
"border: none;"));
        label_12->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_7->addWidget(label_12, 0, 2, 1, 1);

        webEngineView_2 = new QWebEngineView(frame_3);
        webEngineView_2->setObjectName(QString::fromUtf8("webEngineView_2"));
        webEngineView_2->setMinimumSize(QSize(100, 100));
        webEngineView_2->setMaximumSize(QSize(100, 100));
        webEngineView_2->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout_7->addWidget(webEngineView_2, 0, 0, 2, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        label_17 = new QLabel(frame_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        sizePolicy.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy);
        label_17->setFont(font4);
        label_17->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_7->addWidget(label_17, 0, 3, 1, 1);

        label_13 = new QLabel(frame_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font);
        label_13->setStyleSheet(QString::fromUtf8("color: #666666;\n"
"background: none;\n"
"border: none;"));
        label_13->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_7->addWidget(label_13, 1, 2, 1, 2);


        horizontalLayout_2->addWidget(frame_3);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setMinimumSize(QSize(0, 0));
        frame_4->setMaximumSize(QSize(16777215, 16777215));
        frame_4->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: none;\n"
"	border: none;\n"
"}"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_8 = new QGridLayout(frame_4);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        webEngineView_3 = new QWebEngineView(frame_4);
        webEngineView_3->setObjectName(QString::fromUtf8("webEngineView_3"));
        webEngineView_3->setMinimumSize(QSize(100, 100));
        webEngineView_3->setMaximumSize(QSize(100, 100));
        webEngineView_3->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout_8->addWidget(webEngineView_3, 0, 0, 2, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        label_14 = new QLabel(frame_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy);
        label_14->setFont(font2);
        label_14->setStyleSheet(QString::fromUtf8("color: #333333;\n"
"background: none;\n"
"border: none;"));
        label_14->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_8->addWidget(label_14, 0, 2, 1, 1);

        label_18 = new QLabel(frame_4);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        sizePolicy.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy);
        label_18->setFont(font4);
        label_18->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_8->addWidget(label_18, 0, 3, 1, 1);

        label_15 = new QLabel(frame_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font);
        label_15->setStyleSheet(QString::fromUtf8("color: #666666;\n"
"background: none;\n"
"border: none;"));
        label_15->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_8->addWidget(label_15, 1, 2, 1, 2);


        horizontalLayout_2->addWidget(frame_4);


        gridLayout_5->addWidget(frame, 4, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_5->addItem(verticalSpacer_4, 3, 1, 1, 1);

        rank_title_frame = new QFrame(rank_frame);
        rank_title_frame->setObjectName(QString::fromUtf8("rank_title_frame"));
        rank_title_frame->setMinimumSize(QSize(0, 50));
        rank_title_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: none;\n"
"	border: 1px solid #E8ECEC;\n"
"	border-top: none;\n"
"	border-right: none;\n"
"	border-left: none;\n"
"}"));
        rank_title_frame->setFrameShape(QFrame::StyledPanel);
        rank_title_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(rank_title_frame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, 0, 20, 0);
        label_6 = new QLabel(rank_title_frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);
        label_6->setMinimumSize(QSize(0, 0));
        label_6->setMaximumSize(QSize(16777215, 16777215));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setWeight(75);
        label_6->setFont(font5);
        label_6->setStyleSheet(QString::fromUtf8("color: #666666;\n"
"background: none;\n"
"border: none;"));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_6);

        label_8 = new QLabel(rank_title_frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy2.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy2);
        label_8->setMinimumSize(QSize(0, 0));
        label_8->setMaximumSize(QSize(16777215, 16777215));
        label_8->setFont(font5);
        label_8->setStyleSheet(QString::fromUtf8("color: #666666;\n"
"background: none;\n"
"border: none;"));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_8);

        label_7 = new QLabel(rank_title_frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);
        label_7->setMinimumSize(QSize(0, 0));
        label_7->setMaximumSize(QSize(16777215, 16777215));
        label_7->setFont(font5);
        label_7->setStyleSheet(QString::fromUtf8("color: #666666;\n"
"background: none;\n"
"border: none;"));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_7);

        label_9 = new QLabel(rank_title_frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy2.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy2);
        label_9->setMinimumSize(QSize(0, 0));
        label_9->setMaximumSize(QSize(16777215, 16777215));
        label_9->setFont(font5);
        label_9->setStyleSheet(QString::fromUtf8("color: #666666;\n"
"background: none;\n"
"border: none;"));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_9);


        gridLayout_5->addWidget(rank_title_frame, 5, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_4, 0, 2, 7, 1);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_5->addItem(verticalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_3, 0, 0, 7, 1);


        gridLayout_3->addWidget(rank_frame, 1, 0, 1, 1);


        gridLayout_2->addWidget(analysis_frame, 0, 0, 1, 1);

        course_frame = new QFrame(scrollAreaWidgetContents);
        course_frame->setObjectName(QString::fromUtf8("course_frame"));
        course_frame->setMinimumSize(QSize(500, 0));
        course_frame->setMaximumSize(QSize(500, 16777215));
        course_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: none;\n"
"	border: 1px solid #E8ECEC;\n"
"	border-top: none;\n"
"	border-right: none;\n"
"	border-bottom: none;\n"
"}"));
        course_frame->setFrameShape(QFrame::StyledPanel);
        course_frame->setFrameShadow(QFrame::Raised);

        gridLayout_2->addWidget(course_frame, 0, 1, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(CourseAnalysisWidget);

        QMetaObject::connectSlotsByName(CourseAnalysisWidget);
    } // setupUi

    void retranslateUi(QWidget *CourseAnalysisWidget)
    {
        CourseAnalysisWidget->setWindowTitle(QCoreApplication::translate("CourseAnalysisWidget", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("CourseAnalysisWidget", "\344\270\223\346\263\250\345\272\246", nullptr));
        label->setText(QCoreApplication::translate("CourseAnalysisWidget", "\350\257\276\345\240\202\344\270\223\346\263\250\345\272\246\345\257\271\346\257\224\345\210\206\346\236\220", nullptr));
        label_2->setText(QCoreApplication::translate("CourseAnalysisWidget", "\345\257\271\346\257\224\350\277\221\345\215\201\345\240\202\350\257\276\347\232\204\344\270\223\346\263\250\345\272\246", nullptr));
        label_4->setText(QCoreApplication::translate("CourseAnalysisWidget", "\344\270\223\346\263\250\345\272\246\346\216\222\350\241\214\346\246\234", nullptr));
        label_5->setText(QCoreApplication::translate("CourseAnalysisWidget", "\345\261\225\347\244\272\345\255\246\347\224\237\347\232\204\344\270\223\346\263\250\345\272\246\346\216\222\350\241\214", nullptr));
        label_10->setText(QCoreApplication::translate("CourseAnalysisWidget", "300", nullptr));
        label_16->setText(QCoreApplication::translate("CourseAnalysisWidget", "\344\272\272", nullptr));
        label_11->setText(QCoreApplication::translate("CourseAnalysisWidget", "\345\217\202\344\270\216\346\216\222\350\241\214\347\216\207", nullptr));
        label_12->setText(QCoreApplication::translate("CourseAnalysisWidget", "300", nullptr));
        label_17->setText(QCoreApplication::translate("CourseAnalysisWidget", "\344\272\272", nullptr));
        label_13->setText(QCoreApplication::translate("CourseAnalysisWidget", "\344\274\230\347\247\200\347\216\207", nullptr));
        label_14->setText(QCoreApplication::translate("CourseAnalysisWidget", "300", nullptr));
        label_18->setText(QCoreApplication::translate("CourseAnalysisWidget", "\344\272\272\346\254\241", nullptr));
        label_15->setText(QCoreApplication::translate("CourseAnalysisWidget", "\345\271\263\345\235\207\346\264\273\350\267\203\347\216\207", nullptr));
        label_6->setText(QCoreApplication::translate("CourseAnalysisWidget", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_8->setText(QCoreApplication::translate("CourseAnalysisWidget", "\345\217\202\344\270\216\346\254\241\346\225\260", nullptr));
        label_7->setText(QCoreApplication::translate("CourseAnalysisWidget", "\344\270\223\346\263\250\345\272\246\346\200\273\345\210\206", nullptr));
        label_9->setText(QCoreApplication::translate("CourseAnalysisWidget", "\346\216\222\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CourseAnalysisWidget: public Ui_CourseAnalysisWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_COURSEANALYSISWIDGET_H
