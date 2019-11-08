/********************************************************************************
** Form generated from reading UI file 't_enterDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_T_ENTERDIALOG_H
#define UI_T_ENTERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TEnterDialog
{
public:
    QFrame *layout;
    QVBoxLayout *verticalLayout;
    QFrame *title_bar;
    QGridLayout *gridLayout_2;
    QPushButton *close_btn;
    QLabel *title_text;
    QSpacerItem *horizontalSpacer_4;
    QFrame *main_area;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QPushButton *confirm_btn;
    QTabWidget *tabWidget;
    QWidget *mine_courses_tab;
    QGridLayout *gridLayout_3;
    QTableWidget *courses_table;
    QWidget *tab;

    void setupUi(QDialog *TEnterDialog)
    {
        if (TEnterDialog->objectName().isEmpty())
            TEnterDialog->setObjectName(QString::fromUtf8("TEnterDialog"));
        TEnterDialog->resize(410, 260);
        TEnterDialog->setStyleSheet(QString::fromUtf8(""));
        layout = new QFrame(TEnterDialog);
        layout->setObjectName(QString::fromUtf8("layout"));
        layout->setGeometry(QRect(0, 0, 410, 260));
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
        close_btn = new QPushButton(title_bar);
        close_btn->setObjectName(QString::fromUtf8("close_btn"));
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


        verticalLayout->addWidget(title_bar);

        main_area = new QFrame(layout);
        main_area->setObjectName(QString::fromUtf8("main_area"));
        main_area->setStyleSheet(QString::fromUtf8("QFrame {\n"
"	border-bottom-left-radius: 4px;\n"
"	border-bottom-right-radius: 4px;\n"
"	background-color: #F3F4F8;\n"
"}\n"
"\n"
""));
        main_area->setFrameShape(QFrame::StyledPanel);
        main_area->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(main_area);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 1, 0, 1, 4);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);

        confirm_btn = new QPushButton(main_area);
        confirm_btn->setObjectName(QString::fromUtf8("confirm_btn"));
        confirm_btn->setMinimumSize(QSize(90, 30));
        confirm_btn->setMaximumSize(QSize(90, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        confirm_btn->setFont(font1);
        confirm_btn->setCursor(QCursor(Qt::PointingHandCursor));
        confirm_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 15px;\n"
"	border: 1px solid #1296db;\n"
"	color: #1296db;\n"
"	background: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E6E6E6;\n"
"}"));

        gridLayout->addWidget(confirm_btn, 2, 2, 1, 1);

        tabWidget = new QTabWidget(main_area);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        tabWidget->setFont(font1);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab {\n"
"	padding-top: 0px;\n"
"	color: #999999;\n"
"	border: none;\n"
"	height: 35px;\n"
"	width: 70px;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"	background-color: #E6E6E6;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"	color: #1296db;\n"
"}\n"
"\n"
"QTabWidget#tabWidget::pane {\n"
"	border-top: 1px solid #E8ECEC;\n"
"}\n"
"\n"
"QTabWidget#tabWidget::tab-bar {\n"
"	alignment:left;\n"
"}"));
        mine_courses_tab = new QWidget();
        mine_courses_tab->setObjectName(QString::fromUtf8("mine_courses_tab"));
        mine_courses_tab->setStyleSheet(QString::fromUtf8("/*\346\225\264\344\275\223*/\n"
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
"QScrollBar:horizontal {\n"
"    border: none;\n"
"    background-color: #F3F4F8;\n"
"    height: 10px;\n"
"}\n"
"\n"
"QScrollBar:horizontal:hover {\n"
"    border: none;\n"
"    background-color: rgb(220, 220, 220);\n"
"    height: 10px;\n"
"}\n"
"\n"
"/*--------------------\345\236\202\347\233\264---------------------*/\n"
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
"/*\344\270"
                        "\213\347\256\255\345\244\264*/\n"
"QScrollBar::add-line:vertical {\n"
"    height: 0;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"/*\344\270\212\347\256\255\345\244\264*/\n"
"QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"/*--------------------\346\260\264\345\271\263---------------------*/\n"
"\n"
"/*\346\273\232\345\212\250\346\235\241*/\n"
"QScrollBar::handle:horizontal {\n"
"	border-radius: 5px;\n"
"    background: rgb(220, 220, 220);\n"
"    min-width: 20px;\n"
"}\n"
"\n"
"/*\346\273\232\345\212\250\346\235\241\357\274\232\346\202\254\346\265\256*/\n"
"QScrollBar::handle:horizontal:hover {\n"
"	border-radius: 5px;\n"
"    background: rgb(200, 200, 200);\n"
"    min-width: 20px;\n"
"}\n"
"\n"
"/*\344\270\213\347\256\255\345\244\264*/\n"
"QScrollBar::add-line:horizontal {\n"
"    width: 0px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
""
                        "/*\344\270\212\347\256\255\345\244\264*/\n"
"QScrollBar::sub-line:horizontal {\n"
"    width: 0px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}"));
        gridLayout_3 = new QGridLayout(mine_courses_tab);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        courses_table = new QTableWidget(mine_courses_tab);
        if (courses_table->columnCount() < 2)
            courses_table->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        courses_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        courses_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        courses_table->setObjectName(QString::fromUtf8("courses_table"));
        QFont font2;
        font2.setPointSize(10);
        courses_table->setFont(font2);
        courses_table->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"	border: none;\n"
"	color: #666666;\n"
"	background-color: rgb(255, 255, 255);\n"
"	alternate-background-color: rgb(235, 235, 235);\n"
"}"));
        courses_table->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        courses_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        courses_table->setAlternatingRowColors(true);
        courses_table->setSelectionMode(QAbstractItemView::SingleSelection);
        courses_table->setSelectionBehavior(QAbstractItemView::SelectRows);
        courses_table->setShowGrid(false);
        courses_table->horizontalHeader()->setVisible(false);
        courses_table->horizontalHeader()->setDefaultSectionSize(200);
        courses_table->verticalHeader()->setVisible(false);

        gridLayout_3->addWidget(courses_table, 0, 0, 1, 1);

        tabWidget->addTab(mine_courses_tab, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 4);


        verticalLayout->addWidget(main_area);


        retranslateUi(TEnterDialog);
        QObject::connect(close_btn, SIGNAL(clicked()), TEnterDialog, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TEnterDialog);
    } // setupUi

    void retranslateUi(QDialog *TEnterDialog)
    {
        TEnterDialog->setWindowTitle(QCoreApplication::translate("TEnterDialog", "Dialog", nullptr));
#if QT_CONFIG(tooltip)
        close_btn->setToolTip(QCoreApplication::translate("TEnterDialog", "\345\205\263\351\227\255", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        close_btn->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        close_btn->setText(QString());
        title_text->setText(QCoreApplication::translate("TEnterDialog", "\345\210\233\345\273\272\350\257\276\345\256\244", nullptr));
        confirm_btn->setText(QCoreApplication::translate("TEnterDialog", "\345\210\233\345\273\272\350\257\276\345\256\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem = courses_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("TEnterDialog", "\350\257\276\347\250\213id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = courses_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("TEnterDialog", "\350\257\276\347\250\213\345\220\215", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(mine_courses_tab), QCoreApplication::translate("TEnterDialog", "\346\210\221\347\232\204\350\257\276\347\250\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("TEnterDialog", "\344\270\264\346\227\266\346\210\277\351\227\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TEnterDialog: public Ui_TEnterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_T_ENTERDIALOG_H
