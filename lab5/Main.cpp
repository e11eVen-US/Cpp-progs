#include <iostream>
#include <string>
#include <cstdio>
#include <windows.h>
#include <fstream>
#include <vector>

#include "Class_header.hpp"
#include "Task_header.hpp"
#include "Class_container.hpp"

const int all_options = 15;

int main()
{
    using namespace std;

    setlocale(LC_ALL, "Russian");

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int16_t amount_of_teams;
    int16_t test = amount_of_teamsf();
    bool data_in_structure = false;
    string file_name = "file.txt", file_name2 = "file2.txt";

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
 
    participant_team b;

    int16_t is_continue;
    int16_t choice;

    do
    {
        test = amount_of_teamsf();
        do
        {
            if (data_in_structure)
            {
                cout << "Data in structure: true\n";
            }
            else
            {
                cout << "Data in structure: false\n";
            }
            cout << "What do you wanna do?\n 1. Filling structure from file\n 2. All teams from city you'll type.\n 3. The team with the highest ratio of points scored to money spent (budget)\n 4. Structure printing\n 5. Fill structure(and file) from keyboard\n 6. Add to structure and file.\n 7. Delete from structure\n\n\n For the 5th lab below.\n 8.+= \n 9. ==\n 10. << ofstream\n 11. << ostream\n 12. -= \n 13. >>o \n 14. >>of \n 15.Rewrite file \n ---> ";
            cin >> choice;
            if (choice < 1 || choice > all_options)
            {
                system("cls");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                cerr << "You have typed " << choice << ". You have to type 1 - " << all_options << "\n";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
        } while (choice < 1 || choice > all_options);


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
                b.vector_resize(amount_of_teams);
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
            b.vector_resize(amount_of_teams);
            b.file_and_particpant_filling();
            data_in_structure = true;
            break;
        }
        case 6:
        {
            if (data_in_structure)
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

                b.add_participant(test);

                file.close();

                ++amount_of_teams;

                fstream file1;
                file1.open(file_name, ios::in | ios::out);
                file1 << amount_of_teams;
                file1.close();
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

                if (b.get_vector_size() == 0)
                {
                    data_in_structure = false;
                }

                ofstream file;
                file.open(file_name);

                file << b.get_vector_size() << '\n';


                b.write_to_file_cont(file);


                file.close();
                break;
            }
        }

        //for the 5th lab below

        case 8:
        {
            
            if (!data_in_structure)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                cerr << "Input the data first.\n";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  
            }
            else
            {
                cout << "Input the number of objects you wanna add: ";
                int16_t amount1;
                cin >> amount1;
                vector<participant> test(amount1);
                for (register int i = 0; i < amount1; i++)
                {
                    cin >> test[i];
                    b += test[i];
                }

            }
            break;
        }

        case 9:
        {
            vector<participant> eq_eq(2);


            for (register int i = 0; i < 2; i++)
            {
                eq_eq[i].set_array();
            }

            if (eq_eq[0] == eq_eq[1])
            {
                cout << "They are equal.\n";
            }
            else
            {
                cout << "They aren't equal.\n";
            }
            break;
        }

        case 10:
        {
            int16_t amount1;
            cout << "Type amount of participants: ";
            cin >> amount1;

            vector<participant> test_array(amount1);

            for (register int i = 0; i < amount1; i++)
            {
                cin >> test_array[i];
            }

            ofstream file;
            file.open(file_name2, ios::app);
            for (register int i = 0; i < amount1; i++)
            {
               file << test_array[i];
            }
            file.close();
            break;
        }
        case 11:
        {
            int16_t amount1;
            cout << "Type amount of participants: ";
            cin >> amount1;
 
            vector<participant> test_array(amount1);
            for (register int i = 0; i < amount1; i++)
            {
                cin >> test_array[i];
            }
            for (register int i = 0; i < amount1; i++)
            {
                cout << test_array[i];
            }
        break;
        }
        case 12:
        {
            int16_t amount1;
            cout << "Type amount of participants: ";
            cin >> amount1;

            vector<participant> pl_eq(amount1);
            if (!data_in_structure)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                cerr << "Input the data first.\n";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);              
            }
            else
            {
                for (register int i = 0; i < amount1; i++)
                {
                    b -= pl_eq[i];
                }
                
                if (b.get_vector_size() == 0)
                {
                    data_in_structure = false;
                }
            }
            
            break;
        }
        case 13:
        {
            cout << "Type amount of participants: ";
            int16_t amount1;
            cin >> amount1;
            vector<participant> test(amount1);

            for (register int i = 0; i < amount1; i++)
            {
                cin >> test[i];
            }

            for (register int i = 0; i < amount1; i++)
            {
                cout << test[i];
            } 
            break;
        }
        case 14:
        {
            cout << "Type amount of participants: ";
            int16_t amount1;
            cin >> amount1;

            vector<participant> test(amount1);

            ifstream file;
            file.open("file2.txt");
            for (register int i = 0; i < amount1; i++)
            {
                file >> test[i];
            }
            file.close();
            for (register int i = 0; i < amount1; i++)
            {
                cout << test[i];
            }

            break;
        }
        case 15:
        {
            ofstream file;
            file.open(file_name);
            file << b.get_vector_size() << "\n";
            if (data_in_structure)
            {
                b.write_to_file_cont(file);
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                cerr << "Input the data first.\n";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            } 
            file.close();
            break;
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