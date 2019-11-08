/********************************************************************************
** Form generated from reading UI file 'c_chatItemMineWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_CHATITEMMINEWIDGET_H
#define UI_C_CHATITEMMINEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CChatItemMineWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *time_text;
    QLabel *username_text;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *user_pic;
    QTextBrowser *chat_textBrowser;

    void setupUi(QWidget *CChatItemMineWidget)
    {
        if (CChatItemMineWidget->objectName().isEmpty())
            CChatItemMineWidget->setObjectName(QString::fromUtf8("CChatItemMineWidget"));
        CChatItemMineWidget->resize(224, 50);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CChatItemMineWidget->sizePolicy().hasHeightForWidth());
        CChatItemMineWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(CChatItemMineWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(5, 5, 5, 5);
        time_text = new QLabel(CChatItemMineWidget);
        time_text->setObjectName(QString::fromUtf8("time_text"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(time_text->sizePolicy().hasHeightForWidth());
        time_text->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(9);
        time_text->setFont(font);
        time_text->setStyleSheet(QString::fromUtf8("color: #333333;\n"
"background: none;"));
        time_text->setScaledContents(false);
        time_text->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        time_text->setWordWrap(false);

        gridLayout->addWidget(time_text, 0, 0, 1, 2);

        username_text = new QLabel(CChatItemMineWidget);
        username_text->setObjectName(QString::fromUtf8("username_text"));
        sizePolicy1.setHeightForWidth(username_text->sizePolicy().hasHeightForWidth());
        username_text->setSizePolicy(sizePolicy1);
        username_text->setFont(font);
        username_text->setStyleSheet(QString::fromUtf8("color: #1296db;\n"
"background: none;"));
        username_text->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(username_text, 0, 2, 1, 1);

        frame = new QFrame(CChatItemMineWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("background: none;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(5, 0, 0, 0);
        user_pic = new QLabel(frame);
        user_pic->setObjectName(QString::fromUtf8("user_pic"));
        user_pic->setMinimumSize(QSize(30, 30));
        user_pic->setMaximumSize(QSize(30, 30));
        user_pic->setStyleSheet(QString::fromUtf8("background: none;"));
        user_pic->setPixmap(QPixmap(QString::fromUtf8(":/pic/Resources/material/pic/teacher.png")));
        user_pic->setScaledContents(true);

        gridLayout_2->addWidget(user_pic, 0, 0, 1, 1, Qt::AlignTop);


        gridLayout->addWidget(frame, 0, 3, 2, 1);

        chat_textBrowser = new QTextBrowser(CChatItemMineWidget);
        chat_textBrowser->setObjectName(QString::fromUtf8("chat_textBrowser"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(chat_textBrowser->sizePolicy().hasHeightForWidth());
        chat_textBrowser->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        chat_textBrowser->setFont(font1);
        chat_textBrowser->setAutoFillBackground(false);
        chat_textBrowser->setStyleSheet(QString::fromUtf8("color: #666666;\n"
"background: transparent;\n"
"border: none;"));
        chat_textBrowser->setLineWidth(1);
        chat_textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        chat_textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(chat_textBrowser, 1, 0, 1, 3);


        retranslateUi(CChatItemMineWidget);

        QMetaObject::connectSlotsByName(CChatItemMineWidget);
    } // setupUi

    void retranslateUi(QWidget *CChatItemMineWidget)
    {
        CChatItemMineWidget->setWindowTitle(QCoreApplication::translate("CChatItemMineWidget", "Form", nullptr));
        time_text->setText(QCoreApplication::translate("CChatItemMineWidget", "time", nullptr));
        username_text->setText(QCoreApplication::translate("CChatItemMineWidget", "username", nullptr));
        user_pic->setText(QString());
        chat_textBrowser->setHtml(QCoreApplication::translate("CChatItemMineWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'\345\276\256\350\275\257\351\233\205\351\273\221';\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CChatItemMineWidget: public Ui_CChatItemMineWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_CHATITEMMINEWIDGET_H
