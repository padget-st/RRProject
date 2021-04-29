#include "ProductScreen.h"

ProductScreen::ProductScreen(QWidget* wgt)
	: QWidget{ wgt }, m_list{new QListWidget}, m_pb_close{new QPushButton}
{
	m_pb_close->setText("Close");
	connect(m_pb_close, SIGNAL(clicked()), SLOT(close()));
	connect(m_pb_close, SIGNAL(clicked()), SIGNAL(signalClosed()));

	ProductManager pm;
	std::shared_ptr<std::vector<Lamp>> product = pm.get_catalog("SELECT lamp_id, name, type, power FROM Lamp");

	QListWidgetItem* list_item{ nullptr };
	for (auto& elem : *product)
	{
		list_item = new QListWidgetItem(elem.name.c_str(), m_list);
		list_item->setIcon(QPixmap("S:/perfect_circle/RRProject/ElPoTrade/icons/lamp.jpg"));
	}

	QVBoxLayout* lay = new QVBoxLayout;
	lay->addWidget(m_list);
	lay->addWidget(m_pb_close);
	setLayout(lay);
}