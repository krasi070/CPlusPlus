#include <iostream>
#include "GameObject.h"

#ifndef __ENVIRONMENT_H
#define __ENVIRONMENT_H

class Environment : public GameObject
{
public:
	Environment() {}
	Environment(unsigned int id, std::string name, float gravity)
		: GameObject(name, id)
	{
		this->gravity = gravity;
	}

	float gravity;
};

#endif