/********************************************************************************
** Form generated from reading UI file 'teacher_interaction_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHER_INTERACTION_WIDGET_H
#define UI_TEACHER_INTERACTION_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeacherInteractionWidget
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QPushButton *begin_lesson_btn;
    QFrame *frame_2;
    QLabel *mine_camera_label;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_6;
    QFrame *frame;
    QGridLayout *gridLayout_7;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_8;
    QLabel *label_19;
    QLabel *label_17;
    QLabel *label_2;
    QLabel *label_11;
    QLabel *label_15;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_5;
    QLabel *label_16;
    QSpacerItem *verticalSpacer_7;
    QLabel *label_4;
    QLabel *label_18;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_20;
    QLabel *label_21;
    QCheckBox *checkBox;
    QLabel *label_23;
    QCheckBox *checkBox_3;
    QLabel *label_22;
    QCheckBox *checkBox_2;
    QWidget *widget;
    QLabel *label_14;
    QLabel *label_12;
    QLabel *label_13;
    QTabWidget *function_tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QSlider *pen_width_slider;
    QLineEdit *pen_width_edit;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_7;
    QSlider *rubber_width_slider;
    QLineEdit *rubber_width_edit;
    QSpacerItem *horizontalSpacer_5;
    QTabWidget *board_tabWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *add_board_btn;
    QSpacerItem *verticalSpacer_2;
    QPushButton *black_pen_btn;
    QPushButton *red_pen_btn;
    QPushButton *blue_pen_btn;
    QPushButton *color_pen_btn;
    QPushButton *text_btn;
    QPushButton *line_btn;
    QPushButton *rect_btn;
    QPushButton *ellipse_btn;
    QPushButton *clear_btn;
    QPushButton *undo_btn;
    QPushButton *rubber_btn;
    QSpacerItem *verticalSpacer;
    QWidget *tab_2;
    QGridLayout *gridLayout_4;
    QTabWidget *quiz_tabWidget;
    QWidget *tab_4;
    QGridLayout *gridLayout_5;
    QFrame *frame_5;
    QGridLayout *gridLayout_6;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_10;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_9;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_7;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_12;
    QSpacerItem *verticalSpacer_9;
    QWidget *tab_5;
    QWidget *tab_6;
    QWidget *tab_3;
    QGridLayout *gridLayout_9;
    QTabWidget *tabWidget;
    QWidget *tab_7;
    QGridLayout *gridLayout_10;
    QLabel *label_27;
    QLabel *label_24;
    QLabel *label_26;
    QLabel *label_28;
    QFrame *area_chart_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *area_chart_title_text_3;
    QWidget *area_chart_widget_3;
    QFrame *area_chart;
    QVBoxLayout *verticalLayout_5;
    QLabel *area_chart_title_text;
    QWidget *area_chart_widget;
    QLabel *label_25;
    QSpacerItem *verticalSpacer_8;
    QWidget *tab_8;
    QGridLayout *gridLayout_11;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_29;
    QLabel *label_30;
    QSpacerItem *horizontalSpacer_9;
    QFrame *frame_4;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_6;
    QButtonGroup *buttonGroup;
    QButtonGroup *buttonGroup_2;

    void setupUi(QWidget *TeacherInteractionWidget)
    {
        if (TeacherInteractionWidget->objectName().isEmpty())
            TeacherInteractionWidget->setObjectName(QString::fromUtf8("TeacherInteractionWidget"));
        TeacherInteractionWidget->resize(819, 627);
        TeacherInteractionWidget->setMinimumSize(QSize(819, 627));
        TeacherInteractionWidget->setStyleSheet(QString::fromUtf8("QWidget#TeacherInteractionWidget {\n"
"	background: #F3F4F8;\n"
"}"));
        gridLayout = new QGridLayout(TeacherInteractionWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, -1, 0);
        begin_lesson_btn = new QPushButton(TeacherInteractionWidget);
        begin_lesson_btn->setObjectName(QString::fromUtf8("begin_lesson_btn"));
        begin_lesson_btn->setMinimumSize(QSize(0, 40));
        begin_lesson_btn->setMaximumSize(QSize(16777215, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
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

        gridLayout_2->addWidget(begin_lesson_btn, 0, 0, 1, 1);

        frame_2 = new QFrame(TeacherInteractionWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(200, 130));
        frame_2->setMaximumSize(QSize(200, 130));
        frame_2->setStyleSheet(QString::fromUtf8(""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        mine_camera_label = new QLabel(frame_2);
        mine_camera_label->setObjectName(QString::fromUtf8("mine_camera_label"));
        mine_camera_label->setGeometry(QRect(0, 0, 200, 130));
        mine_camera_label->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border-left: 1px solid #E8ECEC;\n"
"	background: blue;\n"
"}"));
        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(0, 100, 200, 39));
        frame_3->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border-left: 1px solid #E8ECEC;\n"
"	background-color: rgba(0, 0, 0, 100);\n"
"}"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_3);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 0, 10, 10);
        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #ffffff;\n"
"}"));

        horizontalLayout->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_6 = new QPushButton(frame_3);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(20, 0));
        pushButton_6->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: none;\n"
"	border: none;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/button/Resources/material/button/voice.png"), QSize(), QIcon::Active, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/button/Resources/material/button/voice_close.png"), QSize(), QIcon::Active, QIcon::On);
        pushButton_6->setIcon(icon);
        pushButton_6->setIconSize(QSize(15, 15));
        pushButton_6->setCheckable(true);

        horizontalLayout->addWidget(pushButton_6);


        gridLayout_2->addWidget(frame_2, 2, 0, 1, 1);

        frame = new QFrame(TeacherInteractionWidget);
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
        scrollArea = new QScrollArea(frame);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 198, 453));
        scrollAreaWidgetContents->setMinimumSize(QSize(198, 0));
        scrollAreaWidgetContents->setMaximumSize(QSize(198, 16777215));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	border: none;\n"
"	background-color: #ffffff;\n"
"}"));
        gridLayout_8 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(9, 9, -1, -1);
        label_19 = new QLabel(scrollAreaWidgetContents);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font1);
        label_19->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));

        gridLayout_8->addWidget(label_19, 1, 2, 1, 6);

        label_17 = new QLabel(scrollAreaWidgetContents);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFont(font);
        label_17->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #666666;\n"
"}"));

        gridLayout_8->addWidget(label_17, 3, 0, 1, 8);

        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #666666;\n"
"}"));

        gridLayout_8->addWidget(label_2, 0, 0, 1, 8);

        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));

        gridLayout_8->addWidget(label_11, 5, 0, 1, 2);

        label_15 = new QLabel(scrollAreaWidgetContents);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font1);
        label_15->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));

        gridLayout_8->addWidget(label_15, 6, 0, 1, 2);

        verticalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_8->addItem(verticalSpacer_6, 2, 0, 1, 8);

        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_5, 4, 2, 1, 4);

        label_16 = new QLabel(scrollAreaWidgetContents);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font1);
        label_16->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));
        label_16->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_16, 6, 2, 1, 5);

        verticalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_8->addItem(verticalSpacer_7, 8, 0, 1, 8);

        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));

        gridLayout_8->addWidget(label_4, 4, 0, 1, 2);

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

        verticalSpacer_5 = new QSpacerItem(171, 548, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(verticalSpacer_5, 14, 0, 1, 8);

        label_20 = new QLabel(scrollAreaWidgetContents);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font);
        label_20->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #666666;\n"
"}"));

        gridLayout_8->addWidget(label_20, 9, 0, 1, 8);

        label_21 = new QLabel(scrollAreaWidgetContents);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font1);
        label_21->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));

        gridLayout_8->addWidget(label_21, 10, 0, 1, 2);

        checkBox = new QCheckBox(scrollAreaWidgetContents);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy);
        checkBox->setMinimumSize(QSize(27, 16));
        checkBox->setMaximumSize(QSize(16777215, 16));
        checkBox->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 30px;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 27px;\n"
"    height: 16px;\n"
"	background: none;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"	image: url(:/button/Resources/material/button/turn_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    image: url(:/button/Resources/material/button/turn_on.png);\n"
"}"));
        checkBox->setTristate(false);

        gridLayout_8->addWidget(checkBox, 10, 2, 1, 6);

        label_23 = new QLabel(scrollAreaWidgetContents);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setFont(font1);
        label_23->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));

        gridLayout_8->addWidget(label_23, 11, 0, 1, 2);

        checkBox_3 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        sizePolicy.setHeightForWidth(checkBox_3->sizePolicy().hasHeightForWidth());
        checkBox_3->setSizePolicy(sizePolicy);
        checkBox_3->setMinimumSize(QSize(27, 16));
        checkBox_3->setMaximumSize(QSize(16777215, 16));
        checkBox_3->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 30px;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 27px;\n"
"    height: 16px;\n"
"	background: none;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"	image: url(:/button/Resources/material/button/turn_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    image: url(:/button/Resources/material/button/turn_on.png);\n"
"}"));
        checkBox_3->setTristate(false);

        gridLayout_8->addWidget(checkBox_3, 11, 2, 1, 6);

        label_22 = new QLabel(scrollAreaWidgetContents);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font1);
        label_22->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));

        gridLayout_8->addWidget(label_22, 12, 0, 1, 2);

        checkBox_2 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        sizePolicy.setHeightForWidth(checkBox_2->sizePolicy().hasHeightForWidth());
        checkBox_2->setSizePolicy(sizePolicy);
        checkBox_2->setMinimumSize(QSize(27, 16));
        checkBox_2->setMaximumSize(QSize(16777215, 16));
        checkBox_2->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	padding-left: 30px;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 27px;\n"
"    height: 16px;\n"
"	background: none;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"	image: url(:/button/Resources/material/button/turn_off.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    image: url(:/button/Resources/material/button/turn_on.png);\n"
"}"));
        checkBox_2->setTristate(false);

        gridLayout_8->addWidget(checkBox_2, 12, 2, 1, 6);

        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 70));
        widget->setMaximumSize(QSize(16777215, 70));

        gridLayout_8->addWidget(widget, 7, 0, 1, 8);

        label_14 = new QLabel(scrollAreaWidgetContents);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font1);
        label_14->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_14, 5, 4, 1, 1);

        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font1);
        label_12->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));
        label_12->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_12, 5, 2, 1, 2);

        label_13 = new QLabel(scrollAreaWidgetContents);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font1);
        label_13->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));
        label_13->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_8->addWidget(label_13, 5, 5, 1, 2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_7->addWidget(scrollArea, 1, 5, 1, 1);


        gridLayout_2->addWidget(frame, 1, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 1, 1, 1);

        function_tabWidget = new QTabWidget(TeacherInteractionWidget);
        function_tabWidget->setObjectName(QString::fromUtf8("function_tabWidget"));
        function_tabWidget->setMinimumSize(QSize(553, 627));
        function_tabWidget->setFont(font);
        function_tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab {\n"
"	padding-top: 0px;\n"
"	color: #999999;\n"
"	border: none;\n"
"	height: 40px;\n"
"	width: 70px;\n"
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
        function_tabWidget->setTabPosition(QTabWidget::North);
        function_tabWidget->setTabShape(QTabWidget::Rounded);
        function_tabWidget->setIconSize(QSize(40, 20));
        function_tabWidget->setElideMode(Qt::ElideNone);
        function_tabWidget->setUsesScrollButtons(true);
        function_tabWidget->setTabsClosable(false);
        function_tabWidget->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setSpacing(5);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(5, 5, 5, 5);
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #666666;\n"
"}"));

        horizontalLayout_3->addWidget(label_6);

        pen_width_slider = new QSlider(tab);
        pen_width_slider->setObjectName(QString::fromUtf8("pen_width_slider"));
        sizePolicy1.setHeightForWidth(pen_width_slider->sizePolicy().hasHeightForWidth());
        pen_width_slider->setSizePolicy(sizePolicy1);
        pen_width_slider->setMinimumSize(QSize(168, 0));
        pen_width_slider->setMaximumSize(QSize(168, 16777215));
        pen_width_slider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: 1px solid #E8ECEC;\n"
"	border-radius: 2px;\n"
"    height: 4px; \n"
"    background: #ffffff;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    border: 1px solid #E8ECEC;\n"
"	border-radius: 2px;\n"
"    background: #ffffff;\n"
"	width: 16px;\n"
"    margin-top: -7px;\n"
"    margin-bottom: -7px;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"	border: 1px solid #E8ECEC;\n"
"	border-radius: 2px;\n"
"    height: 4px; \n"
"    background-color: #1296db;\n"
"}"));
        pen_width_slider->setMinimum(1);
        pen_width_slider->setSliderPosition(3);
        pen_width_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(pen_width_slider);

        pen_width_edit = new QLineEdit(tab);
        pen_width_edit->setObjectName(QString::fromUtf8("pen_width_edit"));
        sizePolicy1.setHeightForWidth(pen_width_edit->sizePolicy().hasHeightForWidth());
        pen_width_edit->setSizePolicy(sizePolicy1);
        pen_width_edit->setMinimumSize(QSize(22, 0));
        pen_width_edit->setMaximumSize(QSize(20, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(9);
        pen_width_edit->setFont(font2);
        pen_width_edit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border: 1px solid #E8ECEC;\n"
"}"));

        horizontalLayout_3->addWidget(pen_width_edit);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #666666;\n"
"}"));

        horizontalLayout_3->addWidget(label_7);

        rubber_width_slider = new QSlider(tab);
        rubber_width_slider->setObjectName(QString::fromUtf8("rubber_width_slider"));
        sizePolicy1.setHeightForWidth(rubber_width_slider->sizePolicy().hasHeightForWidth());
        rubber_width_slider->setSizePolicy(sizePolicy1);
        rubber_width_slider->setMinimumSize(QSize(168, 0));
        rubber_width_slider->setMaximumSize(QSize(168, 16777215));
        rubber_width_slider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: 1px solid #E8ECEC;\n"
"	border-radius: 2px;\n"
"    height: 4px; \n"
"    background: #ffffff;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    border: 1px solid #E8ECEC;\n"
"	border-radius: 2px;\n"
"    background: #ffffff;\n"
"	width: 16px;\n"
"    margin-top: -7px;\n"
"    margin-bottom: -7px;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"	border: 1px solid #E8ECEC;\n"
"	border-radius: 2px;\n"
"    height: 4px; \n"
"    background-color: #1296db;\n"
"}"));
        rubber_width_slider->setMinimum(1);
        rubber_width_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(rubber_width_slider);

        rubber_width_edit = new QLineEdit(tab);
        rubber_width_edit->setObjectName(QString::fromUtf8("rubber_width_edit"));
        sizePolicy1.setHeightForWidth(rubber_width_edit->sizePolicy().hasHeightForWidth());
        rubber_width_edit->setSizePolicy(sizePolicy1);
        rubber_width_edit->setMinimumSize(QSize(22, 0));
        rubber_width_edit->setMaximumSize(QSize(20, 16777215));
        rubber_width_edit->setFont(font2);
        rubber_width_edit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border: 1px solid #E8ECEC;\n"
"}"));

        horizontalLayout_3->addWidget(rubber_width_edit);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        gridLayout_3->addLayout(horizontalLayout_3, 0, 1, 1, 1);

        board_tabWidget = new QTabWidget(tab);
        board_tabWidget->setObjectName(QString::fromUtf8("board_tabWidget"));
        board_tabWidget->setMinimumSize(QSize(556, 539));
        board_tabWidget->setFont(font1);
        board_tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab {\n"
"	padding-top: 0px;\n"
"	color: #999999;\n"
"	border: 1px solid #E8ECEC;\n"
"	border-bottom: none;\n"
"	border-top-left-radius: 3px;\n"
"	border-top-right-radius: 3px;\n"
"	height: 20px;\n"
"	width: 90px;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"	color: #1296db;\n"
"	border: 1px solid #E8ECEC;\n"
"	border-bottom: none;\n"
"	border-top-left-radius: 3px;\n"
"	border-top-right-radius: 3px;\n"
"	background-color: #ffffff;\n"
"	height: 20px;\n"
"	width: 90px;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"	background-color: #E6E6E6;\n"
"}\n"
"\n"
"QTabWidget#board_tabWidget::pane {\n"
"	border: 1px solid #E8ECEC;\n"
"	border-top: none;\n"
"}\n"
"\n"
"QTabBar::close-button {\n"
"	image: url(:/button/Resources/material/button/close_mini.png);\n"
"}\n"
"QTabBar::close-button:hover {\n"
"    image: url(:/button/Resources/material/button/close_mini.png);\n"
"	border-radius: 8px;\n"
"	background-color: red;\n"
"}"));
        board_tabWidget->setTabShape(QTabWidget::Rounded);
        board_tabWidget->setTabsClosable(false);

        gridLayout_3->addWidget(board_tabWidget, 1, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        add_board_btn = new QPushButton(tab);
        add_board_btn->setObjectName(QString::fromUtf8("add_board_btn"));
        add_board_btn->setCursor(QCursor(Qt::PointingHandCursor));
        add_board_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	background: none;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/button/Resources/material/button/\346\226\260\345\273\272.png"), QSize(), QIcon::Normal, QIcon::Off);
        add_board_btn->setIcon(icon1);
        add_board_btn->setIconSize(QSize(20, 20));

        verticalLayout->addWidget(add_board_btn);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        black_pen_btn = new QPushButton(tab);
        buttonGroup = new QButtonGroup(TeacherInteractionWidget);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(black_pen_btn);
        black_pen_btn->setObjectName(QString::fromUtf8("black_pen_btn"));
        black_pen_btn->setMinimumSize(QSize(40, 40));
        black_pen_btn->setMaximumSize(QSize(40, 40));
        black_pen_btn->setCursor(QCursor(Qt::PointingHandCursor));
        black_pen_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid #E8ECEC;\n"
"	border-bottom: none;\n"
"	border-top-left-radius: 5px;\n"
"	border-top-right-radius: 5px;\n"
"	background-color: #FCFCFC;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E3E3E3;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #CACACA;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/button/Resources/material/button/pen#000000.png"), QSize(), QIcon::Normal, QIcon::Off);
        black_pen_btn->setIcon(icon2);
        black_pen_btn->setIconSize(QSize(20, 20));
        black_pen_btn->setCheckable(true);

        verticalLayout->addWidget(black_pen_btn);

        red_pen_btn = new QPushButton(tab);
        buttonGroup->addButton(red_pen_btn);
        red_pen_btn->setObjectName(QString::fromUtf8("red_pen_btn"));
        red_pen_btn->setMinimumSize(QSize(40, 40));
        red_pen_btn->setMaximumSize(QSize(40, 40));
        red_pen_btn->setCursor(QCursor(Qt::PointingHandCursor));
        red_pen_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid #E8ECEC;\n"
"	border-bottom: none;\n"
"	background-color: #FCFCFC;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E3E3E3;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #CACACA;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/button/Resources/material/button/pend#d81e06.png"), QSize(), QIcon::Normal, QIcon::Off);
        red_pen_btn->setIcon(icon3);
        red_pen_btn->setIconSize(QSize(20, 20));
        red_pen_btn->setCheckable(true);

        verticalLayout->addWidget(red_pen_btn);

        blue_pen_btn = new QPushButton(tab);
        buttonGroup->addButton(blue_pen_btn);
        blue_pen_btn->setObjectName(QString::fromUtf8("blue_pen_btn"));
        blue_pen_btn->setMinimumSize(QSize(40, 40));
        blue_pen_btn->setMaximumSize(QSize(40, 40));
        blue_pen_btn->setCursor(QCursor(Qt::PointingHandCursor));
        blue_pen_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid #E8ECEC;\n"
"	border-bottom: none;\n"
"	background-color: #FCFCFC;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E3E3E3;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #CACACA;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/button/Resources/material/button/pen#1296db.png"), QSize(), QIcon::Normal, QIcon::Off);
        blue_pen_btn->setIcon(icon4);
        blue_pen_btn->setIconSize(QSize(20, 20));
        blue_pen_btn->setCheckable(true);

        verticalLayout->addWidget(blue_pen_btn);

        color_pen_btn = new QPushButton(tab);
        buttonGroup->addButton(color_pen_btn);
        color_pen_btn->setObjectName(QString::fromUtf8("color_pen_btn"));
        color_pen_btn->setMinimumSize(QSize(40, 40));
        color_pen_btn->setMaximumSize(QSize(40, 40));
        color_pen_btn->setCursor(QCursor(Qt::PointingHandCursor));
        color_pen_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 5px solid #E8ECEC;\n"
"	background-color: #FCFCFC;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E3E3E3;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #CACACA;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/button/Resources/material/button/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        color_pen_btn->setIcon(icon5);
        color_pen_btn->setIconSize(QSize(20, 20));
        color_pen_btn->setCheckable(true);

        verticalLayout->addWidget(color_pen_btn);

        text_btn = new QPushButton(tab);
        buttonGroup->addButton(text_btn);
        text_btn->setObjectName(QString::fromUtf8("text_btn"));
        text_btn->setMinimumSize(QSize(40, 40));
        text_btn->setMaximumSize(QSize(40, 40));
        text_btn->setCursor(QCursor(Qt::PointingHandCursor));
        text_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid #E8ECEC;\n"
"	border-bottom: none;\n"
"	background-color: #FCFCFC;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E3E3E3;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #CACACA;\n"
"}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/button/Resources/material/button/text.png"), QSize(), QIcon::Normal, QIcon::Off);
        text_btn->setIcon(icon6);
        text_btn->setIconSize(QSize(20, 20));
        text_btn->setCheckable(true);

        verticalLayout->addWidget(text_btn);

        line_btn = new QPushButton(tab);
        buttonGroup->addButton(line_btn);
        line_btn->setObjectName(QString::fromUtf8("line_btn"));
        line_btn->setMinimumSize(QSize(40, 40));
        line_btn->setMaximumSize(QSize(40, 40));
        line_btn->setCursor(QCursor(Qt::PointingHandCursor));
        line_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid #E8ECEC;\n"
"	border-bottom: none;\n"
"	background-color: #FCFCFC;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E3E3E3;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #CACACA;\n"
"}"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/button/Resources/material/button/line.png"), QSize(), QIcon::Normal, QIcon::Off);
        line_btn->setIcon(icon7);
        line_btn->setIconSize(QSize(20, 20));
        line_btn->setCheckable(true);

        verticalLayout->addWidget(line_btn);

        rect_btn = new QPushButton(tab);
        buttonGroup->addButton(rect_btn);
        rect_btn->setObjectName(QString::fromUtf8("rect_btn"));
        rect_btn->setMinimumSize(QSize(40, 40));
        rect_btn->setMaximumSize(QSize(40, 40));
        rect_btn->setCursor(QCursor(Qt::PointingHandCursor));
        rect_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid #E8ECEC;\n"
"	border-bottom: none;\n"
"	background-color: #FCFCFC;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E3E3E3;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #CACACA;\n"
"}"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/button/Resources/material/button/rect.png"), QSize(), QIcon::Normal, QIcon::Off);
        rect_btn->setIcon(icon8);
        rect_btn->setIconSize(QSize(20, 20));
        rect_btn->setCheckable(true);

        verticalLayout->addWidget(rect_btn);

        ellipse_btn = new QPushButton(tab);
        buttonGroup->addButton(ellipse_btn);
        ellipse_btn->setObjectName(QString::fromUtf8("ellipse_btn"));
        ellipse_btn->setMinimumSize(QSize(40, 40));
        ellipse_btn->setMaximumSize(QSize(40, 40));
        ellipse_btn->setCursor(QCursor(Qt::PointingHandCursor));
        ellipse_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid #E8ECEC;\n"
"	border-bottom: none;\n"
"	background-color: #FCFCFC;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E3E3E3;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #CACACA;\n"
"}"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/button/Resources/material/button/circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        ellipse_btn->setIcon(icon9);
        ellipse_btn->setIconSize(QSize(20, 20));
        ellipse_btn->setCheckable(true);

        verticalLayout->addWidget(ellipse_btn);

        clear_btn = new QPushButton(tab);
        clear_btn->setObjectName(QString::fromUtf8("clear_btn"));
        clear_btn->setMinimumSize(QSize(40, 40));
        clear_btn->setMaximumSize(QSize(40, 40));
        clear_btn->setCursor(QCursor(Qt::PointingHandCursor));
        clear_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid #E8ECEC;\n"
"	border-bottom: none;\n"
"	background-color: #FCFCFC;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E3E3E3;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #CACACA;\n"
"}"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/button/Resources/material/button/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clear_btn->setIcon(icon10);
        clear_btn->setIconSize(QSize(20, 20));
        clear_btn->setCheckable(false);

        verticalLayout->addWidget(clear_btn);

        undo_btn = new QPushButton(tab);
        undo_btn->setObjectName(QString::fromUtf8("undo_btn"));
        undo_btn->setMinimumSize(QSize(40, 40));
        undo_btn->setMaximumSize(QSize(40, 40));
        undo_btn->setCursor(QCursor(Qt::PointingHandCursor));
        undo_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid #E8ECEC;\n"
"	border-bottom: none;\n"
"	background-color: #FCFCFC;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E3E3E3;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #CACACA;\n"
"}"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/button/Resources/material/button/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        undo_btn->setIcon(icon11);
        undo_btn->setIconSize(QSize(20, 20));
        undo_btn->setCheckable(false);

        verticalLayout->addWidget(undo_btn);

        rubber_btn = new QPushButton(tab);
        buttonGroup->addButton(rubber_btn);
        rubber_btn->setObjectName(QString::fromUtf8("rubber_btn"));
        rubber_btn->setMinimumSize(QSize(40, 40));
        rubber_btn->setMaximumSize(QSize(40, 40));
        rubber_btn->setCursor(QCursor(Qt::PointingHandCursor));
        rubber_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid #E8ECEC;\n"
"	border-bottom-left-radius: 5px;\n"
"	border-bottom-right-radius: 5px;\n"
"	background-color: #FCFCFC;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E3E3E3;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #CACACA;\n"
"}"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/button/Resources/material/button/rubber.png"), QSize(), QIcon::Normal, QIcon::Off);
        rubber_btn->setIcon(icon12);
        rubber_btn->setIconSize(QSize(20, 20));
        rubber_btn->setCheckable(true);

        verticalLayout->addWidget(rubber_btn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout_3->addLayout(verticalLayout, 1, 0, 1, 1);

        function_tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_4 = new QGridLayout(tab_2);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        quiz_tabWidget = new QTabWidget(tab_2);
        quiz_tabWidget->setObjectName(QString::fromUtf8("quiz_tabWidget"));
        quiz_tabWidget->setFont(font1);
        quiz_tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab {\n"
"	padding-top: 0px;\n"
"	margin: 10px 50px 10px 50px;\n"
"	color: #999999;\n"
"	border: 1px solid #999999;\n"
"	border-radius: 15px;\n"
"	height: 30px;\n"
"	width: 100px;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"	color: #1296db;\n"
"	border: 1px solid #1296db;\n"
"	border-radius: 15px;\n"
"	height: 30px;\n"
"	width: 100px;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"	background-color: #E6E6E6;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"	alignment:center;\n"
"}\n"
"\n"
"QTabWidget#quiz_tabWidget::pane {\n"
"	border-top: 1px solid #E8ECEC;\n"
"}\n"
""));
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_5 = new QGridLayout(tab_4);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        frame_5 = new QFrame(tab_4);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setMinimumSize(QSize(607, 90));
        frame_5->setMaximumSize(QSize(16777215, 90));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_5);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setHorizontalSpacing(0);
        gridLayout_6->setVerticalSpacing(5);
        gridLayout_6->setContentsMargins(10, 0, 10, 0);
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_4, 0, 0, 1, 8);

        label_10 = new QLabel(frame_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #666666;\n"
"}"));

        gridLayout_6->addWidget(label_10, 2, 3, 1, 1);

        pushButton_3 = new QPushButton(frame_5);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(80, 25));
        pushButton_3->setMaximumSize(QSize(80, 25));
        pushButton_3->setFont(font1);
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #ffffff;\n"
"	border-radius: 5px;\n"
"	background-color: #1296db;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #0E71A4;\n"
"}"));
        pushButton_3->setCheckable(false);

        gridLayout_6->addWidget(pushButton_3, 1, 6, 1, 1, Qt::AlignRight);

        pushButton_2 = new QPushButton(frame_5);
        buttonGroup_2 = new QButtonGroup(TeacherInteractionWidget);
        buttonGroup_2->setObjectName(QString::fromUtf8("buttonGroup_2"));
        buttonGroup_2->addButton(pushButton_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(60, 35));
        pushButton_2->setMaximumSize(QSize(60, 35));
        pushButton_2->setFont(font1);
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #666666;\n"
"	border: 1px solid #E8ECEC;\n"
"	background-color: #ffffff;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E3E3E3;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #CACACA;\n"
"}"));
        pushButton_2->setCheckable(true);

        gridLayout_6->addWidget(pushButton_2, 2, 5, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_3, 3, 0, 1, 8);

        label_9 = new QLabel(frame_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #666666;\n"
"}"));

        gridLayout_6->addWidget(label_9, 2, 0, 1, 1);

        label_8 = new QLabel(frame_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #333333;\n"
"}"));

        gridLayout_6->addWidget(label_8, 1, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_7, 2, 2, 1, 1);

        comboBox = new QComboBox(frame_5);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(80, 35));
        comboBox->setMaximumSize(QSize(80, 35));
        comboBox->setFont(font1);
        comboBox->setCursor(QCursor(Qt::PointingHandCursor));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	color: #666666;\n"
"	border: 1px solid #E8ECEC;\n"
"	background-color: #ffffff;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"	image: url(:/button/Resources/material/button/down_2.png);\n"
"	width: 20px;\n"
"	height: 20px;\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"	border-left: 1px solid #E8ECEC;\n"
"	width: 30px;\n"
"  \n"
"}\n"
"\n"
"QComboBox#comboBoxTwo::drop-down{\n"
"	border: none;\n"
"	background: none;  \n"
"}"));

        gridLayout_6->addWidget(comboBox, 2, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_8, 2, 6, 1, 1);

        pushButton = new QPushButton(frame_5);
        buttonGroup_2->addButton(pushButton);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(60, 35));
        pushButton->setMaximumSize(QSize(60, 35));
        pushButton->setFont(font1);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #666666;\n"
"	border: 1px solid #E8ECEC;\n"
"	border-right: none;\n"
"	background-color: #ffffff;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E3E3E3;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #CACACA;\n"
"}"));
        pushButton->setCheckable(true);
        pushButton->setChecked(true);

        gridLayout_6->addWidget(pushButton, 2, 4, 1, 1);


        gridLayout_5->addWidget(frame_5, 0, 0, 1, 1);

        scrollArea_2 = new QScrollArea(tab_4);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setStyleSheet(QString::fromUtf8("QScrollArea#scrollArea_2 {\n"
"	border-top: 1px solid #E8ECEC;\n"
"	background-color: #ffffff;\n"
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
""
                        "QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 615, 441));
        scrollAreaWidgetContents_2->setStyleSheet(QString::fromUtf8("background: #ffffff;"));
        gridLayout_12 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setHorizontalSpacing(0);
        gridLayout_12->setContentsMargins(20, -1, 20, -1);
        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_12->addItem(verticalSpacer_9, 10, 0, 1, 2);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        gridLayout_5->addWidget(scrollArea_2, 1, 0, 1, 1);

        quiz_tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        quiz_tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        quiz_tabWidget->addTab(tab_6, QString());

        gridLayout_4->addWidget(quiz_tabWidget, 0, 0, 1, 1);

        function_tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tab_3->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
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
"QScrollBar::sub-line:vert"
                        "ical {\n"
"    height: 0px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}"));
        gridLayout_9 = new QGridLayout(tab_3);
        gridLayout_9->setSpacing(0);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(tab_3);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setFont(font1);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab {\n"
"	padding-top: 0px;\n"
"	margin: 10px 50px 10px 50px;\n"
"	color: #999999;\n"
"	border: 1px solid #999999;\n"
"	border-radius: 15px;\n"
"	height: 30px;\n"
"	width: 100px;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"	color: #1296db;\n"
"	border: 1px solid #1296db;\n"
"	border-radius: 15px;\n"
"	height: 30px;\n"
"	width: 100px;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"	background-color: #E6E6E6;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"	alignment:center;\n"
"}\n"
"\n"
"QTabWidget#tabWidget::pane {\n"
"	border-top: 1px solid #E8ECEC;\n"
"}\n"
""));
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        gridLayout_10 = new QGridLayout(tab_7);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label_27 = new QLabel(tab_7);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setMinimumSize(QSize(40, 40));
        label_27->setMaximumSize(QSize(40, 40));
        label_27->setPixmap(QPixmap(QString::fromUtf8(":/button/Resources/material/button/neutral.png")));
        label_27->setScaledContents(true);

        gridLayout_10->addWidget(label_27, 4, 1, 1, 1);

        label_24 = new QLabel(tab_7);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setMaximumSize(QSize(16777215, 20));
        label_24->setFont(font1);
        label_24->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));

        gridLayout_10->addWidget(label_24, 3, 0, 1, 1);

        label_26 = new QLabel(tab_7);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setMinimumSize(QSize(0, 40));
        label_26->setMaximumSize(QSize(16777215, 40));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(20);
        label_26->setFont(font3);
        label_26->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #333333;\n"
"}"));

        gridLayout_10->addWidget(label_26, 4, 0, 1, 1);

        label_28 = new QLabel(tab_7);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setMinimumSize(QSize(0, 40));
        label_28->setMaximumSize(QSize(16777215, 40));
        label_28->setFont(font3);
        label_28->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #333333;\n"
"}"));

        gridLayout_10->addWidget(label_28, 4, 2, 1, 1);

        area_chart_2 = new QFrame(tab_7);
        area_chart_2->setObjectName(QString::fromUtf8("area_chart_2"));
        area_chart_2->setMinimumSize(QSize(0, 200));
        area_chart_2->setMaximumSize(QSize(16777215, 16777215));
        area_chart_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #ffffff;\n"
"}"));
        area_chart_2->setFrameShape(QFrame::StyledPanel);
        area_chart_2->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(area_chart_2);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        area_chart_title_text_3 = new QLabel(area_chart_2);
        area_chart_title_text_3->setObjectName(QString::fromUtf8("area_chart_title_text_3"));
        area_chart_title_text_3->setMinimumSize(QSize(0, 30));
        area_chart_title_text_3->setMaximumSize(QSize(16777215, 30));
        area_chart_title_text_3->setFont(font);
        area_chart_title_text_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #333333;\n"
"}"));

        verticalLayout_7->addWidget(area_chart_title_text_3);

        area_chart_widget_3 = new QWidget(area_chart_2);
        area_chart_widget_3->setObjectName(QString::fromUtf8("area_chart_widget_3"));
        area_chart_widget_3->setMinimumSize(QSize(0, 0));
        area_chart_widget_3->setMaximumSize(QSize(16777215, 16777215));
        area_chart_widget_3->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_7->addWidget(area_chart_widget_3);


        gridLayout_10->addWidget(area_chart_2, 1, 0, 1, 3);

        area_chart = new QFrame(tab_7);
        area_chart->setObjectName(QString::fromUtf8("area_chart"));
        area_chart->setMinimumSize(QSize(0, 200));
        area_chart->setMaximumSize(QSize(16777215, 16777215));
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
        area_chart_title_text->setFont(font);
        area_chart_title_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #333333;\n"
"}"));

        verticalLayout_5->addWidget(area_chart_title_text);

        area_chart_widget = new QWidget(area_chart);
        area_chart_widget->setObjectName(QString::fromUtf8("area_chart_widget"));
        area_chart_widget->setMinimumSize(QSize(0, 0));
        area_chart_widget->setMaximumSize(QSize(16777215, 16777215));
        area_chart_widget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_5->addWidget(area_chart_widget);


        gridLayout_10->addWidget(area_chart, 0, 0, 1, 3);

        label_25 = new QLabel(tab_7);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setMinimumSize(QSize(0, 20));
        label_25->setMaximumSize(QSize(16777215, 20));
        label_25->setFont(font1);
        label_25->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));

        gridLayout_10->addWidget(label_25, 3, 1, 1, 2);

        verticalSpacer_8 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_10->addItem(verticalSpacer_8, 2, 0, 1, 3);

        tabWidget->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        gridLayout_11 = new QGridLayout(tab_8);
        gridLayout_11->setSpacing(0);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame_7 = new QFrame(tab_8);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setMinimumSize(QSize(250, 40));
        frame_7->setMaximumSize(QSize(250, 40));
        frame_7->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #F6F8F7;\n"
"	border-right: 1px solid #E8ECEC;\n"
"	border-bottom: 1px solid #E8ECEC;\n"
"}"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_7);
        horizontalLayout_2->setSpacing(8);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 0, 10, 0);
        label_29 = new QLabel(frame_7);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setMinimumSize(QSize(20, 20));
        label_29->setMaximumSize(QSize(20, 20));
        label_29->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	border: none;\n"
"}"));
        label_29->setPixmap(QPixmap(QString::fromUtf8(":/pic/Resources/material/pic/member.png")));
        label_29->setScaledContents(true);

        horizontalLayout_2->addWidget(label_29);

        label_30 = new QLabel(frame_7);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setFont(font1);
        label_30->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #666666;\n"
"}"));

        horizontalLayout_2->addWidget(label_30);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_9);


        verticalLayout_2->addWidget(frame_7);

        frame_4 = new QFrame(tab_8);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setMinimumSize(QSize(250, 0));
        frame_4->setMaximumSize(QSize(250, 16777215));
        frame_4->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #ffffff;\n"
"	border-right: 1px solid #E8ECEC;\n"
"}"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(frame_4);


        gridLayout_11->addLayout(verticalLayout_2, 1, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_10, 1, 3, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_6, 1, 2, 1, 1);

        tabWidget->addTab(tab_8, QString());

        gridLayout_9->addWidget(tabWidget, 0, 0, 1, 1);

        function_tabWidget->addTab(tab_3, QString());

        gridLayout->addWidget(function_tabWidget, 0, 0, 1, 1);


        retranslateUi(TeacherInteractionWidget);

        function_tabWidget->setCurrentIndex(0);
        board_tabWidget->setCurrentIndex(-1);
        quiz_tabWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TeacherInteractionWidget);
    } // setupUi

    void retranslateUi(QWidget *TeacherInteractionWidget)
    {
        TeacherInteractionWidget->setWindowTitle(QCoreApplication::translate("TeacherInteractionWidget", "Form", nullptr));
        begin_lesson_btn->setText(QCoreApplication::translate("TeacherInteractionWidget", "\345\274\200\345\247\213\344\270\212\350\257\276", nullptr));
        mine_camera_label->setText(QString());
        label_3->setText(QCoreApplication::translate("TeacherInteractionWidget", "\347\233\264\346\222\255\344\270\255", nullptr));
        pushButton_6->setText(QString());
        label_19->setText(QCoreApplication::translate("TeacherInteractionWidget", "-", nullptr));
        label_17->setText(QCoreApplication::translate("TeacherInteractionWidget", "\342\227\217 \350\257\276\345\240\202\346\246\202\345\206\265", nullptr));
        label_2->setText(QCoreApplication::translate("TeacherInteractionWidget", "-", nullptr));
        label_11->setText(QCoreApplication::translate("TeacherInteractionWidget", "    \345\210\260\350\257\276\344\272\272\346\225\260\357\274\232", nullptr));
        label_15->setText(QCoreApplication::translate("TeacherInteractionWidget", "    \344\270\223\346\263\250\345\272\246\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("TeacherInteractionWidget", "00:00:00", nullptr));
        label_16->setText(QCoreApplication::translate("TeacherInteractionWidget", "-", nullptr));
        label_4->setText(QCoreApplication::translate("TeacherInteractionWidget", "    \345\267\262\350\277\233\350\241\214\357\274\232", nullptr));
        label_18->setText(QCoreApplication::translate("TeacherInteractionWidget", "    \350\257\276\345\240\202\345\217\267\357\274\232", nullptr));
        label_20->setText(QCoreApplication::translate("TeacherInteractionWidget", "\342\227\217 \350\257\276\345\240\202\347\256\241\347\220\206", nullptr));
        label_21->setText(QCoreApplication::translate("TeacherInteractionWidget", "    \347\224\273\346\235\277\345\220\214\346\255\245", nullptr));
        checkBox->setText(QString());
        label_23->setText(QCoreApplication::translate("TeacherInteractionWidget", "    \345\217\257\344\270\276\346\211\213", nullptr));
        checkBox_3->setText(QString());
        label_22->setText(QCoreApplication::translate("TeacherInteractionWidget", "    \345\217\257\344\270\255\351\200\224\345\212\240\345\205\245", nullptr));
        checkBox_2->setText(QString());
        label_14->setText(QCoreApplication::translate("TeacherInteractionWidget", "/", nullptr));
        label_12->setText(QCoreApplication::translate("TeacherInteractionWidget", "-", nullptr));
        label_13->setText(QCoreApplication::translate("TeacherInteractionWidget", "-", nullptr));
        label_6->setText(QCoreApplication::translate("TeacherInteractionWidget", "\347\224\273\347\254\224\347\262\227\347\273\206", nullptr));
        pen_width_edit->setText(QString());
        label_7->setText(QCoreApplication::translate("TeacherInteractionWidget", "\346\251\241\347\232\256\346\252\253\347\262\227\347\273\206", nullptr));
        rubber_width_edit->setText(QString());
#if QT_CONFIG(tooltip)
        add_board_btn->setToolTip(QCoreApplication::translate("TeacherInteractionWidget", "\346\226\260\345\273\272\347\224\273\346\235\277", nullptr));
#endif // QT_CONFIG(tooltip)
        add_board_btn->setText(QString());
#if QT_CONFIG(tooltip)
        black_pen_btn->setToolTip(QCoreApplication::translate("TeacherInteractionWidget", "\351\273\221\347\254\224", nullptr));
#endif // QT_CONFIG(tooltip)
        black_pen_btn->setText(QString());
#if QT_CONFIG(tooltip)
        red_pen_btn->setToolTip(QCoreApplication::translate("TeacherInteractionWidget", "\347\272\242\347\254\224", nullptr));
#endif // QT_CONFIG(tooltip)
        red_pen_btn->setText(QString());
#if QT_CONFIG(tooltip)
        blue_pen_btn->setToolTip(QCoreApplication::translate("TeacherInteractionWidget", "\350\223\235\347\254\224", nullptr));
#endif // QT_CONFIG(tooltip)
        blue_pen_btn->setText(QString());
#if QT_CONFIG(tooltip)
        color_pen_btn->setToolTip(QCoreApplication::translate("TeacherInteractionWidget", "\350\207\252\345\256\232\344\271\211\351\242\234\350\211\262", nullptr));
#endif // QT_CONFIG(tooltip)
        color_pen_btn->setText(QString());
#if QT_CONFIG(tooltip)
        text_btn->setToolTip(QCoreApplication::translate("TeacherInteractionWidget", "\346\217\222\345\205\245\346\226\207\346\234\254", nullptr));
#endif // QT_CONFIG(tooltip)
        text_btn->setText(QString());
#if QT_CONFIG(tooltip)
        line_btn->setToolTip(QCoreApplication::translate("TeacherInteractionWidget", "\347\233\264\347\272\277", nullptr));
#endif // QT_CONFIG(tooltip)
        line_btn->setText(QString());
#if QT_CONFIG(tooltip)
        rect_btn->setToolTip(QCoreApplication::translate("TeacherInteractionWidget", "\347\237\251\345\275\242", nullptr));
#endif // QT_CONFIG(tooltip)
        rect_btn->setText(QString());
#if QT_CONFIG(tooltip)
        ellipse_btn->setToolTip(QCoreApplication::translate("TeacherInteractionWidget", "\346\244\255\345\234\206", nullptr));
#endif // QT_CONFIG(tooltip)
        ellipse_btn->setText(QString());
#if QT_CONFIG(tooltip)
        clear_btn->setToolTip(QCoreApplication::translate("TeacherInteractionWidget", "\346\270\205\347\251\272\347\224\273\346\235\277", nullptr));
#endif // QT_CONFIG(tooltip)
        clear_btn->setText(QString());
#if QT_CONFIG(tooltip)
        undo_btn->setToolTip(QCoreApplication::translate("TeacherInteractionWidget", "\346\222\244\351\224\200", nullptr));
#endif // QT_CONFIG(tooltip)
        undo_btn->setText(QString());
#if QT_CONFIG(tooltip)
        rubber_btn->setToolTip(QCoreApplication::translate("TeacherInteractionWidget", "\346\251\241\347\232\256\346\252\253", nullptr));
#endif // QT_CONFIG(tooltip)
        rubber_btn->setText(QString());
        function_tabWidget->setTabText(function_tabWidget->indexOf(tab), QCoreApplication::translate("TeacherInteractionWidget", "\347\224\273\346\235\277", nullptr));
        label_10->setText(QCoreApplication::translate("TeacherInteractionWidget", "\347\261\273\345\236\213  ", nullptr));
        pushButton_3->setText(QCoreApplication::translate("TeacherInteractionWidget", "\345\217\221\350\265\267\346\217\220\351\227\256", nullptr));
        pushButton_2->setText(QCoreApplication::translate("TeacherInteractionWidget", "\345\244\232\351\200\211", nullptr));
        label_9->setText(QCoreApplication::translate("TeacherInteractionWidget", "        \351\200\211\351\241\271\344\270\252\346\225\260  ", nullptr));
        label_8->setText(QCoreApplication::translate("TeacherInteractionWidget", "\342\227\217 \346\217\220\351\227\256\350\256\276\347\275\256", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("TeacherInteractionWidget", "1", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("TeacherInteractionWidget", "2", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("TeacherInteractionWidget", "3", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("TeacherInteractionWidget", "4", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("TeacherInteractionWidget", "5", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("TeacherInteractionWidget", "6", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("TeacherInteractionWidget", "7", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("TeacherInteractionWidget", "8", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("TeacherInteractionWidget", "9", nullptr));
        comboBox->setItemText(9, QString());

        pushButton->setText(QCoreApplication::translate("TeacherInteractionWidget", "\345\215\225\351\200\211", nullptr));
        quiz_tabWidget->setTabText(quiz_tabWidget->indexOf(tab_4), QCoreApplication::translate("TeacherInteractionWidget", "\351\200\211\346\213\251\351\242\230", nullptr));
        quiz_tabWidget->setTabText(quiz_tabWidget->indexOf(tab_5), QCoreApplication::translate("TeacherInteractionWidget", "\351\227\256\347\255\224\351\242\230", nullptr));
        quiz_tabWidget->setTabText(quiz_tabWidget->indexOf(tab_6), QCoreApplication::translate("TeacherInteractionWidget", "\345\205\266\344\273\226\351\242\230\345\236\213", nullptr));
        function_tabWidget->setTabText(function_tabWidget->indexOf(tab_2), QCoreApplication::translate("TeacherInteractionWidget", "\346\217\220\351\227\256", nullptr));
        label_27->setText(QString());
        label_24->setText(QCoreApplication::translate("TeacherInteractionWidget", "\345\271\263\345\235\207\344\270\223\346\263\250\345\272\246", nullptr));
        label_26->setText(QCoreApplication::translate("TeacherInteractionWidget", "99", nullptr));
        label_28->setText(QCoreApplication::translate("TeacherInteractionWidget", "\345\271\263\351\235\231", nullptr));
        area_chart_title_text_3->setText(QCoreApplication::translate("TeacherInteractionWidget", "\342\227\217  \350\241\250\346\203\205\345\210\206\346\236\220", nullptr));
        area_chart_title_text->setText(QCoreApplication::translate("TeacherInteractionWidget", "\342\227\217  \345\271\263\345\235\207\344\270\223\346\263\250\345\272\246", nullptr));
        label_25->setText(QCoreApplication::translate("TeacherInteractionWidget", "\345\275\223\345\211\215\345\207\272\347\216\260\346\234\200\345\244\232\347\232\204\350\241\250\346\203\205", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("TeacherInteractionWidget", "\346\225\264\344\275\223\346\203\205\345\206\265", nullptr));
        label_29->setText(QString());
        label_30->setText(QCoreApplication::translate("TeacherInteractionWidget", "\346\210\220\345\221\230", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QCoreApplication::translate("TeacherInteractionWidget", "\346\210\220\345\221\230\347\256\241\347\220\206", nullptr));
        function_tabWidget->setTabText(function_tabWidget->indexOf(tab_3), QCoreApplication::translate("TeacherInteractionWidget", "\350\257\276\345\240\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeacherInteractionWidget: public Ui_TeacherInteractionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHER_INTERACTION_WIDGET_H
