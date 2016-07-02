#include <iostream>
#include "PhysicsController.h"

float PhysicsController::convertJumpSpeedUnits(const Character &character)
{
	float convertedJumpSpeed = (character.jumpSpeedInKmPerHour * 1000) / 3600; // 1km = 1000m and 1h = 3600s

	return convertedJumpSpeed;
}

float PhysicsController::getMaxJumpHeightInMeters(const Environment &environment, const Character &character)
{
	float convertedJumpSpeed = convertJumpSpeedUnits(character);
	float jumpHeight = (convertedJumpSpeed * convertedJumpSpeed) / (environment.gravity * 2);

	return jumpHeight;
}

float PhysicsController::getJumpDurationInSeconds(const Environment &environment, const Character &character)
{
	float convertedJumpSpeed = convertJumpSpeedUnits(character);
	float fallingTimeInSeconds = convertedJumpSpeed / environment.gravity;
	float timeInAirInseconds = fallingTimeInSeconds * 2; 
	// time to reach max height is the same amount as the time it takes for the character to fall down according to my google search results

	return timeInAirInseconds;
}

bool PhysicsController::canJumpOverObstacle(
	const Environment &environment,
	const Character &character,
	float heightOfObstacleInMeters)
{
	float maxJumpHeight = getMaxJumpHeightInMeters(environment, character);
	if (maxJumpHeight > heightOfObstacleInMeters)
	{
		return true;
	}

	return false;
}