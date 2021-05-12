#pragma once
#include <vector>
#include <string_view>
#include <fstream>

class ResourceManager
{
private:
	const std::string icon_path{ "S:/perfect_circle/RRProject/ElPoTrade/icons/" };
public:
	//ResourceManager();
	std::vector<unsigned char> get_icon(std::string_view);
};
