#include <iostream>
#include <string>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <vector>

#include "Class_header.hpp"
#include "Task_header.hpp"
#include "Class_container.hpp"




int main()
{
    using namespace std;

    setlocale(LC_ALL, "Russian");

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int16_t amount_of_teams;
    int16_t test = amount_of_teamsf();
    bool data_in_structure = false;
    string file_name = "file.txt";

    if (test == 0)
    {
        do
        {
            cout << "Type the number of teams: \n--->";
            cin >> amount_of_teams;
            if (amount_of_teams < 1)
            {
                system("cls");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                cerr << "You have typed " << amount_of_teams << ". You have to type the amount of teams > 0\n";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }

        } while (amount_of_teams < 1);
    }
    else
    {
        amount_of_teams = test;
    }
 
    cout << "Type max amount of participants: ";
    int max_amount_of_participants;
    cin >> max_amount_of_participants;
    participant_team b(max_amount_of_participants, amount_of_teams);

    int16_t is_continue;
    int16_t choice;

    do
    {
        amount_of_teams = b.get_amount();
        test = amount_of_teamsf();
        do
        {
            if (data_in_structure)
            {
                cout << "Data in structure: true\n";
                cout << "String in file: " << amount_of_teams << "\n\n";
            }
            else
            {
                cout << "Data in structure: false\n";
                cout << "String in file: " << amount_of_teams << "\n\n";
            }
            cout << "What do you wanna do?\n 1. Filling structure from file\n 2. All teams from city you'll type.\n 3. The team with the highest ratio of points scored to money spent (budget)\n 4. Structure printing\n 5. Fill structure(and file) from keyboard\n 6. Add to structure and file.\n 7. Delete from structure\n\n\n For the 5th lab below.\n 8.Add to vector \n 9. ==\n 10. << ofstream\n 11. << ostream\n ---> ";
            cin >> choice;
            if (choice < 1 || choice > 11)
            {
                system("cls");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                cerr << "You have typed " << choice << ". You have to type 1 - 7.\n";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
        } while (choice < 1 || choice > 11);


        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            if (test == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                cerr << "Enter the data in file first(the data will also be entered into the structure).\n";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
            else
            {          
                b.read_from_file();
                data_in_structure = true;
            }
            break;
        }
        case 2:
        {
            second_task(&b, amount_of_teams, &data_in_structure);
            break;
        }    
        case 3:
        {
            third_task(&b, amount_of_teams, &data_in_structure);
            break;
        }
        case 4:
        {
            if (!data_in_structure)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                std::cerr << "Your structure isn't filled, fill it.\n";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
            else
            {
                cout << "\t   Club\t\t  City\t\tCoach\t\tDate\t     Budget\t    Points\t    Place\n";
                b.print(); 
            }
            break;
        }     
        case 5:
        {
            b.file_and_particpant_filling();
            data_in_structure = true;
            break;
        }
        case 6:
        {
            if ((b.get_amount() < max_amount_of_participants) && data_in_structure)
            {
                ofstream file;
                file.open(file_name, ios::app);

                participant test;
                int test1;
                string test2;

                cout << "Type club name: ";
                getline(cin, test2);
                file << " " << test2;
                test.set_club(test2);
                cout << "Type city: ";
                getline(cin, test2);
                file << " " << test2;
                test.set_city(test2);
                cout << "Type the name of coach: ";
                getline(cin, test2);
                file << " " << test2;
                test.set_coach(test2);
                cout << "Type club foundation date: ";
                getline(cin, test2);
                file << " " << test2;
                test.set_date(test2);
                cout << "Type budget: ";
                cin >> test1;
                file << " " << test1;
                test.set_budget(test1);
                cout << "Type the amount of points: ";
                cin >> test1;
                file << " " << test1;
                test.set_points(test1);
                cout << "Type place: ";
                cin >> test1;
                file << " " << test1 << endl;
                test.set_place(test1);


                b.add_participant(data_in_structure, test);


                file.close();

                FILE* fileC = fopen("file.txt", "r+");
                fprintf(fileC, "%d", b.get_amount());
                fclose(fileC);
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                cerr << "Already max amount of participants.\n";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
            break;
        }
        case 7:
        {
            if (!data_in_structure)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                cerr << "Input data in structure first\n";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
            else
            {
                cout << "Type number of participant you wanna delete: ";
                int16_t number_of_participant;
                cin >> number_of_participant;
                --number_of_participant;

                b.delete_participant(&data_in_structure, number_of_participant);

                if (b.get_amount() == 0)
                {
                    data_in_structure = false;
                }

                ofstream file;
                file.open(file_name);

                file << b.get_amount() << '\n';


                b.file_filling_cont(file);


                file.close();
                break;
            }
        }

        //for the 5th lab below

        case 8:
        {
            participant pl_eq;
            b += pl_eq;
        }

        case 9:
        {
            participant eq_eq, eq_eq2;
            //eq_eq.set_city("qwe");
            if (eq_eq == eq_eq2)
            {
                cout << "They are equal.\n";
            }
            else
            {
                cout << "They aren't equal.\n";
            }
        }
        case 10:
        {
            participant eq_eq;

            ofstream file;
            file.open("file2.txt", ios::app);
            file << eq_eq;
            file.close();
        }
        case 11:
        {
            participant eq_eq;

            cout << eq_eq;
        }

        }
        cout << "Do you wanna continue? (type 0 or 1)\n--->";
        do
        {
            cin >> is_continue;
            if (is_continue != 0 && is_continue != 1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                cerr << "You have typed " << is_continue << ". You have to type 0 or 1.\n--->";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
        } while (is_continue != 0 && is_continue != 1);
        system("cls");
    } while (is_continue);

    return 0;
}