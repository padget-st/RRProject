#pragma once

#include <QtWidgets>
#include <memory>
#include "ProductManager.h"
#include "ResourceManager.h"
#include "ProductGroup.h"

class GroupScreen : public QScrollArea
{
	Q_OBJECT
private:
	QPushButton* m_pb_left, *m_pb_right, *m_pb_close;
	QListWidget* m_list;
	QLabel* m_info_text, *m_info_img, *m_img_viewer;
	std::vector<QPixmap> v_images;
	int img_count;
	std::vector<QPixmap> get_images(std::vector<std::string>&);
	void fill_in(ProductGroup&);
public:
	GroupScreen(ProductGroup&, QWidget* wgt = 0);
signals:
	void signalClosed();
	void signalItemSelected(QListWidgetItem*);
public slots:
	void slotSetLeftImg();
	void slotSetRightImg();
};
