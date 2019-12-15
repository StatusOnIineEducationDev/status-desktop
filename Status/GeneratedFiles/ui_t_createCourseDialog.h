/********************************************************************************
** Form generated from reading UI file 't_createCourseDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_T_CREATECOURSEDIALOG_H
#define UI_T_CREATECOURSEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeacherCreateCourseDialog
{
public:
    QGridLayout *gridLayout_2;
    QFrame *shadow;
    QGridLayout *gridLayout;
    QFrame *title_bar;
    QGridLayout *gridLayout_3;
    QPushButton *close_btn;
    QLabel *title_text;
    QSpacerItem *horizontalSpacer_4;
    QFrame *main_area;
    QGridLayout *gridLayout_4;
    QFrame *frame;
    QGridLayout *gridLayout_8;
    QFrame *frame_3;
    QGridLayout *gridLayout_5;
    QFrame *basic_logo_frame;
    QGridLayout *gridLayout_16;
    QLabel *label_13;
    QLabel *label;
    QFrame *line_2;
    QFrame *line_1;
    QFrame *frame_6;
    QGridLayout *gridLayout_7;
    QLabel *finish_title;
    QFrame *finish_logo_frame;
    QGridLayout *gridLayout_17;
    QLabel *finish_pic;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame_4;
    QGridLayout *gridLayout_6;
    QFrame *intro_logo_frame;
    QGridLayout *gridLayout_18;
    QLabel *intro_pic;
    QLabel *intro_title;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *next_btn;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_12;
    QTabWidget *tabWidget;
    QWidget *page_1;
    QGridLayout *gridLayout_10;
    QSpacerItem *verticalSpacer;
    QFrame *frame_8;
    QGridLayout *gridLayout_9;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_3;
    QFrame *frame_9;
    QLineEdit *course_name_edit;
    QLabel *label_4;
    QLabel *label_2;
    QFrame *frame_12;
    QGridLayout *gridLayout_12;
    QLabel *label_9;
    QFrame *frame_13;
    QFrame *course_pic_frame;
    QGridLayout *gridLayout_19;
    QLabel *course_pic;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_8;
    QPushButton *choose_pic_btn;
    QLabel *label_7;
    QFrame *frame_10;
    QGridLayout *gridLayout_11;
    QSpacerItem *horizontalSpacer_5;
    QFrame *frame_11;
    QComboBox *course_classify;
    QLabel *label_3;
    QLabel *label_6;
    QWidget *page_2;
    QGridLayout *gridLayout_14;
    QFrame *frame_14;
    QGridLayout *gridLayout_13;
    QLabel *label_10;
    QFrame *frame_15;
    QLabel *label_11;
    QFrame *frame_16;
    QGridLayout *gridLayout_15;
    QLabel *now_count_text;
    QLabel *max_count_text;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_11;
    QPlainTextEdit *course_introduction_edit;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_14;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_3;
    QPushButton *back_btn;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *confirm_btn;
    QPushButton *finish_btn;
    QSpacerItem *horizontalSpacer_13;

    void setupUi(QDialog *TeacherCreateCourseDialog)
    {
        if (TeacherCreateCourseDialog->objectName().isEmpty())
            TeacherCreateCourseDialog->setObjectName(QString::fromUtf8("TeacherCreateCourseDialog"));
        TeacherCreateCourseDialog->resize(600, 665);
        TeacherCreateCourseDialog->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(TeacherCreateCourseDialog);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        shadow = new QFrame(TeacherCreateCourseDialog);
        shadow->setObjectName(QString::fromUtf8("shadow"));
        shadow->setFrameShape(QFrame::StyledPanel);
        shadow->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(shadow);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
        title_bar = new QFrame(shadow);
        title_bar->setObjectName(QString::fromUtf8("title_bar"));
        title_bar->setMinimumSize(QSize(0, 35));
        title_bar->setMaximumSize(QSize(16777215, 35));
        title_bar->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border-top-left-radius: 4px;\n"
"	border-top-right-radius: 4px;\n"
"	background-color: #fafafa;\n"
"}"));
        title_bar->setFrameShape(QFrame::StyledPanel);
        title_bar->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(title_bar);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        close_btn = new QPushButton(title_bar);
        close_btn->setObjectName(QString::fromUtf8("close_btn"));
        close_btn->setEnabled(true);
        close_btn->setMinimumSize(QSize(35, 35));
        close_btn->setMaximumSize(QSize(35, 35));
        close_btn->setCursor(QCursor(Qt::PointingHandCursor));
        close_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	border-top-right-radius: 4px;\n"
"	background-color: #fafafa;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(244, 84, 84);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/button/Resources/material/button/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        close_btn->setIcon(icon);
        close_btn->setIconSize(QSize(12, 12));

        gridLayout_3->addWidget(close_btn, 0, 2, 1, 1);

        title_text = new QLabel(title_bar);
        title_text->setObjectName(QString::fromUtf8("title_text"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        title_text->setFont(font);
        title_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));
        title_text->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(title_text, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 0, 0, 1, 1);


        gridLayout->addWidget(title_bar, 0, 0, 1, 1);

        main_area = new QFrame(shadow);
        main_area->setObjectName(QString::fromUtf8("main_area"));
        main_area->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: #ffffff;\n"
"	border-bottom-left-radius: 4px;\n"
"	border-bottom-right-radius: 4px;\n"
"}"));
        main_area->setFrameShape(QFrame::StyledPanel);
        main_area->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(main_area);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 20);
        frame = new QFrame(main_area);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 100));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border-bottom: 1px solid #E8ECEC;\n"
"	border-radius: 0px;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_8 = new QGridLayout(frame);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMinimumSize(QSize(80, 80));
        frame_3->setMaximumSize(QSize(80, 80));
        frame_3->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border: none;\n"
"}"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_3);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        basic_logo_frame = new QFrame(frame_3);
        basic_logo_frame->setObjectName(QString::fromUtf8("basic_logo_frame"));
        basic_logo_frame->setMinimumSize(QSize(60, 60));
        basic_logo_frame->setMaximumSize(QSize(60, 60));
        basic_logo_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: rgba(18, 150, 214, 50);\n"
"	border-radius: 30px;\n"
"	border: none;\n"
"}"));
        basic_logo_frame->setFrameShape(QFrame::StyledPanel);
        basic_logo_frame->setFrameShadow(QFrame::Raised);
        gridLayout_16 = new QGridLayout(basic_logo_frame);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        label_13 = new QLabel(basic_logo_frame);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(25, 25));
        label_13->setMaximumSize(QSize(25, 25));
        label_13->setStyleSheet(QString::fromUtf8("background: none;\n"
"border: none;"));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/pic/Resources/material/pic/basic.png")));
        label_13->setScaledContents(true);

        gridLayout_16->addWidget(label_13, 0, 0, 1, 1);


        gridLayout_5->addWidget(basic_logo_frame, 0, 0, 1, 1);

        label = new QLabel(frame_3);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: #1296d6;"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label, 1, 0, 1, 1);


        gridLayout_8->addWidget(frame_3, 0, 1, 1, 1);

        line_2 = new QFrame(frame);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_8->addWidget(line_2, 0, 4, 1, 1);

        line_1 = new QFrame(frame);
        line_1->setObjectName(QString::fromUtf8("line_1"));
        line_1->setStyleSheet(QString::fromUtf8("background: rgba(18, 150, 214, 50);"));
        line_1->setFrameShape(QFrame::HLine);
        line_1->setFrameShadow(QFrame::Sunken);

        gridLayout_8->addWidget(line_1, 0, 2, 1, 1);

        frame_6 = new QFrame(frame);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setMinimumSize(QSize(80, 80));
        frame_6->setMaximumSize(QSize(80, 80));
        frame_6->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border: none;\n"
"}"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame_6);
        gridLayout_7->setSpacing(0);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        finish_title = new QLabel(frame_6);
        finish_title->setObjectName(QString::fromUtf8("finish_title"));
        sizePolicy.setHeightForWidth(finish_title->sizePolicy().hasHeightForWidth());
        finish_title->setSizePolicy(sizePolicy);
        finish_title->setFont(font1);
        finish_title->setStyleSheet(QString::fromUtf8("color: #999999;"));
        finish_title->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(finish_title, 1, 0, 1, 1);

        finish_logo_frame = new QFrame(frame_6);
        finish_logo_frame->setObjectName(QString::fromUtf8("finish_logo_frame"));
        finish_logo_frame->setMinimumSize(QSize(60, 60));
        finish_logo_frame->setMaximumSize(QSize(60, 60));
        finish_logo_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: #f5f5f5;\n"
"	border-radius: 30px;\n"
"	border: none;\n"
"}"));
        finish_logo_frame->setFrameShape(QFrame::StyledPanel);
        finish_logo_frame->setFrameShadow(QFrame::Raised);
        gridLayout_17 = new QGridLayout(finish_logo_frame);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        finish_pic = new QLabel(finish_logo_frame);
        finish_pic->setObjectName(QString::fromUtf8("finish_pic"));
        finish_pic->setMinimumSize(QSize(25, 25));
        finish_pic->setMaximumSize(QSize(25, 25));
        finish_pic->setStyleSheet(QString::fromUtf8("background: none;\n"
"border: none;"));
        finish_pic->setPixmap(QPixmap(QString::fromUtf8(":/pic/Resources/material/pic/complete.png")));
        finish_pic->setScaledContents(true);

        gridLayout_17->addWidget(finish_pic, 0, 0, 1, 1);


        gridLayout_7->addWidget(finish_logo_frame, 0, 0, 1, 1);


        gridLayout_8->addWidget(frame_6, 0, 5, 1, 1);

        horizontalSpacer = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_2, 0, 6, 1, 1);

        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setMinimumSize(QSize(80, 80));
        frame_4->setMaximumSize(QSize(80, 80));
        frame_4->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border: none;\n"
"}"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_4);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        intro_logo_frame = new QFrame(frame_4);
        intro_logo_frame->setObjectName(QString::fromUtf8("intro_logo_frame"));
        intro_logo_frame->setMinimumSize(QSize(60, 60));
        intro_logo_frame->setMaximumSize(QSize(60, 60));
        intro_logo_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: #f5f5f5;\n"
"	border-radius: 30px;\n"
"	border: none;\n"
"}"));
        intro_logo_frame->setFrameShape(QFrame::StyledPanel);
        intro_logo_frame->setFrameShadow(QFrame::Raised);
        gridLayout_18 = new QGridLayout(intro_logo_frame);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        intro_pic = new QLabel(intro_logo_frame);
        intro_pic->setObjectName(QString::fromUtf8("intro_pic"));
        intro_pic->setMinimumSize(QSize(25, 25));
        intro_pic->setMaximumSize(QSize(25, 25));
        intro_pic->setStyleSheet(QString::fromUtf8("background: none;\n"
"border: none;"));
        intro_pic->setPixmap(QPixmap(QString::fromUtf8(":/pic/Resources/material/pic/introduction.png")));
        intro_pic->setScaledContents(true);

        gridLayout_18->addWidget(intro_pic, 0, 0, 1, 1);


        gridLayout_6->addWidget(intro_logo_frame, 0, 0, 1, 1);

        intro_title = new QLabel(frame_4);
        intro_title->setObjectName(QString::fromUtf8("intro_title"));
        sizePolicy.setHeightForWidth(intro_title->sizePolicy().hasHeightForWidth());
        intro_title->setSizePolicy(sizePolicy);
        intro_title->setFont(font1);
        intro_title->setStyleSheet(QString::fromUtf8("color: #999999;"));
        intro_title->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(intro_title, 1, 0, 1, 1);


        gridLayout_8->addWidget(frame_4, 0, 3, 1, 1);


        gridLayout_4->addWidget(frame, 0, 0, 1, 9);

        horizontalSpacer_10 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_10, 2, 2, 1, 1);

        next_btn = new QPushButton(main_area);
        next_btn->setObjectName(QString::fromUtf8("next_btn"));
        next_btn->setEnabled(true);
        next_btn->setMinimumSize(QSize(120, 30));
        next_btn->setMaximumSize(QSize(16777215, 30));
        next_btn->setFont(font1);
        next_btn->setCursor(QCursor(Qt::PointingHandCursor));
        next_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #1296d6;\n"
"	background: none;\n"
"	border: 1px solid  #1296d6;\n"
"	border-radius: 15px;\n"
"	padding-left: 10px;\n"
"	padding-right: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E6E6E6;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	color: #999999;\n"
"	background: none;\n"
"	border: 1px solid  #999999;\n"
"	border-radius: 15px;\n"
"	padding-left: 10px;\n"
"	padding-right: 10px;\n"
"}"));

        gridLayout_4->addWidget(next_btn, 2, 3, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_8, 2, 0, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_12, 2, 4, 1, 1);

        tabWidget = new QTabWidget(main_area);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab {\n"
"	border: none;\n"
"	background: none;\n"
"}\n"
"\n"
"QTabWidget {\n"
"	background: none;\n"
"	border: none;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"	border: none;\n"
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
"    subco"
                        "ntrol-origin: margin;\n"
"}\n"
"\n"
"/*\344\270\212\347\256\255\345\244\264*/\n"
"QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}"));
        tabWidget->setTabBarAutoHide(false);
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        gridLayout_10 = new QGridLayout(page_1);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setVerticalSpacing(20);
        gridLayout_10->setContentsMargins(20, 20, 20, 20);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_10->addItem(verticalSpacer, 3, 0, 1, 1);

        frame_8 = new QFrame(page_1);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        gridLayout_9 = new QGridLayout(frame_8);
        gridLayout_9->setSpacing(10);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(5, 5, 5, 5);
        label_5 = new QLabel(frame_8);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("color: #999999;"));

        gridLayout_9->addWidget(label_5, 0, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_3, 0, 4, 1, 1);

        frame_9 = new QFrame(frame_8);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setMinimumSize(QSize(10, 10));
        frame_9->setMaximumSize(QSize(10, 10));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        frame_9->setFont(font2);
        frame_9->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: #1296d6;\n"
