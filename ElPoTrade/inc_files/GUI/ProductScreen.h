#pragma once
#include <QtWidgets>
#include <vector>
#include "GroupManager.h"
#include "ResourceManager.h"

constexpr int PROD_SCR_IMG_W_SCALE{ 5 };
constexpr int PROD_SCR_IMG_H_SCALE{ 4 };


class ProductScreen : public QWidget
{
	Q_OBJECT
private:
	QListWidget* m_list;
	QPushButton* m_pb_close;
	QPixmap get_pixIcon(std::string_view);
	void fill_in();
public:
	ProductScreen(QWidget* wgt = 0);
signals:
	void signalClosed();
	void signalItemSelected(QListWidgetItem*);
};
