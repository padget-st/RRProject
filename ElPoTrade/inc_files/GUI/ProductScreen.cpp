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
	: QWidget{ wgt }, m_list{new QListWidget(this)},
	m_pb_close{new QPushButton("Close", this)}
{
	setAttribute(Qt::WA_DeleteOnClose);

	connect(m_pb_close, SIGNAL(clicked()), SLOT(close()));
	connect(m_pb_close, SIGNAL(clicked()), SIGNAL(signalClosed()));

	connect(m_list, SIGNAL(itemDoubleClicked(QListWidgetItem*)), 
		SIGNAL(signalItemSelected(QListWidgetItem*)));

	fill_in();

	QVBoxLayout* lay = new QVBoxLayout(this);
	lay->addWidget(m_list);
	lay->addWidget(m_pb_close);
	setLayout(lay);
}

void ProductScreen::fill_in()
{
	GroupManager pm;
	std::vector<ProductGroup> v_groups{ pm.get_all() };
	QListWidgetItem* list_item{ nullptr };

	for (auto& elem : v_groups)
	{
		list_item = new QListWidgetItem(QString(elem.group_name.c_str()), m_list);
		list_item->setIcon(get_pixIcon(elem.images_url[0]));
		list_item->setData(Qt::UserRole, elem.id);
	}
	m_list->setIconSize(QSize(size().height()/PROD_SCR_IMG_W_SCALE,
		size().width()/PROD_SCR_IMG_H_SCALE));
}