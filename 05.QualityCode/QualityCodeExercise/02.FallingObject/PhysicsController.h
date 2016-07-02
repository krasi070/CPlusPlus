#include <iostream>
#include "PhysicalObject.h"
#include "Environment.h"

#ifndef __PHYSICSCONTROLLER_H
#define __PHYSICSCONTROLLER_H

class PhysicsController
{
private:
	Environment environment;
public:
	PhysicsController() {}
	PhysicsController(Environment environment) :
		environment(environment) {}

	float getFinalSpeedOfFallingPhysicalObject(const PhysicalObject &object, double fallingTimeInSec);
};

#endif