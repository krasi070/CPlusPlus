#include <iostream>
#include "Rectangle.h"

#ifndef __SQUARE_H
#define __SQUARE_H

class Square : public Rectangle
{
public:
	Square() { }

	Square(float side) : Rectangle(side, side) { }
};

#endif