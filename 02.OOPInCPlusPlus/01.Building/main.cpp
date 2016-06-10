#include <iostream>
#include <string>

class Building
{
public:
	inline Building(
		std::string newCompanyName, 
		int newNumberOfFloors, 
		int newNumberOfOffices, 
		int newNumberOfEmployees,
		int newNumberOfFreeWorkingSeats,
		bool newIsFirstFloorRestaurant)
	{
		companyName = newCompanyName;
		numberOfFloors = newNumberOfFloors;
		numberOfOffices = newNumberOfOffices;
		numberOfEmployees = newNumberOfEmployees;
		numberOfFreeWorkingSeats = newNumberOfFreeWorkingSeats;
		isFirstFloorRestaurant = newIsFirstFloorRestaurant;
	}

	inline Building()
	{
		companyName = "";
		numberOfFloors = 0;
		numberOfOffices = 0;
		numberOfEmployees = 0;
		numberOfFreeWorkingSeats = 0;
		isFirstFloorRestaurant = false;
	}

	inline ~Building()
	{
		std::cout << "Building destructor called." << std::endl;
	}

	std::string companyName;
	int numberOfFloors;
	int numberOfOffices;
	int numberOfEmployees;
	int numberOfFreeWorkingSeats;
	bool isFirstFloorRestaurant;

	inline double getPeoplePerFloor()
	{
		int floors = numberOfFloors;
		if (isFirstFloorRestaurant)
		{
			floors--;
		}

		return 1.0 * numberOfEmployees / floors;
	}
	inline double getOfficesPerFloor()
	{
		int floors = numberOfFloors;
		if (isFirstFloorRestaurant)
		{
			floors--;
		}

		return 1.0 * numberOfOffices / floors;
	}
	inline double getPeoplePerOffice()
	{
		return 1.0 * numberOfEmployees / numberOfOffices;
	}
};

Building getBuildingWithMostEmployees(Building buildings[], int size);
Building getBuildingWithMostFreeSpaces(Building buildings[], int size);
Building getHighestCoefficientEmployees(Building buildings[], int size);
Building getBuildingWithMostPeoplePerFloor(Building buildings[], int size);
Building getBuildingWithLeastPeoplePerFloor(Building buildings[], int size);
Building getBuildingWithMostOfficesPerFloor(Building buildings[], int size);
Building getBuildingWithLeastOfficesPerFloor(Building buildings[], int size);
Building getBuildingWithMostPeoplePerOffice(Building buildings[], int size);
Building getBuildingWithLeastPeoplePerOffice(Building buildings[], int size);

int main()
{
	Building buildings[3];
	buildings[0] = Building("XYZ industries", 6, 127, 600, 196, false);
	buildings[1] = Building("Rapid Development Crew", 8, 210, 822, 85, true);
	buildings[2] = Building("SoftUni", 11, 106, 200, 60, false);

	std::string buildingWithMostEmployees = getBuildingWithMostEmployees(buildings, 3).companyName;
	std::cout << "Building with most employees: " << buildingWithMostEmployees << std::endl;

	std::string buildingWithMostFreeSpaces = getBuildingWithMostFreeSpaces(buildings, 3).companyName;
	std::cout << "Building with most free working seats: " << buildingWithMostFreeSpaces << std::endl;

	std::string buildingWithHighestCoefficientEmployees = getHighestCoefficientEmployees(buildings, 3).companyName;
	std::cout << "Building with highest coefficient employees: " << buildingWithHighestCoefficientEmployees << std::endl;

	// EPF = Employees Per Floor
	std::string buildingWithMostEPF = getBuildingWithMostPeoplePerFloor(buildings, 3).companyName;
	std::cout << "Building with most employees per floor: " << buildingWithMostEPF << std::endl;

	std::string buildingWithLeastEPF = getBuildingWithLeastPeoplePerFloor(buildings, 3).companyName;
	std::cout << "Building with least employees per floor: " << buildingWithLeastEPF << std::endl;

	// OPF = OfficesPerFloor
	std::string buildingWithMostOPF = getBuildingWithMostOfficesPerFloor(buildings, 3).companyName;
	std::cout << "Building with most offices per floor: " << buildingWithMostOPF << std::endl;

	std::string buildingWithLeastOPF = getBuildingWithLeastOfficesPerFloor(buildings, 3).companyName;
	std::cout << "Building with least offices per floor: " << buildingWithLeastOPF << std::endl;

	// PPF = People Per Office
	std::string buildingWithMostPPF = getBuildingWithMostPeoplePerOffice(buildings, 3).companyName;
	std::cout << "Building with most people per office: " << buildingWithMostPPF << std::endl;

	std::string buildingWithLeastPPF = getBuildingWithLeastPeoplePerOffice(buildings, 3).companyName;
	std::cout << "Building with least people per office: " << buildingWithLeastPPF << std::endl;

	return 0;
}

