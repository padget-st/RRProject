#include "ProductManager.h"

ProductManager::ProductManager()
	: m_pdm{ new ProductDataManager }
{}

std::vector<std::pair<Lamp, int>> ProductManager::get_catalog() const
{
	return m_pdm->get_catalog();
}

Lamp ProductManager::get_lamp(int lamp_id) const
{
	return m_pdm->get_lamp(lamp_id);
}

ProductManager::~ProductManager()
{
	delete m_pdm;
}