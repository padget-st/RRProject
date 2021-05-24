#include "ProductScreen.h"

QPixmap ProductScreen::get_pixIcon(std::string_view iconName)
{
	ResourceManager rm;
	std::vector<uchar> v_icon{ rm.get_icon(iconName) };

	QPixmap pix;
	if (!pix.loadFromData(v_icon.data(), v_icon.size()))
	{
		throw std::runtime_error("can't open an icon");
	}

	return std::move(pix);
}

ProductScreen::ProductScreen(QWidget* wgt)
	: QWidget{ wgt }, m_list{new QListWidget}, m_pb_close{new QPushButton }
{
	setAttribute(Qt::WA_DeleteOnClose);

	m_pb_close->setText("Close");
	connect(m_pb_close, SIGNAL(clicked()), SLOT(close()));
	connect(m_pb_close, SIGNAL(clicked()), SIGNAL(signalClosed()));

	connect(m_list, SIGNAL(itemDoubleClicked(QListWidgetItem*)), 
		SIGNAL(signalItemSelected(QListWidgetItem*)));

	QVBoxLayout* lay = new QVBoxLayout;
	lay->addWidget(m_list);
	lay->addWidget(m_pb_close);
	setLayout(lay);
}

void ProductScreen::show_catalog()
{
	ProductManager pm;
	std::vector<std::pair<Lamp, int>> product{ pm.get_catalog() };

	QListWidgetItem* list_item{ nullptr };
	/*temporary*///QPixmap pix_icon{ get_pixIcon("lamp.jpg") };
	for (auto& elem : product)
	{
		list_item = new QListWidgetItem("Name: " + QString(elem.first.name.c_str()) + "\nType: "
			+ QString(elem.first.type.c_str()) + "\nPower: " + QString::number(elem.first.power), m_list);
		list_item->setIcon(get_pixIcon(elem.first.images_url[0]));//(get_pixIcon("lamp.jpg"));
		list_item->setData(Qt::UserRole, elem.second);
	}
	m_list->setIconSize(QSize(32, 32));
}

ProductScreen::~ProductScreen()
{
	delete layout();
}