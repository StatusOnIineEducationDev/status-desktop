#include "Core/Model/user.h"

QString User::G_UID = "";
QString User::G_USERNAME = "";
QList<CourseBase> *User::G_COURSES_BASE_LIST = nullptr;
AccountType User::G_ACCOUNT_TYPE = AccountType::Teacher;
UserStatus User::G_USER_STATUS = UserStatus::Free;
