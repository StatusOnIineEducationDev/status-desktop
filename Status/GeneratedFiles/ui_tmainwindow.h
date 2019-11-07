/********************************************************************************
** Form generated from reading UI file 'tmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TMAINWINDOW_H
#define UI_TMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TMainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QFrame *title_logo_bar;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *logo;
    QSpacerItem *horizontalSpacer_3;
    QLabel *client_type_text;
    QSpacerItem *horizontalSpacer_2;
    QFrame *nav_bar;
    QVBoxLayout *verticalLayout;
    QLabel *user_pic;
    QLabel *username_text;
    QPushButton *logout_btn;
    QFrame *line;
    QLabel *function_navigation_text;
    QPushButton *course_btn;
    QPushButton *interaction_btn;
    QPushButton *history_btn;
    QFrame *line_2;
    QLabel *other_navigation_text;
    QPushButton *setting_btn;
    QPushButton *document_btn;
    QSpacerItem *verticalSpacer;
    QFrame *main_area;
    QGridLayout *gridLayout_4;
    QGridLayout *widget_layout;
    QFrame *status_bar;
    QHBoxLayout *horizontalLayout_3;
    QLabel *version_text;
    QLabel *resize_icon;
    QFrame *title_bar;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *undo_btn;
    QPushButton *redo_btn;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *minus_btn;
    QPushButton *full_or_normal_btn;
    QPushButton *close_btn;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *TMainWindow)
    {
        if (TMainWindow->objectName().isEmpty())
            TMainWindow->setObjectName(QString::fromUtf8("TMainWindow"));
        TMainWindow->resize(990, 698);
        TMainWindow->setMinimumSize(QSize(990, 698));
        TMainWindow->setMaximumSize(QSize(16777215, 16777215));
        TMainWindow->setBaseSize(QSize(990, 698));
        centralwidget = new QWidget(TMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("QWidget#centralwidget {\n"
"	/*border-image\345\217\257\344\273\245\345\271\263\351\223\272\357\274\210\345\215\263\345\217\257\346\213\211\344\274\270\357\274\211*/\n"
"	border-image: url(:/shadow/Resources/material/shadow/980x680_shadow.png);\n"
"}"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        title_logo_bar = new QFrame(centralwidget);
        title_logo_bar->setObjectName(QString::fromUtf8("title_logo_bar"));
        title_logo_bar->setMinimumSize(QSize(155, 40));
        title_logo_bar->setMaximumSize(QSize(155, 40));
        title_logo_bar->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #1D2B36;\n"
"	border-bottom: 1px solid #131D24;\n"
"}"));
        title_logo_bar->setFrameShape(QFrame::StyledPanel);
        title_logo_bar->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(title_logo_bar);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        logo = new QLabel(title_logo_bar);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setMinimumSize(QSize(42, 20));
        logo->setMaximumSize(QSize(42, 20));
        logo->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"}"));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/logo/Resources/material/logo/logo.png")));
        logo->setScaledContents(true);

        horizontalLayout->addWidget(logo);

        horizontalSpacer_3 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        client_type_text = new QLabel(title_logo_bar);
        client_type_text->setObjectName(QString::fromUtf8("client_type_text"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        client_type_text->setFont(font);
        client_type_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #ffffff;\n"
"}"));
        client_type_text->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(client_type_text);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_2->addWidget(title_logo_bar, 0, 0, 1, 1);

        nav_bar = new QFrame(centralwidget);
        nav_bar->setObjectName(QString::fromUtf8("nav_bar"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nav_bar->sizePolicy().hasHeightForWidth());
        nav_bar->setSizePolicy(sizePolicy);
        nav_bar->setMinimumSize(QSize(155, 638));
        nav_bar->setMaximumSize(QSize(155, 16777215));
        nav_bar->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #1D2B36;\n"
"}"));
        nav_bar->setFrameShape(QFrame::StyledPanel);
        nav_bar->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(nav_bar);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        user_pic = new QLabel(nav_bar);
        user_pic->setObjectName(QString::fromUtf8("user_pic"));
        user_pic->setMinimumSize(QSize(90, 90));
        user_pic->setMaximumSize(QSize(90, 90));
        user_pic->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"}"));
        user_pic->setPixmap(QPixmap(QString::fromUtf8(":/pic/Resources/material/pic/teacher.png")));
        user_pic->setScaledContents(true);

        verticalLayout->addWidget(user_pic, 0, Qt::AlignHCenter);

        username_text = new QLabel(nav_bar);
        username_text->setObjectName(QString::fromUtf8("username_text"));
        username_text->setFont(font);
        username_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #ffffff;\n"
