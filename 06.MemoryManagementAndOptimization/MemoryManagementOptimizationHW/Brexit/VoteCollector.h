#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include "User.h"
#include "Voter.h"

#ifndef __VOTECOLLECTOR_H
#define __VOTECOLLECTOR_H

class VoteCollector : public User
{
public:
	std::map<std::string, std::tuple<int, int>> getResultsByName(std::vector<Voter> voters);

	std::map<int, std::tuple<int, int>> getResultsByAge(std::vector<Voter> voters);

	std::map<std::string, std::tuple<int, int>> getResultsByLocation(std::vector<Voter> voters);

	std::map<std::string, std::tuple<int, int>> getResultsByEthnicity(std::vector<Voter> voters);

	std::map<Gender, std::tuple<int, int>> getResultsByGender(std::vector<Voter> voters);
};

#endif