#include "round_ticket.h"

void round_ticket::set_values() {
	first_class = 1;
	bonus_luggage = 1;
	free_drinks = 1;
}


void round_ticket::get_details() {
	std::cout << "This ticket has mentioned pleasures below:" << std::endl;
	std::cout << "First class ticket: "; if (first_class) std::cout << "YES" << std::endl; else std::cout << "NO" << std::endl;
	std::cout << "Bonus luggage: "; if (bonus_luggage) std::cout << "YES" << std::endl; else std::cout << "NO" << std::endl;
	std::cout << "Free drinks: "; if (free_drinks) std::cout << "YES" << std::endl; else std::cout << "NO" << std::endl;
}
