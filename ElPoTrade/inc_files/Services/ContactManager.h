#pragma once
#include <vector>
#include <memory>
#include "ProductDataManager.h"

constexpr int MAIN_CONTACT_ID{ 1 };

class ContactManager
{
private:
	std::unique_ptr<ProductDataManager> m_pdm;
public:
	ContactManager();

	std::vector<Suggestion> get_all_sug() const;
	Suggestion get_suggestion(int) const;
	Contact get_contact() const;
	void save_suggestion(const Suggestion&) const;
};
