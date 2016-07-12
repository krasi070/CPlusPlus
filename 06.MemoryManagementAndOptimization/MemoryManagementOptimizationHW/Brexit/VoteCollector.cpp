#include <iostream>
#include <memory>
#include <map>
#include <set>
#include <vector>
#include <tuple>
#include "VoteCollector.h"
#include "Voter.h"
#include "Vote.h"
#include "Gender.h"

void VoteCollector::calculateResults(std::vector<std::shared_ptr<Voter>> voters)
{
	this->results = std::make_tuple(0, 0);

	this->resultsByGender[Female] = std::make_tuple(0, 0);
	this->resultsByGender[Male] = std::make_tuple(0, 0);

	for (std::shared_ptr<Voter> const &voter : voters)
	{
		if (this->resultsByName.find(voter->getName()) == this->resultsByName.end())
		{
			this->resultsByName[voter->getName()] = std::make_tuple(0, 0);
			this->names.insert(voter->getName());
		}

		if (this->resultsByAge.find(voter->getAge()) == this->resultsByAge.end())
		{
			this->resultsByAge[voter->getAge()] = std::make_tuple(0, 0);
			this->ages.insert(voter->getAge());
		}

		if (this->resultsByLocation.find(voter->getLocation()) == this->resultsByLocation.end())
		{
			this->resultsByLocation[voter->getLocation()] = std::make_tuple(0, 0);
			this->locations.insert(voter->getLocation());
		}

		if (this->resultsByEthnicity.find(voter->getEthnicity()) == this->resultsByEthnicity.end())
		{
			this->resultsByEthnicity[voter->getEthnicity()] = std::make_tuple(0, 0);
			this->ethnicities.insert(voter->getEthnicity());
		}

		if (voter->getVote() == Remain)
		{
			std::get<0>(this->results)++;
			std::get<0>(this->resultsByName[voter->getName()])++;
			std::get<0>(this->resultsByAge[voter->getAge()])++;
			std::get<0>(this->resultsByLocation[voter->getLocation()])++;
			std::get<0>(this->resultsByEthnicity[voter->getEthnicity()])++;
			std::get<0>(this->resultsByGender[voter->getGender()])++;
		}
		else
		{
			std::get<1>(this->results)++;
			std::get<1>(this->resultsByName[voter->getName()])++;
			std::get<1>(this->resultsByAge[voter->getAge()])++;
			std::get<1>(this->resultsByLocation[voter->getLocation()])++;
			std::get<1>(this->resultsByEthnicity[voter->getEthnicity()])++;
			std::get<1>(this->resultsByGender[voter->getGender()])++;
		}
	}
}

std::tuple<int, int> VoteCollector::getResults()
{
	return this->results;
}

std::map<std::string, std::tuple<int, int>> VoteCollector::getResultsByName()
{
	return this->resultsByName;
}

std::map<int, std::tuple<int, int>> VoteCollector::getResultsByAge()
{
	return this->resultsByAge;
}

std::map<std::string, std::tuple<int, int>> VoteCollector::getResultsByLocation()
{
	return this->resultsByLocation;
}

std::map<std::string, std::tuple<int, int>> VoteCollector::getResultsByEthnicity()
{
	return this->resultsByEthnicity;
}

std::map<Gender, std::tuple<int, int>> VoteCollector::getResultsByGender()
{
	return this->resultsByGender;
}

std::set<std::string> VoteCollector::getNames()
{
	return this->names;
}

std::set<int> VoteCollector::getAges()
{
	return this->ages;
}

std::set<std::string> VoteCollector::getLocations()
{
	return this->locations;
}

std::set<std::string> VoteCollector::getEthnicities()
{
	return this->ethnicities;
}