#pragma once
#include <QtWidgets>
#include <memory>
#include <vector>
#include "Lamp.h"
#include "ProductManager.h"
#include "ResourceManager.h"
#include "LampWidget.h"

class ProductScreen : public QWidget
{
	Q_OBJECT
private:
	QListWidget* m_list;
	QPushButton* m_pb_close;
	QPixmap get_pixIcon(std::string_view);
public:
	ProductScreen(QWidget* wgt = 0);
	~ProductScreen();
signals:
	void signalClosed();
};
