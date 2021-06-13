#pragma once
#include <vector>
#include <utility>
#include "Lamp.h"

constexpr char* DB_FILE_PATH_PRODUCTS = "database/DB_FILE.db";

class ProductDataManager
{
private:
	hiberlite::Database m_db;
public:
	ProductDataManager();
	~ProductDataManager();
	std::vector<std::pair<Lamp, int>> get_catalog();
	Lamp get_lamp(int);
};
