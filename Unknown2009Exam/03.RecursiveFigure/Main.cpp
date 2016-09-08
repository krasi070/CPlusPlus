#include <iostream>
#include <string>

void printRow(int n, int distance, int count = 1);
void printElementLeft(int n, int count, int currCount = 0);
void printElementRight(int n, int count, int currCount);

int main()
{
	int n;
	do
	{
		std::cout << "N: ";
		std::cin >> n;
	} while (n < 0 || n > 40);
	
	int count = 1;
	int distance = n - 1;
	if (n > 9)
	{
		distance += 9;
		distance += (n - 10) * 2;
	}
	else
	{
		distance += n - 1;
	}

	distance *= 2;
	printRow(n, distance);

	return 0;
}

void printRow(int n, int distance, int count)
{
	if (count > n)
	{
		return;
	}

	printElementLeft(n, count);
	std::cout << std::string(distance, ' ');
	printElementRight(n, count, count);

	if (n - count >= 10)
	{
		distance -= 6;
	}
	else
	{
		distance -= 4;
	}

	std::cout << std::endl;

	printRow(n, distance, count + 1);
}

void printElementLeft(int n, int count, int currCount)
{
	if (currCount == count)
	{
		return;
	}

	std::cout << n - currCount << " ";
	
	printElementLeft(n, count, currCount + 1);
}

void printElementRight(int n, int count, int currCount)
{
	if (currCount == 0)
	{
		return;
	}

	std::cout << n - currCount + 1 << " ";
	
	printElementRight(n, count, currCount - 1);
}