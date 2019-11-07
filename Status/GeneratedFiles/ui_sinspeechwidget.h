/********************************************************************************
** Form generated from reading UI file 'sinspeechwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINSPEECHWIDGET_H
#define UI_SINSPEECHWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SInSpeechWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *shadow_frame;
    QGridLayout *gridLayout_4;
    QFrame *main_area;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label;

    void setupUi(QWidget *SInSpeechWidget)
    {
        if (SInSpeechWidget->objectName().isEmpty())
            SInSpeechWidget->setObjectName(QString::fromUtf8("SInSpeechWidget"));
        SInSpeechWidget->resize(150, 55);
        gridLayout = new QGridLayout(SInSpeechWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        shadow_frame = new QFrame(SInSpeechWidget);
        shadow_frame->setObjectName(QString::fromUtf8("shadow_frame"));
        shadow_frame->setStyleSheet(QString::fromUtf8("QFrame#shadow_frame {\n"
"	/*border-image\345\217\257\344\273\245\345\271\263\351\223\272\357\274\210\345\215\263\345\217\257\346\213\211\344\274\270\357\274\211*/\n"
"	border-image: url(:/shadow/Resources/material/shadow/140x45_shadow.png);\n"
"	background: none;\n"
"}"));
        shadow_frame->setFrameShape(QFrame::StyledPanel);
        shadow_frame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(shadow_frame);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(5, 5, 5, 5);
        main_area = new QFrame(shadow_frame);
        main_area->setObjectName(QString::fromUtf8("main_area"));
        main_area->setStyleSheet(QString::fromUtf8("QFrame#main_area {\n"
"	border: none;\n"
"	border-radius: 22px;\n"
"	background: #ffffff;\n"
"}"));
        main_area->setFrameShape(QFrame::StyledPanel);
        main_area->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(main_area);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(5, 5, 5, 5);
        pushButton = new QPushButton(main_area);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(35, 35));
        pushButton->setMaximumSize(QSize(35, 35));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	background: none;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/button/Resources/material/button/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(35, 35));

        gridLayout_5->addWidget(pushButton, 0, 0, 2, 1);

        label_2 = new QLabel(main_area);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 15));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(11);
        font.setBold(false);
        font.setWeight(50);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	border: none;\n"
"	color: #333333;\n"
"}"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_2, 1, 1, 1, 1);

        label = new QLabel(main_area);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 15));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	border: none;\n"
"	color: #333333;\n"
"}"));
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label, 0, 1, 1, 1);


        gridLayout_4->addWidget(main_area, 0, 0, 1, 1);


        gridLayout->addWidget(shadow_frame, 0, 0, 1, 1);


        retranslateUi(SInSpeechWidget);

        QMetaObject::connectSlotsByName(SInSpeechWidget);
    } // setupUi

    void retranslateUi(QWidget *SInSpeechWidget)
    {
        SInSpeechWidget->setWindowTitle(QCoreApplication::translate("SInSpeechWidget", "Form", nullptr));
#if QT_CONFIG(tooltip)
        pushButton->setToolTip(QCoreApplication::translate("SInSpeechWidget", "\344\270\255\346\255\242\345\217\221\350\250\200", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton->setText(QString());
        label_2->setText(QCoreApplication::translate("SInSpeechWidget", "00:00:00", nullptr));
        label->setText(QCoreApplication::translate("SInSpeechWidget", "\345\217\221\350\250\200\344\270\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SInSpeechWidget: public Ui_SInSpeechWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINSPEECHWIDGET_H
