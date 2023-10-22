#pragma once
#include "ticket.h"


class round_ticket :public ticket
{
	bool first_class;
	bool bonus_luggage;
	bool free_drinks;

public:
	round_ticket(const ticket& t) : ticket(t) {}
	round_ticket();
	void get_details();
	void set_values();
};

