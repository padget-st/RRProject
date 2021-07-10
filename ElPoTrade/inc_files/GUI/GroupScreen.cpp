#include "GroupScreen.h"

GroupScreen::GroupScreen(const ProductGroup& group, QWidget* wgt)
	: QScrollArea{ wgt }, m_pb_close{new QPushButton("Close", this)},
	m_pb_left{new QPushButton("<", this)}, m_pb_right{new QPushButton(">", this)},
	m_prod_list{new QListWidget(this)}, m_doc_list{new QListWidget(this)},
	m_info_text{new QLabel(this)}, m_info_img{new QLabel(this)},
	m_img_viewer{new QLabel(this)}, v_images{get_images(group.images_url)},
	img_count{}
{
	setAttribute(Qt::WA_DeleteOnClose);

	connect(m_pb_close, SIGNAL(clicked()), SLOT(close()));
	connect(m_pb_close, SIGNAL(clicked()), SIGNAL(signalClosed()));

	connect(m_prod_list, SIGNAL(itemDoubleClicked(QListWidgetItem*)),
		SIGNAL(signalProdSelected(QListWidgetItem*)));
	connect(m_doc_list, SIGNAL(itemDoubleClicked(QListWidgetItem*)),
		SIGNAL(signalDocSelected(QListWidgetItem*)));

	connect(m_pb_left, SIGNAL(clicked()), SLOT(slotSetLeftImg()));
	connect(m_pb_right, SIGNAL(clicked()), SLOT(slotSetRightImg()));

	QSize pb_lr_size((size().width() / GROUP_SCR_LR_W_SCALE),
		size().height()/GROUP_SCR_LR_H_SCALE);
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
	vert_lay->addWidget(m_prod_list);
	vert_lay->addWidget(m_doc_list);
	vert_lay->addWidget(m_pb_close);

	QWidget* wgt_area = new QWidget(this);
	resize(size());
	wgt_area->setLayout(vert_lay);
	setWidget(wgt_area);
}

void GroupScreen::fill_in(const ProductGroup& group)
{
	m_img_viewer->setPixmap(v_images[0]);
	m_img_viewer->setAlignment(Qt::AlignCenter);
	m_info_text->setText(group.info.c_str());
	m_info_text->setAlignment(Qt::AlignCenter);
	m_info_img->setPixmap(v_images[v_images.size() - 1]);
	m_info_img->setAlignment(Qt::AlignCenter);

	ProductManager pm;
	std::vector<Lamp> v_lamps{ pm.get_grouped(group.id) };
	QListWidgetItem* list_prod{ nullptr };
	for (auto& elem : v_lamps)
	{
		list_prod = new QListWidgetItem(QString(elem.name.c_str()), m_prod_list);
		list_prod->setData(Qt::UserRole, elem.id);
	}

	DocumentManager dm;
	std::vector<ItemDocument> v_docs{ dm.get_grouped(group.id) };
	QListWidgetItem* list_doc{ nullptr };
	for (auto& elem : v_docs)
	{
		list_doc = new QListWidgetItem(QString(elem.doc_name.c_str()), m_doc_list);
		list_doc->setData(Qt::UserRole, elem.id);
	}
}

std::vector<QPixmap> GroupScreen::get_images(const std::vector<std::string>& v_images)
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
		pix = pix.scaled(QSize(size().width()/GROUP_SCR_PIX_W_SCALE,
			size().height()/GROUP_SCR_PIX_H_SCALE));
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