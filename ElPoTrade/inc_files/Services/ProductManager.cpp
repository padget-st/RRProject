#include "ProductManager.h"

std::vector<Lamp> ProductManager::get_catalog()
{
	ProductDataManager pdm;
	return pdm.get_catalog();
}