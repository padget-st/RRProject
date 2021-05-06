#include "ProductDataManager.h"

ProductDataManager::ProductDataManager()
{
	if (SQLITE_OK != sqlite3_open_v2(DB_FILE_PATH, &m_db, SQLITE_OPEN_READONLY, NULL))
	{
		sqlite3_close_v2(m_db);
		throw std::runtime_error("can't open the database");
	}
}


std::string ProductDataManager::evaluate_sql_query(const char* sql_query)
{
	std::string result{};
	sqlite3_stmt* stmt;

	if (SQLITE_OK != sqlite3_prepare_v2(m_db, sql_query, -1, &stmt, NULL))
	{
		sqlite3_finalize(stmt);
		sqlite3_close_v2(m_db);
		throw std::runtime_error("can't prepare the statement");
	}

	while (SQLITE_ROW == sqlite3_step(stmt))
	{
		for (int i{}; i < sqlite3_column_count(stmt); i++)
		{
			result = result + sqlite3_column_name(stmt, i) + "\n" +
				static_cast<const char*>(sqlite3_column_blob(stmt, i)) + '\n';
		}
		result = result + LAMP_DELIM + '\n';
	}

	sqlite3_finalize(stmt);

	return std::move(result);
}

ProductDataManager::~ProductDataManager()
{
	if (m_db)
	{
		sqlite3_close_v2(m_db);
	}
}