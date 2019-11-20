/********************************************************************************
** Form generated from reading UI file 'c_chatAndInSpeechWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_CHATANDINSPEECHWIDGET_H
#define UI_C_CHATANDINSPEECHWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatAndInSpeechWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *flexible_main_area;
    QGridLayout *gridLayout_15;
    QFrame *chat_frame;
    QGridLayout *gridLayout_16;
    QPushButton *send_btn;
    QListWidget *chat_view;
    QLineEdit *chat_text_edit;
    QFrame *chat_tool_frame;
    QGridLayout *gridLayout_18;
    QPushButton *chat_clear_btn;
    QLabel *tips_text;
    QPushButton *chat_ban_btn;
    QLabel *label_36;
    QFrame *in_speech_member_frame;
    QGridLayout *gridLayout_17;
    QListWidget *in_speech_member_view;
    QFrame *in_speech_tool_frame;
    QGridLayout *gridLayout_19;
    QSpacerItem *horizontalSpacer;
    QPushButton *remove_btn;
    QLabel *label_37;

    void setupUi(QWidget *ChatAndInSpeechWidget)
    {
        if (ChatAndInSpeechWidget->objectName().isEmpty())
            ChatAndInSpeechWidget->setObjectName(QString::fromUtf8("ChatAndInSpeechWidget"));
        ChatAndInSpeechWidget->resize(238, 559);
        gridLayout = new QGridLayout(ChatAndInSpeechWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        flexible_main_area = new QFrame(ChatAndInSpeechWidget);
        flexible_main_area->setObjectName(QString::fromUtf8("flexible_main_area"));
        flexible_main_area->setMinimumSize(QSize(238, 0));
        flexible_main_area->setMaximumSize(QSize(238, 16777215));
        flexible_main_area->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background-color: #f0f0f0;\n"
"}\n"
"\n"
"/*\346\225\264\344\275\223*/\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background-color: #F3F4F8;\n"
"    width: 5px;\n"
"}\n"
"\n"
"QScrollBar:vertical:hover {\n"
"    border: none;\n"
"    background-color: rgb(220, 220, 220);\n"
"    width: 5px;\n"
"}\n"
"\n"
"\n"
"/*\346\273\232\345\212\250\346\235\241*/\n"
"QScrollBar::handle:vertical {\n"
"	border-radius: 2px;\n"
"    background: rgb(220, 220, 220);\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"/*\346\273\232\345\212\250\346\235\241\357\274\232\346\202\254\346\265\256*/\n"
"QScrollBar::handle:vertical:hover {\n"
"	border-radius: 2px;\n"
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
"    height: 0px;\n"
""
                        "    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}"));
        flexible_main_area->setFrameShape(QFrame::StyledPanel);
        flexible_main_area->setFrameShadow(QFrame::Raised);
        gridLayout_15 = new QGridLayout(flexible_main_area);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        gridLayout_15->setContentsMargins(5, 5, 5, 5);
        chat_frame = new QFrame(flexible_main_area);
        chat_frame->setObjectName(QString::fromUtf8("chat_frame"));
        chat_frame->setMinimumSize(QSize(0, 0));
        chat_frame->setStyleSheet(QString::fromUtf8(""));
        chat_frame->setFrameShape(QFrame::StyledPanel);
        chat_frame->setFrameShadow(QFrame::Raised);
        gridLayout_16 = new QGridLayout(chat_frame);
        gridLayout_16->setSpacing(0);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setContentsMargins(0, 0, 0, 0);
        send_btn = new QPushButton(chat_frame);
        send_btn->setObjectName(QString::fromUtf8("send_btn"));
        send_btn->setMinimumSize(QSize(30, 30));
        send_btn->setMaximumSize(QSize(30, 30));
        send_btn->setCursor(QCursor(Qt::PointingHandCursor));
        send_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #ffffff;\n"
"	border: none;\n"
"	background-color: #1296db;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #0E71A4;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/button/Resources/material/button/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        send_btn->setIcon(icon);

        gridLayout_16->addWidget(send_btn, 2, 1, 1, 1);

        chat_view = new QListWidget(chat_frame);
        chat_view->setObjectName(QString::fromUtf8("chat_view"));
        chat_view->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"	border: none;\n"
