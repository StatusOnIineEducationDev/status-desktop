/********************************************************************************
** Form generated from reading UI file 'teacher_course_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHER_COURSE_WIDGET_H
#define UI_TEACHER_COURSE_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qchartview.h"

QT_BEGIN_NAMESPACE

class Ui_TeacherCourseWidget
{
public:
    QGridLayout *gridLayout_2;
    QFrame *course_base_info_area;
    QGridLayout *gridLayout;
    QLabel *create_date_text;
    QPushButton *pushButton_17;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *pushButton_16;
    QSpacerItem *verticalSpacer;
    QComboBox *courses_comboBox;
    QLabel *create_time_text_2;
    QPushButton *delete_course_btn;
    QLabel *course_id_text;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabWidget;
    QWidget *course_data_tab;
    QGridLayout *gridLayout_22;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_9;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_3;
    QFrame *data_2_area;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_7;
    QLabel *data_2_text;
    QLabel *title_2_text;
    QSpacerItem *verticalSpacer_8;
    QFrame *data_1_area;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QLabel *data_1_text;
    QLabel *title_1_text;
    QSpacerItem *verticalSpacer_4;
    QFrame *data_3_area;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_5;
    QLabel *data_3_text;
    QLabel *title_3_text;
    QSpacerItem *verticalSpacer_6;
    QFrame *course_key_area;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer_11;
    QLabel *label_10;
    QLabel *course_key_title_text;
    QLabel *couse_key_text;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_12;
    QFrame *data_4_area;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_9;
    QLabel *data_4_text;
    QLabel *title_4_text;
    QSpacerItem *verticalSpacer_10;
    QSpacerItem *verticalSpacer_15;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QFrame *emotion_report_chart;
    QVBoxLayout *verticalLayout_6;
    QLabel *emotion_report_title_text;
    QLabel *emotion_report_tips_text;
    QWidget *emotion_report_line_chart_widget;
    QFrame *emotion_report_percentage_chart;
    QGridLayout *gridLayout_7;
    QPushButton *disgust_btn;
    QLabel *label_122;
    QPushButton *neutral_btn;
    QLabel *label_103;
    QLabel *label_119;
    QPushButton *fear_btn;
    QLabel *label_99;
    QLabel *label_89;
    QLabel *neutral_times_text;
    QLabel *fear_times_text;
    QLabel *fear_title_text;
    QProgressBar *fear_progressBar;
    QProgressBar *happy_progressBar;
    QLabel *disgust_percent_text;
    QLabel *sad_times_text;
    QProgressBar *disgust_progressBar;
    QLabel *angry_title_text;
    QLabel *surprise_title_text;
    QLabel *label_88;
    QLabel *happy_times_text;
    QLabel *angry_percent_text;
    QLabel *disgust_times_text;
    QLabel *happy_percent_text;
    QLabel *label_123;
    QLabel *label_91;
    QLabel *surprise_percent_text;
    QProgressBar *neutral_progressBar;
    QLabel *happy_title_text;
    QLabel *label_111;
    QPushButton *surprise_btn;
    QPushButton *angry_btn;
    QProgressBar *angry_progressBar;
    QLabel *sad_percent_text;
    QLabel *neutral_title_text;
    QLabel *label_112;
    QLabel *label_102;
    QLabel *label_116;
    QLabel *label_92;
    QLabel *fear_percent_text;
    QProgressBar *surprise_progressBar;
    QLabel *label_106;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *happy_btn;
    QLabel *angry_times_text;
    QLabel *sad_title_text;
    QLabel *disgust_title_text;
    QLabel *label_120;
    QProgressBar *sad_progressBar;
    QPushButton *sad_btn;
    QLabel *surprise_times_text;
    QLabel *neutral_percent_text;
    QSpacerItem *verticalSpacer_14;
    QSpacerItem *verticalSpacer_13;
    QSpacerItem *verticalSpacer_16;
    QGridLayout *gridLayout_8;
    QFrame *distribution_chart;
    QVBoxLayout *verticalLayout_7;
    QLabel *label;
    QWidget *distribution_chart_widget;
    QFrame *distribution_chart_progressBar;
    QGridLayout *gridLayout_10;
    QLabel *label_97;
    QLabel *label_95;
    QLabel *label_93;
    QProgressBar *progressBar_17;
    QProgressBar *excellent_progressBar;
    QLabel *distribution_chart_title_text;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_90;
    QProgressBar *bad_progressBar;
    QLabel *label_96;
    QLabel *label_94;
    QLabel *label_98;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_11;
    QFrame *area_chart;
    QVBoxLayout *verticalLayout_5;
    QLabel *area_chart_title_text;
    QtCharts::QChartView *area_chart_widget;
    QWidget *course_member_tab;
    QGridLayout *gridLayout_16;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_11;
    QGridLayout *gridLayout_17;
    QGridLayout *gridLayout_21;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_9;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_17;
    QLabel *concentration_text;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_18;
    QLabel *raise_hand_rate_text;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_11;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_19;
    QLabel *excellent_rate_text;
    QFrame *frame_9;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_14;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer_20;
    QLabel *join_date_text;
    QFrame *frame_5;
    QGridLayout *gridLayout_23;
    QLabel *member_name_text;
    QLabel *member_id_text;
    QLabel *member_pic;
    QFrame *frame;
    QGridLayout *gridLayout_18;
    QSpacerItem *horizontalSpacer_13;
    QFrame *frame_15;
    QFrame *frame_16;
    QLabel *num_of_student_text;
    QSpacerItem *horizontalSpacer_16;
    QLabel *label_100;
    QLabel *label_104;
    QLabel *label_107;
    QLabel *label_109;
    QFrame *frame_17;
    QFrame *frame_18;
    QLabel *total_text;
    QSpacerItem *horizontalSpacer_14;
    QFrame *frame_13;
    QFrame *frame_14;
    QLabel *num_of_teacher_text;
    QSpacerItem *horizontalSpacer_15;
    QLabel *area_chart_title_text_2;
    QSpacerItem *verticalSpacer_18;
    QSpacerItem *verticalSpacer_17;
    QVBoxLayout *verticalLayout_8;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *area_chart_title_text_3;
    QSpacerItem *horizontalSpacer_21;
    QPushButton *pushButton_15;
    QFrame *frame_4;
    QGridLayout *gridLayout_24;
    QTableWidget *member_table;
    QFrame *frame_10;
    QVBoxLayout *verticalLayout_12;
    QLabel *area_chart_title_text_4;
    QWidget *student_area_chart_widget;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *TeacherCourseWidget)
    {
        if (TeacherCourseWidget->objectName().isEmpty())
            TeacherCourseWidget->setObjectName(QString::fromUtf8("TeacherCourseWidget"));
        TeacherCourseWidget->resize(819, 627);
        TeacherCourseWidget->setMinimumSize(QSize(819, 627));
        TeacherCourseWidget->setStyleSheet(QString::fromUtf8("QWidget#TeacherCourseWidget {\n"
"	background: #F3F4F8;\n"
"}"));
        gridLayout_2 = new QGridLayout(TeacherCourseWidget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        course_base_info_area = new QFrame(TeacherCourseWidget);
        course_base_info_area->setObjectName(QString::fromUtf8("course_base_info_area"));
        course_base_info_area->setMinimumSize(QSize(819, 100));
        course_base_info_area->setMaximumSize(QSize(16777215, 100));
        course_base_info_area->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #F6F8F7;\n"
"	border-bottom: 1px solid #E8ECEC;\n"
"}"));
        course_base_info_area->setFrameShape(QFrame::StyledPanel);
        course_base_info_area->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(course_base_info_area);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(10);
        gridLayout->setContentsMargins(5, 5, 5, 5);
        create_date_text = new QLabel(course_base_info_area);
        create_date_text->setObjectName(QString::fromUtf8("create_date_text"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        create_date_text->setFont(font);
        create_date_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));

        gridLayout->addWidget(create_date_text, 2, 0, 1, 1);

        pushButton_17 = new QPushButton(course_base_info_area);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        pushButton_17->setMinimumSize(QSize(80, 0));
        pushButton_17->setMaximumSize(QSize(80, 16777215));
        pushButton_17->setFont(font);
        pushButton_17->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_17->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #bbbbbb;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	color: #333333;\n"
"}"));

        gridLayout->addWidget(pushButton_17, 1, 4, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 0, 1, 4);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_12, 2, 1, 1, 1);

        pushButton_16 = new QPushButton(course_base_info_area);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        pushButton_16->setMinimumSize(QSize(80, 0));
        pushButton_16->setMaximumSize(QSize(80, 16777215));
        pushButton_16->setFont(font);
        pushButton_16->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_16->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #bbbbbb;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	color: #333333;\n"
"}"));

        gridLayout->addWidget(pushButton_16, 1, 5, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 4);

        courses_comboBox = new QComboBox(course_base_info_area);
        courses_comboBox->addItem(QString());
        courses_comboBox->setObjectName(QString::fromUtf8("courses_comboBox"));
        courses_comboBox->setMinimumSize(QSize(250, 0));
        courses_comboBox->setMaximumSize(QSize(250, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(16);
        courses_comboBox->setFont(font1);
        courses_comboBox->setCursor(QCursor(Qt::PointingHandCursor));
        courses_comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	color: #333333;\n"
"	border: none;\n"
"	background-color: #F6F8F7;\n"
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
        courses_comboBox->setIconSize(QSize(16, 16));

        gridLayout->addWidget(courses_comboBox, 1, 0, 1, 1);

        create_time_text_2 = new QLabel(course_base_info_area);
        create_time_text_2->setObjectName(QString::fromUtf8("create_time_text_2"));
        create_time_text_2->setFont(font);
        create_time_text_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));
        create_time_text_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(create_time_text_2, 2, 5, 1, 1);

        delete_course_btn = new QPushButton(course_base_info_area);
        delete_course_btn->setObjectName(QString::fromUtf8("delete_course_btn"));
        delete_course_btn->setMinimumSize(QSize(80, 0));
        delete_course_btn->setMaximumSize(QSize(80, 16777215));
        delete_course_btn->setFont(font);
        delete_course_btn->setCursor(QCursor(Qt::PointingHandCursor));
        delete_course_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #bbbbbb;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	color: red;\n"
"}"));

        gridLayout->addWidget(delete_course_btn, 1, 6, 1, 1, Qt::AlignRight);

        course_id_text = new QLabel(course_base_info_area);
        course_id_text->setObjectName(QString::fromUtf8("course_id_text"));
        course_id_text->setFont(font);
        course_id_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));
        course_id_text->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(course_id_text, 2, 6, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 2);


        gridLayout_2->addWidget(course_base_info_area, 0, 0, 1, 1);

        tabWidget = new QTabWidget(TeacherCourseWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(819, 527));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab {\n"
"	margin: 10px 20px 10px 20px;\n"
"	width: 30px;\n"
"	height: 30px;\n"
"	border: none;\n"
"	background: none;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"	border: none;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"	alignment:center;\n"
"}"));
        tabWidget->setIconSize(QSize(30, 30));
        course_data_tab = new QWidget();
        course_data_tab->setObjectName(QString::fromUtf8("course_data_tab"));
        course_data_tab->setStyleSheet(QString::fromUtf8(""));
        gridLayout_22 = new QGridLayout(course_data_tab);
        gridLayout_22->setSpacing(0);
        gridLayout_22->setObjectName(QString::fromUtf8("gridLayout_22"));
        gridLayout_22->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(course_data_tab);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setLayoutDirection(Qt::LeftToRight);
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea#scrollArea {\n"
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
"/*\344\270\212\347\256\255\345\244\264*/\n"
"QScrollBar::su"
                        "b-line:vertical {\n"
