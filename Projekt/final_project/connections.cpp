#include "connections.h"


connections::connections(std::string destination, std::string departure, std::string day, int hours, int minutes) {
	this->destination = destination;
	this->departure = departure;
	this->day = day;
	this->hours = hours;
	this->minutes = minutes;
}


void connections::show_connections(std::vector<connections>& vec) {

	std::cout << std::endl;
	int i = 0;
	for (auto& a : vec) {
		std::cout << i << ". " << "Departure: " << a.departure << " , Destination: " << a.destination << ", Day of departure: " << a.day << ", Hour of departure: " << a.hours << ":" << a.minutes << std::endl;
		i++;
	}
}

void connections::delete_connection(std::vector<connections>& vec, int user_input, std::vector<connections>& deleted_connections) {


	deleted_connections.push_back(vec[user_input]);

	vec.erase(vec.begin() + (user_input));

}

void connections::get_back_deleted_connection(int user_input, std::vector<connections>& vec, std::vector<connections>& deleted_connections) {
	if (deleted_connections.size() != 0 and user_input <= deleted_connections.size() and user_input > 0) {
		vec.push_back(deleted_connections[(user_input - 1)]);
		deleted_connections.erase(deleted_connections.begin() + (user_input - 1));
	}
	else {
		//std::cout << "NIE UDALO SIE ZWROCIC POLACZENIA" << std::endl;
	}
}




void connections::show_connections_no_numbers(std::vector<connections> vec) {
	for (auto& a : vec) {
		std::cout << "Departure: " << a.departure << " , Destination: " << a.destination << ", Day of departure: " << a.day << ", Hour of departure: " << a.hours << ":" << a.minutes << std::endl;

	}
}


std::vector<connections> connections::add_connections_from_file(std::string file_name) {
	std::ifstream file(file_name);
	std::string line;
	std::vector<connections> vec;

	if (!file.is_open()) {
		std::cout << "Could not open file" << std::endl;
		return vec;
	}

	if (file) {
		while (std::getline(file, line)) {
			std::stringstream ss(line);
			std::string destination, departure, day;
			int hours, minutes;
			while (ss >> departure >> destination >> day >> hours >> minutes) {
				vec.push_back(connections(destination, departure, day, hours, minutes));
			}
		}
	}
	return vec;
}



connections::connections() {
	destination = "none";
	departure = "none";
	day = "monday";
	hours = 1;
	minutes = 00;
}


std::string connections::get_departure() {
	return departure;
}


std::string connections::get_destination() {
	return destination;
}


std::string connections::get_day() {
	return day;
}


int connections::get_hours() {
	return hours;
}

int connections::get_minutes() {
	return minutes;
}

int connections::ask_if_interested() {
	int answer;
	std::cout << "Are u interested in any?:" << std::endl;
	std::cout << "Write 0 if no / 1 if yes: ";
	std::cin >> answer;
	return answer;
}



