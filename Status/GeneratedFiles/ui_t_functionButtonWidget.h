/********************************************************************************
** Form generated from reading UI file 't_functionButtonWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_T_FUNCTIONBUTTONWIDGET_H
#define UI_T_FUNCTIONBUTTONWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeacherFunctionButtonWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *function_navigation_text;
    QPushButton *course_management_btn;
    QPushButton *online_classroom_btn;
    QPushButton *history_btn;
    QFrame *line_2;
    QLabel *other_navigation_text;
    QPushButton *setting_btn;
    QPushButton *document_btn;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *TeacherFunctionButtonWidget)
    {
        if (TeacherFunctionButtonWidget->objectName().isEmpty())
            TeacherFunctionButtonWidget->setObjectName(QString::fromUtf8("TeacherFunctionButtonWidget"));
        TeacherFunctionButtonWidget->resize(155, 248);
        TeacherFunctionButtonWidget->setStyleSheet(QString::fromUtf8("QPushButton { \n"
"	text-align: left;\n"
"	padding-left: 15px;\n"
"	border: none;\n"
"	color:  #79A0BA;;\n"
"	background-color: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #385368;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #537b9b;\n"
"	border-left: 5px solid #699BC3;\n"
"}"));
        verticalLayout = new QVBoxLayout(TeacherFunctionButtonWidget);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        function_navigation_text = new QLabel(TeacherFunctionButtonWidget);
        function_navigation_text->setObjectName(QString::fromUtf8("function_navigation_text"));
        function_navigation_text->setMinimumSize(QSize(155, 30));
        function_navigation_text->setMaximumSize(QSize(155, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        function_navigation_text->setFont(font);
        function_navigation_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #5b788c;\n"
"}"));
        function_navigation_text->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(function_navigation_text);

        course_management_btn = new QPushButton(TeacherFunctionButtonWidget);
        buttonGroup = new QButtonGroup(TeacherFunctionButtonWidget);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(course_management_btn);
        course_management_btn->setObjectName(QString::fromUtf8("course_management_btn"));
        course_management_btn->setMinimumSize(QSize(155, 30));
        course_management_btn->setMaximumSize(QSize(155, 30));
        course_management_btn->setFont(font);
        course_management_btn->setCursor(QCursor(Qt::PointingHandCursor));
        course_management_btn->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/button/Resources/material/button/course.png"), QSize(), QIcon::Normal, QIcon::Off);
        course_management_btn->setIcon(icon);
        course_management_btn->setIconSize(QSize(18, 18));
        course_management_btn->setCheckable(true);
        course_management_btn->setChecked(true);

        verticalLayout->addWidget(course_management_btn);

        online_classroom_btn = new QPushButton(TeacherFunctionButtonWidget);
        buttonGroup->addButton(online_classroom_btn);
        online_classroom_btn->setObjectName(QString::fromUtf8("online_classroom_btn"));
        online_classroom_btn->setMinimumSize(QSize(155, 30));
        online_classroom_btn->setMaximumSize(QSize(155, 30));
        online_classroom_btn->setFont(font);
        online_classroom_btn->setCursor(QCursor(Qt::PointingHandCursor));
        online_classroom_btn->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/button/Resources/material/button/interaction.png"), QSize(), QIcon::Normal, QIcon::Off);
        online_classroom_btn->setIcon(icon1);
        online_classroom_btn->setIconSize(QSize(18, 18));
        online_classroom_btn->setCheckable(true);

        verticalLayout->addWidget(online_classroom_btn);

        history_btn = new QPushButton(TeacherFunctionButtonWidget);
        buttonGroup->addButton(history_btn);
        history_btn->setObjectName(QString::fromUtf8("history_btn"));
        history_btn->setMinimumSize(QSize(155, 30));
        history_btn->setMaximumSize(QSize(155, 30));
        history_btn->setFont(font);
        history_btn->setCursor(QCursor(Qt::PointingHandCursor));
        history_btn->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/button/Resources/material/button/history.png"), QSize(), QIcon::Normal, QIcon::Off);
        history_btn->setIcon(icon2);
        history_btn->setIconSize(QSize(18, 18));
        history_btn->setCheckable(true);

        verticalLayout->addWidget(history_btn);

        line_2 = new QFrame(TeacherFunctionButtonWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        other_navigation_text = new QLabel(TeacherFunctionButtonWidget);
        other_navigation_text->setObjectName(QString::fromUtf8("other_navigation_text"));
        other_navigation_text->setMinimumSize(QSize(155, 30));
        other_navigation_text->setMaximumSize(QSize(155, 30));
        other_navigation_text->setFont(font);
        other_navigation_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #5b788c;\n"
"}"));
        other_navigation_text->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(other_navigation_text);

        setting_btn = new QPushButton(TeacherFunctionButtonWidget);
        buttonGroup->addButton(setting_btn);
        setting_btn->setObjectName(QString::fromUtf8("setting_btn"));
        setting_btn->setMinimumSize(QSize(155, 30));
        setting_btn->setMaximumSize(QSize(155, 30));
        setting_btn->setFont(font);
        setting_btn->setCursor(QCursor(Qt::PointingHandCursor));
        setting_btn->setStyleSheet(QString::fromUtf8(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/button/Resources/material/button/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        setting_btn->setIcon(icon3);
        setting_btn->setIconSize(QSize(18, 18));
        setting_btn->setCheckable(true);

        verticalLayout->addWidget(setting_btn);

        document_btn = new QPushButton(TeacherFunctionButtonWidget);
        buttonGroup->addButton(document_btn);
        document_btn->setObjectName(QString::fromUtf8("document_btn"));
        document_btn->setMinimumSize(QSize(155, 30));
        document_btn->setMaximumSize(QSize(155, 30));
        document_btn->setFont(font);
        document_btn->setCursor(QCursor(Qt::PointingHandCursor));
        document_btn->setStyleSheet(QString::fromUtf8(""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/button/Resources/material/button/document.png"), QSize(), QIcon::Normal, QIcon::Off);
        document_btn->setIcon(icon4);
        document_btn->setIconSize(QSize(18, 18));
        document_btn->setCheckable(true);

        verticalLayout->addWidget(document_btn);


        retranslateUi(TeacherFunctionButtonWidget);

        QMetaObject::connectSlotsByName(TeacherFunctionButtonWidget);
    } // setupUi

    void retranslateUi(QWidget *TeacherFunctionButtonWidget)
    {
        TeacherFunctionButtonWidget->setWindowTitle(QCoreApplication::translate("TeacherFunctionButtonWidget", "Form", nullptr));
        function_navigation_text->setText(QCoreApplication::translate("TeacherFunctionButtonWidget", "   \345\212\237\350\203\275\350\217\234\345\215\225", nullptr));
        course_management_btn->setText(QCoreApplication::translate("TeacherFunctionButtonWidget", " \350\257\276\347\250\213\347\256\241\347\220\206", nullptr));
        online_classroom_btn->setText(QCoreApplication::translate("TeacherFunctionButtonWidget", " \345\234\250\347\272\277\346\225\231\345\256\244", nullptr));
        history_btn->setText(QCoreApplication::translate("TeacherFunctionButtonWidget", " \345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        other_navigation_text->setText(QCoreApplication::translate("TeacherFunctionButtonWidget", "   \345\205\266\344\273\226", nullptr));
        setting_btn->setText(QCoreApplication::translate("TeacherFunctionButtonWidget", " \350\256\276\347\275\256", nullptr));
        document_btn->setText(QCoreApplication::translate("TeacherFunctionButtonWidget", " \344\275\277\347\224\250\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeacherFunctionButtonWidget: public Ui_TeacherFunctionButtonWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_T_FUNCTIONBUTTONWIDGET_H
