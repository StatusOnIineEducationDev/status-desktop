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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QFrame *login_frame;
    QLineEdit *account_edit;
    QPushButton *confirm_btn;
    QLineEdit *password_edit;
    QLabel *label;
    QLabel *label_2;
    QCheckBox *student_checkBox;
    QCheckBox *teacher_checkBox;
    QLabel *warn_text;
    QFrame *frame_2;
    QPushButton *close_btn;
    QPushButton *minus_btn;
    QLabel *logo_label;
    QLabel *loading_label_1;
    QLabel *loading_label_2;
    QLabel *loading_label_3;
    QLabel *shadow;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(510, 330);
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        login_frame = new QFrame(centralwidget);
        login_frame->setObjectName(QString::fromUtf8("login_frame"));
        login_frame->setGeometry(QRect(5, 120, 500, 205));
        login_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-top-left-radius: 20px;\n"
"	border-top-right-radius: 20px;\n"
"}"));
        login_frame->setFrameShape(QFrame::StyledPanel);
        login_frame->setFrameShadow(QFrame::Raised);
        account_edit = new QLineEdit(login_frame);
        account_edit->setObjectName(QString::fromUtf8("account_edit"));
        account_edit->setGeometry(QRect(100, 20, 300, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        account_edit->setFont(font);
        account_edit->setCursor(QCursor(Qt::IBeamCursor));
        account_edit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border-top: none;\n"
"	border-bottom: 1px solid rgb(187, 187, 187);\n"
"	padding-left: 30px;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"	border-bottom: 1px solid rgb(220, 195, 170);\n"
"}"));
        confirm_btn = new QPushButton(login_frame);
        confirm_btn->setObjectName(QString::fromUtf8("confirm_btn"));
        confirm_btn->setGeometry(QRect(100, 135, 300, 35));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        confirm_btn->setFont(font1);
        confirm_btn->setCursor(QCursor(Qt::PointingHandCursor));
        confirm_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: none;\n"
"	color: rgb(53, 53, 53);\n"
"	border-radius: 15px;\n"
"	border: 1px solid rgb(220, 195, 170);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(220, 195, 170);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	padding-left: 1px;\n"
"	padding-top: 1px;\n"
"}"));
        password_edit = new QLineEdit(login_frame);
        password_edit->setObjectName(QString::fromUtf8("password_edit"));
        password_edit->setGeometry(QRect(100, 70, 300, 30));
        password_edit->setFont(font);
        password_edit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border-top: none;\n"
