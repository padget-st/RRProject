#pragma once
#include <string>
#include "hiberlite.h"

struct Contact
{
	friend class hiberlite::access;
	template<class Archive>
	void hibernate(Archive& ar)
	{
		ar& HIBERLITE_NVP(name);
		ar& HIBERLITE_NVP(address);
		ar& HIBERLITE_NVP(phones);
		ar& HIBERLITE_NVP(bank_acc);
		ar& HIBERLITE_NVP(TIN);
		ar& HIBERLITE_NVP(site);
		ar& HIBERLITE_NVP(email);
	}

	int id;
	std::string name;
	std::string address;
	std::string phones;
	std::string bank_acc;
	int TIN;
	std::string site;
	std::string email;
};