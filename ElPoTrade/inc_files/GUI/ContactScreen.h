#pragma once
#include <QtWidgets>
#include "Contact.h"

class ContactScreen : public QWidget
{
	Q_OBJECT
private:
	QLabel* m_lbl_info;
	QPushButton* m_pb_close;
	void fill_in(const Contact&);
public:
	ContactScreen(const Contact&, QWidget* wgt = 0);
signals:
	void signalClosed();
};