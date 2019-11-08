#pragma once

#include <QtWidgets/QMainWindow>
#include <QList>
#include <QScrollArea>
#include <QColorDialog>
#include "ui_t_onlineClassroomWidget.h"
#include "ui_t_handleRaiseHandWidget.h"
#include "Core/Component/WhiteBoard/whiteBoard.h"
#include "Core/Client/Teacher/t_mainWindow.h"


class TOnlineClassroomWidget : public QWidget {
	Q_OBJECT

public:
	TOnlineClassroomWidget(TMainWindow *parent = Q_NULLPTR);
	~TOnlineClassroomWidget();
	
	const Ui::TOnlineClassroomWidget& ui() const { return this->m_ui; };
	WhiteBoard* board() const { return this->m_board; }

	void handleWindowResized() { emit this->windowResized(); };

signals:
	void windowResized();

public slots:
	/*�����������������ʴ�ϸ*/
	void setPenWidth(int value);
	/*����������������Ƥ�ߴ�ϸ*/
	void setRubberWidth(int value);
	/*������������������Slider*/
	void setPenSlider();
	/*����������������Ƥ��Slider*/
	void setRubberSlider();
	/*����������ѡ��ڱ�*/
	void chooseBlackPen();
	/*����������ѡ������*/
	void chooseBluePen();
	/*����������ѡ����*/
	void chooseRedPen();
	/*�����������Զ��廭����ɫ*/
	void chooseColorPen();
	/*����������ѡ������ı�*/
	void chooseText();
	/*����������ѡ����Ƥ��*/
	void chooseRubber();
	/*����������ѡ��ֱ�߹���*/
	void chooseLine();
	/*����������ѡ����ι���*/
	void chooseRect();
	/*����������ѡ����Բ����*/
	void chooseEllipse();
	/*��������������*/
	void undo();
	/*�������������*/
	void clear();
	/*�ڹ���������ɫ����ť�߿���ʾ��ǰ��ɫ*/
	void showCurrentColor(QString rgb);
	/*�½�����*/
	void addBoard();
	/*ɾ������*/
	void deleteBoard(int index);
	/*�л�����*/
	void changeBoard(int index);

private:
	Ui::TOnlineClassroomWidget m_ui;

	WhiteBoard *m_board;  // ��ǰ���ƵĻ���
	QList<WhiteBoard*> m_board_list;  // �Ѵ����Ļ���
	int m_board_id;  // �����Ļ���id����
};


class THandleRaiseHandWidget : public QWidget {
	Q_OBJECT

public:
	THandleRaiseHandWidget(TOnlineClassroomWidget *parent = Q_NULLPTR);
	~THandleRaiseHandWidget();
	const Ui::THandleRaiseHandWidget& ui() const { return this->m_ui; };

	void updataPos();

private:
	Ui::THandleRaiseHandWidget m_ui;
	TOnlineClassroomWidget *m_parent;
};
