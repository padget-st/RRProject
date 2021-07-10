#include "SuggestionScreen.h"

SuggestionScreen::SuggestionScreen(QWidget* wgt)
	: QWidget{wgt}, m_txt_sugg{new QTextEdit(this)},
	m_line_name{new QLineEdit(this)}, m_line_email{new QLineEdit(this)},
	m_lbl_name{new QLabel("Name, organisation:", this)}, m_lbl_email{new QLabel("E-mail:", this)},
	m_pb_send{ new QPushButton("Send", this) }, m_pb_close{ new QPushButton("Close", this) }
{
	setAttribute(Qt::WA_DeleteOnClose);

	connect(m_pb_close, SIGNAL(clicked()), SLOT(close()));
	connect(m_pb_close, SIGNAL(clicked()), SIGNAL(signalClosed()));
	connect(m_pb_send, SIGNAL(clicked()), SLOT(slotSendClicked()));

	std::unique_ptr<QHBoxLayout> horiz_lay1{ std::make_unique<QHBoxLayout>() };
	horiz_lay1->addWidget(m_lbl_name);
	horiz_lay1->addWidget(m_line_name);

	std::unique_ptr<QHBoxLayout> horiz_lay2{ std::make_unique<QHBoxLayout>() };
	horiz_lay2->addWidget(m_lbl_email);
	horiz_lay2->addWidget(m_line_email);

	QVBoxLayout* vert_lay = new QVBoxLayout(this);
	vert_lay->addWidget(m_txt_sugg);
	vert_lay->addLayout(horiz_lay1.release());
	vert_lay->addLayout(horiz_lay2.release());
	vert_lay->addWidget(m_pb_send);
	vert_lay->addWidget(m_pb_close);

	setLayout(vert_lay);
}

void SuggestionScreen::slotSendClicked()
{
	QString text{ m_txt_sugg->toPlainText() };
	QString name{ m_line_name->text() };
	QString email{ m_line_email->text() };
	if (!text.isEmpty() || !name.isEmpty() || !email.isEmpty())
	{
		Suggestion sugg;
		sugg.text = text.toStdString();
		sugg.name = name.toStdString();
		sugg.email = email.toStdString();

		ContactManager cm;
		cm.save_suggestion(sugg);

		m_txt_sugg->setPlainText("Successfully sent");
		m_line_name->setText("");
		m_line_email->setText("");
	}
}
