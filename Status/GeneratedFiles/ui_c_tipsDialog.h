/********************************************************************************
** Form generated from reading UI file 'c_tipsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_TIPSDIALOG_H
#define UI_C_TIPSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TipsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *layout;
    QVBoxLayout *verticalLayout_2;
    QFrame *title_bar;
    QGridLayout *gridLayout_2;
    QLabel *title_text;
    QFrame *main_area;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QLabel *text;
    QPushButton *confirm_btn;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *cancel_btn;

    void setupUi(QDialog *TipsDialog)
    {
        if (TipsDialog->objectName().isEmpty())
            TipsDialog->setObjectName(QString::fromUtf8("TipsDialog"));
        TipsDialog->resize(330, 150);
        verticalLayout = new QVBoxLayout(TipsDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        layout = new QFrame(TipsDialog);
        layout->setObjectName(QString::fromUtf8("layout"));
        layout->setFrameShape(QFrame::StyledPanel);
        layout->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(layout);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        title_bar = new QFrame(layout);
        title_bar->setObjectName(QString::fromUtf8("title_bar"));
        title_bar->setMinimumSize(QSize(0, 35));
        title_bar->setMaximumSize(QSize(16777215, 35));
        title_bar->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border-top-left-radius: 4px;\n"
"	border-top-right-radius: 4px;\n"
"	background-color: #1D2B36;\n"
"}"));
        title_bar->setFrameShape(QFrame::StyledPanel);
        title_bar->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(title_bar);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        title_text = new QLabel(title_bar);
        title_text->setObjectName(QString::fromUtf8("title_text"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        title_text->setFont(font);
        title_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #ffffff;\n"
"}"));
        title_text->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(title_text, 0, 0, 1, 1);


        verticalLayout_2->addWidget(title_bar);

        main_area = new QFrame(layout);
        main_area->setObjectName(QString::fromUtf8("main_area"));
        main_area->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border-bottom-left-radius: 4px;\n"
"	border-bottom-right-radius: 4px;\n"
"	background-color: #fafafa;\n"
"}\n"
"\n"
""));
        main_area->setFrameShape(QFrame::StyledPanel);
        main_area->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(main_area);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 5);

        text = new QLabel(main_area);
        text->setObjectName(QString::fromUtf8("text"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        text->setFont(font1);
        text->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(text, 0, 0, 1, 5);

        confirm_btn = new QPushButton(main_area);
        confirm_btn->setObjectName(QString::fromUtf8("confirm_btn"));
        confirm_btn->setMinimumSize(QSize(90, 30));
        confirm_btn->setMaximumSize(QSize(90, 30));
        confirm_btn->setFont(font1);
        confirm_btn->setCursor(QCursor(Qt::PointingHandCursor));
        confirm_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 15px;\n"
"	border: 1px solid #1296db;\n"
"	color: #1296db;\n"
"	background: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E6E6E6;\n"
"}"));

        gridLayout->addWidget(confirm_btn, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 4, 1, 1);

        cancel_btn = new QPushButton(main_area);
        cancel_btn->setObjectName(QString::fromUtf8("cancel_btn"));
        cancel_btn->setMinimumSize(QSize(90, 30));
        cancel_btn->setMaximumSize(QSize(90, 30));
        cancel_btn->setFont(font1);
        cancel_btn->setCursor(QCursor(Qt::PointingHandCursor));
        cancel_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 15px;\n"
"	border: 1px solid #999999;\n"
"	color: #999999;\n"
"	background: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E6E6E6;\n"
"}"));

        gridLayout->addWidget(cancel_btn, 1, 3, 1, 1);


        verticalLayout_2->addWidget(main_area);


        verticalLayout->addWidget(layout);


        retranslateUi(TipsDialog);

        QMetaObject::connectSlotsByName(TipsDialog);
    } // setupUi

    void retranslateUi(QDialog *TipsDialog)
    {
        TipsDialog->setWindowTitle(QCoreApplication::translate("TipsDialog", "Dialog", nullptr));
        title_text->setText(QCoreApplication::translate("TipsDialog", "\346\217\220\347\244\272", nullptr));
        text->setText(QCoreApplication::translate("TipsDialog", "\346\226\207\346\234\254", nullptr));
        confirm_btn->setText(QCoreApplication::translate("TipsDialog", "\347\241\256\345\256\232", nullptr));
        cancel_btn->setText(QCoreApplication::translate("TipsDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TipsDialog: public Ui_TipsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_TIPSDIALOG_H
