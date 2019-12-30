/********************************************************************************
** Form generated from reading UI file 'c_courseAnalysisRankItemWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_COURSEANALYSISRANKITEMWIDGET_H
#define UI_C_COURSEANALYSISRANKITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CourseAnalysisRankItemWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *times_text;
    QLabel *concentration_text;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *user_pic;
    QSpacerItem *horizontalSpacer_3;
    QLabel *username_text;
    QSpacerItem *horizontalSpacer_2;
    QLabel *rank_text;

    void setupUi(QWidget *CourseAnalysisRankItemWidget)
    {
        if (CourseAnalysisRankItemWidget->objectName().isEmpty())
            CourseAnalysisRankItemWidget->setObjectName(QString::fromUtf8("CourseAnalysisRankItemWidget"));
        CourseAnalysisRankItemWidget->resize(825, 45);
        CourseAnalysisRankItemWidget->setStyleSheet(QString::fromUtf8("background: none;\n"
"border: none"));
        gridLayout = new QGridLayout(CourseAnalysisRankItemWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(20, 5, 20, 5);
        times_text = new QLabel(CourseAnalysisRankItemWidget);
        times_text->setObjectName(QString::fromUtf8("times_text"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(times_text->sizePolicy().hasHeightForWidth());
        times_text->setSizePolicy(sizePolicy);
        times_text->setMinimumSize(QSize(0, 0));
        times_text->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        times_text->setFont(font);
        times_text->setStyleSheet(QString::fromUtf8("color: #999999;"));
        times_text->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(times_text, 0, 1, 2, 1);

        concentration_text = new QLabel(CourseAnalysisRankItemWidget);
        concentration_text->setObjectName(QString::fromUtf8("concentration_text"));
        sizePolicy.setHeightForWidth(concentration_text->sizePolicy().hasHeightForWidth());
        concentration_text->setSizePolicy(sizePolicy);
        concentration_text->setMinimumSize(QSize(0, 0));
        concentration_text->setMaximumSize(QSize(16777215, 16777215));
        concentration_text->setFont(font);
        concentration_text->setStyleSheet(QString::fromUtf8("color: #999999;"));
        concentration_text->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(concentration_text, 0, 2, 2, 1);

        frame = new QFrame(CourseAnalysisRankItemWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        user_pic = new QLabel(frame);
        user_pic->setObjectName(QString::fromUtf8("user_pic"));
        user_pic->setMinimumSize(QSize(20, 20));
        user_pic->setMaximumSize(QSize(20, 20));
        user_pic->setFont(font);
        user_pic->setScaledContents(true);
        user_pic->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(user_pic);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        username_text = new QLabel(frame);
        username_text->setObjectName(QString::fromUtf8("username_text"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(username_text->sizePolicy().hasHeightForWidth());
        username_text->setSizePolicy(sizePolicy2);
        username_text->setMinimumSize(QSize(0, 0));
        username_text->setMaximumSize(QSize(16777215, 16777215));
        username_text->setFont(font);
        username_text->setStyleSheet(QString::fromUtf8("color: #999999;"));
        username_text->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(username_text);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(frame, 0, 0, 2, 1);

        rank_text = new QLabel(CourseAnalysisRankItemWidget);
        rank_text->setObjectName(QString::fromUtf8("rank_text"));
        sizePolicy.setHeightForWidth(rank_text->sizePolicy().hasHeightForWidth());
        rank_text->setSizePolicy(sizePolicy);
        rank_text->setMinimumSize(QSize(0, 0));
        rank_text->setMaximumSize(QSize(16777215, 16777215));
        rank_text->setFont(font);
        rank_text->setStyleSheet(QString::fromUtf8("color: #999999;"));
        rank_text->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(rank_text, 0, 3, 2, 1);


        retranslateUi(CourseAnalysisRankItemWidget);

        QMetaObject::connectSlotsByName(CourseAnalysisRankItemWidget);
    } // setupUi

    void retranslateUi(QWidget *CourseAnalysisRankItemWidget)
    {
        CourseAnalysisRankItemWidget->setWindowTitle(QCoreApplication::translate("CourseAnalysisRankItemWidget", "Form", nullptr));
        times_text->setText(QCoreApplication::translate("CourseAnalysisRankItemWidget", "times", nullptr));
        concentration_text->setText(QCoreApplication::translate("CourseAnalysisRankItemWidget", "concentration", nullptr));
        user_pic->setText(QCoreApplication::translate("CourseAnalysisRankItemWidget", "pic", nullptr));
        username_text->setText(QCoreApplication::translate("CourseAnalysisRankItemWidget", "username", nullptr));
        rank_text->setText(QCoreApplication::translate("CourseAnalysisRankItemWidget", "rank", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CourseAnalysisRankItemWidget: public Ui_CourseAnalysisRankItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_COURSEANALYSISRANKITEMWIDGET_H
