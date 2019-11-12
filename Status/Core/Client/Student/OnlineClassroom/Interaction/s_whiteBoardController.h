#pragma once
#pragma execution_character_set("utf-8")
#include <QThread>
#include <QList>
#include <QScrollArea>
#include <QColorDialog>
#include "Core/Client/Student/OnlineClassroom/s_onlineclassroomWidget.h"
#include "Core/Network/socket.h"
#include "Core/Client/onlineEdu.h"
#include "Core/Client/conf.h"
#include "Core/Component/WhiteBoard/whiteBoard.h"


class SWhiteBoardController : public QObject {
	Q_OBJECT

public:
	SWhiteBoardController(SOnlineClassroomWidget *online_classroom_widget, QObject *parent = nullptr);
	virtual ~SWhiteBoardController();

	void createPaintConnection(QString course_id, QString lesson_id, QString uid);
	void distroyPaintConnection();
	void setInteractiveWhiteBoardDisabled(bool flag);

protected:
	void handlePaintConnectionRecv();
	void handleCommandPaintCommand(QJsonObject &data);
	void sendPaintCommand(QJsonObject &data);

	void setPaintConnectionSendBaseInfo(QString course_id, QString lesson_id, QString uid);
	
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

	WhiteBoard *m_board;  // ��ǰ���ƵĻ���
	QList<WhiteBoard*> m_board_list;  // �Ѵ����Ļ���
	int m_board_id;  // �����Ļ���id����

	SOnlineClassroomWidget *m_online_classroom_widget;
	Connection *m_paint_connection;  // �����Tcp����
	QMap<QString, QVariant> m_send_base_info;
};