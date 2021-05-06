#pragma once
#include <string>

struct Lamp
{
	int id;
	std::string name;
	std::string type;
	int power;
	int lightflow;
	int efficiency;
	int color_temperature;
	Lamp() : id{}, name{}, type{}, power{},
		lightflow{}, efficiency{}, color_temperature{}
	{}
};
