/********************************************************************************
** Form generated from reading UI file 'c_memberWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_MEMBERWIDGET_H
#define UI_C_MEMBERWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MemberWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *member_frame;
    QVBoxLayout *verticalLayout;
    QFrame *search_frame;
    QGridLayout *gridLayout_3;
    QLineEdit *search_lineEdit;
    QPushButton *search_btn;
    QListWidget *member_view;
    QLabel *label_9;

    void setupUi(QWidget *MemberWidget)
    {
        if (MemberWidget->objectName().isEmpty())
            MemberWidget->setObjectName(QString::fromUtf8("MemberWidget"));
        MemberWidget->resize(240, 565);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MemberWidget->sizePolicy().hasHeightForWidth());
        MemberWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(MemberWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        member_frame = new QFrame(MemberWidget);
        member_frame->setObjectName(QString::fromUtf8("member_frame"));
        member_frame->setMinimumSize(QSize(240, 0));
        member_frame->setMaximumSize(QSize(240, 16777215));
        member_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: #ffffff;\n"
"	border-left: 1px solid #E8ECEC;\n"
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
"QScrollBar::sub-line:ve"
                        "rtical {\n"
"    height: 0px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}"));
        member_frame->setFrameShape(QFrame::StyledPanel);
        member_frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(member_frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 6, 0, 0);
        search_frame = new QFrame(member_frame);
        search_frame->setObjectName(QString::fromUtf8("search_frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(search_frame->sizePolicy().hasHeightForWidth());
        search_frame->setSizePolicy(sizePolicy1);
        search_frame->setStyleSheet(QString::fromUtf8("border: 1px solid #E8ECEC;\n"
"border-radius: 15px;\n"
"margin-left: 10px;\n"
"margin-right: 10px;\n"
""));
        search_frame->setFrameShape(QFrame::StyledPanel);
        search_frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(search_frame);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(2, 5, 5, 5);
        search_lineEdit = new QLineEdit(search_frame);
        search_lineEdit->setObjectName(QString::fromUtf8("search_lineEdit"));
        search_lineEdit->setMinimumSize(QSize(0, 0));
        search_lineEdit->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        search_lineEdit->setFont(font);
        search_lineEdit->setStyleSheet(QString::fromUtf8("background: none;\n"
"border: none;\n"
"padding-left: 10px;"));

        gridLayout_3->addWidget(search_lineEdit, 0, 0, 1, 1);

        search_btn = new QPushButton(search_frame);
        search_btn->setObjectName(QString::fromUtf8("search_btn"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(search_btn->sizePolicy().hasHeightForWidth());
        search_btn->setSizePolicy(sizePolicy2);
        search_btn->setCursor(QCursor(Qt::PointingHandCursor));
        search_btn->setStyleSheet(QString::fromUtf8("background: none;\n"
"border: none;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/button/Resources/material/button/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        search_btn->setIcon(icon);

        gridLayout_3->addWidget(search_btn, 0, 1, 1, 1);


        verticalLayout->addWidget(search_frame);

        member_view = new QListWidget(member_frame);
        member_view->setObjectName(QString::fromUtf8("member_view"));
        member_view->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"	border: none;\n"
"	background: #ffffff;\n"
"}"));
        member_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout->addWidget(member_view);


        gridLayout->addWidget(member_frame, 1, 0, 1, 1);

        label_9 = new QLabel(MemberWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy3);
        label_9->setMinimumSize(QSize(0, 30));
        label_9->setMaximumSize(QSize(16777215, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("color: #666666;\n"
"background-color: #E8ECEC;\n"
"border: 1px solid #E8ECEC;"));
        label_9->setScaledContents(true);

        gridLayout->addWidget(label_9, 0, 0, 1, 1);


        retranslateUi(MemberWidget);

        QMetaObject::connectSlotsByName(MemberWidget);
    } // setupUi

    void retranslateUi(QWidget *MemberWidget)
    {
        MemberWidget->setWindowTitle(QCoreApplication::translate("MemberWidget", "Form", nullptr));
        search_lineEdit->setPlaceholderText(QCoreApplication::translate("MemberWidget", "\346\220\234\347\264\242\350\257\276\345\240\202\346\210\220\345\221\230", nullptr));
        search_btn->setText(QString());
        label_9->setText(QCoreApplication::translate("MemberWidget", "  \346\210\220\345\221\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MemberWidget: public Ui_MemberWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_MEMBERWIDGET_H
