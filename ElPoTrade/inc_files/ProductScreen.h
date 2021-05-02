#pragma once
#include <QtWidgets>
#include <memory>
#include <vector>
#include "Lamp.h"
#include "ProductManager.h"
#include "LampWidget.h"

class ProductScreen : public QWidget
{
	Q_OBJECT
private:
	QListWidget* m_list;
	QPushButton* m_pb_close;
public:
	ProductScreen(QWidget* wgt = 0);
	~ProductScreen();
signals:
	void signalClosed();
};
