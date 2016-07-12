#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <tuple>
#include "Vote.h"
#include "Gender.h"
#include "Voter.h"
#include "VoteCollector.h"

std::shared_ptr<Voter> createVoter();
std::string getVoterName();
int getVoterAge();
Gender getVoterGender();
std::string getVoterLocation();
std::string getVoterEthnicity();
Vote getVoterVote();
bool enterPassword();
void startVoteCollectorMode(std::shared_ptr<VoteCollector> voteCollector);
void executeGetResultsInPercentageForm(std::tuple<int, int> &results);
bool isNumber(std::string str);
void executeGetResultsInNumberForm(std::tuple<int, int> &results);
std::tuple<float, float> getPercentage(std::tuple<int, int> &tuple);
void executeGetResultsBasedOnAge(std::map<int, std::tuple<int, int>> &resultsByAge);
std::vector<std::shared_ptr<Voter>> addVotes();
void executeGetResultsBasedOnName(std::map<std::string, std::tuple<int, int>> &resultsByName);
void executeGetResultsBasedOnEthnicity(std::map<std::string, std::tuple<int, int>> &resultsByEthnicity);
void executeGetResultsBasedOnLocation(std::map<std::string, std::tuple<int, int>> &resultsByLocation);
void executeGetResultsBasedOnGender(std::map<Gender, std::tuple<int, int>> &resultsByGender);
void executeGetAllPossibleAges(std::set<int> &ages);
void executeGetAllPossibleNames(std::set<std::string> &names);
void executeGetAllPossibleEthnicities(std::set<std::string> &ethnicities);
void executeGetAllPossibleLocations(std::set<std::string> &locations);
void executeGetSpecificResult(std::shared_ptr<VoteCollector> &voteCollector);
bool checkIfInputIsForAge(std::string input, std::set<int> &ages, std::map<int, std::tuple<int, int>> &resultsByAge);
bool checkIfInputIsForName(
	std::string input,
	std::set<std::string> &names,
	std::map<std::string, std::tuple<int, int>> &resultsByName);
bool checkIfInputIsForGender(std::string input, std::map<Gender, std::tuple<int, int>> &resultsByGender);
bool checkIfInputIsForEthnicity(
	std::string input,
	std::set<std::string> &ethnicicties,
	std::map<std::string, std::tuple<int, int>> &resultsByEthnicity);
bool checkIfInputIsForLocation(
	std::string input, 
	std::set<std::string> &locations, 
	std::map<std::string, std::tuple<int, int>> &resultsByLocation);

int main()
{
	std::vector<std::shared_ptr<Voter>> voters = addVotes();

	while (true)
	{
		std::string choiceStr;
		std::cout << "MAIN MENU:" << std::endl <<
			"1.Enter Vote" << std::endl <<
			"2.Enter Vote Collector Mode" << std::endl <<
			"0.Exit" << std::endl <<
			">";
		getline(std::cin, choiceStr);
		if (choiceStr != "1" && choiceStr != "2" && choiceStr != "0")
		{
			system("cls");
			continue;
		}

		int choice = std::stoi(choiceStr);

		switch (choice)
		{
		case 0:
			system("cls");
			return 0;
			break;
		case 1:
			voters.push_back(createVoter());
			system("cls");
			std::cout << "CONGRATULATIONS! YOU VOTED!" << std::endl <<
				std::endl <<
				"PRESS ANY KEY TO CONTINUE";
			std::cin.ignore();
			break;
		case 2:
			if (enterPassword())
			{
				std::shared_ptr<VoteCollector> voteCollector(new VoteCollector());
				voteCollector->calculateResults(voters);
				startVoteCollectorMode(voteCollector);
			}

			break;
		}

		system("cls");
	}

	return 0;
}

std::shared_ptr<Voter> createVoter()
{
	system("cls");
	std::string name = getVoterName();
	int age = getVoterAge();
	Gender gender = getVoterGender();
	std::string location = getVoterLocation();
	std::string ethnicity = getVoterEthnicity();
	Vote vote = getVoterVote();

	return std::shared_ptr<Voter>(new Voter(age, name, gender, location, ethnicity, vote));
}

