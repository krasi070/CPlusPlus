#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define DEFAULT_MAX_SIZE 100

bool arePermutations(int* row1, int* row2, int size);

int main()
{
	int size;
	std::cout << "Size [1, " << DEFAULT_MAX_SIZE << "]: ";
	std::cin >> size;
	std::cin.ignore();
	while (size <= 0 || size > DEFAULT_MAX_SIZE)
	{
		std::cout << "Size [1, " << DEFAULT_MAX_SIZE << "]: ";
		std::cin >> size;
		std::cin.ignore();
	}

	int matrix[DEFAULT_MAX_SIZE][DEFAULT_MAX_SIZE];
	for (int i = 0; i < size; i++)
	{
		int spaceCounter;
		do
		{
			spaceCounter = 0;
			std::cout << "Row " << i << ": ";
			std::string currRow;
			std::getline(std::cin, currRow);
			std::string currElement = "";
			for (int j = 0; j < currRow.size(); j++)
			{
				if (currRow[j] == '-' && currElement == "")
				{
					currElement = "-";
					continue;
				}

				if (currRow[j] >= '0' && currRow[j] <= '9')
				{
					currElement += currRow[j];
					if (j == currRow.size() - 1)
					{
						matrix[i][spaceCounter] = std::stoi(currElement);
						spaceCounter++;
					}
				}
				else
				{
					if (currRow[j] == ' ' && currElement != "")
					{
						matrix[i][spaceCounter] = std::stoi(currElement);
						currElement = "";
						spaceCounter++;
						if (spaceCounter >= size)
						{
							break;
						}
					}
					else
					{
						break;
					}
				}
			}
		} while (spaceCounter < size);
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arePermutations(matrix[i], matrix[j], size))
			{
				std::cout << "Row " << i << " and Row " << j << " are permuatations of one another." << std::endl;
			}
		}
	}

	int diagonal1[DEFAULT_MAX_SIZE];
	for (int i = 0; i < size; i++)
	{
		diagonal1[i] = matrix[i][i];
	}

	int diagonal2[DEFAULT_MAX_SIZE];
	for (int i = 0; i < size; i++)
	{
		diagonal2[i] = matrix[i][size - i - 1];
	}

	if (arePermutations(diagonal1, diagonal2, size))
	{
		std::cout << "The diagonals are permutations of one another." << std::endl;
	}

	return 0;
}

bool arePermutations(int* row1, int* row2, int size)
{
	std::vector<int> vector1(row1, row1 + size);
	std::vector<int> vector2(row2, row2 + size);
	std::sort(vector1.begin(), vector1.end());
	std::sort(vector2.begin(), vector2.end());
	for (int i = 0; i < size; i++)
	{
		if (vector1[i] != vector2[i])
		{
			return false;
		}
	}

	return true;
}