/********************************************************************************
** Form generated from reading UI file 'cpaintmemberitemwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CPAINTMEMBERITEMWIDGET_H
#define UI_CPAINTMEMBERITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CPaintMemberItemWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *account_type_label;
    QLabel *username_text;
    QLabel *user_pic;
    QLabel *writing_pic;
    QLabel *uid_text;

    void setupUi(QWidget *CPaintMemberItemWidget)
    {
        if (CPaintMemberItemWidget->objectName().isEmpty())
            CPaintMemberItemWidget->setObjectName(QString::fromUtf8("CPaintMemberItemWidget"));
        CPaintMemberItemWidget->resize(224, 30);
        gridLayout = new QGridLayout(CPaintMemberItemWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(5);
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(5, 5, 5, 5);
        account_type_label = new QLabel(CPaintMemberItemWidget);
        account_type_label->setObjectName(QString::fromUtf8("account_type_label"));
        account_type_label->setMinimumSize(QSize(50, 17));
        account_type_label->setMaximumSize(QSize(50, 17));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        account_type_label->setFont(font);
        account_type_label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border-radius: 8px;\n"
"	color: #ffffff;\n"
"	background: green;\n"
"}"));
        account_type_label->setScaledContents(false);
        account_type_label->setAlignment(Qt::AlignCenter);
        account_type_label->setMargin(0);
        account_type_label->setIndent(-1);

        gridLayout->addWidget(account_type_label, 0, 2, 1, 1);

        username_text = new QLabel(CPaintMemberItemWidget);
        username_text->setObjectName(QString::fromUtf8("username_text"));
        username_text->setFont(font);
        username_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #666666;\n"
"	background: none;\n"
"}"));

        gridLayout->addWidget(username_text, 0, 3, 1, 1);

        user_pic = new QLabel(CPaintMemberItemWidget);
        user_pic->setObjectName(QString::fromUtf8("user_pic"));
        user_pic->setMinimumSize(QSize(20, 20));
        user_pic->setMaximumSize(QSize(20, 20));
        user_pic->setStyleSheet(QString::fromUtf8("background: none;"));
        user_pic->setPixmap(QPixmap(QString::fromUtf8(":/pic/Resources/material/pic/teacher.png")));
        user_pic->setScaledContents(true);

        gridLayout->addWidget(user_pic, 0, 1, 1, 1);

        writing_pic = new QLabel(CPaintMemberItemWidget);
        writing_pic->setObjectName(QString::fromUtf8("writing_pic"));
        writing_pic->setMinimumSize(QSize(12, 12));
        writing_pic->setMaximumSize(QSize(12, 12));
        writing_pic->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"}"));
        writing_pic->setPixmap(QPixmap(QString::fromUtf8(":/pic/Resources/material/pic/writing.png")));
        writing_pic->setScaledContents(true);

        gridLayout->addWidget(writing_pic, 0, 0, 1, 1);

        uid_text = new QLabel(CPaintMemberItemWidget);
        uid_text->setObjectName(QString::fromUtf8("uid_text"));
        uid_text->setFont(font);
        uid_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #666666;\n"
"	background: none;\n"
"}"));

        gridLayout->addWidget(uid_text, 0, 4, 1, 1);


        retranslateUi(CPaintMemberItemWidget);

        QMetaObject::connectSlotsByName(CPaintMemberItemWidget);
    } // setupUi

    void retranslateUi(QWidget *CPaintMemberItemWidget)
    {
        CPaintMemberItemWidget->setWindowTitle(QCoreApplication::translate("CPaintMemberItemWidget", "Form", nullptr));
        account_type_label->setText(QCoreApplication::translate("CPaintMemberItemWidget", "\346\225\231\345\270\210", nullptr));
        username_text->setText(QCoreApplication::translate("CPaintMemberItemWidget", "username", nullptr));
        user_pic->setText(QString());
        writing_pic->setText(QString());
        uid_text->setText(QCoreApplication::translate("CPaintMemberItemWidget", "uid", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CPaintMemberItemWidget: public Ui_CPaintMemberItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CPAINTMEMBERITEMWIDGET_H
