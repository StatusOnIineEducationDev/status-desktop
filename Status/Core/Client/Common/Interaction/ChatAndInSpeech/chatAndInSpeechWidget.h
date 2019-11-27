#pragma once
#include <QWidget>
#include <QListView>
#include <QJsonObject>
#include "ui_c_chatAndInSpeechWidget.h"
#include "Core/Component/toast.h"
#include "Core/Client/onlineEdu.h"
#include "inSpeechMemberItemWidget.h"
#include "chatItemWidget.h"


class ChatAndInSpeechWidget : public QWidget {
	Q_OBJECT

enum ChatError {
	BlankContentError = 0
	};

signals:
	void lessonConnectionDataReady(QJsonObject &data);

public:
	ChatAndInSpeechWidget(QWidget *parent = nullptr);
	virtual ~ChatAndInSpeechWidget();
	const Ui::ChatAndInSpeechWidget& ui() const { return this->m_ui; };

	void addMemberToInSpeech(QMap<QString, QVariant> &info);
	void removeMemberFromInSpeech();
	void handleCommandRemoveMemberFromInSpeech(QJsonObject &data);

	void handleCommandSendChatContent(QJsonObject &data);
	void handleCommandRecvChatContent(QJsonObject &data);
	void handleCommandChatBan(QJsonObject &data);

protected:
	void addMemberToSpeechWidget(const QPixmap &user_pic, const QString &username);
	void removeMemberFromSpeechWidget(const int row);

	void addOtherContentToChatWiget(const QPixmap &user_pic, const QString &username,
		const QString &content, const int &timestamp);
	void addMyContentToChatWiget(const QPixmap &user_pic, const QString &username,
		const QString &content, const int &timestamp);

	void chatBan();
	void chatClear();
	void sendChatContent();

	void handleChatError(ChatError chat_error);

	Ui::ChatAndInSpeechWidget m_ui;

	/*
		|-info(m_in_speech_list)
			|-student_id(QString)
			|-username(QString)
	*/
	QList<QMap<QString, QVariant>> m_in_speech_list;  // 发言中信息
};