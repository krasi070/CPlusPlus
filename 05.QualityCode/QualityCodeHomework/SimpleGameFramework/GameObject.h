#include <iostream>

#ifndef __GAMEOBJECT_H
#define __GAMEOBJECT_H

class GameObject
{
public:
	GameObject() {}
	GameObject(std::string name, unsigned int id)
	{
		this->name = name;
		this->id = id;
	}

	std::string name;
	unsigned int id;
};

#endif