#pragma once
#include <QtWidgets>
#include <memory>
#include "MainScreen.h"
#include "ProductScreen.h"
#include "GroupScreen.h"
#include "LampScreen.h"
#include "DocumentScreen.h"
#include "DownloadDocScreen.h"
#include "ContactScreen.h"
#include "SuggestionScreen.h"

constexpr int SCR_STACK_W_SCALE{5};
constexpr int SCR_STACK_H_SCALE{2};

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
	void slotShowDocuments();
	void slotShowDownload(QListWidgetItem*);
	void slotShowContact();
	void slotShowSuggest();
	void slotDeleteWidget(QWidget*);
};
