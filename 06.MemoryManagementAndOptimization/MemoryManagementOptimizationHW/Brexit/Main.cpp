#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <tuple>
#include "Vote.h"
#include "Gender.h"
#include "Voter.h"

int main()
{
	std::vector<Voter> voters;

	// Sets used for showing the collector all names, ages, etc.
	std::set<std::string> names;
	std::set<int> ages;
	std::set<std::string> locations;
	std::set<std::string> ethnicities;

	std::map<std::string, std::tuple<int, int>> resultsByName;
	std::map<int, std::tuple<int, int>> resultsByAge;
	std::map<std::string, std::tuple<int, int>> resultsByLocation;
	std::map<std::string, std::tuple<int, int>> resultsByEthnicity;
	std::map<Gender, std::tuple<int, int>> resultsByGender;

	

	return 0;
}