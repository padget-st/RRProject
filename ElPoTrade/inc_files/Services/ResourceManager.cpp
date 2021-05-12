#include "ResourceManager.h"

std::vector<unsigned char> ResourceManager::get_icon(std::string_view iconName)
{
	std::vector<unsigned char> v_image;

	std::ifstream res_icon(icon_path + iconName.data(), std::ios::binary);
	if (!res_icon)
	{
		throw std::runtime_error("Can't open icon's file");
	}

	res_icon.seekg(0, std::ios::end);
	v_image.resize(res_icon.tellg());
	res_icon.seekg(0, std::ios::beg);

	res_icon.read(reinterpret_cast<char*>(v_image.data()), v_image.size() * sizeof(unsigned char));

	return v_image;
}