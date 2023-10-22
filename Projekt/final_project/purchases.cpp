#include "purchases.h"



void purchases::add_purchase(const ticket& ticket) {
    tickets.push_back(ticket);
}



void purchases::show_purchases() {
    int i = 1;
    if (tickets.size() != 0) {
        for (auto& ticket : tickets) {
            std::cout << i << ". " << "Id: " << ticket.get_id()
                << ", Category: " << ticket.get_category()
                << ", Price: " << ticket.get_price()
                << ", Seat: " << ticket.get_seat() 
                << ", user_data: "<< ticket.get_user_data() << std::endl;

            // ticket.show_last_connection();


            std::cout << std::endl;
            i++;
        }
    }
    else {
        std::cout << "You have not purchased anything yet!" << std::endl;
    }
}



void purchases::delete_purchase(int del) {

    if (tickets.size() != 0 and  (del-1) <= tickets.size() and (del - 1) >= 0)
    {
        tickets.erase(tickets.begin() + (del - 1));

    }
   // std::cout << "FAILED DELETING CONNECTION" << std::endl;
}



void purchases::show_connections_to_delete() {
    int i = 1;
    for (auto &a : tickets) {
        std::cout << i << ". ";
        a.show_last_connection();i++;
    }
}


int purchases::which_connection_to_delete() {
    int del;
    if (tickets.size() != 0) {
        
        std::cout << "Which connection do you want to cancel?:";
        std::cin >> del;

        return del;
    }
}


int purchases::ask_if_interested() {
    int answer;

        std::cout << "Do you wanna cancel any?:" << std::endl;
        std::cout << "Write 0 if no / 1 if yes:";
        std::cin >> answer;
   
    return answer;

}


std::ostream& operator <<(std::ostream& s, const purchases& obj) {

    for (auto a : obj.tickets) {
        s << "Id: " << a.get_id() << " ,Category: " << a.get_category() << " ,Price: " << a.get_price() << " ,Seat: " << a.get_seat() << " ,User: " << a.get_user_data() << std::endl;;
    }
    return s;
}



void purchases::show_connections_to_file2(std::string file_name, purchases& obj, ticket &t1) {
    std::ofstream file(file_name, std::ios::app);
    if (!file.is_open()) {
        std::cout << "Could not open the file!" << std::endl;
    }
    int i = 0;

    for (auto a : t1.connectiones) {
        if (a.get_departure() != "none")
            file << "Connection connected with " << ++i << " ticket: " << "Departure: "
            << a.get_departure() << ", Destination: " << a.get_destination() << ", Day of flight: "
            << a.get_day() << ", At time: " << a.get_hours() << ":" << a.get_minutes() << std::endl;
    }

    file.close();
}






void purchases::booked_ticket_to_file(std::string file_name, const purchases& obj) {
    std::ofstream file(file_name);
    if (!file.is_open()) {
        std::cout << "Could not open the file!" << std::endl;
    }
    file << obj;

    file.close();
}


void purchases::connections_data_for_service(std::string file_name, const purchases& obj, ticket& t1) {
    std::ofstream file(file_name);
    if (!file.is_open()) {
        std::cout << "Could not open the file!" << std::endl;
    }

    for (auto a : t1.connectiones) {
        if (a.get_departure() != "none")
            file <<  a.get_departure() << " " << a.get_destination() << " "
            << a.get_day() << " " << a.get_hours() << " " << a.get_minutes() << std::endl;
    }

    file.close();

}


void purchases::data_for_service(std::string file_name, const purchases& obj) {
    std::ofstream file(file_name);
    if (!file.is_open()) {
        std::cout << "Could not open the file!" << std::endl;
    }
    
    for (auto a : obj.tickets) {
        file << a.get_id() << "," << a.get_category() << "," << a.get_price() << "," << a.get_seat() << "," << a.get_user_data() << std::endl;
    }

    file.close();
}



std::vector<int> purchases::get_seat_from_ticket() {
    std::vector<int> seats;
    for (auto a : tickets) {
        seats.push_back(a.get_seat());
    }
    return seats;
}