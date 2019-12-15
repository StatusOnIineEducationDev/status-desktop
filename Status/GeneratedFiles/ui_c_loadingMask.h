/********************************************************************************
** Form generated from reading UI file 'c_loadingMask.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_LOADINGMASK_H
#define UI_C_LOADINGMASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadingMask
{
public:
    QGridLayout *gridLayout;
    QFrame *mask;
    QGridLayout *gridLayout_2;
    QFrame *toast;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer;
    QFrame *square_frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QFrame *square_1;
    QFrame *square_2;
    QFrame *square_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *tips_text;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *LoadingMask)
    {
        if (LoadingMask->objectName().isEmpty())
            LoadingMask->setObjectName(QString::fromUtf8("LoadingMask"));
        LoadingMask->resize(200, 200);
        gridLayout = new QGridLayout(LoadingMask);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        mask = new QFrame(LoadingMask);
        mask->setObjectName(QString::fromUtf8("mask"));
        mask->setMaximumSize(QSize(16777215, 16777215));
        mask->setStyleSheet(QString::fromUtf8("QFrame#mask{\n"
"	background-color:rgba(0,0,0,50);\n"
"}"));
        mask->setFrameShape(QFrame::StyledPanel);
        mask->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(mask);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        toast = new QFrame(mask);
        toast->setObjectName(QString::fromUtf8("toast"));
        toast->setMinimumSize(QSize(50, 50));
        toast->setMaximumSize(QSize(80, 80));
        toast->setStyleSheet(QString::fromUtf8("QFrame#toast{\n"
"	color:white;\n"
"	background: none;\n"
"	/*background-color:rgba(0,0,0,150);*/\n"
"	border-radius:5px;\n"
"}"));
        toast->setFrameShape(QFrame::StyledPanel);
        toast->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(toast);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 0, 0, 1, 1);

        square_frame = new QFrame(toast);
        square_frame->setObjectName(QString::fromUtf8("square_frame"));
        square_frame->setStyleSheet(QString::fromUtf8("background: none;"));
        square_frame->setFrameShape(QFrame::StyledPanel);
        square_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(square_frame);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        square_1 = new QFrame(square_frame);
        square_1->setObjectName(QString::fromUtf8("square_1"));
        square_1->setMinimumSize(QSize(0, 0));
        square_1->setMaximumSize(QSize(16777215, 16777215));
        square_1->setStyleSheet(QString::fromUtf8("background: #ffffff;"));
        square_1->setFrameShape(QFrame::StyledPanel);
        square_1->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(square_1, 0, Qt::AlignVCenter);

        square_2 = new QFrame(square_frame);
        square_2->setObjectName(QString::fromUtf8("square_2"));
        square_2->setMinimumSize(QSize(0, 0));
        square_2->setMaximumSize(QSize(16777215, 16777215));
        square_2->setStyleSheet(QString::fromUtf8("background: #ffffff;"));
        square_2->setFrameShape(QFrame::StyledPanel);
        square_2->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(square_2, 0, Qt::AlignVCenter);

        square_3 = new QFrame(square_frame);
        square_3->setObjectName(QString::fromUtf8("square_3"));
        square_3->setMinimumSize(QSize(0, 0));
        square_3->setMaximumSize(QSize(16777215, 16777215));
        square_3->setStyleSheet(QString::fromUtf8("background: #ffffff;"));
        square_3->setFrameShape(QFrame::StyledPanel);
        square_3->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(square_3, 0, Qt::AlignVCenter);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_3->addWidget(square_frame, 2, 0, 1, 1);

        tips_text = new QLabel(toast);
        tips_text->setObjectName(QString::fromUtf8("tips_text"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        tips_text->setFont(font);
        tips_text->setStyleSheet(QString::fromUtf8("color: #ffffff;\n"
"background: none;"));
        tips_text->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(tips_text, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 3, 0, 1, 1);


        gridLayout_2->addWidget(toast, 0, 0, 1, 1);


        gridLayout->addWidget(mask, 0, 0, 1, 1);


        retranslateUi(LoadingMask);

        QMetaObject::connectSlotsByName(LoadingMask);
    } // setupUi

    void retranslateUi(QWidget *LoadingMask)
    {
        LoadingMask->setWindowTitle(QCoreApplication::translate("LoadingMask", "Form", nullptr));
        tips_text->setText(QCoreApplication::translate("LoadingMask", "Loading...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoadingMask: public Ui_LoadingMask {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_LOADINGMASK_H
