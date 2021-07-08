#include "ScreenStack.h"

ScreenStack::ScreenStack() : m_mapper{ new QSignalMapper(this) }
{
	QRect screen_size = QApplication::desktop()->screenGeometry();
	setFixedSize(screen_size.width() / 5, screen_size.height() / 2);
	resize(screen_size.width() / 5, screen_size.height() / 2);

	connect(m_mapper, SIGNAL(mapped(QWidget*)), SLOT(slotDeleteWidget(QWidget*)));

	std::unique_ptr<MainScreen> ms = std::make_unique<MainScreen>();
	connect(ms.get(), SIGNAL(catalogClicked()), SLOT(slotShowCatalog()));
	addWidget(ms.get());
	setCurrentWidget(ms.release());
}

void ScreenStack::slotShowCatalog()
{
	try
	{
		std::unique_ptr<ProductScreen> ps = std::make_unique<ProductScreen>();
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
		ProductManager pm;
		ProductGroup group{ pm.get_group(item->data(Qt::UserRole).toInt()) };

		std::unique_ptr<GroupScreen> gs = std::make_unique<GroupScreen>(group);
		connect(gs.get(), SIGNAL(signalClosed()), m_mapper, SLOT(map()));
		connect(gs.get(), SIGNAL(signalItemSelected(QListWidgetItem*)),
			this, SLOT(slotShowProductItem(QListWidgetItem*)));
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
		Lamp lamp{ pm.get_lamp(item->data(Qt::UserRole).toInt()) };

		std::unique_ptr<LampScreen> ls = std::make_unique<LampScreen>(lamp);

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

void ScreenStack::slotDeleteWidget(QWidget* wgt)
{
	removeWidget(wgt);
}