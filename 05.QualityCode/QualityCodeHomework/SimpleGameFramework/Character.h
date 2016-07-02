#include <iostream>

#ifndef __CHARACTER_H
#define __CHARACTER_H

class Character
{
public:
	Character() {}
	Character(std::string name, float massInKg, float jumpSpeedInKmPerHour, unsigned int id)
	{
		this->name = name;
		this->massInKg = massInKg;
		this->jumpSpeedInKmPerHour = jumpSpeedInKmPerHour;
		this->id = id;
	}

	std::string name;
	float massInKg;
	float jumpSpeedInKmPerHour;
	unsigned int id;
};

#endif