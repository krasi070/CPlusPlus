#include <iostream>
#include <vector>
#include <memory>
#include <thread>
#include "Student.h"

#ifndef __COURSECONTAINER_H
#define __COURSECONTAINER_H

class CourseContainer
{
public:
	std::vector<std::shared_ptr<Student>> studentsContainer;

	void searchByFacultyNumber(std::string facultyNumber);
};

#endif