#include "GroupScreen.h"

GroupScreen::GroupScreen(ProductGroup& group, QWidget* wgt)
	: QScrollArea{ wgt }, m_pb_close{new QPushButton("Close", this)},
	m_pb_left{new QPushButton("<", this)}, m_pb_right{new QPushButton(">", this)},
	m_list{new QListWidget(this)}, m_info_text{new QLabel(this)}, m_info_img{new QLabel(this)},
	m_img_viewer{new QLabel(this)}, v_images{get_images(group.images_url)},
	img_count{}
{
	setAttribute(Qt::WA_DeleteOnClose);

	connect(m_pb_close, SIGNAL(clicked()), SLOT(close()));
	connect(m_pb_close, SIGNAL(clicked()), SIGNAL(signalClosed()));

	connect(m_list, SIGNAL(itemDoubleClicked(QListWidgetItem*)),
		SIGNAL(signalItemSelected(QListWidgetItem*)));

	connect(m_pb_left, SIGNAL(clicked()), SLOT(slotSetLeftImg()));
	connect(m_pb_right, SIGNAL(clicked()), SLOT(slotSetRightImg()));

	QSize pb_lr_size(30, 30);
	m_pb_left->setMaximumSize(pb_lr_size);
	m_pb_left->setDisabled(true);
	m_pb_right->setMaximumSize(pb_lr_size);

	fill_in(group);

	std::unique_ptr<QHBoxLayout> horiz_lay = std::make_unique<QHBoxLayout>();
	horiz_lay->addWidget(m_pb_left);
	horiz_lay->addWidget(m_img_viewer);
	horiz_lay->addWidget(m_pb_right);

	QVBoxLayout* vert_lay = new QVBoxLayout(this);
	vert_lay->addLayout(horiz_lay.release());
	vert_lay->addWidget(m_info_text);
	vert_lay->addWidget(m_info_img);
	vert_lay->addWidget(m_list);
	vert_lay->addWidget(m_pb_close);

	QWidget* wgt_area = new QWidget(this);
	resize(size());
	wgt_area->setLayout(vert_lay);
	setWidget(wgt_area);
}

void GroupScreen::fill_in(ProductGroup& group)
{
	m_img_viewer->setPixmap(v_images[0]);
	m_img_viewer->setAlignment(Qt::AlignCenter);
	m_info_text->setText(group.info.c_str());
	m_info_text->setAlignment(Qt::AlignCenter);
	m_info_img->setPixmap(v_images[v_images.size() - 1]);
	m_info_img->setAlignment(Qt::AlignCenter);

	ProductManager pm;
	std::vector<Lamp> v_lamps{ pm.get_grouped_catalog(group.group_id) };
	QListWidgetItem* list_item{ nullptr };
	for (auto& elem : v_lamps)
	{
		list_item = new QListWidgetItem(QString(elem.name.c_str()), m_list);
		list_item->setData(Qt::UserRole, elem.lamp_id);
	}
}

std::vector<QPixmap> GroupScreen::get_images(std::vector<std::string>& v_images)
{
	ResourceManager rm;
	std::vector<uchar> v_icon;
	std::vector<QPixmap> v_pix;
	QPixmap pix;

	for (auto& elem : v_images)
	{
		v_icon = rm.get_icon(elem);
		if (!pix.loadFromData(v_icon.data(), v_icon.size()))
		{
			throw std::runtime_error("can't open an icon");
		}
		pix = pix.scaled(QSize(size().width()/2.35, size().height()/2));
		v_pix.push_back(pix);
	}

	return v_pix;
}

void GroupScreen::slotSetLeftImg()
{
	if (!m_pb_right->isEnabled())
	{
		m_pb_right->setDisabled(false);
	}
	if (img_count > 0)
	{
		img_count--;
		m_img_viewer->setPixmap(v_images[img_count]);
		if (img_count == 0)
		{
			m_pb_left->setDisabled(true);
		}
	}
}

void GroupScreen::slotSetRightImg()
{
	if (!m_pb_left->isEnabled())
	{
		m_pb_left->setDisabled(false);
	}
	if (img_count < (v_images.size() - 2))
	{
		img_count++;
		m_img_viewer->setPixmap(v_images[img_count]);
		if (img_count == (v_images.size() - 2))
		{
			m_pb_right->setDisabled(true);
		}
	}
}