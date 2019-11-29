/********************************************************************************
** Form generated from reading UI file 'c_courseOverviewWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_COURSEOVERVIEWWIDGET_H
#define UI_C_COURSEOVERVIEWWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CourseOverviewWidget
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QFrame *introduction_frame;
    QGridLayout *gridLayout_3;
    QFrame *title_frame;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QPushButton *edit_btn;
    QPlainTextEdit *plainTextEdit;
    QFrame *introduction_edit_tool_frame;
    QGridLayout *gridLayout_9;
    QPushButton *confirm_btn;
    QLabel *num_of_words_text;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QFrame *teaching_member_frame;
    QGridLayout *gridLayout_5;
    QFrame *title_frame_2;
    QGridLayout *gridLayout_6;
    QLabel *label_2;
    QListWidget *listWidget;

    void setupUi(QWidget *CourseOverviewWidget)
    {
        if (CourseOverviewWidget->objectName().isEmpty())
            CourseOverviewWidget->setObjectName(QString::fromUtf8("CourseOverviewWidget"));
        CourseOverviewWidget->resize(825, 450);
        CourseOverviewWidget->setStyleSheet(QString::fromUtf8("QWidget#CourseOverviewWidget {\n"
"	background: #fafafa;\n"
"}\n"
"\n"
"QScrollArea#scrollArea {\n"
"	border: none;\n"
"	background-color:transparent;\n"
"}\n"
"\n"
"/*\346\225\264\344\275\223*/\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background-color: #F3F4F8;\n"
"    width: 10px;\n"
"}\n"
"\n"
"QScrollBar:vertical:hover {\n"
"    border: none;\n"
"    background-color: rgb(220, 220, 220);\n"
"    width: 10px;\n"
"}\n"
"\n"
"\n"
"/*\346\273\232\345\212\250\346\235\241*/\n"
"QScrollBar::handle:vertical {\n"
"	border-radius: 5px;\n"
"    background: rgb(220, 220, 220);\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"/*\346\273\232\345\212\250\346\235\241\357\274\232\346\202\254\346\265\256*/\n"
"QScrollBar::handle:vertical:hover {\n"
"	border-radius: 5px;\n"
"    background: rgb(200, 200, 200);\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"/*\344\270\213\347\256\255\345\244\264*/\n"
"QScrollBar::add-line:vertical {\n"
"    height: 0;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
""
                        "}\n"
