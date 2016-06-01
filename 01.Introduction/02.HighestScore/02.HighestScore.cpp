/*HIGHEST SCORE
You are given a person's name and their age on a seperate line.
That person's score is equal to the sum of the digits in their age and if 
a char's ASCII code from their name is even then it is added to the score
and if it's odd it's subtracted (minimum score is 0). You are given names and ages until you receive the
command stop. After the stop command you must print the person with the highest score.
EXAMPLE:
Jimmy
12
Timmy
12
Bob
100
stop*/

#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include<string>

int sumOfDigits(int number);
int calculateScore(std::string name, int age);

int main()
{
	int maxScore = -1;
	std::string winnerName;
	std::string name;
	getline(std::cin, name);
	while (name != "stop")
	{
		std::string inputAge;
		getline(std::cin, inputAge);
		int age = std::stoi(inputAge);
		int currScore = calculateScore(name, age);
		if (currScore > maxScore)
		{
			maxScore = currScore;
			winnerName.assign(name);
		}

		getline(std::cin, name);
	}

	std::cout << "Highest Score: " << std::endl << winnerName << " -> " << maxScore << std::endl;

	return 0;
}

int sumOfDigits(int number)
{
	int sum = 0;
	while (number != 0)
	{
		sum += number % 10;
		number /= 10;
	}

	return sum;
}

int calculateScore(std::string name, int age)
{
	int score = sumOfDigits(age);
	for (int i = 0; i < name.length(); i++)
	{
		if (name[i] % 2 == 0)
		{
			score += name[i];
		}
		else
		{
			score -= name[i];
		}
	}

	if (score < 0)
	{
		return 0;
	}

	return score;
}