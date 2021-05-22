#pragma once
#include <QtWidgets>
#include "MainScreen.h"
#include "ProductScreen.h"
#include "LampScreen.h"

class ScreenStack : public QStackedWidget
{
	Q_OBJECT
private:
	QSignalMapper* m_mapper;
public:
	ScreenStack();
public slots:
	void slotShowCatalog();
	void slotShowProductItem(QListWidgetItem*);
	void slotDeleteWidget(QWidget*);
};
