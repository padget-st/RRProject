#pragma once
#include <vector>
#include <string_view>
#include <fstream>

class ResourceManager
{
private:
	const std::string icon_path{ "icons/" };
public:
	//ResourceManager();
	std::vector<unsigned char> get_icon(std::string_view);
};
