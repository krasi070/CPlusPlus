#include <iostream>
#include <memory>
#include "Dog.h"

#ifndef __PERSON_H
#define __PERSON_H

class Person
{
public:
	Person() {}
	Person(std::string name, std::shared_ptr<Dog> dog)
		: name(name), dog(dog) {}

	std::string name;
	std::shared_ptr<Dog> dog;
};

#endif