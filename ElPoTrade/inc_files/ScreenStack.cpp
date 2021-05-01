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
	ProductScreen* ps = new ProductScreen;
	connect(ps, SIGNAL(signalClosed()), m_mapper, SLOT(map()));
	addWidget(ps);
	m_mapper->setMapping(ps, ps);
	setCurrentWidget(ps);
}

void ScreenStack::slotDeleteWidget(QWidget* wgt)
{
	removeWidget(wgt);
}