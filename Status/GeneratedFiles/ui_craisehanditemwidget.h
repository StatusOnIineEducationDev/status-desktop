/********************************************************************************
** Form generated from reading UI file 'craisehanditemwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CRAISEHANDITEMWIDGET_H
#define UI_CRAISEHANDITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CRaiseHandItemWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *time_text;
    QLabel *content_text;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *user_pic;
    QLabel *username_text;

    void setupUi(QWidget *CRaiseHandItemWidget)
    {
        if (CRaiseHandItemWidget->objectName().isEmpty())
            CRaiseHandItemWidget->setObjectName(QString::fromUtf8("CRaiseHandItemWidget"));
        CRaiseHandItemWidget->resize(220, 48);
        gridLayout = new QGridLayout(CRaiseHandItemWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(5);
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(5, 5, 5, 5);
        time_text = new QLabel(CRaiseHandItemWidget);
        time_text->setObjectName(QString::fromUtf8("time_text"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        time_text->setFont(font);
        time_text->setStyleSheet(QString::fromUtf8("color: #999999;\n"
"background: none;"));
        time_text->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(time_text, 0, 2, 1, 1);

        content_text = new QLabel(CRaiseHandItemWidget);
        content_text->setObjectName(QString::fromUtf8("content_text"));
        content_text->setFont(font);
        content_text->setStyleSheet(QString::fromUtf8("color: #333333;\n"
"background: none;"));

        gridLayout->addWidget(content_text, 1, 1, 1, 2);

        frame = new QFrame(CRaiseHandItemWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(30, 0));
        frame->setMaximumSize(QSize(30, 16777215));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: none;\n"
"	border: none;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        user_pic = new QLabel(frame);
        user_pic->setObjectName(QString::fromUtf8("user_pic"));
        user_pic->setMinimumSize(QSize(30, 30));
        user_pic->setMaximumSize(QSize(30, 30));
        user_pic->setStyleSheet(QString::fromUtf8("background: none;"));
        user_pic->setPixmap(QPixmap(QString::fromUtf8(":/pic/Resources/material/pic/student.png")));
        user_pic->setScaledContents(true);

        gridLayout_2->addWidget(user_pic, 0, 0, 1, 1);


        gridLayout->addWidget(frame, 0, 0, 2, 1);

        username_text = new QLabel(CRaiseHandItemWidget);
        username_text->setObjectName(QString::fromUtf8("username_text"));
        username_text->setFont(font);
        username_text->setStyleSheet(QString::fromUtf8("color: #1296db;\n"
"background: none;"));

        gridLayout->addWidget(username_text, 0, 1, 1, 1);


        retranslateUi(CRaiseHandItemWidget);

        QMetaObject::connectSlotsByName(CRaiseHandItemWidget);
    } // setupUi

    void retranslateUi(QWidget *CRaiseHandItemWidget)
    {
        CRaiseHandItemWidget->setWindowTitle(QCoreApplication::translate("CRaiseHandItemWidget", "Form", nullptr));
        time_text->setText(QCoreApplication::translate("CRaiseHandItemWidget", "time", nullptr));
        content_text->setText(QCoreApplication::translate("CRaiseHandItemWidget", "\344\270\276\346\211\213\357\274\210\347\224\263\350\257\267\347\224\273\346\235\277\343\200\201\350\257\255\351\237\263\346\235\203\351\231\220\357\274\211", nullptr));
        user_pic->setText(QString());
        username_text->setText(QCoreApplication::translate("CRaiseHandItemWidget", "username", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CRaiseHandItemWidget: public Ui_CRaiseHandItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRAISEHANDITEMWIDGET_H
