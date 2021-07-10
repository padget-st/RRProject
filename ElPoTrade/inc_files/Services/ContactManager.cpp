#include "ContactManager.h"

ContactManager::ContactManager()
	: m_pdm{ std::make_unique<ProductDataManager>() }
{}

std::vector<Suggestion> ContactManager::get_all_sug() const
{
	return m_pdm->get_all<Suggestion>();
}

Suggestion ContactManager::get_suggestion(int id) const
{
	return m_pdm->get_item<Suggestion>(id);
}

Contact ContactManager::get_contact() const
{
	return m_pdm->get_item<Contact>(MAIN_CONTACT_ID);
}

void ContactManager::save_suggestion(const Suggestion& sugg) const
{
	m_pdm->save_item(sugg);
}