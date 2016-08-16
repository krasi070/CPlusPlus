#include <iostream>
#include "Circle.h"
#include "Cube.h"
#include "Parallelepiped.h"
#include "Rectangle.h"
#include "Sphere.h"
#include "Square.h"

int main()
{
	std::cout << "-------------------------------------------------------------" << std::endl;

	Square square = Square(12);
	std::cout << "SQUARE:" << std::endl <<
		"--Side: " << square.getWidth() << std::endl <<
		"--Perimeter: " << square.calculatePerimeter() << std::endl <<
		"--Surface: " << square.calculateSurface() << std::endl <<
		"-------------------------------------------------------------" << std::endl;

	Rectangle rectangle = Rectangle(10, 5);
	std::cout << "RECTANGLE:" << std::endl <<
		"--Width: " << rectangle.getWidth() << std::endl <<
		"--Height: " << rectangle.getHeight() << std::endl <<
		"--Perimeter: " << rectangle.calculatePerimeter() << std::endl <<
		"--Surface: " << rectangle.calculateSurface() << std::endl <<
		"-------------------------------------------------------------" << std::endl;

	Circle circle = Circle(7);
	std::cout << "CIRCLE:" << std::endl <<
		"--Radius: " << circle.getRadius() << std::endl <<
		"--Perimeter: " << circle.calculatePerimeter() << std::endl <<
		"--Surface: " << circle.calculateSurface() << std::endl <<
		"-------------------------------------------------------------" << std::endl;

	Cube cube = Cube(4);
	std::cout << "CUBE:" << std::endl <<
		"--Side: " << cube.getWidth() << std::endl <<
		"--Surface: " << cube.calculateSurface() << std::endl <<
		"--Volume: " << cube.calculateVolume() << std::endl <<
		"-------------------------------------------------------------" << std::endl;

	Parallelepiped parallelepiped = Parallelepiped(10, 8, 6);
	std::cout << "PARALLELEPIPED:" << std::endl <<
		"--Width: " << parallelepiped.getWidth() << std::endl <<
		"--Height: " << parallelepiped.getHeight() << std::endl <<
		"--Length: " << parallelepiped.getLength() << std::endl <<
		"--Surface: " << parallelepiped.calculateSurface() << std::endl <<
		"--Volume: " << parallelepiped.calculateVolume() << std::endl <<
		"-------------------------------------------------------------" << std::endl;

	Sphere sphere = Sphere(5);
	std::cout << "SPHERE:" << std::endl <<
		"--Radius: " << sphere.getRadius() << std::endl <<
		"--Surface: " << sphere.calculateSurface() << std::endl <<
		"--Volume: " << sphere.calculateVolume() << std::endl <<
		"-------------------------------------------------------------" << std::endl;

	return 0;
}