"	border-bottom: 1px solid #E8ECEC;\n"
"	background-color: #F8F8F8;\n"
"}\n"
"\n"
""));
        chat_view->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        chat_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        chat_view->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        chat_view->setSelectionMode(QAbstractItemView::SingleSelection);
        chat_view->setTextElideMode(Qt::ElideRight);
        chat_view->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        chat_view->setProperty("isWrapping", QVariant(false));
        chat_view->setResizeMode(QListView::Fixed);
        chat_view->setBatchSize(100);
        chat_view->setWordWrap(true);

        gridLayout_16->addWidget(chat_view, 0, 0, 1, 2);

        chat_text_edit = new QLineEdit(chat_frame);
        chat_text_edit->setObjectName(QString::fromUtf8("chat_text_edit"));
        chat_text_edit->setMinimumSize(QSize(0, 30));
        chat_text_edit->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        chat_text_edit->setFont(font);
        chat_text_edit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border: none;\n"
"	background-color: #F8F8F8;\n"
"}"));

        gridLayout_16->addWidget(chat_text_edit, 2, 0, 1, 1);

        chat_tool_frame = new QFrame(chat_frame);
        chat_tool_frame->setObjectName(QString::fromUtf8("chat_tool_frame"));
        chat_tool_frame->setMinimumSize(QSize(0, 30));
        chat_tool_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border: none;\n"
"	background-color: #F8F8F8;\n"
"}"));
        chat_tool_frame->setFrameShape(QFrame::StyledPanel);
        chat_tool_frame->setFrameShadow(QFrame::Raised);
        gridLayout_18 = new QGridLayout(chat_tool_frame);
        gridLayout_18->setSpacing(0);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        gridLayout_18->setContentsMargins(5, 2, 5, 2);
        chat_clear_btn = new QPushButton(chat_tool_frame);
        chat_clear_btn->setObjectName(QString::fromUtf8("chat_clear_btn"));
        chat_clear_btn->setMinimumSize(QSize(20, 20));
        chat_clear_btn->setMaximumSize(QSize(20, 20));
        chat_clear_btn->setCursor(QCursor(Qt::PointingHandCursor));
        chat_clear_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	border-radius: 3px;\n"
"	background: none;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #dedede;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/button/Resources/material/button/chat_clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        chat_clear_btn->setIcon(icon1);
        chat_clear_btn->setIconSize(QSize(17, 17));
        chat_clear_btn->setCheckable(false);

        gridLayout_18->addWidget(chat_clear_btn, 0, 2, 1, 1);

        tips_text = new QLabel(chat_tool_frame);
        tips_text->setObjectName(QString::fromUtf8("tips_text"));
        tips_text->setFont(font);
        tips_text->setStyleSheet(QString::fromUtf8("color: red;"));
        tips_text->setAlignment(Qt::AlignCenter);

        gridLayout_18->addWidget(tips_text, 0, 1, 1, 1);

        chat_ban_btn = new QPushButton(chat_tool_frame);
        chat_ban_btn->setObjectName(QString::fromUtf8("chat_ban_btn"));
        chat_ban_btn->setMinimumSize(QSize(20, 20));
        chat_ban_btn->setMaximumSize(QSize(20, 20));
        chat_ban_btn->setCursor(QCursor(Qt::PointingHandCursor));
        chat_ban_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	border-radius: 3px;\n"
"	background: none;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #dedede;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/button/Resources/material/button/chat_ban.png"), QSize(), QIcon::Normal, QIcon::Off);
        chat_ban_btn->setIcon(icon2);
        chat_ban_btn->setIconSize(QSize(15, 15));
        chat_ban_btn->setCheckable(true);

        gridLayout_18->addWidget(chat_ban_btn, 0, 0, 1, 1);


        gridLayout_16->addWidget(chat_tool_frame, 1, 0, 1, 2);


        gridLayout_15->addWidget(chat_frame, 5, 0, 1, 2);

        label_36 = new QLabel(flexible_main_area);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setFont(font);
        label_36->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #666666;\n"
"}"));
        label_36->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(label_36, 4, 0, 1, 2);

        in_speech_member_frame = new QFrame(flexible_main_area);
        in_speech_member_frame->setObjectName(QString::fromUtf8("in_speech_member_frame"));
        in_speech_member_frame->setMaximumSize(QSize(16777215, 100));
        in_speech_member_frame->setFrameShape(QFrame::StyledPanel);
        in_speech_member_frame->setFrameShadow(QFrame::Raised);
        gridLayout_17 = new QGridLayout(in_speech_member_frame);
        gridLayout_17->setSpacing(0);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        gridLayout_17->setContentsMargins(0, 0, 0, 0);
        in_speech_member_view = new QListWidget(in_speech_member_frame);
        in_speech_member_view->setObjectName(QString::fromUtf8("in_speech_member_view"));
        in_speech_member_view->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"	border: none;\n"
