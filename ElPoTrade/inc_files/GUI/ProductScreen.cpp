#include "ProductScreen.h"

QPixmap ProductScreen::get_pixIcon(std::string_view iconName)
{
	ResourceManager rm;
	//std::vector<uchar> v_temp{ rm.get_icon(iconName) };
	std::pair<unsigned char*, int> temp_pair{ rm.get_icon(iconName) };

	QPixmap pix;
	if (!pix.loadFromData(temp_pair.first, temp_pair.second))
	{
		throw std::runtime_error("can't open an icon");
	}

	delete[] temp_pair.first;
	return std::move(pix);
}

ProductScreen::ProductScreen(QWidget* wgt)
	: QWidget{ wgt }, m_list{new QListWidget}, m_pb_close{new QPushButton }
{
	setAttribute(Qt::WA_DeleteOnClose);

	m_pb_close->setText("Close");
	connect(m_pb_close, SIGNAL(clicked()), SLOT(close()));
	connect(m_pb_close, SIGNAL(clicked()), SIGNAL(signalClosed()));

	ProductManager pm;
	std::shared_ptr<std::vector<Lamp>> product{ pm.get_catalog()};

	QListWidgetItem* list_item{ nullptr };
	for (auto& elem : *product)
	{
		list_item = new QListWidgetItem("Name: " + QString(elem.name.c_str()) + "\nType: "
			+ QString(elem.type.c_str()) + "\nPower: " + QString::number(elem.power), m_list);
		list_item->setIcon(get_pixIcon("lamp.jpg"));
	}
	m_list->setIconSize(QSize(32, 32));

	QVBoxLayout* lay = new QVBoxLayout;
	lay->addWidget(m_list);
	lay->addWidget(m_pb_close);
	setLayout(lay);
}

ProductScreen::~ProductScreen()
{
	delete layout();
}