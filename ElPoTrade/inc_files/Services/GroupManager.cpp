#include "GroupManager.h"

GroupManager::GroupManager()
	: m_pdm{ std::make_unique<ProductDataManager>() }
{}

std::vector<ProductGroup> GroupManager::get_all() const
{
	return m_pdm->get_all<ProductGroup>();
}

ProductGroup GroupManager::get_item(int item_id) const
{
	return m_pdm->get_item<ProductGroup>(item_id);
}