// Name: Krasimir Balchev
// Username: krasi070

#include <iostream>

int main()
{
	int a;
	std::cin >> a;
	int b;
	std::cin >> b;
	int c;
	std::cin >> c;

	int discriminant = b * b - 4 * a * c;
	if (discriminant >= 0)
	{
		double x1 = (-1 * b + sqrt(discriminant)) / (2 * a);
		double x2 = (-1 * b - sqrt(discriminant)) / (2 * a);
		printf("x1 = %0.2f\nx2 = %0.2f\n", x1, x2);
	}
	else
	{
		printf("x1 = nan\nx2 = nan\n");
	}

	return 0;
}