"\n"
"/*\344\270\212\347\256\255\345\244\264*/\n"
"QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}"));
        gridLayout = new QGridLayout(CourseOverviewWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(CourseOverviewWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMaximumSize(QSize(16777215, 16777215));
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 815, 1000));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 1000));
        scrollAreaWidgetContents->setMaximumSize(QSize(1200, 16777215));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8("border: none;\n"
"background-color: #fafafa;"));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        introduction_frame = new QFrame(scrollAreaWidgetContents);
        introduction_frame->setObjectName(QString::fromUtf8("introduction_frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(introduction_frame->sizePolicy().hasHeightForWidth());
        introduction_frame->setSizePolicy(sizePolicy);
        introduction_frame->setMinimumSize(QSize(0, 0));
        introduction_frame->setMaximumSize(QSize(16777215, 16777215));
        introduction_frame->setStyleSheet(QString::fromUtf8(""));
        introduction_frame->setFrameShape(QFrame::StyledPanel);
        introduction_frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(introduction_frame);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setVerticalSpacing(0);
        title_frame = new QFrame(introduction_frame);
        title_frame->setObjectName(QString::fromUtf8("title_frame"));
        sizePolicy.setHeightForWidth(title_frame->sizePolicy().hasHeightForWidth());
        title_frame->setSizePolicy(sizePolicy);
        title_frame->setMinimumSize(QSize(0, 0));
        title_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border-bottom: 1px solid #E8ECEC;\n"
"}"));
        title_frame->setFrameShape(QFrame::StyledPanel);
        title_frame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(title_frame);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, -1, 0, -1);
        label = new QLabel(title_frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #333333;\n"
"	background: none;\n"
"	border: none;\n"
"}"));

        gridLayout_4->addWidget(label, 1, 0, 1, 1);

        edit_btn = new QPushButton(title_frame);
        edit_btn->setObjectName(QString::fromUtf8("edit_btn"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(edit_btn->sizePolicy().hasHeightForWidth());
        edit_btn->setSizePolicy(sizePolicy1);
        edit_btn->setMinimumSize(QSize(0, 25));
        edit_btn->setMaximumSize(QSize(16777215, 25));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        edit_btn->setFont(font1);
        edit_btn->setCursor(QCursor(Qt::PointingHandCursor));
        edit_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #666666;\n"
"	background: #ffffff;\n"
"	border: 1px solid #E8ECEC;\n"
"	border-radius: 12px;\n"
"	padding-left: 10px;\n"
"	padding-right: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #dedede;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/button/Resources/material/button/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        edit_btn->setIcon(icon);
        edit_btn->setIconSize(QSize(17, 17));

        gridLayout_4->addWidget(edit_btn, 1, 1, 1, 1);


        gridLayout_3->addWidget(title_frame, 1, 0, 1, 2);

        plainTextEdit = new QPlainTextEdit(introduction_frame);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy2);
        plainTextEdit->setMaximumSize(QSize(16777215, 100));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        plainTextEdit->setFont(font2);
        plainTextEdit->setStyleSheet(QString::fromUtf8("QPlainTextEdit {\n"
"	border: 1px solid #fafafa;\n"
"	border-top-left-radius: 5px;\n"
"	border-top-right-radius: 5px;\n"
"	color: #666666;\n"
"	background: #fafafa;\n"
"}\n"
"\n"
"QPlainTextEdit::focus {\n"
"	border: 1px solid #E8ECEC;\n"
"	background: #ffffff;\n"
"	color: #333333;\n"
"}"));
        plainTextEdit->setReadOnly(true);
        plainTextEdit->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_3->addWidget(plainTextEdit, 3, 0, 1, 2);

        introduction_edit_tool_frame = new QFrame(introduction_frame);
        introduction_edit_tool_frame->setObjectName(QString::fromUtf8("introduction_edit_tool_frame"));
        sizePolicy.setHeightForWidth(introduction_edit_tool_frame->sizePolicy().hasHeightForWidth());
        introduction_edit_tool_frame->setSizePolicy(sizePolicy);
        introduction_edit_tool_frame->setStyleSheet(QString::fromUtf8("background: #f0f0f0;\n"
"border-bottom-left-radius: 5px;\n"
"border-bottom-right-radius: 5px;"));
        introduction_edit_tool_frame->setFrameShape(QFrame::StyledPanel);
        introduction_edit_tool_frame->setFrameShadow(QFrame::Raised);
        gridLayout_9 = new QGridLayout(introduction_edit_tool_frame);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        confirm_btn = new QPushButton(introduction_edit_tool_frame);
        confirm_btn->setObjectName(QString::fromUtf8("confirm_btn"));
        sizePolicy1.setHeightForWidth(confirm_btn->sizePolicy().hasHeightForWidth());
        confirm_btn->setSizePolicy(sizePolicy1);
        confirm_btn->setFont(font1);
        confirm_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	padding: 5px 20px 5px 20px;\n"
"	color: #ffffff;\n"
"	border: none;\n"
"	border-radius: 5px;\n"
"	background-color: #1296db;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #0E71A4;\n"
"}"));

        gridLayout_9->addWidget(confirm_btn, 0, 1, 1, 1);

        num_of_words_text = new QLabel(introduction_edit_tool_frame);
        num_of_words_text->setObjectName(QString::fromUtf8("num_of_words_text"));
        num_of_words_text->setFont(font1);
        num_of_words_text->setStyleSheet(QString::fromUtf8("color: #999999;"));
        num_of_words_text->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_9->addWidget(num_of_words_text, 0, 0, 1, 1);


        gridLayout_3->addWidget(introduction_edit_tool_frame, 4, 0, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_3->addItem(verticalSpacer_2, 2, 0, 1, 2);


        gridLayout_2->addWidget(introduction_frame, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 3, 0, 1, 1);

        teaching_member_frame = new QFrame(scrollAreaWidgetContents);
        teaching_member_frame->setObjectName(QString::fromUtf8("teaching_member_frame"));
        teaching_member_frame->setMinimumSize(QSize(0, 200));
        teaching_member_frame->setMaximumSize(QSize(16777215, 200));
        teaching_member_frame->setFrameShape(QFrame::StyledPanel);
        teaching_member_frame->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(teaching_member_frame);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        title_frame_2 = new QFrame(teaching_member_frame);
        title_frame_2->setObjectName(QString::fromUtf8("title_frame_2"));
        title_frame_2->setMinimumSize(QSize(0, 0));
        title_frame_2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: none;\n"
"	border-bottom: 1px solid #E8ECEC;\n"
"}"));
        title_frame_2->setFrameShape(QFrame::StyledPanel);
        title_frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(title_frame_2);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, -1, 0, -1);
        label_2 = new QLabel(title_frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 25));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #333333;\n"
