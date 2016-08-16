#define _USE_MATH_DEFINES

#include <iostream>
#include "Circle.h"
#include "Object2D.h"

Circle::Circle(float radius)
{
	this->setRadius(radius);
}

float Circle::getRadius()
{
	return this->radius;
}

void Circle::setRadius(float radius)
{
	this->radius = radius;
}

float Circle::calculatePerimeter()
{
	return M_PI * this->getRadius() * 2;
}

float Circle::calculateSurface()
{
	return M_PI * this->getRadius() * this->getRadius();
}