std::string getVoterName()
{
	std::cout << "Name: ";
	std::string name;
	getline(std::cin, name);
	while (name == "")
	{
		std::cout << "Invalid! Name cannot be empty!" << std::endl <<
			"Name: ";
		getline(std::cin, name);
	}

	return name;
}

int getVoterAge()
{
	std::cout << "Age: ";
	std::string ageStr;
	getline(std::cin, ageStr);
	while (!isNumber(ageStr))
	{
		std::cout << "Invalid! Please enter number." << std::endl <<
			"Age: ";
		getline(std::cin, ageStr);
	}

	int age = std::stoi(ageStr);
	while (age < 18 || age > 100)
	{
		std::cout << "Invalid! ";
		if (age < 0)
		{
			std::cout << "Age cannot be negative!" << std::endl;
		}
		else if (age < 18)
		{
			std::cout << "You must be at least 18 to vote!" << std::endl;
		}
		else if (age > 100)
		{
			std::cout << "Wow... We weren't expecting someone as old as you to vote... Just say you are 100 next time. Okay?" << std::endl;
		}

		std::cout << "Age: ";
		std::cin >> age;
		std::cin.ignore();
	}

	return age;
}

Gender getVoterGender()
{
	std::cout << "Gender: ";
	std::string gender;
	getline(std::cin, gender);
	while (gender != "Female" && gender != "Male")
	{
		std::cout << "Invalid! Valid genders:" << std::endl <<
			"--Female" << std::endl <<
			"--Male" << std::endl <<
			"Gender: ";
		getline(std::cin, gender);
	}

	if (gender == "Female")
	{
		return Female;
	}

	return Male;
}

std::string getVoterLocation()
{
	std::cout << "Loaction: ";
	std::string location;
	getline(std::cin, location);
	while (location == "")
	{
		std::cout << "Invalid! Location cannot be empty!" << std::endl <<
			"Location: ";
		getline(std::cin, location);
	}

	return location;
}

std::string getVoterEthnicity()
{
	std::cout << "Ethnicity: ";
	std::string ethnicity;
	getline(std::cin, ethnicity);
	while (ethnicity == "")
	{
		std::cout << "Invalid! Ethnicity cannot be empty!" << std::endl <<
			"Ethnicity: ";
		getline(std::cin, ethnicity);
	}

	return ethnicity;
}

Vote getVoterVote()
{
	system("cls");
	std::cout << "VOTE MENU:" << std::endl <<
		"1.Remain" << std::endl <<
		"2.Leave" << std::endl <<
		">";
	std::string choiceStr;
	getline(std::cin, choiceStr);

	while (choiceStr != "1" && choiceStr != "2")
	{
		std::cout << "Well, aren't you the rebellious type. Just enter 1 or 2 already." << std::endl <<
			">";
		getline(std::cin, choiceStr);
	}

	if (choiceStr == "1")
	{
		return Remain;
	}

	return Leave;
}

bool enterPassword()
{
	system("cls");
	std::cout << "In order to continue you must first enter the SUPER-MEGA-GIGA-ULTRA-HYPER-SECRET password!" << std::endl <<
		"Password: ";
	std::string password;
	getline(std::cin, password);
	if (password == "12344321")
	{
		std::cout << "Noice!" << std::endl <<
			std::endl <<
			"PRESS ANY KEY TO CONTINUE" << std::endl;
		std::cin.ignore();
		return true;
	}

	std::cout << "BZZZZZZ! Better luck next time." << std::endl <<
		std::endl <<
		"PRESS ANY KEY TO CONTINUE" << std::endl;
	std::cin.ignore();
	return false;
}

