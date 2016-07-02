#include <iostream>
#include "Object.h"
#include "Environment.h"
#include "PhysicalObject.h"
#include "PhysicsController.h"

#define EARTH_GRAVITY 9.81
#define MOON_GRAVITY 1.622

int main()
{
	PhysicalObject obj;
	obj.setWeight(100);

	Environment earth = Environment(EARTH_GRAVITY);
	PhysicsController controller = PhysicsController(earth);
	std::cout << "Final speed with earth gravity: " << controller.getFinalSpeedOfFallingPhysicalObject(obj, 30) << std::endl;

	Environment moon = Environment(MOON_GRAVITY);
	PhysicsController moonController = PhysicsController(moon);
	std::cout << "Final speed with moon gravity: " << moonController.getFinalSpeedOfFallingPhysicalObject(obj, 30) << std::endl;

	return 0;
}