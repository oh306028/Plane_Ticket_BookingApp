#pragma once
#include "ticket.h"
class one_way_ticket :public ticket {
	bool bonus_luggage;
	bool free_drinks;
	bool first_class;
public:
	one_way_ticket(const ticket& t) : ticket(t) {}
	void get_details();
	void set_values();
};


