/********************************************************************************
** Form generated from reading UI file 'c_interactionWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_INTERACTIONWIDGET_H
#define UI_C_INTERACTIONWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InteractionWidget
{
public:
    QGridLayout *gridLayout;
    QGridLayout *white_board_widget_layout;
    QPushButton *flexible_frame_btn;
    QGridLayout *chat_and_in_speech_widget_layout;

    void setupUi(QWidget *InteractionWidget)
    {
        if (InteractionWidget->objectName().isEmpty())
            InteractionWidget->setObjectName(QString::fromUtf8("InteractionWidget"));
        InteractionWidget->resize(625, 565);
        InteractionWidget->setMinimumSize(QSize(0, 0));
        gridLayout = new QGridLayout(InteractionWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        white_board_widget_layout = new QGridLayout();
        white_board_widget_layout->setSpacing(0);
        white_board_widget_layout->setObjectName(QString::fromUtf8("white_board_widget_layout"));

        gridLayout->addLayout(white_board_widget_layout, 0, 0, 1, 1);

        flexible_frame_btn = new QPushButton(InteractionWidget);
        flexible_frame_btn->setObjectName(QString::fromUtf8("flexible_frame_btn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(flexible_frame_btn->sizePolicy().hasHeightForWidth());
        flexible_frame_btn->setSizePolicy(sizePolicy);
        flexible_frame_btn->setMinimumSize(QSize(12, 0));
        flexible_frame_btn->setMaximumSize(QSize(12, 16777215));
        flexible_frame_btn->setCursor(QCursor(Qt::PointingHandCursor));
        flexible_frame_btn->setAutoFillBackground(false);
        flexible_frame_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-top-left-radius: 7px;\n"
"	border-bottom-left-radius: 7px;\n"
"	border: none;\n"
"	background: #dedede;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #999999;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #1D2B36;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/button/Resources/material/button/show.png"), QSize(), QIcon::Active, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/button/Resources/material/button/hide.png"), QSize(), QIcon::Active, QIcon::On);
        flexible_frame_btn->setIcon(icon);
        flexible_frame_btn->setIconSize(QSize(12, 12));
        flexible_frame_btn->setCheckable(true);

        gridLayout->addWidget(flexible_frame_btn, 0, 1, 1, 1);

        chat_and_in_speech_widget_layout = new QGridLayout();
        chat_and_in_speech_widget_layout->setSpacing(0);
        chat_and_in_speech_widget_layout->setObjectName(QString::fromUtf8("chat_and_in_speech_widget_layout"));

        gridLayout->addLayout(chat_and_in_speech_widget_layout, 0, 2, 1, 1);


        retranslateUi(InteractionWidget);

        QMetaObject::connectSlotsByName(InteractionWidget);
    } // setupUi

    void retranslateUi(QWidget *InteractionWidget)
    {
        InteractionWidget->setWindowTitle(QCoreApplication::translate("InteractionWidget", "Form", nullptr));
        flexible_frame_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class InteractionWidget: public Ui_InteractionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_INTERACTIONWIDGET_H