"    height: 0px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 802, 1249));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color:transparent;\n"
"}"));
        gridLayout_9 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        data_2_area = new QFrame(scrollAreaWidgetContents);
        data_2_area->setObjectName(QString::fromUtf8("data_2_area"));
        data_2_area->setMinimumSize(QSize(155, 100));
        data_2_area->setMaximumSize(QSize(155, 100));
        data_2_area->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #6C6FC0;\n"
"}"));
        data_2_area->setFrameShape(QFrame::StyledPanel);
        data_2_area->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(data_2_area);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_7);

        data_2_text = new QLabel(data_2_area);
        data_2_text->setObjectName(QString::fromUtf8("data_2_text"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(20);
        data_2_text->setFont(font2);
        data_2_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #ffffff;\n"
"}"));
        data_2_text->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(data_2_text);

        title_2_text = new QLabel(data_2_area);
        title_2_text->setObjectName(QString::fromUtf8("title_2_text"));
        title_2_text->setFont(font);
        title_2_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #A8B1DC;\n"
"}"));
        title_2_text->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(title_2_text);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_8);


        gridLayout_3->addWidget(data_2_area, 0, 1, 1, 1);

        data_1_area = new QFrame(scrollAreaWidgetContents);
        data_1_area->setObjectName(QString::fromUtf8("data_1_area"));
        data_1_area->setMinimumSize(QSize(155, 100));
        data_1_area->setMaximumSize(QSize(155, 100));
        data_1_area->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #ffffff;\n"
"}"));
        data_1_area->setFrameShape(QFrame::StyledPanel);
        data_1_area->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(data_1_area);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        data_1_text = new QLabel(data_1_area);
        data_1_text->setObjectName(QString::fromUtf8("data_1_text"));
        data_1_text->setFont(font2);
        data_1_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #23B7E5;\n"
"}"));
        data_1_text->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(data_1_text);

        title_1_text = new QLabel(data_1_area);
        title_1_text->setObjectName(QString::fromUtf8("title_1_text"));
        title_1_text->setFont(font);
        title_1_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #666666;\n"
"}"));
        title_1_text->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(title_1_text);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);


        gridLayout_3->addWidget(data_1_area, 0, 0, 1, 1);

        data_3_area = new QFrame(scrollAreaWidgetContents);
        data_3_area->setObjectName(QString::fromUtf8("data_3_area"));
        data_3_area->setMinimumSize(QSize(155, 100));
        data_3_area->setMaximumSize(QSize(155, 100));
        data_3_area->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #23B7E5;\n"
"}"));
        data_3_area->setFrameShape(QFrame::StyledPanel);
        data_3_area->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(data_3_area);
        verticalLayout_4->setSpacing(5);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);

        data_3_text = new QLabel(data_3_area);
        data_3_text->setObjectName(QString::fromUtf8("data_3_text"));
        data_3_text->setFont(font2);
        data_3_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #ffffff;\n"
"}"));
        data_3_text->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(data_3_text);

        title_3_text = new QLabel(data_3_area);
        title_3_text->setObjectName(QString::fromUtf8("title_3_text"));
        title_3_text->setFont(font);
        title_3_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #666666;\n"
"}"));
        title_3_text->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(title_3_text);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_6);


        gridLayout_3->addWidget(data_3_area, 1, 0, 1, 1);

        course_key_area = new QFrame(scrollAreaWidgetContents);
        course_key_area->setObjectName(QString::fromUtf8("course_key_area"));
        course_key_area->setMinimumSize(QSize(320, 100));
        course_key_area->setMaximumSize(QSize(320, 100));
        course_key_area->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #E4E9EC;\n"
"}"));
        course_key_area->setFrameShape(QFrame::StyledPanel);
        course_key_area->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(course_key_area);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setHorizontalSpacing(0);
        gridLayout_4->setVerticalSpacing(5);
        gridLayout_4->setContentsMargins(10, 0, 10, 0);
        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_11, 3, 2, 1, 1);

        label_10 = new QLabel(course_key_area);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(60, 60));
        label_10->setMaximumSize(QSize(60, 60));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/pic/Resources/material/pic/key.png")));
        label_10->setScaledContents(true);

        gridLayout_4->addWidget(label_10, 1, 0, 2, 1);

        course_key_title_text = new QLabel(course_key_area);
        course_key_title_text->setObjectName(QString::fromUtf8("course_key_title_text"));
        course_key_title_text->setFont(font);
        course_key_title_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #666666;\n"
"}"));
        course_key_title_text->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(course_key_title_text, 2, 2, 1, 1);

        couse_key_text = new QLabel(course_key_area);
        couse_key_text->setObjectName(QString::fromUtf8("couse_key_text"));
        couse_key_text->setFont(font2);
        couse_key_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #6C6FC0;\n"
"}"));
        couse_key_text->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(couse_key_text, 1, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 1, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 1, 1, 1, 1);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_12, 0, 2, 1, 1);


        gridLayout_3->addWidget(course_key_area, 2, 0, 1, 2);

        data_4_area = new QFrame(scrollAreaWidgetContents);
        data_4_area->setObjectName(QString::fromUtf8("data_4_area"));
        data_4_area->setMinimumSize(QSize(155, 100));
        data_4_area->setMaximumSize(QSize(155, 100));
        data_4_area->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #ffffff;\n"
"}"));
        data_4_area->setFrameShape(QFrame::StyledPanel);
        data_4_area->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(data_4_area);
        verticalLayout_3->setSpacing(5);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_9);

        data_4_text = new QLabel(data_4_area);
        data_4_text->setObjectName(QString::fromUtf8("data_4_text"));
        data_4_text->setFont(font2);
        data_4_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #23B7E5;\n"
"}"));
        data_4_text->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(data_4_text);

        title_4_text = new QLabel(data_4_area);
        title_4_text->setObjectName(QString::fromUtf8("title_4_text"));
        title_4_text->setFont(font);
        title_4_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #666666;\n"
"}"));
        title_4_text->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(title_4_text);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_10);


        gridLayout_3->addWidget(data_4_area, 1, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_3, 0, 0, 1, 1);

        verticalSpacer_15 = new QSpacerItem(20, 11, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_9->addItem(verticalSpacer_15, 1, 0, 1, 4);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        emotion_report_chart = new QFrame(scrollAreaWidgetContents);
        emotion_report_chart->setObjectName(QString::fromUtf8("emotion_report_chart"));
        emotion_report_chart->setMinimumSize(QSize(500, 350));
        emotion_report_chart->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #ffffff;\n"
"}"));
        emotion_report_chart->setFrameShape(QFrame::StyledPanel);
        emotion_report_chart->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(emotion_report_chart);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        emotion_report_title_text = new QLabel(emotion_report_chart);
        emotion_report_title_text->setObjectName(QString::fromUtf8("emotion_report_title_text"));
        emotion_report_title_text->setMinimumSize(QSize(0, 30));
        emotion_report_title_text->setMaximumSize(QSize(16777215, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(12);
        emotion_report_title_text->setFont(font3);
        emotion_report_title_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #6C6FC0;\n"
"}"));

        verticalLayout_6->addWidget(emotion_report_title_text);

        emotion_report_tips_text = new QLabel(emotion_report_chart);
        emotion_report_tips_text->setObjectName(QString::fromUtf8("emotion_report_tips_text"));
        emotion_report_tips_text->setFont(font);
        emotion_report_tips_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));

        verticalLayout_6->addWidget(emotion_report_tips_text);

        emotion_report_line_chart_widget = new QWidget(emotion_report_chart);
        emotion_report_line_chart_widget->setObjectName(QString::fromUtf8("emotion_report_line_chart_widget"));
        emotion_report_line_chart_widget->setMinimumSize(QSize(0, 270));
        emotion_report_line_chart_widget->setMaximumSize(QSize(16777215, 270));
        emotion_report_line_chart_widget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_6->addWidget(emotion_report_line_chart_widget);


        horizontalLayout_2->addWidget(emotion_report_chart);

        emotion_report_percentage_chart = new QFrame(scrollAreaWidgetContents);
        emotion_report_percentage_chart->setObjectName(QString::fromUtf8("emotion_report_percentage_chart"));
        emotion_report_percentage_chart->setMinimumSize(QSize(280, 350));
        emotion_report_percentage_chart->setMaximumSize(QSize(280, 350));
        emotion_report_percentage_chart->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #E4E9EC;\n"
