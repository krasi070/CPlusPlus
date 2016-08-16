#include <iostream>
#include "Object3D.h"

#ifndef __PARALLELEPIPED_H
#define __PARALLELEPIPED_H

class Parallelepiped : public Object3D
{
private:
	float width;
	float height;
	float length;
public:
	Parallelepiped() { }

	Parallelepiped(float width, float height, float length);

	float getWidth();

	void setWidth(float width);

	float getHeight();

	void setHeight(float height);

	float getLength();

	void setLength(float length);

	float calculateSurface();

	float calculateVolume();
};

#endif