/********************************************************************************
** Form generated from reading UI file 's_onlineClassroomFunctionButtonWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S_ONLINECLASSROOMFUNCTIONBUTTONWIDGET_H
#define UI_S_ONLINECLASSROOMFUNCTIONBUTTONWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentOnlineClassroomFunctionButtonWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *function_btn_frame;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_35;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *raise_hand_btn;
    QPushButton *quit_lesson_btn;

    void setupUi(QWidget *StudentOnlineClassroomFunctionButtonWidget)
    {
        if (StudentOnlineClassroomFunctionButtonWidget->objectName().isEmpty())
            StudentOnlineClassroomFunctionButtonWidget->setObjectName(QString::fromUtf8("StudentOnlineClassroomFunctionButtonWidget"));
        StudentOnlineClassroomFunctionButtonWidget->resize(825, 30);
        gridLayout = new QGridLayout(StudentOnlineClassroomFunctionButtonWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        function_btn_frame = new QFrame(StudentOnlineClassroomFunctionButtonWidget);
        function_btn_frame->setObjectName(QString::fromUtf8("function_btn_frame"));
        function_btn_frame->setMinimumSize(QSize(825, 30));
        function_btn_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: #f0f0f0;\n"
"	border: none;\n"
"	border-bottom: 1px solid #E8ECEC;\n"
"}"));
        function_btn_frame->setFrameShape(QFrame::StyledPanel);
        function_btn_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(function_btn_frame);
        horizontalLayout_4->setSpacing(20);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(10, 0, 10, 0);
        label_35 = new QLabel(function_btn_frame);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        label_35->setFont(font);
        label_35->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	color: #666666;\n"
"	background: none;\n"
"	border: none;\n"
"}"));

        horizontalLayout_4->addWidget(label_35);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_11);

        raise_hand_btn = new QPushButton(function_btn_frame);
        raise_hand_btn->setObjectName(QString::fromUtf8("raise_hand_btn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(raise_hand_btn->sizePolicy().hasHeightForWidth());
        raise_hand_btn->setSizePolicy(sizePolicy);
        raise_hand_btn->setMinimumSize(QSize(0, 25));
        raise_hand_btn->setMaximumSize(QSize(16777215, 25));
        raise_hand_btn->setFont(font);
        raise_hand_btn->setCursor(QCursor(Qt::PointingHandCursor));
        raise_hand_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #666666;\n"
"	background: none;\n"
"	border: none;\n"
"	border-radius: 5px;\n"
"	padding-left: 5px;\n"
"	padding-right: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #dedede;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/button/Resources/material/button/raise_hand.png"), QSize(), QIcon::Normal, QIcon::Off);
        raise_hand_btn->setIcon(icon);
        raise_hand_btn->setIconSize(QSize(15, 15));

        horizontalLayout_4->addWidget(raise_hand_btn);

        quit_lesson_btn = new QPushButton(function_btn_frame);
        quit_lesson_btn->setObjectName(QString::fromUtf8("quit_lesson_btn"));
        sizePolicy.setHeightForWidth(quit_lesson_btn->sizePolicy().hasHeightForWidth());
        quit_lesson_btn->setSizePolicy(sizePolicy);
        quit_lesson_btn->setMinimumSize(QSize(0, 25));
        quit_lesson_btn->setMaximumSize(QSize(16777215, 25));
        quit_lesson_btn->setFont(font);
        quit_lesson_btn->setCursor(QCursor(Qt::PointingHandCursor));
        quit_lesson_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #666666;\n"
"	background: none;\n"
"	border: none;\n"
"	border-radius: 5px;\n"
"	padding-left: 5px;\n"
"	padding-right: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #dedede;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/button/Resources/material/button/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        quit_lesson_btn->setIcon(icon1);
        quit_lesson_btn->setIconSize(QSize(15, 15));

        horizontalLayout_4->addWidget(quit_lesson_btn);


        gridLayout->addWidget(function_btn_frame, 0, 0, 1, 1);


        retranslateUi(StudentOnlineClassroomFunctionButtonWidget);

        QMetaObject::connectSlotsByName(StudentOnlineClassroomFunctionButtonWidget);
    } // setupUi

    void retranslateUi(QWidget *StudentOnlineClassroomFunctionButtonWidget)
    {
        StudentOnlineClassroomFunctionButtonWidget->setWindowTitle(QCoreApplication::translate("StudentOnlineClassroomFunctionButtonWidget", "Form", nullptr));
        label_35->setText(QCoreApplication::translate("StudentOnlineClassroomFunctionButtonWidget", "\345\234\250\347\272\277\346\225\231\345\256\244", nullptr));
        raise_hand_btn->setText(QCoreApplication::translate("StudentOnlineClassroomFunctionButtonWidget", "\344\270\276\346\211\213", nullptr));
        quit_lesson_btn->setText(QCoreApplication::translate("StudentOnlineClassroomFunctionButtonWidget", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentOnlineClassroomFunctionButtonWidget: public Ui_StudentOnlineClassroomFunctionButtonWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S_ONLINECLASSROOMFUNCTIONBUTTONWIDGET_H