"}"));
        emotion_report_percentage_chart->setFrameShape(QFrame::StyledPanel);
        emotion_report_percentage_chart->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(emotion_report_percentage_chart);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        disgust_btn = new QPushButton(emotion_report_percentage_chart);
        buttonGroup = new QButtonGroup(TeacherCourseWidget);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(disgust_btn);
        disgust_btn->setObjectName(QString::fromUtf8("disgust_btn"));
        disgust_btn->setMinimumSize(QSize(20, 0));
        disgust_btn->setMaximumSize(QSize(20, 16777215));
        disgust_btn->setCursor(QCursor(Qt::PointingHandCursor));
        disgust_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	background: none;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/button/Resources/material/button/disgust.png"), QSize(), QIcon::Normal, QIcon::Off);
        disgust_btn->setIcon(icon);
        disgust_btn->setIconSize(QSize(20, 20));
        disgust_btn->setCheckable(true);

        gridLayout_7->addWidget(disgust_btn, 4, 0, 1, 1);

        label_122 = new QLabel(emotion_report_percentage_chart);
        label_122->setObjectName(QString::fromUtf8("label_122"));

        gridLayout_7->addWidget(label_122, 6, 4, 1, 1);

        neutral_btn = new QPushButton(emotion_report_percentage_chart);
        buttonGroup->addButton(neutral_btn);
        neutral_btn->setObjectName(QString::fromUtf8("neutral_btn"));
        neutral_btn->setMinimumSize(QSize(20, 0));
        neutral_btn->setMaximumSize(QSize(20, 16777215));
        neutral_btn->setCursor(QCursor(Qt::PointingHandCursor));
        neutral_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	background: none;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/button/Resources/material/button/neutral.png"), QSize(), QIcon::Normal, QIcon::Off);
        neutral_btn->setIcon(icon1);
        neutral_btn->setIconSize(QSize(20, 20));
        neutral_btn->setCheckable(true);

        gridLayout_7->addWidget(neutral_btn, 14, 0, 1, 1);

        label_103 = new QLabel(emotion_report_percentage_chart);
        label_103->setObjectName(QString::fromUtf8("label_103"));

        gridLayout_7->addWidget(label_103, 10, 6, 1, 1);

        label_119 = new QLabel(emotion_report_percentage_chart);
        label_119->setObjectName(QString::fromUtf8("label_119"));

        gridLayout_7->addWidget(label_119, 2, 4, 1, 1);

        fear_btn = new QPushButton(emotion_report_percentage_chart);
        buttonGroup->addButton(fear_btn);
        fear_btn->setObjectName(QString::fromUtf8("fear_btn"));
        fear_btn->setMinimumSize(QSize(20, 0));
        fear_btn->setMaximumSize(QSize(20, 16777215));
        fear_btn->setCursor(QCursor(Qt::PointingHandCursor));
        fear_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	background: none;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/button/Resources/material/button/fear.png"), QSize(), QIcon::Normal, QIcon::Off);
        fear_btn->setIcon(icon2);
        fear_btn->setIconSize(QSize(20, 20));
        fear_btn->setCheckable(true);

        gridLayout_7->addWidget(fear_btn, 6, 0, 1, 1);

        label_99 = new QLabel(emotion_report_percentage_chart);
        label_99->setObjectName(QString::fromUtf8("label_99"));

        gridLayout_7->addWidget(label_99, 12, 6, 1, 1);

        label_89 = new QLabel(emotion_report_percentage_chart);
        label_89->setObjectName(QString::fromUtf8("label_89"));

        gridLayout_7->addWidget(label_89, 8, 6, 1, 1);

        neutral_times_text = new QLabel(emotion_report_percentage_chart);
        neutral_times_text->setObjectName(QString::fromUtf8("neutral_times_text"));
        neutral_times_text->setMinimumSize(QSize(25, 0));
        neutral_times_text->setMaximumSize(QSize(25, 16777215));
        neutral_times_text->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(neutral_times_text, 14, 3, 1, 1);

        fear_times_text = new QLabel(emotion_report_percentage_chart);
        fear_times_text->setObjectName(QString::fromUtf8("fear_times_text"));
        fear_times_text->setMinimumSize(QSize(25, 0));
        fear_times_text->setMaximumSize(QSize(25, 16777215));
        fear_times_text->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(fear_times_text, 6, 3, 1, 1);

        fear_title_text = new QLabel(emotion_report_percentage_chart);
        fear_title_text->setObjectName(QString::fromUtf8("fear_title_text"));
        fear_title_text->setFont(font);

        gridLayout_7->addWidget(fear_title_text, 6, 1, 1, 1);

        fear_progressBar = new QProgressBar(emotion_report_percentage_chart);
        fear_progressBar->setObjectName(QString::fromUtf8("fear_progressBar"));
        fear_progressBar->setMinimumSize(QSize(0, 8));
        fear_progressBar->setMaximumSize(QSize(16777215, 8));
        fear_progressBar->setStyleSheet(QString::fromUtf8("QProgressBar{\n"
"        border: none;\n"
"		border-radius: 4px;\n"
"        color: black;\n"
"        text-align: right;\n"
"        background: #ffffff;\n"
"}\n"
"QProgressBar::chunk {\n"
"        border: none;\n"
"		border-radius: 4px;\n"
"        background: #F9D31A;\n"
"}"));
        fear_progressBar->setValue(43);
        fear_progressBar->setTextVisible(false);

        gridLayout_7->addWidget(fear_progressBar, 7, 0, 1, 7);

        happy_progressBar = new QProgressBar(emotion_report_percentage_chart);
        happy_progressBar->setObjectName(QString::fromUtf8("happy_progressBar"));
        happy_progressBar->setMinimumSize(QSize(0, 8));
        happy_progressBar->setMaximumSize(QSize(16777215, 8));
        happy_progressBar->setStyleSheet(QString::fromUtf8("QProgressBar{\n"
"        border: none;\n"
"		border-radius: 4px;\n"
"        color: black;\n"
"        text-align: right;\n"
"        background: #ffffff;\n"
"}\n"
"QProgressBar::chunk {\n"
"        border: none;\n"
"		border-radius: 4px;\n"
"        background: #24AD1D;\n"
"}"));
        happy_progressBar->setValue(43);
        happy_progressBar->setTextVisible(false);

        gridLayout_7->addWidget(happy_progressBar, 9, 0, 1, 7);

        disgust_percent_text = new QLabel(emotion_report_percentage_chart);
        disgust_percent_text->setObjectName(QString::fromUtf8("disgust_percent_text"));
        disgust_percent_text->setMinimumSize(QSize(20, 0));
        disgust_percent_text->setMaximumSize(QSize(20, 16777215));

        gridLayout_7->addWidget(disgust_percent_text, 4, 5, 1, 1);

        sad_times_text = new QLabel(emotion_report_percentage_chart);
        sad_times_text->setObjectName(QString::fromUtf8("sad_times_text"));
        sad_times_text->setMinimumSize(QSize(25, 0));
        sad_times_text->setMaximumSize(QSize(25, 16777215));
        sad_times_text->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(sad_times_text, 10, 3, 1, 1);

        disgust_progressBar = new QProgressBar(emotion_report_percentage_chart);
        disgust_progressBar->setObjectName(QString::fromUtf8("disgust_progressBar"));
        disgust_progressBar->setMinimumSize(QSize(0, 8));
        disgust_progressBar->setMaximumSize(QSize(16777215, 8));
        disgust_progressBar->setStyleSheet(QString::fromUtf8("QProgressBar{\n"
"        border: none;\n"
"		border-radius: 4px;\n"
"        color: black;\n"
"        text-align: right;\n"
"        background: #ffffff;\n"
"}\n"
"QProgressBar::chunk {\n"
"        border: none;\n"
"		border-radius: 4px;\n"
"        background: #23B7E5;\n"
"}"));
        disgust_progressBar->setValue(43);
        disgust_progressBar->setTextVisible(false);

        gridLayout_7->addWidget(disgust_progressBar, 5, 0, 1, 7);

        angry_title_text = new QLabel(emotion_report_percentage_chart);
        angry_title_text->setObjectName(QString::fromUtf8("angry_title_text"));
        angry_title_text->setFont(font);

        gridLayout_7->addWidget(angry_title_text, 2, 1, 1, 1);

        surprise_title_text = new QLabel(emotion_report_percentage_chart);
        surprise_title_text->setObjectName(QString::fromUtf8("surprise_title_text"));
        surprise_title_text->setFont(font);

        gridLayout_7->addWidget(surprise_title_text, 12, 1, 1, 1);

        label_88 = new QLabel(emotion_report_percentage_chart);
        label_88->setObjectName(QString::fromUtf8("label_88"));

        gridLayout_7->addWidget(label_88, 10, 4, 1, 1);

        happy_times_text = new QLabel(emotion_report_percentage_chart);
        happy_times_text->setObjectName(QString::fromUtf8("happy_times_text"));
        happy_times_text->setMinimumSize(QSize(25, 0));
        happy_times_text->setMaximumSize(QSize(25, 16777215));
        happy_times_text->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(happy_times_text, 8, 3, 1, 1);

        angry_percent_text = new QLabel(emotion_report_percentage_chart);
        angry_percent_text->setObjectName(QString::fromUtf8("angry_percent_text"));
        angry_percent_text->setMinimumSize(QSize(20, 0));
        angry_percent_text->setMaximumSize(QSize(20, 16777215));

        gridLayout_7->addWidget(angry_percent_text, 2, 5, 1, 1);

        disgust_times_text = new QLabel(emotion_report_percentage_chart);
        disgust_times_text->setObjectName(QString::fromUtf8("disgust_times_text"));
        disgust_times_text->setMinimumSize(QSize(25, 0));
        disgust_times_text->setMaximumSize(QSize(25, 16777215));
        disgust_times_text->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(disgust_times_text, 4, 3, 1, 1);

        happy_percent_text = new QLabel(emotion_report_percentage_chart);
        happy_percent_text->setObjectName(QString::fromUtf8("happy_percent_text"));
        happy_percent_text->setMinimumSize(QSize(20, 0));
        happy_percent_text->setMaximumSize(QSize(20, 16777215));

        gridLayout_7->addWidget(happy_percent_text, 8, 5, 1, 1);

        label_123 = new QLabel(emotion_report_percentage_chart);
        label_123->setObjectName(QString::fromUtf8("label_123"));
        label_123->setFont(font);
        label_123->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));

        gridLayout_7->addWidget(label_123, 1, 0, 1, 4);

        label_91 = new QLabel(emotion_report_percentage_chart);
        label_91->setObjectName(QString::fromUtf8("label_91"));

        gridLayout_7->addWidget(label_91, 2, 6, 1, 1);

        surprise_percent_text = new QLabel(emotion_report_percentage_chart);
        surprise_percent_text->setObjectName(QString::fromUtf8("surprise_percent_text"));
        surprise_percent_text->setMinimumSize(QSize(20, 0));
        surprise_percent_text->setMaximumSize(QSize(20, 16777215));

        gridLayout_7->addWidget(surprise_percent_text, 12, 5, 1, 1);

        neutral_progressBar = new QProgressBar(emotion_report_percentage_chart);
        neutral_progressBar->setObjectName(QString::fromUtf8("neutral_progressBar"));
        neutral_progressBar->setMinimumSize(QSize(0, 8));
        neutral_progressBar->setMaximumSize(QSize(16777215, 8));
        neutral_progressBar->setStyleSheet(QString::fromUtf8("QProgressBar{\n"
"        border: none;\n"
"		border-radius: 4px;\n"
"        color: black;\n"
"        text-align: right;\n"
"        background: #ffffff;\n"
"}\n"
"QProgressBar::chunk {\n"
"        border: none;\n"
"		border-radius: 4px;\n"
"        background: rgb(0, 160, 230);\n"
"}"));
        neutral_progressBar->setValue(43);
        neutral_progressBar->setTextVisible(false);

        gridLayout_7->addWidget(neutral_progressBar, 15, 0, 1, 7);

        happy_title_text = new QLabel(emotion_report_percentage_chart);
        happy_title_text->setObjectName(QString::fromUtf8("happy_title_text"));
        happy_title_text->setFont(font);

        gridLayout_7->addWidget(happy_title_text, 8, 1, 1, 1);

        label_111 = new QLabel(emotion_report_percentage_chart);
        label_111->setObjectName(QString::fromUtf8("label_111"));

        gridLayout_7->addWidget(label_111, 6, 6, 1, 1);

        surprise_btn = new QPushButton(emotion_report_percentage_chart);
        buttonGroup->addButton(surprise_btn);
        surprise_btn->setObjectName(QString::fromUtf8("surprise_btn"));
        surprise_btn->setMinimumSize(QSize(20, 0));
        surprise_btn->setMaximumSize(QSize(20, 16777215));
        surprise_btn->setCursor(QCursor(Qt::PointingHandCursor));
        surprise_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	background: none;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/button/Resources/material/button/surprise.png"), QSize(), QIcon::Normal, QIcon::Off);
        surprise_btn->setIcon(icon3);
        surprise_btn->setIconSize(QSize(20, 20));
        surprise_btn->setCheckable(true);

        gridLayout_7->addWidget(surprise_btn, 12, 0, 1, 1);

        angry_btn = new QPushButton(emotion_report_percentage_chart);
        buttonGroup->addButton(angry_btn);
        angry_btn->setObjectName(QString::fromUtf8("angry_btn"));
        angry_btn->setMinimumSize(QSize(20, 0));
        angry_btn->setMaximumSize(QSize(20, 16777215));
        angry_btn->setCursor(QCursor(Qt::PointingHandCursor));
        angry_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	background: none;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/button/Resources/material/button/angry.png"), QSize(), QIcon::Normal, QIcon::Off);
        angry_btn->setIcon(icon4);
        angry_btn->setIconSize(QSize(20, 20));
        angry_btn->setCheckable(true);

        gridLayout_7->addWidget(angry_btn, 2, 0, 1, 1);

        angry_progressBar = new QProgressBar(emotion_report_percentage_chart);
        angry_progressBar->setObjectName(QString::fromUtf8("angry_progressBar"));
        angry_progressBar->setMinimumSize(QSize(0, 8));
        angry_progressBar->setMaximumSize(QSize(16777215, 8));
        angry_progressBar->setStyleSheet(QString::fromUtf8("QProgressBar{\n"
"        border: none;\n"
"		border-radius: 4px;\n"
"        color: black;\n"
"        text-align: right;\n"
"        background: #ffffff;\n"
"}\n"
"QProgressBar::chunk {\n"
"        border: none;\n"
"		border-radius: 4px;\n"
"        background: #6C6FC0;\n"
"}"));
        angry_progressBar->setValue(43);
        angry_progressBar->setTextVisible(false);

        gridLayout_7->addWidget(angry_progressBar, 3, 0, 1, 7);

        sad_percent_text = new QLabel(emotion_report_percentage_chart);
        sad_percent_text->setObjectName(QString::fromUtf8("sad_percent_text"));
        sad_percent_text->setMinimumSize(QSize(20, 0));
        sad_percent_text->setMaximumSize(QSize(20, 16777215));

        gridLayout_7->addWidget(sad_percent_text, 10, 5, 1, 1);

        neutral_title_text = new QLabel(emotion_report_percentage_chart);
        neutral_title_text->setObjectName(QString::fromUtf8("neutral_title_text"));
        neutral_title_text->setFont(font);

        gridLayout_7->addWidget(neutral_title_text, 14, 1, 1, 1);

        label_112 = new QLabel(emotion_report_percentage_chart);
        label_112->setObjectName(QString::fromUtf8("label_112"));

        gridLayout_7->addWidget(label_112, 4, 6, 1, 1);

        label_102 = new QLabel(emotion_report_percentage_chart);
        label_102->setObjectName(QString::fromUtf8("label_102"));

        gridLayout_7->addWidget(label_102, 4, 4, 1, 1);

        label_116 = new QLabel(emotion_report_percentage_chart);
        label_116->setObjectName(QString::fromUtf8("label_116"));

        gridLayout_7->addWidget(label_116, 14, 6, 1, 1);

        label_92 = new QLabel(emotion_report_percentage_chart);
        label_92->setObjectName(QString::fromUtf8("label_92"));

        gridLayout_7->addWidget(label_92, 14, 4, 1, 1);

        fear_percent_text = new QLabel(emotion_report_percentage_chart);
        fear_percent_text->setObjectName(QString::fromUtf8("fear_percent_text"));
        fear_percent_text->setMinimumSize(QSize(20, 0));
        fear_percent_text->setMaximumSize(QSize(20, 16777215));

        gridLayout_7->addWidget(fear_percent_text, 6, 5, 1, 1);

        surprise_progressBar = new QProgressBar(emotion_report_percentage_chart);
        surprise_progressBar->setObjectName(QString::fromUtf8("surprise_progressBar"));
        surprise_progressBar->setMinimumSize(QSize(0, 8));
        surprise_progressBar->setMaximumSize(QSize(16777215, 8));
        surprise_progressBar->setStyleSheet(QString::fromUtf8("QProgressBar{\n"
"        border: none;\n"
"		border-radius: 4px;\n"
"        color: black;\n"
"        text-align: right;\n"
"        background: #ffffff;\n"
"}\n"
"QProgressBar::chunk {\n"
"        border: none;\n"
"		border-radius: 4px;\n"
"        background: #393E51;\n"
"}"));
        surprise_progressBar->setValue(43);
        surprise_progressBar->setTextVisible(false);

        gridLayout_7->addWidget(surprise_progressBar, 13, 0, 1, 7);

        label_106 = new QLabel(emotion_report_percentage_chart);
        label_106->setObjectName(QString::fromUtf8("label_106"));

        gridLayout_7->addWidget(label_106, 12, 4, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_7, 2, 2, 1, 1);

        happy_btn = new QPushButton(emotion_report_percentage_chart);
        buttonGroup->addButton(happy_btn);
        happy_btn->setObjectName(QString::fromUtf8("happy_btn"));
        happy_btn->setMinimumSize(QSize(20, 0));
        happy_btn->setMaximumSize(QSize(20, 16777215));
        happy_btn->setCursor(QCursor(Qt::PointingHandCursor));
        happy_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	background: none;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/button/Resources/material/button/happy.png"), QSize(), QIcon::Normal, QIcon::Off);
        happy_btn->setIcon(icon5);
        happy_btn->setIconSize(QSize(20, 20));
        happy_btn->setCheckable(true);

        gridLayout_7->addWidget(happy_btn, 8, 0, 1, 1);

        angry_times_text = new QLabel(emotion_report_percentage_chart);
        angry_times_text->setObjectName(QString::fromUtf8("angry_times_text"));
        angry_times_text->setMinimumSize(QSize(25, 0));
        angry_times_text->setMaximumSize(QSize(25, 16777215));
        angry_times_text->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(angry_times_text, 2, 3, 1, 1);

        sad_title_text = new QLabel(emotion_report_percentage_chart);
        sad_title_text->setObjectName(QString::fromUtf8("sad_title_text"));
        sad_title_text->setFont(font);

        gridLayout_7->addWidget(sad_title_text, 10, 1, 1, 1);

        disgust_title_text = new QLabel(emotion_report_percentage_chart);
        disgust_title_text->setObjectName(QString::fromUtf8("disgust_title_text"));
        disgust_title_text->setFont(font);

        gridLayout_7->addWidget(disgust_title_text, 4, 1, 1, 1);

        label_120 = new QLabel(emotion_report_percentage_chart);
        label_120->setObjectName(QString::fromUtf8("label_120"));

        gridLayout_7->addWidget(label_120, 8, 4, 1, 1);

        sad_progressBar = new QProgressBar(emotion_report_percentage_chart);
        sad_progressBar->setObjectName(QString::fromUtf8("sad_progressBar"));
        sad_progressBar->setMinimumSize(QSize(0, 8));
        sad_progressBar->setMaximumSize(QSize(16777215, 8));
        sad_progressBar->setStyleSheet(QString::fromUtf8("QProgressBar{\n"
"        border: none;\n"
"		border-radius: 4px;\n"
"        color: black;\n"
"        text-align: right;\n"
"        background: #ffffff;\n"
"}\n"
"QProgressBar::chunk {\n"
"        border: none;\n"
"		border-radius: 4px;\n"
"        background: #F05050;\n"
"}"));
        sad_progressBar->setValue(43);
        sad_progressBar->setTextVisible(false);

        gridLayout_7->addWidget(sad_progressBar, 11, 0, 1, 7);

        sad_btn = new QPushButton(emotion_report_percentage_chart);
        buttonGroup->addButton(sad_btn);
        sad_btn->setObjectName(QString::fromUtf8("sad_btn"));
        sad_btn->setMinimumSize(QSize(20, 0));
        sad_btn->setMaximumSize(QSize(20, 16777215));
        sad_btn->setCursor(QCursor(Qt::PointingHandCursor));
        sad_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	background: none;\n"
