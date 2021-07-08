#pragma once
#include <QtWidgets>
#include <memory>
#include "ProductScreen.h"

class MainScreen : public QWidget
{
	Q_OBJECT
private:
	QLabel* m_lbl_banner;
	QPushButton* m_pb_catalog, * m_pb_calc, * m_pb_docs, * m_pb_contacts, * m_pb_suggest;
public:
	MainScreen(QWidget* wgt = 0);
signals:
	void catalogClicked();

};

