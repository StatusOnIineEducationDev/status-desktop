/********************************************************************************
** Form generated from reading UI file 'c_uploadFileDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_UPLOADFILEDIALOG_H
#define UI_C_UPLOADFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_UploadFileDialog
{
public:
    QGridLayout *gridLayout_3;
    QFrame *layout;
    QVBoxLayout *verticalLayout;
    QFrame *title_bar;
    QGridLayout *gridLayout_2;
    QLabel *title_text;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *close_btn;
    QFrame *main_area;
    QGridLayout *gridLayout;
    QFrame *text_frame;
    QGridLayout *gridLayout_4;
    QLineEdit *resource_title_edit;
    QLabel *label;
    QLabel *file_size_text;
    QLabel *label_2;
    QLabel *file_type_pic;
    QLabel *label_3;
    QLabel *filename_text;
    QPushButton *confirm_btn;
    QProgressBar *progressBar;
    QLabel *warn_text;

    void setupUi(QDialog *UploadFileDialog)
    {
        if (UploadFileDialog->objectName().isEmpty())
            UploadFileDialog->setObjectName(QString::fromUtf8("UploadFileDialog"));
        UploadFileDialog->resize(410, 260);
        UploadFileDialog->setStyleSheet(QString::fromUtf8(""));
        gridLayout_3 = new QGridLayout(UploadFileDialog);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        layout = new QFrame(UploadFileDialog);
        layout->setObjectName(QString::fromUtf8("layout"));
        layout->setStyleSheet(QString::fromUtf8("QFrame#layout {\n"
"	border-image: url(:/shadow/Resources/material/shadow/400x250_shadow.png);\n"
"	background: none;\n"
"}"));
        layout->setFrameShape(QFrame::StyledPanel);
        layout->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(layout);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        title_bar = new QFrame(layout);
        title_bar->setObjectName(QString::fromUtf8("title_bar"));
        title_bar->setMinimumSize(QSize(0, 35));
        title_bar->setMaximumSize(QSize(16777215, 35));
        title_bar->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border-top-left-radius: 4px;\n"
"	border-top-right-radius: 4px;\n"
"	background-color: #1D2B36;\n"
"}"));
        title_bar->setFrameShape(QFrame::StyledPanel);
        title_bar->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(title_bar);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        title_text = new QLabel(title_bar);
        title_text->setObjectName(QString::fromUtf8("title_text"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        title_text->setFont(font);
        title_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background: none;\n"
"	color: #ffffff;\n"
"}"));
        title_text->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(title_text, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(35, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 0, 1, 1);

        close_btn = new QPushButton(title_bar);
        close_btn->setObjectName(QString::fromUtf8("close_btn"));
        close_btn->setEnabled(true);
        close_btn->setMinimumSize(QSize(35, 35));
        close_btn->setMaximumSize(QSize(35, 35));
        close_btn->setCursor(QCursor(Qt::PointingHandCursor));
        close_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	border-top-right-radius: 4px;\n"
"	background-color: #1D2B36;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(244, 84, 84);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/button/Resources/material/button/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        close_btn->setIcon(icon);
        close_btn->setIconSize(QSize(12, 12));

        gridLayout_2->addWidget(close_btn, 0, 2, 1, 1);


        verticalLayout->addWidget(title_bar);

        main_area = new QFrame(layout);
        main_area->setObjectName(QString::fromUtf8("main_area"));
        main_area->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border-bottom-left-radius: 4px;\n"
"	border-bottom-right-radius: 4px;\n"
"	background-color: #fafafa;\n"
"}\n"
"\n"
""));
        main_area->setFrameShape(QFrame::StyledPanel);
        main_area->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(main_area);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(20, 10, 20, 10);
        text_frame = new QFrame(main_area);
        text_frame->setObjectName(QString::fromUtf8("text_frame"));
        text_frame->setFrameShape(QFrame::StyledPanel);
        text_frame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(text_frame);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setVerticalSpacing(0);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        resource_title_edit = new QLineEdit(text_frame);
        resource_title_edit->setObjectName(QString::fromUtf8("resource_title_edit"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        resource_title_edit->setFont(font1);
        resource_title_edit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border: none;\n"
"	color: #666666;\n"
"	background: #fafafa;\n"
"	border-bottom: 1px solid #666666;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"	border-bottom: 1px solid #1296d6;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"	border-bottom: 1px solid #1296d6;\n"
"}"));

        gridLayout_4->addWidget(resource_title_edit, 1, 1, 1, 2);

        label = new QLabel(text_frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 30));
        label->setMaximumSize(QSize(16777215, 30));
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("background: none;\n"
"border: none;\n"
"color: #666666;"));

        gridLayout_4->addWidget(label, 1, 0, 1, 1);

        file_size_text = new QLabel(text_frame);
        file_size_text->setObjectName(QString::fromUtf8("file_size_text"));
        file_size_text->setMinimumSize(QSize(0, 30));
        file_size_text->setMaximumSize(QSize(16777215, 30));
        file_size_text->setFont(font1);
        file_size_text->setStyleSheet(QString::fromUtf8("background: none;\n"
"border: none;\n"
"color: #999999;"));

        gridLayout_4->addWidget(file_size_text, 3, 1, 1, 2);

        label_2 = new QLabel(text_frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(0, 30));
        label_2->setMaximumSize(QSize(16777215, 30));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("background: none;\n"
"border: none;\n"
"color: #666666;"));

        gridLayout_4->addWidget(label_2, 2, 0, 1, 1);

        file_type_pic = new QLabel(text_frame);
        file_type_pic->setObjectName(QString::fromUtf8("file_type_pic"));
        file_type_pic->setMinimumSize(QSize(30, 30));
        file_type_pic->setMaximumSize(QSize(30, 30));
        file_type_pic->setFont(font1);
        file_type_pic->setScaledContents(true);
        file_type_pic->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(file_type_pic, 2, 1, 1, 1);

        label_3 = new QLabel(text_frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(0, 30));
        label_3->setMaximumSize(QSize(16777215, 30));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("background: none;\n"
"border: none;\n"
"color: #666666;"));

        gridLayout_4->addWidget(label_3, 3, 0, 1, 1);

        filename_text = new QLabel(text_frame);
        filename_text->setObjectName(QString::fromUtf8("filename_text"));
        filename_text->setMinimumSize(QSize(0, 30));
        filename_text->setMaximumSize(QSize(16777215, 30));
        filename_text->setFont(font1);
        filename_text->setStyleSheet(QString::fromUtf8("background: none;\n"
"border: none;\n"
"color: #999999;"));

        gridLayout_4->addWidget(filename_text, 2, 2, 1, 1);


        gridLayout->addWidget(text_frame, 2, 0, 1, 1);

        confirm_btn = new QPushButton(main_area);
        confirm_btn->setObjectName(QString::fromUtf8("confirm_btn"));
        confirm_btn->setEnabled(true);
        confirm_btn->setMinimumSize(QSize(0, 30));
        confirm_btn->setMaximumSize(QSize(16777215, 30));
        confirm_btn->setFont(font1);
        confirm_btn->setCursor(QCursor(Qt::PointingHandCursor));
        confirm_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #1296d6;\n"
"	background: none;\n"
"	border: 1px solid  #1296d6;\n"
"	border-radius: 15px;\n"
"	padding-left: 10px;\n"
"	padding-right: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E6E6E6;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"	color: #999999;\n"
"	background: none;\n"
"	border: 1px solid  #999999;\n"
"	border-radius: 15px;\n"
"	padding-left: 10px;\n"
"	padding-right: 10px;\n"
"}"));

        gridLayout->addWidget(confirm_btn, 4, 0, 1, 1);

        progressBar = new QProgressBar(main_area);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMinimumSize(QSize(0, 8));
        progressBar->setMaximumSize(QSize(16777215, 8));
        progressBar->setFont(font1);
        progressBar->setStyleSheet(QString::fromUtf8("QProgressBar{\n"
"        border: none;\n"
"		border-radius: 4px;\n"
"        color: black;\n"
"        text-align: right;\n"
"        background: #ffffff;\n"
"}\n"
"QProgressBar::chunk {\n"
"        border: none;\n"
"		border-radius: 4px;\n"
"        background: #1296d6;\n"
"}"));
        progressBar->setValue(0);
        progressBar->setTextVisible(false);

        gridLayout->addWidget(progressBar, 0, 0, 1, 1);

        warn_text = new QLabel(main_area);
        warn_text->setObjectName(QString::fromUtf8("warn_text"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(warn_text->sizePolicy().hasHeightForWidth());
        warn_text->setSizePolicy(sizePolicy1);
        warn_text->setFont(font1);
        warn_text->setStyleSheet(QString::fromUtf8("background: none;\n"
"border: none;\n"
"color: red;"));
        warn_text->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(warn_text, 5, 0, 1, 1);


        verticalLayout->addWidget(main_area);


        gridLayout_3->addWidget(layout, 0, 0, 1, 1);


        retranslateUi(UploadFileDialog);
        QObject::connect(close_btn, SIGNAL(clicked()), UploadFileDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(UploadFileDialog);
    } // setupUi

    void retranslateUi(QDialog *UploadFileDialog)
    {
        UploadFileDialog->setWindowTitle(QCoreApplication::translate("UploadFileDialog", "Dialog", nullptr));
        title_text->setText(QCoreApplication::translate("UploadFileDialog", "\344\270\212\344\274\240\350\265\204\346\272\220", nullptr));
#if QT_CONFIG(tooltip)
        close_btn->setToolTip(QCoreApplication::translate("UploadFileDialog", "\345\205\263\351\227\255", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        close_btn->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        close_btn->setText(QString());
        label->setText(QCoreApplication::translate("UploadFileDialog", "\350\265\204\346\272\220\346\240\207\351\242\230\357\274\232", nullptr));
        file_size_text->setText(QCoreApplication::translate("UploadFileDialog", "file_size", nullptr));
        label_2->setText(QCoreApplication::translate("UploadFileDialog", "\346\226\207\344\273\266\345\220\215\357\274\232", nullptr));
        file_type_pic->setText(QCoreApplication::translate("UploadFileDialog", "pic", nullptr));
        label_3->setText(QCoreApplication::translate("UploadFileDialog", "\346\226\207\344\273\266\345\244\247\345\260\217\357\274\232", nullptr));
        filename_text->setText(QCoreApplication::translate("UploadFileDialog", "filename", nullptr));
        confirm_btn->setText(QCoreApplication::translate("UploadFileDialog", "\345\274\200\345\247\213\344\270\212\344\274\240", nullptr));
        warn_text->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UploadFileDialog: public Ui_UploadFileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_UPLOADFILEDIALOG_H
