#pragma once
#include <QtWidgets>
#include "MainScreen.h"
#include "ProductScreen.h"

class ScreenStack : public QStackedWidget
{
	Q_OBJECT
private:
	QSignalMapper* m_mapper;
public:
	ScreenStack();
public slots:
	void slotShowCatalog();
	void slotDeleteWidget(QWidget*);
};
