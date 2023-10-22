#pragma once
#include "ticket.h"


class purchases {
	std::vector<ticket> tickets;
public:
	void add_purchase(const ticket& ticket);
	void show_purchases();
	void booked_ticket_to_file(std::string file_name, const purchases &obj);
	void delete_purchase(int del);
	void show_connections_to_delete();
	int which_connection_to_delete();
	int ask_if_interested();
	void data_for_service(std::string file_name, const purchases& obj);
	friend std::ostream& operator <<(std::ostream& s, const purchases& obj);
	void show_connections_to_file2(std::string file_name, purchases& obj, ticket& t1);
	void connections_data_for_service(std::string file_name, const purchases& obj, ticket &t1);
	std::vector<int> get_seat_from_ticket();
};