"}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/button/Resources/material/button/sad.png"), QSize(), QIcon::Normal, QIcon::Off);
        sad_btn->setIcon(icon6);
        sad_btn->setIconSize(QSize(20, 20));
        sad_btn->setCheckable(true);

        gridLayout_7->addWidget(sad_btn, 10, 0, 1, 1);

        surprise_times_text = new QLabel(emotion_report_percentage_chart);
        surprise_times_text->setObjectName(QString::fromUtf8("surprise_times_text"));
        surprise_times_text->setMinimumSize(QSize(25, 0));
        surprise_times_text->setMaximumSize(QSize(25, 16777215));
        surprise_times_text->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(surprise_times_text, 12, 3, 1, 1);

        neutral_percent_text = new QLabel(emotion_report_percentage_chart);
        neutral_percent_text->setObjectName(QString::fromUtf8("neutral_percent_text"));
        neutral_percent_text->setMinimumSize(QSize(20, 0));
        neutral_percent_text->setMaximumSize(QSize(20, 16777215));

        gridLayout_7->addWidget(neutral_percent_text, 14, 5, 1, 1);

        verticalSpacer_14 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_14, 0, 0, 1, 7);

        verticalSpacer_13 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_13, 16, 0, 1, 7);


        horizontalLayout_2->addWidget(emotion_report_percentage_chart);


        gridLayout_6->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_6, 2, 0, 1, 4);

        verticalSpacer_16 = new QSpacerItem(20, 11, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_9->addItem(verticalSpacer_16, 3, 0, 1, 4);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(0);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        distribution_chart = new QFrame(scrollAreaWidgetContents);
        distribution_chart->setObjectName(QString::fromUtf8("distribution_chart"));
        distribution_chart->setMinimumSize(QSize(782, 350));
        distribution_chart->setMaximumSize(QSize(16777215, 350));
        distribution_chart->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #ffffff;\n"
"}"));
        distribution_chart->setFrameShape(QFrame::StyledPanel);
        distribution_chart->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(distribution_chart);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(9, 9, 9, 9);
        label = new QLabel(distribution_chart);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));

        verticalLayout_7->addWidget(label);

        distribution_chart_widget = new QWidget(distribution_chart);
        distribution_chart_widget->setObjectName(QString::fromUtf8("distribution_chart_widget"));
        distribution_chart_widget->setMinimumSize(QSize(0, 300));
        distribution_chart_widget->setMaximumSize(QSize(16777215, 300));
        distribution_chart_widget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_7->addWidget(distribution_chart_widget);


        gridLayout_8->addWidget(distribution_chart, 1, 0, 1, 1);

        distribution_chart_progressBar = new QFrame(scrollAreaWidgetContents);
        distribution_chart_progressBar->setObjectName(QString::fromUtf8("distribution_chart_progressBar"));
        distribution_chart_progressBar->setMinimumSize(QSize(782, 165));
        distribution_chart_progressBar->setMaximumSize(QSize(16777215, 165));
        distribution_chart_progressBar->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #F9FAFC;\n"
