#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "connections.h"
#include <time.h>
#include <cctype>



class ticket
{
protected:
	std::string id, category, user_data;
	float price;
	int seat;


public:

	std::vector<connections> connectiones;
	ticket(std::string id, std::string category, float price, int seat);
	ticket();
	void show_properties();
	std::string get_id();
	std::string get_category();
	float get_price();
	int get_seat();
	void show_last_connection();
	void add_connection(const connections &c);
	void choose_category();
	void choose_price();
	void ask_for_user_data();
	std::string get_user_data();
	std::string random_id();
	void set_seat();
	void set_seat2(int number);

	void set_id(std::string identity);
	void set_category(std::string cat);
	void set_price(double pric);
	void delete_purchase(int del);
	void set_data_user(std::string data);

};




