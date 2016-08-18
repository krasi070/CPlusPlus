#include <algorithm>
#include <string>
#include "CourseContainer.h"

void CourseContainer::searchByFacultyNumber(std::string facultyNumber)
{
	bool found = false;
	std::for_each(this->studentsContainer.begin(), this->studentsContainer.end(),
		[&](std::shared_ptr<Student> student) 
	{
		if (student->getFacultyNumber() == facultyNumber)
		{
			std::cout << "STUDENT FOUND" << std::endl << 
				"Name: " << student->getName() << std::endl;
			found = true;
		}
	});

	if (!found)
	{
		std::cout << "Cannot find student!" << std::endl;
	}
}