#include <iostream>
#include <thread>

void func();

int main()
{
	std::thread thread(func);
	thread.join();

	return 0;
}

void func()
{
	std::cout << "A new thread has been created!" << std::endl;
}