/********************************************************************************
** Form generated from reading UI file 'c_mainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_MAINWINDOW_H
#define UI_C_MAINWINDOW_H

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

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *logo_bar_frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *logo;
    QSpacerItem *horizontalSpacer_3;
    QLabel *client_type_text;
    QSpacerItem *horizontalSpacer_2;
    QFrame *title_bar_frame;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *undo_btn;
    QPushButton *redo_btn;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *minus_btn;
    QPushButton *full_or_normal_btn;
    QPushButton *close_btn;
    QGridLayout *widget_layout;
    QFrame *status_bar;
    QHBoxLayout *horizontalLayout_3;
    QLabel *version_text;
    QLabel *resize_icon;
    QFrame *nav_bar_frame;
    QVBoxLayout *verticalLayout;
    QLabel *user_pic;
    QLabel *username_text;
    QPushButton *logout_btn;
    QFrame *line;
    QGridLayout *function_button_widget_layout;
    QSpacerItem *verticalSpacer;
    QButtonGroup *list_buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(990, 690);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("QWidget#centralwidget {\n"
"	/*border-image\345\217\257\344\273\245\345\271\263\351\223\272\357\274\210\345\215\263\345\217\257\346\213\211\344\274\270\357\274\211*/\n"
"	border-image: url(:/shadow/Resources/material/shadow/980x680_shadow.png);\n"
"}"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
        logo_bar_frame = new QFrame(centralwidget);
        logo_bar_frame->setObjectName(QString::fromUtf8("logo_bar_frame"));
        logo_bar_frame->setMinimumSize(QSize(155, 40));
        logo_bar_frame->setMaximumSize(QSize(155, 40));
        logo_bar_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #1D2B36;\n"
"	border-bottom: 1px solid #131D24;\n"
"}"));
        logo_bar_frame->setFrameShape(QFrame::StyledPanel);
        logo_bar_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(logo_bar_frame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        logo = new QLabel(logo_bar_frame);
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

        client_type_text = new QLabel(logo_bar_frame);
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


        gridLayout->addWidget(logo_bar_frame, 0, 0, 1, 1);

        title_bar_frame = new QFrame(centralwidget);
        title_bar_frame->setObjectName(QString::fromUtf8("title_bar_frame"));
        title_bar_frame->setMinimumSize(QSize(643, 40));
        title_bar_frame->setMaximumSize(QSize(16777215, 40));
        title_bar_frame->setBaseSize(QSize(0, 0));
        title_bar_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #ffffff;\n"
"}"));
        title_bar_frame->setFrameShape(QFrame::StyledPanel);
        title_bar_frame->setFrameShadow(QFrame::Raised);
        title_bar_frame->setLineWidth(1);
        horizontalLayout_2 = new QHBoxLayout(title_bar_frame);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        undo_btn = new QPushButton(title_bar_frame);
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
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/button/Resources/material/button/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        undo_btn->setIcon(icon);

        horizontalLayout_2->addWidget(undo_btn);

        redo_btn = new QPushButton(title_bar_frame);
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/button/Resources/material/button/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        redo_btn->setIcon(icon1);

        horizontalLayout_2->addWidget(redo_btn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        minus_btn = new QPushButton(title_bar_frame);
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/button/Resources/material/button/minus.png"), QSize(), QIcon::Normal, QIcon::Off);
        minus_btn->setIcon(icon2);

        horizontalLayout_2->addWidget(minus_btn);

        full_or_normal_btn = new QPushButton(title_bar_frame);
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
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/button/Resources/material/button/full.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/button/Resources/material/button/full.png"), QSize(), QIcon::Active, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/button/Resources/material/button/normal.png"), QSize(), QIcon::Active, QIcon::On);
        full_or_normal_btn->setIcon(icon3);
        full_or_normal_btn->setCheckable(true);

        horizontalLayout_2->addWidget(full_or_normal_btn);

        close_btn = new QPushButton(title_bar_frame);
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
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/button/Resources/material/button/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        close_btn->setIcon(icon4);

        horizontalLayout_2->addWidget(close_btn);


        gridLayout->addWidget(title_bar_frame, 0, 1, 1, 1);

        widget_layout = new QGridLayout();
        widget_layout->setSpacing(0);
        widget_layout->setObjectName(QString::fromUtf8("widget_layout"));

        gridLayout->addLayout(widget_layout, 1, 1, 1, 1);

        status_bar = new QFrame(centralwidget);
        status_bar->setObjectName(QString::fromUtf8("status_bar"));
        status_bar->setMinimumSize(QSize(0, 15));
        status_bar->setMaximumSize(QSize(16777215, 15));
        status_bar->setFont(font);
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
        version_text->setMinimumSize(QSize(0, 10));
        version_text->setMaximumSize(QSize(16777215, 10));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(8);
        version_text->setFont(font1);
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


        gridLayout->addWidget(status_bar, 2, 1, 1, 1);

        nav_bar_frame = new QFrame(centralwidget);
        nav_bar_frame->setObjectName(QString::fromUtf8("nav_bar_frame"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nav_bar_frame->sizePolicy().hasHeightForWidth());
        nav_bar_frame->setSizePolicy(sizePolicy);
        nav_bar_frame->setMinimumSize(QSize(155, 638));
        nav_bar_frame->setMaximumSize(QSize(155, 16777215));
        nav_bar_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #1D2B36;\n"
"}\n"
"\n"
"QPushButton { \n"
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
        nav_bar_frame->setFrameShape(QFrame::StyledPanel);
        nav_bar_frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(nav_bar_frame);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        user_pic = new QLabel(nav_bar_frame);
        user_pic->setObjectName(QString::fromUtf8("user_pic"));
        user_pic->setMinimumSize(QSize(90, 90));
        user_pic->setMaximumSize(QSize(90, 90));
        user_pic->setFont(font);
        user_pic->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: white;\n"
"}"));
        user_pic->setScaledContents(true);
        user_pic->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(user_pic, 0, Qt::AlignHCenter);

        username_text = new QLabel(nav_bar_frame);
        username_text->setObjectName(QString::fromUtf8("username_text"));
        username_text->setFont(font);
        username_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #ffffff;\n"
