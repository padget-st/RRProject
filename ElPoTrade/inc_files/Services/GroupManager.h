#pragma once

#include <vector>
#include <memory>
#include "ProductDataManager.h"

class GroupManager
{
private:
	std::unique_ptr<ProductDataManager> m_pdm;
public:
	GroupManager();

	std::vector<ProductGroup> get_all() const;
	ProductGroup get_item(int) const;
};
