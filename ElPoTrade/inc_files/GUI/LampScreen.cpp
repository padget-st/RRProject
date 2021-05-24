#include "LampScreen.h"

LampScreen::LampScreen(QWidget* wgt)
	: m_image{ new QLabel(this) }, m_info{ new QLabel(this) }, QWidget{ wgt }
{
	setAttribute(Qt::WA_DeleteOnClose);

	m_pb_close = new QPushButton("Close");
	connect(m_pb_close, SIGNAL(clicked()), SLOT(close()));
	connect(m_pb_close, SIGNAL(clicked()), SIGNAL(signalClosed()));

	QVBoxLayout* lay = new QVBoxLayout;
	lay->addWidget(m_image);
	lay->addWidget(m_info);
	lay->addWidget(m_pb_close);
	setLayout(lay);
}

void LampScreen::setLabelImage(const QPixmap& pix)
{
	m_image->setPixmap(pix.scaled(QSize(350, 350)));
	m_image->setAlignment(Qt::AlignCenter);
}

void LampScreen::setLabelText(const QString& str)
{
	m_info->setText(str);
	m_info->setAlignment(Qt::AlignCenter);
}

LampScreen::~LampScreen()
{
	delete layout();
}