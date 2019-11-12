#pragma once
#pragma execution_character_set("utf-8")
#include <QThread>
#include <QList>
#include <QScrollArea>
#include <QColorDialog>
#include "Core/Client/Teacher/OnlineClassroom/t_onlineClassroomWidget.h"
#include "Core/Component/WhiteBoard/whiteBoard.h"
#include "Core/Network/socket.h"
#include "Core/Client/onlineEdu.h"
#include "Core/Client/conf.h"


class TWhiteBoardController : public QObject {
	Q_OBJECT

public:
	TWhiteBoardController(TOnlineClassroomWidget *online_classroom_widget, QObject *parent = nullptr);
	virtual ~TWhiteBoardController();

	void createPaintConnection(QString course_id, QString lesson_id, QString uid);
	void distroyPaintConnection();

protected:
	void handlePaintConnectionRecv();
	void handleCommandPaintCommand(QJsonObject &data);
	void sendPaintCommand(QJsonObject &data);

	void setPaintConnectionSendBaseInfo(QString course_id, QString lesson_id, QString uid);
	
	void initWhiteBoard();
	void toolBarSignalConnect();
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

	TOnlineClassroomWidget *m_online_classroom_widget;
	Connection *m_paint_connection;  // �����Tcp����
	QMap<QString, QVariant> m_send_base_info;
};