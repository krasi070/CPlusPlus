#include <iostream>
#include "SoftUniPerson.h"
#include "CurrentCourse.h"

class GuestTeacher : public SoftUniPerson
{
public:
	GuestTeacher() {}
	GuestTeacher(
		unsigned short id,
		std::string name,
		CurrentCourse currCourse,
		double salaryForCourse)
	{
		this->id = id;
		this->name = name;
		this->currCourse = currCourse;
		this->salaryForCourse = salaryForCourse;
	}

	double salaryForCourse;
};