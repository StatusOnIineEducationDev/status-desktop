/********************************************************************************
** Form generated from reading UI file 't_courseManagementWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_T_COURSEMANAGEMENTWIDGET_H
#define UI_T_COURSEMANAGEMENTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TCourseManagementWidget
{
public:
    QGridLayout *gridLayout_2;
    QFrame *function_btn_frame;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_26;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *mini_program_btn;
    QPushButton *raise_hand_btn;
    QPushButton *raise_hand_btn_2;
    QSpacerItem *verticalSpacer_3;
    QFrame *course_base_frame;
    QGridLayout *gridLayout;
    QComboBox *courses_comboBox;
    QLabel *create_time_text;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QPushButton *delete_course_btn;
    QLabel *course_id_text;
    QLabel *label_2;
    QLabel *text;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *TCourseManagementWidget)
    {
        if (TCourseManagementWidget->objectName().isEmpty())
            TCourseManagementWidget->setObjectName(QString::fromUtf8("TCourseManagementWidget"));
        TCourseManagementWidget->resize(819, 627);
        gridLayout_2 = new QGridLayout(TCourseManagementWidget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        function_btn_frame = new QFrame(TCourseManagementWidget);
        function_btn_frame->setObjectName(QString::fromUtf8("function_btn_frame"));
        function_btn_frame->setMinimumSize(QSize(0, 30));
        function_btn_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: #f0f0f0;\n"
"	border: none;\n"
"	border-bottom: 1px solid #E8ECEC;\n"
"}"));
        function_btn_frame->setFrameShape(QFrame::StyledPanel);
        function_btn_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(function_btn_frame);
        horizontalLayout_4->setSpacing(5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(10, 0, 10, 0);
        label_26 = new QLabel(function_btn_frame);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        label_26->setFont(font);
        label_26->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	color: #666666;\n"
"	background: none;\n"
"	border: none;\n"
"}"));

        horizontalLayout_4->addWidget(label_26);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/button/Resources/material/button/join_in.png"), QSize(), QIcon::Normal, QIcon::Off);
        raise_hand_btn->setIcon(icon1);
        raise_hand_btn->setIconSize(QSize(15, 15));

        horizontalLayout_4->addWidget(raise_hand_btn);

        raise_hand_btn_2 = new QPushButton(function_btn_frame);
        raise_hand_btn_2->setObjectName(QString::fromUtf8("raise_hand_btn_2"));
        sizePolicy.setHeightForWidth(raise_hand_btn_2->sizePolicy().hasHeightForWidth());
        raise_hand_btn_2->setSizePolicy(sizePolicy);
        raise_hand_btn_2->setMinimumSize(QSize(0, 25));
        raise_hand_btn_2->setMaximumSize(QSize(16777215, 25));
        raise_hand_btn_2->setFont(font);
        raise_hand_btn_2->setCursor(QCursor(Qt::PointingHandCursor));
        raise_hand_btn_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        raise_hand_btn_2->setIcon(icon2);
        raise_hand_btn_2->setIconSize(QSize(15, 15));

        horizontalLayout_4->addWidget(raise_hand_btn_2);


        gridLayout_2->addWidget(function_btn_frame, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 3, 0, 1, 1);

        course_base_frame = new QFrame(TCourseManagementWidget);
        course_base_frame->setObjectName(QString::fromUtf8("course_base_frame"));
        course_base_frame->setMinimumSize(QSize(819, 100));
        course_base_frame->setMaximumSize(QSize(16777215, 100));
        course_base_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #ffffff;\n"
"	border-bottom: 1px solid #E8ECEC;\n"
"}"));
        course_base_frame->setFrameShape(QFrame::StyledPanel);
        course_base_frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(course_base_frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(5);
        gridLayout->setVerticalSpacing(10);
        gridLayout->setContentsMargins(20, 5, 20, 5);
        courses_comboBox = new QComboBox(course_base_frame);
        courses_comboBox->setObjectName(QString::fromUtf8("courses_comboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(courses_comboBox->sizePolicy().hasHeightForWidth());
        courses_comboBox->setSizePolicy(sizePolicy1);
        courses_comboBox->setMinimumSize(QSize(0, 0));
        courses_comboBox->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(16);
        courses_comboBox->setFont(font1);
        courses_comboBox->setCursor(QCursor(Qt::PointingHandCursor));
        courses_comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	color: #333333;\n"
"	border: none;\n"
"	background-color: #ffffff;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"	image: url(:/button/Resources/material/button/down.png);\n"
"	width: 20px;\n"
"	height: 10px;\n"
"}\n"
"\n"
"QComboBox::drop-down{\n"
"	border:none;\n"
"  \n"
"}\n"
"\n"
"QComboBox#comboBoxTwo::drop-down{\n"
"	border: none;\n"
"	background: none;  \n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item {\n"
"    font-size: 10px;\n"
"}"));
        courses_comboBox->setIconSize(QSize(16, 16));

        gridLayout->addWidget(courses_comboBox, 1, 0, 1, 2);

        create_time_text = new QLabel(course_base_frame);
        create_time_text->setObjectName(QString::fromUtf8("create_time_text"));
        create_time_text->setMinimumSize(QSize(200, 0));
        create_time_text->setMaximumSize(QSize(200, 16777215));
        create_time_text->setFont(font);
        create_time_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));

        gridLayout->addWidget(create_time_text, 2, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 0, 1, 6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 6);

        delete_course_btn = new QPushButton(course_base_frame);
        delete_course_btn->setObjectName(QString::fromUtf8("delete_course_btn"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(delete_course_btn->sizePolicy().hasHeightForWidth());
        delete_course_btn->setSizePolicy(sizePolicy2);
        delete_course_btn->setMinimumSize(QSize(0, 0));
        delete_course_btn->setMaximumSize(QSize(16777215, 16777215));
        delete_course_btn->setFont(font);
        delete_course_btn->setCursor(QCursor(Qt::PointingHandCursor));
        delete_course_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #bbbbbb;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	color: red;\n"
"}"));

        gridLayout->addWidget(delete_course_btn, 1, 5, 1, 1);

        course_id_text = new QLabel(course_base_frame);
        course_id_text->setObjectName(QString::fromUtf8("course_id_text"));
        course_id_text->setFont(font);
        course_id_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));
        course_id_text->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(course_id_text, 2, 4, 1, 2);

        label_2 = new QLabel(course_base_frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 2, 3, 1, 1);

        text = new QLabel(course_base_frame);
        text->setObjectName(QString::fromUtf8("text"));
        text->setMinimumSize(QSize(50, 0));
        text->setMaximumSize(QSize(50, 16777215));
        text->setFont(font);
        text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));
        text->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(text, 2, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 2, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 2, 1, 1);


        gridLayout_2->addWidget(course_base_frame, 2, 0, 1, 1);


        retranslateUi(TCourseManagementWidget);

        QMetaObject::connectSlotsByName(TCourseManagementWidget);
    } // setupUi

    void retranslateUi(QWidget *TCourseManagementWidget)
    {
        TCourseManagementWidget->setWindowTitle(QCoreApplication::translate("TCourseManagementWidget", "Form", nullptr));
        label_26->setText(QCoreApplication::translate("TCourseManagementWidget", "\350\257\276\347\250\213\347\256\241\347\220\206", nullptr));
        mini_program_btn->setText(QCoreApplication::translate("TCourseManagementWidget", "\345\260\217\347\250\213\345\272\217", nullptr));
        raise_hand_btn->setText(QCoreApplication::translate("TCourseManagementWidget", "\345\212\240\345\205\245\350\257\276\347\250\213", nullptr));
        raise_hand_btn_2->setText(QCoreApplication::translate("TCourseManagementWidget", "\345\210\233\345\273\272\350\257\276\347\250\213", nullptr));
        create_time_text->setText(QString());
        delete_course_btn->setText(QCoreApplication::translate("TCourseManagementWidget", "\345\210\240\351\231\244\350\257\276\347\250\213", nullptr));
        course_id_text->setText(QString());
        label_2->setText(QCoreApplication::translate("TCourseManagementWidget", "id: ", nullptr));
        text->setText(QCoreApplication::translate("TCourseManagementWidget", "\345\210\233\345\273\272\344\272\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TCourseManagementWidget: public Ui_TCourseManagementWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_T_COURSEMANAGEMENTWIDGET_H
