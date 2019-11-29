/********************************************************************************
** Form generated from reading UI file 's_inSpeechRemovableWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S_INSPEECHREMOVABLEWIDGET_H
#define UI_S_INSPEECHREMOVABLEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentInSpeechRemovableWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *shadow_frame;
    QGridLayout *gridLayout_4;
    QFrame *main_area;
    QGridLayout *gridLayout_5;
    QPushButton *end_btn;
    QLabel *time_text;
    QLabel *label;

    void setupUi(QWidget *StudentInSpeechRemovableWidget)
    {
        if (StudentInSpeechRemovableWidget->objectName().isEmpty())
            StudentInSpeechRemovableWidget->setObjectName(QString::fromUtf8("StudentInSpeechRemovableWidget"));
        StudentInSpeechRemovableWidget->resize(150, 55);
        gridLayout = new QGridLayout(StudentInSpeechRemovableWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        shadow_frame = new QFrame(StudentInSpeechRemovableWidget);
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
"	background: #fafafa;\n"
"}"));
        main_area->setFrameShape(QFrame::StyledPanel);
        main_area->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(main_area);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(5, 5, 5, 5);
        end_btn = new QPushButton(main_area);
        end_btn->setObjectName(QString::fromUtf8("end_btn"));
        end_btn->setMinimumSize(QSize(35, 35));
        end_btn->setMaximumSize(QSize(35, 35));
        end_btn->setCursor(QCursor(Qt::PointingHandCursor));
        end_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	background: none;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/button/Resources/material/button/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        end_btn->setIcon(icon);
        end_btn->setIconSize(QSize(35, 35));

        gridLayout_5->addWidget(end_btn, 0, 0, 2, 1);

        time_text = new QLabel(main_area);
        time_text->setObjectName(QString::fromUtf8("time_text"));
        time_text->setMaximumSize(QSize(16777215, 15));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(11);
        font.setBold(false);
        font.setWeight(50);
        time_text->setFont(font);
        time_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	border: none;\n"
"	color: #333333;\n"
"}"));
        time_text->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(time_text, 1, 1, 1, 1);

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


        retranslateUi(StudentInSpeechRemovableWidget);

        QMetaObject::connectSlotsByName(StudentInSpeechRemovableWidget);
    } // setupUi

    void retranslateUi(QWidget *StudentInSpeechRemovableWidget)
    {
        StudentInSpeechRemovableWidget->setWindowTitle(QCoreApplication::translate("StudentInSpeechRemovableWidget", "Form", nullptr));
#if QT_CONFIG(tooltip)
        end_btn->setToolTip(QCoreApplication::translate("StudentInSpeechRemovableWidget", "\344\270\255\346\255\242\345\217\221\350\250\200", nullptr));
#endif // QT_CONFIG(tooltip)
        end_btn->setText(QString());
        time_text->setText(QCoreApplication::translate("StudentInSpeechRemovableWidget", "00:00:00", nullptr));
        label->setText(QCoreApplication::translate("StudentInSpeechRemovableWidget", "\345\217\221\350\250\200\344\270\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentInSpeechRemovableWidget: public Ui_StudentInSpeechRemovableWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S_INSPEECHREMOVABLEWIDGET_H
