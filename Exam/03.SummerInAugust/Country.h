// Name: Krasimir Balchev
// Username: krasi070

#ifndef __COUNTRY_H
#define __COUNTRY_H

#include <iostream>
#include <map>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include "HolidaySpot.h"

class Country
{
private:
	std::string _name;
	std::map<std::string, std::shared_ptr<HolidaySpot>> _holidaySpots;
	std::string _currency;
	float _currencyExcangeRateInEuro;
	std::vector<std::thread> threads;
	std::mutex lock;

public:
	// Constructors
	Country() { }

	Country(std::string name, std::string currency, float currencyExchnageRateInEuro);

	Country(const Country &country);

	// Getters & Setters
	std::string getName()
	{
		return this->_name;
	}

	void setName(std::string name)
	{
		this->_name = name;
	}

	std::string getCurrency()
	{
		return this->_currency;
	}

	void setCurrency(std::string currency)
	{
		this->_currency = currency;
	}

	float getCurrencyExcangeRateInEuro()
	{
		return this->_currencyExcangeRateInEuro;
	}

	void setCurrencyExcangeRateInEuro(float currencyExchangeRateInEuro);

	// Functions
	void addHolidaySpot(std::shared_ptr<HolidaySpot> holidaySpot);

	void removeHolidaySpotByName(std::string name);

	void getHolidaySpot(float raspberryDaiquiriPrice, float mojitoPrice, float orangeJuicePrice);

	void joinThreads();
};

#endif