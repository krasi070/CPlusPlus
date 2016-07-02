#include <iostream>
#include "Character.h"
#include "Environment.h"
#include "PhysicsController.h"

#define EARTH_GRAVITY 9.81
#define MOON_GRAVITY 1.622

int main()
{
	Character cube = Character("Cube", 5, 25, 123);
	Environment earth = Environment(137, "Earth", EARTH_GRAVITY);
	PhysicsController controller = PhysicsController();

	float maxJumpHeightOnEarth = controller.getMaxJumpHeightInMeters(earth, cube);
	float timeInAirOnEarth = controller.getJumpDurationInSeconds(earth, cube);
	float bookHeight = 0.05;
	bool canJumpOverBookOnEarth = controller.canJumpOverObstacle(earth, cube, bookHeight);
	std::cout << "EARTH:" << std::endl <<
		"--max jump height: " << maxJumpHeightOnEarth << " meters" << std::endl <<
		"--time in air: " << timeInAirOnEarth << " seconds" << std::endl <<
		"--can jump over book: " << (canJumpOverBookOnEarth ? "Yes" : "No") << std::endl;
	std::cout << std::endl;

	Environment moon = Environment(321, "Moon", MOON_GRAVITY);
	float maxJumpHeightOnTheMoon = controller.getMaxJumpHeightInMeters(moon, cube);
	float timeInAirOnTheMoon = controller.getJumpDurationInSeconds(moon, cube);
	bool canJumpOverBookOnTheMoon = controller.canJumpOverObstacle(moon, cube, bookHeight);
	std::cout << "MOON:" << std::endl <<
		"--max jump height: " << maxJumpHeightOnTheMoon << " meters" << std::endl <<
		"--time in air: " << timeInAirOnTheMoon << " seconds" << std::endl <<
		"--can jump over book: " << (canJumpOverBookOnTheMoon ? "Yes" : "No") << std::endl;

	return 0;
}