#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
//#include "ticket.h"


class connections
{
	std::string departure, destination, day;
	int hours, minutes;

public:

	connections(std::string destination, std::string departure, std::string day, int hours, int minutes);
	connections();
	void show_connections(std::vector<connections> &vec);
	void show_connections_no_numbers(std::vector<connections> vec);
	void delete_connection(std::vector<connections>& vec, int user_input, std::vector<connections> &deleted_connections);
	void get_back_deleted_connection(int user_input, std::vector<connections>& vec, std::vector<connections> &deleted_connections);
	std::vector<connections> add_connections_from_file(std::string file_name);
	std::string get_departure();
	std::string get_destination();
	std::string get_day();
	int get_hours();
	int get_minutes();
	int ask_if_interested();
//	friend std::ostream& operator <<(std::ostream& s, const connections& obj);


};

