// Rezerwacje biletow lotniczych.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "ticket.h"
#include "plane.h"
#include "connections.h"
#include "purchases.h"
#include "round_ticket.h"
#include "one_way_ticket.h"
#include "functions.h"



int main()
{
    // variables needed to start
    char user_choice1, user_choice2;
    int user_input = 0;
    std::vector<connections> deleted_connections; int answer = 0;
    ticket ticket("nonee", "none", 0, 0); purchases buys; connections connect;
    std::vector<connections> connects = (connect.add_connections_from_file("arrives.txt"));
    plane* ptr;
    boeing boeing1;
    airbus airbus1;
    embraer embraer1;

    //previous tickets
    std::vector<connections> connects_from_previous_buys;
    chech_if_tickets_was_booked2("data_base.txt", "connects_dat_base.txt", buys, connects_from_previous_buys);
    ticket.connectiones = connects_from_previous_buys;
    one_way_ticket one_way_ticket1(ticket);


    plane* list_of_planes[3];
    list_of_planes[0] = &boeing1;
    list_of_planes[1] = &airbus1;
    list_of_planes[2] = &embraer1;



    //start
    do {
        std::cout << "Welcome to the booking site" << std::endl;
        std::cout << "1. Buy ticket" << std::endl;
        std::cout << "2. Check your purchases" << std::endl;
        std::cout << "3. Cancel" << std::endl;
        std::cout << "Write (1-3): ";
        std::cin >> user_choice1;

        switch (user_choice1) {
        case'1':


            std::cout << "Our tickets are connected with planes: " << std::endl;
            std::cout << "1. Boeing" << std::endl;
            std::cout << "2. Airbus" << std::endl;
            std::cout << "3. Embraer" << std::endl;
            std::cout << "4. Cancel" << std::endl;
            std::cout << "Write (1-4): ";
            std::cin >> user_choice2;

            switch (user_choice2) {

            case'1':
                ptr = list_of_planes[0];
                ptr->random_id(ticket, buys);
                ptr->show_properties(ticket, connect, connects, answer, user_input, deleted_connections, one_way_ticket1, buys);

                break;
            case'2':
                ptr = list_of_planes[1];
                ptr->random_id(ticket, buys);
                ptr->show_properties(ticket, connect, connects, answer, user_input, deleted_connections, one_way_ticket1, buys);

                break;
            case'3':
                ptr = list_of_planes[2];
                ptr->random_id(ticket, buys);
                ptr->show_properties(ticket, connect, connects, answer, user_input, deleted_connections, one_way_ticket1, buys);
                break;

            case'4':break;
            default:
                std::cout << "INCORRECT CHOICE! TRY AGAIN: " << std::endl;
            }


            break;
        case'2':
            std::cout << "Your purchases below: " << std::endl;
            int number_to_delete;

            buys.show_purchases();

            // deleting
            buys.show_connections_to_delete();
            answer = buys.ask_if_interested();
            if (answer) {
                number_to_delete = buys.which_connection_to_delete();
                buys.delete_purchase(number_to_delete);
                ticket.delete_purchase(number_to_delete);
                connect.get_back_deleted_connection(number_to_delete, connects, deleted_connections);

            }

            // data base's structure
            buys.booked_ticket_to_file("ready.txt", buys);
            buys.data_for_service("data_base.txt", buys);
            buys.show_connections_to_file2("ready.txt", buys, ticket);
            buys.connections_data_for_service("connects_dat_base.txt", buys, ticket);
            break;

        case'3':break;
        default:
            std::cout << "INCORRECT CHOICE! TRY AGAIN: " << std::endl;
        }


    } while (user_choice1 != '3');


    return 0;
}

