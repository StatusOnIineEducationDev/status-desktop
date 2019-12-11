/********************************************************************************
** Form generated from reading UI file 'c_loginWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_LOGINWINDOW_H
#define UI_C_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *background_frame;
    QFrame *main_frame;
    QGridLayout *gridLayout_2;
    QFrame *miniprogram_frame;
    QGridLayout *gridLayout_4;
    QLabel *miniprogram_code_pic;
    QFrame *text_frame;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame_4;
    QGridLayout *gridLayout_5;
    QPushButton *forget_password_btn;
    QFrame *password_frame;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *password_edit;
    QPushButton *confirm_btn;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *teacher_btn;
    QPushButton *student_btn;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QCheckBox *student_checkBox;
    QCheckBox *teacher_checkBox;
    QSpacerItem *verticalSpacer_3;
    QFrame *account_frame;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *account_edit;
    QPushButton *register_btn;
    QLabel *warn_text;
    QLabel *logo_pic;
    QLabel *point_1;
    QLabel *point_2;
    QLabel *point_3;
    QFrame *title_bar_frame;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *minus_btn;
    QPushButton *close_btn;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(610, 410);
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("QWidget#centralwidget {\n"
"	/*border-image\345\217\257\344\273\245\345\271\263\351\223\272\357\274\210\345\215\263\345\217\257\346\213\211\344\274\270\357\274\211*/\n"
"	border-image: url(:/shadow/Resources/material/shadow/600x400_shadow.png);\n"
"}"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
        background_frame = new QFrame(centralwidget);
        background_frame->setObjectName(QString::fromUtf8("background_frame"));
        background_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: #1D2B36;\n"
"}\n"
""));
        background_frame->setFrameShape(QFrame::StyledPanel);
        background_frame->setFrameShadow(QFrame::Raised);
        main_frame = new QFrame(background_frame);
        main_frame->setObjectName(QString::fromUtf8("main_frame"));
        main_frame->setGeometry(QRect(0, 40, 600, 320));
        main_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: #ffffff;\n"
