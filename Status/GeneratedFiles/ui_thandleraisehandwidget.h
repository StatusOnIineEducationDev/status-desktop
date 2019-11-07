/********************************************************************************
** Form generated from reading UI file 'thandleraisehandwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THANDLERAISEHANDWIDGET_H
#define UI_THANDLERAISEHANDWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_THandleRaiseHandWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *shadow_frame;
    QGridLayout *gridLayout_4;
    QFrame *main_area;
    QGridLayout *gridLayout_2;
    QFrame *title_frame;
    QGridLayout *gridLayout_3;
    QLabel *title_text;
    QPushButton *close_btn;
    QListWidget *raise_hand_view;
    QPushButton *refuse_btn;
    QPushButton *accept_btn;

    void setupUi(QWidget *THandleRaiseHandWidget)
    {
        if (THandleRaiseHandWidget->objectName().isEmpty())
            THandleRaiseHandWidget->setObjectName(QString::fromUtf8("THandleRaiseHandWidget"));
        THandleRaiseHandWidget->resize(230, 280);
        THandleRaiseHandWidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(THandleRaiseHandWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        shadow_frame = new QFrame(THandleRaiseHandWidget);
        shadow_frame->setObjectName(QString::fromUtf8("shadow_frame"));
        shadow_frame->setStyleSheet(QString::fromUtf8("QFrame#shadow_frame {\n"
"	/*border-image\345\217\257\344\273\245\345\271\263\351\223\272\357\274\210\345\215\263\345\217\257\346\213\211\344\274\270\357\274\211*/\n"
"	border-image: url(:/shadow/Resources/material/shadow/220x270_shadow.png);\n"
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
"	border-radius: 5px;\n"
"	background: #ffffff;\n"
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
"QScrol"
                        "lBar::sub-line:vertical {\n"
"    height: 0px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}"));
        main_area->setFrameShape(QFrame::StyledPanel);
        main_area->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(main_area);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        title_frame = new QFrame(main_area);
        title_frame->setObjectName(QString::fromUtf8("title_frame"));
        title_frame->setStyleSheet(QString::fromUtf8("QFrame#title_frame {\n"
"	margin-left: 10px;\n"
"	margin-right: 10px;\n"
"	border: none;\n"
"	background: none;\n"
"	border-bottom: 1px solid #E6E6E6;\n"
"}"));
        title_frame->setFrameShape(QFrame::StyledPanel);
        title_frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(title_frame);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        title_text = new QLabel(title_frame);
        title_text->setObjectName(QString::fromUtf8("title_text"));
        title_text->setMinimumSize(QSize(0, 35));
        title_text->setMaximumSize(QSize(16777215, 35));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        title_text->setFont(font);
        title_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #666666;\n"
"}"));
        title_text->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_3->addWidget(title_text, 0, 0, 1, 1);

        close_btn = new QPushButton(title_frame);
        close_btn->setObjectName(QString::fromUtf8("close_btn"));
        close_btn->setMinimumSize(QSize(20, 20));
        close_btn->setMaximumSize(QSize(20, 20));
        close_btn->setCursor(QCursor(Qt::PointingHandCursor));
        close_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: none;\n"
"	border: none;\n"
"	border-radius: 5px;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/button/Resources/material/button/close_mini.png"), QSize(), QIcon::Normal, QIcon::Off);
        close_btn->setIcon(icon);
        close_btn->setIconSize(QSize(20, 20));

        gridLayout_3->addWidget(close_btn, 0, 1, 1, 1);


        gridLayout_2->addWidget(title_frame, 0, 0, 1, 2);

        raise_hand_view = new QListWidget(main_area);
        raise_hand_view->setObjectName(QString::fromUtf8("raise_hand_view"));
        raise_hand_view->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"	border: none;\n"
"	background: #ffffff;\n"
"}"));
        raise_hand_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        raise_hand_view->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

        gridLayout_2->addWidget(raise_hand_view, 1, 0, 1, 2);

        refuse_btn = new QPushButton(main_area);
        refuse_btn->setObjectName(QString::fromUtf8("refuse_btn"));
        refuse_btn->setMinimumSize(QSize(0, 30));
        refuse_btn->setMaximumSize(QSize(16777215, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        refuse_btn->setFont(font1);
        refuse_btn->setCursor(QCursor(Qt::PointingHandCursor));
        refuse_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	border-bottom-right-radius: 5px;\n"
"	border-top: 1px solid #E6E6E6;\n"
"	color: #666666;\n"
"	background: #ffffff;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #dedede;\n"
"}"));

        gridLayout_2->addWidget(refuse_btn, 2, 1, 1, 1);

        accept_btn = new QPushButton(main_area);
        accept_btn->setObjectName(QString::fromUtf8("accept_btn"));
        accept_btn->setMinimumSize(QSize(0, 30));
        accept_btn->setMaximumSize(QSize(16777215, 30));
        accept_btn->setFont(font1);
        accept_btn->setCursor(QCursor(Qt::PointingHandCursor));
        accept_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	border-bottom-left-radius: 5px;\n"
"	border-top: 1px solid #E6E6E6;\n"
"	border-right: 1px solid #E6E6E6;\n"
"	color: #0E71A4;\n"
"	background: #ffffff;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #dedede;\n"
"}"));

        gridLayout_2->addWidget(accept_btn, 2, 0, 1, 1);


        gridLayout_4->addWidget(main_area, 0, 0, 1, 1);


        gridLayout->addWidget(shadow_frame, 0, 0, 1, 1);


        retranslateUi(THandleRaiseHandWidget);
        QObject::connect(close_btn, SIGNAL(clicked()), THandleRaiseHandWidget, SLOT(hide()));

        QMetaObject::connectSlotsByName(THandleRaiseHandWidget);
    } // setupUi

    void retranslateUi(QWidget *THandleRaiseHandWidget)
    {
        THandleRaiseHandWidget->setWindowTitle(QCoreApplication::translate("THandleRaiseHandWidget", "Form", nullptr));
        title_text->setText(QCoreApplication::translate("THandleRaiseHandWidget", "\344\270\276\346\211\213", nullptr));
        close_btn->setText(QString());
        refuse_btn->setText(QCoreApplication::translate("THandleRaiseHandWidget", "\346\213\222\347\273\235", nullptr));
        accept_btn->setText(QCoreApplication::translate("THandleRaiseHandWidget", "\346\216\245\345\217\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class THandleRaiseHandWidget: public Ui_THandleRaiseHandWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THANDLERAISEHANDWIDGET_H
