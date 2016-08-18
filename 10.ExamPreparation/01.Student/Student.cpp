#include <iostream>
#include <string>
#include "Student.h"

void Student::fillInfo()
{
	std::cout << "Name: ";
	std::string name;
	getline(std::cin, name);
	this->setName(name);

	std::cout << "Faculty number: ";
	std::string facultyNumber;
	getline(std::cin, facultyNumber);
	this->setFacultyNumber(facultyNumber);

	int group;
	do
	{
		std::cout << "Group [40; 44]: ";
		std::cin >> group;
		std::cin.ignore();
	} while (this->setGroup((Group)group) == false);

	int course;
	do
	{
		std::cout << "Course [1; 5]: ";
		std::cin >> course;
		std::cin.ignore();
	} while (this->setCourse((Course)course) == false);

	int currSubject = 1;
	do
	{
		std::cout << "Subject " << currSubject << ": ";
		std::string subject;
		getline(std::cin, subject);
		if (subject[0] == '!')
		{
			break;
		}

		std::cout << "Mark (" << subject << "): ";
		float mark;
		std::cin >> mark;
		std::cin.ignore();

		this->addMark(subject, mark);
		currSubject++;
	} while (true);
}

void Student::addMark(std::string subject, float mark)
{
	this->_subjects.insert(subject);
	this->_marks[subject] = mark;
}

float Student::calculateAverageMark()
{
	float sum = 0;
	for each (std::string subject in this->_subjects)
	{
		sum += this->_marks[subject];
	}

	float averageMark = sum / this->_subjects.size();
	return averageMark;
}