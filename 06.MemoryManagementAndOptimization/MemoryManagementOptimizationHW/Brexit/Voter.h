#include <iostream>
#include "User.h"
#include "Vote.h"

#ifndef __VOTER_H
#define __VOTER_H

class Voter : public User
{
private:
	Vote vote;

	Vote getVote();

	void setVote(Vote vote);
public:
	Voter();

	Voter(int age, std::string name, Gender gender, std::string loc, std::string ethnicity, Vote vote);

	friend class VoteCollector;
};

#endif