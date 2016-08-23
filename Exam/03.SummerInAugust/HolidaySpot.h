// Name: Krasimir Balchev
// Username: krasi070

#ifndef __HOLIDAYSPOT_H
#define __HOLIDAYSPOT_H

#include <iostream>

#define MAX_SCORE 10
#define MIN_SCORE 0

class HolidaySpot
{
private:
	std::string _name;
	std::string _coordinates;
	std::string _terrain;
	std::string _waterBody;
	int _terrainCleanliness;
	int _waterBodyCleanliness;
	int _numberOfGuestsAnnually;
	float _averageCostPerDay;
	int _numberOfBars;
	float _raspberryDaiquiriPrice;
	float _mojitoPrice;
	float _orangeJuicePrice;
public:
	// Coonstructors
	HolidaySpot() { }

	HolidaySpot(std::string name, std::string coordinates, std::string terrain, std::string waterBody, int terrainCleanliness,
		int waterBodyCleanliness, int numberOfGuestsAnnually, float averageCostPerDay, int numberOfBars, float raspberryDaiquiriPrice,
		float mojitoPrice, float orangeJuicePrice);

	// Getters & Setters
	std::string getName()
	{
		return this->_name;
	}

	void setName(std::string name)
	{
		this->_name = name;
	}

	std::string getCoordinates()
	{
		return this->_coordinates;
	}

	void setCoordinates(std::string coordinates)
	{
		this->_coordinates = coordinates;
	}

	std::string getTerrain()
	{
		return this->_terrain;
	}

	void setTerrain(std::string terrain)
	{
		this->_terrain = terrain;
	}

	std::string getWaterBody()
	{
		return this->_waterBody;
	}

	void setWaterBody(std::string waterBody)
	{
		this->_waterBody = waterBody;
	}

	int getTerrainCleanliness()
	{
		return this->_terrainCleanliness;
	}

	void setTerrainCleanliness(int terrainCleanliness);

	int getWaterBodyCleanliness()
	{
		return this->_waterBodyCleanliness;
	}

	void setWaterBodyCleanliness(int waterBodyCleanliness);

	int getNumberOfGuestsAnnually()
	{
		return this->_numberOfGuestsAnnually;
	}

	void setNumberOfGuestsAnnually(int numberOfGuestsAnually);

	float getAverageCostPerDay()
	{
		return this->_averageCostPerDay;
	}

	void setAverageCostPerDay(float averageCostPerDay);

	int getNumberOfBars()
	{
		return this->_numberOfBars;
	}

	void setNumberOfBars(int numberOfBars);

	float getRaspberryDaiquiriPrice()
	{
		return this->_raspberryDaiquiriPrice;
	}

	void setRaspberryDaiquiriPrice(float raspberryDaiquiriprice);

	float getMojitoPrice()
	{
		return this->_mojitoPrice;
	}

	void setMojitoPrice(float mojitoPrice);

	float getOrangeJuicePrice()
	{
		return this->_orangeJuicePrice;
	}

	void setOrangeJuicePrice(float orangeJuicePrice);
};

#endif