void startVoteCollectorMode(std::shared_ptr<VoteCollector> voteCollector)
{
	system("cls");
	std::string choiceStr;
	while (true)
	{
		std::cout << "VOTE COLLECTOR MODE:" << std::endl <<
			"01.Get results in percentage form" << std::endl <<
			"02.Get results in number form" << std::endl <<
			"03.Get results based on age" << std::endl <<
			"04.Get results based on name" << std::endl <<
			"05.Get results based on gender" << std::endl <<
			"06.Get results based on ethnicity" << std::endl <<
			"07.Get results based on location" << std::endl <<
			"08.Get all possible ages" << std::endl <<
			"09.Get all possible names" << std::endl <<
			"10.Get all possible locations" << std::endl <<
			"11.Get all possible ethnicities" << std::endl <<
			"12.Get specific result" << std::endl <<
			"00.Go back to MAIN MENU" << std::endl <<
			">";
		getline(std::cin, choiceStr);
		system("cls");
		if (!isNumber(choiceStr))
		{
			continue;
		}

		int choice = std::stoi(choiceStr);
		switch (choice)
		{
		case 0:
			return;
			break;
		case 1:
			executeGetResultsInPercentageForm(voteCollector->getResults());
			break;
		case 2:
			executeGetResultsInNumberForm(voteCollector->getResults());
			break;
		case 3:
			executeGetResultsBasedOnAge(voteCollector->getResultsByAge());
			break;
		case 4:
			executeGetResultsBasedOnName(voteCollector->getResultsByName());
			break;
		case 5:
			executeGetResultsBasedOnGender(voteCollector->getResultsByGender());
			break;
		case 6:
			executeGetResultsBasedOnEthnicity(voteCollector->getResultsByEthnicity());
			break;
		case 7:
			executeGetResultsBasedOnLocation(voteCollector->getResultsByLocation());
			break;
		case 8:
			executeGetAllPossibleAges(voteCollector->getAges());
			break;
		case 9:
			executeGetAllPossibleNames(voteCollector->getNames());
			break;
		case 10:
			executeGetAllPossibleLocations(voteCollector->getLocations());
			break;
		case 11:
			executeGetAllPossibleEthnicities(voteCollector->getEthnicities());
			break;
		case 12:
			executeGetSpecificResult(voteCollector);
			break;
		default:
			std::cout << "Ha ha, very funny. #sarcasam";
			break;
		}

		system("cls");
	}
}

std::tuple<float, float> getPercentage(std::tuple<int, int> &tuple)
{
	unsigned int sum = std::get<0>(tuple) + std::get<1>(tuple);
	if (sum == 0)
	{
		return std::make_tuple(0, 0);
	}

	float firstPercentage = 100.0 * std::get<0>(tuple) / sum;
	float secondPercentage = 100.0 * std::get<1>(tuple) / sum;
	std::tuple<float, float> percentage = std::make_tuple(firstPercentage, secondPercentage);

	return percentage;
}

void executeGetResultsInPercentageForm(std::tuple<int, int> &results)
{
	system("cls");
	std::tuple<float, float> percentages = getPercentage(results);
	float remain = std::get<0>(percentages);
	float leave = std::get<1>(percentages);
	std::cout << std::setprecision(2) << std::fixed <<
		"Remain -> " << remain << "%" << std::endl <<
		"Leave -> " << leave << "%" << std::endl <<
		std::endl <<
		"PRESS ANY KEY TO CONTINUE";
	std::cin.ignore();
}

void executeGetResultsInNumberForm(std::tuple<int, int> &results)
{
	system("cls");
	int remain = std::get<0>(results);
	int leave = std::get<1>(results);
	std::cout << std::setprecision(2) << std::fixed <<
		"Remain -> " << remain << std::endl <<
		"Leave -> " << leave << std::endl <<
		std::endl <<
		"PRESS ANY KEY TO CONTINUE";
	std::cin.ignore();
}

