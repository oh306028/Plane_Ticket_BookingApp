#pragma once
#include "ticket.h"
#include "purchases.h"
#include "functions.h"
#include "connections.h"
#include "one_way_ticket.h"
#include "round_ticket.h"

class plane
{
public:
	virtual void show_properties(ticket& ticket, connections& connect, std::vector<connections>& connects,
		int& answer, int& user_input, std::vector<connections>& deleted_connections, one_way_ticket& one_way_ticket1, purchases& buys) = 0;
	virtual void random_id(ticket& t1, purchases& p2) = 0;

};



class boeing :public plane {

	std::string seats, name;

public:
	virtual void show_properties(ticket& ticket, connections& connect, std::vector<connections>& connects,
		int& answer, int& user_input, std::vector<connections>& deleted_connections, one_way_ticket& one_way_ticket1, purchases& buys);
	virtual void random_id(ticket& t1, purchases& p2);

	boeing();

};




class airbus :public plane {

	std::string seats, name;

public:
	virtual void show_properties(ticket& ticket, connections& connect, std::vector<connections>& connects,
		int& answer, int& user_input, std::vector<connections>& deleted_connections, one_way_ticket& one_way_ticket1, purchases& buys);
	virtual void random_id(ticket& t1, purchases& p2);

	airbus();

};



class embraer :public plane {

	std::string seats, name;

public:
	virtual void show_properties(ticket& ticket, connections& connect, std::vector<connections>& connects,
		int& answer, int& user_input, std::vector<connections>& deleted_connections, one_way_ticket& one_way_ticket1, purchases& buys);
	virtual void random_id(ticket& t1, purchases& p2);

	embraer();

};