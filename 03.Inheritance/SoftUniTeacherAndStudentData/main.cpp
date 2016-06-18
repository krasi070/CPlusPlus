#include <iostream>
#include <string>
#include "CurrentCourse.h"
#include "SoftUniPerson.h"
#include "Student.h"
#include "Teacher.h"
#include "GuestTeacher.h"

void getStudentById(Student students[], std::string courses[], unsigned short studentCount, int id);
void getTeacherById(Teacher teachers[], std::string courses[], unsigned short teacherCount, int id);
void getGuestTeacherById(GuestTeacher guestTeachers[], std::string courses[], unsigned short guestTeacherCount, int id);
CurrentCourse getCurrCourse(std::string course, std::string courses[], int numberOfCourses);
void addStudent(Student students[], unsigned short studentCount, std::string courses[], int coursesCount);
void addGuestTeacher(GuestTeacher guestTeachers[], unsigned short guestTeacherCount, std::string courses[], int coursesCount);
void addTeacher(Teacher teachers[], unsigned short teacherCount, std::string courses[], int coursesCount);
bool checkIfStudentIdExists(Student students[], unsigned short studentCount, int id);
bool checkIfTeacherIdExists(Teacher teachers[], unsigned short teacherCount, int id);
bool checkIfGuestTeacherIdExists(GuestTeacher guestTeachers[], unsigned short guestTeacherCount, int id);

// Check CurrentCourse.h for valid courses.
// Wasn't able to make maximum capacity 65535. I think I can't store that much space.
// But if I'm wrong I'd be happy if you could tell me where I got it wrong.
int main()
{
	Student students[6553];
	unsigned short studentCount = 0;
	Teacher teachers[6553];
	unsigned short teacherCount = 0;
	GuestTeacher guestTeachers[6553];
	unsigned short guestTeacherCount = 0;

	// array for courses
	int coursesCount = 6;
	std::string courses[6] =
	{
		"ProgrammingBasics",
		"ProgrammingFundamentals",
		"CPlusPlus",
		"SoftwareTechnologies",
		"CSharpAdvanced",
		"JavaBasics"
	};

	// default students
	students[0] = Student(1, "Morty", CPlusPlus, 0, 3.00);
	students[1] = Student(2, "Summer", JavaBasics, 50, 5.33);
	students[2] = Student(3, "Tiny Rick", CSharpAdvanced, 20, 6.00);
	studentCount = 3;
	// default teavhers
	teachers[0] = Teacher(1, "Mr. Goldenfold", CPlusPlus, 1.01, 2);
	teachers[1] = Teacher(2, "Teacher Rick", ProgrammingFundamentals, 1000.99, 100);
	teacherCount = 2;
	// default guest teachers
	guestTeachers[0] = GuestTeacher(1, "Mr. Garrison", ProgrammingBasics, 100);

	while (true)
	{
		std::cout << "1. Get data for student with ID" << std::endl <<
			"2. Get data for teacher with ID" << std::endl <<
			"3. Get data for guest teacher with ID" << std::endl <<
			"4. Add data for new student" << std::endl <<
			"5. Add data for new teacher" << std::endl <<
			"6. Add data for new guest teacher" << std::endl <<
			"Enter number: ";

		int choice;
		std::cin >> choice;
		std::cin.ignore();
		std::system("cls");
		switch (choice)
		{
		case 1:
			std::cout << "Enter ID: ";
			int id;
			std::cin >> id;
			std::cin.ignore();
			getStudentById(students, courses, studentCount, id);
			break;
		case 2:
			std::cout << "Enter ID: ";
			int id1;
			std::cin >> id1;
			std::cin.ignore();
			getTeacherById(teachers, courses, teacherCount, id1);
			break;
		case 3:
			std::cout << "Enter ID: ";
			int id2;
			std::cin >> id2;
			std::cin.ignore();
			getGuestTeacherById(guestTeachers, courses, guestTeacherCount, id2);
			break;
		case 4:
			addStudent(students, studentCount, courses, coursesCount);
			studentCount++;
			break;
		case 5:
			addTeacher(teachers, teacherCount, courses, coursesCount);
			teacherCount++;
			break;
		case 6:
			addGuestTeacher(guestTeachers, guestTeacherCount, courses, coursesCount);
			guestTeacherCount++;
			break;
		}

		std::cout << std::endl << "PRESS ANY KEY TO CONTINUE";
		std::cin.ignore();
		std::system("cls");
	}

	return 0;
}

