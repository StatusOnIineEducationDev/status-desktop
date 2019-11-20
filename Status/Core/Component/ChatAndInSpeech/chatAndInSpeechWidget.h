#pragma once
#include <QWidget>
#include <QListView>
#include "ui_c_chatAndInSpeechWidget.h"
#include "Core/Component/toast.h"
#include "inSpeechMemberItemWidget.h"
#include "chatItemWidget.h"


class ChatAndInSpeechWidget : public QWidget {
	Q_OBJECT

enum ChatError {
	BlankContentError = 0
	};

signals:
	void chatAllowed();
	void chatBanned();
	void chatSend(const QString &content);

public:
	ChatAndInSpeechWidget(QWidget *parent = nullptr);
	virtual ~ChatAndInSpeechWidget();
	const Ui::ChatAndInSpeechWidget& ui() const { return this->m_ui; };

	void addMemberToSpeechWidget(const QPixmap &user_pic, const QString &username);
	void removeMemberFromSpeechWidget(const int row);
	void addOtherContentToChatWiget(const QPixmap &user_pic, const QString &username, 
		const QString &content, const int &timestamp);
	void addMyContentToChatWiget(const QPixmap &user_pic, const QString &username,
		const QString &content, const int &timestamp);

protected:
	void chatBan();
	void chatClear();
	void sendChatContent();

	void handleChatError(ChatError chat_error);

	Ui::ChatAndInSpeechWidget m_ui;
};