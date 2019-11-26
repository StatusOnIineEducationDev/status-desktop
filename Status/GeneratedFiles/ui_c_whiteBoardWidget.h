/********************************************************************************
** Form generated from reading UI file 'c_whiteBoardWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_WHITEBOARDWIDGET_H
#define UI_C_WHITEBOARDWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WhiteBoardWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *btn_tool_bar_frame;
    QVBoxLayout *verticalLayout;
    QPushButton *add_board_btn;
    QSpacerItem *verticalSpacer_2;
    QPushButton *black_pen_btn;
    QPushButton *red_pen_btn;
    QPushButton *blue_pen_btn;
    QPushButton *color_pen_btn;
    QPushButton *text_btn;
    QPushButton *line_btn;
    QPushButton *rect_btn;
    QPushButton *ellipse_btn;
    QPushButton *clear_btn;
    QPushButton *undo_btn;
    QPushButton *rubber_btn;
    QSpacerItem *verticalSpacer;
    QTabWidget *board_tabWidget;
    QFrame *slider_tool_bar_frame;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QSlider *pen_width_slider;
    QLineEdit *pen_width_edit;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_7;
    QSlider *rubber_width_slider;
    QLineEdit *rubber_width_edit;
    QSpacerItem *horizontalSpacer;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *WhiteBoardWidget)
    {
        if (WhiteBoardWidget->objectName().isEmpty())
            WhiteBoardWidget->setObjectName(QString::fromUtf8("WhiteBoardWidget"));
        WhiteBoardWidget->resize(615, 565);
        WhiteBoardWidget->setMinimumSize(QSize(0, 0));
        gridLayout = new QGridLayout(WhiteBoardWidget);
        gridLayout->setSpacing(5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
        btn_tool_bar_frame = new QFrame(WhiteBoardWidget);
        btn_tool_bar_frame->setObjectName(QString::fromUtf8("btn_tool_bar_frame"));
        btn_tool_bar_frame->setMinimumSize(QSize(42, 0));
        btn_tool_bar_frame->setFrameShape(QFrame::StyledPanel);
        btn_tool_bar_frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(btn_tool_bar_frame);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        add_board_btn = new QPushButton(btn_tool_bar_frame);
        add_board_btn->setObjectName(QString::fromUtf8("add_board_btn"));
        add_board_btn->setCursor(QCursor(Qt::PointingHandCursor));
        add_board_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: none;\n"
"	background: none;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/button/Resources/material/button/\346\226\260\345\273\272.png"), QSize(), QIcon::Normal, QIcon::Off);
        add_board_btn->setIcon(icon);
        add_board_btn->setIconSize(QSize(20, 20));

        verticalLayout->addWidget(add_board_btn);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        black_pen_btn = new QPushButton(btn_tool_bar_frame);
        buttonGroup = new QButtonGroup(WhiteBoardWidget);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(black_pen_btn);
        black_pen_btn->setObjectName(QString::fromUtf8("black_pen_btn"));
        black_pen_btn->setMinimumSize(QSize(40, 40));
        black_pen_btn->setMaximumSize(QSize(40, 40));
        black_pen_btn->setCursor(QCursor(Qt::PointingHandCursor));
        black_pen_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid #E8ECEC;\n"
"	border-bottom: none;\n"
"	border-top-left-radius: 5px;\n"
"	border-top-right-radius: 5px;\n"
"	background-color: #FCFCFC;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E3E3E3;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #CACACA;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/button/Resources/material/button/pen#000000.png"), QSize(), QIcon::Normal, QIcon::Off);
        black_pen_btn->setIcon(icon1);
        black_pen_btn->setIconSize(QSize(20, 20));
        black_pen_btn->setCheckable(true);

        verticalLayout->addWidget(black_pen_btn);

        red_pen_btn = new QPushButton(btn_tool_bar_frame);
        buttonGroup->addButton(red_pen_btn);
        red_pen_btn->setObjectName(QString::fromUtf8("red_pen_btn"));
        red_pen_btn->setMinimumSize(QSize(40, 40));
        red_pen_btn->setMaximumSize(QSize(40, 40));
        red_pen_btn->setCursor(QCursor(Qt::PointingHandCursor));
        red_pen_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid #E8ECEC;\n"
"	border-bottom: none;\n"
"	background-color: #FCFCFC;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E3E3E3;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #CACACA;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/button/Resources/material/button/pend#d81e06.png"), QSize(), QIcon::Normal, QIcon::Off);
        red_pen_btn->setIcon(icon2);
        red_pen_btn->setIconSize(QSize(20, 20));
        red_pen_btn->setCheckable(true);

        verticalLayout->addWidget(red_pen_btn);

        blue_pen_btn = new QPushButton(btn_tool_bar_frame);
        buttonGroup->addButton(blue_pen_btn);
        blue_pen_btn->setObjectName(QString::fromUtf8("blue_pen_btn"));
        blue_pen_btn->setMinimumSize(QSize(40, 40));
        blue_pen_btn->setMaximumSize(QSize(40, 40));
        blue_pen_btn->setCursor(QCursor(Qt::PointingHandCursor));
        blue_pen_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid #E8ECEC;\n"
"	border-bottom: none;\n"
"	background-color: #FCFCFC;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E3E3E3;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #CACACA;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/button/Resources/material/button/pen#1296db.png"), QSize(), QIcon::Normal, QIcon::Off);
        blue_pen_btn->setIcon(icon3);
        blue_pen_btn->setIconSize(QSize(20, 20));
        blue_pen_btn->setCheckable(true);

        verticalLayout->addWidget(blue_pen_btn);

        color_pen_btn = new QPushButton(btn_tool_bar_frame);
        buttonGroup->addButton(color_pen_btn);
        color_pen_btn->setObjectName(QString::fromUtf8("color_pen_btn"));
        color_pen_btn->setMinimumSize(QSize(40, 40));
        color_pen_btn->setMaximumSize(QSize(40, 40));
        color_pen_btn->setCursor(QCursor(Qt::PointingHandCursor));
        color_pen_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 5px solid #E8ECEC;\n"
"	background-color: #FCFCFC;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E3E3E3;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #CACACA;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/button/Resources/material/button/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        color_pen_btn->setIcon(icon4);
        color_pen_btn->setIconSize(QSize(20, 20));
        color_pen_btn->setCheckable(true);

        verticalLayout->addWidget(color_pen_btn);

        text_btn = new QPushButton(btn_tool_bar_frame);
        buttonGroup->addButton(text_btn);
        text_btn->setObjectName(QString::fromUtf8("text_btn"));
        text_btn->setMinimumSize(QSize(40, 40));
        text_btn->setMaximumSize(QSize(40, 40));
        text_btn->setCursor(QCursor(Qt::PointingHandCursor));
        text_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid #E8ECEC;\n"
"	border-bottom: none;\n"
"	background-color: #FCFCFC;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E3E3E3;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #CACACA;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/button/Resources/material/button/text.png"), QSize(), QIcon::Normal, QIcon::Off);
        text_btn->setIcon(icon5);
        text_btn->setIconSize(QSize(20, 20));
        text_btn->setCheckable(true);

        verticalLayout->addWidget(text_btn);

        line_btn = new QPushButton(btn_tool_bar_frame);
        buttonGroup->addButton(line_btn);
        line_btn->setObjectName(QString::fromUtf8("line_btn"));
        line_btn->setMinimumSize(QSize(40, 40));
        line_btn->setMaximumSize(QSize(40, 40));
        line_btn->setCursor(QCursor(Qt::PointingHandCursor));
        line_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid #E8ECEC;\n"
"	border-bottom: none;\n"
"	background-color: #FCFCFC;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E3E3E3;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #CACACA;\n"
"}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/button/Resources/material/button/line.png"), QSize(), QIcon::Normal, QIcon::Off);
        line_btn->setIcon(icon6);
        line_btn->setIconSize(QSize(20, 20));
        line_btn->setCheckable(true);

        verticalLayout->addWidget(line_btn);

        rect_btn = new QPushButton(btn_tool_bar_frame);
        buttonGroup->addButton(rect_btn);
        rect_btn->setObjectName(QString::fromUtf8("rect_btn"));
        rect_btn->setMinimumSize(QSize(40, 40));
        rect_btn->setMaximumSize(QSize(40, 40));
        rect_btn->setCursor(QCursor(Qt::PointingHandCursor));
        rect_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid #E8ECEC;\n"
"	border-bottom: none;\n"
"	background-color: #FCFCFC;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E3E3E3;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #CACACA;\n"
"}"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/button/Resources/material/button/rect.png"), QSize(), QIcon::Normal, QIcon::Off);
        rect_btn->setIcon(icon7);
        rect_btn->setIconSize(QSize(20, 20));
        rect_btn->setCheckable(true);

        verticalLayout->addWidget(rect_btn);

        ellipse_btn = new QPushButton(btn_tool_bar_frame);
        buttonGroup->addButton(ellipse_btn);
        ellipse_btn->setObjectName(QString::fromUtf8("ellipse_btn"));
        ellipse_btn->setMinimumSize(QSize(40, 40));
        ellipse_btn->setMaximumSize(QSize(40, 40));
        ellipse_btn->setCursor(QCursor(Qt::PointingHandCursor));
        ellipse_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid #E8ECEC;\n"
"	border-bottom: none;\n"
"	background-color: #FCFCFC;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E3E3E3;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #CACACA;\n"
"}"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/button/Resources/material/button/circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        ellipse_btn->setIcon(icon8);
        ellipse_btn->setIconSize(QSize(20, 20));
        ellipse_btn->setCheckable(true);

        verticalLayout->addWidget(ellipse_btn);

        clear_btn = new QPushButton(btn_tool_bar_frame);
        clear_btn->setObjectName(QString::fromUtf8("clear_btn"));
        clear_btn->setMinimumSize(QSize(40, 40));
        clear_btn->setMaximumSize(QSize(40, 40));
        clear_btn->setCursor(QCursor(Qt::PointingHandCursor));
        clear_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid #E8ECEC;\n"
"	border-bottom: none;\n"
"	background-color: #FCFCFC;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E3E3E3;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #CACACA;\n"
"}"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/button/Resources/material/button/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clear_btn->setIcon(icon9);
        clear_btn->setIconSize(QSize(20, 20));
        clear_btn->setCheckable(false);

        verticalLayout->addWidget(clear_btn);

        undo_btn = new QPushButton(btn_tool_bar_frame);
        undo_btn->setObjectName(QString::fromUtf8("undo_btn"));
        undo_btn->setMinimumSize(QSize(40, 40));
        undo_btn->setMaximumSize(QSize(40, 40));
        undo_btn->setCursor(QCursor(Qt::PointingHandCursor));
        undo_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid #E8ECEC;\n"
"	border-bottom: none;\n"
"	background-color: #FCFCFC;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E3E3E3;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #CACACA;\n"
"}"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/button/Resources/material/button/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        undo_btn->setIcon(icon10);
        undo_btn->setIconSize(QSize(20, 20));
        undo_btn->setCheckable(false);

        verticalLayout->addWidget(undo_btn);

        rubber_btn = new QPushButton(btn_tool_bar_frame);
        buttonGroup->addButton(rubber_btn);
        rubber_btn->setObjectName(QString::fromUtf8("rubber_btn"));
        rubber_btn->setMinimumSize(QSize(40, 40));
        rubber_btn->setMaximumSize(QSize(40, 40));
        rubber_btn->setCursor(QCursor(Qt::PointingHandCursor));
        rubber_btn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 1px solid #E8ECEC;\n"
"	border-bottom-left-radius: 5px;\n"
"	border-bottom-right-radius: 5px;\n"
"	background-color: #FCFCFC;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #E3E3E3;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"	background-color: #CACACA;\n"
"}"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/button/Resources/material/button/rubber.png"), QSize(), QIcon::Normal, QIcon::Off);
        rubber_btn->setIcon(icon11);
        rubber_btn->setIconSize(QSize(20, 20));
        rubber_btn->setCheckable(true);

        verticalLayout->addWidget(rubber_btn);

        verticalSpacer = new QSpacerItem(20, 35, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addWidget(btn_tool_bar_frame, 1, 0, 1, 1);

        board_tabWidget = new QTabWidget(WhiteBoardWidget);
        board_tabWidget->setObjectName(QString::fromUtf8("board_tabWidget"));
        board_tabWidget->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        board_tabWidget->setFont(font);
        board_tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab {\n"
"	padding-top: 0px;\n"
"	color: #999999;\n"
"	border: 1px solid #E8ECEC;\n"
"	border-top-left-radius: 3px;\n"
"	border-top-right-radius: 3px;\n"
"	height: 20px;\n"
"	width: 90px;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"	color: #1296db;\n"
"	border: 1px solid #E8ECEC;\n"
"	border-bottom: none;\n"
"	border-top-left-radius: 3px;\n"
"	border-top-right-radius: 3px;\n"
"	background-color: #ffffff;\n"
"	height: 20px;\n"
"	width: 90px;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"	background-color: #E6E6E6;\n"
"}\n"
"\n"
"QTabWidget#board_tabWidget::pane {\n"
"	border: 1px solid #E8ECEC;\n"
"	border-top: none;\n"
"}\n"
"\n"
"QTabBar::close-button {\n"
"	image: url(:/button/Resources/material/button/close_mini.png);\n"
"}\n"
"QTabBar::close-button:hover {\n"
"    image: url(:/button/Resources/material/button/close_mini.png);\n"
"	border-radius: 8px;\n"
"	background-color: red;\n"
"}\n"
"\n"
"\n"
"QScrollArea {border:none;background-color:transparent;}\n"
"QScrollBar:vertical {border:none;background-colo"
                        "r:#ffffff;width:10px;}\n"
"QScrollBar:vertical:hover {border:none;background-color:rgb(220,220,220);width:10px;}\n"
"QScrollBar::handle:vertical{border-radius:5px;background:rgb(220,220,220);min-height:20px;}QScrollBar::handle:vertical:hover{border-radius:5px;background:rgb(200,200,200);min-height:20px;}QScrollBar::add-line:vertical{height:0;subcontrol-position:bottom;subcontrol-origin:margin;}QScrollBar::sub-line:vertical{height:0px;subcontrol-position:top;subcontrol-origin:margin;}QScrollBar:horizontal{border:none;background-color:#ffffff;height:10px;}QScrollBar:horizontal:hover{border:none;background-color:rgb(220,220,220);height:10px;}QScrollBar::handle:horizontal{border-radius:5px;background:rgb(220,220,220);min-width:20px;}QScrollBar::handle:horizontal:hover{border-radius:5px;background:rgb(200,200,200);min-width:20px;}QScrollBar::add-line:horizontal{width:0;subcontrol-position:bottom;subcontrol-origin:margin;}QScrollBar::sub-line:horizontal{width:0px;subcontrol-position:top;subcontrol-origin:margin;}"));
        board_tabWidget->setTabShape(QTabWidget::Rounded);
        board_tabWidget->setTabsClosable(true);

        gridLayout->addWidget(board_tabWidget, 1, 1, 1, 1);

        slider_tool_bar_frame = new QFrame(WhiteBoardWidget);
        slider_tool_bar_frame->setObjectName(QString::fromUtf8("slider_tool_bar_frame"));
        slider_tool_bar_frame->setMinimumSize(QSize(0, 25));
        slider_tool_bar_frame->setFrameShape(QFrame::StyledPanel);
        slider_tool_bar_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(slider_tool_bar_frame);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(slider_tool_bar_frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #666666;\n"
"}"));

        horizontalLayout->addWidget(label_6);

        pen_width_slider = new QSlider(slider_tool_bar_frame);
        pen_width_slider->setObjectName(QString::fromUtf8("pen_width_slider"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pen_width_slider->sizePolicy().hasHeightForWidth());
        pen_width_slider->setSizePolicy(sizePolicy1);
        pen_width_slider->setMinimumSize(QSize(30, 0));
        pen_width_slider->setMaximumSize(QSize(150, 16777215));
        pen_width_slider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: 1px solid #E8ECEC;\n"
"	border-radius: 2px;\n"
"    height: 4px; \n"
"    background: #ffffff;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    border: 1px solid #E8ECEC;\n"
"	border-radius: 2px;\n"
"    background: #ffffff;\n"
"	width: 16px;\n"
"    margin-top: -7px;\n"
"    margin-bottom: -7px;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"	border: 1px solid #E8ECEC;\n"
"	border-radius: 2px;\n"
"    height: 4px; \n"
"    background-color: #1296db;\n"
"}"));
        pen_width_slider->setMinimum(1);
        pen_width_slider->setSliderPosition(1);
        pen_width_slider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(pen_width_slider);

        pen_width_edit = new QLineEdit(slider_tool_bar_frame);
        pen_width_edit->setObjectName(QString::fromUtf8("pen_width_edit"));
        sizePolicy.setHeightForWidth(pen_width_edit->sizePolicy().hasHeightForWidth());
        pen_width_edit->setSizePolicy(sizePolicy);
        pen_width_edit->setMinimumSize(QSize(22, 0));
        pen_width_edit->setMaximumSize(QSize(20, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(9);
        pen_width_edit->setFont(font1);
        pen_width_edit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border: 1px solid #E8ECEC;\n"
"}"));

        horizontalLayout->addWidget(pen_width_edit);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        label_7 = new QLabel(slider_tool_bar_frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #666666;\n"
"}"));

        horizontalLayout->addWidget(label_7);

        rubber_width_slider = new QSlider(slider_tool_bar_frame);
        rubber_width_slider->setObjectName(QString::fromUtf8("rubber_width_slider"));
        sizePolicy1.setHeightForWidth(rubber_width_slider->sizePolicy().hasHeightForWidth());
        rubber_width_slider->setSizePolicy(sizePolicy1);
        rubber_width_slider->setMinimumSize(QSize(30, 0));
        rubber_width_slider->setMaximumSize(QSize(150, 16777215));
        rubber_width_slider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: 1px solid #E8ECEC;\n"
"	border-radius: 2px;\n"
"    height: 4px; \n"
"    background: #ffffff;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    border: 1px solid #E8ECEC;\n"
"	border-radius: 2px;\n"
"    background: #ffffff;\n"
"	width: 16px;\n"
"    margin-top: -7px;\n"
"    margin-bottom: -7px;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"	border: 1px solid #E8ECEC;\n"
"	border-radius: 2px;\n"
"    height: 4px; \n"
"    background-color: #1296db;\n"
"}"));
        rubber_width_slider->setMinimum(1);
        rubber_width_slider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(rubber_width_slider);

        rubber_width_edit = new QLineEdit(slider_tool_bar_frame);
        rubber_width_edit->setObjectName(QString::fromUtf8("rubber_width_edit"));
        sizePolicy.setHeightForWidth(rubber_width_edit->sizePolicy().hasHeightForWidth());
        rubber_width_edit->setSizePolicy(sizePolicy);
        rubber_width_edit->setMinimumSize(QSize(22, 0));
        rubber_width_edit->setMaximumSize(QSize(20, 16777215));
        rubber_width_edit->setFont(font1);
        rubber_width_edit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border: 1px solid #E8ECEC;\n"
"}"));

        horizontalLayout->addWidget(rubber_width_edit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addWidget(slider_tool_bar_frame, 0, 1, 1, 1);


        retranslateUi(WhiteBoardWidget);

        board_tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(WhiteBoardWidget);
    } // setupUi

    void retranslateUi(QWidget *WhiteBoardWidget)
    {
        WhiteBoardWidget->setWindowTitle(QCoreApplication::translate("WhiteBoardWidget", "Form", nullptr));
#if QT_CONFIG(tooltip)
        add_board_btn->setToolTip(QCoreApplication::translate("WhiteBoardWidget", "\346\226\260\345\273\272\347\224\273\346\235\277", nullptr));
#endif // QT_CONFIG(tooltip)
        add_board_btn->setText(QString());
#if QT_CONFIG(tooltip)
        black_pen_btn->setToolTip(QCoreApplication::translate("WhiteBoardWidget", "\351\273\221\347\254\224", nullptr));
#endif // QT_CONFIG(tooltip)
        black_pen_btn->setText(QString());
#if QT_CONFIG(tooltip)
        red_pen_btn->setToolTip(QCoreApplication::translate("WhiteBoardWidget", "\347\272\242\347\254\224", nullptr));
#endif // QT_CONFIG(tooltip)
        red_pen_btn->setText(QString());
#if QT_CONFIG(tooltip)
        blue_pen_btn->setToolTip(QCoreApplication::translate("WhiteBoardWidget", "\350\223\235\347\254\224", nullptr));
#endif // QT_CONFIG(tooltip)
        blue_pen_btn->setText(QString());
#if QT_CONFIG(tooltip)
        color_pen_btn->setToolTip(QCoreApplication::translate("WhiteBoardWidget", "\350\207\252\345\256\232\344\271\211\351\242\234\350\211\262", nullptr));
#endif // QT_CONFIG(tooltip)
        color_pen_btn->setText(QString());
#if QT_CONFIG(tooltip)
        text_btn->setToolTip(QCoreApplication::translate("WhiteBoardWidget", "\346\217\222\345\205\245\346\226\207\346\234\254", nullptr));
#endif // QT_CONFIG(tooltip)
        text_btn->setText(QString());
#if QT_CONFIG(tooltip)
        line_btn->setToolTip(QCoreApplication::translate("WhiteBoardWidget", "\347\233\264\347\272\277", nullptr));
#endif // QT_CONFIG(tooltip)
        line_btn->setText(QString());
#if QT_CONFIG(tooltip)
        rect_btn->setToolTip(QCoreApplication::translate("WhiteBoardWidget", "\347\237\251\345\275\242", nullptr));
#endif // QT_CONFIG(tooltip)
        rect_btn->setText(QString());
#if QT_CONFIG(tooltip)
        ellipse_btn->setToolTip(QCoreApplication::translate("WhiteBoardWidget", "\346\244\255\345\234\206", nullptr));
#endif // QT_CONFIG(tooltip)
        ellipse_btn->setText(QString());
#if QT_CONFIG(tooltip)
        clear_btn->setToolTip(QCoreApplication::translate("WhiteBoardWidget", "\346\270\205\347\251\272\347\224\273\346\235\277", nullptr));
#endif // QT_CONFIG(tooltip)
        clear_btn->setText(QString());
#if QT_CONFIG(tooltip)
        undo_btn->setToolTip(QCoreApplication::translate("WhiteBoardWidget", "\346\222\244\351\224\200", nullptr));
#endif // QT_CONFIG(tooltip)
        undo_btn->setText(QString());
#if QT_CONFIG(tooltip)
        rubber_btn->setToolTip(QCoreApplication::translate("WhiteBoardWidget", "\346\251\241\347\232\256\346\252\253", nullptr));
#endif // QT_CONFIG(tooltip)
        rubber_btn->setText(QString());
        label_6->setText(QCoreApplication::translate("WhiteBoardWidget", "\347\224\273\347\254\224\347\262\227\347\273\206", nullptr));
        pen_width_edit->setText(QString());
        label_7->setText(QCoreApplication::translate("WhiteBoardWidget", "\346\251\241\347\232\256\346\252\253\347\262\227\347\273\206", nullptr));
        rubber_width_edit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WhiteBoardWidget: public Ui_WhiteBoardWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_WHITEBOARDWIDGET_H
