#include <iostream>
#include <memory>
#include "Dog.h"

#ifndef __FRIEND_H
#define __FRIEND_H

class Friend
{
public:
	Friend() {}
	Friend(std::string name, std::weak_ptr<Dog> dog)
		: name(name), dog(dog) {}

	std::string name;
	std::weak_ptr<Dog> dog;
};

#endif