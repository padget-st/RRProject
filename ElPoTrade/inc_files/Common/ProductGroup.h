#pragma once
#include <string>
#include "hiberlite.h"

struct ProductGroup
{
	friend class hiberlite::access;
	template<class Archive>
	void hibernate(Archive& ar)
	{
		ar& HIBERLITE_NVP(group_name);
		ar& HIBERLITE_NVP(info);
		ar& HIBERLITE_NVP(images_url);
		ar& HIBERLITE_NVP(doc_url);
	}

	int group_id;
	std::string group_name;
	std::string info;
	std::vector<std::string> images_url;
	std::vector<std::string> doc_url;
};
