#pragma once
#include <vector>
#include <memory>
#include "ProductDataManager.h"

class ProductManager
{
private:
	std::shared_ptr<ProductDataManager> m_pdm;
public:
	ProductManager();

	std::vector<Lamp> get_catalog() const;
	std::vector<Lamp> get_grouped_catalog(int) const;
	Lamp get_lamp(int) const;
	
	std::vector<ProductGroup> get_all_groups() const;
	ProductGroup get_group(int) const;
};