"	border-radius: 5px;\n"
"}"));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);

        gridLayout_9->addWidget(frame_9, 0, 0, 1, 1);

        course_name_edit = new QLineEdit(frame_8);
        course_name_edit->setObjectName(QString::fromUtf8("course_name_edit"));
        course_name_edit->setMinimumSize(QSize(0, 40));
        course_name_edit->setMaximumSize(QSize(16777215, 40));
        course_name_edit->setFont(font1);
        course_name_edit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	padding-left: 10px;\n"
"	padding-right: 10px;\n"
"	border: 1px solid #E8ECEC;\n"
"	color: #666666;\n"
"}"));

        gridLayout_9->addWidget(course_name_edit, 1, 0, 1, 5);

        label_4 = new QLabel(frame_8);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8("color: #666666;"));

        gridLayout_9->addWidget(label_4, 0, 1, 1, 1);

        label_2 = new QLabel(frame_8);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setWeight(75);
        label_2->setFont(font4);
        label_2->setStyleSheet(QString::fromUtf8("color: red;"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_9->addWidget(label_2, 0, 2, 1, 1);


        gridLayout_10->addWidget(frame_8, 0, 0, 1, 1);

        frame_12 = new QFrame(page_1);
        frame_12->setObjectName(QString::fromUtf8("frame_12"));
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);
        gridLayout_12 = new QGridLayout(frame_12);
        gridLayout_12->setSpacing(10);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(5, 5, 5, 5);
        label_9 = new QLabel(frame_12);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("color: #999999;"));

        gridLayout_12->addWidget(label_9, 0, 3, 1, 1);

        frame_13 = new QFrame(frame_12);
        frame_13->setObjectName(QString::fromUtf8("frame_13"));
        frame_13->setMinimumSize(QSize(10, 10));
        frame_13->setMaximumSize(QSize(10, 10));
        frame_13->setFont(font2);
        frame_13->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: #1296d6;\n"
