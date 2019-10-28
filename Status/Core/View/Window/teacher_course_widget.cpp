#include <QNetworkAccessManager>
#include "teacher_course_widget.h"
#include "Core/View/Component/component.h"
#include "Core/Transport/http_request.h"

TeacherCourseWidget::TeacherCourseWidget(QWidget *parent) : QWidget(parent) {
	m_ui.setupUi(this);

	m_ui.courses_comboBox->setView(new QListView());
}
