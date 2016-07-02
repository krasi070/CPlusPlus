#include <iostream>
#include "PhysicsController.h"
#include "PhysicalObject.h"

float PhysicsController::getFinalSpeedOfFallingPhysicalObject(
	const PhysicalObject &object, 
	double fallingTimeInSec)
{
	float vFinal = environment.gravity * fallingTimeInSec;

	return vFinal;
}