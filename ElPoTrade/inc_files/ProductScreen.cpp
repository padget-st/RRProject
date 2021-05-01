#include "ProductScreen.h"

ProductScreen::ProductScreen(QWidget* wgt)
	: QWidget{ wgt }, m_list{new QListWidget(this)}, m_pb_close{new QPushButton(this) }
{
	setAttribute(Qt::WA_DeleteOnClose);

	m_pb_close->setText("Close");
	connect(m_pb_close, SIGNAL(clicked()), SLOT(close()));
	connect(m_pb_close, SIGNAL(clicked()), SIGNAL(signalClosed()));

	ProductManager pm;
	std::shared_ptr<std::vector<Lamp>> product = pm.get_catalog("SELECT lamp_id, name, type, power FROM Lamp");


	QListWidgetItem* list_item{ nullptr };
	for (auto& elem : *product)
	{
		list_item = new QListWidgetItem("Name: " + QString(elem.name.c_str()) + "\nType: "
			+ QString(elem.type.c_str()) + "\nPower: " + QString::number(elem.power), m_list);
		list_item->setIcon(QPixmap("S:/perfect_circle/RRProject/ElPoTrade/icons/lamp.jpg"));
	}
	m_list->setIconSize(QSize(32, 32));

	QVBoxLayout* lay = new QVBoxLayout;
	lay->addWidget(m_list);
	lay->addWidget(m_pb_close);
	setLayout(lay);
}