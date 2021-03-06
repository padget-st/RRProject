#pragma once
#include <QtWidgets>
#include "Lamp.h"

class LampScreen : public QWidget
{
	Q_OBJECT
private:
	QLabel* m_image, * m_info;
	QPushButton* m_pb_close;
	void fill_in(const Lamp&);
public:
	LampScreen(const Lamp&, QWidget* wgt = 0);
signals:
	void signalClosed();
};