"	border-radius: 5px;\n"
"}"));
        frame_13->setFrameShape(QFrame::StyledPanel);
        frame_13->setFrameShadow(QFrame::Raised);

        gridLayout_12->addWidget(frame_13, 0, 0, 1, 1);

        course_pic_frame = new QFrame(frame_12);
        course_pic_frame->setObjectName(QString::fromUtf8("course_pic_frame"));
        course_pic_frame->setMinimumSize(QSize(200, 130));
        course_pic_frame->setMaximumSize(QSize(200, 130));
        course_pic_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border: 1px solid #E8ECEC;\n"
"	border-radius: 0px;\n"
"}"));
        course_pic_frame->setFrameShape(QFrame::StyledPanel);
        course_pic_frame->setFrameShadow(QFrame::Raised);
        gridLayout_19 = new QGridLayout(course_pic_frame);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        gridLayout_19->setHorizontalSpacing(0);
        gridLayout_19->setContentsMargins(0, 0, 0, 0);
        course_pic = new QLabel(course_pic_frame);
        course_pic->setObjectName(QString::fromUtf8("course_pic"));
        course_pic->setFont(font1);
        course_pic->setStyleSheet(QString::fromUtf8("border: none;\n"
"background: none;"));
        course_pic->setPixmap(QPixmap(QString::fromUtf8(":/pic/Resources/material/pic/none.png")));
        course_pic->setAlignment(Qt::AlignCenter);

        gridLayout_19->addWidget(course_pic, 0, 0, 1, 1);


        gridLayout_12->addWidget(course_pic_frame, 1, 0, 1, 5);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_12->addItem(horizontalSpacer_6, 0, 4, 1, 1);

        label_8 = new QLabel(frame_12);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font3);
        label_8->setStyleSheet(QString::fromUtf8("color: #666666;"));

        gridLayout_12->addWidget(label_8, 0, 1, 1, 1);

        choose_pic_btn = new QPushButton(frame_12);
        choose_pic_btn->setObjectName(QString::fromUtf8("choose_pic_btn"));
        choose_pic_btn->setEnabled(true);
        choose_pic_btn->setMinimumSize(QSize(0, 30));
        choose_pic_btn->setMaximumSize(QSize(16777215, 30));
        choose_pic_btn->setFont(font1);
        choose_pic_btn->setCursor(QCursor(Qt::PointingHandCursor));
        choose_pic_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #1296d6;\n"
