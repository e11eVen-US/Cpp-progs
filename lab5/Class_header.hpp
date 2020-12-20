#ifndef CLASS_HEADER_HPP
#define CLASS_HEADER_HPP

#include <string>
#include <iostream>
#include <fstream>
#define wc cout.width(15);
#define wf file.width(15);

class participant
{
private:
    std::string club;
    std::string city;
    std::string coach;
    std::string date;
    int budget;
    int points;
    short place;
public:
    participant() : club("0"), city("0"), coach("0"), date("0"), budget(0), points(0), place(0) {};
    participant(std::string, std::string, std::string, std::string, int, int, short);
    ~participant();

    void struct_filling(participant* c, std::ifstream& file);
    void struct_print(participant* c);
    void file_filling(participant* c, std::ofstream& file);
    void file_filling_cont_main(std::ofstream& file);

    
    std::string get_club();
    std::string get_city();
    std::string get_coach();
    std::string get_date();
    int get_points();
    int get_budget();
    int get_place();
    
    void set_club(std::string a1);
    void set_city(std::string a1);
    void set_coach(std::string a1);
    void set_date(std::string a1);
    void set_budget(int a2);
    void set_points(int a2);
    void set_place(int a2);
    void set_array();

    friend bool operator==(participant eq_eq, participant eq_eq2);
    friend std::ostream& operator<<(std::ostream& stream, participant& test);
    friend std::ofstream& operator<<(std::ofstream& stream, participant& test);
    friend std::istream& operator>>(std::istream& stream, participant& test);
    friend std::ifstream& operator>>(std::ifstream& stream, participant& test);
};

#endif