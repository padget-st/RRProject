#include "ResourceManager.h"

std::pair<unsigned char*, int> ResourceManager::get_icon(std::string_view iconName)
{
	int buff_size{ 300'000 };
	unsigned char* icon_buff = new unsigned char[buff_size];

	std::ifstream res_icon(icon_path + iconName.data(), std::ios::binary);
	if (!res_icon)
	{
		throw std::runtime_error("Can't open icon's file");
	}

	res_icon.read(reinterpret_cast<char*>(icon_buff), buff_size * sizeof(unsigned char));

	//std::vector<unsigned char>  v_icon{};
	//for (unsigned int i{}; i < res_icon.gcount(); i++)
	//	v_icon.push_back(icon_buff[i]);

	return std::make_pair(icon_buff, static_cast<int>(res_icon.gcount()));
}