"	background: none;\n"
"	border: 1px solid  #1296d6;\n"
"	border-radius: 15px;\n"
"	padding-left: 10px;\n"
"	padding-right: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E6E6E6;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	color: #999999;\n"
"	background: none;\n"
"	border: 1px solid  #999999;\n"
"	border-radius: 15px;\n"
"	padding-left: 10px;\n"
"	padding-right: 10px;\n"
"}"));

        gridLayout_12->addWidget(choose_pic_btn, 0, 5, 1, 1);

        label_7 = new QLabel(frame_12);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font4);
        label_7->setStyleSheet(QString::fromUtf8("color: red;"));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_12->addWidget(label_7, 0, 2, 1, 1);


        gridLayout_10->addWidget(frame_12, 2, 0, 1, 1);

        frame_10 = new QFrame(page_1);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        gridLayout_11 = new QGridLayout(frame_10);
        gridLayout_11->setSpacing(10);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(5, 5, 5, 5);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_5, 0, 4, 1, 1);

        frame_11 = new QFrame(frame_10);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        frame_11->setMinimumSize(QSize(10, 10));
        frame_11->setMaximumSize(QSize(10, 10));
        frame_11->setFont(font2);
        frame_11->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: #1296d6;\n"
"	border-radius: 5px;\n"
"}"));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);

        gridLayout_11->addWidget(frame_11, 0, 0, 1, 1);

        course_classify = new QComboBox(frame_10);
        course_classify->addItem(QString());
        course_classify->addItem(QString());
        course_classify->addItem(QString());
        course_classify->addItem(QString());
        course_classify->addItem(QString());
        course_classify->addItem(QString());
        course_classify->addItem(QString());
        course_classify->addItem(QString());
        course_classify->addItem(QString());
        course_classify->addItem(QString());
        course_classify->addItem(QString());
        course_classify->addItem(QString());
        course_classify->addItem(QString());
        course_classify->setObjectName(QString::fromUtf8("course_classify"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(course_classify->sizePolicy().hasHeightForWidth());
        course_classify->setSizePolicy(sizePolicy1);
        course_classify->setMinimumSize(QSize(0, 40));
        course_classify->setMaximumSize(QSize(16777215, 40));
        course_classify->setFont(font1);
        course_classify->setCursor(QCursor(Qt::PointingHandCursor));
        course_classify->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	padding-left: 10px;\n"
"	padding-right: 10px;\n"
"	border: 1px solid #E8ECEC;\n"
"	color: #666666;\n"
"	background: #ffffff;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"	image: url(:/button/Resources/material/button/down.png);\n"
"	width: 20px;\n"
"	height: 10px;\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"	border:none;\n"
"  \n"
"}\n"
"\n"
"QComboBox#comboBoxTwo::drop-down{\n"
"	border: none;\n"
"	background: none;  \n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item {\n"
"    font-size: 10px;\n"
"}"));
        course_classify->setIconSize(QSize(16, 16));

        gridLayout_11->addWidget(course_classify, 1, 0, 1, 5);

        label_3 = new QLabel(frame_10);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font4);
        label_3->setStyleSheet(QString::fromUtf8("color: red;"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_11->addWidget(label_3, 0, 2, 1, 1);

        label_6 = new QLabel(frame_10);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font3);
        label_6->setStyleSheet(QString::fromUtf8("color: #666666;"));

        gridLayout_11->addWidget(label_6, 0, 1, 1, 1);


        gridLayout_10->addWidget(frame_10, 1, 0, 1, 1);

        tabWidget->addTab(page_1, QString());
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout_14 = new QGridLayout(page_2);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_14->setVerticalSpacing(20);
        gridLayout_14->setContentsMargins(20, 20, 20, 20);
        frame_14 = new QFrame(page_2);
        frame_14->setObjectName(QString::fromUtf8("frame_14"));
        frame_14->setMinimumSize(QSize(0, 350));
        frame_14->setMaximumSize(QSize(16777215, 350));
        frame_14->setFrameShape(QFrame::StyledPanel);
        frame_14->setFrameShadow(QFrame::Raised);
        gridLayout_13 = new QGridLayout(frame_14);
        gridLayout_13->setSpacing(10);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setContentsMargins(5, 5, 5, 5);
        label_10 = new QLabel(frame_14);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font3);
        label_10->setStyleSheet(QString::fromUtf8("color: #666666;"));

        gridLayout_13->addWidget(label_10, 0, 1, 1, 1);

        frame_15 = new QFrame(frame_14);
        frame_15->setObjectName(QString::fromUtf8("frame_15"));
        frame_15->setMinimumSize(QSize(10, 10));
        frame_15->setMaximumSize(QSize(10, 10));
        frame_15->setFont(font2);
        frame_15->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: #1296d6;\n"
