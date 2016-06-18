#include <iostream>
#include "SoftUniPerson.h"
#include "CurrentCourse.h"

class Student : public SoftUniPerson
{
public:
	Student() {}
	Student(
		unsigned short newId, 
		std::string newName,
		CurrentCourse newCurrCourse, 
		unsigned int newCurrPoints,
		float newAverageEvaluationMark)
	{
		id = newId;
		name = newName;
		currCourse = newCurrCourse;
		currPoints = newCurrPoints;
		averageEvaluationMark = newAverageEvaluationMark;
	}

	unsigned int currPoints;
	float averageEvaluationMark;
};