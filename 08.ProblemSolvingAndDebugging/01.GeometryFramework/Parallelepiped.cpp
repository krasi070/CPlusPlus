#include <iostream>
#include "Parallelepiped.h"
#include "Object3D.h"

Parallelepiped::Parallelepiped(float width, float height, float length)
{
	this->setWidth(width);
	this->setHeight(height);
	this->setLength(length);
}

float Parallelepiped::getWidth()
{
	return this->width;
}

void Parallelepiped::setWidth(float width)
{
	this->width = width;
}

float Parallelepiped::getHeight()
{
	return this->height;
}

void Parallelepiped::setHeight(float height)
{
	this->height = height;
}

float Parallelepiped::getLength()
{
	return this->length;
}

void Parallelepiped::setLength(float length)
{
	this->length = length;
}

float Parallelepiped::calculateSurface()
{
	return 2 * (this->getWidth() * this->getHeight() +
		this->getWidth() * this->getLength() +
		this->getHeight() * this->getLength());
}

float Parallelepiped::calculateVolume()
{
	return this->getWidth() * this->getHeight() * this->getLength();
}