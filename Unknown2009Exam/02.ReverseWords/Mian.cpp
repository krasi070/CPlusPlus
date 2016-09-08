#include <iostream>

void reverseWords(char* words);

int main()
{
	char words[100];
	std::cin.getline(words, 100);
	reverseWords(words);

	return 0;
}

void reverseWords(char* words)
{
	int i = 0;
	char currWord[100];
	int lengthOfCurrWord = 0;
	while (words[i] != '\0')
	{
		if ((words[i] < 'A' || words[i] > 'Z') &&
			(words[i] < 'a' || words[i] > 'z') &&
			words[i] != '-')
		{
			for (int j = lengthOfCurrWord - 1; j >= 0; j--)
			{
				std::cout << currWord[j];
			}

			lengthOfCurrWord = 0;
			std::cout << words[i];
		}
		else
		{
			currWord[lengthOfCurrWord] = words[i];
			lengthOfCurrWord++;
		}

		i++;
	}

	for (int j = lengthOfCurrWord - 1; j >= 0; j--)
	{
		std::cout << currWord[j];
	}

	std::cout << std::endl;
}