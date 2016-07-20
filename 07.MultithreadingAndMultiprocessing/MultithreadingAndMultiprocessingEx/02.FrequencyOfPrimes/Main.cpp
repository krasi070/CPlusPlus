#include <iostream>
#include <math.h>
#include <time.h>

int calculateFrequencyOfPrimes(int n);

int main()
{
	unsigned long long startClock = clock();
	int frequencyOfPrimes = 0;
	for (int i = 0; i < 10; ++i)
	{
		frequencyOfPrimes = calculateFrequencyOfPrimes(100000);
	}

	printf("Frequency of primes: %d\n", frequencyOfPrimes);
	printf("Time: %0.4f sec\n", (float)(clock() - startClock) / CLOCKS_PER_SEC);

	return 0;
}

int calculateFrequencyOfPrimes(int n)
{
	int frequency = n - 1;
	for (int i = 2; i <= n; ++i)
	{
		int squareOfI = sqrt(i);
		for (int j = 2; j <= squareOfI; ++j)
		{
			if (i % j == 0)
			{
				--frequency;
				break;
			}
		}
	}

	return frequency;
}