#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
#include "Class_container.hpp"
#include "Class_header.hpp"
#include <stdlib.h>

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




participant_team::~participant_team()
{
	std::vector<participant>().swap(c);
}

void participant_team::operator+=(participant& pl_eq)
{
	using namespace std;

	c.push_back(std::move(pl_eq));
}

void participant_team::add_participant(participant test)
{
	using namespace std;

	c.push_back(move(test));
}

participant_team::participant_team()
{
	c.resize(1);
}

void participant_team::read_from_file()
{
	using namespace std;
	ifstream file;
	file.open("file.txt");
	int16_t x;
	file >> x;

	for (register int i = 0; i < c.size(); i++)
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
	file << c.size() << endl;

	for (register int i = 0; i < c.size(); i++) ///////////////
	{
		c[i].file_filling(&c[0], file);
	}

	file.close();
}

void participant_team::print()
{
	for (register int i = 0; i < c.size(); i++)
	{
		c[i].struct_print(&c[0]);
	}
}

void participant_team::write_to_file_cont(std::ofstream& file)
{
	for (register int i = 0; i < c.size(); i++)
	{
		c[i].file_filling_cont_main(file);
	}
}

void participant_team::delete_participant(bool* data_in_structure, int16_t number_of_participant)
{
	using namespace std;

	c.erase(c.begin() + number_of_participant);		
}

void participant_team::operator-=(participant& pl_eq)
{
	using namespace std;

	if (c.size() != 0)
	{
		c.erase(c.end() - 1);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cerr << "There's no data in structure.\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
}

int participant_team::get_vector_size()
{
	return c.size();
}

void participant_team::vector_resize(int16_t a)
{
	c.resize(a);
}

std::ostream& operator<<(std::ostream& stream, participant_team& test)
{
	for (register int i = 0; i < test.c.size(); i++)
	{
		stream << test.c[i];
	}

	return stream;
}

std::ofstream& operator<<(std::ofstream& stream, participant_team& test)
{
	for (register int i = 0; i < test.c.size(); i++)
	{
		stream << test.c[i];
	}
	
	return stream;
}

std::istream& operator>>(std::istream& stream, participant_team& test)
{
	for (register int i = 0; i < test.c.size(); i++)
	{
		stream >> test.c[i];
	}

	return stream;
}

std::ifstream& operator>>(std::ifstream& stream, participant_team& test)\
{
	for (register int i = 0; i < test.c.size(); i++)
	{
		stream >> test.c[i];
	}
	return stream;
}

void participant_team::set_array_for_container()
{
	for (register int i = 0; i < c.size(); i++)
	{
		c[i].set_array();
	}
}