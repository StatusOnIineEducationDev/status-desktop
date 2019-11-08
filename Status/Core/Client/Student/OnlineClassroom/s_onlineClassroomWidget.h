#pragma once

#include <QtWidgets/QMainWindow>
#include <QList>
#include <QScrollArea>
#include <QColorDialog>
#include "ui_s_onlineClassroomWidget.h"
#include "ui_s_inSpeechRemovableWidget.h"
#include "Core/Component/WhiteBoard/whiteBoard.h"
#include "Core/Client/Student/s_mainWindow.h"


class SOnlineClassroomWidget : public QWidget {
	Q_OBJECT

public:
	SOnlineClassroomWidget(SMainWindow *parent = Q_NULLPTR);
	~SOnlineClassroomWidget();

	const Ui::SOnlineClassroomWidget& ui() const { return this->m_ui; };
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
	Ui::SOnlineClassroomWidget m_ui;

	WhiteBoard *m_board;  // ��ǰ���ƵĻ���
	QList<WhiteBoard*> m_board_list;  // �Ѵ����Ļ���
	int m_board_id;  // �����Ļ���id����
};


class SInSpeechRemovableWidget : public QWidget {
	Q_OBJECT

public:
	SInSpeechRemovableWidget(SOnlineClassroomWidget *parent = Q_NULLPTR);
	~SInSpeechRemovableWidget();

	const Ui::SInSpeechRemovableWidget& ui() const { return this->m_ui; };

	void handleWindowResized() { emit this->windowResized(); };

signals:
	void windowResized();

private:
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

	void updatePos();

	Ui::SInSpeechRemovableWidget m_ui;

	bool is_pressed;  // �������Ƿ���
	QPoint start_pos;  // ����������ʱ������
};
