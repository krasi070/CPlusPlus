#include <iostream>
#include "SoftUniPerson.h"
#include "CurrentCourse.h"

class Teacher : public SoftUniPerson
{
public:
	Teacher() {}
	Teacher(
		unsigned short id, 
		std::string name, 
		CurrentCourse currCourse, 
		double monthlySalary, 
		unsigned short daysInSoftUni)
	{
		this->id = id;
		this->name = name;
		this->currCourse = currCourse;
		this->monthlySalary = monthlySalary;
		this->daysInSoftUni = daysInSoftUni;
	}

	double monthlySalary;
	unsigned short daysInSoftUni;
};