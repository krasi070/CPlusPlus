#include <iostream>
#include <math.h>
#include <time.h>
#include <thread>
#include <vector>
#include <mutex>

int calculateFrequencyOfPrimes(int n);
void printFrequencyOfPrimes(int n);

std::mutex mtx;

int main()
{
	unsigned long long startClock = clock();
	std::vector<std::thread> threads;
	for (int i = 0; i < 10; ++i)
	{
		threads.push_back(std::thread(printFrequencyOfPrimes, 100000));
	}

	for (int i = 0; i < threads.size(); ++i)
	{
		threads[i].join();
	}

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

void printFrequencyOfPrimes(int n)
{
	mtx.lock();
	std::cout << "Frequency: " << calculateFrequencyOfPrimes(n) << std::endl;
	mtx.unlock();
}