"	border-top-left-radius: 20px;\n"
"	border-top-right-radius: 20px;\n"
"}"));
        main_frame->setFrameShape(QFrame::StyledPanel);
        main_frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(main_frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        miniprogram_frame = new QFrame(main_frame);
        miniprogram_frame->setObjectName(QString::fromUtf8("miniprogram_frame"));
        miniprogram_frame->setMinimumSize(QSize(250, 0));
        miniprogram_frame->setMaximumSize(QSize(250, 16777215));
        miniprogram_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: none;\n"
"	border:none;\n"
"	border-radius: 0px;\n"
"}"));
        miniprogram_frame->setFrameShape(QFrame::StyledPanel);
        miniprogram_frame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(miniprogram_frame);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(20, -1, 20, -1);
        miniprogram_code_pic = new QLabel(miniprogram_frame);
        miniprogram_code_pic->setObjectName(QString::fromUtf8("miniprogram_code_pic"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        miniprogram_code_pic->setFont(font);
        miniprogram_code_pic->setStyleSheet(QString::fromUtf8("color: #333333;"));
        miniprogram_code_pic->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(miniprogram_code_pic, 1, 0, 1, 1);

        text_frame = new QFrame(miniprogram_frame);
        text_frame->setObjectName(QString::fromUtf8("text_frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(text_frame->sizePolicy().hasHeightForWidth());
        text_frame->setSizePolicy(sizePolicy);
        text_frame->setFrameShape(QFrame::StyledPanel);
        text_frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(text_frame);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_2 = new QLabel(text_frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(20, 20));
        label_2->setMaximumSize(QSize(20, 20));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/pic/Resources/material/pic/scan.png")));
        label_2->setScaledContents(true);

        gridLayout_3->addWidget(label_2, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 0, 1, 1);

        label_3 = new QLabel(text_frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color: #333333;"));

        gridLayout_3->addWidget(label_3, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 3, 1, 1);


        gridLayout_4->addWidget(text_frame, 0, 0, 1, 1);


        gridLayout_2->addWidget(miniprogram_frame, 0, 0, 1, 1);

        frame_4 = new QFrame(main_frame);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: none;\n"
"	border:none;\n"
"	border-radius: 0px;\n"
"}"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(20, -1, 20, -1);
        forget_password_btn = new QPushButton(frame_4);
        forget_password_btn->setObjectName(QString::fromUtf8("forget_password_btn"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(forget_password_btn->sizePolicy().hasHeightForWidth());
        forget_password_btn->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        forget_password_btn->setFont(font2);
        forget_password_btn->setCursor(QCursor(Qt::PointingHandCursor));
        forget_password_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	color: #666666;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	color: #1296d6;\n"
"}"));

        gridLayout_5->addWidget(forget_password_btn, 8, 4, 1, 1);

        password_frame = new QFrame(frame_4);
        password_frame->setObjectName(QString::fromUtf8("password_frame"));
        password_frame->setMinimumSize(QSize(0, 40));
        password_frame->setMaximumSize(QSize(16777215, 40));
        password_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border-bottom: 1px solid rgb(187, 187, 187);\n"
"}\n"
"\n"
"QFrame:hover {\n"
"	border-bottom: 1px solid #1296d6;\n"
"}"));
        password_frame->setFrameShape(QFrame::StyledPanel);
        password_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(password_frame);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(password_frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(20, 20));
        label_4->setMaximumSize(QSize(20, 20));
        label_4->setStyleSheet(QString::fromUtf8("border: none;\n"
"background: none;"));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/pic/Resources/material/pic/password.png")));
        label_4->setScaledContents(true);

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        password_edit = new QLineEdit(password_frame);
        password_edit->setObjectName(QString::fromUtf8("password_edit"));
        password_edit->setMinimumSize(QSize(0, 35));
        password_edit->setMaximumSize(QSize(16777215, 35));
        password_edit->setFont(font);
        password_edit->setCursor(QCursor(Qt::IBeamCursor));
        password_edit->setStyleSheet(QString::fromUtf8("border: none;\n"
"color: #666666;"));
        password_edit->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(password_edit);


        gridLayout_5->addWidget(password_frame, 3, 0, 1, 5);

        confirm_btn = new QPushButton(frame_4);
        confirm_btn->setObjectName(QString::fromUtf8("confirm_btn"));
        confirm_btn->setMinimumSize(QSize(0, 35));
        confirm_btn->setMaximumSize(QSize(16777215, 35));
        confirm_btn->setFont(font2);
        confirm_btn->setCursor(QCursor(Qt::PointingHandCursor));
        confirm_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #1296d6;\n"
"	background: none;\n"
"	border: 1px solid rgba(18, 150, 214, 130);\n"
"	border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	border: 1px solid #1296d6;\n"
"	color: #1296d6;\n"
"}"));

        gridLayout_5->addWidget(confirm_btn, 6, 0, 1, 5);

        frame_2 = new QFrame(frame_4);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_2);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        teacher_btn = new QPushButton(frame_2);
        buttonGroup = new QButtonGroup(LoginWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(teacher_btn);
        teacher_btn->setObjectName(QString::fromUtf8("teacher_btn"));
        teacher_btn->setMinimumSize(QSize(120, 50));
        teacher_btn->setMaximumSize(QSize(120, 50));
        teacher_btn->setFont(font2);
        teacher_btn->setCursor(QCursor(Qt::PointingHandCursor));
        teacher_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #999999;\n"
"	background: none;\n"
"	border: none;\n"
"	border-radius: 25px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background: rgba(18, 150, 214, 20);\n"
"	color: #1296d6;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background: rgba(18, 150, 214, 50);\n"
"	color: #1296d6;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pic/Resources/material/pic/teacher.png"), QSize(), QIcon::Normal, QIcon::Off);
        teacher_btn->setIcon(icon);
        teacher_btn->setIconSize(QSize(35, 35));
        teacher_btn->setCheckable(true);
        teacher_btn->setChecked(true);

        horizontalLayout_5->addWidget(teacher_btn);

        student_btn = new QPushButton(frame_2);
        buttonGroup->addButton(student_btn);
        student_btn->setObjectName(QString::fromUtf8("student_btn"));
        student_btn->setMinimumSize(QSize(120, 50));
        student_btn->setMaximumSize(QSize(120, 50));
        student_btn->setFont(font2);
        student_btn->setCursor(QCursor(Qt::PointingHandCursor));
        student_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #999999;\n"
