#pragma once
#include <QtWidgets>
#include "Lamp.h"

class LampWidget : public QWidget
{
	Q_OBJECT
private:
	QLabel* m_image;
	QLabel* m_info;
	int m_lamp_id;
public:
	LampWidget(const Lamp&, QWidget* wgt = 0);
};
