#pragma once
#include <QtWidgets>
#include <memory>
#include "ResourceManager.h"

constexpr int MAIN_SCR_BANNER_H_SCALE{ 5 };
constexpr int MAIN_SCR_PB_H_SCALE{ 7 };

class MainScreen : public QWidget
{
	Q_OBJECT
private:
	QLabel* m_lbl_banner;
	QPushButton* m_pb_catalog, * m_pb_calc, * m_pb_docs, * m_pb_contacts, * m_pb_suggest;
public:
	MainScreen(QWidget* wgt = 0);
	void fill_in();
signals:
	void catalogClicked();
	void documentClicked();
	void contactClicked();
	void suggestClicked();
};

