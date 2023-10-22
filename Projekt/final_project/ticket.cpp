#include "ticket.h"


ticket::ticket() {
	id = "none";
	category = "none";
	price = 0;
	seat = 1;
}


void ticket::show_properties() {
	std::cout << "Id: " << id << ", Category: " << category << ", Price: " << price << ", Seat: " << seat << std::endl;;
}



ticket::ticket(std::string id, std::string category, float price, int seat) {
	this->id = id;
	this->category = category;
	this->price = price;
	this->seat = seat;
}



std::string ticket::get_id() {
	return id;
}


std::string ticket::get_category() {
	return category;
}

float ticket::get_price() {
	return price;
}



int ticket::get_seat() {
	return seat;
}


void ticket::add_connection(const connections& c) {
	connectiones.push_back(c);
}


void ticket::show_last_connection()
{
	if (connectiones.empty()) {
		std::cout << "No connections added." << std::endl;
	}
	else {
		std::cout << "connection: ";
		connections c;
		c.show_connections_no_numbers({ connectiones.back() });
	}
}



void ticket::choose_category() {
	int user_input;
	do {
		std::cout << "Wchich type of ticket do you want?: " << std::endl;
		std::cout << "1. Rounded" << std::endl;
		std::cout << "2. One-way" << std::endl;
		std::cout << "Write (1-2) to choose: ";
		std::cin >> user_input;
	} while (user_input != 1 and user_input != 2);

	if (user_input == 1) {
		category = "Rounded";
	}
	else if (user_input == 2) {
		category = "One-way";
	}
}



void ticket::choose_price() {
	if (category == "Rounded") {
		price = 255.35;
	}
	else if (category == "One-way") {
		price = 155.55;
	}
	else {
		price = 0;
	}
}




std::string ticket::random_id() {
	int number;
	char charac, symbol;
	srand(time(NULL));

	number = rand() % 10;
	charac = rand() % 25 + 60;
	symbol = rand() % 4 + 35;

	id = std::to_string(number) + symbol + charac;

	return id;
}




void ticket::set_seat2(int number) {
	seat = number;

}

void ticket::set_seat() {
	std::cout << "Choose your seat: ";
	std::cin >> seat;
}


void ticket::ask_for_user_data() {
	std::cout << "Please confirm your purchase with writting your NAME and SURNAME below. " << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Please enter it here: ";
	std::getline(std::cin, user_data);
	std::cout << std::endl;
}


std::string ticket::get_user_data() {
	return user_data;
}



void ticket::set_id(std::string identity) {
	id = identity;
}

void ticket::set_category(std::string cat) {
	category = cat;
}

void ticket::set_price(double pric) {
	price = pric;
}

void ticket::set_data_user(std::string data) {
	user_data = data;
}



void ticket::delete_purchase(int del) {
	if (del > 0 and del <= connectiones.size()) {
		connectiones.erase(connectiones.begin() + (del - 1));
	}
	else {
		std::cout << "FAILED DELETING CONNECTION" << std::endl;
	}
}

