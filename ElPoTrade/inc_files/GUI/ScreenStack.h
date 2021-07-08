#pragma once
#include <QtWidgets>
#include <memory>
#include "MainScreen.h"
#include "ProductScreen.h"
#include "GroupScreen.h"
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
	void slotShowGroup(QListWidgetItem*);
	void slotShowProductItem(QListWidgetItem*);
	void slotDeleteWidget(QWidget*);
};
