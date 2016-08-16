#include <iostream>

#ifndef __OBJECT2D_H
#define __OBJECT2D_H

class Object2D
{
public:
	Object2D() { }

	virtual float calculatePerimeter() = 0;

	virtual float calculateSurface() = 0;
};

#endif