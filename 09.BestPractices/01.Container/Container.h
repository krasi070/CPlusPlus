#include <iostream>
#include <vector>
#include <algorithm>

#ifndef __CONTAINER_H
#define __CONTAINER_H

template<class T, int size>
class Container
{
private:
	std::vector<T> values;
public:
	Container(T* values)
	{
		for (int i = 0; i < size; i++)
		{
			this->values.push_back(values[i]);
		}
	}

	void printElementByIndex(int index)
	{
		std::cout << "Element " << index << ": " << this->values[index] << std::endl;
	}

	void add(T element)
	{
		this->values.push_back(element);
	}

	void sort()
	{
		std::sort(this->values.begin(), this->values.end());
	}

	void print()
	{
		for (int i = 0; i < this->values.size() - 1; i++)
		{
			std::cout << this->values[i] << ", ";
		}

		std::cout << this->values[this->values.size() - 1] << std::endl;
	}
};

#endif