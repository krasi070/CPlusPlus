// Name: Krasimir Balchev
// Username: krasi070

#include "HolidaySpot.h"

HolidaySpot::HolidaySpot(std::string name, std::string coordinates, std::string terrain, std::string waterBody, int terrainCleanliness,
	int waterBodyCleanliness, int numberOfGuestsAnnually, float averageCostPerDay, int numberOfBars, float raspberryDaiquiriPrice,
	float mojitoPrice, float orangeJuicePrice)
{
	this->setName(name);
	this->setCoordinates(coordinates);
	this->setTerrain(terrain);
	this->setWaterBody(waterBody);
	this->setTerrainCleanliness(terrainCleanliness);
	this->setWaterBodyCleanliness(waterBodyCleanliness);
	this->setNumberOfGuestsAnnually(numberOfGuestsAnnually);
	this->setAverageCostPerDay(averageCostPerDay);
	this->setNumberOfBars(numberOfBars);
	this->setRaspberryDaiquiriPrice(raspberryDaiquiriPrice);
	this->setMojitoPrice(mojitoPrice);
	this->setOrangeJuicePrice(orangeJuicePrice);
}

void HolidaySpot::setTerrainCleanliness(int terrainCleanliness)
{
	if (terrainCleanliness < MIN_SCORE)
	{
		terrainCleanliness = MIN_SCORE;
	}
	else if (terrainCleanliness > MAX_SCORE)
	{
		terrainCleanliness = MAX_SCORE;
	}

	this->_terrainCleanliness = terrainCleanliness;
}

void HolidaySpot::setWaterBodyCleanliness(int waterBodyCleanliness)
{
	if (waterBodyCleanliness < MIN_SCORE)
	{
		waterBodyCleanliness = MIN_SCORE;
	}
	else if (waterBodyCleanliness > MAX_SCORE)
	{
		waterBodyCleanliness = MAX_SCORE;
	}

	this->_waterBodyCleanliness = waterBodyCleanliness;
}

void HolidaySpot::setNumberOfGuestsAnnually(int numberOfGuestsAnnually)
{
	if (numberOfGuestsAnnually < 0)
	{
		numberOfGuestsAnnually = 0;
	}

	this->_numberOfGuestsAnnually = numberOfGuestsAnnually;
}

void HolidaySpot::setAverageCostPerDay(float averageCostPerDay)
{
	if (averageCostPerDay < 0)
	{
		averageCostPerDay = 0;
	}

	this->_averageCostPerDay = averageCostPerDay;;
}

void HolidaySpot::setNumberOfBars(int numberOfBars)
{
	if (numberOfBars < 0)
	{
		numberOfBars = 0;
	}

	this->_numberOfBars = numberOfBars;
}

void HolidaySpot::setRaspberryDaiquiriPrice(float raspberryDaiquiriPrice)
{
	if (raspberryDaiquiriPrice < 0)
	{
		raspberryDaiquiriPrice = 0;
	}

	this->_raspberryDaiquiriPrice = raspberryDaiquiriPrice;
}

void HolidaySpot::setMojitoPrice(float mojitoPrice)
{
	if (mojitoPrice < 0)
	{
		mojitoPrice = 0;
	}

	this->_mojitoPrice = mojitoPrice;
}

void HolidaySpot::setOrangeJuicePrice(float orangeJuicePrice)
{
	if (orangeJuicePrice < 0)
	{
		orangeJuicePrice = 0;
	}

	this->_orangeJuicePrice = orangeJuicePrice;
}