void executeGetResultsBasedOnAge(std::map<int, std::tuple<int, int>> &resultsByAge)
{
	typedef std::map<int, std::tuple<int, int>>::iterator it_type;
	for (it_type it = resultsByAge.begin(); it != resultsByAge.end(); it++)
	{
		int age = it->first;
		int remain = std::get<0>(it->second);
		int leave = std::get<1>(it->second);
		std::cout << std::setprecision(2) << std::fixed <<
			age << std::endl <<
			"--Remain -> " << remain << std::endl <<
			"--Leave -> " << leave << std::endl;
	}

	std::cout << std::endl <<
		"PRESS ANY KEY TO CONTINUE";
	std::cin.ignore();
}

void executeGetResultsBasedOnName(std::map<std::string, std::tuple<int, int>> &resultsByName)
{
	typedef std::map<std::string, std::tuple<int, int>>::iterator it_type;
	for (it_type it = resultsByName.begin(); it != resultsByName.end(); it++)
	{
		std::string name = it->first;
		int remain = std::get<0>(it->second);
		int leave = std::get<1>(it->second);
		std::cout << std::setprecision(2) << std::fixed <<
			name << std::endl <<
			"--Remain -> " << remain << std::endl <<
			"--Leave -> " << leave << std::endl;
	}

	std::cout << std::endl <<
		"PRESS ANY KEY TO CONTINUE";
	std::cin.ignore();
}

void executeGetResultsBasedOnGender(std::map<Gender, std::tuple<int, int>> &resultsByGender)
{
	typedef std::map<Gender, std::tuple<int, int>>::iterator it_type;
	for (it_type it = resultsByGender.begin(); it != resultsByGender.end(); it++)
	{
		Gender gender = it->first;
		std::string genderStr = "Male";
		if (gender == Female)
		{
			genderStr = "Female";
		}

		int remain = std::get<0>(it->second);
		int leave = std::get<1>(it->second);
		std::cout << std::setprecision(2) << std::fixed <<
			genderStr << std::endl <<
			"--Remain -> " << remain << std::endl <<
			"--Leave -> " << leave << std::endl;
	}

	std::cout << std::endl <<
		"PRESS ANY KEY TO CONTINUE";
	std::cin.ignore();
}

void executeGetResultsBasedOnEthnicity(std::map<std::string, std::tuple<int, int>> &resultsByEthnicity)
{
	typedef std::map<std::string, std::tuple<int, int>>::iterator it_type;
	for (it_type it = resultsByEthnicity.begin(); it != resultsByEthnicity.end(); it++)
	{
		std::string ethnicity = it->first;
		int remain = std::get<0>(it->second);
		int leave = std::get<1>(it->second);
		std::cout << std::setprecision(2) << std::fixed <<
			ethnicity << std::endl <<
			"--Remain -> " << remain << std::endl <<
			"--Leave -> " << leave << std::endl;
	}

	std::cout << std::endl <<
		"PRESS ANY KEY TO CONTINUE";
	std::cin.ignore();
}

void executeGetResultsBasedOnLocation(std::map<std::string, std::tuple<int, int>> &resultsByLocation)
{
	typedef std::map<std::string, std::tuple<int, int>>::iterator it_type;
	for (it_type it = resultsByLocation.begin(); it != resultsByLocation.end(); it++)
	{
		std::string location = it->first;
		int remain = std::get<0>(it->second);
		int leave = std::get<1>(it->second);
		std::cout << std::setprecision(2) << std::fixed <<
			location << std::endl <<
			"--Remain -> " << remain << std::endl <<
			"--Leave -> " << leave << std::endl;
	}

	std::cout << std::endl <<
		"PRESS ANY KEY TO CONTINUE";
	std::cin.ignore();
}

void executeGetAllPossibleAges(std::set<int> &ages)
{
	std::cout << "ALL AGES:" << std::endl;

	typedef std::set<int>::iterator it_type;
	for (it_type it = ages.begin(); it != ages.end(); it++)
	{
		int age = *it;
		std::cout << "--" << age << std::endl;
	}

	std::cout << std::endl <<
		"PRESS ANY KEY TO CONTINUE";
	std::cin.ignore();
}

