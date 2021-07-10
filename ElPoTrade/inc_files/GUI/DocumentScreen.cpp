#include "DocumentScreen.h"

DocumentScreen::DocumentScreen(QWidget* wgt)
	: QWidget{ wgt }, m_list{ new QListWidget(this) },
	m_pb_close{ new QPushButton("Close", this) }
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

void DocumentScreen::fill_in()
{
	DocumentManager doc_mgr;
	std::vector<ItemDocument> v_docs{ doc_mgr.get_all() };
	QListWidgetItem* list_item{ nullptr };

	for (auto& elem : v_docs)
	{
		list_item = new QListWidgetItem(QString(elem.doc_name.c_str()), m_list);
		list_item->setData(Qt::UserRole, elem.id);
	}
}