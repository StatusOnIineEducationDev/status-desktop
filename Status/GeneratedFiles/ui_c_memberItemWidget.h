/********************************************************************************
** Form generated from reading UI file 'c_memberItemWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_MEMBERITEMWIDGET_H
#define UI_C_MEMBERITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MemberItemWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *user_pic;
    QLabel *username_text;
    QLabel *uid_text;
    QLabel *status_pic;

    void setupUi(QWidget *MemberItemWidget)
    {
        if (MemberItemWidget->objectName().isEmpty())
            MemberItemWidget->setObjectName(QString::fromUtf8("MemberItemWidget"));
        MemberItemWidget->resize(240, 41);
        horizontalLayout = new QHBoxLayout(MemberItemWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        user_pic = new QLabel(MemberItemWidget);
        user_pic->setObjectName(QString::fromUtf8("user_pic"));
        user_pic->setMinimumSize(QSize(20, 20));
        user_pic->setMaximumSize(QSize(20, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        user_pic->setFont(font);
        user_pic->setStyleSheet(QString::fromUtf8("background: none;"));
        user_pic->setScaledContents(true);
        user_pic->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(user_pic);

        username_text = new QLabel(MemberItemWidget);
        username_text->setObjectName(QString::fromUtf8("username_text"));
        username_text->setFont(font);
        username_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #666666;\n"
"	background: none;\n"
"}"));
        username_text->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(username_text);

        uid_text = new QLabel(MemberItemWidget);
        uid_text->setObjectName(QString::fromUtf8("uid_text"));
        uid_text->setMaximumSize(QSize(0, 16777215));

        horizontalLayout->addWidget(uid_text);

        status_pic = new QLabel(MemberItemWidget);
        status_pic->setObjectName(QString::fromUtf8("status_pic"));
        status_pic->setMinimumSize(QSize(10, 10));
        status_pic->setMaximumSize(QSize(10, 10));
        status_pic->setFont(font);
        status_pic->setStyleSheet(QString::fromUtf8("background: none;"));
        status_pic->setScaledContents(true);
        status_pic->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(status_pic);


        retranslateUi(MemberItemWidget);

        QMetaObject::connectSlotsByName(MemberItemWidget);
    } // setupUi

    void retranslateUi(QWidget *MemberItemWidget)
    {
        MemberItemWidget->setWindowTitle(QCoreApplication::translate("MemberItemWidget", "Form", nullptr));
        user_pic->setText(QCoreApplication::translate("MemberItemWidget", "pic", nullptr));
        username_text->setText(QCoreApplication::translate("MemberItemWidget", "username", nullptr));
        uid_text->setText(QCoreApplication::translate("MemberItemWidget", "uid", nullptr));
        status_pic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MemberItemWidget: public Ui_MemberItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_MEMBERITEMWIDGET_H
