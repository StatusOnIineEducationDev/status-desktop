/********************************************************************************
** Form generated from reading UI file 'c_courseBaseWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_COURSEBASEWIDGET_H
#define UI_C_COURSEBASEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CourseBasicWidget
{
public:
    QGridLayout *gridLayout_2;
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

    void setupUi(QWidget *CourseBasicWidget)
    {
        if (CourseBasicWidget->objectName().isEmpty())
            CourseBasicWidget->setObjectName(QString::fromUtf8("CourseBasicWidget"));
        CourseBasicWidget->resize(825, 100);
        CourseBasicWidget->setMinimumSize(QSize(0, 100));
        CourseBasicWidget->setMaximumSize(QSize(16777215, 100));
        gridLayout_2 = new QGridLayout(CourseBasicWidget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        course_base_frame = new QFrame(CourseBasicWidget);
        course_base_frame->setObjectName(QString::fromUtf8("course_base_frame"));
        course_base_frame->setMinimumSize(QSize(0, 0));
        course_base_frame->setMaximumSize(QSize(16777215, 100));
        course_base_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: #fafafa;\n"
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
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(courses_comboBox->sizePolicy().hasHeightForWidth());
        courses_comboBox->setSizePolicy(sizePolicy);
        courses_comboBox->setMinimumSize(QSize(0, 0));
        courses_comboBox->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(16);
        courses_comboBox->setFont(font);
        courses_comboBox->setCursor(QCursor(Qt::PointingHandCursor));
        courses_comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	color: #333333;\n"
"	border: none;\n"
"	background: #fafafa;\n"
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
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        create_time_text->setFont(font1);
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
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(delete_course_btn->sizePolicy().hasHeightForWidth());
        delete_course_btn->setSizePolicy(sizePolicy1);
        delete_course_btn->setMinimumSize(QSize(0, 0));
        delete_course_btn->setMaximumSize(QSize(16777215, 16777215));
        delete_course_btn->setFont(font1);
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
        course_id_text->setFont(font1);
        course_id_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #999999;\n"
"}"));
        course_id_text->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(course_id_text, 2, 4, 1, 2);

        label_2 = new QLabel(course_base_frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
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
        text->setFont(font1);
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


        gridLayout_2->addWidget(course_base_frame, 0, 0, 1, 1);


        retranslateUi(CourseBasicWidget);

        QMetaObject::connectSlotsByName(CourseBasicWidget);
    } // setupUi

    void retranslateUi(QWidget *CourseBasicWidget)
    {
        CourseBasicWidget->setWindowTitle(QCoreApplication::translate("CourseBasicWidget", "Form", nullptr));
        create_time_text->setText(QString());
        delete_course_btn->setText(QCoreApplication::translate("CourseBasicWidget", "\351\200\200\345\207\272\350\257\276\347\250\213", nullptr));
        course_id_text->setText(QString());
        label_2->setText(QCoreApplication::translate("CourseBasicWidget", "id: ", nullptr));
        text->setText(QCoreApplication::translate("CourseBasicWidget", "\345\210\233\345\273\272\344\272\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CourseBasicWidget: public Ui_CourseBasicWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_COURSEBASEWIDGET_H
