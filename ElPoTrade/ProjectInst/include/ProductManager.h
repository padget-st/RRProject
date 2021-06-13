#pragma once
#include <vector>
#include "ProductDataManager.h"

class ProductManager
{
private:
	ProductDataManager* m_pdm;
public:
	ProductManager();
	std::vector<std::pair<Lamp, int>> get_catalog() const;
	Lamp get_lamp(int) const;
	~ProductManager();
};
