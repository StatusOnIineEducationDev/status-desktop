/********************************************************************************
** Form generated from reading UI file 'c_courseResourceWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_COURSERESOURCEWIDGET_H
#define UI_C_COURSERESOURCEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CourseResourceWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *item_title_frame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QFrame *other_info_frame;
    QHBoxLayout *horizontalLayout_3;
    QLabel *file_count_text;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_3;
    QLabel *loading_tips_text;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *refresh_btn;
    QFrame *function_frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *upload_btn;
    QPushButton *download_btn;
    QPushButton *delete_btn;
    QSpacerItem *horizontalSpacer;
    QFrame *search_frame;
    QGridLayout *gridLayout_2;
    QPushButton *search_btn;
    QLineEdit *search_lineEdit;
    QFrame *listWidget_frame;
    QGridLayout *gridLayout_3;
    QListWidget *file_listWidget;

    void setupUi(QWidget *CourseResourceWidget)
    {
        if (CourseResourceWidget->objectName().isEmpty())
            CourseResourceWidget->setObjectName(QString::fromUtf8("CourseResourceWidget"));
        CourseResourceWidget->resize(825, 450);
        CourseResourceWidget->setStyleSheet(QString::fromUtf8("QWidget#CourseResourceWidget {\n"
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
        gridLayout = new QGridLayout(CourseResourceWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        item_title_frame = new QFrame(CourseResourceWidget);
        item_title_frame->setObjectName(QString::fromUtf8("item_title_frame"));
        item_title_frame->setMinimumSize(QSize(0, 30));
        item_title_frame->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Caslon Pro"));
        item_title_frame->setFont(font);
        item_title_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: #ffffff;\n"
"	border-bottom: 1px solid #E8ECEC;\n"
"}"));
        item_title_frame->setFrameShape(QFrame::StyledPanel);
        item_title_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(item_title_frame);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(25, 0, 25, 0);
        label = new QLabel(item_title_frame);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: #999999;\n"
"border: none;\n"
"background: none;"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_2 = new QLabel(item_title_frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(200, 0));
        label_2->setMaximumSize(QSize(200, 16777215));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: #999999;\n"
"border: none;\n"
"background: none;"));

        horizontalLayout_2->addWidget(label_2);

        label_3 = new QLabel(item_title_frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(150, 0));
        label_3->setMaximumSize(QSize(150, 16777215));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color: #999999;\n"
"border: none;\n"
"background: none;"));

        horizontalLayout_2->addWidget(label_3);

        label_4 = new QLabel(item_title_frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(70, 0));
        label_4->setMaximumSize(QSize(70, 16777215));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("color: #999999;\n"
"border: none;\n"
"background: none;"));

        horizontalLayout_2->addWidget(label_4);


        gridLayout->addWidget(item_title_frame, 1, 0, 1, 1);

        other_info_frame = new QFrame(CourseResourceWidget);
        other_info_frame->setObjectName(QString::fromUtf8("other_info_frame"));
        other_info_frame->setMinimumSize(QSize(0, 30));
        other_info_frame->setMaximumSize(QSize(16777215, 30));
        other_info_frame->setFont(font);
        other_info_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: #ffffff;\n"
"	border-top: 1px solid #E8ECEC;\n"
"}"));
        other_info_frame->setFrameShape(QFrame::StyledPanel);
        other_info_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(other_info_frame);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(10, 0, 10, 0);
        file_count_text = new QLabel(other_info_frame);
        file_count_text->setObjectName(QString::fromUtf8("file_count_text"));
        file_count_text->setFont(font1);
        file_count_text->setStyleSheet(QString::fromUtf8("color: #999999;\n"
"border: none;\n"
"background: none;"));

        horizontalLayout_3->addWidget(file_count_text);

        label_5 = new QLabel(other_info_frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("color: #999999;\n"
"border: none;\n"
"background: none;"));

        horizontalLayout_3->addWidget(label_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        loading_tips_text = new QLabel(other_info_frame);
        loading_tips_text->setObjectName(QString::fromUtf8("loading_tips_text"));
        loading_tips_text->setFont(font1);
        loading_tips_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	border: none;\n"
"	color: #999999;\n"
"}"));

        horizontalLayout_3->addWidget(loading_tips_text);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        refresh_btn = new QPushButton(other_info_frame);
        refresh_btn->setObjectName(QString::fromUtf8("refresh_btn"));
        refresh_btn->setCursor(QCursor(Qt::PointingHandCursor));
        refresh_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: none;\n"
"	border: none;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/button/Resources/material/button/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        refresh_btn->setIcon(icon);

        horizontalLayout_3->addWidget(refresh_btn);


        gridLayout->addWidget(other_info_frame, 3, 0, 1, 1);

        function_frame = new QFrame(CourseResourceWidget);
        function_frame->setObjectName(QString::fromUtf8("function_frame"));
        function_frame->setMinimumSize(QSize(0, 40));
        function_frame->setMaximumSize(QSize(16777215, 40));
        function_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: #ffffff;\n"
"	border-bottom: 1px solid #E8ECEC;\n"
"}"));
        function_frame->setFrameShape(QFrame::StyledPanel);
        function_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(function_frame);
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 0, 10, 0);
        upload_btn = new QPushButton(function_frame);
        upload_btn->setObjectName(QString::fromUtf8("upload_btn"));
        upload_btn->setMinimumSize(QSize(0, 30));
        upload_btn->setMaximumSize(QSize(16777215, 30));
        upload_btn->setFont(font1);
        upload_btn->setCursor(QCursor(Qt::PointingHandCursor));
        upload_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #666666;\n"
"	background: none;\n"
"	border: 1px solid #ffffff;\n"
"	border-radius: 2px;\n"
"	padding-left: 10px;\n"
"	padding-right: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	border: 1px solid rgba(18, 150, 214, 130);\n"
"	color: #1296d6;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/button/Resources/material/button/upload.png"), QSize(), QIcon::Normal, QIcon::Off);
        upload_btn->setIcon(icon1);

        horizontalLayout->addWidget(upload_btn);

        download_btn = new QPushButton(function_frame);
        download_btn->setObjectName(QString::fromUtf8("download_btn"));
        download_btn->setMinimumSize(QSize(0, 30));
        download_btn->setMaximumSize(QSize(16777215, 30));
        download_btn->setFont(font1);
        download_btn->setCursor(QCursor(Qt::PointingHandCursor));
        download_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #666666;\n"
"	background: none;\n"
"	border: 1px solid #ffffff;\n"
"	border-radius: 2px;\n"
"	padding-left: 10px;\n"
"	padding-right: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	border: 1px solid rgba(18, 150, 214, 130);\n"
"	color: #1296d6;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/button/Resources/material/button/download.png"), QSize(), QIcon::Normal, QIcon::Off);
        download_btn->setIcon(icon2);

        horizontalLayout->addWidget(download_btn);

        delete_btn = new QPushButton(function_frame);
        delete_btn->setObjectName(QString::fromUtf8("delete_btn"));
        delete_btn->setMinimumSize(QSize(0, 30));
        delete_btn->setMaximumSize(QSize(16777215, 30));
        delete_btn->setFont(font1);
        delete_btn->setCursor(QCursor(Qt::PointingHandCursor));
        delete_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #666666;\n"
"	background: none;\n"
"	border: 1px solid #ffffff;\n"
"	border-radius: 2px;\n"
"	padding-left: 10px;\n"
"	padding-right: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	border: 1px solid rgba(18, 150, 214, 130);\n"
"	color: #1296d6;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/button/Resources/material/button/delete_2.png"), QSize(), QIcon::Normal, QIcon::Off);
        delete_btn->setIcon(icon3);

        horizontalLayout->addWidget(delete_btn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        search_frame = new QFrame(function_frame);
        search_frame->setObjectName(QString::fromUtf8("search_frame"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(search_frame->sizePolicy().hasHeightForWidth());
        search_frame->setSizePolicy(sizePolicy);
        search_frame->setStyleSheet(QString::fromUtf8("background: none;\n"
"border: none;\n"
""));
        search_frame->setFrameShape(QFrame::StyledPanel);
        search_frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(search_frame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        search_btn = new QPushButton(search_frame);
        search_btn->setObjectName(QString::fromUtf8("search_btn"));
        search_btn->setCursor(QCursor(Qt::PointingHandCursor));
        search_btn->setStyleSheet(QString::fromUtf8("background: none;\n"
"border: none;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/button/Resources/material/button/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        search_btn->setIcon(icon4);

        gridLayout_2->addWidget(search_btn, 0, 1, 1, 1);

        search_lineEdit = new QLineEdit(search_frame);
        search_lineEdit->setObjectName(QString::fromUtf8("search_lineEdit"));
        search_lineEdit->setMinimumSize(QSize(150, 0));
        search_lineEdit->setMaximumSize(QSize(150, 16777215));
        search_lineEdit->setFont(font1);
        search_lineEdit->setStyleSheet(QString::fromUtf8("background: none;\n"
"border: none;\n"
"border-left: 1px solid #E8ECEC;\n"
"padding-left: 10px;"));

        gridLayout_2->addWidget(search_lineEdit, 0, 0, 1, 1);


        horizontalLayout->addWidget(search_frame);


        gridLayout->addWidget(function_frame, 0, 0, 1, 1);

        listWidget_frame = new QFrame(CourseResourceWidget);
        listWidget_frame->setObjectName(QString::fromUtf8("listWidget_frame"));
        listWidget_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	background: none;\n"
"	border: none;\n"
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
"}\n"
"\n"
"/*\344\270\212\347\256\255\345\244\264*/\n"
"QScrollBar::sub-line:vertical {\n"
"    he"
                        "ight: 0px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}"));
        listWidget_frame->setFrameShape(QFrame::StyledPanel);
        listWidget_frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(listWidget_frame);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        file_listWidget = new QListWidget(listWidget_frame);
        file_listWidget->setObjectName(QString::fromUtf8("file_listWidget"));
        file_listWidget->setStyleSheet(QString::fromUtf8("background: none;\n"
"border: none;"));
        file_listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        file_listWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

        gridLayout_3->addWidget(file_listWidget, 0, 0, 1, 1);


        gridLayout->addWidget(listWidget_frame, 2, 0, 1, 1);


        retranslateUi(CourseResourceWidget);

        QMetaObject::connectSlotsByName(CourseResourceWidget);
    } // setupUi

    void retranslateUi(QWidget *CourseResourceWidget)
    {
        CourseResourceWidget->setWindowTitle(QCoreApplication::translate("CourseResourceWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("CourseResourceWidget", "\346\226\207\344\273\266\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("CourseResourceWidget", "\344\270\212\344\274\240\346\227\266\351\227\264", nullptr));
        label_3->setText(QCoreApplication::translate("CourseResourceWidget", "\344\270\212\344\274\240\350\200\205", nullptr));
        label_4->setText(QCoreApplication::translate("CourseResourceWidget", "\345\244\247\345\260\217", nullptr));
        file_count_text->setText(QCoreApplication::translate("CourseResourceWidget", "0", nullptr));
        label_5->setText(QCoreApplication::translate("CourseResourceWidget", "\351\241\271", nullptr));
        loading_tips_text->setText(QCoreApplication::translate("CourseResourceWidget", "\345\212\240\350\275\275\344\270\255...", nullptr));
#if QT_CONFIG(tooltip)
        refresh_btn->setToolTip(QCoreApplication::translate("CourseResourceWidget", "\345\210\267\346\226\260", nullptr));
#endif // QT_CONFIG(tooltip)
        refresh_btn->setText(QString());
        upload_btn->setText(QCoreApplication::translate("CourseResourceWidget", "\344\270\212\344\274\240", nullptr));
        download_btn->setText(QCoreApplication::translate("CourseResourceWidget", "\344\270\213\350\275\275", nullptr));
        delete_btn->setText(QCoreApplication::translate("CourseResourceWidget", "\345\210\240\351\231\244", nullptr));
        search_btn->setText(QString());
        search_lineEdit->setPlaceholderText(QCoreApplication::translate("CourseResourceWidget", "\346\220\234\347\264\242\350\257\276\347\250\213\350\265\204\346\272\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CourseResourceWidget: public Ui_CourseResourceWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_COURSERESOURCEWIDGET_H
