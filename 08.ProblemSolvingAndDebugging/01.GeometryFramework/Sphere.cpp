#define _USE_MATH_DEFINES

#include <iostream>
#include "Sphere.h"

Sphere::Sphere(float radius)
{
	this->setRadius(radius);
}

float Sphere::getRadius()
{
	return this->radius;
}

void Sphere::setRadius(float radius)
{
	this->radius = radius;
}

float Sphere::calculateSurface()
{
	return 4 * M_PI * this->getRadius() * this->getRadius();
}

float Sphere::calculateVolume()
{
	return (4 * M_PI * this->getRadius() * this->getRadius() * this->getRadius()) / 3;
}