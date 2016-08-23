// Name: Krasimir Balchev
// Username: krasi070

#include <algorithm>
#include <string>
#include "Country.h"

Country::Country(std::string name, std::string currency, float currencyExchnageRateInEuro)
{
	this->setName(name);
	this->setCurrency(currency);
	this->setCurrencyExcangeRateInEuro(currencyExchnageRateInEuro);
}

Country::Country(const Country &country)
{
	this->setName(country._name);
	this->setCurrency(country._currency);
	this->setCurrencyExcangeRateInEuro(country._currencyExcangeRateInEuro);
}

void Country::setCurrencyExcangeRateInEuro(float currencyExchangeRateInEuro)
{
	this->_currencyExcangeRateInEuro = currencyExchangeRateInEuro;
}

void Country::addHolidaySpot(std::shared_ptr<HolidaySpot> holidaySpot)
{
	this->joinThreads();
	this->_holidaySpots[holidaySpot->getName()] = holidaySpot;
}

void Country::removeHolidaySpotByName(std::string name)
{
	this->joinThreads();
	this->_holidaySpots.erase(name);
}

void Country::getHolidaySpot(float raspberryDaiquiriPrice, float mojitoPrice, float orangeJuicePrice)
{
	this->lock.lock();
	this->threads.push_back(std::thread(
		[&]() 
	{
		std::string nameOfSearchedHoliday;
		bool holidayFound = false;
		std::for_each(this->_holidaySpots.begin(), this->_holidaySpots.end(),
			[&](std::pair<std::string, std::shared_ptr<HolidaySpot>> pair)
		{
			if (pair.second->getRaspberryDaiquiriPrice() == raspberryDaiquiriPrice &&
				pair.second->getMojitoPrice() == mojitoPrice &&
				pair.second->getOrangeJuicePrice() == orangeJuicePrice)
			{
				nameOfSearchedHoliday = pair.first;
				holidayFound = true;
			}
		});

		if (holidayFound)
		{
			std::cout << "Name: " << this->_holidaySpots[nameOfSearchedHoliday]->getName() << std::endl <<
				"Coordinates: " << this->_holidaySpots[nameOfSearchedHoliday]->getCoordinates() << std::endl <<
				"Terrain: " << this->_holidaySpots[nameOfSearchedHoliday]->getTerrain() << std::endl <<
				"Water body: " << this->_holidaySpots[nameOfSearchedHoliday]->getWaterBody() << std::endl <<
				"Terrain cleanliness score: " << this->_holidaySpots[nameOfSearchedHoliday]->getTerrainCleanliness() << std::endl <<
				"Water body cleanliness score: " << this->_holidaySpots[nameOfSearchedHoliday]->getWaterBodyCleanliness() << std::endl <<
				"Number of guests annually: " << this->_holidaySpots[nameOfSearchedHoliday]->getNumberOfGuestsAnnually() << std::endl <<
				"Average cost per day: " << this->_holidaySpots[nameOfSearchedHoliday]->getAverageCostPerDay() << " " <<
				this->getCurrency() << std::endl <<
				"Number of bars: " << this->_holidaySpots[nameOfSearchedHoliday]->getNumberOfBars() << std::endl <<
				"Price of raspberry daiquiri: " << this->_holidaySpots[nameOfSearchedHoliday]->getRaspberryDaiquiriPrice() << " " <<
				this->getCurrency() << std::endl <<
				"Price of mojito: " << this->_holidaySpots[nameOfSearchedHoliday]->getMojitoPrice() << " " <<
				this->getCurrency() << std::endl <<
				"Price of orange juice: " << this->_holidaySpots[nameOfSearchedHoliday]->getOrangeJuicePrice() << " " <<
				this->getCurrency() << std::endl;
		}
		else
		{
			std::cout << "Holiday spot was not found!" << std::endl;
		}

		
	}));

	this->lock.unlock();
}

void Country::joinThreads()
{
	for (int i = 0; i < this->threads.size(); i++)
	{
		this->threads[i].join();
	}

	this->threads.clear();
}