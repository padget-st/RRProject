#include "ProductManager.h"

ProductManager::lamp_col_type ProductManager::get_col_type(const std::string& str) const
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

ProductManager::ProductManager() : m_pLamps{new std::vector<Lamp>()}
{}

std::shared_ptr<std::vector<Lamp>> ProductManager::get_catalog()
{
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
		(*m_pLamps).push_back(temp_lamp);
	}
	return m_pLamps;
}