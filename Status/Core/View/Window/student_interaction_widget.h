#pragma once

#include <QtWidgets/QMainWindow>
#include <QList>
#include <QScrollArea>
#include <QColorDialog>
#include "ui_student_interaction_widget.h"
#include "Core/View/Component/component.h"

class StudentInteractionWidget : public QWidget {
	Q_OBJECT

public:
	StudentInteractionWidget(QWidget *parent = Q_NULLPTR);
	~StudentInteractionWidget();
	const Ui::StudentInteractionWidget& ui() const { return this->m_ui; };
	PaintWidget* board() const { return this->m_board; }


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
	Ui::StudentInteractionWidget m_ui;

	PaintWidget *m_board;  // ��ǰ���ƵĻ���
	QList<PaintWidget*> m_board_list;  // �Ѵ����Ļ���
	int m_board_id;  // �����Ļ���id����
};