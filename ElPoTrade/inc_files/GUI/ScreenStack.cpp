#include "ScreenStack.h"

ScreenStack::ScreenStack() : m_mapper{ new QSignalMapper(this) }
{
	QRect screen_size = QApplication::desktop()->screenGeometry();
	setFixedSize(screen_size.width() / 5, screen_size.height() / 2);
	resize(screen_size.width() / SCR_STACK_W_SCALE, screen_size.height() / SCR_STACK_H_SCALE);

	//std::cout << size().width() << " " << size().height();

	connect(m_mapper, SIGNAL(mapped(QWidget*)), SLOT(slotDeleteWidget(QWidget*)));

	std::unique_ptr<MainScreen> ms = std::make_unique<MainScreen>();
	connect(ms.get(), SIGNAL(catalogClicked()), SLOT(slotShowCatalog()));
	connect(ms.get(), SIGNAL(documentClicked()), SLOT(slotShowDocuments()));
	connect(ms.get(), SIGNAL(contactClicked()), SLOT(slotShowContact()));
	connect(ms.get(), SIGNAL(suggestClicked()), SLOT(slotShowSuggest()));
	addWidget(ms.get());
	setCurrentWidget(ms.release());
}

void ScreenStack::slotShowCatalog()
{
	try
	{
		std::unique_ptr<ProductScreen> ps{ std::make_unique<ProductScreen>() };
		connect(ps.get(), SIGNAL(signalClosed()), m_mapper, SLOT(map()));
		connect(ps.get(), SIGNAL(signalItemSelected(QListWidgetItem*)),
			this, SLOT(slotShowGroup(QListWidgetItem*)));
		addWidget(ps.get());
		m_mapper->setMapping(ps.get(), ps.get());
		setCurrentWidget(ps.release());
	}
	catch (std::exception& e)
	{ 
		QMessageBox::warning(0, "Error", "Can't open the window.\n" + QString(e.what()), QMessageBox::Ok);
	}
}

void ScreenStack::slotShowGroup(QListWidgetItem* item)
{
	try
	{
		GroupManager pm;
		ProductGroup group{ pm.get_item(item->data(Qt::UserRole).toInt()) };

		std::unique_ptr<GroupScreen> gs{ std::make_unique<GroupScreen>(group) };
		connect(gs.get(), SIGNAL(signalClosed()), m_mapper, SLOT(map()));
		connect(gs.get(), SIGNAL(signalProdSelected(QListWidgetItem*)),
			this, SLOT(slotShowProductItem(QListWidgetItem*)));
		connect(gs.get(), SIGNAL(signalDocSelected(QListWidgetItem*)),
			this, SLOT(slotShowDownload(QListWidgetItem*)));
		addWidget(gs.get());
		m_mapper->setMapping(gs.get(), gs.get());
		setCurrentWidget(gs.release());
	}
	catch (std::exception& e)
	{
		QMessageBox::warning(0, "Error", "Can't open the window.\n" + QString(e.what()), QMessageBox::Ok);
	}
}

void ScreenStack::slotShowProductItem(QListWidgetItem* item)
{
	try
	{
		ProductManager pm;
		Lamp lamp{ pm.get_item(item->data(Qt::UserRole).toInt()) };

		std::unique_ptr<LampScreen> ls{ std::make_unique<LampScreen>(lamp) };

		connect(ls.get(), SIGNAL(signalClosed()), m_mapper, SLOT(map()));
		addWidget(ls.get());
		m_mapper->setMapping(ls.get(), ls.get());
		setCurrentWidget(ls.release());
	}
	catch (std::exception& e)
	{
		QMessageBox::warning(0, "Error", "Can't open the window.\n" + QString(e.what()), QMessageBox::Ok);
	}
}

void ScreenStack::slotShowDocuments()
{
	try
	{
		std::unique_ptr<DocumentScreen> ds{ std::make_unique<DocumentScreen>() };
		connect(ds.get(), SIGNAL(signalClosed()), m_mapper, SLOT(map()));
		connect(ds.get(), SIGNAL(signalItemSelected(QListWidgetItem*)),
			this, SLOT(slotShowDownload(QListWidgetItem*)));
		addWidget(ds.get());
		m_mapper->setMapping(ds.get(), ds.get());
		setCurrentWidget(ds.release());
	}
	catch (std::exception& e)
	{
		QMessageBox::warning(0, "Error", "Can't open the window.\n" + QString(e.what()), QMessageBox::Ok);
	}
}

void ScreenStack::slotShowDownload(QListWidgetItem* item)
{
	try
	{
		DocumentManager dm;
		ItemDocument item_doc{ dm.get_item(item->data(Qt::UserRole).toInt()) };
		
		std::unique_ptr<DownloadDocScreen> dds{ std::make_unique<DownloadDocScreen>(item_doc) };

		connect(dds.get(), SIGNAL(signalClosed()), m_mapper, SLOT(map()));
		addWidget(dds.get());
		m_mapper->setMapping(dds.get(), dds.get());
		setCurrentWidget(dds.release());
	}
	catch (std::exception& e)
	{
		QMessageBox::warning(0, "Error", "Can't open the window.\n" + QString(e.what()), QMessageBox::Ok);
	}
}

void ScreenStack::slotShowContact()
{
	try
	{
		ContactManager cm;
		Contact cont{ cm.get_contact() };

		std::unique_ptr<ContactScreen> cs{ std::make_unique<ContactScreen>(cont) };

		connect(cs.get(), SIGNAL(signalClosed()), m_mapper, SLOT(map()));
		addWidget(cs.get());
		m_mapper->setMapping(cs.get(), cs.get());
		setCurrentWidget(cs.release());
	}
	catch (std::exception& e)
	{
		QMessageBox::warning(0, "Error", "Can't open the window.\n" + QString(e.what()), QMessageBox::Ok);
	}
}

void ScreenStack::slotShowSuggest()
{
	try
	{
		std::unique_ptr<SuggestionScreen> ss{ std::make_unique<SuggestionScreen>() };

		connect(ss.get(), SIGNAL(signalClosed()), m_mapper, SLOT(map()));
		addWidget(ss.get());
		m_mapper->setMapping(ss.get(), ss.get());
		setCurrentWidget(ss.release());
	}
	catch (std::exception& e)
	{
		QMessageBox::warning(0, "Error", "Can't open the window.\n" + QString(e.what()), QMessageBox::Ok);
	}
}

void ScreenStack::slotDeleteWidget(QWidget* wgt)
{
	removeWidget(wgt);
}