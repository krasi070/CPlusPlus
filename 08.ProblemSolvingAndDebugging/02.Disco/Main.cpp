#include <iostream>
#include <thread>
#include <mutex>
#include <time.h>
#include <Windows.h>
#include <vector>

#define CAPACITY 100

int peopleInQueue = 0;
int numberOfFreeSpots = 100;
unsigned long secondsAfterStart = 0;
unsigned long long ticks = 0;
std::vector<std::thread> threads;
std::mutex securityLock;
std::mutex exitLock;
bool end = false;

void securityCheck();
void incomingPeople();
void leavingPeople();

int main()
{
	peopleInQueue = 50;
	threads = std::vector<std::thread>();
	ticks = clock();
	std::thread incoming = std::thread(incomingPeople);
	std::thread leaving = std::thread(leavingPeople);

	while (!end)
	{
		while (peopleInQueue > 0 && numberOfFreeSpots > 0)
		{
			std::thread thread = std::thread(securityCheck);
			thread.join();
			//threads.push_back(thread);
		}

		if (peopleInQueue == 0 && numberOfFreeSpots >= CAPACITY)
		{
			end = true;
		}
	} 

	for (int i = 0; i < threads.size(); i++)
	{
		threads[i].join();
	}

	incoming.join();
	leaving.join();

	std::cout << (double)((clock() - ticks) / CLOCKS_PER_SEC) << std::endl;

	return 0;
}

void securityCheck()
{
	while (numberOfFreeSpots <= 0)
	{
		Sleep(1);
	}

	securityLock.lock();
	peopleInQueue--;
	numberOfFreeSpots--;
	Sleep(30);
	securityLock.unlock();
}

void incomingPeople()
{
	while (!end)
	{
		Sleep(60);
		peopleInQueue += rand() % 5 + 1;
	}
}

void leavingPeople()
{
	while ((float)(clock() - ticks) / CLOCKS_PER_SEC < 5.4)
	{
		Sleep(1);
	}

	while (!end)
	{
		Sleep(60);
		numberOfFreeSpots += rand() % 9 + 2;
	}
}