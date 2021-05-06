#include "LampWidget.h"

LampWidget::LampWidget(const Lamp& lamp, QWidget* wgt) : QWidget{ wgt }
{
	setAttribute(Qt::WA_DeleteOnClose);

	m_image = new QLabel(this);
	m_info = new QLabel(this);
	QPixmap image("S:/perfect_circle/RRProject/ElPoTrade/icons/lamp.jpg");

	m_image->setPixmap(image.scaled(m_image->size()));
	m_info->setText("Name: " + QString(lamp.name.c_str()) + "\nType: "
		+ QString(lamp.type.c_str()) + "\nPower: " + QString::number(lamp.power));
	m_lamp_id = lamp.id;

	QHBoxLayout* lay = new QHBoxLayout;
	lay->addWidget(m_image);
	lay->addWidget(m_info);
	setLayout(lay);
}