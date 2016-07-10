#include <iostream>
#include "User.h"
#include "Gender.h"

User::User(int age, std::string name, Gender gender, std::string loc, std::string ethnicity)
{
	this->setAge(age);
	this->setName(name);
	this->setGender(gender);
	this->setLocation(loc);
	this->setEthnicity(ethnicity);
}

int User::getAge()
{
	return this->age;
}

void User::setAge(int age)
{
	this->age = age;
}

std::string User::getName()
{
	return this->name;
}

void User::setName(std::string name)
{
	this->name = name;
}

Gender User::getGender()
{
	return this->gender;
}

void User::setGender(Gender gender)
{
	this->gender = gender;
}

std::string User::getLocation()
{
	return this->location;
}

void User::setLocation(std::string location)
{
	this->location = location;
}

std::string User::getEthnicity()
{
	return this->ethnicity;
}

void User::setEthnicity(std::string ethnicity)
{
	this->ethnicity = ethnicity;
}