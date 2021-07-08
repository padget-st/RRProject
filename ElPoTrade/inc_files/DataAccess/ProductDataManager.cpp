#include "ProductDataManager.h"

ProductDataManager::ProductDataManager()
{
	m_db.open(DB_FILE_PATH_PRODUCTS.data());
}

std::vector<Lamp> ProductDataManager::get_catalog()
{
	std::vector<Lamp> v_lamps;
	auto temp{ m_db.getAllBeans<Lamp>() };

	for (auto elem : temp)
	{
		Lamp lamp{*elem};
		lamp.lamp_id = elem.get_id();
		v_lamps.push_back(lamp);
	}
	
	return v_lamps;
}

std::vector<Lamp> ProductDataManager::get_grouped_catalog(int group_id)
{
	std::vector<Lamp> v_lamps;
	auto temp{ m_db.getAllBeans<Lamp>() };

	for (auto elem : temp)
	{
		if (elem->outer_group_id == group_id)
		{
			Lamp lamp{ *elem };
			lamp.lamp_id = elem.get_id();
			v_lamps.push_back(lamp);
		}
	}

	return v_lamps;
}

Lamp ProductDataManager::get_lamp(int lamp_id)
{
	auto bean_lamp = m_db.loadBean<Lamp>(lamp_id);
	Lamp lamp{ *bean_lamp };
	lamp.lamp_id = bean_lamp.get_id();
	return lamp;
}

std::vector<ProductGroup> ProductDataManager::get_all_groups()
{
	std::vector<ProductGroup> v_groups;
	auto temp{ m_db.getAllBeans<ProductGroup>() };

	for (auto elem : temp)
	{
		ProductGroup group{ *elem };
		group.group_id = elem.get_id();
		v_groups.push_back(group);
	}

	return v_groups;
}

ProductGroup ProductDataManager::get_group(int group_id)
{
	auto bean_group = m_db.loadBean<ProductGroup>(group_id);
	ProductGroup prod_group{ *bean_group };
	prod_group.group_id = bean_group.get_id();
	return prod_group;
}

ProductDataManager::~ProductDataManager()
{
	m_db.close();
}