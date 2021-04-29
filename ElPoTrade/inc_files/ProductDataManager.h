#pragma once
#include <string>
#include <stdexcept>
#include "sqlite3.h"

constexpr char* DB_FILE_PATH = "S:/perfect_circle/RRProject/ElPoTrade/database/DB_FILE.db";
constexpr char* LAMP_DELIM = "*";

class ProductDataManager
{
private:
	sqlite3* m_db;
public:
	ProductDataManager();
	std::string evaluate_sql_query(const char*);
	~ProductDataManager();
};