void executeGetAllPossibleNames(std::set<std::string> &names)
{
	std::cout << "ALL NAMES:" << std::endl;

	typedef std::set<std::string>::iterator it_type;
	for (it_type it = names.begin(); it != names.end(); it++)
	{
		std::string name = *it;
		std::cout << "--" << name << std::endl;
	}

	std::cout << std::endl <<
		"PRESS ANY KEY TO CONTINUE";
	std::cin.ignore();
}

void executeGetAllPossibleEthnicities(std::set<std::string> &ethnicities)
{
	std::cout << "ALL ETHNICITIES:" << std::endl;

	typedef std::set<std::string>::iterator it_type;
	for (it_type it = ethnicities.begin(); it != ethnicities.end(); it++)
	{
		std::string ethnicity = *it;
		std::cout << "--" << ethnicity << std::endl;
	}

	std::cout << std::endl <<
		"PRESS ANY KEY TO CONTINUE";
	std::cin.ignore();
}

void executeGetAllPossibleLocations(std::set<std::string> &locations)
{
	std::cout << "ALL LOCATIONS:" << std::endl;

	typedef std::set<std::string>::iterator it_type;
	for (it_type it = locations.begin(); it != locations.end(); it++)
	{
		std::string location = *it;
		std::cout << "--" << location << std::endl;
	}

	std::cout << std::endl <<
		"PRESS ANY KEY TO CONTINUE";
	std::cin.ignore();
}

void executeGetSpecificResult(std::shared_ptr<VoteCollector> &voteCollector)
{
	system("cls");
	std::cout << ">";
	std::string input;
	getline(std::cin, input);

	bool isAge = checkIfInputIsForAge(input, voteCollector->getAges(), voteCollector->getResultsByAge());
	bool isName = checkIfInputIsForName(input, voteCollector->getNames(), voteCollector->getResultsByName());
	bool isGender = checkIfInputIsForGender(input, voteCollector->getResultsByGender());
	bool isEthnicity = checkIfInputIsForEthnicity(input, voteCollector->getEthnicities(), voteCollector->getResultsByEthnicity());
	bool isLocation = checkIfInputIsForLocation(input, voteCollector->getLocations(), voteCollector->getResultsByLocation());

	if (!(isAge || isName || isGender || isEthnicity || isLocation))
	{
		std::cout << "404 - Not Found" << std::endl;
	}

	std::cout << std::endl <<
		"PRESS ANY KEY TO CONTINUE";
	std::cin.ignore();
}

bool checkIfInputIsForAge(std::string input, std::set<int> &ages, std::map<int, std::tuple<int, int>> &resultsByAge)
{
	if (isNumber(input))
	{
		int possibleAge = std::stoi(input);
		typedef std::set<int>::iterator it_age_type;
		for (it_age_type it = ages.begin(); it != ages.end(); it++)
		{
			int age = *it;
			if (possibleAge == age)
			{
				int remain = std::get<0>(resultsByAge[age]);
				int leave = std::get<1>(resultsByAge[age]);
				std::cout << "" << age << "(AGE)" << std::endl <<
					"--Remain -> " << remain << std::endl <<
					"--Leave -> " << leave << std::endl;

				return true;
			}
		}
	}

	return false;
}

bool checkIfInputIsForName(
	std::string input,
	std::set<std::string> &names,
	std::map<std::string, std::tuple<int, int>> &resultsByName)
{
	typedef std::set<std::string>::iterator it_name_type;
	for (it_name_type it = names.begin(); it != names.end(); it++)
	{
		std::string name = *it;
		if (name == input)
		{
			int remain = std::get<0>(resultsByName[name]);
			int leave = std::get<1>(resultsByName[name]);
			std::cout << "" << name << "(NAME)" << std::endl <<
				"--Remain -> " << remain << std::endl <<
				"--Leave -> " << leave << std::endl;

			return true;
		}
	}

	return false;
}

