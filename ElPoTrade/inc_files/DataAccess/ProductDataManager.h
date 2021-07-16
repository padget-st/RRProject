#pragma once
#include <vector>
#include <string_view>
#include "Lamp.h"
#include "ProductGroup.h"
#include "ItemDocument.h"
#include "Contact.h"
#include "Suggestion.h"

constexpr std::string_view DB_FILE_PATH_PRODUCTS{ "database/DB_FILE.db" };
constexpr int DATA_MANAGER_MIN_ID{ 1 };

class ProductDataManager
{
private:
	hiberlite::Database m_db;
public:
	ProductDataManager();
	~ProductDataManager();

	template<typename T>
	std::vector<T> get_all();

	template<typename T>
	std::vector<T> get_grouped(int group_id);

	template<typename T>
	T get_item(int);

	template<typename T>
	void save_item(const T&);
};

template<typename T>
std::vector<T> ProductDataManager::get_all()
{
	std::vector<T> v_items;
	auto temp{ m_db.getAllBeans<T>() };
	T item;

	for (auto elem : temp)
	{
		item = *elem;
		item.id = elem.get_id();
		v_items.push_back(item);
	}

	return v_items;
}

template<typename T>
std::vector<T> ProductDataManager::get_grouped(int group_id)
{
	auto temp{ m_db.getAllBeans<T>() };

	if (group_id < DATA_MANAGER_MIN_ID || group_id > temp.size())
	{
		throw std::runtime_error("Wrong group_id");
	}

	std::vector<T> v_items;
	T item;

	for (auto elem : temp)
	{
		if (elem->outer_group_id == group_id)
		{
			item = *elem;
			item.id = elem.get_id();
			v_items.push_back(item);
		}
	}

	return v_items;
}

template<typename T>
T ProductDataManager::get_item(int item_id)
{
	auto bean_item = m_db.loadBean<T>(item_id);
	T item{ *bean_item };
	item.id = bean_item.get_id();
	return item;
}

template<typename T>
void ProductDataManager::save_item(const T& item)
{
	m_db.copyBean<T>(item);
}