#include "stdafx.h"
#include<iostream>
#include<string>
#include<stdio.h>

int main()
{
	std::string line;
	getline(std::cin, line);
	int upperCaseCount = 0;
	int lowerCaseCount = 0;
	int otherCount = 0;
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] >= 'a' && line[i] <= 'z')
		{
			lowerCaseCount++;
		}
		else if (line[i] >= 'A' && line[i] <= 'Z')
		{
			upperCaseCount++;
		}
		else
		{
			otherCount++;
		}
	}

	printf("Upper Case: %d\nLower Case: %d\nOther: %d\n", upperCaseCount, lowerCaseCount, otherCount);

	return 0;
}