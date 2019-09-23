#pragma once

#include <QtWidgets/QMainWindow>
#include <QList>
#include <QScrollArea>
#include <QColorDialog>
#include "ui_teacher_interaction_widget.h"
#include "Core/View/Component/component.h"

class TeacherInteractionWidget : public QWidget {
	Q_OBJECT

public:
	TeacherInteractionWidget(QWidget *parent = Q_NULLPTR);
	~TeacherInteractionWidget();

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
	Ui::TeacherInteractionWidget ui;

	PaintWidget *board;  // ��ǰ���ƵĻ���
	QList<PaintWidget*> board_list;  // �Ѵ����Ļ���
	int board_id;  // �����Ļ���id����
};
