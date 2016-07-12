#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <tuple>
#include "User.h"
#include "Voter.h"

#ifndef __VOTECOLLECTOR_H
#define __VOTECOLLECTOR_H

class VoteCollector : public User
{
private:
	std::tuple<int, int> results;

	std::set<std::string> names;
	std::set<int> ages;
	std::set<std::string> locations;
	std::set<std::string> ethnicities;

	std::map<std::string, std::tuple<int, int>> resultsByName;
	std::map<int, std::tuple<int, int>> resultsByAge;
	std::map<std::string, std::tuple<int, int>> resultsByLocation;
	std::map<std::string, std::tuple<int, int>> resultsByEthnicity;
	std::map<Gender, std::tuple<int, int>> resultsByGender;
public:
	VoteCollector() {}

	void calculateResults(std::vector<std::shared_ptr<Voter>> voters);

	std::tuple<int, int> getResults();

	std::map<std::string, std::tuple<int, int>> getResultsByName();

	std::map<int, std::tuple<int, int>> getResultsByAge();

	std::map<std::string, std::tuple<int, int>> getResultsByLocation();

	std::map<std::string, std::tuple<int, int>> getResultsByEthnicity();

	std::map<Gender, std::tuple<int, int>> getResultsByGender();

	std::set<std::string> getNames();

	std::set<int> getAges();

	std::set<std::string> getLocations();

	std::set<std::string> getEthnicities();
};

#endif