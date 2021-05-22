#include "LampScreen.h"

LampScreen::LampScreen(QWidget* wgt) : QWidget{ wgt }
{
	setAttribute(Qt::WA_DeleteOnClose);

	m_image = new QLabel(this);
	m_info = new QLabel(this);
	m_pb_close = new QPushButton("Close");
	connect(m_pb_close, SIGNAL(clicked()), SLOT(close()));
	connect(m_pb_close, SIGNAL(clicked()), SIGNAL(signalClosed()));

	QVBoxLayout* lay = new QVBoxLayout;
	lay->addWidget(m_image);
	lay->addWidget(m_info);
	lay->addWidget(m_pb_close);
	setLayout(lay);
}

void LampScreen::setLabelText(const QString& str)
{
	m_info->setText(str);
}

LampScreen::~LampScreen()
{
	delete layout();
}