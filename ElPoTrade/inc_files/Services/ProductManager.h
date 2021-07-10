#pragma once
#include <vector>
#include <memory>
#include "ProductDataManager.h"

class ProductManager
{
private:
	std::unique_ptr<ProductDataManager> m_pdm;
public:
	ProductManager();

	std::vector<Lamp> get_all() const;
	std::vector<Lamp> get_grouped(int group_id) const;
	Lamp get_item(int) const;
};
