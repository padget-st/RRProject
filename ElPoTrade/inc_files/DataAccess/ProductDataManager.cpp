#include "ProductDataManager.h"

ProductDataManager::ProductDataManager()
{
	m_db.open(DB_FILE_PATH_PRODUCTS);
}

std::vector<Lamp> ProductDataManager::get_catalog()
{
	std::vector<Lamp> v_lamps;
	auto temp{ m_db.getAllBeans<Lamp>() };

	for (auto elem : temp)
	{
		v_lamps.push_back(*elem);
	}
	
	return v_lamps;
}

ProductDataManager::~ProductDataManager()
{
	m_db.close();
}