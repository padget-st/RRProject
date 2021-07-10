#include "DocumentManager.h"

DocumentManager::DocumentManager()
	: m_pdm{ std::make_unique<ProductDataManager>() }
{}

std::vector<ItemDocument> DocumentManager::get_all() const
{
	return m_pdm->get_all<ItemDocument>();
}

std::vector<ItemDocument> DocumentManager::get_grouped(int group_id) const
{
	return m_pdm->get_grouped<ItemDocument>(group_id);
}

ItemDocument DocumentManager::get_item(int item_id) const
{
	return m_pdm->get_item<ItemDocument>(item_id);
}