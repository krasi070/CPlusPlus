#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle(float width, float height)
{
	this->setWidth(width);
	this->setHeight(height);
}

float Rectangle::getWidth()
{
	return this->width;
}

void Rectangle::setWidth(float width)
{
	this->width = width;
}

float Rectangle::getHeight()
{
	return this->height;
}

void Rectangle::setHeight(float height)
{
	this->height = height;
}

float Rectangle::calculatePerimeter()
{
	return 2 * (this->getWidth() + this->getHeight());
}

float Rectangle::calculateSurface()
{
	return this->getWidth() * this->getHeight();
}