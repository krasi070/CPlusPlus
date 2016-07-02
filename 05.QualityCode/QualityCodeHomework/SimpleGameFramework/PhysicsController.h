#include <iostream>
#include "Character.h"
#include "Environment.h"

#ifndef __PHYSICSCONTROLLER_H
#define __PHYSICSCONTROLLER_H

class PhysicsController
{
private:
	float convertJumpSpeedUnits(const Character &character);
public:
	PhysicsController() {}
	float getMaxJumpHeightInMeters(const Environment &environment, const Character &character);
	float getJumpDurationInSeconds(const Environment &environment, const Character &character);
	bool canJumpOverObstacle(const Environment &environment, const Character &character, float heightOfObstacleInMeters);
};

#endif