#include <iostream>
#include "Voter.h"
#include "Vote.h"

Voter::Voter(int age, std::string name, Gender gender, std::string loc, std::string ethnicity, Vote vote)
	: User(age, name, gender, loc, ethnicity)
{
	this->setVote(vote);
}

Vote Voter::getVote()
{
	return this->vote;
}

void Voter::setVote(Vote vote)
{
	this->vote = vote;
}