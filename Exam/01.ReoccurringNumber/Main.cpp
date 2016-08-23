// Name: Krasimir Balchev
// Username: krasi070

#include <iostream>

int main()
{
	unsigned char numberCounter[256]; 
	for (int i = 0; i < 256; i++)
	{
		numberCounter[i] = 0;
	}

	for (int i = 0; i < 255; i++)
	{
		short int currNumber;
		std::cin >> currNumber;
		numberCounter[currNumber]++;
	}

	unsigned char mostReoccurringNumber = 0;
	unsigned char numberOfOccurances = numberCounter[0];
	for (int i = 1; i < 256; i++)
	{
		if (numberCounter[i] > numberOfOccurances ||
			(numberCounter[i] == numberOfOccurances && i > mostReoccurringNumber))
		{
			mostReoccurringNumber = i;
			numberOfOccurances = numberCounter[i];
		}
	}

	std::cout << ">" << (int)mostReoccurringNumber << std::endl;

	return 0;
}