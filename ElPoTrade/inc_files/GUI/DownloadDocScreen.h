#pragma once
#include <QtWidgets>
#include <memory>
#include <fstream>
#include "ItemDocument.h"
#include "ResourceManager.h"

class DownloadDocScreen : public QWidget
{
	Q_OBJECT
private:
	QLabel *m_lbl_info, * m_lbl_status;
	QLineEdit* m_line_path;
	QPushButton* m_pb_path, *m_pb_close, *m_pb_download;
	ItemDocument m_doc;
public:
	DownloadDocScreen(const ItemDocument&, QWidget* wgt = 0);
signals:
	void signalClosed();
public slots:
	void slotBrowsePath();
	void slotDownloadDoc();
};