"}"));
        distribution_chart_progressBar->setFrameShape(QFrame::StyledPanel);
        distribution_chart_progressBar->setFrameShadow(QFrame::Raised);
        gridLayout_10 = new QGridLayout(distribution_chart_progressBar);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label_97 = new QLabel(distribution_chart_progressBar);
        label_97->setObjectName(QString::fromUtf8("label_97"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(9);
        label_97->setFont(font4);
        label_97->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));

        gridLayout_10->addWidget(label_97, 5, 0, 1, 1);

        label_95 = new QLabel(distribution_chart_progressBar);
        label_95->setObjectName(QString::fromUtf8("label_95"));
        label_95->setFont(font4);
        label_95->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));

        gridLayout_10->addWidget(label_95, 3, 0, 1, 1);

        label_93 = new QLabel(distribution_chart_progressBar);
        label_93->setObjectName(QString::fromUtf8("label_93"));
        label_93->setFont(font);
        label_93->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #666666;\n"
"}"));
        label_93->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_93, 6, 1, 1, 1);

        progressBar_17 = new QProgressBar(distribution_chart_progressBar);
        progressBar_17->setObjectName(QString::fromUtf8("progressBar_17"));
        progressBar_17->setMinimumSize(QSize(50, 100));
        progressBar_17->setMaximumSize(QSize(50, 100));
        progressBar_17->setFont(font3);
        progressBar_17->setStyleSheet(QString::fromUtf8("QProgressBar{\n"
"        border: none;\n"
"        color: #666666;\n"
"        text-align: top;\n"
"        background-color: #F9FAFC;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"        border: none;\n"
"        background: #24AD1D;\n"
"}"));
        progressBar_17->setValue(25);
        progressBar_17->setTextVisible(true);
        progressBar_17->setOrientation(Qt::Vertical);
        progressBar_17->setTextDirection(QProgressBar::TopToBottom);

        gridLayout_10->addWidget(progressBar_17, 1, 1, 5, 1);

        excellent_progressBar = new QProgressBar(distribution_chart_progressBar);
        excellent_progressBar->setObjectName(QString::fromUtf8("excellent_progressBar"));
        excellent_progressBar->setMinimumSize(QSize(50, 100));
        excellent_progressBar->setMaximumSize(QSize(50, 100));
        excellent_progressBar->setFont(font3);
        excellent_progressBar->setStyleSheet(QString::fromUtf8("QProgressBar{\n"
"        border: none;\n"
"        color: #666666;\n"
"        text-align: top;\n"
"        background-color: #F9FAFC;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"        border: none;\n"
"        background: #F9D31A;\n"
"}"));
        excellent_progressBar->setValue(50);
        excellent_progressBar->setTextVisible(true);
        excellent_progressBar->setOrientation(Qt::Vertical);
        excellent_progressBar->setTextDirection(QProgressBar::TopToBottom);

        gridLayout_10->addWidget(excellent_progressBar, 1, 3, 5, 1);

        distribution_chart_title_text = new QLabel(distribution_chart_progressBar);
        distribution_chart_title_text->setObjectName(QString::fromUtf8("distribution_chart_title_text"));
        distribution_chart_title_text->setMinimumSize(QSize(0, 30));
        distribution_chart_title_text->setMaximumSize(QSize(16777215, 30));
        distribution_chart_title_text->setFont(font3);
        distribution_chart_title_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #333333;\n"
"}"));

        gridLayout_10->addWidget(distribution_chart_title_text, 0, 0, 2, 4);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_10, 6, 2, 1, 1);

        label_90 = new QLabel(distribution_chart_progressBar);
        label_90->setObjectName(QString::fromUtf8("label_90"));
        label_90->setFont(font);
        label_90->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #666666;\n"
"}"));
        label_90->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_90, 6, 3, 1, 1);

        bad_progressBar = new QProgressBar(distribution_chart_progressBar);
        bad_progressBar->setObjectName(QString::fromUtf8("bad_progressBar"));
        bad_progressBar->setMinimumSize(QSize(50, 100));
        bad_progressBar->setMaximumSize(QSize(50, 100));
        bad_progressBar->setFont(font3);
        bad_progressBar->setStyleSheet(QString::fromUtf8("QProgressBar{\n"
"        border: none;\n"
"        color: #666666;\n"
"        text-align: top;\n"
"        background-color: #F9FAFC;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"        border: none;\n"
"        background: #F05050;\n"
"}"));
        bad_progressBar->setValue(25);
        bad_progressBar->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        bad_progressBar->setTextVisible(true);
        bad_progressBar->setOrientation(Qt::Vertical);
        bad_progressBar->setInvertedAppearance(false);
        bad_progressBar->setTextDirection(QProgressBar::TopToBottom);

        gridLayout_10->addWidget(bad_progressBar, 1, 5, 5, 1);

        label_96 = new QLabel(distribution_chart_progressBar);
        label_96->setObjectName(QString::fromUtf8("label_96"));
        label_96->setFont(font4);
        label_96->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));

        gridLayout_10->addWidget(label_96, 4, 0, 1, 1);

        label_94 = new QLabel(distribution_chart_progressBar);
        label_94->setObjectName(QString::fromUtf8("label_94"));
        label_94->setFont(font);
        label_94->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #666666;\n"
"}"));
        label_94->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_94, 6, 5, 1, 1);

        label_98 = new QLabel(distribution_chart_progressBar);
        label_98->setObjectName(QString::fromUtf8("label_98"));
        label_98->setFont(font4);
        label_98->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));

        gridLayout_10->addWidget(label_98, 2, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_8, 6, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_9, 6, 6, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_11, 6, 4, 1, 1);


        gridLayout_8->addWidget(distribution_chart_progressBar, 0, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_8, 4, 0, 1, 4);

        area_chart = new QFrame(scrollAreaWidgetContents);
        area_chart->setObjectName(QString::fromUtf8("area_chart"));
        area_chart->setMinimumSize(QSize(435, 310));
        area_chart->setMaximumSize(QSize(16777215, 310));
        area_chart->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #ffffff;\n"
"}"));
        area_chart->setFrameShape(QFrame::StyledPanel);
        area_chart->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(area_chart);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        area_chart_title_text = new QLabel(area_chart);
        area_chart_title_text->setObjectName(QString::fromUtf8("area_chart_title_text"));
        area_chart_title_text->setMinimumSize(QSize(0, 30));
        area_chart_title_text->setMaximumSize(QSize(16777215, 30));
        area_chart_title_text->setFont(font3);
        area_chart_title_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #333333;\n"
"}"));

        verticalLayout_5->addWidget(area_chart_title_text);

        area_chart_widget = new QtCharts::QChartView(area_chart);
        area_chart_widget->setObjectName(QString::fromUtf8("area_chart_widget"));
        area_chart_widget->setMinimumSize(QSize(0, 250));
        area_chart_widget->setMaximumSize(QSize(16777215, 250));
        area_chart_widget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_5->addWidget(area_chart_widget);


        gridLayout_9->addWidget(area_chart, 0, 2, 1, 2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_22->addWidget(scrollArea, 0, 0, 1, 1);

        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/button/Resources/material/button/statistic.png"), QSize(), QIcon::Active, QIcon::Off);
        icon7.addFile(QString::fromUtf8(":/button/Resources/material/button/statistic_checked.png"), QSize(), QIcon::Active, QIcon::On);
        tabWidget->addTab(course_data_tab, icon7, QString());
        course_member_tab = new QWidget();
        course_member_tab->setObjectName(QString::fromUtf8("course_member_tab"));
        course_member_tab->setStyleSheet(QString::fromUtf8(""));
        gridLayout_16 = new QGridLayout(course_member_tab);
        gridLayout_16->setSpacing(0);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setContentsMargins(0, 0, 0, 0);
        scrollArea_2 = new QScrollArea(course_member_tab);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setStyleSheet(QString::fromUtf8("QScrollArea#scrollArea_2 {\n"
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
"/*\344\270\212\347\256\255\345\244\264*/\n"
"QScrollBar::"
                        "sub-line:vertical {\n"
"    height: 0px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}"));
        scrollArea_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 802, 802));
        scrollAreaWidgetContents_2->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color:transparent;\n"
