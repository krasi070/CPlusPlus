#include <iostream>

#ifndef __ENVIRONMENT_H
#define __ENVIRONMENT_H

class Environment
{
public:
	Environment() {}
	Environment(double gravity)
	{
		this->gravity = gravity;
	}

	std::string name;
	double gravity;
};

#endif