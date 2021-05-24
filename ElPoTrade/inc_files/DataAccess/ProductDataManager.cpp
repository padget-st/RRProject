#include "ProductDataManager.h"

ProductDataManager::ProductDataManager()
{
	m_db.open(DB_FILE_PATH_PRODUCTS);
}

std::vector<std::pair<Lamp, int>> ProductDataManager::get_catalog()
{
	std::vector<std::pair<Lamp, int>> v_lamps;
	auto temp{ m_db.getAllBeans<Lamp>() };

	for (auto elem : temp)
	{
		v_lamps.push_back(std::make_pair(*elem, elem.get_id()));
	}
	
	return v_lamps;
}

Lamp ProductDataManager::get_lamp(int lamp_id)
{
	return *(m_db.loadBean<Lamp>(lamp_id));
}

ProductDataManager::~ProductDataManager()
{
	m_db.close();
}