"	background: none;\n"
"}"));
        username_text->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(username_text);

        logout_btn = new QPushButton(nav_bar_frame);
        logout_btn->setObjectName(QString::fromUtf8("logout_btn"));
        logout_btn->setMinimumSize(QSize(20, 20));
        logout_btn->setMaximumSize(QSize(20, 20));
        logout_btn->setCursor(QCursor(Qt::PointingHandCursor));
        logout_btn->setStyleSheet(QString::fromUtf8("QPushButton { \n"
"	text-align: center;\n"
"	padding: 0px 0px 0px 0px;\n"
"	border: none;\n"
"	color:  #79A0BA;;\n"
"	background: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background: none;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background: none;\n"
"	border: none;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/button/Resources/material/button/logout.png"), QSize(), QIcon::Normal, QIcon::Off);
        logout_btn->setIcon(icon5);
        logout_btn->setIconSize(QSize(10, 15));

        verticalLayout->addWidget(logout_btn, 0, Qt::AlignHCenter);

        line = new QFrame(nav_bar_frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        function_button_widget_layout = new QGridLayout();
        function_button_widget_layout->setObjectName(QString::fromUtf8("function_button_widget_layout"));

        verticalLayout->addLayout(function_button_widget_layout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addWidget(nav_bar_frame, 1, 0, 2, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        logo->setText(QString());
        client_type_text->setText(QCoreApplication::translate("MainWindow", "Client Type", nullptr));
#if QT_CONFIG(tooltip)
        undo_btn->setToolTip(QCoreApplication::translate("MainWindow", "\345\220\216\351\200\200", nullptr));
#endif // QT_CONFIG(tooltip)
        undo_btn->setText(QString());
#if QT_CONFIG(tooltip)
        redo_btn->setToolTip(QCoreApplication::translate("MainWindow", "\345\211\215\350\277\233", nullptr));
#endif // QT_CONFIG(tooltip)
        redo_btn->setText(QString());
#if QT_CONFIG(tooltip)
        minus_btn->setToolTip(QCoreApplication::translate("MainWindow", "\346\234\200\345\260\217\345\214\226", nullptr));
#endif // QT_CONFIG(tooltip)
        minus_btn->setText(QString());
#if QT_CONFIG(tooltip)
        full_or_normal_btn->setToolTip(QCoreApplication::translate("MainWindow", "\346\234\200\345\244\247\345\214\226", nullptr));
#endif // QT_CONFIG(tooltip)
        full_or_normal_btn->setText(QString());
#if QT_CONFIG(tooltip)
        close_btn->setToolTip(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        close_btn->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        close_btn->setText(QString());
        version_text->setText(QCoreApplication::translate("MainWindow", "Version 1.0.0", nullptr));
        resize_icon->setText(QString());
        user_pic->setText(QCoreApplication::translate("MainWindow", "pic", nullptr));
        username_text->setText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        logout_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_MAINWINDOW_H
