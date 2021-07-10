#pragma once
#include <string>
#include "hiberlite.h"

struct Suggestion
{
	friend class hiberlite::access;
	template<class Archive>
	void hibernate(Archive& ar)
	{
		ar& HIBERLITE_NVP(name);
		ar& HIBERLITE_NVP(email);
		ar& HIBERLITE_NVP(text);
	}

	int id;
	std::string name;
	std::string email;
	std::string text;
};
