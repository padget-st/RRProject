#pragma once
#include <vector>
#include <string_view>
#include <fstream>

class ResourceManager
{
private:
	std::string_view icon_path{ "icons/" }, doc_path{ "docs/" }, banner_path{ "icons/banner.jpg" };
	std::vector<unsigned char> get_vchar(std::string_view) const;
public:
	//ResourceManager();
	std::vector<unsigned char> get_icon(std::string_view) const;
	std::vector<unsigned char> get_doc(std::string_view) const;
	std::vector<unsigned char> get_banner() const;
};
