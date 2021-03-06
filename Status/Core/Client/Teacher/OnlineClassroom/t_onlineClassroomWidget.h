#pragma once

#include <QWidget>
#include "t_onlineClassroomFunctionButtonWidget.h"
#include "../../Common/OnlineClassroom/onlineClassroomWidget.h"
#include "Interaction/t_interactionWidget.h"
#include "Enter/t_enterDialog.h"
#include "HandleRaiseHand/t_handleRaiseHandWidget.h"


class TeacherOnlineClassroomWidget : public OnlineClassroomWidget {
	Q_OBJECT

public:
	TeacherOnlineClassroomWidget(QWidget *parent = nullptr);
	~TeacherOnlineClassroomWidget();
	TeacherOnlineClassroomFunctionButtonWidget* functionButtonWidget()
	{ return this->m_function_button_widget; };
	TeacherHandleRaiseHandWidget* handleRaiseHnadWidget()
	{ return this->m_handle_raise_hand_widget; };
	TeacherEnterDialog* enterDialog()
	{ return this->m_enter_dialog; };
	TeacherInteractionWidget* interactionWidget()
	{ return this->m_interaction_widget; };

protected:
	void init();

	void loadEnterDialog();
	void loadFunctionButtonWidget();
	void loadFunctionPageWidget();
	void loadInteractionPageWidget();
	void loadHandleRaiseHandWidget();

	void handleLessonConnectionRecv() override;

	void handleCommandCreateLesson(QJsonObject &data);
	void handleCommandBeginLesson(QJsonObject &data);
	void handleCommandEndLesson(QJsonObject &data);
	//void handleCommandConcentrationFinalData(QJsonObject &data);

	void createLesson(QString &course_id, QString &course_name);
	void beginLesson();
	void endLesson();

	void showHandleRaiseHandWidget();

	TeacherOnlineClassroomFunctionButtonWidget *m_function_button_widget;
	TeacherHandleRaiseHandWidget *m_handle_raise_hand_widget;
	TeacherEnterDialog *m_enter_dialog;
	TeacherInteractionWidget *m_interaction_widget;
};
