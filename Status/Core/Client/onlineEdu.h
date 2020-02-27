#pragma once

enum TransportCmd {
	TestCommand = 100,
	ConcentrationFinalData = 101,
	StudentCameraFrameData = 102,
	CreateLesson = 103,
	JoinInLesson = 104,
	BeginLesson = 105,
	PaintCommand = 106,
	CreatePaintConnection = 107,
	CreateCVServerConnection = 108,
	EndLesson = 109,
	SendChatContent = 110,
	RecvChatContent = 111,
	ChatBan = 112,
	RaiseHand = 113,
	ResultOfRaiseHand = 114,
	RemoveMemberFromInSpeech = 115,
	ConcentrationRealTimeData = 116,
	QuitLesson = 117,
	TryToJoinIn = 118
};

enum ErrorCode {
	NoError = 0,
	InSpeechError = 1,
	ApplyingError = 2,
	AccountTypeError = 3,
	AccountNotFoundError = 4,
	PasswordError = 5,
	CourseResourceTitleDuplicateError = 6,
	CourseResourceNotFoundError = 7,
	CourseNotFoundError = 8
};

enum CourseStatus {
	OffLine = 0,
	OnLine = 1,
	CantJoinIn = 2,
	Waiting = 3
};

enum ChatStatus {
	ChatFree = 0,
	ChatBaned = 1
};

enum UserStatus {
	Free = 0,
	InRoom = 1,
	InClass = 2
};

enum ApplicationStatus {
	Accepted = 0,
	Refused = 1,
	HungUp = 2
};

enum SpeechStatus {
	SpeechFree = 0,
	InSpeech = 1,
	Applying = 2
};

enum AccountType {
	Teacher = 0,
	Student = 1
};

enum Emotion {
	Angry = 0,
	Disgust = 1,
	Fear = 2,
	Happy = 3,
	Sad = 4,
	Surprise = 5,
	Neutral = 6
};