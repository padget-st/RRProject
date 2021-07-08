#pragma once
#include <vector>
#include <string_view>
#include "Lamp.h"
#include "ProductGroup.h"

constexpr std::string_view DB_FILE_PATH_PRODUCTS{ "database/DB_FILE.db" };

class ProductDataManager
{
private:
	hiberlite::Database m_db;
public:
	ProductDataManager();
	~ProductDataManager();

	std::vector<Lamp> get_catalog();
	std::vector<Lamp> get_grouped_catalog(int);
	Lamp get_lamp(int);

	std::vector<ProductGroup> get_all_groups();
	ProductGroup get_group(int);
};