"	border-radius: 5px;\n"
"}"));
        frame_15->setFrameShape(QFrame::StyledPanel);
        frame_15->setFrameShadow(QFrame::Raised);

        gridLayout_13->addWidget(frame_15, 0, 0, 1, 1);

        label_11 = new QLabel(frame_14);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("color: #999999;"));

        gridLayout_13->addWidget(label_11, 0, 3, 1, 1);

        frame_16 = new QFrame(frame_14);
        frame_16->setObjectName(QString::fromUtf8("frame_16"));
        frame_16->setMinimumSize(QSize(0, 30));
        frame_16->setMaximumSize(QSize(16777215, 30));
        frame_16->setFrameShape(QFrame::StyledPanel);
        frame_16->setFrameShadow(QFrame::Raised);
        gridLayout_15 = new QGridLayout(frame_16);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        now_count_text = new QLabel(frame_16);
        now_count_text->setObjectName(QString::fromUtf8("now_count_text"));
        now_count_text->setFont(font1);
        now_count_text->setStyleSheet(QString::fromUtf8("color: #999999;"));

        gridLayout_15->addWidget(now_count_text, 0, 1, 1, 1);

        max_count_text = new QLabel(frame_16);
        max_count_text->setObjectName(QString::fromUtf8("max_count_text"));
        max_count_text->setFont(font1);
        max_count_text->setStyleSheet(QString::fromUtf8("color: #999999;"));
        max_count_text->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_15->addWidget(max_count_text, 0, 3, 1, 1);

        label_12 = new QLabel(frame_16);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font1);
        label_12->setStyleSheet(QString::fromUtf8("color: #999999;"));

        gridLayout_15->addWidget(label_12, 0, 2, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_15->addItem(horizontalSpacer_11, 0, 0, 1, 1);


        gridLayout_13->addWidget(frame_16, 2, 0, 1, 5);

        course_introduction_edit = new QPlainTextEdit(frame_14);
        course_introduction_edit->setObjectName(QString::fromUtf8("course_introduction_edit"));
        course_introduction_edit->setFont(font1);
        course_introduction_edit->setStyleSheet(QString::fromUtf8("QPlainTextEdit {\n"
"	padding-left: 5px;\n"
"	padding-right: 5px;\n"
"	border: 1px solid #E8ECEC;\n"
"	border-radius: 0px;\n"
"	background: transparent;\n"
"	color: #666666;\n"
"}"));

        gridLayout_13->addWidget(course_introduction_edit, 1, 0, 1, 5);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_13->addItem(horizontalSpacer_7, 0, 4, 1, 1);

        label_14 = new QLabel(frame_14);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font4);
        label_14->setStyleSheet(QString::fromUtf8("color: red;"));
        label_14->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_13->addWidget(label_14, 0, 2, 1, 1);


        gridLayout_14->addWidget(frame_14, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_14->addItem(verticalSpacer_2, 1, 0, 1, 1);

        tabWidget->addTab(page_2, QString());
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        tabWidget->addTab(page_3, QString());

        gridLayout_4->addWidget(tabWidget, 1, 0, 1, 9);

        back_btn = new QPushButton(main_area);
        back_btn->setObjectName(QString::fromUtf8("back_btn"));
        back_btn->setEnabled(true);
        back_btn->setMinimumSize(QSize(120, 30));
        back_btn->setMaximumSize(QSize(120, 30));
        back_btn->setFont(font1);
        back_btn->setCursor(QCursor(Qt::PointingHandCursor));
        back_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #999999;\n"
"	background: none;\n"
"	border: 1px solid  #999999;\n"
"	border-radius: 15px;\n"
"	padding-left: 10px;\n"
"	padding-right: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E6E6E6;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	color: #999999;\n"
"	background: none;\n"
"	border: 1px solid  #999999;\n"
"	border-radius: 15px;\n"
"	padding-left: 10px;\n"
"	padding-right: 10px;\n"
"}"));

        gridLayout_4->addWidget(back_btn, 2, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_9, 2, 8, 1, 1);

        confirm_btn = new QPushButton(main_area);
        confirm_btn->setObjectName(QString::fromUtf8("confirm_btn"));
        confirm_btn->setEnabled(true);
        confirm_btn->setMinimumSize(QSize(120, 30));
        confirm_btn->setMaximumSize(QSize(16777215, 30));
        confirm_btn->setFont(font1);
        confirm_btn->setCursor(QCursor(Qt::PointingHandCursor));
        confirm_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #1296d6;\n"