"}"));
        gridLayout_11 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(9, 9, 9, 9);
        gridLayout_17 = new QGridLayout();
        gridLayout_17->setSpacing(15);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        gridLayout_17->setContentsMargins(-1, -1, 0, 0);
        gridLayout_21 = new QGridLayout();
        gridLayout_21->setSpacing(0);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        frame_3 = new QFrame(scrollAreaWidgetContents_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMinimumSize(QSize(313, 160));
        frame_3->setMaximumSize(QSize(16777215, 160));
        frame_3->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #ffffff;\n"
"	border: 1px solid #E8ECEC;\n"
"	border-top: none;\n"
"}"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_9 = new QVBoxLayout(frame_3);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        frame_6 = new QFrame(frame_3);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setMinimumSize(QSize(0, 40));
        frame_6->setMaximumSize(QSize(16777215, 40));
        frame_6->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: none;\n"
"	border: none;\n"
"	border-bottom: 1px solid #E8ECEC;\n"
"}"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(15, -1, 15, -1);
        label_5 = new QLabel(frame_6);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(20, 20));
        label_5->setMaximumSize(QSize(20, 20));
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"}"));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/pic/Resources/material/pic/concentration.png")));
        label_5->setScaledContents(true);

        horizontalLayout_4->addWidget(label_5);

        label_4 = new QLabel(frame_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #666666;\n"
"}"));

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_17);

        concentration_text = new QLabel(frame_6);
        concentration_text->setObjectName(QString::fromUtf8("concentration_text"));
        concentration_text->setMinimumSize(QSize(45, 20));
        concentration_text->setMaximumSize(QSize(45, 20));
        concentration_text->setFont(font);
        concentration_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border-radius: 10px;\n"
"	background: green;\n"
"	color: #ffffff;\n"
"}"));
        concentration_text->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(concentration_text);


        verticalLayout_9->addWidget(frame_6);

        frame_7 = new QFrame(frame_3);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setMinimumSize(QSize(0, 40));
        frame_7->setMaximumSize(QSize(16777215, 40));
        frame_7->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: none;\n"
"	border: none;\n"
"	border-bottom: 1px solid #E8ECEC;\n"
"}"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_7);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(15, -1, 15, -1);
        label_7 = new QLabel(frame_7);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(20, 20));
        label_7->setMaximumSize(QSize(20, 20));
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"}"));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/pic/Resources/material/pic/hand.png")));
        label_7->setScaledContents(true);

        horizontalLayout_5->addWidget(label_7);

        label_8 = new QLabel(frame_7);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #666666;\n"
"}"));

        horizontalLayout_5->addWidget(label_8);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_18);

        raise_hand_rate_text = new QLabel(frame_7);
        raise_hand_rate_text->setObjectName(QString::fromUtf8("raise_hand_rate_text"));
        raise_hand_rate_text->setMinimumSize(QSize(45, 20));
        raise_hand_rate_text->setMaximumSize(QSize(45, 20));
        raise_hand_rate_text->setFont(font);
        raise_hand_rate_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border-radius: 10px;\n"
"	background: green;\n"
"	color: #ffffff;\n"
"}"));
        raise_hand_rate_text->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(raise_hand_rate_text);


        verticalLayout_9->addWidget(frame_7);

        frame_8 = new QFrame(frame_3);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setMinimumSize(QSize(0, 40));
        frame_8->setMaximumSize(QSize(16777215, 40));
        frame_8->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: none;\n"
"	border: none;\n"
"	border-bottom: 1px solid #E8ECEC;\n"
"}"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_8);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(15, -1, 15, -1);
        label_11 = new QLabel(frame_8);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(20, 20));
        label_11->setMaximumSize(QSize(20, 20));
        label_11->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"}"));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/pic/Resources/material/pic/excellent.png")));
        label_11->setScaledContents(true);

        horizontalLayout_6->addWidget(label_11);

        label_12 = new QLabel(frame_8);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);
        label_12->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #666666;\n"
"}"));

        horizontalLayout_6->addWidget(label_12);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_19);

        excellent_rate_text = new QLabel(frame_8);
        excellent_rate_text->setObjectName(QString::fromUtf8("excellent_rate_text"));
        excellent_rate_text->setMinimumSize(QSize(45, 20));
        excellent_rate_text->setMaximumSize(QSize(45, 20));
        excellent_rate_text->setFont(font);
        excellent_rate_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border-radius: 10px;\n"
"	background: green;\n"
"	color: #ffffff;\n"
"}"));
        excellent_rate_text->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(excellent_rate_text);


        verticalLayout_9->addWidget(frame_8);

        frame_9 = new QFrame(frame_3);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setMinimumSize(QSize(0, 40));
        frame_9->setMaximumSize(QSize(16777215, 40));
        frame_9->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: none;\n"
"	border: none;\n"
"	border-bottom: 1px solid #E8ECEC;\n"
"}"));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame_9);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(15, -1, 15, -1);
        label_14 = new QLabel(frame_9);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(20, 20));
        label_14->setMaximumSize(QSize(20, 20));
        label_14->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"}"));
        label_14->setPixmap(QPixmap(QString::fromUtf8(":/pic/Resources/material/pic/time.png")));
        label_14->setScaledContents(true);

        horizontalLayout_7->addWidget(label_14);

        label_15 = new QLabel(frame_9);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font);
        label_15->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #666666;\n"
"}"));

        horizontalLayout_7->addWidget(label_15);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_20);

        join_date_text = new QLabel(frame_9);
        join_date_text->setObjectName(QString::fromUtf8("join_date_text"));
        join_date_text->setMinimumSize(QSize(0, 0));
        join_date_text->setMaximumSize(QSize(16777215, 20));
        join_date_text->setFont(font);
        join_date_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border:none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));
        join_date_text->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(join_date_text);


        verticalLayout_9->addWidget(frame_9);


        gridLayout_21->addWidget(frame_3, 1, 0, 1, 1, Qt::AlignTop);

        frame_5 = new QFrame(scrollAreaWidgetContents_2);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setMinimumSize(QSize(313, 80));
        frame_5->setMaximumSize(QSize(16777215, 80));
        frame_5->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #F9FAFC;\n"
"	border: 1px solid #E8ECEC;\n"
"	border-top: none;\n"
"}"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout_23 = new QGridLayout(frame_5);
        gridLayout_23->setObjectName(QString::fromUtf8("gridLayout_23"));
        gridLayout_23->setHorizontalSpacing(10);
        gridLayout_23->setVerticalSpacing(0);
        gridLayout_23->setContentsMargins(10, 10, 10, 10);
        member_name_text = new QLabel(frame_5);
        member_name_text->setObjectName(QString::fromUtf8("member_name_text"));
        member_name_text->setMinimumSize(QSize(0, 0));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(14);
        member_name_text->setFont(font5);
        member_name_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #333333;\n"
"}"));
        member_name_text->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_23->addWidget(member_name_text, 0, 1, 1, 2);

        member_id_text = new QLabel(frame_5);
        member_id_text->setObjectName(QString::fromUtf8("member_id_text"));
        member_id_text->setMinimumSize(QSize(0, 30));
        member_id_text->setFont(font);
        member_id_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));
        member_id_text->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_23->addWidget(member_id_text, 1, 1, 1, 1);

        member_pic = new QLabel(frame_5);
        member_pic->setObjectName(QString::fromUtf8("member_pic"));
        member_pic->setMinimumSize(QSize(60, 60));
        member_pic->setMaximumSize(QSize(60, 60));
        member_pic->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"}"));
        member_pic->setPixmap(QPixmap(QString::fromUtf8(":/pic/Resources/material/pic/student.png")));
        member_pic->setScaledContents(true);

        gridLayout_23->addWidget(member_pic, 0, 0, 1, 1);


        gridLayout_21->addWidget(frame_5, 0, 0, 1, 1);


        gridLayout_17->addLayout(gridLayout_21, 1, 1, 2, 1);

        frame = new QFrame(scrollAreaWidgetContents_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(782, 200));
        frame->setMaximumSize(QSize(16777215, 200));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #ffffff;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_18 = new QGridLayout(frame);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_18->addItem(horizontalSpacer_13, 3, 0, 1, 1);

        frame_15 = new QFrame(frame);
        frame_15->setObjectName(QString::fromUtf8("frame_15"));
        frame_15->setMinimumSize(QSize(80, 80));
        frame_15->setMaximumSize(QSize(80, 80));
        frame_15->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border-radius: 40px;\n"
"	background-color: #23B7E5;\n"
"	\n"
"}"));
        frame_15->setFrameShape(QFrame::StyledPanel);
        frame_15->setFrameShadow(QFrame::Raised);
        frame_16 = new QFrame(frame_15);
        frame_16->setObjectName(QString::fromUtf8("frame_16"));
        frame_16->setGeometry(QRect(5, 5, 70, 70));
        frame_16->setMinimumSize(QSize(70, 70));
        frame_16->setMaximumSize(QSize(70, 70));
        frame_16->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border-radius: 35px;\n"
"	background-color: #ffffff;\n"
"	\n"
"}"));
        frame_16->setFrameShape(QFrame::StyledPanel);
        frame_16->setFrameShadow(QFrame::Raised);
        num_of_student_text = new QLabel(frame_16);
        num_of_student_text->setObjectName(QString::fromUtf8("num_of_student_text"));
        num_of_student_text->setGeometry(QRect(10, 10, 50, 50));
        num_of_student_text->setFont(font2);
        num_of_student_text->setAlignment(Qt::AlignCenter);

        gridLayout_18->addWidget(frame_15, 2, 3, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_18->addItem(horizontalSpacer_16, 3, 4, 1, 1);

        label_100 = new QLabel(frame);
        label_100->setObjectName(QString::fromUtf8("label_100"));
        label_100->setFont(font);
        label_100->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #333333;\n"
"}"));
        label_100->setAlignment(Qt::AlignCenter);

        gridLayout_18->addWidget(label_100, 3, 1, 1, 1);

        label_104 = new QLabel(frame);
        label_104->setObjectName(QString::fromUtf8("label_104"));
        label_104->setFont(font);
        label_104->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #333333;\n"
"}"));
        label_104->setAlignment(Qt::AlignCenter);

        gridLayout_18->addWidget(label_104, 3, 3, 1, 1);

        label_107 = new QLabel(frame);
        label_107->setObjectName(QString::fromUtf8("label_107"));
        label_107->setFont(font4);
        label_107->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));

        gridLayout_18->addWidget(label_107, 1, 0, 1, 1);

        label_109 = new QLabel(frame);
        label_109->setObjectName(QString::fromUtf8("label_109"));
        label_109->setFont(font);
        label_109->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #333333;\n"
