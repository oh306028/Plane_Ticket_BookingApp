#include "plane.h"


void boeing::show_properties(ticket& ticket, connections& connect, std::vector<connections>& connects,
	int& answer, int& user_input, std::vector<connections>& deleted_connections, one_way_ticket& one_way_ticket1, purchases& buys) {

	std::cout << "***************************************************" << std::endl;
	std::cout << "Thanks for choosing Boeing Travel Company" << std::endl;
	std::cout << "Our plane has " << seats << std::endl;
	std::cout << "Your seat is: " << ticket.get_seat() << std::endl;


	connect.show_connections(connects);
	answer = connect.ask_if_interested();

	if (answer) {

		std::cout << "Write number of connection that you wanna book: ";
		std::cin >> user_input;

		check_size(connects, user_input);

		ticket.add_connection(connects[user_input]);
		connect.delete_connection(connects, user_input, deleted_connections);

		ticket.choose_category();
		if (ticket.get_category() == "One-way") {

			one_way_ticket one_way_ticket1(ticket);
			one_way_ticket1.set_values();
			one_way_ticket1.get_details();
			one_way_ticket1.choose_price();
			one_way_ticket1.random_id();
			//boeing1.random_id(one_way_ticket, buys);
			one_way_ticket1.ask_for_user_data();
			buys.add_purchase(one_way_ticket1);

		}
		else {

			round_ticket round_ticket(ticket);
			round_ticket.set_values();
			round_ticket.get_details();
			round_ticket.choose_price();
			round_ticket.random_id();

			round_ticket.ask_for_user_data();
			buys.add_purchase(round_ticket);

		}
	}
}




void airbus::show_properties(ticket& ticket, connections& connect, std::vector<connections>& connects,
	int& answer, int& user_input, std::vector<connections>& deleted_connections, one_way_ticket& one_way_ticket1, purchases& buys) {
	std::cout << "***************************************************" << std::endl;
	std::cout << "Thanks for choosing Airbus Travel Company" << std::endl;
	std::cout << "Our plane has " << seats << std::endl;
	std::cout << "Your seat is: " << ticket.get_seat() << std::endl;


	connect.show_connections(connects);
	answer = connect.ask_if_interested();

	if (answer) {

		std::cout << "Write number of connection that you wanna book: ";
		std::cin >> user_input;

		check_size(connects, user_input);

		ticket.add_connection(connects[user_input]);
		connect.delete_connection(connects, user_input, deleted_connections);

		ticket.choose_category();
		if (ticket.get_category() == "One-way") {

			one_way_ticket one_way_ticket1(ticket);
			one_way_ticket1.set_values();
			one_way_ticket1.get_details();
			one_way_ticket1.choose_price();
			one_way_ticket1.random_id();
			//boeing1.random_id(one_way_ticket, buys);
			one_way_ticket1.ask_for_user_data();
			buys.add_purchase(one_way_ticket1);

		}
		else {

			round_ticket round_ticket(ticket);
			round_ticket.set_values();
			round_ticket.get_details();
			round_ticket.choose_price();
			round_ticket.random_id();

			round_ticket.ask_for_user_data();
			buys.add_purchase(round_ticket);

		}
	}

}




void embraer::show_properties(ticket& ticket, connections& connect, std::vector<connections>& connects,
	int& answer, int& user_input, std::vector<connections>& deleted_connections, one_way_ticket& one_way_ticket1, purchases& buys) {
	std::cout << "***************************************************" << std::endl;
	std::cout << "Thanks for choosing Embraer Travel Company" << std::endl;
	std::cout << "Our plane has " << seats << std::endl;
	std::cout << "Your seat is: " << ticket.get_seat() << std::endl;


	connect.show_connections(connects);
	answer = connect.ask_if_interested();

	if (answer) {

		std::cout << "Write number of connection that you wanna book: ";
		std::cin >> user_input;

		check_size(connects, user_input);

		ticket.add_connection(connects[user_input]);
		connect.delete_connection(connects, user_input, deleted_connections);

		ticket.choose_category();
		if (ticket.get_category() == "One-way") {

			one_way_ticket one_way_ticket1(ticket);
			one_way_ticket1.set_values();
			one_way_ticket1.get_details();
			one_way_ticket1.choose_price();
			one_way_ticket1.random_id();
			//boeing1.random_id(one_way_ticket, buys);
			one_way_ticket1.ask_for_user_data();
			buys.add_purchase(one_way_ticket1);

		}
		else {

			round_ticket round_ticket(ticket);
			round_ticket.set_values();
			round_ticket.get_details();
			round_ticket.choose_price();
			round_ticket.random_id();

			round_ticket.ask_for_user_data();
			buys.add_purchase(round_ticket);

		}
	}
}





embraer::embraer() {
	seats = "8 rows x 4 places, seats from 1-32";
	name = "Embraer";
}



boeing::boeing() {
	seats = "12 rows x 3 places, seats from 1-36";
	name = "Boeing";
}



airbus::airbus() {
	seats = "10 rows x 2 places, seats from 1-20";
	name = "Airbus";
}


void boeing::random_id(ticket& t1, purchases& p2) {
	srand(time(NULL));

	std::vector<int> seats = p2.get_seat_from_ticket();

	int number;
	number = rand() % 35 + 1;

	t1.set_seat2(number);
}



void embraer::random_id(ticket& t1, purchases& p2) {
	srand(time(NULL));
	int number;
	number = rand() % 35 + 1;
	std::vector<int> seats = p2.get_seat_from_ticket();


	t1.set_seat2(number);
}




void airbus::random_id(ticket& t1, purchases& p2) {
	srand(time(NULL));
	std::vector<int> seats = p2.get_seat_from_ticket();
	int number;
	number = rand() % 35 + 1;

	t1.set_seat2(number);


}




