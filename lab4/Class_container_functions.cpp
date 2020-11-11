#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
#include "Class_container.hpp"
#include "Class_header.hpp"

int participant_team::get_points_cont(int i)
{
	int points = c[i].get_points();
	return points;
}

int participant_team::get_budget_cont(int i)
{
	int budget = c[i].get_budget();
	return budget;
}

int participant_team::get_amount()
{
	return amount;
}

std::string participant_team::get_club_cont(int i)
{
	std::string club = c[i].get_club();
	return club;
}

std::string participant_team::get_city_cont(int i)
{
	std::string city = c[i].get_city();
	return city;
}

participant_team::participant_team(int max_amount_of_teams, int amount_of_participants)
{
	max_amount = max_amount_of_teams;
	amount = amount_of_participants;
}


participant_team::~participant_team()
{
	std::vector<participant>().swap(c);
	max_amount = 0;
	amount = 0;
}

void participant_team::operator+=(participant pl_eq)
{
	using namespace std;
	
	if (amount < max_amount)
	{
		ofstream file;
		file.open("file.txt", ios::app);
		file << " " << pl_eq.get_club(); file << " " << pl_eq.get_city(); file << " " << pl_eq.get_coach(); file << " " << pl_eq.get_date();
		file << " " << pl_eq.get_budget(); file << " " << pl_eq.get_points(); file << " " << pl_eq.get_place() << '\n';
		file.close();
		c.push_back(std::move(pl_eq));
		++amount;

		FILE* fileC = fopen("file.txt", "r+");
		fprintf(fileC, "%d", amount);
		fclose(fileC);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cerr << "Already max amount of participants.\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
}

void participant_team::add_participant(participant test)
{
	using namespace std;

	c.push_back(move(test));
	amount++;	
}

/*void participant_team::expand_vector()
{
	using namespace std;

	vector<participant> test_vector;
	int16_t test1;
	string test2;

	if (amount < max_amount)
	{
		c.push_back(test_vector[0]);
		amount++;
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cerr << "There is no data in structure or already max participants\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
}*/

void participant_team::read_from_file()
{
	using namespace std;
	ifstream file;
	file.open("file.txt");
	int16_t x;
	file >> x;

	if (c.size() != amount)
	{
		c.resize(amount);
	}

	for (register int i = 0; i < amount; i++)
	{
		c[i].struct_filling(&c[0], file); ////////////
	}

	file.close();
}

void participant_team::file_and_particpant_filling()
{
	using namespace std;

	ofstream file;
	file.open("file.txt");
	file << amount << endl;

	if (c.size() != amount)
	{
		c.resize(amount);
	}

	for (register int i = 0; i < amount; i++) ///////////////
	{
		c[i].file_filling(&c[0], file);
	}

	file.close();
}

void participant_team::print()
{
	for (register int i = 0; i < amount; i++)
	{
		c[i].struct_print(&c[0]);
	}
}

void participant_team::file_filling_cont(std::ofstream& file)
{
	if (c.size() != amount)
	{
		c.resize(amount);
	}
	for (register int i = 0; i < amount; i++)
	{
		c[i].file_filling_cont_main(file);
	}
}

void participant_team::delete_participant(bool* data_in_structure, int16_t number_of_participant)
{
	using namespace std;

	c.erase(c.begin() + number_of_participant);
	--amount;		
}

