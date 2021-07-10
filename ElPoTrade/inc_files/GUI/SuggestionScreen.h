#pragma once
#include <QtWidgets>
#include <memory>
#include "ContactManager.h"
#include "Suggestion.h"

class SuggestionScreen : public QWidget
{
	Q_OBJECT
private:
	QTextEdit* m_txt_sugg;
	QLineEdit* m_line_name, * m_line_email;
	QLabel* m_lbl_name, * m_lbl_email;
	QPushButton* m_pb_send, * m_pb_close;
public:
	SuggestionScreen(QWidget* wgt = 0);
signals:
	void signalClosed();
public slots:
	void slotSendClicked();
};