"	background: none;\n"
"}"));
        username_text->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(username_text);

        logout_btn = new QPushButton(nav_bar);
        logout_btn->setObjectName(QString::fromUtf8("logout_btn"));
        logout_btn->setMinimumSize(QSize(20, 20));
        logout_btn->setMaximumSize(QSize(20, 20));
        logout_btn->setCursor(QCursor(Qt::PointingHandCursor));
        logout_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/button/Resources/material/button/logout.png"), QSize(), QIcon::Normal, QIcon::Off);
        logout_btn->setIcon(icon);
        logout_btn->setIconSize(QSize(10, 15));

        verticalLayout->addWidget(logout_btn, 0, Qt::AlignHCenter);

        line = new QFrame(nav_bar);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        function_navigation_text = new QLabel(nav_bar);
        function_navigation_text->setObjectName(QString::fromUtf8("function_navigation_text"));
        function_navigation_text->setMinimumSize(QSize(155, 30));
        function_navigation_text->setMaximumSize(QSize(155, 30));
        function_navigation_text->setFont(font);
        function_navigation_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #5b788c;\n"
"}"));
        function_navigation_text->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(function_navigation_text);

        course_btn = new QPushButton(nav_bar);
        buttonGroup = new QButtonGroup(TMainWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(course_btn);
        course_btn->setObjectName(QString::fromUtf8("course_btn"));
        course_btn->setMinimumSize(QSize(155, 30));
        course_btn->setMaximumSize(QSize(155, 30));
        course_btn->setFont(font);
        course_btn->setCursor(QCursor(Qt::PointingHandCursor));
        course_btn->setStyleSheet(QString::fromUtf8("QPushButton { \n"
"	text-align: left;\n"
"	padding-left: 15px;\n"
"	border: none;\n"
"	color:  #79A0BA;;\n"
"	background-color: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #385368;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #537b9b;\n"
"	border-left: 5px solid #699BC3;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/button/Resources/material/button/course.png"), QSize(), QIcon::Normal, QIcon::Off);
        course_btn->setIcon(icon1);
        course_btn->setIconSize(QSize(18, 18));
        course_btn->setCheckable(true);
        course_btn->setChecked(true);

        verticalLayout->addWidget(course_btn);

        interaction_btn = new QPushButton(nav_bar);
        buttonGroup->addButton(interaction_btn);
        interaction_btn->setObjectName(QString::fromUtf8("interaction_btn"));
        interaction_btn->setMinimumSize(QSize(155, 30));
        interaction_btn->setMaximumSize(QSize(155, 30));
        interaction_btn->setFont(font);
        interaction_btn->setCursor(QCursor(Qt::PointingHandCursor));
        interaction_btn->setStyleSheet(QString::fromUtf8("QPushButton { \n"
"	text-align: left;\n"
"	padding-left: 15px;\n"
"	border: none;\n"
"	color:  #79A0BA;;\n"
"	background-color: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #385368;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #537b9b;\n"
"	border-left: 5px solid #699BC3;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/button/Resources/material/button/interaction.png"), QSize(), QIcon::Normal, QIcon::Off);
        interaction_btn->setIcon(icon2);
        interaction_btn->setIconSize(QSize(18, 18));
        interaction_btn->setCheckable(true);

        verticalLayout->addWidget(interaction_btn);

        history_btn = new QPushButton(nav_bar);
        buttonGroup->addButton(history_btn);
        history_btn->setObjectName(QString::fromUtf8("history_btn"));
        history_btn->setMinimumSize(QSize(155, 30));
        history_btn->setMaximumSize(QSize(155, 30));
        history_btn->setFont(font);
        history_btn->setCursor(QCursor(Qt::PointingHandCursor));
        history_btn->setStyleSheet(QString::fromUtf8("QPushButton { \n"
"	text-align: left;\n"
"	padding-left: 15px;\n"
"	border: none;\n"
"	color:  #79A0BA;;\n"
"	background-color: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #385368;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #537b9b;\n"
"	border-left: 5px solid #699BC3;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/button/Resources/material/button/history.png"), QSize(), QIcon::Normal, QIcon::Off);
        history_btn->setIcon(icon3);
        history_btn->setIconSize(QSize(18, 18));
        history_btn->setCheckable(true);

        verticalLayout->addWidget(history_btn);

        line_2 = new QFrame(nav_bar);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        other_navigation_text = new QLabel(nav_bar);
        other_navigation_text->setObjectName(QString::fromUtf8("other_navigation_text"));
        other_navigation_text->setMinimumSize(QSize(155, 30));
        other_navigation_text->setMaximumSize(QSize(155, 30));
        other_navigation_text->setFont(font);
        other_navigation_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #5b788c;\n"
"}"));
        other_navigation_text->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(other_navigation_text);

        setting_btn = new QPushButton(nav_bar);
        buttonGroup->addButton(setting_btn);
        setting_btn->setObjectName(QString::fromUtf8("setting_btn"));
        setting_btn->setMinimumSize(QSize(155, 30));
        setting_btn->setMaximumSize(QSize(155, 30));
        setting_btn->setFont(font);
        setting_btn->setCursor(QCursor(Qt::PointingHandCursor));
        setting_btn->setStyleSheet(QString::fromUtf8("QPushButton { \n"
"	text-align: left;\n"
"	padding-left: 15px;\n"
"	border: none;\n"
"	color:  #79A0BA;;\n"
"	background-color: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #385368;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #537b9b;\n"
"	border-left: 5px solid #699BC3;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/button/Resources/material/button/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        setting_btn->setIcon(icon4);
        setting_btn->setIconSize(QSize(18, 18));
        setting_btn->setCheckable(true);

        verticalLayout->addWidget(setting_btn);

        document_btn = new QPushButton(nav_bar);
        buttonGroup->addButton(document_btn);
        document_btn->setObjectName(QString::fromUtf8("document_btn"));
        document_btn->setMinimumSize(QSize(155, 30));
        document_btn->setMaximumSize(QSize(155, 30));
        document_btn->setFont(font);
        document_btn->setCursor(QCursor(Qt::PointingHandCursor));
        document_btn->setStyleSheet(QString::fromUtf8("QPushButton { \n"
"	text-align: left;\n"
"	padding-left: 15px;\n"
"	border: none;\n"
"	color:  #79A0BA;;\n"
"	background-color: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #385368;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #537b9b;\n"
"	border-left: 5px solid #699BC3;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/button/Resources/material/button/document.png"), QSize(), QIcon::Normal, QIcon::Off);
        document_btn->setIcon(icon5);
        document_btn->setIconSize(QSize(18, 18));
        document_btn->setCheckable(true);

        verticalLayout->addWidget(document_btn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout_2->addWidget(nav_bar, 1, 0, 1, 1);

        main_area = new QFrame(centralwidget);
        main_area->setObjectName(QString::fromUtf8("main_area"));
        main_area->setMinimumSize(QSize(823, 638));
        main_area->setMaximumSize(QSize(16777215, 16777215));
        main_area->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #F3F4F8;\n"
"}"));
        main_area->setFrameShape(QFrame::StyledPanel);
        main_area->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(main_area);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_layout = new QGridLayout();
        widget_layout->setSpacing(0);
        widget_layout->setObjectName(QString::fromUtf8("widget_layout"));

        gridLayout_4->addLayout(widget_layout, 0, 0, 1, 2);

        status_bar = new QFrame(main_area);
        status_bar->setObjectName(QString::fromUtf8("status_bar"));
        status_bar->setMinimumSize(QSize(0, 15));
        status_bar->setMaximumSize(QSize(16777215, 15));
        status_bar->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border-top: 1px solid #E8ECEC;\n"
"	background-color: #ffffff;\n"
"}"));
        status_bar->setFrameShape(QFrame::StyledPanel);
        status_bar->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(status_bar);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        version_text = new QLabel(status_bar);
        version_text->setObjectName(QString::fromUtf8("version_text"));
        version_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"}"));

        horizontalLayout_3->addWidget(version_text);

        resize_icon = new QLabel(status_bar);
        resize_icon->setObjectName(QString::fromUtf8("resize_icon"));
        resize_icon->setMinimumSize(QSize(10, 10));
        resize_icon->setMaximumSize(QSize(10, 10));
        resize_icon->setCursor(QCursor(Qt::SizeFDiagCursor));
        resize_icon->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"}"));
        resize_icon->setPixmap(QPixmap(QString::fromUtf8(":/button/Resources/material/button/resize.png")));
        resize_icon->setScaledContents(true);
        resize_icon->setMargin(0);

        horizontalLayout_3->addWidget(resize_icon);


        gridLayout_4->addWidget(status_bar, 2, 0, 1, 2);


        gridLayout_2->addWidget(main_area, 1, 1, 1, 4);

        title_bar = new QFrame(centralwidget);
        title_bar->setObjectName(QString::fromUtf8("title_bar"));
        title_bar->setMinimumSize(QSize(643, 40));
        title_bar->setMaximumSize(QSize(16777215, 40));
        title_bar->setBaseSize(QSize(0, 0));
        title_bar->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #ffffff;\n"