"}"));
        label_109->setAlignment(Qt::AlignCenter);

        gridLayout_18->addWidget(label_109, 3, 5, 1, 1);

        frame_17 = new QFrame(frame);
        frame_17->setObjectName(QString::fromUtf8("frame_17"));
        frame_17->setMinimumSize(QSize(80, 80));
        frame_17->setMaximumSize(QSize(80, 80));
        frame_17->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border-radius: 40px;\n"
"	background-color: #E4E9EC;\n"
"	\n"
"}"));
        frame_17->setFrameShape(QFrame::StyledPanel);
        frame_17->setFrameShadow(QFrame::Raised);
        frame_18 = new QFrame(frame_17);
        frame_18->setObjectName(QString::fromUtf8("frame_18"));
        frame_18->setGeometry(QRect(5, 5, 70, 70));
        frame_18->setMinimumSize(QSize(70, 70));
        frame_18->setMaximumSize(QSize(70, 70));
        frame_18->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border-radius: 35px;\n"
"	background-color: #ffffff;\n"
"	\n"
"}"));
        frame_18->setFrameShape(QFrame::StyledPanel);
        frame_18->setFrameShadow(QFrame::Raised);
        total_text = new QLabel(frame_18);
        total_text->setObjectName(QString::fromUtf8("total_text"));
        total_text->setGeometry(QRect(10, 10, 50, 50));
        total_text->setFont(font2);
        total_text->setAlignment(Qt::AlignCenter);

        gridLayout_18->addWidget(frame_17, 2, 5, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_18->addItem(horizontalSpacer_14, 3, 6, 1, 1);

        frame_13 = new QFrame(frame);
        frame_13->setObjectName(QString::fromUtf8("frame_13"));
        frame_13->setMinimumSize(QSize(80, 80));
        frame_13->setMaximumSize(QSize(80, 80));
        frame_13->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border-radius: 40px;\n"
"	background-color: #6C6FC0;\n"
"	\n"
"}"));
        frame_13->setFrameShape(QFrame::StyledPanel);
        frame_13->setFrameShadow(QFrame::Raised);
        frame_14 = new QFrame(frame_13);
        frame_14->setObjectName(QString::fromUtf8("frame_14"));
        frame_14->setGeometry(QRect(5, 5, 70, 70));
        frame_14->setMinimumSize(QSize(70, 70));
        frame_14->setMaximumSize(QSize(70, 70));
        frame_14->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border-radius: 35px;\n"
"	background-color: #ffffff;\n"
"	\n"
"}"));
        frame_14->setFrameShape(QFrame::StyledPanel);
        frame_14->setFrameShadow(QFrame::Raised);
        num_of_teacher_text = new QLabel(frame_14);
        num_of_teacher_text->setObjectName(QString::fromUtf8("num_of_teacher_text"));
        num_of_teacher_text->setGeometry(QRect(10, 10, 50, 50));
        num_of_teacher_text->setFont(font2);
        num_of_teacher_text->setAlignment(Qt::AlignCenter);

        gridLayout_18->addWidget(frame_13, 2, 1, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_18->addItem(horizontalSpacer_15, 3, 2, 1, 1);

        area_chart_title_text_2 = new QLabel(frame);
        area_chart_title_text_2->setObjectName(QString::fromUtf8("area_chart_title_text_2"));
        area_chart_title_text_2->setMinimumSize(QSize(0, 30));
        area_chart_title_text_2->setMaximumSize(QSize(16777215, 30));
        area_chart_title_text_2->setFont(font3);
        area_chart_title_text_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #333333;\n"
"}"));

        gridLayout_18->addWidget(area_chart_title_text_2, 0, 0, 1, 1);

        verticalSpacer_18 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_18->addItem(verticalSpacer_18, 0, 1, 2, 5);

        verticalSpacer_17 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_18->addItem(verticalSpacer_17, 4, 1, 1, 5);


        gridLayout_17->addWidget(frame, 0, 0, 1, 2);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        frame_2 = new QFrame(scrollAreaWidgetContents_2);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(450, 40));
        frame_2->setMaximumSize(QSize(450, 40));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #F6F8F7;\n"
"	border: 1px solid #E8ECEC;\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_2);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(9, 0, 9, 0);
        area_chart_title_text_3 = new QLabel(frame_2);
        area_chart_title_text_3->setObjectName(QString::fromUtf8("area_chart_title_text_3"));
        area_chart_title_text_3->setMinimumSize(QSize(0, 30));
        area_chart_title_text_3->setMaximumSize(QSize(16777215, 30));
        area_chart_title_text_3->setFont(font3);
        area_chart_title_text_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	border: none;\n"
"	color: #333333;\n"
"}"));

        horizontalLayout_3->addWidget(area_chart_title_text_3, 0, Qt::AlignVCenter);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_21);

        pushButton_15 = new QPushButton(frame_2);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        pushButton_15->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/button/Resources/material/button/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_15->setIcon(icon8);
        pushButton_15->setIconSize(QSize(15, 15));

        horizontalLayout_3->addWidget(pushButton_15);


        verticalLayout_8->addWidget(frame_2);

        frame_4 = new QFrame(scrollAreaWidgetContents_2);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setMinimumSize(QSize(450, 300));
        frame_4->setMaximumSize(QSize(450, 16777215));
        frame_4->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #ffffff;\n"
"	border: 1px solid #E8ECEC;\n"
"	border-top: none;\n"
"}"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_24 = new QGridLayout(frame_4);
        gridLayout_24->setSpacing(0);
        gridLayout_24->setObjectName(QString::fromUtf8("gridLayout_24"));
        gridLayout_24->setContentsMargins(0, 0, 0, 0);
        member_table = new QTableWidget(frame_4);
        if (member_table->columnCount() < 3)
            member_table->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        member_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        member_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        member_table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        member_table->setObjectName(QString::fromUtf8("member_table"));
        member_table->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"	border: none;\n"
"}"));

        gridLayout_24->addWidget(member_table, 0, 0, 1, 1);


        verticalLayout_8->addWidget(frame_4);


        gridLayout_17->addLayout(verticalLayout_8, 1, 0, 4, 1);

        frame_10 = new QFrame(scrollAreaWidgetContents_2);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setMinimumSize(QSize(0, 310));
        frame_10->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #ffffff;\n"
"}"));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        verticalLayout_12 = new QVBoxLayout(frame_10);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        area_chart_title_text_4 = new QLabel(frame_10);
        area_chart_title_text_4->setObjectName(QString::fromUtf8("area_chart_title_text_4"));
        area_chart_title_text_4->setMinimumSize(QSize(293, 30));
        area_chart_title_text_4->setMaximumSize(QSize(16777215, 30));
        area_chart_title_text_4->setFont(font3);
        area_chart_title_text_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #333333;\n"
