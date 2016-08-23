// Name: Krasimir Balchev
// Username: krasi070

#include <iostream>
#include "HolidaySpot.h"
#include "Country.h"

int main()
{
	HolidaySpot *holidaySpot1 = new HolidaySpot("HS1", "11 2 23 12", "Sand", "Ocean", 7, 4, 12000, 35, 67, 10, 12, 100);
	HolidaySpot *holidaySpot2 = new HolidaySpot("HS2", "11 3 23 42", "Rock", "Sea", 5, 10, 123000, 57, 120, 5, 6, 10);
	HolidaySpot *holidaySpot3 = new HolidaySpot("HS3", "11 4 13 22", "Sand", "Pool", 3, 9, 12500, 100, 34, 12, 12, 1);
	HolidaySpot *holidaySpot4 = new HolidaySpot("HS4", "11 5 23 12", "Tiles", "Puddle", 10, 10, 1000000, 1000, 0, 13, 14, 1.5f);
	HolidaySpot *holidaySpot5 = new HolidaySpot("HS5", "11 6 23 72", "Sand", "Sea", 5, 5, 6000, 42.45f, 83, 7, 5, 3.1f);
	
	Country country = Country("Bulgaria", "lv.", 0.51f);
	country.addHolidaySpot(std::shared_ptr<HolidaySpot>(holidaySpot1));
	country.addHolidaySpot(std::shared_ptr<HolidaySpot>(holidaySpot2));
	country.addHolidaySpot(std::shared_ptr<HolidaySpot>(holidaySpot3));
	country.addHolidaySpot(std::shared_ptr<HolidaySpot>(holidaySpot4));
	country.addHolidaySpot(std::shared_ptr<HolidaySpot>(holidaySpot5));

	country.getHolidaySpot(10, 12, 100); // this line doesn't work when you test it but if you debug it, it works perfectly fine :o
	country.removeHolidaySpotByName("HS4");
	
	country.joinThreads();

	return 0;
}