#ifndef CLASS_CONTAINER_HPP
#define CLASS_CONTAINER_HPP
#include "Class_header.hpp"
#include <vector>
class participant_team
{
private:
	std::vector<participant> c;
public:
	participant_team();
	~participant_team();

	void add_participant(participant test);
	void delete_participant(bool* data_in_structure, int16_t number_of_participant);
	void read_from_file();
	void file_and_particpant_filling();
	void print();
	void write_to_file_cont(std::ofstream& file);
	void vector_resize(int16_t);

	int get_points_cont(int i);
	int get_budget_cont(int i);
	int get_vector_size();
	std::string get_city_cont(int i);
	std::string get_club_cont(int i);


	void operator+=(participant& pl_eq);
	void operator-=(participant& pl_eq);
	friend std::ostream& operator<<(std::ostream& stream, participant_team& test);
	friend std::ofstream& operator<<(std::ofstream& stream, participant_team& test);
	friend std::istream& operator>>(std::istream& stream, participant_team& test);
	friend std::ifstream& operator>>(std::ifstream& stream, participant_team& test);

	void set_array_for_container();
};
#endif // !CLASS_CONTAINER_HPP
