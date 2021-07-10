#pragma once
#include <string>
#include "hiberlite.h"

struct ItemDocument
{
	friend class hiberlite::access;
	template<class Archive>
	void hibernate(Archive& ar)
	{
		ar& HIBERLITE_NVP(outer_group_id);
		ar& HIBERLITE_NVP(doc_name);
		ar& HIBERLITE_NVP(doc_url);
	}

	int id;
	int outer_group_id;
	std::string doc_name;
	std::string doc_url;
};
