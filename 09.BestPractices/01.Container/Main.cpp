#include <iostream>
#include <vector>
#include "Container.h"

int main()
{
	int values[10] = { 14, 11, 2, 0, 1, 4, 5, 8, 20, -5 };
	Container<int, sizeof(values) / sizeof(values[0])> container(values);
	container.add(100);
	container.sort();
	container.print();
	
	return 0;
} 
