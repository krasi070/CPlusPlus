#include <iostream>
#include "Object.h"
#include "Environment.h"

#ifndef __PHYSICALOBJECT_H
#define __PHYSICALOBJECT_H

class PhysicalObject : public Object
{
private:
	float weightInGrams;
public:
	inline void setWeight(float weightInGrams)
	{
		this->weightInGrams = weightInGrams;
	}
};

#endif