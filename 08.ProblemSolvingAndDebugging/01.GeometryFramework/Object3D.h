#include <iostream>

#ifndef __OBJECT3D_H
#define __OBJECT3D_H

class Object3D
{
public:
	Object3D() { }

	virtual float calculateSurface() = 0;

	virtual float calculateVolume() = 0;
};

#endif