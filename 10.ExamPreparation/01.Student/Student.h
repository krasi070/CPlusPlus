#include <iostream>
#include <set>
#include <map>

#ifndef __STUDENT_H
#define __STUDENT_H

enum Group
{
	GROUP_40 = 40,
	GROUP_41,
	GROUP_42,
	GROUP_43,
	GROUP_44
};

enum Course
{
	COURSE_1 = 1,
	COURSE_2,
	COURSE_3,
	COURSE_4,
	COURSE_5
};

class Student
{
protected:
	std::string _name;
	std::string _facultyNumber;
	Group _group;
	Course _course;
	std::set<std::string> _subjects;
	std::map<std::string, float> _marks;

public:
	// Constructors
	Student() { }

	// Getters & Setters
	std::string getName() 
	{ 
		return this->_name; 
	}

	void setName(std::string name) 
	{
		this->_name = name; 
	}

	std::string getFacultyNumber() 
	{ 
		return this->_facultyNumber; 
	}

	void setFacultyNumber(std::string facultyNumber) 
	{ 
		this->_facultyNumber = facultyNumber; 
	}

	Group getGroup() 
	{ 
		return this->_group;
	}

	bool setGroup(Group group) 
	{
		switch (group)
		{
		case GROUP_40:
		case GROUP_41:
		case GROUP_42:
		case GROUP_43:
		case GROUP_44:
			this->_group = group;
			return true;
		default:
			return false;
		}
	}

	Course getCourse()
	{ 
		return this->_course; 
	}

	bool setCourse(Course course) 
	{ 
		switch (course)
		{
		case COURSE_1:
		case COURSE_2:
		case COURSE_3:
		case COURSE_4:
		case COURSE_5:
			this->_course = course;
			return true;
		default:
			return false;
		}
	}

	std::set<std::string> getSubjects() 
	{ 
		return this->_subjects;
	}

	void setSubjects(std::set<std::string> subjects) 
	{ 
		this->_subjects = subjects;
	}

	std::map<std::string, float> getMarks()
	{ 
		return this->_marks;
	}

	void setMarks(std::map<std::string, float> marks) 
	{ 
		this->_marks = marks;
	}

	// Functions
	void fillInfo();

	void addMark(std::string subject, float mark);

	float calculateAverageMark();
};

#endif