/********************************************************************************
** Form generated from reading UI file 'c_fileItemWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_FILEITEMWIDGET_H
#define UI_C_FILEITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileItemWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *filename_text;
    QSpacerItem *horizontalSpacer_2;
    QLabel *file_type_pic;
    QLabel *title_text;
    QLabel *uploader_text;
    QLabel *upload_time_text;
    QLabel *file_size_text;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FileItemWidget)
    {
        if (FileItemWidget->objectName().isEmpty())
            FileItemWidget->setObjectName(QString::fromUtf8("FileItemWidget"));
        FileItemWidget->resize(825, 45);
        FileItemWidget->setStyleSheet(QString::fromUtf8("background: none;\n"
"border: none"));
        gridLayout = new QGridLayout(FileItemWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(25, 5, 25, 5);
        filename_text = new QLabel(FileItemWidget);
        filename_text->setObjectName(QString::fromUtf8("filename_text"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(filename_text->sizePolicy().hasHeightForWidth());
        filename_text->setSizePolicy(sizePolicy);
        filename_text->setMinimumSize(QSize(0, 0));
        filename_text->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(8);
        filename_text->setFont(font);
        filename_text->setStyleSheet(QString::fromUtf8("color: #999999;"));

        gridLayout->addWidget(filename_text, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 1, 2, 1);

        file_type_pic = new QLabel(FileItemWidget);
        file_type_pic->setObjectName(QString::fromUtf8("file_type_pic"));
        file_type_pic->setMinimumSize(QSize(20, 20));
        file_type_pic->setMaximumSize(QSize(20, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        file_type_pic->setFont(font1);
        file_type_pic->setScaledContents(true);
        file_type_pic->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(file_type_pic, 0, 0, 2, 1);

        title_text = new QLabel(FileItemWidget);
        title_text->setObjectName(QString::fromUtf8("title_text"));
        sizePolicy.setHeightForWidth(title_text->sizePolicy().hasHeightForWidth());
        title_text->setSizePolicy(sizePolicy);
        title_text->setMinimumSize(QSize(0, 0));
        title_text->setMaximumSize(QSize(16777215, 16777215));
        title_text->setFont(font1);
        title_text->setStyleSheet(QString::fromUtf8("color: #333333;"));

        gridLayout->addWidget(title_text, 0, 2, 1, 1);

        uploader_text = new QLabel(FileItemWidget);
        uploader_text->setObjectName(QString::fromUtf8("uploader_text"));
        uploader_text->setMinimumSize(QSize(150, 0));
        uploader_text->setMaximumSize(QSize(150, 16777215));
        uploader_text->setFont(font1);
        uploader_text->setStyleSheet(QString::fromUtf8("color: #999999;"));
        uploader_text->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(uploader_text, 0, 5, 2, 1);

        upload_time_text = new QLabel(FileItemWidget);
        upload_time_text->setObjectName(QString::fromUtf8("upload_time_text"));
        upload_time_text->setMinimumSize(QSize(200, 0));
        upload_time_text->setMaximumSize(QSize(200, 16777215));
        upload_time_text->setFont(font1);
        upload_time_text->setStyleSheet(QString::fromUtf8("color: #999999;"));
        upload_time_text->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(upload_time_text, 0, 4, 2, 1);

        file_size_text = new QLabel(FileItemWidget);
        file_size_text->setObjectName(QString::fromUtf8("file_size_text"));
        file_size_text->setMinimumSize(QSize(70, 0));
        file_size_text->setMaximumSize(QSize(70, 16777215));
        file_size_text->setFont(font1);
        file_size_text->setStyleSheet(QString::fromUtf8("color: #999999;"));
        file_size_text->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(file_size_text, 0, 6, 2, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 2, 1);


        retranslateUi(FileItemWidget);

        QMetaObject::connectSlotsByName(FileItemWidget);
    } // setupUi

    void retranslateUi(QWidget *FileItemWidget)
    {
        FileItemWidget->setWindowTitle(QCoreApplication::translate("FileItemWidget", "Form", nullptr));
        filename_text->setText(QCoreApplication::translate("FileItemWidget", "filename", nullptr));
        file_type_pic->setText(QCoreApplication::translate("FileItemWidget", "pic", nullptr));
        title_text->setText(QCoreApplication::translate("FileItemWidget", "title", nullptr));
        uploader_text->setText(QCoreApplication::translate("FileItemWidget", "uploader", nullptr));
        upload_time_text->setText(QCoreApplication::translate("FileItemWidget", "upload_time", nullptr));
        file_size_text->setText(QCoreApplication::translate("FileItemWidget", "file_size", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileItemWidget: public Ui_FileItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_FILEITEMWIDGET_H
