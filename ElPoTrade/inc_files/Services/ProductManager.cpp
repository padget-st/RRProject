#include "ProductManager.h"

ProductManager::ProductManager()
	: m_pdm{ std::make_unique<ProductDataManager>() }
{}

std::vector<Lamp> ProductManager::get_all() const
{
	return m_pdm->get_all<Lamp>();
}

std::vector<Lamp> ProductManager::get_grouped(int group_id) const
{
	return m_pdm->get_grouped<Lamp>(group_id);
}

Lamp ProductManager::get_item(int item_id) const
{
	return m_pdm->get_item<Lamp>(item_id);
}