void getStudentById(Student students[], std::string courses[], unsigned short studentCount, int id)
{
	for (int i = 0; i < studentCount; i++)
	{
		if (students[i].id == id)
		{
			std::cout << "Student ID: " << students[i].id << std::endl <<
				"Name: " << students[i].name << std::endl <<
				"Current Course: " << courses[students[i].currCourse] << std::endl <<
				"Current Points: " << students[i].currPoints << std::endl <<
				"Average Evaluation Mark: " << students[i].averageEvaluationMark << std::endl;
			return;
		}
	}

	std::cout << "No student with id " << id << " exists." << std::endl;
}

void getTeacherById(Teacher teachers[], std::string courses[], unsigned short teacherCount, int id)
{
	for (int i = 0; i < teacherCount; i++)
	{
		if (teachers[i].id == id)
		{
			std::cout << "Teacher ID: " << teachers[i].id << std::endl <<
				"Name: " << teachers[i].name << std::endl <<
				"Current Course: " << courses[teachers[i].currCourse] << std::endl <<
				"Monthly Salary: " << teachers[i].monthlySalary << std::endl <<
				"Days passed since they joined SoftUni: " << teachers[i].daysInSoftUni << std::endl;
			return;
		}
	}

	std::cout << "No teacher with id " << id << " exists." << std::endl;
}

void getGuestTeacherById(GuestTeacher guestTeachers[], std::string courses[], unsigned short guestTeacherCount, int id)
{
	for (int i = 0; i < guestTeacherCount; i++)
	{
		if (guestTeachers[i].id == id)
		{
			std::cout << "Guest Teacher ID: " << guestTeachers[i].id << std::endl <<
				"Name: " << guestTeachers[i].name << std::endl <<
				"Current Course: " << courses[guestTeachers[i].currCourse] << std::endl <<
				"Salary for Course: " << guestTeachers[i].salaryForCourse << std::endl;
			return;
		}
	}

	std::cout << "No guest teacher with id " << id << " exists." << std::endl;
}

void addStudent(Student students[], unsigned short studentCount, std::string courses[], int coursesCount)
{
	std::cout << "Enter ID: ";
	unsigned short id;
	std::cin >> id;
	std::cin.ignore();
	while (checkIfStudentIdExists(students, studentCount, id))
	{
		std::cout << "ID is in use! Enter ID: ";
		std::cin >> id;
		std::cin.ignore();
	}

	std::cout << "Enter name: ";
	std::string name;
	getline(std::cin, name);
	std::cout << "Enter current course: ";
	std::string course;
	getline(std::cin, course);
	CurrentCourse currCourse = getCurrCourse(course, courses, coursesCount);
	while (currCourse == Invalid)
	{

		std::cout << "Invalid course name! Enter current course: ";
		std::string course;
		getline(std::cin, course);
		CurrentCourse currCourse = getCurrCourse(course, courses, coursesCount);
	}

	std::cout << "Enter current points (0 - 100): ";
	int currPoints;
	std::cin >> currPoints;
	std::cin.ignore();
	while (currPoints < 0 || currPoints > 100)
	{
		std::cout << "Enter current points (0 - 100): ";
		std::cin >> currPoints;
		std::cin.ignore();
	}

	std::cout << "Enter average evaluation mark (2.00 - 6.00): ";
	float mark;
	std::cin >> mark;
	std::cin.ignore();
	while (mark < 2 || mark > 6)
	{
		std::cout << "Enter average evaluation mark (2.00 - 6.00): ";
		std::cin >> mark;
		std::cin.ignore();
	}

	students[studentCount] = Student(id, name, currCourse, currPoints, mark);
}