"	background: none;\n"
"	border: 1px solid  #1296d6;\n"
"	border-radius: 15px;\n"
"	padding-left: 10px;\n"
"	padding-right: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E6E6E6;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	color: #999999;\n"
"	background: none;\n"
"	border: 1px solid  #999999;\n"
"	border-radius: 15px;\n"
"	padding-left: 10px;\n"
"	padding-right: 10px;\n"
"}"));

        gridLayout_4->addWidget(confirm_btn, 2, 5, 1, 1);

        finish_btn = new QPushButton(main_area);
        finish_btn->setObjectName(QString::fromUtf8("finish_btn"));
        finish_btn->setEnabled(true);
        finish_btn->setMinimumSize(QSize(120, 30));
        finish_btn->setMaximumSize(QSize(16777215, 30));
        finish_btn->setFont(font1);
        finish_btn->setCursor(QCursor(Qt::PointingHandCursor));
        finish_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #1296d6;\n"
"	background: none;\n"
"	border: 1px solid  #1296d6;\n"
"	border-radius: 15px;\n"
"	padding-left: 10px;\n"
"	padding-right: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E6E6E6;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	color: #999999;\n"
"	background: none;\n"
"	border: 1px solid  #999999;\n"
"	border-radius: 15px;\n"
"	padding-left: 10px;\n"
"	padding-right: 10px;\n"
"}"));

        gridLayout_4->addWidget(finish_btn, 2, 7, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_13, 2, 6, 1, 1);


        gridLayout->addWidget(main_area, 1, 0, 1, 1);


        gridLayout_2->addWidget(shadow, 0, 0, 1, 1);


        retranslateUi(TeacherCreateCourseDialog);
        QObject::connect(close_btn, SIGNAL(clicked()), TeacherCreateCourseDialog, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TeacherCreateCourseDialog);
    } // setupUi

    void retranslateUi(QDialog *TeacherCreateCourseDialog)
    {
        TeacherCreateCourseDialog->setWindowTitle(QCoreApplication::translate("TeacherCreateCourseDialog", "Dialog", nullptr));
#if QT_CONFIG(tooltip)
        close_btn->setToolTip(QCoreApplication::translate("TeacherCreateCourseDialog", "\345\205\263\351\227\255", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        close_btn->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        close_btn->setText(QString());
        title_text->setText(QCoreApplication::translate("TeacherCreateCourseDialog", "\345\210\233\345\273\272\350\257\276\347\250\213", nullptr));
        label_13->setText(QString());
        label->setText(QCoreApplication::translate("TeacherCreateCourseDialog", "\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        finish_title->setText(QCoreApplication::translate("TeacherCreateCourseDialog", "\345\256\214\346\210\220", nullptr));
        finish_pic->setText(QString());
        intro_pic->setText(QString());
        intro_title->setText(QCoreApplication::translate("TeacherCreateCourseDialog", "\350\257\276\347\250\213\344\273\213\347\273\215", nullptr));
        next_btn->setText(QCoreApplication::translate("TeacherCreateCourseDialog", "\344\270\213\344\270\200\346\255\245", nullptr));
        label_5->setText(QCoreApplication::translate("TeacherCreateCourseDialog", "\350\257\276\347\250\213\345\220\215\347\247\260\347\224\2611-40\344\270\252\345\255\227\347\254\246\347\273\204\346\210\220", nullptr));
        label_4->setText(QCoreApplication::translate("TeacherCreateCourseDialog", "\350\257\276\347\250\213\345\220\215\347\247\260", nullptr));
        label_2->setText(QCoreApplication::translate("TeacherCreateCourseDialog", "*", nullptr));
        label_9->setText(QCoreApplication::translate("TeacherCreateCourseDialog", "\344\270\212\344\274\240\344\270\200\345\274\240\345\233\276\347\211\207\344\275\234\344\270\272\350\257\276\347\250\213\347\232\204\345\260\201\351\235\242\345\261\225\347\244\272", nullptr));
        course_pic->setText(QString());
        label_8->setText(QCoreApplication::translate("TeacherCreateCourseDialog", "\350\257\276\347\250\213\345\260\201\351\235\242", nullptr));
        choose_pic_btn->setText(QCoreApplication::translate("TeacherCreateCourseDialog", "\351\200\211\346\213\251\345\233\276\347\211\207", nullptr));
        label_7->setText(QCoreApplication::translate("TeacherCreateCourseDialog", "*", nullptr));
        course_classify->setItemText(0, QCoreApplication::translate("TeacherCreateCourseDialog", "\345\223\262\345\255\246", nullptr));
        course_classify->setItemText(1, QCoreApplication::translate("TeacherCreateCourseDialog", "\347\273\217\346\265\216\345\255\246", nullptr));
        course_classify->setItemText(2, QCoreApplication::translate("TeacherCreateCourseDialog", "\346\263\225\345\255\246", nullptr));
        course_classify->setItemText(3, QCoreApplication::translate("TeacherCreateCourseDialog", "\346\225\231\350\202\262\345\255\246", nullptr));
        course_classify->setItemText(4, QCoreApplication::translate("TeacherCreateCourseDialog", "\346\226\207\345\255\246", nullptr));
        course_classify->setItemText(5, QCoreApplication::translate("TeacherCreateCourseDialog", "\345\216\206\345\217\262\345\255\246", nullptr));
        course_classify->setItemText(6, QCoreApplication::translate("TeacherCreateCourseDialog", "\347\220\206\345\255\246", nullptr));
        course_classify->setItemText(7, QCoreApplication::translate("TeacherCreateCourseDialog", "\345\267\245\345\255\246", nullptr));
        course_classify->setItemText(8, QCoreApplication::translate("TeacherCreateCourseDialog", "\345\206\234\345\255\246", nullptr));
        course_classify->setItemText(9, QCoreApplication::translate("TeacherCreateCourseDialog", "\345\214\273\345\255\246", nullptr));
        course_classify->setItemText(10, QCoreApplication::translate("TeacherCreateCourseDialog", "\345\206\233\344\272\213\345\255\246", nullptr));
        course_classify->setItemText(11, QCoreApplication::translate("TeacherCreateCourseDialog", "\347\256\241\347\220\206\345\255\246", nullptr));
        course_classify->setItemText(12, QCoreApplication::translate("TeacherCreateCourseDialog", "\350\211\272\346\234\257\345\255\246", nullptr));

        label_3->setText(QCoreApplication::translate("TeacherCreateCourseDialog", "*", nullptr));
        label_6->setText(QCoreApplication::translate("TeacherCreateCourseDialog", "\350\257\276\347\250\213\345\210\206\347\261\273", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(page_1), QCoreApplication::translate("TeacherCreateCourseDialog", "\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        label_10->setText(QCoreApplication::translate("TeacherCreateCourseDialog", "\350\257\276\347\250\213\347\256\200\344\273\213", nullptr));
        label_11->setText(QCoreApplication::translate("TeacherCreateCourseDialog", "\347\256\200\350\246\201\344\273\213\347\273\215\346\202\250\347\232\204\350\257\276\347\250\213", nullptr));
        now_count_text->setText(QCoreApplication::translate("TeacherCreateCourseDialog", "now_count", nullptr));
        max_count_text->setText(QCoreApplication::translate("TeacherCreateCourseDialog", "200", nullptr));
        label_12->setText(QCoreApplication::translate("TeacherCreateCourseDialog", "/", nullptr));
        course_introduction_edit->setPlainText(QString());
        label_14->setText(QCoreApplication::translate("TeacherCreateCourseDialog", "*", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(page_2), QCoreApplication::translate("TeacherCreateCourseDialog", "\350\257\276\347\250\213\344\273\213\347\273\215", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(page_3), QCoreApplication::translate("TeacherCreateCourseDialog", "\345\256\214\346\210\220", nullptr));
        back_btn->setText(QCoreApplication::translate("TeacherCreateCourseDialog", "\344\270\212\344\270\200\346\255\245", nullptr));
        confirm_btn->setText(QCoreApplication::translate("TeacherCreateCourseDialog", "\347\241\256\350\256\244\345\210\233\345\273\272", nullptr));
        finish_btn->setText(QCoreApplication::translate("TeacherCreateCourseDialog", "\345\256\214\346\210\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeacherCreateCourseDialog: public Ui_TeacherCreateCourseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_T_CREATECOURSEDIALOG_H
