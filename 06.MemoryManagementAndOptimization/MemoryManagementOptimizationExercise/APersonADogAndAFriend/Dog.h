#include <iostream>

#ifndef __DOG_H
#define __DOG_H

class Dog
{
public:
	Dog() 
	{
		std::cout << "Dog allocated!" << std::endl;
	}

	Dog(std::string name, std::string breed)
		: name(name), breed(breed) 
	{
		std::cout << "Dog allocated!" << std::endl;
	}

	~Dog()
	{
		std::cout << "Dog deallocated!" << std::endl;
	}

	std::string name;
	std::string breed;
};

#endif