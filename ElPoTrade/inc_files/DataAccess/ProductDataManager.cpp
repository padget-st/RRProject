#include "ProductDataManager.h"

ProductDataManager::lamp_col_type ProductDataManager::get_col_type(const std::string& str) const
{
	if (str == LAMP_ID_COL_STR)
	{
		return lamp_col_type::lamp_id;
	}
	else if (str == NAME_COL_STR)
	{
		return lamp_col_type::name;
	}
	else if (str == TYPE_COL_STR)
	{
		return lamp_col_type::type;
	}
	else if (str == POWER_COL_STR)
	{
		return lamp_col_type::power;
	}
	else if (str == LIGHTFLOW_COL_STR)
	{
		return lamp_col_type::lightflow;
	}
	else if (str == EFFICIENCY_COL_STR)
	{
		return lamp_col_type::efficiency;
	}
	else if (str == COLOR_COL_STR)
	{
		return lamp_col_type::color_t;
	}
	else if (str == LAMP_DELIM)
	{
		return lamp_col_type::delim;
	}
	else return lamp_col_type::error;
}

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

std::vector<Lamp> ProductDataManager::get_catalog()
{
	std::vector<Lamp> v_lamps;
	ProductDataManager pdm;
	std::string str_data{ pdm.evaluate_sql_query("SELECT lamp_id, name, type, power FROM Lamp") }, temp_str{};
	std::istringstream is{ str_data };
	while (true)
	{
		bool flag{ true };
		Lamp temp_lamp{};
		while (flag && is >> temp_str)
		{
			switch (get_col_type(temp_str))
			{
			case lamp_col_type::lamp_id:
				is >> temp_lamp.id;
				break;
			case lamp_col_type::name:
				is >> temp_lamp.name;
				break;
			case lamp_col_type::type:
				is >> temp_lamp.type;
				break;
			case lamp_col_type::power:
				is >> temp_lamp.power;
				break;
			case lamp_col_type::lightflow:
				is >> temp_lamp.lightflow;
				break;
			case lamp_col_type::efficiency:
				is >> temp_lamp.efficiency;
				break;
			case lamp_col_type::color_t:
				is >> temp_lamp.color_temperature;
				break;
			case lamp_col_type::delim:
				flag = false;
				break;
			case lamp_col_type::error:
				throw std::runtime_error("wrong data");
			}
		}
		if (!is)
		{
			break;
		}
		v_lamps.push_back(temp_lamp);
	}
	return v_lamps;
}

ProductDataManager::~ProductDataManager()
{
	if (m_db)
	{
		sqlite3_close_v2(m_db);
	}
}