"	background: none;\n"
"	border: none;\n"
"	border-radius: 25px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background: rgba(18, 150, 214, 20);\n"
"	color: #1296d6;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background: rgba(18, 150, 214, 50);\n"
"	color: #1296d6;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/pic/Resources/material/pic/student.png"), QSize(), QIcon::Normal, QIcon::Off);
        student_btn->setIcon(icon1);
        student_btn->setIconSize(QSize(35, 35));
        student_btn->setCheckable(true);
        student_btn->setChecked(false);

        horizontalLayout_5->addWidget(student_btn);


        gridLayout_5->addWidget(frame_2, 0, 0, 1, 5);

        frame = new QFrame(frame_4);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        student_checkBox = new QCheckBox(frame);
        student_checkBox->setObjectName(QString::fromUtf8("student_checkBox"));
        sizePolicy2.setHeightForWidth(student_checkBox->sizePolicy().hasHeightForWidth());
        student_checkBox->setSizePolicy(sizePolicy2);
        student_checkBox->setFont(font2);
        student_checkBox->setCursor(QCursor(Qt::PointingHandCursor));
        student_checkBox->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	color: #666666;\n"
"}\n"
"\n"
"QCheckBox:hover {\n"
"	color: #1296d6;\n"
"}"));
        student_checkBox->setAutoExclusive(false);
        student_checkBox->setTristate(false);

        horizontalLayout->addWidget(student_checkBox);

        teacher_checkBox = new QCheckBox(frame);
        teacher_checkBox->setObjectName(QString::fromUtf8("teacher_checkBox"));
        sizePolicy2.setHeightForWidth(teacher_checkBox->sizePolicy().hasHeightForWidth());
        teacher_checkBox->setSizePolicy(sizePolicy2);
        teacher_checkBox->setFont(font2);
        teacher_checkBox->setCursor(QCursor(Qt::PointingHandCursor));
        teacher_checkBox->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	color: #666666;\n"
"}\n"
"\n"
"QCheckBox:hover {\n"
"	color: #1296d6;\n"
"}"));

        horizontalLayout->addWidget(teacher_checkBox);


        gridLayout_5->addWidget(frame, 5, 0, 1, 5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_3, 1, 1, 1, 3);

        account_frame = new QFrame(frame_4);
        account_frame->setObjectName(QString::fromUtf8("account_frame"));
        account_frame->setMinimumSize(QSize(0, 40));
        account_frame->setMaximumSize(QSize(16777215, 40));
        account_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border-bottom: 1px solid rgb(187, 187, 187);\n"
