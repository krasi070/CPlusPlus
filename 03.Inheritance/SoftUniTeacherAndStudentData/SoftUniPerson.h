#ifndef SOFTUNIPERSON_HEADER
#define SOFTUNIPERSON_HEADER

#include <iostream>

class SoftUniPerson
{
public:
	SoftUniPerson() {}
	unsigned short id;
	std::string name;
	CurrentCourse currCourse;
};

#endif