#pragma once
#include <string>
#include "hiberlite.h"

struct Lamp
{
	friend class hiberlite::access;
	template<class Archive>
	void hibernate(Archive& ar)
	{
		ar& HIBERLITE_NVP(outer_group_id);
		ar& HIBERLITE_NVP(name);
		ar& HIBERLITE_NVP(dimensions);
		ar& HIBERLITE_NVP(radiant_type);
		ar& HIBERLITE_NVP(lightflow);
		ar& HIBERLITE_NVP(power);
		ar& HIBERLITE_NVP(light_efficiency);
		ar& HIBERLITE_NVP(color_temperature_low);
		ar& HIBERLITE_NVP(color_temperature_high);
		ar& HIBERLITE_NVP(diffuser_material);
		ar& HIBERLITE_NVP(diffusing_angle);
		ar& HIBERLITE_NVP(LIC_type);
		ar& HIBERLITE_NVP(protect_degree);
		ar& HIBERLITE_NVP(climatic_type);
		ar& HIBERLITE_NVP(emergency_power_unit);
		ar& HIBERLITE_NVP(housing_color);
		ar& HIBERLITE_NVP(housing_material);
		ar& HIBERLITE_NVP(work_temperature_low);
		ar& HIBERLITE_NVP(work_temperature_high);
		ar& HIBERLITE_NVP(power_ratio);
		ar& HIBERLITE_NVP(pulse_ratio);
		ar& HIBERLITE_NVP(voltage_low);
		ar& HIBERLITE_NVP(voltage_high);
		ar& HIBERLITE_NVP(protect_class);
		ar& HIBERLITE_NVP(service_life);
		ar& HIBERLITE_NVP(weight);
		ar& HIBERLITE_NVP(images_url);
	}

	int lamp_id;
	int outer_group_id;
	std::string name;
	std::string dimensions;
	std::string radiant_type;
	int lightflow;
	int power;
	int light_efficiency;
	int color_temperature_low;
	int color_temperature_high;
	std::string diffuser_material;
	int diffusing_angle;
	std::string LIC_type;
	std::string protect_degree;
	std::string climatic_type;
	std::string emergency_power_unit;
	std::string housing_color;
	std::string housing_material;
	int work_temperature_low;
	int work_temperature_high;
	float power_ratio;
	float pulse_ratio;
	int voltage_low;
	int voltage_high;
	std::string protect_class;
	int service_life;
	float weight;
  std::vector<std::string> images_url;
};
