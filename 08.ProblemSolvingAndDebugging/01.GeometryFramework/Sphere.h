#include <iostream>
#include "Object3D.h"

#ifndef __SPHERE_H
#define __SPHERE_H

class Sphere : public Object3D
{
private:
	float radius;
public:
	Sphere() { }

	Sphere(float radius);

	float getRadius();

	void setRadius(float radius);

	float calculateSurface();

	float calculateVolume();
};

#endif