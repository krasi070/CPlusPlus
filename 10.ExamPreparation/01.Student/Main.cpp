#include <iostream>
#include <string>
#include "Student.h"
#include "CourseContainer.h"

void searchForStudent(std::string facultyNumber, CourseContainer courseContainer);

int main()
{
	Student* student1 = new Student();
	student1->setName("Krasi");
	student1->setFacultyNumber("123456");
	student1->setGroup(GROUP_42);

	Student* student2 = new Student();
	student2->setName("Prasi");
	student2->setFacultyNumber("1234567");
	student2->setGroup(GROUP_41);

	Student* student3 = new Student();
	student3->setName("Frasi");
	student3->setFacultyNumber("1234568");
	student3->setGroup(GROUP_43);

	CourseContainer courseContainer;
	courseContainer.studentsContainer.push_back(std::shared_ptr<Student>(student1));
	courseContainer.studentsContainer.push_back(std::shared_ptr<Student>(student2));
	courseContainer.studentsContainer.push_back(std::shared_ptr<Student>(student3));
	
	std::thread thread(searchForStudent, "1234567", courseContainer);
	thread.join();

	return 0;
}

void searchForStudent(std::string facultyNumber, CourseContainer courseContainer)
{
	courseContainer.searchByFacultyNumber(facultyNumber);
}