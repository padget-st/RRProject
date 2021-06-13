#pragma once
#include <QtWidgets>
#include <vector>
#include "ProductManager.h"
#include "ResourceManager.h"

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
	void show_catalog();
signals:
	void signalClosed();
	void signalItemSelected(QListWidgetItem*);
};
