#include "MainScreen.h"

MainScreen::MainScreen(QWidget* wgt) : QWidget{ wgt },
	m_lbl_banner{new QLabel("BANNER", this)}, m_pb_catalog{new QPushButton("Catalog", this)},
	m_pb_calc{new QPushButton("Calculations", this)}, m_pb_docs{new QPushButton("Documents", this)},
	m_pb_contacts{new QPushButton("Contacts", this)}, m_pb_suggest{new QPushButton("Suggestion", this)}
{
	setAttribute(Qt::WA_DeleteOnClose);

	m_lbl_banner->setFrameStyle(QFrame::Box | QFrame::Raised);
	m_lbl_banner->setAlignment(Qt::AlignCenter);

	connect(m_pb_catalog, SIGNAL(clicked()), SIGNAL(catalogClicked()));

	std::unique_ptr<QHBoxLayout> horiz_lay1 = std::make_unique<QHBoxLayout>();
	horiz_lay1->addWidget(m_pb_catalog);
	horiz_lay1->addWidget(m_pb_calc);

	std::unique_ptr<QHBoxLayout> horiz_lay2 = std::make_unique<QHBoxLayout>();
	horiz_lay2->addWidget(m_pb_docs);
	horiz_lay2->addWidget(m_pb_contacts);

	QVBoxLayout* vert_lay = new QVBoxLayout(this);
	vert_lay->addWidget(m_lbl_banner);
	vert_lay->addLayout(horiz_lay1.release());
	vert_lay->addLayout(horiz_lay2.release());
	vert_lay->addWidget(m_pb_suggest);

	setLayout(vert_lay);
}

