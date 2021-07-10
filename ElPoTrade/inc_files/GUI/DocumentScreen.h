#pragma once
#include <QtWidgets>
#include <vector>
#include "DocumentManager.h"
#include "ResourceManager.h"

class DocumentScreen : public QWidget
{
	Q_OBJECT
private:
	QListWidget* m_list;
	QPushButton* m_pb_close;
	void fill_in();
public:
	DocumentScreen(QWidget* wgt = 0);
signals:
	void signalClosed();
	void signalItemSelected(QListWidgetItem*);
};
