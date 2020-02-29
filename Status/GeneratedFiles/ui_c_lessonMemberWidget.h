/********************************************************************************
** Form generated from reading UI file 'c_lessonMemberWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_LESSONMEMBERWIDGET_H
#define UI_C_LESSONMEMBERWIDGET_H

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

class Ui_LessonMemberWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *member_frame;
    QVBoxLayout *verticalLayout;
    QLabel *label_9;
    QFrame *search_frame;
    QGridLayout *gridLayout_3;
    QLineEdit *search_lineEdit;
    QPushButton *search_btn;
    QListWidget *in_speech_member_view;

    void setupUi(QWidget *LessonMemberWidget)
    {
        if (LessonMemberWidget->objectName().isEmpty())
            LessonMemberWidget->setObjectName(QString::fromUtf8("LessonMemberWidget"));
        LessonMemberWidget->resize(240, 683);
        gridLayout = new QGridLayout(LessonMemberWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        member_frame = new QFrame(LessonMemberWidget);
        member_frame->setObjectName(QString::fromUtf8("member_frame"));
        member_frame->setMinimumSize(QSize(240, 0));
        member_frame->setMaximumSize(QSize(240, 16777215));
        member_frame->setStyleSheet(QString::fromUtf8("background: #ffffff;\n"
"border-left: 1px solid #E8ECEC;\n"
""));
        member_frame->setFrameShape(QFrame::StyledPanel);
        member_frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(member_frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(member_frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setMinimumSize(QSize(0, 30));
        label_9->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("color: #666666;\n"
"background-color: #E8ECEC;\n"
"border: none;"));
        label_9->setScaledContents(true);

        verticalLayout->addWidget(label_9);

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
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        search_lineEdit->setFont(font1);
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

        in_speech_member_view = new QListWidget(member_frame);
        in_speech_member_view->setObjectName(QString::fromUtf8("in_speech_member_view"));
        in_speech_member_view->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"	border: none;\n"
"	background: #ffffff;\n"
"}"));
        in_speech_member_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout->addWidget(in_speech_member_view);


        gridLayout->addWidget(member_frame, 0, 0, 1, 1);


        retranslateUi(LessonMemberWidget);

        QMetaObject::connectSlotsByName(LessonMemberWidget);
    } // setupUi

    void retranslateUi(QWidget *LessonMemberWidget)
    {
        LessonMemberWidget->setWindowTitle(QCoreApplication::translate("LessonMemberWidget", "Form", nullptr));
        label_9->setText(QCoreApplication::translate("LessonMemberWidget", "  \346\210\220\345\221\230", nullptr));
        search_lineEdit->setPlaceholderText(QCoreApplication::translate("LessonMemberWidget", "\346\220\234\347\264\242\350\257\276\345\240\202\346\210\220\345\221\230", nullptr));
        search_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LessonMemberWidget: public Ui_LessonMemberWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_LESSONMEMBERWIDGET_H
