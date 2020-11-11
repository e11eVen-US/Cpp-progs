#include <fstream>
#include <iostream>
#include <windows.h>
#include <string>
#include "Class_header.hpp"

#define ws stream.width(15);

void participant::set_club(std::string a1)
{
    club = a1;
}
void participant::set_city(std::string a1)
{
    city = a1;
}
void participant::set_coach(std::string a1)
{
    coach = a1;
}
void participant::set_date(std::string a1)
{
    date = a1;
}
void participant::set_budget(int a2)
{
    budget = a2;
}
void participant::set_points(int a2)
{
    points = a2;
}
void participant::set_place(int a2)
{
    place = a2;
}

std::string participant::get_club()
{
    return club;
}

std::string participant::get_city()
{
    return city;
}

std::string participant::get_coach()
{
    return coach;
}
std::string participant::get_date()
{
    return date;
}

int participant::get_points()
{
    return points;
}

int participant::get_budget()
{
    return budget;
}

int participant::get_place()
{
    return place;
}

bool operator==(participant eq_eq, participant eq_eq2)
{
    if (eq_eq.club != eq_eq2.club) return false;
    if (eq_eq.city != eq_eq2.city) return false;
    if (eq_eq.coach != eq_eq2.coach) return false;
    if (eq_eq.date != eq_eq2.date) return false;
    if (eq_eq.budget != eq_eq2.budget) return false;
    if (eq_eq.points != eq_eq2.points) return false;
    if (eq_eq.place != eq_eq2.place) return false;
    return true;
}

std::ostream& operator<<(std::ostream& stream, participant test)
{
    ws; stream << test.club; ws; stream << test.city; ws;
    stream << test.coach; ws; stream << test.date; ws; stream << test.budget; ws;
    stream << test.points; ws; stream << test.place << '\n';

    return stream;
}
std::istream& participant::operator>>(std::istream& stream)
{
    getline(stream, club);
    getline(stream, city);
    getline(stream, coach);
    getline(stream, date);
    stream >> budget;
    stream >> points;
    stream >> place; 
    stream.ignore();

    return stream;
}
std::ofstream& operator<<(std::ofstream& stream, participant test)
{
    stream << ' '; stream << test.club; stream << ' '; stream << test.city; stream << ' ';
    stream << test.coach; stream << ' '; stream << test.date; stream << ' '; stream << test.budget; stream << ' ';
    stream << test.points; stream << ' '; stream << test.place << '\n';

    return stream;
}
std::ifstream& participant::operator>>(std::ifstream& stream)
{
    getline(stream, club);
    getline(stream, city);
    getline(stream, coach);
    getline(stream, date);
    stream >> budget;
    stream >> points;
    stream >> place;
    stream.ignore();
    return stream;
}

void participant::struct_print(participant* c)
{
    using std::cout;
    using std::endl;

    wc; cout << club; wc; cout << city; wc; 
    cout << coach; wc; cout << date; wc; cout << budget; wc;
    cout << points; wc; cout << place << endl;
}

void participant::file_filling(participant* c, std::ofstream& file)
{
    using namespace std;

    cout << "Type club name: ";
    getline(cin, club);
    cout << "Type city: ";
    getline(cin, city);
    cout << "Type the name of coach: ";
    getline(cin, coach);
    cout << "Type club foundation date: ";
    getline(cin, date);
    cout << "Type budget: ";
    cin >> budget;
    cout << "Type the amount of points: ";
    cin >> points;
    cout << "Type place: ";
    cin >> place; cout << endl;
    cin.ignore();

    file << " " << club; file << " " << city; file << " " << coach; file << " " << date;
    file << " " << budget; file << " " << points; file << " " << place << '\n';
}

void participant::struct_filling(participant* c, std::ifstream &file)
{
    file >> club >> city >> coach >> date >> budget >> points >> place;
}

void participant::file_filling_cont_main(std::ofstream& file)
{
    file << ' ' << club; file << ' ' << city; file << ' ' << coach; file << ' ' << date;
    file << ' ' << budget; file << ' ' << points; file << ' ' << place << '\n';
}