"	border: none;\n"
"}"));

        gridLayout_6->addWidget(label_2, 1, 0, 1, 1);


        gridLayout_5->addWidget(title_frame_2, 1, 0, 1, 2);

        listWidget = new QListWidget(teaching_member_frame);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"	background: none;\n"
"}"));

        gridLayout_5->addWidget(listWidget, 2, 0, 1, 1);


        gridLayout_2->addWidget(teaching_member_frame, 2, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(CourseOverviewWidget);

        QMetaObject::connectSlotsByName(CourseOverviewWidget);
    } // setupUi

    void retranslateUi(QWidget *CourseOverviewWidget)
    {
        CourseOverviewWidget->setWindowTitle(QCoreApplication::translate("CourseOverviewWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("CourseOverviewWidget", "\350\257\276\347\250\213\344\273\213\347\273\215", nullptr));
        edit_btn->setText(QCoreApplication::translate("CourseOverviewWidget", "\347\274\226\350\276\221", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("CourseOverviewWidget", "\351\200\232\350\277\207\346\234\254\350\257\276\347\250\213\347\232\204\345\255\246\344\271\240\357\274\214\344\275\277\345\255\246\347\224\237\344\272\206\350\247\243\350\275\257\344\273\266\345\267\245\347\250\213\347\232\204\345\237\272\346\234\254\346\246\202\345\277\265\343\200\201\345\237\272\346\234\254\345\216\237\347\220\206\343\200\201\345\274\200\345\217\221\350\275\257\344\273\266\351\241\271\347\233\256\347\232\204\345\267\245\347\250\213\345\214\226\347\232\204\346\226\271\346\263\225\345\222\214\346\212\200\346\234\257\345\217\212\345\234\250\345\274\200\345\217\221\350\277\207\347\250\213\344\270\255\345\272\224\351\201\265\345\276\252\347\232\204\346\265\201\347\250\213\343\200\201\345\207\206\345\210\231\343\200\201\346\240\207\345\207\206\345\222\214\350\247\204\350\214\203\347\255\211\357\274\233\347\206\237\346\202\211\350\275\257\344\273\266\351\241\271\347\233\256\345\274\200\345\217\221\345\222\214\347\273\264\346\212\244\347\232\204\344\270\200\350\210\254\350\277\207\347\250\213\357\274"
                        "\233\347\206\237\347\273\203\346\216\214\346\217\241\350\275\257\344\273\266\351\234\200\346\261\202\345\210\206\346\236\220\343\200\201\350\256\276\350\256\241\343\200\201\347\274\226\347\240\201\345\222\214\346\265\213\350\257\225\347\255\211\351\230\266\346\256\265\347\232\204\344\270\273\350\246\201\346\200\235\346\203\263\345\222\214\346\212\200\346\234\257\346\226\271\346\263\225\357\274\214\345\271\266\344\270\224\350\203\275\345\244\237\345\210\251\347\224\250\346\211\200\345\255\246\347\237\245\350\257\206\350\277\233\350\241\214\345\220\204\347\247\215\350\275\257\344\273\266\351\241\271\347\233\256\347\232\204\345\256\236\351\231\205\345\274\200\345\217\221\345\256\236\350\267\265\343\200\202", nullptr));
        confirm_btn->setText(QCoreApplication::translate("CourseOverviewWidget", "\346\233\264\346\224\271", nullptr));
        num_of_words_text->setText(QCoreApplication::translate("CourseOverviewWidget", "max count", nullptr));
        label_2->setText(QCoreApplication::translate("CourseOverviewWidget", "\346\225\231\345\255\246\351\230\237\344\274\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CourseOverviewWidget: public Ui_CourseOverviewWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_COURSEOVERVIEWWIDGET_H
