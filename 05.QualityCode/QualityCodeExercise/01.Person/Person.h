#include <iostream>

#ifndef __PERSON_H
#define __PERSON_H

enum gender_t
{
	male,
	female,
	other
};

class Person
{
public:
	Person();
	Person(std::string name, gender_t gender)
	{
		this->name = name;
		this->gender = gender;
	}

	std::string name;
	std::string ucn;
	int age;
	float height;
	gender_t gender;

	void setAge(int age);
	void setUcn(std::string ucn);
};

#endif