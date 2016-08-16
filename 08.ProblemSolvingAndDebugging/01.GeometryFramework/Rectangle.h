#include <iostream>
#include "Object2D.h"

#ifndef __RECTANGLE_H
#define __RECTANGLE_H

class Rectangle : public Object2D 
{
private:
	float width;
	float height;
public:
	Rectangle() { }

	Rectangle(float width, float height);

	float getWidth();

	void setWidth(float width);

	float getHeight();

	void setHeight(float height);

	float calculatePerimeter();

	float calculateSurface();
};

#endif