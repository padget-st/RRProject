#pragma once

#include <QtWidgets>
#include <memory>
#include "ProductManager.h"
#include "ResourceManager.h"
#include "DocumentManager.h"
#include "ProductGroup.h"

constexpr double GROUP_SCR_PIX_W_SCALE{2.35};
constexpr double GROUP_SCR_PIX_H_SCALE{2};
constexpr int GROUP_SCR_LR_W_SCALE{21};
constexpr int GROUP_SCR_LR_H_SCALE{16};

class GroupScreen : public QScrollArea
{
	Q_OBJECT
private:
	QPushButton* m_pb_left, *m_pb_right, *m_pb_close;
	QListWidget* m_prod_list, *m_doc_list;
	QLabel* m_info_text, *m_info_img, *m_img_viewer;
	std::vector<QPixmap> v_images;
	int img_count;
	std::vector<QPixmap> get_images(const std::vector<std::string>&);
	void fill_in(const ProductGroup&);
public:
	GroupScreen(const ProductGroup&, QWidget* wgt = 0);
signals:
	void signalClosed();
	void signalProdSelected(QListWidgetItem*);
	void signalDocSelected(QListWidgetItem*);
public slots:
	void slotSetLeftImg();
	void slotSetRightImg();
};
