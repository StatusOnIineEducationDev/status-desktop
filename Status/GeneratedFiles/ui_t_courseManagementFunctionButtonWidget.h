/********************************************************************************
** Form generated from reading UI file 't_courseManagementFunctionButtonWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_T_COURSEMANAGEMENTFUNCTIONBUTTONWIDGET_H
#define UI_T_COURSEMANAGEMENTFUNCTIONBUTTONWIDGET_H

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

class Ui_TeacherCourseManagementFunctionButtonWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *function_btn_frame;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_35;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *mini_program_btn;
    QPushButton *join_course_btn;
    QPushButton *create_course_btn;

    void setupUi(QWidget *TeacherCourseManagementFunctionButtonWidget)
    {
        if (TeacherCourseManagementFunctionButtonWidget->objectName().isEmpty())
            TeacherCourseManagementFunctionButtonWidget->setObjectName(QString::fromUtf8("TeacherCourseManagementFunctionButtonWidget"));
        TeacherCourseManagementFunctionButtonWidget->resize(825, 30);
        gridLayout = new QGridLayout(TeacherCourseManagementFunctionButtonWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        function_btn_frame = new QFrame(TeacherCourseManagementFunctionButtonWidget);
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

        mini_program_btn = new QPushButton(function_btn_frame);
        mini_program_btn->setObjectName(QString::fromUtf8("mini_program_btn"));
        mini_program_btn->setMinimumSize(QSize(0, 25));
        mini_program_btn->setMaximumSize(QSize(16777215, 25));
        mini_program_btn->setFont(font);
        mini_program_btn->setCursor(QCursor(Qt::PointingHandCursor));
        mini_program_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        icon.addFile(QString::fromUtf8(":/button/Resources/material/button/mini_program.png"), QSize(), QIcon::Normal, QIcon::Off);
        mini_program_btn->setIcon(icon);

        horizontalLayout_4->addWidget(mini_program_btn);

        join_course_btn = new QPushButton(function_btn_frame);
        join_course_btn->setObjectName(QString::fromUtf8("join_course_btn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(join_course_btn->sizePolicy().hasHeightForWidth());
        join_course_btn->setSizePolicy(sizePolicy);
        join_course_btn->setMinimumSize(QSize(0, 25));
        join_course_btn->setMaximumSize(QSize(16777215, 25));
        join_course_btn->setFont(font);
        join_course_btn->setCursor(QCursor(Qt::PointingHandCursor));
        join_course_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        icon1.addFile(QString::fromUtf8(":/button/Resources/material/button/join_in.png"), QSize(), QIcon::Normal, QIcon::Off);
        join_course_btn->setIcon(icon1);
        join_course_btn->setIconSize(QSize(15, 15));

        horizontalLayout_4->addWidget(join_course_btn);

        create_course_btn = new QPushButton(function_btn_frame);
        create_course_btn->setObjectName(QString::fromUtf8("create_course_btn"));
        sizePolicy.setHeightForWidth(create_course_btn->sizePolicy().hasHeightForWidth());
        create_course_btn->setSizePolicy(sizePolicy);
        create_course_btn->setMinimumSize(QSize(0, 25));
        create_course_btn->setMaximumSize(QSize(16777215, 25));
        create_course_btn->setFont(font);
        create_course_btn->setCursor(QCursor(Qt::PointingHandCursor));
        create_course_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/button/Resources/material/button/create.png"), QSize(), QIcon::Normal, QIcon::Off);
        create_course_btn->setIcon(icon2);
        create_course_btn->setIconSize(QSize(15, 15));

        horizontalLayout_4->addWidget(create_course_btn);


        gridLayout->addWidget(function_btn_frame, 0, 0, 1, 1);


        retranslateUi(TeacherCourseManagementFunctionButtonWidget);

        QMetaObject::connectSlotsByName(TeacherCourseManagementFunctionButtonWidget);
    } // setupUi

    void retranslateUi(QWidget *TeacherCourseManagementFunctionButtonWidget)
    {
        TeacherCourseManagementFunctionButtonWidget->setWindowTitle(QCoreApplication::translate("TeacherCourseManagementFunctionButtonWidget", "Form", nullptr));
        label_35->setText(QCoreApplication::translate("TeacherCourseManagementFunctionButtonWidget", "\350\257\276\347\250\213\347\256\241\347\220\206", nullptr));
        mini_program_btn->setText(QCoreApplication::translate("TeacherCourseManagementFunctionButtonWidget", "\345\260\217\347\250\213\345\272\217", nullptr));
        join_course_btn->setText(QCoreApplication::translate("TeacherCourseManagementFunctionButtonWidget", "\345\212\240\345\205\245\350\257\276\347\250\213", nullptr));
        create_course_btn->setText(QCoreApplication::translate("TeacherCourseManagementFunctionButtonWidget", "\345\210\233\345\273\272\350\257\276\347\250\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeacherCourseManagementFunctionButtonWidget: public Ui_TeacherCourseManagementFunctionButtonWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_T_COURSEMANAGEMENTFUNCTIONBUTTONWIDGET_H