void addTeacher(Teacher teachers[], unsigned short teacherCount, std::string courses[], int coursesCount)
{
	std::cout << "Enter ID: ";
	unsigned short id;
	std::cin >> id;
	std::cin.ignore();
	while (checkIfTeacherIdExists(teachers, teacherCount, id))
	{
		std::cout << "ID is in use! Enter ID: ";
		std::cin >> id;
		std::cin.ignore();
	}

	std::cout << "Enter name: ";
	std::string name;
	getline(std::cin, name);
	std::cout << "Enter current course: ";
	std::string course;
	getline(std::cin, course);
	CurrentCourse currCourse = getCurrCourse(course, courses, coursesCount);
	while (currCourse == Invalid)
	{
		std::cout << "Enter current course: ";
		std::string course;
		getline(std::cin, course);
		CurrentCourse currCourse = getCurrCourse(course, courses, coursesCount);
	}

	std::cout << "Enter monthly salary: ";
	double monthlySalary;
	std::cin >> monthlySalary;
	std::cin.ignore();
	std::cout << "Enter days in SoftUni: ";
	unsigned short days;
	std::cin >> days;
	std::cin.ignore();

	teachers[teacherCount] = Teacher(id, name, currCourse, monthlySalary, days);
}

void addGuestTeacher(GuestTeacher guestTeachers[], unsigned short guestTeacherCount, std::string courses[], int coursesCount)
{
	std::cout << "Enter ID: ";
	unsigned short id;
	std::cin >> id;
	std::cin.ignore();
	while (checkIfGuestTeacherIdExists(guestTeachers, guestTeacherCount, id))
	{
		std::cout << "ID is in use! Enter ID: ";
		std::cin >> id;
		std::cin.ignore();
	}

	std::cout << "Enter name: ";
	std::string name;
	getline(std::cin, name);
	std::cout << "Enter current course: ";
	std::string course;
	getline(std::cin, course);
	CurrentCourse currCourse = getCurrCourse(course, courses, coursesCount);
	while (currCourse == Invalid)
	{
		std::cout << "Enter current course: ";
		std::string course;
		getline(std::cin, course);
		CurrentCourse currCourse = getCurrCourse(course, courses, coursesCount);
	}

	std::cout << "Enter monthly salary: ";
	double salaryForCourse;
	std::cin >> salaryForCourse;
	std::cin.ignore();

	guestTeachers[guestTeacherCount] = GuestTeacher(id, name, currCourse, salaryForCourse);
}

CurrentCourse getCurrCourse(std::string course, std::string courses[], int numberOfCourses)
{
	for (int i = 0; i < numberOfCourses; i++)
	{
		if (courses[i] == course)
		{
			return (CurrentCourse)i;
		}
	}

	return (CurrentCourse)Invalid;
}

bool checkIfStudentIdExists(Student students[], unsigned short studentCount, int id)
{
	for (int i = 0; i < studentCount; i++)
	{
		if (students[i].id == id)
		{
			return true;
		}
	}

	return false;
}

bool checkIfTeacherIdExists(Teacher teachers[], unsigned short teacherCount, int id)
{
	for (int i = 0; i < teacherCount; i++)
	{
		if (teachers[i].id == id)
		{
			return true;
		}
	}

	return false;
}

bool checkIfGuestTeacherIdExists(GuestTeacher guestTeachers[], unsigned short guestTeacherCount, int id)
{
	for (int i = 0; i < guestTeacherCount; i++)
	{
		if (guestTeachers[i].id == id)
		{
			return true;
		}
	}

	return false;
}