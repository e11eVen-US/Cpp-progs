#include <Windows.h>
#include <iostream>
#include <fstream>
#include "Task_header.hpp"
#include "Class_container.hpp"

void second_task(participant_team* b, int16_t amount_of_teams, bool* data_in_structure)
{
    using namespace std;

    if (!*data_in_structure)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cerr << "Your structure isn't filled. Fill it first.\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else
    {
        cout << "\t   Club\t\t  City\t\tCoach\t\tDate\t     Budget\t    Points\t    Place\n";

        b->print();  

        cout << "Type city title: ";
        string city_name;
        getline(cin, city_name);

        int16_t counter = 0;
        for (register int i = 0; i < b->get_vector_size(); i++)
        {
            if (city_name == b->get_city_cont(i))
            {
                counter++;
                cout << counter << ": " << b->get_club_cont(i) << endl;
            }
        }
        if (counter == 0)
        {
            cout << "There are no teams from typed city\n";
        }
    }
}

void third_task(participant_team* b, int16_t amount_of_teams, bool* data_in_structure)
{
    using namespace std;

    if (!*data_in_structure)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cerr << "Your structure isn't filled, fill it.\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else
    {
        int number = 0;

        for (register int i = 1; i < b->get_vector_size(); i++)
        {
            if (float(b->get_points_cont(i)) / float(b->get_budget_cont(i)) > (float(b->get_points_cont(number)) / float(b->get_budget_cont(number))))
            {
                number = i;
            }
        }
        cout << b->get_club_cont(number)  << endl;
    }
}

int amount_of_teamsf()
{
    using namespace std;

    ifstream strings_in_file;
    int16_t strings_in_file_i = 0;

    strings_in_file.open("file.txt");

    if (!strings_in_file.is_open())
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cerr << "Open file error." << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
    else
    {
        strings_in_file >> strings_in_file_i;
    }
    strings_in_file.close();
    return strings_in_file_i;
}