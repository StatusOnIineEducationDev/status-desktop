#pragma once

#include <QWidget>
#include <QScrollArea>
#include <QTabBar>
#include <QColorDialog>
#include <QThread>
#include "ui_c_whiteBoardWidget.h"
#include "Core/Network/socket.h"
#include "Core/Client/onlineEdu.h"
#include "Core/Client/conf.h"
#include "Core/Model/user.h"
#include "whiteboard.h"


class WhiteBoardWidget : public QWidget {
	Q_OBJECT

public:
	WhiteBoardWidget(QWidget *parent = nullptr);
	~WhiteBoardWidget();
	const Ui::WhiteBoardWidget& ui() const { return this->m_ui; };
	WhiteBoard* interactiveBoard() const { return this->m_interactive_board; };

	void createPaintConnection(QString &course_id, QString &lesson_id);
	void distroyPaintConnection();
	void setInteractiveWhiteBoardDisabled(bool flag);

protected:
	void setPaintConnectionSendBaseInfo(QString &course_id, QString &lesson_id);
	void sendPaintCommand(QJsonObject &data);
	void handlePaintConnectionRecv();
	void handleCommandPaintCommand(QJsonObject &data);

	void initWhiteBoardArea();
	void createInteractiveWhiteBoard();
	void toolBarSignalConnect();
	void setToolBarDisabled(bool flag);
	void setPenWidth(int value);
	void setRubberWidth(int value);
	void setPenSlider();
	void setRubberSlider();
	void chooseBlackPen();
	void chooseBluePen();
	void chooseRedPen();
	void chooseColorPen();
	void chooseText();
	void chooseRubber();
	void chooseLine();
	void chooseRect();
	void chooseEllipse();
	void undo();
	void clear();
	void showCurrentColor(QString rgb);
	void addBoard();
	void deleteBoard(int index);
	void changeBoard(int index);

	Ui::WhiteBoardWidget m_ui;
	
	Connection *m_paint_connection;  // ���ÿε�Tcp����
	QMap<QString, QVariant> m_send_base_info;

	WhiteBoard *m_board;  // ��ǰ���ƵĻ���
	WhiteBoard *m_interactive_board;  // ��������
	QList<WhiteBoard*> m_board_list;  // �Ѵ����Ļ���
	int m_board_id;  // �����Ļ���id����
};
