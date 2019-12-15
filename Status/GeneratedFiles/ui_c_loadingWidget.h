/********************************************************************************
** Form generated from reading UI file 'c_loadingWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_LOADINGWIDGET_H
#define UI_C_LOADINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadingWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *main_area;
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

    void setupUi(QWidget *LoadingWidget)
    {
        if (LoadingWidget->objectName().isEmpty())
            LoadingWidget->setObjectName(QString::fromUtf8("LoadingWidget"));
        LoadingWidget->resize(150, 80);
        gridLayout = new QGridLayout(LoadingWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        main_area = new QFrame(LoadingWidget);
        main_area->setObjectName(QString::fromUtf8("main_area"));
        main_area->setMinimumSize(QSize(50, 50));
        main_area->setMaximumSize(QSize(80, 80));
        main_area->setStyleSheet(QString::fromUtf8("QFrame#main_area{\n"
"	color:white;\n"
"	background: none;\n"
"	/*background-color:rgba(0,0,0,150);*/\n"
"	border-radius:5px;\n"
"}"));
        main_area->setFrameShape(QFrame::StyledPanel);
        main_area->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(main_area);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 0, 0, 1, 1);

        square_frame = new QFrame(main_area);
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
        square_1->setStyleSheet(QString::fromUtf8("background: #999999;"));
        square_1->setFrameShape(QFrame::StyledPanel);
        square_1->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(square_1, 0, Qt::AlignVCenter);

        square_2 = new QFrame(square_frame);
        square_2->setObjectName(QString::fromUtf8("square_2"));
        square_2->setMinimumSize(QSize(0, 0));
        square_2->setMaximumSize(QSize(16777215, 16777215));
        square_2->setStyleSheet(QString::fromUtf8("background: #999999;"));
        square_2->setFrameShape(QFrame::StyledPanel);
        square_2->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(square_2, 0, Qt::AlignVCenter);

        square_3 = new QFrame(square_frame);
        square_3->setObjectName(QString::fromUtf8("square_3"));
        square_3->setMinimumSize(QSize(0, 0));
        square_3->setMaximumSize(QSize(16777215, 16777215));
        square_3->setStyleSheet(QString::fromUtf8("background: #999999;"));
        square_3->setFrameShape(QFrame::StyledPanel);
        square_3->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(square_3, 0, Qt::AlignVCenter);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_3->addWidget(square_frame, 2, 0, 1, 1);

        tips_text = new QLabel(main_area);
        tips_text->setObjectName(QString::fromUtf8("tips_text"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        tips_text->setFont(font);
        tips_text->setStyleSheet(QString::fromUtf8("color: #999999;\n"
"background: none;"));
        tips_text->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(tips_text, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 3, 0, 1, 1);


        gridLayout->addWidget(main_area, 0, 0, 1, 1);


        retranslateUi(LoadingWidget);

        QMetaObject::connectSlotsByName(LoadingWidget);
    } // setupUi

    void retranslateUi(QWidget *LoadingWidget)
    {
        LoadingWidget->setWindowTitle(QCoreApplication::translate("LoadingWidget", "Form", nullptr));
        tips_text->setText(QCoreApplication::translate("LoadingWidget", "Loading...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoadingWidget: public Ui_LoadingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_LOADINGWIDGET_H
