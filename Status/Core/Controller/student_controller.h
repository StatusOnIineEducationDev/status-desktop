#pragma once

#include <QUdpSocket>
#include "Core/View/Window/student_main_window.h"
#include "Core/View/Window/student_interaction_widget.h"
#include "Core/View/Window/student_interaction_enter_dialog.h"
#include "Core/View/Component/camera.h"
#include "Core/View/Component/chart.h"
#include "Core/Transport/socket.h"
#include "Core/Model/user.h"


class StudentInteractionWidgetController : public QObject {
	Q_OBJECT

public:
	StudentInteractionWidgetController(StudentMainWindow *win, User *user);
	virtual ~StudentInteractionWidgetController();

public slots:
	void openCamera();
	void mineCameraDisplay(QImage &frame);
	void startSendCameraFrame();
	void sendMineCameraFrame();
	void handleLessonConnectionRecv();
	void handlePaintConnectionRecv();
	// ������ȡ���пγ�״̬
	void getCoursesListStatusRequest();
	void getCoursesListStatusSuccess(const QJsonObject &data);
	//void getCoursesListStatusFail();
	// ��������������
	void joinInLesson();

protected:
	// �������γ�ʼ��
	void enterDialogInit();
	void interactionWidgetInit();

	void handleCommandJoinInLesson(QJsonObject &data);
	void handleCommandBeginLesson(QJsonObject &data);
	void handleCommandConcentrationData(QJsonObject &data);
	void handleCommandPaintCommand(QJsonObject &data);
	void updateRoomBaseInfo(const QJsonObject &data);
	void createLessonConnection();
	void createPaintConnection();

	StudentMainWindow *m_win;  // ����
	User *m_user;
	StudentInteractionWidget *m_student_interaction_widget;
	StudentInteractionEnterDialog *m_student_interaction_enter_dialog;

	// �����������
	Camera *m_camera;  // ����ͷ����
	Connection *m_lesson_connection;  // ���ÿε�Tcp����
	Connection *m_paint_connection;  // �����Tcp����
	AreaChartDynamic *m_concentration_area_chart;  // רע�����ͼ
	AreaChartDynamicMin *m_concentration_area_chart_min;  // רע�����ͼ�����ԣ�
	QList<Concentration> m_concentration_list;  // רע������
	Room m_room;  // ��ǰ�ķ�����Ϣ
};


class StudentController : public QObject {
	Q_OBJECT

public:
	StudentController(StudentMainWindow *win, User* user);
	virtual ~StudentController();

public slots:
	/*�л�����ʵʱ�������Ӵ�*/
	void showStudentInteractionWidget();

protected:
	StudentMainWindow *m_win;
	User *m_user;
	StudentInteractionWidgetController *m_student_interaction_widget_controller;

	/*�л�����ʱ���ã������ǰ���Ӵ�*/
	void clearWidget();
};