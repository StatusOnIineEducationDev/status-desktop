/********************************************************************************
** Form generated from reading UI file 'c_inSpeechMemberItemWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_INSPEECHMEMBERITEMWIDGET_H
#define UI_C_INSPEECHMEMBERITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InSpeechMemberItemWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *account_type_label;
    QLabel *username_text;
    QLabel *writing_pic;
    QLabel *user_pic;

    void setupUi(QWidget *InSpeechMemberItemWidget)
    {
        if (InSpeechMemberItemWidget->objectName().isEmpty())
            InSpeechMemberItemWidget->setObjectName(QString::fromUtf8("InSpeechMemberItemWidget"));
        InSpeechMemberItemWidget->resize(224, 30);
        gridLayout = new QGridLayout(InSpeechMemberItemWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(5, 5, 5, 5);
        account_type_label = new QLabel(InSpeechMemberItemWidget);
        account_type_label->setObjectName(QString::fromUtf8("account_type_label"));
        account_type_label->setMinimumSize(QSize(50, 15));
        account_type_label->setMaximumSize(QSize(50, 11));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(9);
        account_type_label->setFont(font);
        account_type_label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border-radius: 7px;\n"
"	color: #ffffff;\n"
"	background: green;\n"
"}"));
        account_type_label->setScaledContents(false);
        account_type_label->setAlignment(Qt::AlignCenter);
        account_type_label->setMargin(0);
        account_type_label->setIndent(-1);

        gridLayout->addWidget(account_type_label, 0, 2, 1, 1);

        username_text = new QLabel(InSpeechMemberItemWidget);
        username_text->setObjectName(QString::fromUtf8("username_text"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        username_text->setFont(font1);
        username_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #666666;\n"
"	background: none;\n"
"}"));
        username_text->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(username_text, 0, 3, 1, 1);

        writing_pic = new QLabel(InSpeechMemberItemWidget);
        writing_pic->setObjectName(QString::fromUtf8("writing_pic"));
        writing_pic->setMinimumSize(QSize(12, 12));
        writing_pic->setMaximumSize(QSize(12, 12));
        writing_pic->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"}"));
        writing_pic->setPixmap(QPixmap(QString::fromUtf8(":/pic/Resources/material/pic/writing.png")));
        writing_pic->setScaledContents(true);

        gridLayout->addWidget(writing_pic, 0, 0, 1, 1);

        user_pic = new QLabel(InSpeechMemberItemWidget);
        user_pic->setObjectName(QString::fromUtf8("user_pic"));
        user_pic->setMinimumSize(QSize(20, 20));
        user_pic->setMaximumSize(QSize(20, 20));
        user_pic->setFont(font1);
        user_pic->setStyleSheet(QString::fromUtf8("background: none;"));
        user_pic->setScaledContents(true);
        user_pic->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(user_pic, 0, 1, 1, 1);


        retranslateUi(InSpeechMemberItemWidget);

        QMetaObject::connectSlotsByName(InSpeechMemberItemWidget);
    } // setupUi

    void retranslateUi(QWidget *InSpeechMemberItemWidget)
    {
        InSpeechMemberItemWidget->setWindowTitle(QCoreApplication::translate("InSpeechMemberItemWidget", "Form", nullptr));
        account_type_label->setText(QCoreApplication::translate("InSpeechMemberItemWidget", "\345\255\246\347\224\237", nullptr));
        username_text->setText(QCoreApplication::translate("InSpeechMemberItemWidget", "username", nullptr));
        writing_pic->setText(QString());
        user_pic->setText(QCoreApplication::translate("InSpeechMemberItemWidget", "pic", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InSpeechMemberItemWidget: public Ui_InSpeechMemberItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_INSPEECHMEMBERITEMWIDGET_H
