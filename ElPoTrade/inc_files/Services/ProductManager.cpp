#include "ProductManager.h"

ProductManager::ProductManager()
	: m_pdm{ std::make_shared<ProductDataManager>() }
{}

std::vector<Lamp> ProductManager::get_catalog() const
{
	return m_pdm->get_catalog();
}

std::vector<Lamp> ProductManager::get_grouped_catalog(int group_id) const
{
	return m_pdm->get_grouped_catalog(group_id);
}

Lamp ProductManager::get_lamp(int lamp_id) const
{
	return m_pdm->get_lamp(lamp_id);
}

std::vector<ProductGroup> ProductManager::get_all_groups() const
{
	return m_pdm->get_all_groups();
}

ProductGroup ProductManager::get_group(int group_id) const
{
	return m_pdm->get_group(group_id);
}