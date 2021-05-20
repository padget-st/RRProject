#include "ScreenStack.h"

ScreenStack::ScreenStack() : m_mapper{ new QSignalMapper(this) }
{
	connect(m_mapper, SIGNAL(mapped(QWidget*)), SLOT(slotDeleteWidget(QWidget*)));

	MainScreen* ms = new MainScreen;
	connect(ms, SIGNAL(catalogClicked()), SLOT(slotShowCatalog()));
	addWidget(ms);
	setCurrentWidget(ms);
}

void ScreenStack::slotShowCatalog()
{
	try
	{
		ProductScreen* ps = new ProductScreen;
		connect(ps, SIGNAL(signalClosed()), m_mapper, SLOT(map()));
		addWidget(ps);
		m_mapper->setMapping(ps, ps);
		setCurrentWidget(ps);
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