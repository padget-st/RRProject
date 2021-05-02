#include "MainScreen.h"

MainScreen::MainScreen(QWidget* wgt) : QWidget{ wgt }
{
	setAttribute(Qt::WA_DeleteOnClose);

	QRect screen_size = QApplication::desktop()->screenGeometry();
	setMinimumSize(screen_size.width() / 5, screen_size.height() / 2);
	resize(screen_size.width() / 5, screen_size.height() / 2);

	m_lbl_banner = new QLabel("BANNER");
	m_lbl_banner->setFrameStyle(QFrame::Box | QFrame::Raised);
	m_lbl_banner->setAlignment(Qt::AlignCenter);

	QPushButton* m_pb_catalog = new QPushButton("Catalog");
	connect(m_pb_catalog, SIGNAL(clicked()), SIGNAL(catalogClicked()));

	QPushButton* m_pb_calc = new QPushButton("Calculations");
	QPushButton* m_pb_docs = new QPushButton("Documents");
	QPushButton* m_pb_contacts = new QPushButton("Contacts");
	QPushButton* m_pb_suggest = new QPushButton("Suggestion");
	
	QHBoxLayout* horiz_lay1 = new QHBoxLayout;
	horiz_lay1->addWidget(m_pb_catalog);
	horiz_lay1->addWidget(m_pb_calc);

	QHBoxLayout* horiz_lay2 = new QHBoxLayout;
	horiz_lay2->addWidget(m_pb_docs);
	horiz_lay2->addWidget(m_pb_contacts);

	QVBoxLayout* vert_lay = new QVBoxLayout;
	vert_lay->addWidget(m_lbl_banner);
	vert_lay->addLayout(horiz_lay1);
	vert_lay->addLayout(horiz_lay2);
	vert_lay->addWidget(m_pb_suggest);

	setLayout(vert_lay);
}

MainScreen::~MainScreen()
{
	delete layout();
}

