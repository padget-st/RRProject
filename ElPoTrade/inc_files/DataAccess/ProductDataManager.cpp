#include "ProductDataManager.h"

ProductDataManager::ProductDataManager()
{
	m_db.open(DB_FILE_PATH_PRODUCTS.data());
}

ProductDataManager::~ProductDataManager()
{
	m_db.close();
}