"}"));
        title_bar->setFrameShape(QFrame::StyledPanel);
        title_bar->setFrameShadow(QFrame::Raised);
        title_bar->setLineWidth(1);
        horizontalLayout_2 = new QHBoxLayout(title_bar);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        undo_btn = new QPushButton(title_bar);
        undo_btn->setObjectName(QString::fromUtf8("undo_btn"));
        undo_btn->setMinimumSize(QSize(20, 20));
        undo_btn->setMaximumSize(QSize(20, 20));
        undo_btn->setCursor(QCursor(Qt::PointingHandCursor));
        undo_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: none;\n"
"	border: 1px solid #f0f0f0;\n"
"	border-top-left-radius: 3px;\n"
"	border-bottom-left-radius: 3px;\n"
"}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/button/Resources/material/button/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        undo_btn->setIcon(icon6);

        horizontalLayout_2->addWidget(undo_btn);

        redo_btn = new QPushButton(title_bar);
        redo_btn->setObjectName(QString::fromUtf8("redo_btn"));
        redo_btn->setMinimumSize(QSize(20, 20));
        redo_btn->setMaximumSize(QSize(20, 20));
        redo_btn->setCursor(QCursor(Qt::PointingHandCursor));
        redo_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: none;\n"
"	border: 1px solid #f0f0f0;\n"
"	border-left: none;\n"
"	border-top-right-radius: 3px;\n"
"	border-bottom-right-radius: 3px;\n"
"}"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/button/Resources/material/button/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        redo_btn->setIcon(icon7);

        horizontalLayout_2->addWidget(redo_btn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        minus_btn = new QPushButton(title_bar);
        minus_btn->setObjectName(QString::fromUtf8("minus_btn"));
        minus_btn->setMinimumSize(QSize(50, 40));
        minus_btn->setMaximumSize(QSize(50, 40));
        minus_btn->setCursor(QCursor(Qt::PointingHandCursor));
        minus_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	background-color: #ffffff;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #8F8F8F;\n"
"}"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/button/Resources/material/button/minus.png"), QSize(), QIcon::Normal, QIcon::Off);
        minus_btn->setIcon(icon8);

        horizontalLayout_2->addWidget(minus_btn);

        full_or_normal_btn = new QPushButton(title_bar);
        full_or_normal_btn->setObjectName(QString::fromUtf8("full_or_normal_btn"));
        full_or_normal_btn->setMinimumSize(QSize(50, 40));
        full_or_normal_btn->setMaximumSize(QSize(50, 40));
        full_or_normal_btn->setCursor(QCursor(Qt::PointingHandCursor));
        full_or_normal_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	background-color: #ffffff;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #8F8F8F;\n"
"}"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/button/Resources/material/button/full.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon9.addFile(QString::fromUtf8(":/button/Resources/material/button/full.png"), QSize(), QIcon::Active, QIcon::Off);
        icon9.addFile(QString::fromUtf8(":/button/Resources/material/button/normal.png"), QSize(), QIcon::Active, QIcon::On);
        full_or_normal_btn->setIcon(icon9);
        full_or_normal_btn->setCheckable(true);

        horizontalLayout_2->addWidget(full_or_normal_btn);

        close_btn = new QPushButton(title_bar);
        close_btn->setObjectName(QString::fromUtf8("close_btn"));
        close_btn->setMinimumSize(QSize(50, 40));
        close_btn->setMaximumSize(QSize(50, 40));
        close_btn->setCursor(QCursor(Qt::PointingHandCursor));
        close_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	background-color: #ffffff;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(244, 84, 84);\n"
"}"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/button/Resources/material/button/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        close_btn->setIcon(icon10);

        horizontalLayout_2->addWidget(close_btn);


        gridLayout_2->addWidget(title_bar, 0, 1, 1, 4);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        TMainWindow->setCentralWidget(centralwidget);

        retranslateUi(TMainWindow);
        QObject::connect(close_btn, SIGNAL(clicked()), TMainWindow, SLOT(close()));
        QObject::connect(minus_btn, SIGNAL(clicked()), TMainWindow, SLOT(showMinimized()));

        QMetaObject::connectSlotsByName(TMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TMainWindow)
    {
        TMainWindow->setWindowTitle(QCoreApplication::translate("TMainWindow", "MainWindow", nullptr));
        logo->setText(QString());
        client_type_text->setText(QCoreApplication::translate("TMainWindow", "\346\225\231\345\270\210\347\253\257", nullptr));
        user_pic->setText(QString());
        username_text->setText(QCoreApplication::translate("TMainWindow", "\346\210\221\346\230\257\344\275\240\347\210\270\347\210\270", nullptr));
        logout_btn->setText(QString());
        function_navigation_text->setText(QCoreApplication::translate("TMainWindow", "   \345\212\237\350\203\275\350\217\234\345\215\225", nullptr));
        course_btn->setText(QCoreApplication::translate("TMainWindow", " \350\257\276\347\250\213\347\256\241\347\220\206", nullptr));
        interaction_btn->setText(QCoreApplication::translate("TMainWindow", " \345\234\250\347\272\277\346\225\231\345\256\244", nullptr));
        history_btn->setText(QCoreApplication::translate("TMainWindow", " \345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        other_navigation_text->setText(QCoreApplication::translate("TMainWindow", "   \345\205\266\344\273\226", nullptr));
        setting_btn->setText(QCoreApplication::translate("TMainWindow", " \350\256\276\347\275\256", nullptr));
        document_btn->setText(QCoreApplication::translate("TMainWindow", " \344\275\277\347\224\250\345\270\256\345\212\251", nullptr));
        version_text->setText(QCoreApplication::translate("TMainWindow", "Version 1.0.0", nullptr));
        resize_icon->setText(QString());
#if QT_CONFIG(tooltip)
        undo_btn->setToolTip(QCoreApplication::translate("TMainWindow", "\345\220\216\351\200\200", nullptr));
#endif // QT_CONFIG(tooltip)
        undo_btn->setText(QString());
#if QT_CONFIG(tooltip)
        redo_btn->setToolTip(QCoreApplication::translate("TMainWindow", "\345\211\215\350\277\233", nullptr));
#endif // QT_CONFIG(tooltip)
        redo_btn->setText(QString());
#if QT_CONFIG(tooltip)
        minus_btn->setToolTip(QCoreApplication::translate("TMainWindow", "\346\234\200\345\260\217\345\214\226", nullptr));
#endif // QT_CONFIG(tooltip)
        minus_btn->setText(QString());
#if QT_CONFIG(tooltip)
        full_or_normal_btn->setToolTip(QCoreApplication::translate("TMainWindow", "\346\234\200\345\244\247\345\214\226", nullptr));
#endif // QT_CONFIG(tooltip)
        full_or_normal_btn->setText(QString());
#if QT_CONFIG(tooltip)
        close_btn->setToolTip(QCoreApplication::translate("TMainWindow", "\345\205\263\351\227\255", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        close_btn->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        close_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TMainWindow: public Ui_TMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TMAINWINDOW_H