bool checkIfInputIsForGender(std::string input, std::map<Gender, std::tuple<int, int>> &resultsByGender)
{
	if (input == "Female")
	{
		int remain = std::get<0>(resultsByGender[Female]);
		int leave = std::get<1>(resultsByGender[Female]);
		std::cout << "" << input << "(GENDER)" << std::endl <<
			"--Remain -> " << remain << std::endl <<
			"--Leave -> " << leave << std::endl;

		return true;
	}
	else if (input == "Male")
	{
		int remain = std::get<0>(resultsByGender[Male]);
		int leave = std::get<1>(resultsByGender[Male]);
		std::cout << "" << input << "(GENDER)" << std::endl <<
			"--Remain -> " << remain << std::endl <<
			"--Leave -> " << leave << std::endl;

		return true;
	}

	return false;
}

bool checkIfInputIsForEthnicity(
	std::string input,
	std::set<std::string> &ethnicicties,
	std::map<std::string, std::tuple<int, int>> &resultsByEthnicity)
{
	typedef std::set<std::string>::iterator it_ethnicity_type;
	for (it_ethnicity_type it = ethnicicties.begin(); it != ethnicicties.end(); it++)
	{
		std::string ethnicity = *it;
		if (ethnicity == input)
		{
			int remain = std::get<0>(resultsByEthnicity[ethnicity]);
			int leave = std::get<1>(resultsByEthnicity[ethnicity]);
			std::cout << "" << ethnicity << "(ETHNICITY)" << std::endl <<
				"--Remain -> " << remain << std::endl <<
				"--Leave -> " << leave << std::endl;

			return true;
		}
	}

	return false;
}

bool checkIfInputIsForLocation(
	std::string input,
	std::set<std::string> &locations,
	std::map<std::string, std::tuple<int, int>> &resultsByLocation)
{
	typedef std::set<std::string>::iterator it_location_type;
	for (it_location_type it = locations.begin(); it != locations.end(); it++)
	{
		std::string location = *it;
		if (location == input)
		{
			int remain = std::get<0>(resultsByLocation[location]);
			int leave = std::get<1>(resultsByLocation[location]);
			std::cout << "" << location << "(LOCATION)" << std::endl <<
				"--Remain -> " << remain << std::endl <<
				"--Leave -> " << leave << std::endl;

			return true;
		}
	}

	return false;
}

bool isNumber(std::string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return false;
		}
	}

	return true;
}

std::vector<std::shared_ptr<Voter>> addVotes()
{
	std::vector<std::shared_ptr<Voter>> voters;
	std::string names[] = 
	{
		"Jonathan Joestar", "Ivan Ivanov", "George Georgov", "Jon Snow", "John Bain", "Alice Wonderland", "Magica", "Iris Lake",
		"Howard Duck", "Steve Rogers", "Tony Stark", "Poppy Bop", "Clover Howardson", "Ruby", "Pearl", "Eve Friday", "Felicia Day",
		"Wil Wheaton"
	};
	int namesSize = 18;
	int ages[] = 
	{
		18, 19, 20, 30, 21, 34, 22, 23, 90, 100, 67, 45, 44, 33, 32, 
		80, 65, 66, 55, 54, 56, 57, 58, 70, 77, 76, 71, 31, 25, 27, 81, 82
	};
	int agesSize = 32;
	std::string locations[] =
	{
		"Scotland", "Northern Ireland", "England", "Wales"
	};
	int locationsSize = 4;
	std::string ethnicities[] =
	{
		"French", "German", "English", "Bularian", "Italian", "Korean", "Norwegian", "Russian", "Scottish", "Serb", "Greek"
	};
	int ethnicitiesSize = 11;

	for (int i = 0; i < 10000; i++)
	{
		std::string name = names[i % namesSize];
		int age = ages[i % agesSize];
		Gender gender = (Gender)(i % 2);
		std::string location = locations[i % locationsSize];
		std::string ethnicity = ethnicities[i % ethnicitiesSize];

		int randomNumber = std::rand() % 1000;
		Vote vote = Leave;
		if (randomNumber % 3 == 0)
		{
			vote = Remain;
		}

		std::shared_ptr<Voter> newVoter(new Voter(age, name, gender, location, ethnicity, vote));
		voters.push_back(newVoter);
	}

	return voters;
}