#pragma once
#include <vector>
#include <memory>
#include "ProductDataManager.h"

class DocumentManager
{
private:
	std::unique_ptr<ProductDataManager> m_pdm;
public:
	DocumentManager();

	std::vector<ItemDocument> get_all() const;
	std::vector<ItemDocument> get_grouped(int group_id) const;
	ItemDocument get_item(int) const;
};
