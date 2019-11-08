#include "lineEdit.h"

LineEdit::LineEdit(QLineEdit *parent) {
	this->is_pressed = false;
	QFont font = this->font();

	font.setFamily("΢���ź�");
	font.setPointSize(12);
	this->setFont(font);
	this->resize(100, 25);
	this->setStyleSheet("border: 2px dashed  #000000;");

	// �źŰ�
	this->connect(this, &QLineEdit::textChanged, this, &LineEdit::adjustTextLengthAndSize);
}

void LineEdit::adjustTextLengthAndSize() {

	QFont font = this->font();  // ��ȡ�ı�������
	QString text = this->text();  // ��ȡ�ı����ı�����
	QFontMetrics fm(font);  // ��������ĸ߶ȺͿ�ȣ�px��
	QRect rect = fm.boundingRect(text);

	this->resize(rect.width() + 10, rect.height() + 10);

	return;
}

void LineEdit::mouseDoubleClickEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton) {
		this->setCursor(Qt::SizeAllCursor);  // ���������ʽ
		this->is_pressed = true;
		this->start_pos = QPoint(event->pos().x(), event->pos().y());
	}

	return;
}

void LineEdit::mouseMoveEvent(QMouseEvent *event) {
	// ������굱ǰλ��
	// ������������£���ִ���ƶ�
	if (this->is_pressed) {
		this->move(this->pos() + event->pos() - this->start_pos);
	}

	return;
}

void LineEdit::mouseReleaseEvent(QMouseEvent *event) {
	this->setCursor(Qt::ArrowCursor);  // �ָ������ʽ
	this->is_pressed = false;

	return;
}