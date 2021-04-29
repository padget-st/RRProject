#pragma once
#include <QtWidgets>
#include "ProductScreen.h"

class MainScreen : public QWidget
{
	Q_OBJECT
private:
	QLabel* m_lbl_banner;
public:
	MainScreen(QWidget* wgt = 0);
signals:
	void catalogClicked();

};

