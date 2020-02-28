/********************************************************************************
** Form generated from reading UI file 'c_cameraDisplayWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_CAMERADISPLAYWIDGET_H
#define UI_C_CAMERADISPLAYWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CameraDisplayWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *frame_label;
    QFrame *tool_frame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *username_text;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_7;

    void setupUi(QWidget *CameraDisplayWidget)
    {
        if (CameraDisplayWidget->objectName().isEmpty())
            CameraDisplayWidget->setObjectName(QString::fromUtf8("CameraDisplayWidget"));
        CameraDisplayWidget->resize(200, 130);
        CameraDisplayWidget->setMinimumSize(QSize(200, 130));
        CameraDisplayWidget->setMaximumSize(QSize(200, 130));
        gridLayout = new QGridLayout(CameraDisplayWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame_label = new QLabel(CameraDisplayWidget);
        frame_label->setObjectName(QString::fromUtf8("frame_label"));
        frame_label->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border:none;\n"
"	background: #f2f2f2;\n"
"	background-image: url(:/logo/Resources/material/logo/logo.png);\n"
"}"));
        frame_label->setScaledContents(false);

        gridLayout->addWidget(frame_label, 0, 0, 1, 1);

        tool_frame = new QFrame(CameraDisplayWidget);
        tool_frame->setObjectName(QString::fromUtf8("tool_frame"));
        tool_frame->setMinimumSize(QSize(0, 30));
        tool_frame->setMaximumSize(QSize(16777215, 30));
        tool_frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border: none;\n"
"	background-color: rgb(0, 0, 0);\n"
"}"));
        tool_frame->setFrameShape(QFrame::StyledPanel);
        tool_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(tool_frame);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 0, 10, 0);
        username_text = new QLabel(tool_frame);
        username_text->setObjectName(QString::fromUtf8("username_text"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        username_text->setFont(font);
        username_text->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: none;\n"
"	background: none;\n"
"	color: #ffffff;\n"
"}"));

        horizontalLayout_2->addWidget(username_text);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        pushButton_7 = new QPushButton(tool_frame);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(20, 0));
        pushButton_7->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: none;\n"
"	border: none;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/button/Resources/material/button/voice.png"), QSize(), QIcon::Active, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/button/Resources/material/button/voice_close.png"), QSize(), QIcon::Active, QIcon::On);
        pushButton_7->setIcon(icon);
        pushButton_7->setIconSize(QSize(15, 15));
        pushButton_7->setCheckable(true);
        pushButton_7->setChecked(false);

        horizontalLayout_2->addWidget(pushButton_7);


        gridLayout->addWidget(tool_frame, 1, 0, 1, 1);


        retranslateUi(CameraDisplayWidget);

        QMetaObject::connectSlotsByName(CameraDisplayWidget);
    } // setupUi

    void retranslateUi(QWidget *CameraDisplayWidget)
    {
        CameraDisplayWidget->setWindowTitle(QCoreApplication::translate("CameraDisplayWidget", "Form", nullptr));
        frame_label->setText(QString());
        username_text->setText(QCoreApplication::translate("CameraDisplayWidget", "-", nullptr));
        pushButton_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CameraDisplayWidget: public Ui_CameraDisplayWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_CAMERADISPLAYWIDGET_H
