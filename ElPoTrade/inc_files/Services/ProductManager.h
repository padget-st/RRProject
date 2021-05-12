#pragma once
#include <vector>
#include "ProductDataManager.h"
#include "Lamp.h"

class ProductManager
{
public:
	//ProductManager();
	std::vector<Lamp> get_catalog();
};