"	border-bottom: 1px solid rgb(187, 187, 187);\n"
"	padding-left: 30px;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"	border-bottom: 1px solid rgb(220, 195, 170);\n"
"}"));
        password_edit->setEchoMode(QLineEdit::Password);
        label = new QLabel(login_frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 20, 25, 25));
        label->setPixmap(QPixmap(QString::fromUtf8("../../../../../PycharmProjects/Status/resources/icon/login/account.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(login_frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 70, 25, 25));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../../../../PycharmProjects/Status/resources/icon/login/password.png")));
        label_2->setScaledContents(true);
        student_checkBox = new QCheckBox(login_frame);
        buttonGroup = new QButtonGroup(LoginWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(student_checkBox);
        student_checkBox->setObjectName(QString::fromUtf8("student_checkBox"));
        student_checkBox->setGeometry(QRect(170, 107, 60, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(9);
        student_checkBox->setFont(font2);
        student_checkBox->setCursor(QCursor(Qt::PointingHandCursor));
        student_checkBox->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	color: rgb(166, 166, 166);\n"
"}"));
        student_checkBox->setAutoExclusive(false);
        student_checkBox->setTristate(false);
        teacher_checkBox = new QCheckBox(login_frame);
        buttonGroup->addButton(teacher_checkBox);
        teacher_checkBox->setObjectName(QString::fromUtf8("teacher_checkBox"));
        teacher_checkBox->setGeometry(QRect(265, 107, 60, 20));
        teacher_checkBox->setFont(font2);
        teacher_checkBox->setCursor(QCursor(Qt::PointingHandCursor));
        teacher_checkBox->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	color: rgb(166, 166, 166);\n"
"}"));
        warn_text = new QLabel(login_frame);
        warn_text->setObjectName(QString::fromUtf8("warn_text"));
        warn_text->setGeometry(QRect(100, 175, 300, 28));
        warn_text->setStyleSheet(QString::fromUtf8("color: red;"));
        warn_text->setAlignment(Qt::AlignCenter);
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(5, 5, 500, 320));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: rgb(37, 40, 43);\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        close_btn = new QPushButton(frame_2);
        close_btn->setObjectName(QString::fromUtf8("close_btn"));
        close_btn->setGeometry(QRect(440, 0, 60, 45));
        close_btn->setCursor(QCursor(Qt::PointingHandCursor));
        close_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(244, 84, 84);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../../PycharmProjects/Status/resources/icon/main/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        close_btn->setIcon(icon);
        minus_btn = new QPushButton(frame_2);
        minus_btn->setObjectName(QString::fromUtf8("minus_btn"));
        minus_btn->setGeometry(QRect(380, 0, 60, 45));
        minus_btn->setCursor(QCursor(Qt::PointingHandCursor));
        minus_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(100, 100, 100);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../../../PycharmProjects/Status/resources/icon/main/minus.png"), QSize(), QIcon::Normal, QIcon::Off);
        minus_btn->setIcon(icon1);
        logo_label = new QLabel(frame_2);
        logo_label->setObjectName(QString::fromUtf8("logo_label"));
        logo_label->setGeometry(QRect(0, 8, 100, 40));
        logo_label->setPixmap(QPixmap(QString::fromUtf8("../../../../../PycharmProjects/Status/resources/pic/logo.png")));
        logo_label->setScaledContents(true);
        logo_label->setAlignment(Qt::AlignCenter);
        loading_label_1 = new QLabel(frame_2);
        loading_label_1->setObjectName(QString::fromUtf8("loading_label_1"));
        loading_label_1->setGeometry(QRect(100, 115, 50, 50));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Adobe Arabic"));
        font3.setPointSize(52);
        font3.setBold(true);
        font3.setWeight(75);
        loading_label_1->setFont(font3);
        loading_label_1->setStyleSheet(QString::fromUtf8("color: white;\n"
"background: none;"));
        loading_label_1->setAlignment(Qt::AlignCenter);
        loading_label_2 = new QLabel(frame_2);
        loading_label_2->setObjectName(QString::fromUtf8("loading_label_2"));
        loading_label_2->setGeometry(QRect(50, 115, 50, 50));
        loading_label_2->setFont(font3);
        loading_label_2->setStyleSheet(QString::fromUtf8("color: white;\n"
"background: none;"));
        loading_label_2->setAlignment(Qt::AlignCenter);
        loading_label_3 = new QLabel(frame_2);
        loading_label_3->setObjectName(QString::fromUtf8("loading_label_3"));
        loading_label_3->setGeometry(QRect(0, 115, 50, 50));
        loading_label_3->setFont(font3);
        loading_label_3->setStyleSheet(QString::fromUtf8("color: white;\n"
"background: none;"));
        loading_label_3->setAlignment(Qt::AlignCenter);
        shadow = new QLabel(centralwidget);
        shadow->setObjectName(QString::fromUtf8("shadow"));
        shadow->setGeometry(QRect(0, 0, 510, 330));
        shadow->setPixmap(QPixmap(QString::fromUtf8("../../../../../PycharmProjects/Status/resources/pic/login_win_shadow.png")));
        shadow->setScaledContents(true);
        LoginWindow->setCentralWidget(centralwidget);
        shadow->raise();
        frame_2->raise();
        login_frame->raise();
        QWidget::setTabOrder(account_edit, password_edit);
        QWidget::setTabOrder(password_edit, student_checkBox);
        QWidget::setTabOrder(student_checkBox, teacher_checkBox);
        QWidget::setTabOrder(teacher_checkBox, confirm_btn);
        QWidget::setTabOrder(confirm_btn, minus_btn);
        QWidget::setTabOrder(minus_btn, close_btn);

        retranslateUi(LoginWindow);
        QObject::connect(close_btn, SIGNAL(clicked()), LoginWindow, SLOT(close()));
        QObject::connect(minus_btn, SIGNAL(clicked()), LoginWindow, SLOT(showMinimized()));

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "MainWindow", nullptr));
        account_edit->setText(QString());
        account_edit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\350\264\246\345\217\267", nullptr));
        confirm_btn->setText(QCoreApplication::translate("LoginWindow", "\347\231\273\345\275\225", nullptr));
#if QT_CONFIG(shortcut)
        confirm_btn->setShortcut(QCoreApplication::translate("LoginWindow", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        password_edit->setInputMask(QString());
        password_edit->setText(QString());
        password_edit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\345\257\206\347\240\201", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        student_checkBox->setText(QCoreApplication::translate("LoginWindow", "\345\255\246\347\224\237", nullptr));
        teacher_checkBox->setText(QCoreApplication::translate("LoginWindow", "\346\225\231\345\270\210", nullptr));
        warn_text->setText(QString());
#if QT_CONFIG(tooltip)
        close_btn->setToolTip(QCoreApplication::translate("LoginWindow", "\345\205\263\351\227\255", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        close_btn->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        close_btn->setText(QString());
#if QT_CONFIG(tooltip)
        minus_btn->setToolTip(QCoreApplication::translate("LoginWindow", "\346\234\200\345\260\217\345\214\226", nullptr));
#endif // QT_CONFIG(tooltip)
        minus_btn->setText(QString());
        logo_label->setText(QString());
        loading_label_1->setText(QCoreApplication::translate("LoginWindow", "\302\267", nullptr));
        loading_label_2->setText(QCoreApplication::translate("LoginWindow", "\302\267", nullptr));
        loading_label_3->setText(QCoreApplication::translate("LoginWindow", "\302\267", nullptr));
        shadow->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_LOGINWINDOW_H
