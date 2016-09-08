#include <iostream>

#define DEFAULT_LENGTH 100

char* stringReplace(const char* str, const char* what, const char* with);
int isWhat(const char* str, const char* what, int index);

int main()
{
	std::cout << "Text: ";
	char str[DEFAULT_LENGTH];
	std::cin.getline(str, DEFAULT_LENGTH);

	std::cout << "What: ";
	char what[DEFAULT_LENGTH];
	std::cin.getline(what, DEFAULT_LENGTH);

	std::cout << "With: ";
	char with[DEFAULT_LENGTH];
	std::cin.getline(with, DEFAULT_LENGTH);

	std::cout << "Result: ";
	char* result = stringReplace(str, what, with);
	int index = 0;
	while (result[index] != '\0')
	{
		std::cout << result[index];
		index++;
	}

	std::cout << std::endl;

	return 0;
}

char* stringReplace(const char* str, const char* what, const char* with)
{
	int index = 0;
	int resultIndex = 0;
	char* result = new char[DEFAULT_LENGTH];
	while (str[index] != '\0')
	{
		if (str[index] == what[0])
		{
			int newIndex = isWhat(str, what, index);
			if (newIndex != -1)
			{
				int withIndex = 0;
				while (with[withIndex] != '\0' && resultIndex < DEFAULT_LENGTH)
				{
					result[resultIndex] = with[withIndex];

					withIndex++;
					resultIndex++;
				}

				index += newIndex;
				continue;
			}
		}
		else
		{
			result[resultIndex] = str[index];
		}

		index++;
		resultIndex++;
	}

	int lastIndex = resultIndex >= 100 ? 99 : resultIndex;
	result[lastIndex] = '\0';

	return result;
}

int isWhat(const char* str, const char* what, int index)
{
	int whatIndex = 0;
	while (what[whatIndex] != '\0')
	{
		if (str[index + whatIndex] != what[whatIndex])
		{
			return -1;
		}

		if (str[index + whatIndex + 1] == '\0' && what[whatIndex + 1] != '\0')
		{
			return -1;
		}

		whatIndex++;
	}

	return whatIndex;
}