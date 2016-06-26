#include <iostream>
#include <iomanip>

class Car;

class Man
{
public:
	Man() {};
	void crashCar(Car &car);
};

class Car
{
private:
	bool needsToBeRepaired;
public:
	Car() {};
	Car(double price) : price(price) 
	{
		needsToBeRepaired = false;
	};

	double price;
	friend class Mechanic;
	friend void Man::crashCar(Car &car);
};

class Mechanic
{
public:
	Mechanic() {};
	double priceForCarRepair(Car &car);
	void repairCar(Car &car);
};

double Mechanic::priceForCarRepair(Car &car)
{
	return car.price * 0.05;
}

void Mechanic::repairCar(Car &car)
{
	car.needsToBeRepaired = false;
}

void Man::crashCar(Car &car)
{
	car.needsToBeRepaired = true;
}

int main()
{
	Car car = Car(1999.99);
	Man man = Man();
	Mechanic mechanic = Mechanic();

	man.crashCar(car);
	mechanic.repairCar(car);
	double priceForCarRepair = mechanic.priceForCarRepair(car);

	std::cout << "Car price: " << car.price << std::endl <<
		"Price for car repair: " << std::fixed << std::setprecision(2) << priceForCarRepair << std::endl;

	return 0;
}