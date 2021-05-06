#pragma once
#include <vector>
#include <string_view>
#include <fstream>
#include <utility>

class ResourceManager
{
private:
	const std::string icon_path{ "S:/perfect_circle/RRProject/ElPoTrade/icons/" };
public:
	//ResourceManager();
	std::pair<unsigned char*, int> get_icon(std::string_view);
};