Building getBuildingWithMostEmployees(Building buildings[], int size)
{
	int maxEmployees = buildings[0].numberOfEmployees;
	int indexOfBuildingWithMaxEmployees = 0;
	for (int i = 1; i < size; i++)
	{
		if (maxEmployees < buildings[i].numberOfEmployees)
		{
			maxEmployees = buildings[i].numberOfEmployees;
			indexOfBuildingWithMaxEmployees = i;
		}
	}

	return buildings[indexOfBuildingWithMaxEmployees];
}

Building getBuildingWithMostFreeSpaces(Building buildings[], int size)
{
	int maxFreePlaces = buildings[0].numberOfFreeWorkingSeats;
	int indexOfBuildingWithMaxFreePlaces = 0;
	for (int i = 1; i < size; i++)
	{
		if (maxFreePlaces < buildings[i].numberOfFreeWorkingSeats)
		{
			maxFreePlaces = buildings[i].numberOfFreeWorkingSeats;
			indexOfBuildingWithMaxFreePlaces = i;
		}
	}

	return buildings[indexOfBuildingWithMaxFreePlaces];
}

Building getHighestCoefficientEmployees(Building buildings[], int size)
{
	float max = 0;
	int indexOfHighestCoefficientEmployees = 0;
	for (int i = 0; i < size; i++)
	{
		float curr = buildings[i].numberOfEmployees / (buildings[i].numberOfEmployees + buildings[i].numberOfFreeWorkingSeats);
		if (curr > max)
		{
			max = curr;
			indexOfHighestCoefficientEmployees = i;
		}
	}

	return buildings[indexOfHighestCoefficientEmployees];
}

Building getBuildingWithMostPeoplePerFloor(Building buildings[], int size)
{
	double max = buildings[0].getPeoplePerFloor();
	int maxIndex = 0;
	for (int i = 1; i < size; i++)
	{
		if (buildings[i].getPeoplePerFloor() > max)
		{
			max = buildings[i].getPeoplePerFloor();
			maxIndex = i;
		}
	}

	return buildings[maxIndex];
}

Building getBuildingWithLeastPeoplePerFloor(Building buildings[], int size)
{
	double min = buildings[0].getPeoplePerFloor();
	int minIndex = 0;
	for (int i = 1; i < size; i++)
	{
		if (buildings[i].getPeoplePerFloor() < min)
		{
			min = buildings[i].getPeoplePerFloor();
			minIndex = i;
		}
	}

	return buildings[minIndex];
}

Building getBuildingWithMostOfficesPerFloor(Building buildings[], int size)
{
	double max = buildings[0].getOfficesPerFloor();
	int maxIndex = 0;
	for (int i = 1; i < size; i++)
	{
		if (buildings[0].getOfficesPerFloor() > max)
		{
			max = buildings[0].getOfficesPerFloor();
			maxIndex = i;
		}
	}

	return buildings[maxIndex];
}

Building getBuildingWithLeastOfficesPerFloor(Building buildings[], int size)
{
	double min = buildings[0].getOfficesPerFloor();
	int minIndex = 0;
	for (int i = 1; i < size; i++)
	{
		if (buildings[0].getOfficesPerFloor() < min)
		{
			min = buildings[0].getOfficesPerFloor();
			minIndex = i;
		}
	}

	return buildings[minIndex];
}

Building getBuildingWithMostPeoplePerOffice(Building buildings[], int size)
{
	double max = buildings[0].getPeoplePerOffice();
	int maxIndex = 0;
	for (int i = 1; i < size; i++)
	{
		if (buildings[0].getPeoplePerOffice() > max)
		{
			max = buildings[0].getPeoplePerOffice();
			maxIndex = i;
		}
	}

	return buildings[maxIndex];
}

Building getBuildingWithLeastPeoplePerOffice(Building buildings[], int size)
{
	double min = buildings[0].getPeoplePerOffice();
	int minIndex = 0;
	for (int i = 1; i < size; i++)
	{
		if (buildings[0].getPeoplePerOffice() < min)
		{
			min = buildings[0].getPeoplePerOffice();
			minIndex = i;
		}
	}

	return buildings[minIndex];
}