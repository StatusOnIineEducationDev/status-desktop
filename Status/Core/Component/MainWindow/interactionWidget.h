#pragma once

#include <QWidget>
#include <QScrollArea>
#include <QTabBar>
#include <QColorDialog>
#include "ui_c_interactionWidget.h"
#include "../Interaction/WhiteBoard/whiteBoardWidget.h"


class InteractionWidget : public QWidget {
	Q_OBJECT

public:
	InteractionWidget(QWidget *parent = nullptr);
	~InteractionWidget();
	const Ui::InteractionWidget& ui() const { return this->m_ui; };

protected:
	Ui::InteractionWidget m_ui;
};
