#pragma once

#include <QWidget>
#include "s_onlineClassroomFunctionButtonWidget.h"
#include "s_inSpeechRemovableWidget.h"
#include "../../Common/OnlineClassroom/onlineClassroomWidget.h"
#include "Interaction/s_interactionWidget.h"
#include "Enter/s_enterDialog.h"


class StudentOnlineClassroomWidget : public OnlineClassroomWidget {
	Q_OBJECT

public:
	StudentOnlineClassroomWidget(QWidget *parent = nullptr);
	~StudentOnlineClassroomWidget();
	StudentOnlineClassroomFunctionButtonWidget* functionButtonWidget() 
	{ return this->m_function_button_widget; };
	StudentInSpeechRemovableWidget* inSpeechRemovableWidget()
	{ return this->m_in_speech_removeable_widget; };
	StudentEnterDialog* enterDialog()
	{ return this->m_enter_dialog; };
	StudentInteractionWidget* interactionWidget()
	{ return this->m_interaction_widget; };

protected:
	void init();

	void loadEnterDialog();
	void loadFunctionButtonWidget();
	void loadFunctionPageWidget();
	void loadInteractionPageWidget();
	void loadInSpeechRemovableWidget();

	void handleLessonConnectionRecv() override;

	void handleCommandJoinInLesson(QJsonObject &data);
	void handleCommandBeginLesson(QJsonObject &data);
	void handleCommandConcentrationData(QJsonObject &data);
	void handleCommandEndLesson(QJsonObject &data);
	void handleCommandQuitLesson(QJsonObject &data);
	void handleCommandRaiseHand(QJsonObject &data);
	void handleCommandResultOfRaiseHand(QJsonObject &data);
	void handleCommandRemoveMemberFromInSpeech(QJsonObject &data);
	void handleCommandConcentrationFinalData(QJsonObject &data);

	void joinInLesson(QString &course_id, QString &course_name);
	void lessonBegin();
	void quitLesson();

	void raiseHand();
	void showInSpeechRemovableWidget();
	void endSpeech();

	StudentOnlineClassroomFunctionButtonWidget *m_function_button_widget;

	StudentInSpeechRemovableWidget *m_in_speech_removeable_widget;
	StudentEnterDialog *m_enter_dialog;
	StudentInteractionWidget *m_interaction_widget;
};

