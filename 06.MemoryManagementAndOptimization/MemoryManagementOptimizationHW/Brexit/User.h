#include <iostream>
#include "Gender.h"

#ifndef __USER_H
#define __USER_H

class User
{
private:
	int age;
	std::string name;
	Gender gender;
	std::string location;
	std::string ethnicity;
public:
	User() {}

	User(int age, std::string name, Gender gender, std::string loc, std::string ethnicity);

	int getAge();

	void setAge(int age);

	std::string getName();

	void setName(std::string name);

	Gender getGender();

	void setGender(Gender gender);

	std::string getLocation();

	void setLocation(std::string location);

	std::string getEthnicity();

	void setEthnicity(std::string ethnicity);
};

#endif