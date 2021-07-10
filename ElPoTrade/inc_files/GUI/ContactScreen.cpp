#include "ContactScreen.h"

ContactScreen::ContactScreen(const Contact& cont, QWidget* wgt)
	: QWidget{ wgt }, m_lbl_info{ new QLabel(this) },
	m_pb_close{ new QPushButton("Close", this) }
{
	setAttribute(Qt::WA_DeleteOnClose);

	connect(m_pb_close, SIGNAL(clicked()), SLOT(close()));
	connect(m_pb_close, SIGNAL(clicked()), SIGNAL(signalClosed()));

	fill_in(cont);

	QVBoxLayout* lay = new QVBoxLayout(this);
	lay->addWidget(m_lbl_info);
	lay->addWidget(m_pb_close);
	setLayout(lay);
}

void ContactScreen::fill_in(const Contact& cont)
{
	m_lbl_info->setText(
		"Organisation's name: " + QString(cont.name.c_str()) +
		"\nAddress: " + QString(cont.address.c_str()) +
		"\nPhone numbers: " + QString(cont.phones.c_str()) +
		"\nBank account: " + QString(cont.bank_acc.c_str()) +
		"\nTIN: " + QString::number(cont.TIN) +
		"\nWebsite: " + QString(cont.site.c_str()) +
		"\nE-mail: " + QString(cont.email.c_str()));
	m_lbl_info->setWordWrap(true);
}