"}"));

        verticalLayout_12->addWidget(area_chart_title_text_4);

        student_area_chart_widget = new QWidget(frame_10);
        student_area_chart_widget->setObjectName(QString::fromUtf8("student_area_chart_widget"));
        student_area_chart_widget->setMinimumSize(QSize(293, 250));
        student_area_chart_widget->setMaximumSize(QSize(16777215, 250));
        student_area_chart_widget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_12->addWidget(student_area_chart_widget);


        gridLayout_17->addWidget(frame_10, 3, 1, 1, 1, Qt::AlignTop);


        gridLayout_11->addLayout(gridLayout_17, 1, 0, 1, 1);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        gridLayout_16->addWidget(scrollArea_2, 0, 0, 1, 1);

        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/button/Resources/material/button/member.png"), QSize(), QIcon::Active, QIcon::Off);
        icon9.addFile(QString::fromUtf8(":/button/Resources/material/button/member_checked.png"), QSize(), QIcon::Active, QIcon::On);
        tabWidget->addTab(course_member_tab, icon9, QString());

        gridLayout_2->addWidget(tabWidget, 1, 0, 1, 1);


        retranslateUi(TeacherCourseWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TeacherCourseWidget);
    } // setupUi

    void retranslateUi(QWidget *TeacherCourseWidget)
    {
        TeacherCourseWidget->setWindowTitle(QCoreApplication::translate("TeacherCourseWidget", "Form", nullptr));
        create_date_text->setText(QCoreApplication::translate("TeacherCourseWidget", " \345\210\233\345\273\272\344\272\2162019-08-12", nullptr));
        pushButton_17->setText(QCoreApplication::translate("TeacherCourseWidget", "\345\212\240\345\205\245\350\257\276\347\250\213", nullptr));
        pushButton_16->setText(QCoreApplication::translate("TeacherCourseWidget", "\345\210\233\345\273\272\350\257\276\347\250\213", nullptr));
        courses_comboBox->setItemText(0, QCoreApplication::translate("TeacherCourseWidget", "\346\246\202\347\216\207\350\256\272\344\270\216\346\225\260\347\220\206\347\273\237\350\256\241", nullptr));

        create_time_text_2->setText(QCoreApplication::translate("TeacherCourseWidget", "id: ", nullptr));
        delete_course_btn->setText(QCoreApplication::translate("TeacherCourseWidget", " \345\210\240\351\231\244\350\257\276\347\250\213", nullptr));
        course_id_text->setText(QCoreApplication::translate("TeacherCourseWidget", "12312312", nullptr));
        data_2_text->setText(QCoreApplication::translate("TeacherCourseWidget", "6", nullptr));
        title_2_text->setText(QCoreApplication::translate("TeacherCourseWidget", "\345\267\262\344\270\212\350\257\276\346\254\241\346\225\260", nullptr));
        data_1_text->setText(QCoreApplication::translate("TeacherCourseWidget", "521", nullptr));
        title_1_text->setText(QCoreApplication::translate("TeacherCourseWidget", "\344\272\272\346\225\260", nullptr));
        data_3_text->setText(QCoreApplication::translate("TeacherCourseWidget", "87", nullptr));
        title_3_text->setText(QCoreApplication::translate("TeacherCourseWidget", "\345\271\263\345\235\207\344\270\223\346\263\250\345\272\246", nullptr));
        label_10->setText(QString());
        course_key_title_text->setText(QCoreApplication::translate("TeacherCourseWidget", "\350\257\276\347\250\213\351\200\211\350\257\276\347\240\201", nullptr));
        couse_key_text->setText(QCoreApplication::translate("TeacherCourseWidget", "jaskne12421", nullptr));
        data_4_text->setText(QCoreApplication::translate("TeacherCourseWidget", "879", nullptr));
        title_4_text->setText(QCoreApplication::translate("TeacherCourseWidget", "\347\202\271\350\265\236\346\225\260", nullptr));
        emotion_report_title_text->setText(QCoreApplication::translate("TeacherCourseWidget", "\342\227\217  \345\255\246\347\224\237\350\241\250\346\203\205\346\225\260\346\215\256\346\212\245\345\221\212", nullptr));
        emotion_report_tips_text->setText(QCoreApplication::translate("TeacherCourseWidget", "\347\202\271\345\207\273\345\217\263\344\276\247\344\270\215\345\220\214\350\241\250\346\203\205\345\217\257\344\273\245\346\237\245\347\234\213\345\205\266\346\225\260\346\215\256\346\212\245\350\241\250", nullptr));
        disgust_btn->setText(QString());
        label_122->setText(QCoreApplication::translate("TeacherCourseWidget", "\346\254\241", nullptr));
        neutral_btn->setText(QString());
        label_103->setText(QCoreApplication::translate("TeacherCourseWidget", "%", nullptr));
        label_119->setText(QCoreApplication::translate("TeacherCourseWidget", "\346\254\241", nullptr));
        fear_btn->setText(QString());
        label_99->setText(QCoreApplication::translate("TeacherCourseWidget", "%", nullptr));
        label_89->setText(QCoreApplication::translate("TeacherCourseWidget", "%", nullptr));
        neutral_times_text->setText(QCoreApplication::translate("TeacherCourseWidget", "503", nullptr));
        fear_times_text->setText(QCoreApplication::translate("TeacherCourseWidget", "503", nullptr));
        fear_title_text->setText(QCoreApplication::translate("TeacherCourseWidget", "\346\201\220\346\203\247", nullptr));
        disgust_percent_text->setText(QCoreApplication::translate("TeacherCourseWidget", "100", nullptr));
        sad_times_text->setText(QCoreApplication::translate("TeacherCourseWidget", "503", nullptr));
        angry_title_text->setText(QCoreApplication::translate("TeacherCourseWidget", "\347\224\237\346\260\224", nullptr));
        surprise_title_text->setText(QCoreApplication::translate("TeacherCourseWidget", "\346\203\212\350\256\266", nullptr));
        label_88->setText(QCoreApplication::translate("TeacherCourseWidget", "\346\254\241", nullptr));
        happy_times_text->setText(QCoreApplication::translate("TeacherCourseWidget", "503", nullptr));
        angry_percent_text->setText(QCoreApplication::translate("TeacherCourseWidget", "100", nullptr));
        disgust_times_text->setText(QCoreApplication::translate("TeacherCourseWidget", "503", nullptr));
        happy_percent_text->setText(QCoreApplication::translate("TeacherCourseWidget", "100", nullptr));
        label_123->setText(QCoreApplication::translate("TeacherCourseWidget", "\345\220\204\350\241\250\346\203\205\345\207\272\347\216\260\346\257\224\344\276\213\345\217\212\346\254\241\346\225\260", nullptr));
        label_91->setText(QCoreApplication::translate("TeacherCourseWidget", "%", nullptr));
        surprise_percent_text->setText(QCoreApplication::translate("TeacherCourseWidget", "100", nullptr));
        happy_title_text->setText(QCoreApplication::translate("TeacherCourseWidget", "\351\253\230\345\205\264", nullptr));
        label_111->setText(QCoreApplication::translate("TeacherCourseWidget", "%", nullptr));
        surprise_btn->setText(QString());
        angry_btn->setText(QString());
        sad_percent_text->setText(QCoreApplication::translate("TeacherCourseWidget", "100", nullptr));
        neutral_title_text->setText(QCoreApplication::translate("TeacherCourseWidget", "\345\271\263\346\267\241", nullptr));
        label_112->setText(QCoreApplication::translate("TeacherCourseWidget", "%", nullptr));
        label_102->setText(QCoreApplication::translate("TeacherCourseWidget", "\346\254\241", nullptr));
        label_116->setText(QCoreApplication::translate("TeacherCourseWidget", "%", nullptr));
        label_92->setText(QCoreApplication::translate("TeacherCourseWidget", "\346\254\241", nullptr));
        fear_percent_text->setText(QCoreApplication::translate("TeacherCourseWidget", "100", nullptr));
        label_106->setText(QCoreApplication::translate("TeacherCourseWidget", "\346\254\241", nullptr));
        happy_btn->setText(QString());
        angry_times_text->setText(QCoreApplication::translate("TeacherCourseWidget", "503", nullptr));
        sad_title_text->setText(QCoreApplication::translate("TeacherCourseWidget", "\344\274\244\345\277\203", nullptr));
        disgust_title_text->setText(QCoreApplication::translate("TeacherCourseWidget", "\345\216\214\346\201\266", nullptr));
        label_120->setText(QCoreApplication::translate("TeacherCourseWidget", "\346\254\241", nullptr));
        sad_btn->setText(QString());
        surprise_times_text->setText(QCoreApplication::translate("TeacherCourseWidget", "503", nullptr));
        neutral_percent_text->setText(QCoreApplication::translate("TeacherCourseWidget", "100", nullptr));
        label->setText(QCoreApplication::translate("TeacherCourseWidget", "\345\210\206\345\270\203\346\233\262\347\272\277", nullptr));
        label_97->setText(QCoreApplication::translate("TeacherCourseWidget", "\342\200\234\345\267\256\345\212\262\342\200\235\344\270\272\345\260\217\344\272\21660", nullptr));
        label_95->setText(QCoreApplication::translate("TeacherCourseWidget", "\342\200\234\344\274\230\347\247\200\342\200\235\344\270\272\345\244\247\344\272\216\347\255\211\344\272\21685", nullptr));
        label_93->setText(QCoreApplication::translate("TeacherCourseWidget", "\344\274\230\347\247\200", nullptr));
        distribution_chart_title_text->setText(QCoreApplication::translate("TeacherCourseWidget", "\342\227\217  \344\270\223\346\263\250\345\272\246\345\210\206\345\270\203\346\233\262\347\272\277", nullptr));
        label_90->setText(QCoreApplication::translate("TeacherCourseWidget", "\344\270\200\350\210\254", nullptr));
        label_96->setText(QCoreApplication::translate("TeacherCourseWidget", "\342\200\234\344\270\200\350\210\254\342\200\235\344\270\272\345\244\247\344\272\216\347\255\211\344\272\21660\344\275\206\345\260\217\344\272\21685", nullptr));
        label_94->setText(QCoreApplication::translate("TeacherCourseWidget", "\345\267\256\345\212\262", nullptr));
        label_98->setText(QCoreApplication::translate("TeacherCourseWidget", "*\346\263\250\357\274\232", nullptr));
        area_chart_title_text->setText(QCoreApplication::translate("TeacherCourseWidget", "\342\227\217  \346\257\217\345\240\202\350\257\276\347\232\204\344\270\223\346\263\250\345\272\246\345\257\271\346\257\224", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(course_data_tab), QString());
        label_5->setText(QString());
        label_4->setText(QCoreApplication::translate("TeacherCourseWidget", "\344\270\223\346\263\250\345\272\246", nullptr));
        concentration_text->setText(QCoreApplication::translate("TeacherCourseWidget", "100", nullptr));
        label_7->setText(QString());
        label_8->setText(QCoreApplication::translate("TeacherCourseWidget", "\344\270\276\346\211\213\347\216\207", nullptr));
        raise_hand_rate_text->setText(QCoreApplication::translate("TeacherCourseWidget", "100", nullptr));
        label_11->setText(QString());
        label_12->setText(QCoreApplication::translate("TeacherCourseWidget", "\345\233\236\347\255\224\344\274\230\347\247\200\347\216\207", nullptr));
        excellent_rate_text->setText(QCoreApplication::translate("TeacherCourseWidget", "100", nullptr));
        label_14->setText(QString());
        label_15->setText(QCoreApplication::translate("TeacherCourseWidget", "\345\212\240\345\205\245\346\227\266\351\227\264", nullptr));
        join_date_text->setText(QCoreApplication::translate("TeacherCourseWidget", "2017-09-21", nullptr));
        member_name_text->setText(QCoreApplication::translate("TeacherCourseWidget", "Lan YangBo", nullptr));
        member_id_text->setText(QCoreApplication::translate("TeacherCourseWidget", "20172131100", nullptr));
        member_pic->setText(QString());
        num_of_student_text->setText(QCoreApplication::translate("TeacherCourseWidget", "888", nullptr));
        label_100->setText(QCoreApplication::translate("TeacherCourseWidget", "\346\225\231\345\270\210", nullptr));
        label_104->setText(QCoreApplication::translate("TeacherCourseWidget", "\345\255\246\347\224\237", nullptr));
        label_107->setText(QCoreApplication::translate("TeacherCourseWidget", "*\345\215\225\344\275\215\357\274\232\344\272\272", nullptr));
        label_109->setText(QCoreApplication::translate("TeacherCourseWidget", "\345\220\210\350\256\241", nullptr));
        total_text->setText(QCoreApplication::translate("TeacherCourseWidget", "890", nullptr));
        num_of_teacher_text->setText(QCoreApplication::translate("TeacherCourseWidget", "2", nullptr));
        area_chart_title_text_2->setText(QCoreApplication::translate("TeacherCourseWidget", "\342\227\217  \346\246\202\345\206\265", nullptr));
        area_chart_title_text_3->setText(QCoreApplication::translate("TeacherCourseWidget", "\342\227\217  \346\210\220\345\221\230\345\210\227\350\241\250", nullptr));
        pushButton_15->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = member_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("TeacherCourseWidget", "\347\224\250\346\210\267\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = member_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("TeacherCourseWidget", "\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = member_table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("TeacherCourseWidget", "\350\247\222\350\211\262", nullptr));
        area_chart_title_text_4->setText(QCoreApplication::translate("TeacherCourseWidget", "\342\227\217  \346\257\217\345\240\202\350\257\276\347\232\204\344\270\223\346\263\250\345\272\246\345\257\271\346\257\224", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(course_member_tab), QString());
    } // retranslateUi

};

namespace Ui {
    class TeacherCourseWidget: public Ui_TeacherCourseWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHER_COURSE_WIDGET_H
