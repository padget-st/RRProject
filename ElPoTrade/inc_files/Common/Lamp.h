#pragma once
#include <string>
#include "hiberlite.h"

struct Lamp
{
	friend class hiberlite::access;
	template<class Archive>
	void hibernate(Archive& ar)
	{
		ar& HIBERLITE_NVP(name);
		ar& HIBERLITE_NVP(type);
		ar& HIBERLITE_NVP(power);
		ar& HIBERLITE_NVP(lightflow);
		ar& HIBERLITE_NVP(efficiency);
		ar& HIBERLITE_NVP(color_temperature);
		ar& HIBERLITE_NVP(images_url);
	}

	std::string name;
	std::string type;
	int power;
	int lightflow;
	int efficiency;
	int color_temperature;
	std::vector<std::string> images_url;
	Lamp() : name{}, type{}, power{},
		lightflow{}, efficiency{}, color_temperature{}
	{}
};
