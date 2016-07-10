#include <iostream>
#include <memory>
#include "Dog.h"
#include "Person.h"
#include "Friend.h"

int main()
{
	std::unique_ptr<Person> person(new Person());
	std::unique_ptr<Friend> personsFriend(new Friend());
	person->dog = std::shared_ptr<Dog>(new Dog());
	personsFriend->dog = person->dog;
	person->dog = nullptr;

	return 0;
}