"	border-bottom: 1px solid #E8ECEC;\n"
"	background-color: #F8F8F8;\n"
"}"));
        in_speech_member_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout_17->addWidget(in_speech_member_view, 0, 0, 1, 1);

        in_speech_tool_frame = new QFrame(in_speech_member_frame);
        in_speech_tool_frame->setObjectName(QString::fromUtf8("in_speech_tool_frame"));
        in_speech_tool_frame->setMinimumSize(QSize(0, 30));
        in_speech_tool_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border: none;\n"
"	background-color: #F8F8F8;\n"
"}"));
        in_speech_tool_frame->setFrameShape(QFrame::StyledPanel);
        in_speech_tool_frame->setFrameShadow(QFrame::Raised);
        gridLayout_19 = new QGridLayout(in_speech_tool_frame);
        gridLayout_19->setSpacing(0);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        gridLayout_19->setContentsMargins(5, 2, 5, 2);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_19->addItem(horizontalSpacer, 0, 0, 1, 1);

        remove_btn = new QPushButton(in_speech_tool_frame);
        remove_btn->setObjectName(QString::fromUtf8("remove_btn"));
        remove_btn->setMinimumSize(QSize(20, 20));
        remove_btn->setMaximumSize(QSize(20, 20));
        remove_btn->setCursor(QCursor(Qt::PointingHandCursor));
        remove_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: none;\n"
"	border: none;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #dedede;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/button/Resources/material/button/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        remove_btn->setIcon(icon3);
        remove_btn->setIconSize(QSize(13, 13));

        gridLayout_19->addWidget(remove_btn, 0, 1, 1, 1);


        gridLayout_17->addWidget(in_speech_tool_frame, 1, 0, 1, 1);


        gridLayout_15->addWidget(in_speech_member_frame, 2, 0, 1, 2);

        label_37 = new QLabel(flexible_main_area);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setFont(font);
        label_37->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #666666;\n"
"}"));
        label_37->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(label_37, 0, 0, 1, 2);


        gridLayout->addWidget(flexible_main_area, 0, 0, 1, 1);


        retranslateUi(ChatAndInSpeechWidget);

        QMetaObject::connectSlotsByName(ChatAndInSpeechWidget);
    } // setupUi

    void retranslateUi(QWidget *ChatAndInSpeechWidget)
    {
        ChatAndInSpeechWidget->setWindowTitle(QCoreApplication::translate("ChatAndInSpeechWidget", "Form", nullptr));
#if QT_CONFIG(tooltip)
        send_btn->setToolTip(QCoreApplication::translate("ChatAndInSpeechWidget", "\345\217\221\351\200\201", nullptr));
#endif // QT_CONFIG(tooltip)
        send_btn->setText(QString());
#if QT_CONFIG(shortcut)
        send_btn->setShortcut(QCoreApplication::translate("ChatAndInSpeechWidget", "Enter", nullptr));
#endif // QT_CONFIG(shortcut)
        chat_text_edit->setPlaceholderText(QCoreApplication::translate("ChatAndInSpeechWidget", "\350\257\267\350\276\223\345\205\245\346\226\207\345\255\227", nullptr));
#if QT_CONFIG(tooltip)
        chat_clear_btn->setToolTip(QCoreApplication::translate("ChatAndInSpeechWidget", "\346\270\205\345\261\217", nullptr));
#endif // QT_CONFIG(tooltip)
        chat_clear_btn->setText(QString());
        tips_text->setText(QString());
#if QT_CONFIG(tooltip)
        chat_ban_btn->setToolTip(QCoreApplication::translate("ChatAndInSpeechWidget", "\347\246\201\350\250\200", nullptr));
#endif // QT_CONFIG(tooltip)
        chat_ban_btn->setText(QString());
        label_36->setText(QCoreApplication::translate("ChatAndInSpeechWidget", "\344\274\232\350\257\235\345\210\227\350\241\250", nullptr));
#if QT_CONFIG(tooltip)
        remove_btn->setToolTip(QCoreApplication::translate("ChatAndInSpeechWidget", "\347\247\273\351\231\244", nullptr));
#endif // QT_CONFIG(tooltip)
        remove_btn->setText(QString());
        label_37->setText(QCoreApplication::translate("ChatAndInSpeechWidget", "\345\217\221\350\250\200\344\270\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatAndInSpeechWidget: public Ui_ChatAndInSpeechWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_CHATANDINSPEECHWIDGET_H
