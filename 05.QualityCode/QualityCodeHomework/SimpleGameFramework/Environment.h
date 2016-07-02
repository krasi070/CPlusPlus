#include <iostream>

#ifndef __ENVIRONMENT_H
#define __ENVIRONMENT_H

class Environment
{
public:
	Environment() {}
	Environment(unsigned int id, std::string name, float gravity)
	{
		this->id = id;
		this->name = name;
		this->gravity = gravity;
	}

	unsigned int id;
	std::string name;
	float gravity;
};

#endif