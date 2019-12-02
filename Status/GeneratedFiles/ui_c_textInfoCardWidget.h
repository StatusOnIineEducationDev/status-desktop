/********************************************************************************
** Form generated from reading UI file 'c_textInfoCardWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_TEXTINFOCARDWIDGET_H
#define UI_C_TEXTINFOCARDWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TextInfoCardWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *edit_tool_frame;
    QGridLayout *gridLayout_9;
    QPushButton *confirm_btn;
    QLabel *max_count_text;
    QLabel *label;
    QLabel *now_count_text;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPlainTextEdit *content_TextEdit;
    QFrame *title_frame;
    QGridLayout *gridLayout_4;
    QLabel *title_text;
    QPushButton *edit_btn;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *TextInfoCardWidget)
    {
        if (TextInfoCardWidget->objectName().isEmpty())
            TextInfoCardWidget->setObjectName(QString::fromUtf8("TextInfoCardWidget"));
        TextInfoCardWidget->resize(800, 220);
        TextInfoCardWidget->setMinimumSize(QSize(0, 220));
        TextInfoCardWidget->setMaximumSize(QSize(16777215, 220));
        TextInfoCardWidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	border: none;\n"
"	background-color: #fafafa;\n"
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
"}\n"
"\n"
"/*\344\270\212\347\256\255\345\244\264*/\n"
"QScrollBar::sub-line:vertical {\n"
" "
                        "   height: 0px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}"));
        gridLayout = new QGridLayout(TextInfoCardWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(0);
        edit_tool_frame = new QFrame(TextInfoCardWidget);
        edit_tool_frame->setObjectName(QString::fromUtf8("edit_tool_frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(edit_tool_frame->sizePolicy().hasHeightForWidth());
        edit_tool_frame->setSizePolicy(sizePolicy);
        edit_tool_frame->setStyleSheet(QString::fromUtf8("background: #f0f0f0;\n"
"border-bottom-left-radius: 5px;\n"
"border-bottom-right-radius: 5px;"));
        edit_tool_frame->setFrameShape(QFrame::StyledPanel);
        edit_tool_frame->setFrameShadow(QFrame::Raised);
        gridLayout_9 = new QGridLayout(edit_tool_frame);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        confirm_btn = new QPushButton(edit_tool_frame);
        confirm_btn->setObjectName(QString::fromUtf8("confirm_btn"));
        confirm_btn->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(confirm_btn->sizePolicy().hasHeightForWidth());
        confirm_btn->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        confirm_btn->setFont(font);
        confirm_btn->setCursor(QCursor(Qt::PointingHandCursor));
        confirm_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	padding: 5px 20px 5px 20px;\n"
"	color: #ffffff;\n"
"	border: none;\n"
"	border-radius: 5px;\n"
"	background: #1296db;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background: #0E71A4;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	background-color: #818181;\n"
"}"));

        gridLayout_9->addWidget(confirm_btn, 0, 5, 1, 1);

        max_count_text = new QLabel(edit_tool_frame);
        max_count_text->setObjectName(QString::fromUtf8("max_count_text"));
        max_count_text->setFont(font);
        max_count_text->setStyleSheet(QString::fromUtf8("color: #999999;"));
        max_count_text->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_9->addWidget(max_count_text, 0, 3, 1, 1);

        label = new QLabel(edit_tool_frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: #999999;"));

        gridLayout_9->addWidget(label, 0, 2, 1, 1);

        now_count_text = new QLabel(edit_tool_frame);
        now_count_text->setObjectName(QString::fromUtf8("now_count_text"));
        now_count_text->setFont(font);
        now_count_text->setStyleSheet(QString::fromUtf8("color: #999999;"));

        gridLayout_9->addWidget(now_count_text, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_2, 0, 4, 1, 1);


        gridLayout->addWidget(edit_tool_frame, 3, 0, 1, 1);

        content_TextEdit = new QPlainTextEdit(TextInfoCardWidget);
        content_TextEdit->setObjectName(QString::fromUtf8("content_TextEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(content_TextEdit->sizePolicy().hasHeightForWidth());
        content_TextEdit->setSizePolicy(sizePolicy2);
        content_TextEdit->setMinimumSize(QSize(0, 100));
        content_TextEdit->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        content_TextEdit->setFont(font1);
        content_TextEdit->setStyleSheet(QString::fromUtf8("QPlainTextEdit {\n"
"	border: 1px solid #fafafa;\n"
"	border-top-left-radius: 5px;\n"
"	border-top-right-radius: 5px;\n"
"	color: #666666;\n"
"	background: #fafafa;\n"
"}\n"
""));
        content_TextEdit->setReadOnly(true);
        content_TextEdit->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout->addWidget(content_TextEdit, 2, 0, 1, 1);

        title_frame = new QFrame(TextInfoCardWidget);
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
        title_text = new QLabel(title_frame);
        title_text->setObjectName(QString::fromUtf8("title_text"));
        title_text->setMinimumSize(QSize(0, 25));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        title_text->setFont(font2);
        title_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #333333;\n"
"	background: none;\n"
"	border: none;\n"
"}"));

        gridLayout_4->addWidget(title_text, 1, 0, 1, 1);

        edit_btn = new QPushButton(title_frame);
        edit_btn->setObjectName(QString::fromUtf8("edit_btn"));
        sizePolicy1.setHeightForWidth(edit_btn->sizePolicy().hasHeightForWidth());
        edit_btn->setSizePolicy(sizePolicy1);
        edit_btn->setMinimumSize(QSize(0, 25));
        edit_btn->setMaximumSize(QSize(16777215, 25));
        edit_btn->setFont(font);
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


        gridLayout->addWidget(title_frame, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);


        retranslateUi(TextInfoCardWidget);

        QMetaObject::connectSlotsByName(TextInfoCardWidget);
    } // setupUi

    void retranslateUi(QWidget *TextInfoCardWidget)
    {
        TextInfoCardWidget->setWindowTitle(QCoreApplication::translate("TextInfoCardWidget", "Form", nullptr));
        confirm_btn->setText(QCoreApplication::translate("TextInfoCardWidget", "\346\233\264\346\224\271", nullptr));
        max_count_text->setText(QCoreApplication::translate("TextInfoCardWidget", "200", nullptr));
        label->setText(QCoreApplication::translate("TextInfoCardWidget", "/", nullptr));
        now_count_text->setText(QCoreApplication::translate("TextInfoCardWidget", "now_count", nullptr));
        content_TextEdit->setPlainText(QString());
        title_text->setText(QString());
        edit_btn->setText(QCoreApplication::translate("TextInfoCardWidget", "\347\274\226\350\276\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TextInfoCardWidget: public Ui_TextInfoCardWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_TEXTINFOCARDWIDGET_H
