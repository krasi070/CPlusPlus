#include <iostream>
#include "Parallelepiped.h"

#ifndef __CUBE_H
#define __CUBE_H

class Cube : public Parallelepiped
{
public:
	Cube() { }

	Cube(float side) : Parallelepiped(side, side, side) { }
};

#endif