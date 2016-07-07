#include <iostream>
#include "GameObject.h"

#ifndef __CHARACTER_H
#define __CHARACTER_H

class Character : public GameObject
{
public:
	Character() {}
	Character(std::string name, float massInKg, float jumpSpeedInKmPerHour, unsigned int id)
		: GameObject(name, id)
	{
		this->massInKg = massInKg;
		this->jumpSpeedInKmPerHour = jumpSpeedInKmPerHour;
	}

	
	float massInKg;
	float jumpSpeedInKmPerHour;
	
};

#endif