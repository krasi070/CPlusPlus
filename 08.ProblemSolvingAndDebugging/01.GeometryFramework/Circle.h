#include <iostream>
#include "Object2D.h"

#ifndef __CIRCLE_H
#define __CIRCLE_H

class Circle : public Object2D
{
private:
	float radius;
public:
	Circle() { }

	Circle(float radius);

	float getRadius();

	void setRadius(float radius);

	float calculatePerimeter();

	float calculateSurface();
};

#endif