"}\n"
"\n"
"QFrame:hover {\n"
"	border-bottom: 1px solid #1296d6;\n"
"}"));
        account_frame->setFrameShape(QFrame::StyledPanel);
        account_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(account_frame);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(account_frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(20, 20));
        label->setMaximumSize(QSize(20, 20));
        label->setStyleSheet(QString::fromUtf8("border: none;\n"
"background: none;"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/pic/Resources/material/pic/account.png")));
        label->setScaledContents(true);

        horizontalLayout_3->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        account_edit = new QLineEdit(account_frame);
        account_edit->setObjectName(QString::fromUtf8("account_edit"));
        account_edit->setMinimumSize(QSize(0, 35));
        account_edit->setMaximumSize(QSize(16777215, 35));
        account_edit->setFont(font);
        account_edit->setCursor(QCursor(Qt::IBeamCursor));
        account_edit->setStyleSheet(QString::fromUtf8("border: none;\n"
"color: #666666;"));

        horizontalLayout_3->addWidget(account_edit);


        gridLayout_5->addWidget(account_frame, 2, 0, 1, 5);

        register_btn = new QPushButton(frame_4);
        register_btn->setObjectName(QString::fromUtf8("register_btn"));
        sizePolicy2.setHeightForWidth(register_btn->sizePolicy().hasHeightForWidth());
        register_btn->setSizePolicy(sizePolicy2);
        register_btn->setFont(font2);
        register_btn->setCursor(QCursor(Qt::PointingHandCursor));
        register_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	color: #666666;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	color: #1296d6;\n"
"}"));

        gridLayout_5->addWidget(register_btn, 8, 0, 1, 3);

        warn_text = new QLabel(frame_4);
        warn_text->setObjectName(QString::fromUtf8("warn_text"));
        warn_text->setMinimumSize(QSize(0, 20));
        warn_text->setMaximumSize(QSize(16777215, 20));
        warn_text->setFont(font2);
        warn_text->setStyleSheet(QString::fromUtf8("color: red;"));
        warn_text->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(warn_text, 7, 0, 1, 5);


        gridLayout_2->addWidget(frame_4, 0, 1, 1, 1);

        logo_pic = new QLabel(background_frame);
        logo_pic->setObjectName(QString::fromUtf8("logo_pic"));
        logo_pic->setGeometry(QRect(275, 0, 60, 30));
        logo_pic->setStyleSheet(QString::fromUtf8("background: none;\n"
"border: none;"));
        logo_pic->setPixmap(QPixmap(QString::fromUtf8(":/logo/Resources/material/logo/logo.png")));
        logo_pic->setScaledContents(true);
        point_1 = new QLabel(background_frame);
        point_1->setObjectName(QString::fromUtf8("point_1"));
        point_1->setGeometry(QRect(100, 115, 50, 50));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Adobe Arabic"));
        font3.setPointSize(52);
        font3.setBold(true);
        font3.setWeight(75);
        point_1->setFont(font3);
        point_1->setStyleSheet(QString::fromUtf8("color: white;\n"
"background: none;"));
        point_1->setAlignment(Qt::AlignCenter);
        point_2 = new QLabel(background_frame);
        point_2->setObjectName(QString::fromUtf8("point_2"));
        point_2->setGeometry(QRect(50, 115, 50, 50));
        point_2->setFont(font3);
        point_2->setStyleSheet(QString::fromUtf8("color: white;\n"
"background: none;"));
        point_2->setAlignment(Qt::AlignCenter);
        point_3 = new QLabel(background_frame);
        point_3->setObjectName(QString::fromUtf8("point_3"));
        point_3->setGeometry(QRect(0, 115, 50, 50));
        point_3->setFont(font3);
        point_3->setStyleSheet(QString::fromUtf8("color: white;\n"
"background: none;"));
        point_3->setAlignment(Qt::AlignCenter);
        point_2->raise();
        point_3->raise();
        point_1->raise();
        main_frame->raise();
        logo_pic->raise();

        gridLayout->addWidget(background_frame, 1, 0, 1, 1);

        title_bar_frame = new QFrame(centralwidget);
        title_bar_frame->setObjectName(QString::fromUtf8("title_bar_frame"));
        title_bar_frame->setMinimumSize(QSize(600, 40));
        title_bar_frame->setMaximumSize(QSize(16777215, 40));
        title_bar_frame->setBaseSize(QSize(0, 0));
        title_bar_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: #1D2B36;\n"
