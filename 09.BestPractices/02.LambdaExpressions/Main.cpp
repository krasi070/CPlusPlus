#include <iostream>
#include <vector>
#include <algorithm>

void callLambda(void lambda());

int main()
{
	std::vector<int> vector;
	vector.push_back(10);
	vector.push_back(11);
	vector.push_back(12);
	vector.push_back(13);
	vector.push_back(14);
	vector.push_back(15);
	int count = 1;
	std::for_each(vector.begin(), vector.end(), [&](int currValue) -> void {
		std::cout << count << ". ";
		std::cout << currValue << std::endl;
		count++;
	});

	callLambda([]() {
		std::cout << "Did somebody call for LAMBDA-MAN!!!" << std::endl;
	});

	return 0;
}

void callLambda(void lambda())
{
	lambda();
}