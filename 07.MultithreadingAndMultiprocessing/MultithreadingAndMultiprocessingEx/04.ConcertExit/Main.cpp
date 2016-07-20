#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>

void exitConcert(int n);

std::mutex mutex;

int main()
{
	unsigned long long startClock = clock();
	std::vector<std::thread> people;
	for (int i = 1; i <= 10000; i++)
	{
		people.push_back(std::thread(exitConcert, i));
	}

	for (int i = 0; i < people.size(); i++)
	{
		people[i].join();
	}

	float time = (float)(clock() - startClock) / CLOCKS_PER_SEC;
	printf("Time: %0.4f\n", time);
}

void exitConcert(int n)
{
	mutex.lock();

	std::this_thread::sleep_for(std::chrono::milliseconds(20));
	std::cout << "Person " << n << " exited the concert hall." << std::endl;

	mutex.unlock();
}