"}\n"
""));
        title_bar_frame->setFrameShape(QFrame::StyledPanel);
        title_bar_frame->setFrameShadow(QFrame::Raised);
        title_bar_frame->setLineWidth(1);
        horizontalLayout_2 = new QHBoxLayout(title_bar_frame);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        minus_btn = new QPushButton(title_bar_frame);
        minus_btn->setObjectName(QString::fromUtf8("minus_btn"));
        minus_btn->setMinimumSize(QSize(50, 40));
        minus_btn->setMaximumSize(QSize(50, 40));
        minus_btn->setCursor(QCursor(Qt::PointingHandCursor));
        minus_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	background-color: #1D2B36;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #8F8F8F;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/button/Resources/material/button/minus.png"), QSize(), QIcon::Normal, QIcon::Off);
        minus_btn->setIcon(icon2);

        horizontalLayout_2->addWidget(minus_btn);

        close_btn = new QPushButton(title_bar_frame);
        close_btn->setObjectName(QString::fromUtf8("close_btn"));
        close_btn->setMinimumSize(QSize(50, 40));
        close_btn->setMaximumSize(QSize(50, 40));
        close_btn->setCursor(QCursor(Qt::PointingHandCursor));
        close_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	background-color: #1D2B36;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(244, 84, 84);\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/button/Resources/material/button/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        close_btn->setIcon(icon3);

        horizontalLayout_2->addWidget(close_btn);


        gridLayout->addWidget(title_bar_frame, 0, 0, 1, 1);

        LoginWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(account_edit, password_edit);
        QWidget::setTabOrder(password_edit, student_checkBox);
        QWidget::setTabOrder(student_checkBox, teacher_checkBox);
        QWidget::setTabOrder(teacher_checkBox, confirm_btn);
        QWidget::setTabOrder(confirm_btn, register_btn);
        QWidget::setTabOrder(register_btn, forget_password_btn);
        QWidget::setTabOrder(forget_password_btn, teacher_btn);
        QWidget::setTabOrder(teacher_btn, student_btn);
        QWidget::setTabOrder(student_btn, minus_btn);
        QWidget::setTabOrder(minus_btn, close_btn);

        retranslateUi(LoginWindow);
        QObject::connect(close_btn, SIGNAL(clicked()), LoginWindow, SLOT(close()));
        QObject::connect(minus_btn, SIGNAL(clicked()), LoginWindow, SLOT(showMinimized()));

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "MainWindow", nullptr));
        miniprogram_code_pic->setText(QCoreApplication::translate("LoginWindow", "\345\260\217\347\250\213\345\272\217\347\240\201\345\212\240\350\275\275\345\244\261\350\264\245", nullptr));
        label_2->setText(QString());
        label_3->setText(QCoreApplication::translate("LoginWindow", "\346\211\253\344\270\200\346\211\253\344\275\223\351\252\214\345\260\217\347\250\213\345\272\217", nullptr));
        forget_password_btn->setText(QCoreApplication::translate("LoginWindow", "\345\277\230\350\256\260\345\257\206\347\240\201\357\274\237", nullptr));
        label_4->setText(QString());
        password_edit->setText(QCoreApplication::translate("LoginWindow", "test", nullptr));
        password_edit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\345\257\206\347\240\201", nullptr));
        confirm_btn->setText(QCoreApplication::translate("LoginWindow", "\347\231\273\345\275\225", nullptr));
#if QT_CONFIG(shortcut)
        confirm_btn->setShortcut(QCoreApplication::translate("LoginWindow", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        teacher_btn->setText(QCoreApplication::translate("LoginWindow", "\346\210\221\346\230\257\346\225\231\345\270\210", nullptr));
        student_btn->setText(QCoreApplication::translate("LoginWindow", "\346\210\221\346\230\257\345\255\246\347\224\237", nullptr));
        student_checkBox->setText(QCoreApplication::translate("LoginWindow", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        teacher_checkBox->setText(QCoreApplication::translate("LoginWindow", "\350\207\252\345\212\250\347\231\273\345\275\225", nullptr));
        label->setText(QString());
        account_edit->setText(QCoreApplication::translate("LoginWindow", "test", nullptr));
        account_edit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\350\264\246\345\217\267", nullptr));
        register_btn->setText(QCoreApplication::translate("LoginWindow", "\346\263\250\345\206\214\350\264\246\345\217\267", nullptr));
        warn_text->setText(QString());
        logo_pic->setText(QString());
        point_1->setText(QCoreApplication::translate("LoginWindow", "\302\267", nullptr));
        point_2->setText(QCoreApplication::translate("LoginWindow", "\302\267", nullptr));
        point_3->setText(QCoreApplication::translate("LoginWindow", "\302\267", nullptr));
#if QT_CONFIG(tooltip)
        minus_btn->setToolTip(QCoreApplication::translate("LoginWindow", "\346\234\200\345\260\217\345\214\226", nullptr));
#endif // QT_CONFIG(tooltip)
        minus_btn->setText(QString());
#if QT_CONFIG(tooltip)
        close_btn->setToolTip(QCoreApplication::translate("LoginWindow", "\345\205\263\351\227\255", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        close_btn->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        close_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_LOGINWINDOW_H
