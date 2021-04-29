#pragma once
#include <vector>
#include <memory>
#include <sstream>
#include "ProductDataManager.h"
#include "Lamp.h"

constexpr char* LAMP_ID_COL_STR = "lamp_id";
constexpr char* NAME_COL_STR = "name";
constexpr char* TYPE_COL_STR = "type";
constexpr char* POWER_COL_STR = "power";
constexpr char* LIGHTFLOW_COL_STR = "lightflow";
constexpr char* EFFICIENCY_COL_STR = "efficiency";
constexpr char* COLOR_COL_STR = "color_t";

class ProductManager
{
private:
	enum class lamp_col_type
	{
		lamp_id, name, type, power, lightflow, efficiency, color_t, delim, error
	};

	std::shared_ptr<std::vector<Lamp>> m_pLamps;
	lamp_col_type get_col_type(const std::string&) const;

public:
	ProductManager();
	std::shared_ptr<std::vector<Lamp>> get_catalog(const char*);
};
