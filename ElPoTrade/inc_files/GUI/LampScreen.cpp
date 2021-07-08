#include "LampScreen.h"

LampScreen::LampScreen(Lamp& lamp, QWidget* wgt)
	: QWidget{ wgt }, m_image{ new QLabel(this) },
	m_info{ new QLabel(this) }, m_pb_close{new QPushButton("Close", this)}
{
	setAttribute(Qt::WA_DeleteOnClose);

	connect(m_pb_close, SIGNAL(clicked()), SLOT(close()));
	connect(m_pb_close, SIGNAL(clicked()), SIGNAL(signalClosed()));

	fill_in(lamp);

	QVBoxLayout* lay = new QVBoxLayout(this);
	lay->addWidget(m_image);
	lay->addWidget(m_info);
	lay->addWidget(m_pb_close);
	setLayout(lay);
}

void LampScreen::fill_in(Lamp& lamp)
{
	m_image->setText("LAMP IMAGE???");
	m_image->setAlignment(Qt::AlignCenter);

	m_info->setText(
		"Name: " + QString(lamp.name.c_str()) +
		"\nDimensions: " + QString(lamp.dimensions.c_str()) + " mm" +
		"\nRadiant type: " + QString(lamp.radiant_type.c_str()) +
		"\nLightflow: " + QString::number(lamp.lightflow) + " Lm" +
		"\nPower: " + QString::number(lamp.power) + " W" +
		"\nLight efficiency: " + QString::number(lamp.light_efficiency) + " Lm/W" +
		"\nColor temperature: " + QString::number(lamp.color_temperature_low) + "-" + QString::number(lamp.color_temperature_high) + " K" +
		"\nDiffuser material: " + QString(lamp.diffuser_material.c_str()) +
		"\nDiffusing angle: " + QString::number(lamp.diffusing_angle) +
		"\nLIC type: " + QString(lamp.LIC_type.c_str()) +
		"\nProtect degree: " + QString(lamp.protect_degree.c_str()) +
		"\nClimatic type: " + QString(lamp.climatic_type.c_str()) +
		"\nEmergency power unit: " + QString(lamp.emergency_power_unit.c_str()) +
		"\nHousing color: " + QString(lamp.housing_color.c_str()) +
		"\nHousing material: " + QString(lamp.housing_material.c_str()) +
		"\nWork environment temperature: " + QString::number(lamp.work_temperature_low) + " - " + QString::number(lamp.work_temperature_high) + " C" +
		"\nPower ratio: " + QString::number(lamp.power_ratio) +
		"\nPulse ratio: " + QString::number(lamp.pulse_ratio) +
		"\nVoltage: " + QString::number(lamp.voltage_low) + "-" + QString::number(lamp.voltage_high) + " V AC" +
		"\nProtect class: " + QString(lamp.protect_class.c_str()) +
		"\nService life: " + QString::number(lamp.service_life) + " h" +
		"\nWeight: " + QString::number(lamp.weight) + " kg");
	m_info->setAlignment(Qt::AlignCenter);
}