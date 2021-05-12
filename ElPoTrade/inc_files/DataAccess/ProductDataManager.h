#pragma once
#include <string>
#include <stdexcept>
#include <vector>
#include <sstream>
#include "sqlite3.h"
#include "Lamp.h"

constexpr char* DB_FILE_PATH = "S:/perfect_circle/RRProject/ElPoTrade/database/DB_FILE.db";
constexpr char* LAMP_DELIM = "*";

constexpr char* LAMP_ID_COL_STR = "lamp_id";
constexpr char* NAME_COL_STR = "name";
constexpr char* TYPE_COL_STR = "type";
constexpr char* POWER_COL_STR = "power";
constexpr char* LIGHTFLOW_COL_STR = "lightflow";
constexpr char* EFFICIENCY_COL_STR = "efficiency";
constexpr char* COLOR_COL_STR = "color_t";

class ProductDataManager
{
private:
	enum class lamp_col_type
	{
		lamp_id, name, type, power, lightflow, efficiency, color_t, delim, error
	};

	sqlite3* m_db;
	lamp_col_type get_col_type(const std::string&) const;
	std::string evaluate_sql_query(const char*);
public:
	ProductDataManager();
	~ProductDataManager();
	std::vector<Lamp> get_catalog();
};
