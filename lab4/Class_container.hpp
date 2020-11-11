#ifndef CLASS_CONTAINER_HPP
#define CLASS_CONTAINER_HPP
#include "Class_header.hpp"
#include <vector>
class participant_team
{
private:
	int max_amount;
	int amount;
	std::vector<participant> c;
public:
	participant_team(int , int );
	participant_team() : max_amount(0), amount(0), c() {};
	~participant_team();

	void add_participant(participant test);
	void delete_participant(bool* data_in_structure, int16_t number_of_participant);
	void read_from_file();
	void file_and_particpant_filling();
	void print();
	//void expand_vector();
	void file_filling_cont(std::ofstream& file);

	int get_amount();
	int get_points_cont(int i);
	int get_budget_cont(int i);
	std::string get_city_cont(int i);
	std::string get_club_cont(int i);

	void operator+=(participant pl_eq);
};
#endif // !CLASS_CONTAINER_HPP
