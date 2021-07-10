#include "ResourceManager.h"

std::vector<unsigned char> ResourceManager::get_vchar(std::string_view path) const
{
	std::vector<unsigned char> v_char;

	std::ifstream res_char(path.data(), std::ios::binary);
	if (!res_char)
	{
		throw std::runtime_error("Can't open the file");
	}

	res_char.seekg(0, std::ios::end);
	v_char.resize(res_char.tellg());
	res_char.seekg(0, std::ios::beg);

	res_char.read(reinterpret_cast<char*>(v_char.data()), v_char.size() * sizeof(unsigned char));

	return v_char;
}

std::vector<unsigned char> ResourceManager::get_icon(std::string_view iconName) const
{
	return get_vchar(std::string(icon_path.data()) + iconName.data());
}

std::vector<unsigned char> ResourceManager::get_doc(std::string_view docName) const
{
	return get_vchar(std::string(doc_path.data()) + docName.data());
}

std::vector<unsigned char> ResourceManager::get_banner() const
{
	return get_vchar(banner_path);
}