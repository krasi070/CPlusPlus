#include <iostream>
#include <math.h>
#include <thread>
#include <chrono>
#include <mutex>

bool isPrime(unsigned long long number);
void findPrimes();
unsigned long long getFibonacci(int fibPlace);
void printFibonacciNumbers();

std::mutex mutex;

// I tried clock() and std::chrono::high_resolution_clock::now() both of them don't work.
// I'd be really grateful if you could tell me a way to get precise time.
int main()
{
	std::thread findPrimes(findPrimes);
	std::thread printFibonacciNumbers(printFibonacciNumbers);

	findPrimes.join();
	printFibonacciNumbers.join();

	return 0;
}

bool isPrime(unsigned long long number)
{
	unsigned long long square = sqrt(number);
	for (unsigned long long i = 2; i <= square; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}

	return true;
}

void findPrimes()
{
	auto begin = std::chrono::high_resolution_clock::now();
	for (unsigned long long i = 1; i <= ULLONG_MAX; i++)
	{
		if (isPrime(i))
		{
			auto end = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
			//std::this_thread::sleep_for(std::chrono::milliseconds(500));

			mutex.lock();
			std::cout << "New prime found: " << i << ", Time: " << duration << " ns" << std::endl;
			mutex.unlock();

			begin = std::chrono::high_resolution_clock::now();
		}
	}
}

unsigned long long getFibonacci(int fibPlace)
{
	if (fibPlace == 0 || fibPlace == 1)
	{
		return 1;
	}

	return getFibonacci(fibPlace - 2) + getFibonacci(fibPlace - 1);
}

void printFibonacciNumbers()
{
	int fibonacciPlace = 0;
	unsigned long long currFibonacci = 0;
	unsigned long long stopPoint = ULLONG_MAX / 2;
	while (currFibonacci <= stopPoint)
	{
		auto begin = std::chrono::high_resolution_clock::now();
		currFibonacci = getFibonacci(fibonacciPlace);
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();

		//std::this_thread::sleep_for(std::chrono::milliseconds(500));

		mutex.lock();
		std::cout << "Fibonacci: " << currFibonacci << ", Time: " << duration << " ns" << std::endl;
		mutex.unlock();

		fibonacciPlace++;
	}
}